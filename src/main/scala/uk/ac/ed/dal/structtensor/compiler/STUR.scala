package uk.ac.ed.dal
package structtensor
package compiler

sealed trait Exp {
  def prettyFormat(): String
  def cFormat(): String
  def cFormat(m: Map[Variable, Index]): String
  def vars2RedundancyVars(): Exp
}

sealed trait Index {
  def prettyFormat(): String
  def cFormat(): String
  def cFormat(m: Map[Variable, Index]): String
  def vars2RedundancyVars(): Index
}

sealed trait Dim extends Index

sealed trait AccessType {
  def prettyFormat(): String
  def cFormat(): String
}

case object Tensor extends AccessType {
  def prettyFormat(): String = "T"
  def cFormat(): String = "T"
  def cFormat(m: Map[Variable, Index]): String = cFormat
}

case object CompressedTensor extends AccessType {
  def prettyFormat(): String = "C"
  def cFormat(): String = "C"
  def cFormat(m: Map[Variable, Index]): String = cFormat
}

case object UniqueSet extends AccessType {
  def prettyFormat(): String = "U"
  def cFormat(): String = "U"
  def cFormat(m: Map[Variable, Index]): String = cFormat
}

case object RedundancyMap extends AccessType {
  def prettyFormat(): String = "R"
  def cFormat(): String = "R"
  def cFormat(m: Map[Variable, Index]): String = cFormat
}

case object DimensionType extends AccessType {
  def prettyFormat(): String = "D"
  def cFormat(): String = "D"
  def cFormat(m: Map[Variable, Index]): String = cFormat
}


case class Variable(name: String) extends Index with Dim {
  def prettyFormat(): String = name
  def cFormat(): String = if (name.endsWith("'")) name.substring(0, name.size - 1) + "p" else name // renames redundancy vars to a writable format in C
  def cFormat(m: Map[Variable, Index]): String = if (m.keySet.contains(this)) m.get(this).get.cFormat(m) else cFormat
  def vars2RedundancyVars(): Variable = Variable(s"${name}p")
}

case class ConstantDouble(value: Double) extends Index {
  def prettyFormat(): String = value.toString
  def cFormat(): String = value.toString
  def cFormat(m: Map[Variable, Index]): String = cFormat
  def vars2RedundancyVars(): ConstantDouble = this
}

case class ConstantInt(value: Int) extends Index with Dim {
  def prettyFormat(): String = value.toString
  def cFormat(): String = value.toString
  def cFormat(m: Map[Variable, Index]): String = cFormat
  def vars2RedundancyVars(): ConstantInt = this
}

case class Arithmetic(op: String, index1: Index, index2: Index) extends Index with Dim {
  def prettyFormat(): String = s"(${index1.prettyFormat} $op ${index2.prettyFormat})"
  def cFormat(): String = s"(${index1.cFormat} $op ${index2.cFormat})"
  def cFormat(m: Map[Variable, Index]): String = {
    val ind1: String = if (index1.isInstanceOf[Variable] && m.keySet.contains(index1.asInstanceOf[Variable])) m.get(index1.asInstanceOf[Variable]).get.cFormat(m) else index1.cFormat
    val ind2: String = if (index2.isInstanceOf[Variable] && m.keySet.contains(index2.asInstanceOf[Variable])) m.get(index2.asInstanceOf[Variable]).get.cFormat(m) else index2.cFormat
    s"($ind1 $op $ind2)"
  }
  def vars2RedundancyVars(): Arithmetic = Arithmetic(op, index1.vars2RedundancyVars, index2.vars2RedundancyVars)
}

case class Access(name: String, vars: Seq[Variable], kind: AccessType) extends Exp {
  import STURHelper._
  def prettyFormat(): String = {
    val pr = vars.foldLeft("")((acc, cur) => s"$acc, ${cur.prettyFormat}")
    if (pr == "") name else s"${name}(${pr.substring(2, pr.length)})"
  }
  def cFormat(): String = vars.foldLeft(name)((acc, cur) => s"$acc[${cur.cFormat}]")
  def cFormat(m: Map[Variable, Index]): String = vars.foldLeft(name)((acc, cur) => s"$acc[${cur.cFormat(m)}]")
  def cFormat(m: Map[Variable, Index], dl: Function[Seq[Variable], Seq[Index]]): String = dl(vars).foldLeft(name)((acc, cur) => s"$acc[${cur.cFormat(m)}]")
  def vars2RedundancyVars(): Access = Access(name, vars.foldLeft(Seq[Variable]())((acc, cur) => acc :+ cur.vars2RedundancyVars), kind)
  def loadMLIR(m: Map[Variable, Index], kind: String = "affine"): String = {
    val (varsStr, sizeStr, indexStr) = vars.foldLeft(("", "", ""))((acc2, v) => {
      val (varsStr, sizeStr, indexStr) = acc2
      val newVarStr = if (varsStr.length == 0) s"%${v.cFormat(m)}" else s"$varsStr, %${v.cFormat(m)}"
      val newSizeStr = s"${sizeStr}?x"
      val newIndexStr = if (indexStr.length == 0) s"index" else s"$indexStr, index"
      (newVarStr, newSizeStr, newIndexStr)
    })
    if (kind == "affine") s"""affine.load %$name[$varsStr] : memref<${sizeStr}f64>\n"""
    else s""""memref.load"(%$name, $varsStr) : (memref<${sizeStr}f64>, $indexStr) -> f64\n"""
  }
  def uniqueHead(): Access = Access(name.uniqueName, vars, UniqueSet)
  def redundancyHead(): Access = Access(name.redundancyName, vars.redundancyVarsInplace, RedundancyMap)
  def compressedHead(): Access = Access(name.compressedName, vars, CompressedTensor)
  def dimensionHead(): Access = Access(name.dimensionName, vars, DimensionType)
}

case class Comparison(op: String, index: Index, variable: Variable) extends Exp {
  def prettyFormat(): String = if (!(!index.isInstanceOf[Variable] && op == "=")) s"(${index.prettyFormat} $op ${variable.prettyFormat})" else s"(${variable.prettyFormat} $op ${index.prettyFormat})"
  def cFormat(): String = if (!(!index.isInstanceOf[Variable] && op == "=")) s"(${index.cFormat} $op ${variable.cFormat})" else s"(${variable.cFormat} $op ${index.cFormat})"
  def cFormat(m: Map[Variable, Index]): String = if (!(!index.isInstanceOf[Variable] && op == "=")) s"(${index.cFormat(m)} $op ${variable.cFormat(m)})" else s"(${variable.cFormat(m)} $op ${index.cFormat(m)})"
  def vars2RedundancyVars(): Comparison = Comparison(op, index.vars2RedundancyVars, variable.vars2RedundancyVars)
}

case class Prod(exps: Seq[Exp]) {
  def prettyFormat(): String = {
    val pr = exps.foldLeft("")((acc, cur) => s"$acc * ${cur.prettyFormat}")
    if (exps.length == 0) "∅"
    else s"${pr.substring(3, pr.length)}"
  } 
  def cFormat(): String = {
    val pr = exps.foldLeft("")((acc, cur) => s"$acc * ${cur.cFormat}")
    if (exps.length == 0) "∅"
    else s"(${pr.substring(3, pr.length)})"
  } 
  def cFormat(m: Map[Variable, Index]): String = {
    val pr = exps.foldLeft("")((acc, cur) => s"$acc * ${cur.cFormat(m)}")
    if (exps.length == 0) "∅"
    else s"(${pr.substring(3, pr.length)})"
  } 
  def cFormat(m: Map[Variable, Index], dlm: Map[Exp, Function[Seq[Variable], Seq[Index]]]): String = {
    val defaultMap: Function[Seq[Variable], Seq[Index]] = (vars: Seq[Variable]) => vars
    val pr = exps.foldLeft("")((acc, cur) => {
      if (cur.isInstanceOf[Access]) s"$acc * ${cur.asInstanceOf[Access].cFormat(m, dlm.getOrElse(cur, defaultMap))}"
      else s"$acc * ${cur.cFormat(m)}"
    })
    if (exps.length == 0) "∅"
    else s"(${pr.substring(3, pr.length)})"
  }
  def MLIRFormat(m: Map[Variable, Index] = Map.empty[Variable, Index], final_sum: String = "final_sum", cnt_inc: Int = 0): String = {
    var cnt = cnt_inc
    val accesses = exps.filter(e => e.isInstanceOf[Access]).map(e => e.asInstanceOf[Access])
    val (vars, varsCode): (Seq[String], String) = accesses.foldLeft((Seq.empty[String], ""))((acc, cur) => {
      val allVars = acc._1
      val code = acc._2
      val newVar = s"tmp$cnt"
      val newCode = s"""%$newVar = ${cur.loadMLIR(m)}\n"""
      cnt += 1
      (allVars :+ newVar, code + newCode)
    })
    val (multCode, lastMult) = vars.slice(1, vars.length - 1).foldLeft(("", vars(0)))((acc, cur) => {
      val code = acc._1
      val last = acc._2
      val newProd = s"prod$cnt"
      val newCode = s"""%$newProd = "arith.mulf"(%$last, %$cur) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"""
      cnt += 1
      (code + newCode, newProd)
    })
    val finalMultCode = s"""%$final_sum = "arith.mulf"(%$lastMult, %${vars(vars.length - 1)}) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"""
    s"$varsCode$multCode$finalMultCode"
  } 
  
}

case class SoP(prods: Seq[Prod]) {
  var cnt = 0
  def prettyFormat(): String = {
    val pr = prods.foldLeft("")((acc, cur) => s"$acc + ${cur.prettyFormat}")
    if (prods.length == 0) "∅"
    else s"${pr.substring(3, pr.length)}"
  }
  def cFormat(): String = {
    val pr = prods.foldLeft("")((acc, cur) => s"$acc + ${cur.cFormat}")
    if (prods.length == 0) "∅"
    else s"(${pr.substring(3, pr.length)})"
  }
  def cFormat(m: Map[Variable, Index]): String = {
    val pr = prods.foldLeft("")((acc, cur) => s"$acc + ${cur.cFormat(m)}")
    if (prods.length == 0) "∅"
    else s"(${pr.substring(3, pr.length)})"
  }

  def vars2RedundancyVars(): SoP = {
    SoP(prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      acc :+ Prod(prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => {
        acc2 :+ exp.vars2RedundancyVars()
      }))
    }))
  }
  def MLIRFormat(m: Map[Variable, Index] = Map.empty[Variable, Index], final_val: String = "final_val", cnt_inc: Int = 0): String = {
    var cnt = cnt_inc
    val (vars, varsCode) = prods.foldLeft((Seq.empty[String], ""))((acc, cur) => {
      val allVars = acc._1
      val code = acc._2
      val newVar = s"tmpS$cnt"
      val newCode = cur.MLIRFormat(m, newVar, cnt_inc=cnt_inc)
      cnt += 1
      (allVars :+ newVar, code + newCode)
    })
    val (sumCode, lastSum) = vars.slice(1, vars.length - 1).foldLeft(("", vars(0)))((acc, cur) => {
      val code = acc._1
      val last = acc._2
      val newSum = s"sum$cnt"
      val newCode = s"""%$newSum = "arith.addf"(%$last, %$cur) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"""
      (code + newCode, newSum)
    })
    val finalSumCode = s"""%$final_val = "arith.addf"(%$lastSum, %${vars(vars.length - 1)}) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"""
    s"$varsCode$sumCode$finalSumCode"
  }
}

case class Rule(head: Access, body: SoP) {
  def prettyFormat(): String = s"${head.prettyFormat} := ${body.prettyFormat}"
  def cFormat(): String = s"${head.cFormat} = ${body.cFormat};"
  def cPeqFormat(): String = s"${head.cFormat} += ${body.cFormat};"
  def cFormat(m: Map[Variable, Index]): String = s"${head.cFormat(m)} = ${body.cFormat(m)};"
  def cPeqFormat(m: Map[Variable, Index]): String = s"${head.cFormat(m)} += ${body.cFormat(m)};"
  def MLIRFormat(m: Map[Variable, Index] = Map.empty[Variable, Index], peqMode: Boolean = false, cnt_inc: Int = 0): String = {
    val final_val = s"final_val$cnt_inc"
    val bodyCode = body.MLIRFormat(m, final_val, cnt_inc=cnt_inc)
    val (varsStr, sizeStr, indexStr) = head.vars.foldLeft(("", "", ""))((acc2, v) => {
      val (varsStr, sizeStr, indexStr) = acc2
      val newVarStr = if (varsStr.length == 0) s"%${v.cFormat(m)}" else s"$varsStr, %${v.cFormat(m)}"
      val newSizeStr = s"${sizeStr}?x"
      val newIndexStr = if (indexStr.length == 0) s"index" else s"$indexStr, index"
      (newVarStr, newSizeStr, newIndexStr)
    })
    if (peqMode) s"""$bodyCode\n"%r236 = affine.load %${head.name}[$varsStr] : memref<${sizeStr}f64>\n%r237 = arith.addf(%r236, %$final_val) {"fastmath" = #arith.fastmath<fast>}\naffine.store %r237, %${head.name}[$varsStr] : memref<${sizeStr}f64>\n"""
    else s"""$bodyCode\naffine.store %$final_val, %${head.name}[$varsStr] : memref<${sizeStr}f64>\n"""
  }
}

case class Interval(begin: Seq[Index], end: Seq[Index])

case class DimInfo(access: Access, dims: Seq[Dim]) // how to assert that dims.size == access.vars.size?

object STURHelper {
  def emptyProd(): Prod = Prod(Seq[Exp]())

  def emptySoP(): SoP = SoP(Seq[Prod]())

  def emptyAccess(): Access = Access("", Seq[Variable](), Tensor)

  def emptyRule(): Rule = Rule(emptyAccess(), emptySoP())

  def emptyDimInfo(): DimInfo = DimInfo(emptyAccess(), Seq.empty[Dim])

  def trueComparison(): Comparison = Comparison("<=", "0".toVar, "0".toVar)

  implicit class StringOps(s: String) {
    def uniqueName = s"${s}_US"
    def redundancyName = s"${s}_RM"
    def compressedName = s"${s}_C"
    def dimensionName = s"${s}_D"
    def toVar: Variable = Variable(s)
    def redundancyVars: Variable = s.toVar.redundancyVars
  }

  implicit class VariableOps(v: Variable) {
    def redundancyVars = Variable(s"${v.name}p")
    def toAccess(kind: AccessType): Access = Access("", Seq(v), kind)
  }

  implicit class SeqVariableOps(v: Seq[Variable]) {
    def redundancyVars = v.foldLeft(Seq[Variable]())((acc, cur) => acc :+ cur.redundancyVars)
    def redundancyVarsInplace = v ++ v.redundancyVars
    def toAccess(kind: AccessType): Access = Access("", v, kind)
  }
}
