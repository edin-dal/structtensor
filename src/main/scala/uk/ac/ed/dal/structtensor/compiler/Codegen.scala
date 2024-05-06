package uk.ac.ed.dal
package structtensor
package compiler

import scala.collection.mutable.ArraySeq
import scala.sys.process._
import scala.io.Source
import apps.Shared

object Codegen {
  import STURHelper._
  import Shared._

  def CPPFormat(a: Any): String = {
    a match {
      case s: String => s
      case i: Int => i.toString
      case d: Double => d.toString
      case v: Variable => v.name
      case i: Index => i match {
        case v: Variable => v.name
        case c: ConstantInt => c.value.toString
        case c: ConstantDouble => c.value.toString
        case a @ Arithmetic(op, i1, i2) => s"(${CPPFormat(i1)} ${op} ${CPPFormat(i2)})"
        case _ => ""
      }
      case a: Access => s"${a.name}[${a.vars.map(_.name).mkString("][")}]"
      // case d: Dim => d.cFormat
      case c @ Comparison(op, i, v) => s"(${CPPFormat(i)} ${op} ${CPPFormat(v)})"
      case p: Prod => p.exps.length match {
        case 0 => "∅"
        case 1 => CPPFormat(p.exps(0))
        case _ => s"(${p.exps.map(CPPFormat).mkString(" * ")})"
      }
      case s: SoP => s match {
        case SoP(Seq()) => "∅"
        case SoP(Seq(p)) => CPPFormat(p)
        case SoP(prods) => prods.map(CPPFormat).mkString(" + ")
      }
      case r: Rule => s"${CPPFormat(r.head)} = ${CPPFormat(r.body)}"
      case _ => ""
    }
  }

  def getConditionsOnVariable(v: Variable, conditions: Seq[Comparison]): (Seq[String], Seq[String], Seq[Any], Seq[Comparison]) = {
    // This function finds all the conditions on the given variable `v` in the conditions list
    // It returns begin, end, and the rest of the conditions
    val (begin_end_equals_usedIndices) = conditions.zipWithIndex.flatMap {
      case (cond: Comparison, ind: Int) if cond.variable == v => {
        cond.op match {
          case "<=" => Some((s"${CPPFormat(cond.index)}", "", "", ind))
          case "<" => Some((s"(${CPPFormat(cond.index)}) + 1", "", "", ind))
          case ">" => Some(("", s"${CPPFormat(cond.index)}", "", ind))
          case ">=" => Some(("", s"(${CPPFormat(cond.index)}) + 1", "", ind))
          case "=" => Some(("", "", cond.index, ind))
        }
      }
      case (cond: Comparison, ind: Int) => cond.index match {
        case variable: Variable if variable == v => {
          cond.op match {
            case ">=" => Some((s"${CPPFormat(cond.variable)}", "", "", ind))
            case ">" => Some((s"(${CPPFormat(cond.variable)}) + 1", "", "", ind))
            case "<" => Some(("", s"${CPPFormat(cond.variable)}", "", ind))
            case "<=" => Some(("", s"(${CPPFormat(cond.variable)}) + 1", "", ind))
            case "=" => Some(("", "", cond.variable, ind))
          }
        }
        case _ => None
      }
      case _ => None
    }
    val (begin, end, equals, usedIndices) = (begin_end_equals_usedIndices.map(_._1), begin_end_equals_usedIndices.map(_._2), begin_end_equals_usedIndices.map(_._3), begin_end_equals_usedIndices.map(_._4))
    (begin.distinct.filterNot(_ == ""), end.distinct.filterNot(_ == ""), equals.distinct.filterNot(_ == ""), conditions.zipWithIndex.filterNot{case (_, ind) => usedIndices.contains(ind)}.map(_._1))
  }

  def getVariablesInIndex(i: Index): Seq[Variable] = i match {
    case v: Variable => Seq(v)
    case a @ Arithmetic(_, i1, i2) => (getVariablesInIndex(i1) ++ getVariablesInIndex(i2)).distinct
    case _ => Seq()
  }

  def reorder(variables: Seq[Variable], conditions: Seq[Comparison]): Seq[Variable] = {
    // afterMap is a <key, value> pair where key is the variable, and value is a list of variables that key depends on
    val afterMap = conditions.map {
      case Comparison(_, i, v: Variable) => {
        if (variables.contains(v)) {
          i match {
            case va: Variable if (variables.contains(va)) => if (variables.indexOf(va) < variables.indexOf(v)) v -> Seq(va) else va -> Seq(v)
            case _ => v -> getVariablesInIndex(i).filter(variables.contains)
          }
        } else None
      }
    }.filterNot(_ == None).groupBy { case (k: Variable, _) => k }.mapValues(_.flatMap {case (_: Variable, vars: Seq[Variable]) => vars }).toMap //.foreach { case (k, v) => println(s"$k -> ${v}") }

    // indexMap is to sort the variables based on the variables that depend on them
    val indexMap = variables.zipWithIndex.toMap
    @scala.annotation.tailrec
    def reorderRec(afterMap: Map[Variable, Seq[Variable]], indexMap: Map[Variable, Int]): Seq[Variable] = {
      val newIndexMap = afterMap.map { case (k, v) => if (!v.isEmpty) k -> (v.map(indexMap).max + 1) else k -> indexMap(k)}
      if (newIndexMap == indexMap) indexMap.toSeq.sortBy(_._2).map(_._1)
      else reorderRec(afterMap, newIndexMap)
    }
    reorderRec(afterMap, indexMap)
  }

  def codeGenSingleProd(computationHead: Access, conditions: Seq[Comparison], accesses: Seq[Access], orderedVariables: Seq[Variable] = Seq()): String = {
    val variablesInit = (computationHead.vars ++ accesses.flatMap(_.vars)).distinct
    val variables = if (orderedVariables.isEmpty) reorder(variablesInit, conditions) else orderedVariables
    val (loopNests, restOfConditions, numberOfBrackets1) = variables.reverse.foldLeft(Seq[String](), conditions, 0)((acc, v) => {
      val (begin, end, equalsFullList, rest) = getConditionsOnVariable(v, acc._2)
      val equals = equalsFullList.filter {
        case va: Variable => variables.map(_.name).contains(va.name)
        case _ => true
      }
      // println(s"v: $v, begin: $begin, end: $end, equals: $equals, rest: $rest")
      val eqCode = equals.map(e => e match {
        case va: Variable => if (!begin.isEmpty || !end.isEmpty) s"int ${CPPFormat(va)} = ${CPPFormat(v)};" else s"int ${CPPFormat(v)} = ${CPPFormat(va)};"
        case _ => s"int ${CPPFormat(v)} = ${CPPFormat(e)};"
      }).mkString("\n")
      (begin.length, end.length) match {
        case (0, 0) => (acc._1 :+ eqCode, rest, acc._3)
        case (0, 1) => (acc._1 ++ Seq(s"if (${CPPFormat(v)} < ${end.mkString}) {\n$eqCode"), rest, acc._3 + 1)
        case (0, _) => (acc._1 ++ Seq(s"if (${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}) {\n$eqCode"), rest, acc._3 + 1)
        case (1, 0) => (acc._1 ++ Seq(s"if (${CPPFormat(v)} >= ${begin.mkString}) {\n$eqCode"), rest, acc._3 + 1)
        case (_, 0) => (acc._1 ++ Seq(s"if (${CPPFormat(v)} >= ${begin.mkString("max({", ", ", "})")}) {\n$eqCode"), rest, acc._3 + 1)
        case (1, 1) => {
          if (end.mkString == s"(${begin.mkString}) + 1") (acc._1 ++ Seq(s"int ${CPPFormat(v)} = ${begin.mkString};\n$eqCode"), rest, acc._3)
          else (acc._1 ++ Seq(s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(v)} < ${end.mkString}; ++${CPPFormat(v)}) {\n$eqCode"), rest, acc._3 + 1)
        } 
        case (1, _) => (acc._1 ++ Seq(s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}; ++${CPPFormat(v)}) {\n$eqCode"), rest, acc._3 + 1)
        case (_, 1) => (acc._1 ++ Seq(s"for (int ${CPPFormat(v)} = ${begin.mkString("max({", ", ", "})")}; ${CPPFormat(v)} < ${end.mkString}; ++${CPPFormat(v)}) {\n$eqCode"), rest, acc._3 + 1)
        case (_, _) => (acc._1 ++ Seq(s"for (int ${CPPFormat(v)} = ${begin.mkString("max({", ", ", "})")}; ${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}; ++${CPPFormat(v)}) {\n$eqCode"), rest, acc._3 + 1)
      }
    })
    val restString = restOfConditions.collect { case c @ Comparison(op, i, v) => op match {
      case "=" => s"int ${CPPFormat(v)} = ${CPPFormat(i)};"
      case _ => s"if (${CPPFormat(i)} $op ${CPPFormat(v)}) {"
    }}
    val loopNestsString = (loopNests.reverse ++ restString).mkString("\n")
    val numberOfBrackets = numberOfBrackets1 + restOfConditions.filterNot(_.op == "=").length
    val brackets = (0 until numberOfBrackets).map(_ => "}").mkString("\n")
    val computationBody = CPPFormat(Prod(accesses))
    s"$loopNestsString\n${CPPFormat(computationHead)} += $computationBody;\n$brackets"
  }

  def apply(rule: Rule): String = {
    val computationHead = rule.head
    rule.body.prods.map(prod => {
      val conditions = prod.exps.collect { case condition: Comparison => condition }
      val accesses = prod.exps.collect { case access: Access => access }
      codeGenSingleProd(computationHead, conditions, accesses)
    }).mkString("\n")
  }
}