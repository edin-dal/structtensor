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

  def getConditionsOnVariable(v: Variable, conditions: Seq[Comparison]): (Seq[String], Seq[String], Seq[Comparison]) = {
    // This function finds all the conditions on the given variable `v` in the conditions list
    // It returns begin, end, and the rest of the conditions
    val (begin_end_usedIndices): Seq[(String, String, Int)] = conditions.zipWithIndex.flatMap {
      case (cond: Comparison, ind: Int) if cond.variable == v => {
        cond.op match {
          case "<=" => Some((s"${CPPFormat(cond.index)}", "", ind))
          case "<" => Some((s"(${CPPFormat(cond.index)}) + 1", "", ind))
          case ">" => Some(("", s"${CPPFormat(cond.index)}", ind))
          case ">=" => Some(("", s"(${CPPFormat(cond.index)}) + 1", ind))
          case "=" => Some((s"${CPPFormat(cond.index)}", s"(${CPPFormat(cond.index)}) + 1", ind))
        }
      }
      case (cond: Comparison, ind: Int) => cond.index match {
        case variable: Variable if variable == v => {
          cond.op match {
            case ">=" => Some((s"${CPPFormat(cond.variable)}", "", ind))
            case ">" => Some((s"(${CPPFormat(cond.variable)}) + 1", "", ind))
            case "<" => Some(("", s"${CPPFormat(cond.variable)}", ind))
            case "<=" => Some(("", s"(${CPPFormat(cond.variable)}) + 1", ind))
            case "=" => Some((s"${CPPFormat(cond.variable)}", s"(${CPPFormat(cond.variable)}) + 1", ind))
          }
        }
        case _ => None
      }
      case _ => None
    }
    val (begin, end, usedIndices) = begin_end_usedIndices.unzip3
    (begin.distinct.filterNot(_ == ""), end.distinct.filterNot(_ == ""), conditions.zipWithIndex.filterNot{case (_, ind) => usedIndices.contains(ind)}.map(_._1))
  }

  def codeGenSingleProd(computationHead: Access, conditions: Seq[Comparison], accesses: Seq[Access]): String = {
    val variables = (computationHead.vars ++ accesses.flatMap(_.vars)).distinct
    val (loopNests, restOfConditions, numberOfBrackets1) = variables.reverse.foldLeft(Seq[String](), conditions, 0)((acc, v) => {
      val (begin, end, rest) = getConditionsOnVariable(v, acc._2)
      println(s"v: $v, begin: $begin, end: $end, rest: $rest")
      (begin.length, end.length) match {
        case (0, 0) => (acc._1, rest, acc._3)
        case (0, 1) => (acc._1 :+ s"if (${CPPFormat(v)} < ${end.mkString}) {", rest, acc._3 + 1)
        case (0, _) => (acc._1 :+ s"if (${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}) {", rest, acc._3 + 1)
        case (1, 0) => (acc._1 :+ s"if (${CPPFormat(v)} >= ${begin.mkString}) {", rest, acc._3 + 1)
        case (_, 0) => (acc._1 :+ s"if (${CPPFormat(v)} >= ${begin.mkString("max({", ", ", "})")}) {", rest, acc._3 + 1)
        case (1, 1) => (acc._1 :+ s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(v)} < ${end.mkString}; ++${CPPFormat(v)}) {", rest, acc._3 + 1)
        case (1, _) => (acc._1 :+ s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}; ++${CPPFormat(v)}) {", rest, acc._3 + 1)
        case (_, 1) => (acc._1 :+ s"for (int ${CPPFormat(v)} = ${begin.mkString("max({", ", ", "})")}; ${CPPFormat(v)} < ${end.mkString}; ++${CPPFormat(v)}) {", rest, acc._3 + 1)
        case (_, _) => (acc._1 :+ s"for (int ${CPPFormat(v)} = ${begin.mkString("max({", ", ", "})")}; ${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}; ++${CPPFormat(v)}) {", rest, acc._3 + 1)
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