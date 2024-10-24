package uk.ac.ed.dal
package structtensor
package utils

import compiler._

import java.io._
import java.nio.file.{Files, Paths}

object Utils {
  def write2File(filename: String, s: String, append: Boolean = false): Unit = {
    val path = Paths.get(filename)
    if (path.getParent != null && !Files.exists(path.getParent)) {
      Files.createDirectories(path.getParent)
    }
    val bw = new BufferedWriter(new FileWriter(new File(filename), append))
    bw.write(s)
    bw.close()
  }

  var cnt = 0
  def getVar(name: String): String = {
    cnt += 1
    s"$name$cnt"
  }

  def emptyProd(): Prod = Prod(Seq[Exp]())

  def emptySoP(): SoP = SoP(Seq[Prod]())

  def emptyAccess(): Access = Access("", Seq[Variable](), Tensor)

  def emptyRule(): Rule = Rule(emptyAccess(), emptySoP())

  def prodTimesProd(prod1: Prod, prod2: Prod): Prod = {
    if (prod1.exps.isEmpty || prod2.exps.isEmpty) emptyProd()
    else Prod(prod1.exps ++ prod2.exps)
  }

  def prodTimesSoP(prod: Prod, sop: SoP): SoP = {
    if (prod.exps.isEmpty || sop.prods.isEmpty) emptySoP()
    else SoP(sop.prods.map(cur => prodTimesProd(prod, cur)))
  }

  def SoPTimesSoP(sop1: SoP, sop2: SoP): SoP = {
    if (sop1.prods.isEmpty || sop2.prods.isEmpty) emptySoP()
    else SoP(sop1.prods.flatMap(cur => prodTimesSoP(cur, sop2).prods))
  }

  def multSoP(sops: Seq[SoP]): SoP = {
    if (sops.isEmpty) emptySoP()
    else sops.tail.foldLeft(sops.head)((acc, cur) => SoPTimesSoP(acc, cur))
  }

  def mergeMap[A, B](ms: Seq[Map[A, B]])(f: (B, B) => B): Map[A, B] =
    ms.flatten.foldLeft(Map[A, B]())((a, kv) =>
      a + (if (a.contains(kv._1)) (kv._1 -> f(a(kv._1), kv._2)) else kv)
    )

  implicit class DimInfoOps(d: DimInfo) {
    def toAccessMap: Map[Access, Seq[Dim]] =
      Map[Access, Seq[Dim]](d.access -> d.dims)
    def toSoP: SoP = SoP(
      Seq(Prod((d.access.vars zip d.dims).flatMap { case (variable, dim) =>
        Seq(
          Comparison("<=", ConstantInt(0), variable),
          Comparison(">", dim, variable)
        )
      }))
    )
  }

  implicit class SeqDimInfoOps(d: Seq[DimInfo]) {
    def toAccessMap: Map[Access, Seq[Dim]] =
      d.foldLeft(Map.empty[Access, Seq[Dim]])((acc, cur) =>
        mergeMap(Seq(acc, cur.toAccessMap))((v1, v2) => v1 ++ v2)
      )
  }

  implicit class StringOps(s: String) {
    def uniqueName = s"${s}_US"
    def redundancyName = s"${s}_RM"
    def compressedName = s"${s}_C"
    def dimensionName = s"${s}_D"
    def inverseName = if (s.endsWith("^-1")) s.dropRight(3) else s"${s}^-1"
    def deinversifiedName = if (s.endsWith("^-1")) s.dropRight(3) else s
    def toVar: Variable = Variable(s)
    def redundancyVars: Variable = s.toVar.redundancyVars
  }

  implicit class VariableOps(v: Variable) {
    def redundancyVars = Variable(s"${v.name}p")
  }

  implicit class SeqVariableOps(v: Seq[Variable]) {
    def redundancyVars = v.map(_.redundancyVars)
    def redundancyVarsInplace = v ++ v.redundancyVars
  }

  def alphaRename(
      index: Index,
      alphaRenameMap: Map[Variable, Variable]
  ): Index = index match {
    case v: Variable => alphaRenameMap.getOrElse(v, v)
    case Arithmetic(op, i1, i2) =>
      Arithmetic(
        op,
        alphaRename(i1, alphaRenameMap),
        alphaRename(i2, alphaRenameMap)
      )
    case _ => index
  }

  def alphaRename(sop: SoP, alphaRenameMap: Map[Variable, Variable]): SoP = {
    SoP(sop.prods.map(p => {
      Prod(p.exps.map {
        case Access(n, v, k) =>
          Access(n, v.map(v2 => alphaRenameMap.getOrElse(v2, v2)), k)
        case Comparison(op, i, v) =>
          Comparison(
            op,
            alphaRename(i, alphaRenameMap),
            alphaRenameMap.getOrElse(v, v)
          )
        case _ => throw new Exception("Unknown expression")
      })
    }))
  }

  def getNonDimensionVariables(prod: Prod): Seq[Variable] = prod.exps.flatMap {
    case Access(_, vars, _) => vars.distinct
    case _                  => Seq()
  }.distinct

  def getNonDimensionVariables(sop: SoP): Seq[Variable] =
    sop.prods.flatMap(getNonDimensionVariables).distinct

  def getNonDimensionVariables(rule: Rule): Seq[Variable] =
    (rule.head.vars ++ getNonDimensionVariables(rule.body)).distinct

  implicit class MapOps[V <: RuleOrSoP](m: Map[Access, V]) {
    def getByName(name: String): Option[V] =
      m.keys.find(_.name == name).map(m)
    def getByNameOrElse(name: String, default: V): V =
      getByName(name).getOrElse(default)
    def containsByName(name: String): Boolean = m.keys.exists(_.name == name)
    def getByAccessNameAndReplaceVars(access: Access): Option[V] =
      m.keys.find(_.name == access.name).map { key =>
        val value = m(key)
        val body = value match {
          case Rule(_, body) => body
          case v: SoP        => v
        }
        val nonDimVarsValue = getNonDimensionVariables(body)
        val alphaRenameRequiredVars = nonDimVarsValue.diff(key.vars)
        val newBody = alphaRename(
          body,
          (key.vars.redundancyVarsInplace ++ alphaRenameRequiredVars.redundancyVarsInplace)
            .zip(
              access.vars.redundancyVarsInplace ++ alphaRenameRequiredVars
                .map(_ => Variable(getVar("i")))
                .redundancyVarsInplace
            )
            .toMap
        )

        m(key) match {
          case r: Rule => Rule(access, newBody).asInstanceOf[V]
          case s: SoP  => newBody.asInstanceOf[V]
        }
      }
    def getByAccessNameAndReplaceVarsOrElse(
        access: Access,
        default: V
    ): V =
      getByAccessNameAndReplaceVars(access).getOrElse(default)
  }

  implicit class SeqOps(s: Seq[Access]) {
    def containsByName(name: String): Boolean = s.exists(_.name == name)
  }

  def concatSoP(sops: Seq[SoP]): SoP = SoP(sops.flatMap(_.prods))

  def MLIR_start_timer_code(postfix: String = ""): String = s"""
    %stime$postfix = "func.call"() {callee = @timer} : () -> i64
"""

  def CPP_init_code(): String = s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

"""

  def CPP_timer_start(postfix: String = ""): String =
    s"long time$postfix = 0, start$postfix, end$postfix;\nstart$postfix = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"

  def CPP_timer_end(postfix: String = ""): String =
    s"end$postfix = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();\ntime$postfix = end$postfix - start$postfix;\ncout << time$postfix << endl;"

  def C_timer_start(postfix: String = ""): String =
    s"struct timespec start$postfix = timer_start();"

  def C_timer_end(postfix: String = ""): String =
    s"long time$postfix = timer_end(start$postfix);" + "\nprintf(\"%ld\\n\", " + s"time$postfix);"

  def MLIR_timer_end(postfix: String = ""): String = s"""
%time$postfix = "func.call"(%stime$postfix) {callee = @timer_elapsed} : (i64) -> i64
"func.call"(%time$postfix) {callee = @print_i64} : (i64) -> ()"""

  def init_timer(lang: String, postfix: String = ""): String =
    lang.toUpperCase() match {
      case "C"        => C_timer_start(postfix = postfix)
      case "CPP"      => CPP_timer_start(postfix = postfix)
      case "MLIR"     => MLIR_start_timer_code(postfix = postfix)
      case "SNIPPETS" => MLIR_start_timer_code(postfix = postfix)
      case _          => throw new Exception("Unknown code language")
    }

  def end_timer(lang: String, postfix: String = ""): String =
    lang.toUpperCase() match {
      case "C"        => C_timer_end(postfix = postfix)
      case "CPP"      => CPP_timer_end(postfix = postfix)
      case "MLIR"     => MLIR_timer_end(postfix = postfix)
      case "SNIPPETS" => MLIR_timer_end(postfix = postfix)
      case _          => throw new Exception("Unknown code language")
    }

  def unboundVariables(rules: Seq[Rule]): Set[String] =
    allVariables(rules).diff(boundVariables(rules))

  def allVariables(index: Index): Set[String] = {
    index match {
      case Variable(name)        => Set(name)
      case Arithmetic(_, i1, i2) => allVariables(i1) ++ allVariables(i2)
      case _                     => Set.empty[String]
    }
  }

  def allVariables(rules: Seq[Rule]): Set[String] = {
    rules.flatMap { r =>
      r.head.vars.map(_.name).toSet ++
        r.body.prods
          .flatMap(_.exps.collect {
            case Access(_, vars, _) => vars.map(_.name).toSet
            case Comparison(_, index, variable) =>
              allVariables(index) + variable.name
          })
          .flatten
          .toSet
    }.toSet
  }

  def boundVariables(rules: Seq[Rule]): Set[String] = {
    rules.flatMap { r =>
      r.head.vars.map(_.name).toSet ++
        r.body.prods
          .flatMap(_.exps.collect { case Access(_, vars, _) =>
            vars.map(_.name).toSet
          })
          .flatten
    }.toSet
  }

  def getVariablesInIndex(i: Index): Seq[Variable] = i match {
    case v: Variable => Seq(v)
    case a @ Arithmetic(_, i1, i2) =>
      (getVariablesInIndex(i1) ++ getVariablesInIndex(i2)).distinct
    case _ => Seq()
  }

  def getVariables(e: Exp): Seq[Variable] = e match {
    case Access(_, vars, _)  => vars.distinct
    case Comparison(_, i, v) => (getVariablesInIndex(i) :+ v).distinct
    case _                   => Seq()
  }
}
