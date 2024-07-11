package uk.ac.ed.dal
package structtensor
package compiler

import utils._

sealed trait Exp {
  def prettyFormat(): String
  def vars2RedundancyVars(): Exp
}

sealed trait Index {
  def prettyFormat(): String
  def vars2RedundancyVars(): Index
}

sealed trait Dim extends Index

sealed trait AccessType {
  def prettyFormat(): String
}

case object Tensor extends AccessType {
  def prettyFormat(): String = "T"
}

case object CompressedTensor extends AccessType {
  def prettyFormat(): String = "C"
}

case object UniqueSet extends AccessType {
  def prettyFormat(): String = "U"
}

case object RedundancyMap extends AccessType {
  def prettyFormat(): String = "R"
}

case object DimensionType extends AccessType {
  def prettyFormat(): String = "D"
}

case class Variable(name: String) extends Index with Dim {
  def prettyFormat(): String = name
  def vars2RedundancyVars(): Variable = Variable(s"${name}p")
}

case class ConstantDouble(value: Double) extends Index {
  def prettyFormat(): String = value.toString
  def vars2RedundancyVars(): ConstantDouble = this
}

case class ConstantInt(value: Int) extends Index with Dim {
  def prettyFormat(): String = value.toString
  def vars2RedundancyVars(): ConstantInt = this
}

case class Arithmetic(op: String, index1: Index, index2: Index)
    extends Index
    with Dim {
  def prettyFormat(): String =
    s"(${index1.prettyFormat} $op ${index2.prettyFormat})"
  def vars2RedundancyVars(): Arithmetic =
    Arithmetic(op, index1.vars2RedundancyVars, index2.vars2RedundancyVars)
}

case class Access(name: String, vars: Seq[Variable], kind: AccessType)
    extends Exp {
  import Utils._
  def prettyFormat(): String = {
    val pr = vars.map(_.prettyFormat).mkString(", ")
    if (pr.isEmpty) name else s"$name($pr)"
  }

  def vars2RedundancyVars(): Access =
    Access(name, vars.map(_.vars2RedundancyVars), kind)
  def uniqueHead(): Access = Access(name.uniqueName, vars, UniqueSet)
  def redundancyHead(): Access =
    Access(name.redundancyName, vars.redundancyVarsInplace, RedundancyMap)
  def compressedHead(): Access =
    Access(name.compressedName, vars, CompressedTensor)
  def dimensionHead(): Access = Access(name.dimensionName, vars, DimensionType)
  def inverseHead(): Access = Access(name.inverseName, vars, kind)
  def deinversifiedHead(): Access = Access(name.deinversifiedName, vars, kind)
}

case class Comparison(op: String, index: Index, variable: Variable)
    extends Exp {
  def prettyFormat(): String = index match {
    case _: Variable | _ if op != "=" =>
      s"(${index.prettyFormat} $op ${variable.prettyFormat})"
    case _ => s"(${variable.prettyFormat} $op ${index.prettyFormat})"
  }
  def vars2RedundancyVars(): Comparison =
    Comparison(op, index.vars2RedundancyVars, variable.vars2RedundancyVars)
}

case class Prod(exps: Seq[Exp]) {
  def prettyFormat(): String = {
    val pr = exps.map(_.prettyFormat).mkString(" * ")
    if (pr.isEmpty) "∅" else pr
  }
  def inverse(): Prod = Prod(
    exps.map(e =>
      e match {
        case a: Access => a.inverseHead()
        case _         => e
      }
    )
  )
}

case class SoP(prods: Seq[Prod]) {
  def prettyFormat(): String = {
    val pr = prods.map(_.prettyFormat).mkString(" + ")
    if (pr.isEmpty) "∅" else pr
  }

  def vars2RedundancyVars(): SoP = {
    SoP(prods.map { prod =>
      Prod(prod.exps.map(_.vars2RedundancyVars))
    })
  }

  def inverse(): SoP = SoP(prods.map(_.inverse()))
}

case class Rule(head: Access, body: SoP) {
  def prettyFormat(): String = s"${head.prettyFormat} := ${body.prettyFormat}"
  def inverse(): Rule = Rule(head.inverseHead(), body.inverse())
}

case class Interval(begin: Seq[Index], end: Seq[Index])

case class DimInfo(access: Access, dims: Seq[Dim])
