package uk.ac.ed.dal
package structtensor
package codegen

import utils._
import Utils._
import compiler._
import CodegenUtils._

import scala.sys.process._
import scala.io.Source

object Codegen {

  def CPPFormat(a: Any): String = {
    a match {
      case s: String => if (s.endsWith("^-1")) s"1. / ${s.dropRight(3)}" else s
      case i: Int    => i.toString
      case d: Double => d.toString
      case v: Variable => v.name
      case i: Index =>
        i match {
          case v: Variable       => v.name
          case c: ConstantInt    => c.value.toString
          case c: ConstantDouble => c.value.toString
          case a @ Arithmetic(op, i1, i2) =>
            s"(${CPPFormat(i1)} ${op} ${CPPFormat(i2)})"
          case _ => ""
        }
      case a: Access =>
        if (a.vars.isEmpty) CPPFormat(a.name)
        else
          s"${CPPFormat(a.name)}[${a.vars.map(_.name).mkString("][")}]"
      case c @ Comparison(op, i, v) =>
        s"(${CPPFormat(i)} ${op} ${CPPFormat(v)})"
      case p: Prod =>
        p.exps.length match {
          case 0 => "∅"
          case 1 => CPPFormat(p.exps.head)
          case _ => s"(${p.exps.map(CPPFormat).mkString(" * ")})"
        }
      case s: SoP =>
        s match {
          case SoP(Seq())  => "∅"
          case SoP(Seq(p)) => CPPFormat(p)
          case SoP(prods)  => prods.map(CPPFormat).mkString(" + ")
        }
      case r: Rule => s"${CPPFormat(r.head)} = ${CPPFormat(r.body)}"
      case _       => ""
    }
  }

  def getConditionsOnVariable(
      v: Variable,
      conditions: Seq[Comparison]
  ): (Seq[String], Seq[String], Seq[Any], Seq[Comparison]) = {
    // This function finds all the conditions on the given variable `v` in the conditions list
    // It returns begin, end, and the rest of the conditions
    val (begin_end_equals_usedIndices) = conditions.zipWithIndex.flatMap {
      case (cond: Comparison, ind: Int) if cond.variable == v => {
        cond.op match {
          case "<=" => Some((s"${CPPFormat(cond.index)}", "", "", ind))
          case "<"  => Some((s"(${CPPFormat(cond.index)}) + 1", "", "", ind))
          case ">"  => Some(("", s"${CPPFormat(cond.index)}", "", ind))
          case ">=" => Some(("", s"(${CPPFormat(cond.index)}) + 1", "", ind))
          case "="  => Some(("", "", cond.index, ind))
        }
      }
      case (cond: Comparison, ind: Int) =>
        cond.index match {
          case variable: Variable if variable == v => {
            cond.op match {
              case ">=" => Some((s"${CPPFormat(cond.variable)}", "", "", ind))
              case ">" =>
                Some((s"(${CPPFormat(cond.variable)}) + 1", "", "", ind))
              case "<" => Some(("", s"${CPPFormat(cond.variable)}", "", ind))
              case "<=" =>
                Some(("", s"(${CPPFormat(cond.variable)}) + 1", "", ind))
              case "=" => Some(("", "", cond.variable, ind))
            }
          }
          case _ => None
        }
      case _ => None
    }
    val (begin, end, equals, usedIndices) = (
      begin_end_equals_usedIndices.map(_._1),
      begin_end_equals_usedIndices.map(_._2),
      begin_end_equals_usedIndices.map(_._3),
      begin_end_equals_usedIndices.map(_._4)
    )
    (
      begin.distinct.filterNot(_ == ""),
      end.distinct.filterNot(_ == ""),
      equals.distinct.filterNot(_ == ""),
      conditions.zipWithIndex
        .filterNot { case (_, ind) => usedIndices.contains(ind) }
        .map(_._1)
    )
  }

  def reorder(
      variables: Seq[Variable],
      conditions: Seq[Comparison],
      symbols: Seq[Variable]
  ): Seq[Variable] = {
    // afterMap is a <key, value> pair where key is the variable, and value is a list of variables that key depends on
    // If 2 variables depend on each other, they might get removed completely and cause an issue (e.g., a < b + 5 and b > a - 5.)
    // User must make sure that the conditions are not cyclic
    val afterMap_removeIfExist = conditions.map {
      case Comparison(_, i, v: Variable) => {
        if (variables.contains(v)) {
          i match {
            case va: Variable if (variables.contains(va)) =>
              if (variables.indexOf(va) < variables.indexOf(v))
                (v -> Seq(va), None)
              else (va -> Seq(v), None)
            case _ =>
              (
                v -> getVariablesInIndex(i).filter(variables.contains),
                getVariablesInIndex(i)
                  .filter(variables.contains)
                  .map(_ -> Seq(v))
                  .toMap
              )
          }
        } else if (symbols.contains(v)) {
          i match {
            case va: Variable if (variables.contains(va)) =>
              (va -> Seq(v), None)
            case _ => (None, None)
          }
        } else (None, None)
      }
    }
    val (afterMapInit, removeIfExistInit) = afterMap_removeIfExist.unzip
    val afterMap1 = afterMapInit
      .filterNot(_ == None)
      .groupBy { case (k: Variable, _) => k }
      .mapValues(_.flatMap { case (_: Variable, vars: Seq[Variable]) => vars })
      .map { case (k, v) => k -> v.distinct }
      .toMap // .foreach { case (k, v) => println(s"$k -> ${v}") }
    val removeIfExist = removeIfExistInit
      .filterNot(_ == None)
      .filterNot(_ == Map())
      .toSeq
      .flatten
      .groupBy { case (k: Variable, _) => k }
      .mapValues(_.flatMap { case (_: Variable, vars: Seq[Variable]) => vars })
      .map { case (k, v) => k -> v.distinct }
      .toMap
    val afterMap = afterMap1.map {
      case (k, v) => {
        val removeIfExistVars = removeIfExist.getOrElse(k, Seq())
        k -> v.filterNot(removeIfExistVars.contains)
      }
    }

    // indexMap is to sort the variables based on the variables that depend on them
    val indexMap = variables.zipWithIndex.toMap

    @scala.annotation.tailrec
    def reorderRec(
        afterMap: Map[Variable, Seq[Variable]],
        indexMap: Map[Variable, Int]
    ): Seq[Variable] = {
      val newIndexMap = afterMap.map { case (k, v) =>
        if (!v.filter(variables.contains).isEmpty)
          k -> (v.filter(variables.contains).map(indexMap).max + 1)
        else k -> indexMap(k)
      } ++ indexMap.filterNot { case (k, v) => afterMap.keySet.contains(k) }
      val sortedNewIndexMap =
        newIndexMap.toSeq.sortBy(_._2).map(_._1).zipWithIndex.toMap
      if (sortedNewIndexMap == indexMap) indexMap.toSeq.sortBy(_._2).map(_._1)
      else reorderRec(afterMap, sortedNewIndexMap)
    }
    reorderRec(afterMap, indexMap)
  }

  def codeGenSingleProd(
      computationHead: Access,
      conditions: Seq[Comparison],
      accesses: Seq[Access],
      symbols: Seq[Variable],
      codeLang: String,
      kind: AccessType
  ): String = {
    val variablesInit =
      (computationHead.vars ++ accesses.flatMap(_.vars)).distinct
    val variables = reorder(variablesInit, conditions, symbols)
    val (loopNests, restOfConditions, numberOfBrackets1) = variables.reverse.foldLeft(
      Seq[String](),
      conditions,
      0
    )((acc, v) => {
      val (begin, end, equalsFullList, rest) =
        getConditionsOnVariable(v, acc._2)
      val equals = equalsFullList.filter {
        case va: Variable => variables.contains(va) || symbols.contains(va)
        case _            => true
      }
      val eqCode = equals
        .map(e =>
          e match {
            case va: Variable =>
              if ((!begin.isEmpty || !end.isEmpty) && !symbols.contains(va))
                s"int ${CPPFormat(va)} = ${CPPFormat(v)};"
              else s"int ${CPPFormat(v)} = ${CPPFormat(va)};"
            case _ => s"int ${CPPFormat(v)} = ${CPPFormat(e)};"
          }
        )
        .mkString("\n")
      codeLang.toLowerCase() match {
        case "cpp" | "c++" => {
          (
            begin.length,
            end.length,
            eqCode.contains(s"int ${CPPFormat(v)} = ")
          ) match {
            case (0, 0, _) => (acc._1 :+ eqCode, rest, acc._3)
            case (0, 1, _) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} < ${end.mkString}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (0, _, _) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} < ${end.mkString("min({", ", ", "})")}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (1, 0, _) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin.mkString}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (_, 0, _) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin.mkString("max({", ", ", "})")}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (1, 1, false) => {
              if (end.mkString == s"(${begin.mkString}) + 1")
                (
                  acc._1 ++ Seq(
                    eqCode,
                    s"int ${CPPFormat(v)} = ${begin.mkString};"
                  ),
                  rest,
                  acc._3
                )
              else
                (
                  acc._1 ++ Seq(
                    eqCode,
                    s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(
                        v
                      )} < ${end.mkString}; ++${CPPFormat(v)}) {"
                  ),
                  rest,
                  acc._3 + 1
                )
            }
            case (1, _, false) =>
              (
                acc._1 ++ Seq(
                  eqCode,
                  s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(v)} < ${end
                      .mkString("min({", ", ", "})")}; ++${CPPFormat(v)}) {"
                ),
                rest,
                acc._3 + 1
              )
            case (_, 1, false) =>
              (
                acc._1 ++ Seq(
                  eqCode,
                  s"for (int ${CPPFormat(v)} = ${begin
                      .mkString("max({", ", ", "})")}; ${CPPFormat(v)} < ${end.mkString}; ++${CPPFormat(v)}) {"
                ),
                rest,
                acc._3 + 1
              )
            case (_, _, false) =>
              (
                acc._1 ++ Seq(
                  eqCode,
                  s"for (int ${CPPFormat(v)} = ${begin
                      .mkString("max({", ", ", "})")}; ${CPPFormat(v)} < ${end
                      .mkString("min({", ", ", "})")}; ++${CPPFormat(v)}) {"
                ),
                rest,
                acc._3 + 1
              )
            case (1, 1, true) => {
              if (end.mkString == s"(${begin.mkString}) + 1")
                (
                  acc._1 ++ Seq(
                    s"int ${CPPFormat(v)} = ${begin.mkString};",
                    eqCode
                  ),
                  rest,
                  acc._3
                )
              else
                (
                  acc._1 ++ Seq(
                    s"if (${CPPFormat(v)} >= ${begin.mkString} && ${CPPFormat(v)} < ${end.mkString}) {",
                    eqCode
                  ),
                  rest,
                  acc._3 + 1
                )
            }
            case (1, _, true) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin.mkString} && ${CPPFormat(v)} < ${end
                      .mkString("min({", ", ", "})")}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (_, 1, true) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin
                      .mkString("max({", ", ", "})")} && ${CPPFormat(v)} < ${end.mkString}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (_, _, true) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin
                      .mkString("max({", ", ", "})")} && ${CPPFormat(v)} < ${end
                      .mkString("min({", ", ", "})")}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
          }
        }
        case "c" => {
          (
            begin.length,
            end.length,
            eqCode.contains(s"int ${CPPFormat(v)} = ")
          ) match {
            case (0, 0, _) => (acc._1 :+ eqCode, rest, acc._3)
            case (0, 1, _) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} < ${end.mkString}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (0, _, _) => {
              val arr = getVar("arr")
              val c1 =
                s"size_t $arr[${end.length}] = ${end.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} < min($arr, ${end.length})) {",
                  eqCode,
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (1, 0, _) =>
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin.mkString}) {",
                  eqCode
                ),
                rest,
                acc._3 + 1
              )
            case (_, 0, _) => {
              val arr = getVar("arr")
              val c1 =
                s"size_t $arr[${begin.length}] = ${begin.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= max($arr, ${begin.length})) {",
                  eqCode,
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (1, 1, false) => {
              if (end.mkString == s"(${begin.mkString}) + 1")
                (
                  acc._1 ++ Seq(
                    eqCode,
                    s"int ${CPPFormat(v)} = ${begin.mkString};"
                  ),
                  rest,
                  acc._3
                )
              else
                (
                  acc._1 ++ Seq(
                    eqCode,
                    s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(
                        v
                      )} < ${end.mkString}; ++${CPPFormat(v)}) {"
                  ),
                  rest,
                  acc._3 + 1
                )
            }
            case (1, _, false) => {
              val arr = getVar("arr")
              val c1 =
                s"size_t $arr[${end.length}] = ${end.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  eqCode,
                  s"for (int ${CPPFormat(v)} = ${begin.mkString}; ${CPPFormat(
                      v
                    )} < min($arr, ${end.length}); ++${CPPFormat(v)}) {",
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (_, 1, false) => {
              val arr = getVar("arr")
              val c1 =
                s"size_t $arr[${begin.length}] = ${begin.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  eqCode,
                  s"for (int ${CPPFormat(v)} = max($arr, ${begin.length}); ${CPPFormat(
                      v
                    )} < ${end.mkString}; ++${CPPFormat(v)}) {",
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (_, _, false) => {
              val arr1 = getVar("arr1")
              val arr2 = getVar("arr2")
              val c1 =
                s"size_t $arr1[${begin.length}] = ${begin.mkString("{", ", ", "}")};"
              val c2 =
                s"size_t $arr2[${end.length}] = ${end.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  eqCode,
                  s"for (int ${CPPFormat(v)} = max($arr1, ${begin.length}); ${CPPFormat(
                      v
                    )} < min($arr2, ${end.length}); ++${CPPFormat(v)}) {",
                  c2,
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (1, 1, true) => {
              if (end.mkString == s"(${begin.mkString}) + 1")
                (
                  acc._1 ++ Seq(
                    s"int ${CPPFormat(v)} = ${begin.mkString};",
                    eqCode
                  ),
                  rest,
                  acc._3
                )
              else
                (
                  acc._1 ++ Seq(
                    s"if (${CPPFormat(v)} >= ${begin.mkString} && ${CPPFormat(v)} < ${end.mkString}) {",
                    eqCode
                  ),
                  rest,
                  acc._3 + 1
                )
            }
            case (1, _, true) => {
              val arr = getVar("arr")
              val c1 =
                s"size_t $arr[${end.length}] = ${end.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= ${begin.mkString} && ${CPPFormat(v)} < min($arr, ${end.length})) {",
                  eqCode,
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (_, 1, true) => {
              val arr = getVar("arr")
              val c1 =
                s"size_t $arr[${begin.length}] = ${begin.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= max($arr, ${begin.length}) && ${CPPFormat(v)} < ${end.mkString}) {",
                  eqCode,
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
            case (_, _, true) => {
              val arr1 = getVar("arr1")
              val arr2 = getVar("arr2")
              val c1 =
                s"size_t $arr1[${begin.length}] = ${begin.mkString("{", ", ", "}")};"
              val c2 =
                s"size_t $arr2[${end.length}] = ${end.mkString("{", ", ", "}")};"
              (
                acc._1 ++ Seq(
                  s"if (${CPPFormat(v)} >= max($arr1, ${begin.length}) && ${CPPFormat(
                      v
                    )} < min($arr2, ${end.length})) {",
                  eqCode,
                  c2,
                  c1
                ),
                rest,
                acc._3 + 1
              )
            }
          }
        }
        case _ => throw new Exception(s"Unsupported language: $codeLang")
      }
    })
    val restString = restOfConditions.collect { case c @ Comparison(op, i, v) =>
      op match {
        case "=" => s"int ${CPPFormat(v)} = ${CPPFormat(i)};"
        case _   => s"if (${CPPFormat(i)} $op ${CPPFormat(v)}) {"
      }
    }
    // We reverse the loop nests because the first variable has all the conditions thus depending on the most variables
    val loopNestsString = (loopNests.reverse ++ restString).mkString("\n")
    val numberOfBrackets =
      numberOfBrackets1 + restOfConditions.filterNot(_.op == "=").length
    val brackets = (0 until numberOfBrackets).map(_ => "}").mkString("\n")
    val computationBody = CPPFormat(Prod(accesses))
    val assignment = kind match {
      case RedundancyMap => "="
      case _             => "+="
    }
    s"$loopNestsString\n${CPPFormat(computationHead)} $assignment $computationBody;\n$brackets"
  }

  def apply(
      rule: Rule,
      symbols: Seq[Variable],
      codeLang: String,
      kind: AccessType
  ): String = {
    val computationHead = rule.head
    rule.body.prods.zipWithIndex
      .map {
        case (prod, ind) => {
          val conditions =
            prod.exps.collect { case condition: Comparison => condition }
          val accesses = prod.exps.collect { case access: Access => access }
          codeGenSingleProd(
            computationHead,
            conditions,
            accesses,
            symbols,
            codeLang,
            kind
          )
        }
      }
      .mkString("\n")
  }
}
