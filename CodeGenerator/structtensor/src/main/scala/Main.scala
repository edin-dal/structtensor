import java.io._ 

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


case class Variable(name: String) extends Index with Dim {
  def prettyFormat(): String = name
  def cFormat(): String = if (name.endsWith("'")) name.substring(0, name.size - 1) + "p" else name // renames redundancy vars to a writable format in C
  def cFormat(m: Map[Variable, Index]): String = if (m.keySet.contains(this)) m.get(this).get.cFormat(m) else cFormat
  def vars2RedundancyVars(): Variable = Variable(s"${name}'")
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
    else s"(${pr.substring(3, pr.length)})"
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
    else s"(${pr.substring(3, pr.length)})"
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

object Main extends App {

  def emptyProd(): Prod = Prod(Seq[Exp]())

  def emptySoP(): SoP = SoP(Seq[Prod]())

  def emptyAccess(): Access = Access("", Seq[Variable](), Tensor)

  def emptyRule(): Rule = Rule(emptyAccess(), emptySoP())

  def emptyDimInfo(): DimInfo = DimInfo(emptyAccess(), Seq.empty[Dim])

  def trueComparison(): Comparison = Comparison("<=", "0".toVar, "0".toVar)

  def pprint(r: Rule): Unit = println(r.prettyFormat)

  def pprintTest(rTURD: (Rule, (Rule, Rule, DimInfo))): Unit = {
    println("=========================================")
    println("Computation:")
    pprint(rTURD._1)
    println("Unique Set:")
    pprint(rTURD._2._1)
    println("Redundancy Map:")
    pprint(rTURD._2._2)
    println("=========================================")
    println()
  }

  var cnt = 0
  def getVar(name: String): String = {
    cnt += 1
    return s"$name$cnt"
  }

  def prodTimesProd(prod1: Prod, prod2: Prod): Prod = {
    if (prod1.exps.size == 0 || prod2.exps.size == 0) emptyProd()
    else Prod(prod1.exps ++ prod2.exps)
  } 

  def prodMult(prods: Seq[Prod]): Prod = {
    if (prods.size == 0) emptyProd()
    else prods.slice(1, prods.size).foldLeft(prods(0))((acc, cur) => prodTimesProd(acc, cur))
  }

  def prodTimesSoP(prod: Prod, sop: SoP): SoP = {
    if (prod.exps.size == 0 || sop.prods.size == 0) emptySoP()
    else {
      val prods: Seq[Prod] = sop.prods.foldLeft(Seq[Prod]())((acc, cur) => acc :+ prodTimesProd(prod, cur))
      SoP(prods)
    }
  }

  def SoPTimesSoP(sop1: SoP, sop2: SoP): SoP = {
    if (sop1.prods.size == 0 || sop2.prods.size == 0) emptySoP()
    else {
      val prods: Seq[Prod] = sop1.prods.foldLeft(Seq[Prod]())((acc, cur) => acc ++ prodTimesSoP(cur, sop2).prods)
      SoP(prods)
    }
  }

  def multSoP(sops: Seq[SoP]): SoP = {
    if (sops.size == 0) emptySoP()
    else sops.slice(1, sops.length).foldLeft(sops(0))((acc, cur) => SoPTimesSoP(acc, cur))
  } 

  def includeBoundaries(sop: SoP, bounds: Map[Access, Prod], e: Access, t: AccessType): SoP = {
    if (!bounds.contains(e) || sop == emptySoP()) sop
    else SoPTimesSoP(sop, SoP(Seq(bounds.get(e).get)))
  }

  def concatSoP(sops: Seq[SoP]): SoP = {
    val prods: Seq[Prod] = sops.foldLeft(Seq[Prod]())((acc, cur) => acc ++ cur.prods)
    SoP(prods)
  }

  def isIntersectEmpty(inpVars1: Seq[Variable], inpVars2: Seq[Variable]): Boolean = inpVars1.intersect(inpVars2).isEmpty

  def vectorizeComparisonMultiplication(op: String, varsLeft: Seq[Variable], varsRight: Seq[Variable]): Prod = {
    val exps: Seq[Comparison] = (varsLeft zip varsRight).foldLeft(Seq[Comparison]())((acc, cur) => acc :+ Comparison(op, cur._1, cur._2))
    Prod(exps)
  }

  def isSoPEquals(sop1: SoP, sop2: SoP): Boolean = {
    val prodsSet1: Set[Prod] = sop1.prods.toSet
    val prodsSet2: Set[Prod] = sop2.prods.toSet
    val prodsExpsSet1: Set[Set[Exp]] = prodsSet1.map(s => s.exps.toSet)
    val prodsExpsSet2: Set[Set[Exp]] = prodsSet2.map(s => s.exps.toSet)
    prodsExpsSet1 == prodsExpsSet2
  }

  def prodSubProd(prod1: Prod, prod2: Prod): SoP = { // for now it only supports (b <= x < c) - (x = b)
    if (prod1.exps.length == 2) { // this doesn't work for now because (prod1.exps.length != 2) and each product is too many of these expressions // It's vectorized!
      val e1 = prod1.exps(0)
      val e2 = prod1.exps(1)
      (e1, e2) match {
        case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
          if (op1 == "<=" && op2 == "<" && variable1 == index2) {
            val varCheck = prod2.exps.foldLeft((true))((acc, cur) => 
                          acc && cur.isInstanceOf[Comparison] && 
                          cur.asInstanceOf[Comparison].op == "=" &&
                          ((cur.asInstanceOf[Comparison].index == variable1 && cur.asInstanceOf[Comparison].variable == index1) ||
                          (cur.asInstanceOf[Comparison].variable == variable1 && cur.asInstanceOf[Comparison].index == index1)))
            if (varCheck) { 
              
            }
          }
        }
      }
    }
    SoP(Seq(prod1, prod2)) // wrong default
  }

  def mergeMap[A, B](ms: Seq[Map[A, B]])(f: (B, B) => B): Map[A, B] = // copied from https://stackoverflow.com/questions/1262741/scala-how-to-merge-a-collection-of-maps
  (Map[A, B]() /: (for (m <- ms; kv <- m) yield kv)) { 
    (a, kv) => a + (if (a.contains(kv._1)) kv._1 -> f(a(kv._1), kv._2) else kv)
  }

  implicit class StringOps(s: String) {
    def uniqueName = s"${s}_US"
    def redundancyName = s"${s}_RM"
    def compressedName = s"${s}_C"
    def toVar: Variable = Variable(s)
    def redundancyVars: Variable = s.toVar.redundancyVars
  }

  implicit class VariableOps(v: Variable) {
    def redundancyVars = Variable(s"${v.name}'")
    def toAccess(kind: AccessType): Access = Access("", Seq(v), kind)
  }

  implicit class SeqVariableOps(v: Seq[Variable]) {
    def redundancyVars = v.foldLeft(Seq[Variable]())((acc, cur) => acc :+ cur.redundancyVars)
    def redundancyVarsInplace = v ++ v.redundancyVars
    def toAccess(kind: AccessType): Access = Access("", v, kind)
  }

  implicit class DimInfoOps(d: DimInfo) {
    def toAccessMap: Map[Access, Seq[Dim]] = Map[Access, Seq[Dim]](d.access -> d.dims)
    def toVarsMap: Map[Variable, Seq[Dim]] = (d.access.vars zip d.dims).foldLeft(Map.empty[Variable, Seq[Dim]])((acc, cur) => acc + (cur._1 -> Seq(cur._2)))
    def toComparisonVariableProdMap: Map[Variable, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Variable, Prod])((acc, cur) => 
    mergeMap(Seq(acc, Map(cur._1 -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonAccessProdMap: Map[Access, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Access, Prod])((acc, cur) => 
    mergeMap(Seq(acc, Map(d.access -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonProd: Prod = Prod((d.access.vars zip d.dims).foldLeft(Seq[Exp]())((acc, cur) => 
    acc ++ Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))
    def toSoP: SoP = SoP(Seq(Prod((d.access.vars zip d.dims).foldLeft(Seq.empty[Exp])((acc, varDim) => acc ++ Seq(Comparison("<=", ConstantInt(0), varDim._1), Comparison(">", varDim._2, varDim._1))))))
  }

  implicit class SeqDimInfoOps(d: Seq[DimInfo]) {
    def toAccessMap: Map[Access, Seq[Dim]] = d.foldLeft(Map.empty[Access, Seq[Dim]])((acc, cur) => mergeMap(Seq(acc, cur.toAccessMap))((v1, v2) => v1 ++ v2))
    def toVarsMap: Map[Variable, Seq[Dim]] = d.foldLeft(Map.empty[Variable, Seq[Dim]])((acc, cur) => mergeMap(Seq(acc, cur.toVarsMap))((v1, v2) => v1 ++ v2))
    def toComparisonVariableProdMap: Map[Variable, Prod] = d.foldLeft(Map.empty[Variable, Prod])((acc, cur) => mergeMap(Seq(acc, cur.toComparisonVariableProdMap))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonAccessProdMap: Map[Access, Prod] = d.foldLeft(Map.empty[Access, Prod])((acc, cur) => mergeMap(Seq(acc, cur.toComparisonAccessProdMap))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonProd: Prod = prodMult(d.foldLeft(Seq[Prod]())((acc, cur) => acc :+ cur.toComparisonProd))
  }

  def dimMin(dim1: Dim, dim2: Dim): Dim = {
    (dim1, dim2) match {
      case (Variable(name), Arithmetic(op, index1, index2)) => if (op == "+" && ((index1.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == dim1) || (index2.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == dim1))) dim1 else dim1 // this is just random else which is false
      case (Arithmetic(op, index1, index2), Variable(name)) => dimMin(dim2, dim1)
      case (ConstantInt(0), _) => dim1
      case (_, ConstantInt(0)) => dim2
      case _ if (dim1 == dim2) => dim1
    }
  }

  def dimMax(dim1: Dim, dim2: Dim): Dim = {
    (dim1, dim2) match {
      case (Variable(name), Arithmetic(op, index1, index2)) => if (op == "+" && ((index1.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == dim1) || (index2.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == dim1))) dim2 else dim2 // this is just random else which is false
      case (Arithmetic(op, index1, index2), Variable(name)) => dimMax(dim2, dim1)
      case (ConstantInt(0), _) => dim2
      case (_, ConstantInt(0)) => dim1
      case _ if (dim1 == dim2) => dim1
    }
  }

  def dimMin(dims: Seq[Dim]): Dim = {
    if (dims.length == 0) return ConstantInt(0)
    if (dims.length == 1) return dims(0)
    if (dims.length == 2) return dimMin(dims(0), dims(1))
    val dimMinFirst: Dim = dimMin(dims(0), dims(1))
    val newDims: Seq[Dim] = Seq(dimMinFirst) ++ dims.slice(2, dims.length)
    return dimMin(newDims)
  }

  def dimMax(dims: Seq[Dim]): Dim = {
    if (dims.length == 0) return ConstantInt(0)
    if (dims.length == 1) return dims(0)
    if (dims.length == 2) return dimMax(dims(0), dims(1))
    val dimMaxFirst: Dim = dimMax(dims(0), dims(1))
    val newDims: Seq[Dim] = Seq(dimMaxFirst) ++ dims.slice(2, dims.length)
    return dimMax(newDims)
  }

  def getBinOpDimInfo(e1: Exp, e2: Exp, outAccess: Access, dimInfo: Seq[DimInfo], multOrAdd: String): DimInfo = { // it doesn't work perfectly
    val accessMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val inp1DimSeq: Seq[Dim] = if (e1.isInstanceOf[Access]) accessMap.getOrElse(e1.asInstanceOf[Access], Seq.empty[Dim]) else Seq.empty[Dim]
    val inp2DimSeq: Seq[Dim] = if (e2.isInstanceOf[Access]) accessMap.getOrElse(e2.asInstanceOf[Access], Seq.empty[Dim]) else Seq.empty[Dim]
    val in1Vars: Seq[Variable] = if (e1.isInstanceOf[Access]) e1.asInstanceOf[Access].vars else Seq.empty[Variable]
    val in2Vars: Seq[Variable] = if (e2.isInstanceOf[Access]) e2.asInstanceOf[Access].vars else Seq.empty[Variable]
    val outVars: Seq[Variable] = outAccess.vars
    val outDim: Seq[Dim] = outVars.map(v => {
      val i1: Int = in1Vars.indexOf(v)
      val i2: Int = in2Vars.indexOf(v)
      if (i1 == -1 && i2 == -1) Arithmetic("+", ConstantInt(1), v) else if (i2 == -1) inp1DimSeq(i1) else if (i1 == -1) inp2DimSeq(i2) else if (multOrAdd == "mult") dimMin(inp1DimSeq(i1), inp2DimSeq(i2)) else if (multOrAdd == "add") dimMax(inp1DimSeq(i1), inp2DimSeq(i2)) else inp1DimSeq(i1) // else shouldn't happen normally
    })
    return DimInfo(outAccess, outDim)
  }

  def binMult(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, inp1US: Rule, inp1RM: Rule, inp1C: Rule, inp2US: Rule, inp2RM: Rule, inp2C: Rule): (Rule, Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val headC: Access = Access(name.compressedName, outVars, CompressedTensor)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val outDimInfo: DimInfo = getBinOpDimInfo(e1, e2, head, dimInfo, "mult")
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => {
        if (vars1.union(vars2).toSet == head.vars.toSet) {
          val e1US: SoP = inp1US.body // includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet) 
          val e2US: SoP = inp2US.body // includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet) 
          val e1RM: SoP = inp1RM.body // includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
          val e2RM: SoP = inp2RM.body // includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap) 
          val e1C: SoP = inp1C.body
          val e2C: SoP = inp2C.body
          if (isIntersectEmpty(vars1, vars2)) {
            if (name1 == name2) {
              val bodyUS: SoP = multSoP(Seq(e1US, e2US, SoP(Seq(vectorizeComparisonMultiplication("<=", vars1, vars2)))))
              val bodyRM: SoP = concatSoP(Seq(SoPTimesSoP(e1RM, e2RM), 
              multSoP(Seq(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1)))), e2RM)), 
              multSoP(Seq(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2)))), e1RM)), 
              multSoP(Seq(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp1RM.head.vars.diff(vars1)))), e2US, 
                          SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp2RM.head.vars.diff(vars2)))), 
                          SoP(Seq(vectorizeComparisonMultiplication(">", vars1, vars2)))))))
              val bodyC = multSoP(Seq(bodyUS, e1C, e2C))
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
            } else {
              val bodyUS: SoP = if(vars2.length == 0) e1US else if (vars1.length == 0) e2US else SoPTimesSoP(e1US, e2US)
              val bodyRM: SoP = if(vars2.length == 0) e1RM else if (vars1.length == 0) e2RM else concatSoP(Seq(SoPTimesSoP(e1RM, e2RM), 
              SoPTimesSoP(SoPTimesSoP(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1))))), e2RM), 
              SoPTimesSoP(SoPTimesSoP(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2))))), e1RM)))
              val bodyC = multSoP(Seq(bodyUS, e1C, e2C))
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
            }
          } else {
            val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e2US), SoPTimesSoP(e1RM, e2US), SoPTimesSoP(e1US, e2RM)))
            val bodyRM: SoP = SoPTimesSoP(e1RM, e2RM)
            val bodyC: SoP = concatSoP(Seq(multSoP(Seq(e1US, e2US, e1C, e2C)), 
                                          multSoP(Seq(e1RM, e2US, e1C.vars2RedundancyVars, e2C)), 
                                          multSoP(Seq(e1US, e2RM, e1C, e2C.vars2RedundancyVars))))
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
          }
        } else {
          val headP: Access = Access(head.name.redundancyVars.name, vars1.union(vars2), head.kind)
          val us_rm_c_dim: (Rule, Rule, Rule, DimInfo) = binMult(headP, dimInfo, e1, e2, inp1US, inp1RM, inp1C, inp2US, inp2RM, inp2C)
          return project(head, dimInfo :+ us_rm_c_dim._4, headP, us_rm_c_dim._1, us_rm_c_dim._2, us_rm_c_dim._3)
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        val e1US: SoP = inp1US.body // includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet)
        val e1RM: SoP = inp1RM.body // includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap)
        val e1C: SoP = inp1C.body
        val bodyUS: SoP = SoPTimesSoP(e1US, SoP(Seq(Prod(Seq(e2)))))
        val bodyRM: SoP = SoPTimesSoP(e1RM, SoP(Seq(Prod(Seq(e2)))))
        val bodyC: SoP = SoPTimesSoP(bodyUS, e1C)
        return project(head, dimInfo, e1, Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC))
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binMult(head, dimInfo, e2, e1, inp2US, inp2RM, inp2C, inp1US, inp1RM, inp1C)
      case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
        val flag1: Boolean = op1 == "<=" && op2 == "<" && index2.isInstanceOf[Variable] && variable1 == index2.asInstanceOf[Variable]
        val flag2: Boolean = op1 == "<=" && op2 == ">" && variable1 == variable2
        val flag3: Boolean = op1 == ">=" && op2 == "<" && index1.isInstanceOf[Variable] && index2.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == index2.asInstanceOf[Variable]
        val flag4: Boolean = op1 == ">=" && op2 == ">" && index1.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == variable2

        val flag5: Boolean = op1 == "<" && op2 == "<=" && index1.isInstanceOf[Variable] && variable2 == index1.asInstanceOf[Variable]
        val flag6: Boolean = op1 == ">" && op2 == "<=" && variable2 == variable1
        val flag7: Boolean = op1 == "<" && op2 == ">=" && index2.isInstanceOf[Variable] && index1.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == index1.asInstanceOf[Variable]
        val flag8: Boolean = op1 == ">" && op2 == ">=" && index2.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == variable1

        if (flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8) {
          val variable: Variable = if (flag1 || flag2 || flag8) variable1 else if (flag3 || flag7) index1.asInstanceOf[Variable] else variable2
          val indEq: Index = if (flag1 || flag2) index1 else if (flag3 || flag4) variable1 else if (flag5 || flag6) index2 else variable2
          val indGt: Index = if (flag1 || flag3) variable2 else if (flag2 || flag4) index2 else if (flag5 || flag7) variable1 else index1
          
          val bodyUS: SoP = SoP(Seq(Prod(Seq(Comparison("=", indEq, variable)))))
          val bodyRM: SoP = SoP(Seq(Prod(Seq(Comparison("<", indEq, variable), Comparison(">", indGt, variable), Comparison("=", indEq, variable.redundancyVars))))) // inp1RM.head.vars.diff(Seq(variable1))??
          val bodyC: SoP = multSoP(Seq(bodyUS, inp1C.body, inp2C.body))
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
        } else {
          val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(inp1US.body, inp2US.body), SoPTimesSoP(inp1RM.body, inp2US.body), SoPTimesSoP(inp1US.body, inp2RM.body), SoP(Seq(Prod(Seq(e1, e2))))))
          val bodyRM: SoP = SoPTimesSoP(inp1RM.body, inp2RM.body)
          val bodyC: SoP = concatSoP(Seq(multSoP(Seq(inp1US.body, inp2US.body, inp1C.body, inp2C.body)), 
                                        multSoP(Seq(inp1RM.body, inp2US.body, inp1C.body.vars2RedundancyVars, inp2C.body)), 
                                        multSoP(Seq(inp1US.body, inp2RM.body, inp1C.body, inp2C.body.vars2RedundancyVars)), 
                                        multSoP(Seq(SoP(Seq(Prod(Seq(e1, e2)))), inp1C.body, inp2C.body))))
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
        }
      }
    }
    (inp1US, inp1RM, inp1C, emptyDimInfo)
  }

  def isSoPDisjoint(sop1: SoP, sop2: SoP): Boolean = {
    val sop: SoP = SoPTimesSoP(sop1, sop2)
    sop.prods.foldLeft(true)((acc, prod) => {
      val isPEmpty = prod.exps.foldLeft(false)((acc2, exp) => acc2 || prod.exps.foldLeft(false)((acc3, exp2) => acc3 || isProdEmpty(exp, exp2)))
      acc && isPEmpty
    })
  }

  def binAdd(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, inp1US: Rule, inp1RM: Rule, inp1C: Rule, inp2US: Rule, inp2RM: Rule, inp2C: Rule): (Rule, Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val headC: Access = Access(name.compressedName, outVars, CompressedTensor)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val outDimInfo: DimInfo = getBinOpDimInfo(e1, e2, head, dimInfo, "add")
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = inp1US.body // includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet)
        val e2US: SoP = inp2US.body // includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet)
        val e1RM: SoP = inp1RM.body // includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap)
        val e2RM: SoP = inp2RM.body // includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap)
        val e1C: SoP = inp1C.body
        val e2C: SoP = inp2C.body
        if (vars1.toSet == vars2.toSet) {
          if (isSoPEquals(e1US, e2US) && isSoPEquals(e1RM, e2RM)) {
            val bodyUS: SoP = e1US
            val bodyRM: SoP = e1RM
            val bodyC: SoP = SoPTimesSoP(e1US, concatSoP(Seq(e1C, e2C)))
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
          } else if (isSoPDisjoint(e1US, e2US) && isSoPDisjoint(e1RM, e2RM)) {
            val bodyUS: SoP = concatSoP(Seq(e1US, e2US))
            val bodyRM: SoP = concatSoP(Seq(e1RM, e2RM))
            val bodyC: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e1C), SoPTimesSoP(e2US, e2C)))
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
          } else {
            val bodyUS: SoP = concatSoP(Seq(e1US, e2US, e1RM, e2RM))
            val bodyRM: SoP = SoP(Seq())
            val bodyC: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e1C), SoPTimesSoP(e2US, e2C), 
                                          SoPTimesSoP(e1RM, e1C.vars2RedundancyVars), SoPTimesSoP(e2RM, e2C.vars2RedundancyVars)))
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
          }
        } else { // a fake else
          val bodyUS: SoP = concatSoP(Seq(e1US, e2US, e1RM, e2RM))
          val bodyRM: SoP = SoP(Seq())
          val bodyC: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e1C), SoPTimesSoP(e2US, e2C), 
                                          SoPTimesSoP(e1RM, e1C.vars2RedundancyVars), SoPTimesSoP(e2RM, e2C.vars2RedundancyVars)))
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binAdd(head, dimInfo, e2, e1, inp2US, inp2RM, inp2C, inp1US, inp1RM, inp1C)
      case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
        
      }
    }
    (inp1US, inp1RM, inp1C, emptyDimInfo)
  }

  def getProjectDimInfo(inpAccess: Access, outAccess: Access, dimInfo: Seq[DimInfo]): DimInfo = {
    val accessMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val varMap: Map[Variable, Seq[Dim]] = dimInfo.toVarsMap
    val inpDimSeq: Seq[Dim] = accessMap.getOrElse(inpAccess, Seq())
    val inVars: Seq[Variable] = inpAccess.vars
    val outVars: Seq[Variable] = outAccess.vars
    val outDim: Seq[Dim] = outVars.map(v => {
      val i: Int = inVars.indexOf(v)
      val dimSeq: Seq[Dim] = varMap.getOrElse(v, Seq.empty[Dim])
      if (i == -1 && dimSeq.length == 0) Arithmetic("+", ConstantInt(1), v) else if (i != -1) inpDimSeq(i) else dimMax(dimSeq)
    })
    return DimInfo(outAccess, outDim)
  }

  def project(head: Access, dimInfo: Seq[DimInfo], e: Exp, inp1US: Rule, inp1RM: Rule, inp1C: Rule): (Rule, Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val headC: Access = Access(s"${name.compressedName}", outVars, CompressedTensor)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    e match {
      case Access(nameE, varsE, Tensor) => {
        val outDimInfo: DimInfo = getProjectDimInfo(e.asInstanceOf[Access], head, dimInfo)
        val eUS: SoP = inp1US.body // includeBoundaries(inp1US.body, bounds, e.asInstanceOf[Access], UniqueSet) 
        val eRM: SoP = inp1RM.body // includeBoundaries(inp1RM.body, bounds, e.asInstanceOf[Access], RedundancyMap) 
        val eC: SoP = inp1C.body
        if (varsE.toSet.subsetOf(outVars.toSet)) return (Rule(headUS, eUS), Rule(headRM, eRM), Rule(headC, eC), outDimInfo)
        else if(outVars.toSet.subsetOf(varsE.toSet)) {
          val bodyUS: SoP = concatSoP(Seq(eUS, eRM))
          val bodyRM: SoP = SoP(Seq())
          val bodyC: SoP = concatSoP(Seq(multSoP(Seq(eUS, eC)), multSoP(Seq(eRM, eC.vars2RedundancyVars))))
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
        }
      }
      case Comparison(op, index, variable) => {

      }
    }
    (inp1US, inp1RM, inp1C, emptyDimInfo)
  }

  def isDirectSum(exps: Seq[Exp], dimInfo: Seq[DimInfo], e1: Exp, e2: Exp): Boolean = {
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => {
        if (vars1.length == vars2.length && vars1.length == exps.length) {
          return (exps zip vars1 zip vars2).foldLeft(true)((acc, cur) => {
            if (cur._1._1.isInstanceOf[Comparison]) {
              val comp = cur._1._1.asInstanceOf[Comparison]
              if (comp.index.isInstanceOf[Arithmetic]) {
                val arith = comp.index.asInstanceOf[Arithmetic]
                acc && comp.op == "=" && comp.variable == cur._2 && arith.op == "-" && arith.index1 == cur._1._2 && 
                arith.index2.isInstanceOf[Variable] && dimInfo.toVarsMap.get(cur._1._2).get.contains(arith.index2.asInstanceOf[Variable]) // arith.index2.asInstanceOf[Variable] == dimInfo.toVarsMap.get(cur._1._2).get(0)??
              } else false
            } else false
          })
        }
      }
    }
    false
  }

  def isShift(exps: Seq[Exp], dimInfo: Seq[DimInfo], outAccess: Access): Boolean = {
    if (exps.length == 1) return false
    val e: Exp = exps(0)
    val flag: Boolean = exps.slice(1, exps.length).foldLeft(e.isInstanceOf[Access])((acc, cur) => acc && cur.isInstanceOf[Comparison])
    val accessMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    if (flag) {
      val access: Access = e.asInstanceOf[Access]
      val rest: Seq[Comparison] = exps.slice(1, exps.length).map(e => e.asInstanceOf[Comparison])
      val accessVars: Seq[Variable] = access.vars
      val outVars: Seq[Variable] = outAccess.vars
      val newFlag: Boolean = rest.foldLeft(true)((acc, comp) => {
        if (comp.op == "=" && comp.index.isInstanceOf[Arithmetic] && accessVars.contains(comp.variable)) {
          val arith: Arithmetic = comp.index.asInstanceOf[Arithmetic]
          val fl: Boolean = arith.op == "-" && arith.index1.isInstanceOf[Variable] && outVars.contains(arith.index1.asInstanceOf[Variable])
          return (acc && fl)
        } else false
      })
      return newFlag
    }
    false
  }

  def getShiftMap(exps: Seq[Exp], dimInfo: Seq[DimInfo], outAccess: Access): Map[Variable, Variable] = {
    val e: Exp = exps(0)
    val flag: Boolean = exps.slice(1, exps.length).foldLeft(e.isInstanceOf[Access])((acc, cur) => acc && cur.isInstanceOf[Comparison])
    val accessMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    if (flag) {
      val access: Access = e.asInstanceOf[Access]
      val rest: Seq[Comparison] = exps.slice(1, exps.length).map(e => e.asInstanceOf[Comparison])
      val accessVars: Seq[Variable] = access.vars
      val outVars: Seq[Variable] = outAccess.vars
      val res: Map[Variable, Variable] = rest.foldLeft(Seq.empty[(Variable, Variable)])((acc, comp) => {
        if (comp.op == "=" && comp.index.isInstanceOf[Arithmetic] && accessVars.contains(comp.variable)) {
          val arith: Arithmetic = comp.index.asInstanceOf[Arithmetic]
          val fl: Boolean = arith.op == "-" && arith.index1.isInstanceOf[Variable] && outVars.contains(arith.index1.asInstanceOf[Variable])
          if (fl) acc :+ (comp.variable -> arith.index1.asInstanceOf[Variable])
          else acc
        } else acc
      }).toMap
      return res
    }
    Map.empty[Variable, Variable]
  }

  def replaceVarsWithRedundancyVars(vars: Seq[Comparison]): Seq[Comparison] = { // it only supports the case in special case inference rules
    vars.foldLeft(Seq[Comparison]())((acc, cur) => {
      val op = cur.op
      val index: Index = cur.index match {
        case Arithmetic(opAr, index1, index2) => {
          index1 match {
            case Variable(_) => Arithmetic(opAr, index1.asInstanceOf[Variable].redundancyVars, index2)
          }
        } 
        case Variable(_) => cur.index.asInstanceOf[Variable].redundancyVars
        case _ => cur.index
      }
      val variable = cur.variable.redundancyVars
      acc :+ Comparison(op, index, variable)
    })
  }

  def shift(head: Access, shiftMap: Map[Variable, Variable], dimInfo: Seq[DimInfo], e: Exp, eSeq: Seq[Comparison], inpUS: Rule, inpRM: Rule, inpC: Rule): (Rule, Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val headC: Access = Access(name.compressedName, outVars, CompressedTensor)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val minusVarMap: Map[Variable, Dim] = eSeq.map(comp => comp.index.asInstanceOf[Arithmetic].index1.asInstanceOf[Variable] -> comp.index.asInstanceOf[Arithmetic].index2.asInstanceOf[Dim]).toMap
    e match {
      case (Access(name, vars, Tensor)) => { 
        val eUS: SoP = inpUS.body // includeBoundaries(inpUS.body, bounds, e.asInstanceOf[Access], UniqueSet) 
        val eRM: SoP = inpRM.body // includeBoundaries(inpRM.body, bounds, e.asInstanceOf[Access], RedundancyMap) 
        val eC: SoP = inpC.body
        val eDimSeq: Seq[Dim] = dimMap.get(e.asInstanceOf[Access]).getOrElse(Seq.empty)
        val headDimSeq: Seq[Dim] = (outVars zip eDimSeq).map{case (v, d) => if (minusVarMap.contains(v)) Arithmetic("+", d, minusVarMap.get(v).get) else d}
        val headDimInfo: DimInfo = DimInfo(head, headDimSeq)
        val headDimSoP: SoP = headDimInfo.toSoP
        val headDimSoP2: SoP = SoP(Seq(Prod((outVars zip headDimSeq).foldLeft(Seq.empty[Exp])((acc, varDim) => if (varDim._2.isInstanceOf[Arithmetic]) acc :+ Comparison("<=", varDim._2.asInstanceOf[Arithmetic].index2, varDim._1) else acc))))
        val bodyUS: SoP = multSoP(Seq(eUS, SoP(Seq(Prod(eSeq))), headDimSoP, headDimSoP2))
        // val bodyRM: SoP = multSoP(Seq(eRM, SoP(Seq(Prod(eSeq))), SoP(Seq(Prod(replaceVarsWithRedundancyVars(eSeq)))), headDimSoP, headDimSoP2)) // This is correct but hard to simplify, so I changed the implementation a bit and added some levels of inference help here. Should we explain in the paper?
        val redVarMap: Seq[Map[Variable, Variable]] = getRedMap(eRM)
        val redShiftMap: Map[Variable, Variable] = shiftMap.map{case(k, v) => (k.redundancyVars -> v.redundancyVars)}.toMap
        val fullShiftMap: Map[Variable, Variable] = mergeMap(Seq(shiftMap, redShiftMap))((v1, v2) => v1)
        val redSoP: SoP = SoP(redVarMap.map(m => Prod(m.map{case(k, v) => Comparison("=", k, v)}.toSeq)).toSeq)
        val rmReplaced: SoP = replaceVars(redSoP, fullShiftMap)
        val bodyRM: SoP = multSoP(Seq(rmReplaced, headDimSoP, headDimSoP2))
        val bodyC: SoP = multSoP(Seq(getNoComparisonSoP(eC), bodyUS))
        return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), headDimInfo)
      }
    }
    (inpUS, inpRM, inpC, emptyDimInfo)
  }

  def binDirectSum(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, e2Seq: Seq[Comparison], inp1US: Rule, inp1RM: Rule, inp1C: Rule, inp2US: Rule, inp2RM: Rule, inp2C: Rule): (Rule, Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val headC: Access = Access(name.compressedName, outVars, CompressedTensor)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = inp1US.body // includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet) 
        val e2US: SoP = inp2US.body // includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet) 
        val e1RM: SoP = inp1RM.body // includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
        val e2RM: SoP = inp2RM.body // includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap) 
        val e1C: SoP = inp1C.body
        val e2C: SoP = inp2C.body
        val e1DimSeq: Seq[Dim] = dimMap.get(e1.asInstanceOf[Access]).getOrElse(Seq.empty)
        val e2DimSeq: Seq[Dim] = dimMap.get(e2.asInstanceOf[Access]).getOrElse(Seq.empty)
        val headDimSeq: Seq[Dim] = (e1DimSeq zip e2DimSeq).foldLeft(Seq.empty[Dim])((acc, cur) => acc :+ Arithmetic("+", cur._1, cur._2))
        val headDimInfo: DimInfo = DimInfo(head, headDimSeq)
        val headDimSoP: SoP = headDimInfo.toSoP
        val headDimSoP2: SoP = SoP(Seq(Prod((outVars zip e1DimSeq).foldLeft(Seq.empty[Exp])((acc, varDim) => acc :+ Comparison("<=", varDim._2, varDim._1)))))
        val bodyUS: SoP = concatSoP(Seq(e1US, multSoP(Seq(e2US, SoP(Seq(Prod(e2Seq))), headDimSoP, headDimSoP2))))
        val bodyRM: SoP = concatSoP(Seq(e1RM, multSoP(Seq(e2RM, SoP(Seq(Prod(e2Seq))), SoP(Seq(Prod(replaceVarsWithRedundancyVars(e2Seq)))), headDimSoP, headDimSoP2))))
        val bodyC: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e1C), multSoP(Seq(e2US, SoP(Seq(Prod(e2Seq))), headDimSoP, headDimSoP2, e2C))))
        return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), headDimInfo)
      }
    }
    (inp1US, inp1RM, inp1C, emptyDimInfo)
  }

  def isPairwiseIntersectEmpty(vars: Seq[Seq[Variable]]): Boolean = {
    vars.foldLeft(true)((acc, cur) => {
      acc && vars.foldLeft(true)((acc2, cur2) => {
        if(cur != cur2) acc2 && isIntersectEmpty(cur, cur2)
        else acc2
      })
    })
  }

  def crossJoin[T](list: Traversable[Traversable[T]]): Traversable[Traversable[T]] = // taken from https://stackoverflow.com/questions/54330356/scala-create-all-possible-permutations-of-a-sentence-based-synonyms-of-each-wor
  list match {
    case Nil => Nil
    case x :: Nil => x map (Traversable(_))
    case x :: xs =>
      val xsJoin = crossJoin(xs)
      for {
        i <- x
        j <- xsJoin
      } yield {
        Traversable(i) ++ j
      }
  }

  def getSelfProdDimInfo(eAccessSeq: Seq[Access], outAccess: Access, dimInfo: Seq[DimInfo]): DimInfo = {
    val accessMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val inpDimSeq: Seq[Seq[Dim]] = eAccessSeq.map(e => accessMap.getOrElse(e, Seq.empty[Dim]))
    val inVarsSeq: Seq[Seq[Variable]] = eAccessSeq.map(e => e.vars)
    val outVars: Seq[Variable] = outAccess.vars
    val outDim: Seq[Dim] = outVars.map(v => {
      val is: Seq[Int] = inVarsSeq.map(inVar => inVar.indexOf(v))
      val validIs: Seq[(Int, Int)] = is.zipWithIndex.filter(iId => iId._1 != -1)
      if (validIs.length == 0) Arithmetic("+", ConstantInt(1), v) else inpDimSeq(validIs(0)._2)(validIs(0)._1)
    })
    return DimInfo(outAccess, outDim)
  }

  // self outer product with any degree
  def mult(head: Access, dimInfo: Seq[DimInfo], eSeq: Seq[Exp], inpUSSeq: Seq[Rule], inpRMSeq: Seq[Rule], inpCSeq: Seq[Rule]): (Rule, Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val headC: Access = Access(name.compressedName, outVars, CompressedTensor)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val accessFlag: Boolean = eSeq.foldLeft(true)((acc, cur) => acc && cur.isInstanceOf[Access])
    if (accessFlag) {
      val eAccessSeq: Seq[Access] = eSeq.map(e => e.asInstanceOf[Access])
      val nameSeq: Seq[String] = eAccessSeq.map(e => e.name)
      val varsSeq: Seq[Seq[Variable]] = eAccessSeq.map(e => e.vars)
      val eUS: Seq[SoP] = (inpUSSeq zip eAccessSeq).map{case (r, e) => r.body} // includeBoundaries(r.body, bounds, e, UniqueSet)}
      val eRM: Seq[SoP] = (inpRMSeq zip eAccessSeq).map{case (r, e) => r.body} // includeBoundaries(r.body, bounds, e, RedundancyMap)}
      val eC: Seq[SoP] = (inpCSeq zip eAccessSeq).map{case (r, e) => r.body}
      val outDimInfo: DimInfo = getSelfProdDimInfo(eAccessSeq, head, dimInfo)
      val n: Int = eUS.length - 1
      val indSeq: Seq[Int] = (0 to n)
      if (isPairwiseIntersectEmpty(varsSeq)) {
        val nameFlag: Boolean = (0 to n - 1).foldLeft(true)((acc, i) => acc && nameSeq(i) == nameSeq(i + 1))
        if (nameFlag) {
          val eRed = (inpRMSeq zip varsSeq).map{case (r, v) => r.head.vars.diff(v)}
          val eUS_allvars: Seq[SoP] = (eUS zip varsSeq zip eRed).map{case ((us, v), red) => SoPTimesSoP(us, SoP(Seq(vectorizeComparisonMultiplication("=", v, red))))}
          val cRed: Seq[Seq[SoP]] = eRed.map(red => varsSeq.map(v => SoP(Seq(vectorizeComparisonMultiplication("=", red, v)))))
          val cleq: Seq[Seq[SoP]] = varsSeq.map(v1 => varsSeq.map(v2 => SoP(Seq(vectorizeComparisonMultiplication("<=", v1, v2)))))

          val bodyUSSeq: Seq[SoP] = (0 to n - 1).map(ind => SoP(Seq(vectorizeComparisonMultiplication("<=", varsSeq(ind), varsSeq(ind + 1)))))
          val bodyUS: SoP = multSoP(eUS ++ bodyUSSeq)

          val bodyC: SoP = multSoP(eC ++ Seq(bodyUS))

          
          val bodyRMSeq1: Seq[SoP] = indSeq.foldLeft(Seq.empty[SoP])((acc, i) => {
            val usInd: Iterator[Seq[Int]] = indSeq.combinations(i)
            acc ++ usInd.map(indList => {
              val usSeq: Seq[SoP] = (eUS_allvars.zipWithIndex).filter{case (us, ind) => indList.contains(ind)}.map{case (us, ind) => us}
              val rmSeq: Seq[SoP] = (eRM.zipWithIndex).filter{case (rm, ind) => !indList.contains(ind)}.map{case (rm, ind) => rm}
              multSoP(usSeq ++ rmSeq)
            })
          })
          val indeSeqPerm: Iterator[Seq[Int]] = indSeq.permutations
          val bodyRMSeq2: Seq[SoP] = indeSeqPerm.zipWithIndex.foldLeft(Seq.empty[SoP])((acc, cur) => {
            val (iters, x) = (cur._1, cur._2)
            if (x != 0) {
              val conds: Seq[SoP] = (0 to iters.length - 2).map(i => cleq(iters(i))(iters(i + 1)))
              val cReds: Seq[SoP] = (0 to iters.length - 1).map(i => cRed(i)(iters(i)))
              acc :+ multSoP(eUS ++ conds ++ cReds)
            } else acc
          })
          val bodyRM: SoP = concatSoP(bodyRMSeq1 ++ bodyRMSeq2)
          
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), Rule(headC, bodyC), outDimInfo)
        } else (inpUSSeq(0), inpRMSeq(0), inpCSeq(0), emptyDimInfo)
      } else (inpUSSeq(0), inpRMSeq(0), inpCSeq(0), emptyDimInfo)
    }
    else (inpUSSeq(0), inpRMSeq(0), inpCSeq(0), emptyDimInfo)
  }

  def appendUniqueVars(v1: Seq[Variable], v2: Seq[Variable]): Seq[Variable] = v2.foldLeft(v1)((acc, cur) => if (v1.contains(cur)) acc else acc :+ cur)

  def areStringSeqEquiv(n1: Seq[String], n2: Seq[String]): Boolean = {
    if (n1.length != n2.length) return false
    if (n1.length == 0) return true
    val index: Int = n2.indexOf(n1(0))
    if (index == -1) return false
    val s1 = n1.slice(1, n1.length)
    val s2 = n2.slice(0, index) ++ n2.slice(index + 1, n2.length)
    return areStringSeqEquiv(s1, s2)
  }
  
  def areProdTCsEqiv(tc1: Rule, tc2: Rule): Boolean = {
    if (tc1.body.prods.length != 1 || tc2.body.prods.length != 1) return false
    val s1: Seq[Access] = tc1.body.prods.foldLeft(Seq.empty[Access])((acc, prod) => acc ++ prod.exps.foldLeft(Seq.empty[Access])((acc2, exp) => acc2 :+ exp.asInstanceOf[Access]))
    val s2: Seq[Access] = tc2.body.prods.foldLeft(Seq.empty[Access])((acc, prod) => acc ++ prod.exps.foldLeft(Seq.empty[Access])((acc2, exp) => acc2 :+ exp.asInstanceOf[Access]))
    val n1: Seq[String] = s1.map(a => a.name).toSeq
    val n2: Seq[String] = s2.map(a => a.name).toSeq
    return areStringSeqEquiv(n1, n2)
  }

  def createVarMap(s1: Seq[Access], s2: Seq[Access]): Map[Variable, Variable] = {
    if (s1.length == 0) return Map.empty[Variable, Variable]
    val n1: Seq[String] = s1.map(a => a.name).toSeq
    val n2: Seq[String] = s2.map(a => a.name).toSeq
    val index: Int = n2.indexOf(n1(0))
    val map: Map[Variable, Variable] = (s1(0).vars zip s2(index).vars).toMap
    val newS1 = s1.slice(1, s1.length)
    val newS2 = s2.slice(0, index) ++ s2.slice(index + 1, s2.length)
    return mergeMap(Seq(map, createVarMap(newS1, newS2)))((v1, v2) => v1)
  }

  def inline(r: Rule, inliningMap: Map[Access, SoP]): Rule = {
    val sop: SoP = r.body.prods.foldLeft(emptySoP)((acc, prod) => {
      val res: SoP = prod.exps.foldLeft(emptySoP)((acc2, exp) => {
        val inline: SoP = inliningMap.getOrElse(exp.asInstanceOf[Access], SoP(Seq(Prod(Seq(exp)))))
        if (acc2 == emptySoP) inline else multSoP(Seq(acc2, inline))
      })
      if (acc == emptySoP) res else multSoP(Seq(acc, res))
    })
    Rule(r.head, sop)
  }

  def getRedMap(body: SoP): Seq[Map[Variable, Variable]] = {
    body.prods.foldLeft(Seq.empty[Map[Variable, Variable]])((acc, prod) => {
      acc :+ prod.exps.foldLeft(Seq.empty[(Variable, Variable)])((acc2, exp) => {
        if (exp.isInstanceOf[Comparison]) {
          val comp: Comparison = exp.asInstanceOf[Comparison]
          if (comp.op == "=" && comp.index.isInstanceOf[Variable]) {
            val var1: Variable = comp.index.asInstanceOf[Variable]
            val var2: Variable = comp.variable
            val f1: Boolean = var1.name.contains("'")
            val f2: Boolean = var2.name.contains("'")
            if (f1 && !f2) acc2 :+ (var1 -> var2) else if (f2 && !f1) acc2 :+ (var2 -> var1) else acc2
          } else acc2
        } else acc2
      }).toMap
    })
  }

  def getRedMap(r: Rule): Seq[Map[Variable, Variable]] = getRedMap(r.body)

  def cse(tcSeq: Seq[Rule], inliningMap: Map[Access, SoP], uniqueSet: Map[Exp, Rule], redundancyMap: Map[Exp, Rule], compressionMap: Map[Exp, Rule], dimInfo: Seq[DimInfo]): (Seq[Rule], Map[Access, SoP], Map[Exp, Rule], Map[Exp, Rule], Map[Exp, Rule], Seq[DimInfo]) = {
    // println("++++++++++++++++")
    // tcSeq.foldLeft()((acc, cur) => println(cur.prettyFormat))
    // inliningMap.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " -> " + cur._2.prettyFormat))
    // uniqueSet.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <US> " + cur._2.prettyFormat))
    // redundancyMap.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <RM> " + cur._2.prettyFormat))

    if (tcSeq.length  == 0) return (tcSeq, inliningMap, uniqueSet, redundancyMap, compressionMap, dimInfo)

    val firstTC: Rule = inline(Rule(tcSeq(0).head, getNoComparisonSoP(tcSeq(0).body)), inliningMap)
    val us1: Rule = uniqueSet.get(firstTC.head).get
    val rm1: Rule = redundancyMap.get(firstTC.head).get
    // val c1: Rule = compressionMap.get(firstTC.head).get
    val (index, varMap): (Int, Map[Variable, Variable]) = (1 to tcSeq.length - 1).foldLeft((-1, Map.empty[Variable, Variable]))((acc, ind) => {
      if (acc._1 == -1) {
        val tc: Rule = inline(Rule(tcSeq(ind).head, getNoComparisonSoP(tcSeq(ind).body)), inliningMap)
        val us2: Rule = uniqueSet.get(tc.head).get
        val rm2: Rule = redundancyMap.get(tc.head).get
        // val c2: Rule = compressionMap.get(tc.head).get
        if (areProdTCsEqiv(tc, firstTC) && isSoPDisjoint(us1.body, us2.body) && isSoPDisjoint(rm1.body, rm2.body)) {
          val s1: Seq[Access] = firstTC.body.prods.foldLeft(Seq.empty[Access])((acc, prod) => acc ++ prod.exps.foldLeft(Seq.empty[Access])((acc2, exp) => acc2 :+ exp.asInstanceOf[Access]))
          val s2: Seq[Access] = tc.body.prods.foldLeft(Seq.empty[Access])((acc, prod) => acc ++ prod.exps.foldLeft(Seq.empty[Access])((acc2, exp) => acc2 :+ exp.asInstanceOf[Access]))
          val vMap1: Map[Variable, Variable] = (tc.head.vars zip firstTC.head.vars).toMap
          val vMap2: Map[Variable, Variable] = createVarMap(s2, s1) // s2.vars -> s1.vars
          val varMap: Map[Variable, Variable] = mergeMap(Seq(vMap1, vMap2))((v1, v2) => v2)
          val newS2: Seq[Access] = s2.map(a => replaceVars(a, varMap))
          if (s1.toSet == newS2.toSet) (ind, varMap) else acc
        } else acc
      } else acc
    })

    if (index == -1) {
      val (newTCSeq, newInliningMap, newUniqueSet, newRedundancyMap, newCompressionMap, newDimInfo) = cse(tcSeq.slice(1, tcSeq.length), inliningMap, uniqueSet, redundancyMap, compressionMap, dimInfo)
      return (Seq(tcSeq(0)) ++ newTCSeq, newInliningMap, newUniqueSet, newRedundancyMap, newCompressionMap, newDimInfo)
    } else {
      val newTCSeq: Seq[Rule] = tcSeq.slice(0, index) ++ tcSeq.slice(index + 1, tcSeq.length)
      val tc: Rule = tcSeq(index)
      val tcUSSoP: SoP = uniqueSet.get(tc.head).get.body
      val mapProd: SoP = SoP(Seq(Prod(varMap.map{case(k, v) => Comparison("=", k.redundancyVars, v)}.toSeq)))
      val tcRMSoP: SoP = multSoP(Seq(tcUSSoP, mapProd))
      val newUniqueSet: Map[Exp, Rule] = uniqueSet.filter(kv => kv._1 != tc.head)
      val newCompressionMap: Map[Exp, Rule] = compressionMap.filter(kv => kv._1 != tc.head)
      val rm0: Rule = redundancyMap.get(tcSeq(0).head).get
      val rm1: Rule = redundancyMap.get(tc.head).get
      val redVarMap: Seq[Map[Variable, Variable]] = getRedMap(rm1)
      val replacementMap: Seq[Map[Variable, Variable]] = redVarMap.map(m => {
        varMap.foldLeft(Seq.empty[(Variable, Variable)])((acc, cur) => {
          val k: Variable = cur._1
          val v: Variable = cur._2
          val nK: Variable = v.redundancyVars
          val nV: Variable = m.getOrElse(nK, "".toVar)
          acc :+ (k.redundancyVars -> nV)
        }).toMap
      }).toSeq
      val newRM1: SoP = SoP((rm1.body.prods zip replacementMap).map{case(prod, map) => {
        val newComps: Seq[Comparison] = map.map{case(k, v) => Comparison("=", k, v)}.toSeq
        Prod(prod.exps ++ newComps)
      }})
      val newRM0: Map[Exp, Rule] = Map(tcSeq(0).head -> Rule(rm0.head, concatSoP(Seq(rm0.body, newRM1, tcRMSoP))))
      val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(redundancyMap, newRM0))((r1, r2) => r2)
      return cse(newTCSeq, inliningMap, newUniqueSet, newRedundancyMap, newCompressionMap, dimInfo)
    }
  }

  def infer(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule], compressionMap: Map[Exp, Rule] = Map()): (Rule, Rule, Rule, DimInfo) = {
    val prods: Seq[Prod] = tensorComputation.body.prods
    val head: Access = tensorComputation.head
    val nonSizeVariables: Seq[Variable] = getVariables(tensorComputation)
    // println(tensorComputation.prettyFormat)
    if (prods.length == 1) {
      val exps: Seq[Exp] = prods(0).exps
      if (isShift(exps, dimInfo, head)) {
        val e: Exp = exps(0)
        val inpUS: Rule = uniqueSets.getOrElse(e, emptyRule())
        val inpRM: Rule = redundancyMaps.getOrElse(e, emptyRule())
        val inpC: Rule = compressionMap.getOrElse(e, emptyRule())
        val shiftMap: Map[Variable, Variable] = getShiftMap(exps, dimInfo, head)
        return shift(head, shiftMap, dimInfo, e.asInstanceOf[Access], exps.slice(1, exps.length).map(elem => elem.asInstanceOf[Comparison]), inpUS, inpRM, inpC)
      }
      else if (exps.length == 1) {
        val e: Exp = exps(0)
        val inp1US: Rule = uniqueSets.getOrElse(e, emptyRule())
        val inp1RM: Rule = redundancyMaps.getOrElse(e, emptyRule())
        val inp1C: Rule = compressionMap.getOrElse(e, emptyRule())
        return project(head, dimInfo, e, inp1US, inp1RM, inp1C)
      } else if (exps.length == 2) {
        val e1: Exp = exps(0)
        val e2: Exp = exps(1)
        val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
        val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
        val inp1C: Rule = compressionMap.getOrElse(e1, emptyRule())
        val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
        val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
        val inp2C: Rule = compressionMap.getOrElse(e2, emptyRule())
        return binMult(head, dimInfo, e1, e2, inp1US, inp1RM, inp1C, inp2US, inp2RM, inp2C)
      } else {
        val eAccessIndexSeq: Seq[(Access, Int)] = exps.zipWithIndex.filter(eI => eI._1.isInstanceOf[Access]).map(eI => (eI._1.asInstanceOf[Access], eI._2))
        val nameMap: Map[String, Seq[(Access, Int)]] = eAccessIndexSeq.foldLeft(Map.empty[String, Seq[(Access, Int)]])((acc, cur) => mergeMap(Seq(acc, Map(cur._1.name -> Seq(cur))))((v1, v2) => v1 ++ v2))
        val similarNameMap: Map[String, Seq[(Access, Int)]] = nameMap.filter{case (name, accessIdSeq) => accessIdSeq.length > 1}.filter{case (name, accessIdSeq) => {
          val varsSeq: Seq[Seq[Variable]] = accessIdSeq.map(eI => eI._1.vars)
          isPairwiseIntersectEmpty(varsSeq)
        }}
        val multInfers: Map[Access, (Rule, Rule, Rule, DimInfo)] = similarNameMap.foldLeft(Map.empty[Access, (Rule, Rule, Rule, DimInfo)])((acc, cur) => {
          val accessIdSeq: Seq[(Access, Int)] = cur._2
          val varsSeq: Seq[Variable] = accessIdSeq.foldLeft(Seq.empty[Variable])((acc, eI) => appendUniqueVars(acc, eI._1.vars).filter(v => nonSizeVariables.contains(v)))
          val head: Access = Access(getVar("head"), varsSeq, Tensor)
          val similarExps: Seq[Access] = accessIdSeq.map{case (access, id) => access}
          val inpUS: Seq[Rule] = similarExps.map(e => uniqueSets.getOrElse(e, emptyRule()))
          val inpRM: Seq[Rule] = similarExps.map(e => redundancyMaps.getOrElse(e, emptyRule()))
          val inpC: Seq[Rule] = similarExps.map(e => compressionMap.getOrElse(e, emptyRule()))
          mergeMap(Seq(acc, Map(head -> mult(head, dimInfo, similarExps, inpUS, inpRM, inpC))))((v1, v2) => v2)
        })
        
        val similarNameIndices: Seq[Int] = similarNameMap.foldLeft(Seq.empty[Int])((acc, cur) => acc ++ cur._2.map{case (access, i) => i})
        val newExps: Seq[Exp] = exps.zipWithIndex.filter(eI => !similarNameIndices.contains(eI._2)).map(eI => eI._1) ++ multInfers.keySet.toSeq
        val similarUSMap: Map[Exp, Rule] = multInfers.map{case (access, us_rm_c_dim) => (access -> us_rm_c_dim._1)}
        val similarRMMap: Map[Exp, Rule] = multInfers.map{case (access, us_rm_c_dim) => (access -> us_rm_c_dim._2)}
        val similarCMap: Map[Exp, Rule] = multInfers.map{case (access, us_rm_c_dim) => (access -> us_rm_c_dim._3)}
        val similarDimInfoSeq: Seq[DimInfo] = multInfers.map{case (access, us_rm_c_dim) => us_rm_c_dim._4}.toSeq
        val uniqueSetsSim = mergeMap(Seq(uniqueSets, similarUSMap))((v1, v2) => v2)
        val redundancyMapsSim = mergeMap(Seq(redundancyMaps, similarRMMap))((v1, v2) => v2)
        val compressionMapsSim = mergeMap(Seq(compressionMap, similarCMap))((v1, v2) => v2)
        val dimInfoSim = dimInfo ++ similarDimInfoSeq

        if (newExps.length == 1) return (multInfers.values.toSeq)(0)
        else if (newExps.length == 2) {
          val sop: SoP = SoP(Seq(Prod(Seq(newExps(0), newExps(1)))))
          val finalTC: Rule = Rule(head, sop)
          return infer(finalTC, dimInfoSim, uniqueSetsSim, redundancyMapsSim, compressionMapsSim)
        }

        // else if (newExp.length > 2) or in other words else
        val n = newExps.length - 1
        val seqInd: Seq[Int] = 2 to n - 1
        val startHead: Access = Access(getVar("head"), appendUniqueVars(getAllVariables(newExps(0)), getAllVariables(newExps(1))).filter(v => nonSizeVariables.contains(v)), Tensor)
        val startSoP: SoP = SoP(Seq(Prod(Seq(newExps(0), newExps(1)))))
        val startTC: Rule = Rule(startHead, startSoP)
        val inf: (Rule, Rule, Rule, DimInfo) = infer(startTC, dimInfoSim, uniqueSetsSim, redundancyMapsSim, compressionMapsSim)
        val newUS: Map[Exp, Rule] = mergeMap(Seq(uniqueSetsSim, Map[Exp, Rule](startHead -> inf._1)))((v1, v2) => v2)
        val newRM: Map[Exp, Rule] = mergeMap(Seq(redundancyMapsSim, Map[Exp, Rule](startHead -> inf._2)))((v1, v2) => v2)
        val newC: Map[Exp, Rule] = mergeMap(Seq(compressionMapsSim, Map[Exp, Rule](startHead -> inf._3)))((v1, v2) => v2)
        val newDI: Seq[DimInfo] = dimInfoSim :+ inf._4
        val tcMap: Map[Access, SoP] = Map(startHead -> startSoP)
        val (tc, inliningMap, (newUniqueSet, newRedundancyMap, newCompressedMap, newDimInfo)) = seqInd.foldLeft((startTC, tcMap, (newUS, newRM, newC, newDI)))((acc, i) => {
          val accTC: Rule = acc._1
          val tcMap: Map[Access, SoP] = acc._2
          val us: Map[Exp, Rule] = acc._3._1
          val rm: Map[Exp, Rule] = acc._3._2
          val c: Map[Exp, Rule] = acc._3._3
          val di: Seq[DimInfo] = acc._3._4
          val e: Exp = newExps(i)
          val head: Access = Access(getVar("head"), appendUniqueVars(accTC.head.vars, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)), Tensor)
          val sop: SoP = SoP(Seq(Prod(Seq(accTC.head, e))))
          val tc: Rule = Rule(head, sop)
          val inf: (Rule, Rule, Rule, DimInfo) = infer(tc, di, us, rm, c)
          val newUS: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head -> inf._1)))((v1, v2) => v2)
          val newRM: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head -> inf._2)))((v1, v2) => v2)
          val newC: Map[Exp, Rule] = mergeMap(Seq(c, Map[Exp, Rule](head -> inf._3)))((v1, v2) => v2)
          val newDimInfo: Seq[DimInfo] = di :+ inf._4
          val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head -> sop)))((v1, v2) => concatSoP(Seq(v1, v2)))
          (tc, newTCMap, (newUS, newRM, newC, newDimInfo))
        })
        val sop: SoP = SoP(Seq(Prod(Seq(tc.head, newExps(n)))))
        val finalTC: Rule = Rule(head, sop)
        return infer(finalTC, newDimInfo, newUniqueSet, newRedundancyMap, newC)
      }
    } else {
      if (prods.length == 2) {
        val exps1: Seq[Exp] = prods(0).exps
        val exps2: Seq[Exp] = prods(1).exps
        if (exps1.length == 1 && exps2.length == 1) {
          val e1 = exps1(0)
          val e2 = exps2(0)
          val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
          val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
          val inp1C: Rule = compressionMap.getOrElse(e1, emptyRule())
          val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
          val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
          val inp2C: Rule = compressionMap.getOrElse(e2, emptyRule())
          return binAdd(head, dimInfo, e1, e2, inp1US, inp1RM, inp1C, inp2US, inp2RM, inp2C)
        } else if (exps1.length == 1 && exps2.length >= 2 && isDirectSum(exps2.slice(1, exps2.length), dimInfo, exps1(0), exps2(0))) {
          val e1 = exps1(0)
          val e2 = exps2(0)
          val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
          val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
          val inp1C: Rule = compressionMap.getOrElse(e1, emptyRule())
          val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
          val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
          val inp2C: Rule = compressionMap.getOrElse(e2, emptyRule())
          val e2Seq = exps2.slice(1, exps2.length).asInstanceOf[Seq[Comparison]]
          return binDirectSum(head, dimInfo, e1, e2, e2Seq, inp1US, inp1RM, inp1C, inp2US, inp2RM, inp2C)
        } 
      }

      // else
      val (tcSeq1, inliningMap1, (newUniqueSet1, newRedundancyMap1, newCompressionMap1, newDimInfo1)) = prods.foldLeft((Seq.empty[Rule], Map.empty[Access, SoP], (uniqueSets, redundancyMaps, compressionMap, dimInfo)))((acc, prod) => {
        val accTCSeq: Seq[Rule] = acc._1
        val tcMap: Map[Access, SoP] = acc._2
        val us: Map[Exp, Rule] = acc._3._1
        val rm: Map[Exp, Rule] = acc._3._2
        val c: Map[Exp, Rule] = acc._3._3
        val di: Seq[DimInfo] = acc._3._4
        val allVars: Seq[Variable] = prod.exps.foldLeft(Seq.empty[Variable])((acc, e) => appendUniqueVars(acc, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)))
        val allVarsHead: Access = Access(getVar("head"), allVars, Tensor)
        val (f, head, ind): (Boolean, Access, Int) = (0 to prod.exps.length - 2).foldLeft((false, allVarsHead, 0))((a, i) => {
          val flag: Boolean = a._1
          val currHead: Access = a._2
          if (!flag) {
            val allVars: Seq[Variable] = prod.exps.slice(0, i).foldLeft(Seq.empty[Variable])((acc2, e) => appendUniqueVars(acc2, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)))
            val allVars2: Seq[Variable] = prod.exps.slice(i, prod.exps.length).foldLeft(Seq.empty[Variable])((acc2, e) => appendUniqueVars(acc2, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)))
            val someVars: Seq[Variable] = prod.exps.slice(i, prod.exps.length).foldLeft(Seq.empty[Variable])((acc2, e) => appendUniqueVars(acc2, getVariables(e)).filter(v => nonSizeVariables.contains(v)))
            val realSomeVars: Seq[Variable] = allVars2.filter(v => !someVars.contains(v))
            val vars: Seq[Variable] = appendUniqueVars(allVars, realSomeVars)
            val head: Access = Access(getVar("head"), vars, Tensor)
            if (isShift(prod.exps.slice(i, prod.exps.length), di, head)) (true, head, i)
            else a
          } else a
        })
        if (ind == 0) {
          val sop: SoP = SoP(Seq(prod))
          val tc: Rule = Rule(head, sop)
          val inf: (Rule, Rule, Rule, DimInfo) = infer(tc, di, us, rm, c)
          val newUS: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head -> inf._1)))((v1, v2) => v2)
          val newRM: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head -> inf._2)))((v1, v2) => v2)
          val newC: Map[Exp, Rule] = mergeMap(Seq(c, Map[Exp, Rule](head -> inf._3)))((v1, v2) => v2)
          val newDI: Seq[DimInfo] = di :+ inf._4
          val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head -> sop)))((v1, v2) => concatSoP(Seq(v1, v2)))
          (accTCSeq :+ tc, newTCMap, (newUS, newRM, newC, newDI))
        } else {
          val sop1: SoP = SoP(Seq(Prod(prod.exps.slice(0, ind + 1))))
          val head1Vars: Seq[Variable] = prod.exps.slice(0, ind + 1).foldLeft(Seq.empty[Variable])((acc2, e) => appendUniqueVars(acc2, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)))
          val head1: Access = Access(getVar("head"), head1Vars, Tensor)
          val tc1: Rule = Rule(head1, sop1)
          val sop2: SoP = SoP(Seq(Prod(Seq(head1) ++ prod.exps.slice(ind + 1, prod.exps.length))))
          val tc2: Rule = Rule(head, sop2)
          val inf1: (Rule, Rule, Rule, DimInfo) = infer(tc1, di, us, rm, c)
          val us2: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head1 -> inf1._1)))((v1, v2) => v2)
          val rm2: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head1 -> inf1._2)))((v1, v2) => v2)
          val c2: Map[Exp, Rule] = mergeMap(Seq(c, Map[Exp, Rule](head1 -> inf1._3)))((v1, v2) => v2)
          val di2: Seq[DimInfo] = di :+ inf1._4
          val tcMap1: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head1 -> sop1)))((v1, v2) => concatSoP(Seq(v1, v2)))
          val inf2: (Rule, Rule, Rule, DimInfo) = infer(tc2, di2, us2, rm2, c2)
          val newUS: Map[Exp, Rule] = mergeMap(Seq(us2, Map[Exp, Rule](head -> inf2._1)))((v1, v2) => v2)
          val newRM: Map[Exp, Rule] = mergeMap(Seq(rm2, Map[Exp, Rule](head -> inf2._2)))((v1, v2) => v2)
          val newC: Map[Exp, Rule] = mergeMap(Seq(c2, Map[Exp, Rule](head -> inf2._3)))((v1, v2) => v2)
          val newDI: Seq[DimInfo] = di2 :+ inf2._4
          val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap1, Map(head -> sop2)))((v1, v2) => concatSoP(Seq(v1, v2)))
          (accTCSeq :+ tc2, newTCMap, (newUS, newRM, newC, newDI))
        }
      })
      val (tcSeq, inliningMap, newUniqueSet, newRedundancyMap, newCompressedMap, newDimInfo) = cse(tcSeq1, inliningMap1, newUniqueSet1, newRedundancyMap1, newCompressionMap1, newDimInfo1)
      if (tcSeq.length == 1) {
        val tHead: Access = tcSeq(0).head
        val tUS: Rule = newUniqueSet.get(tHead).get
        val tRM: Rule = newRedundancyMap.get(tHead).get
        val tC: Rule = newCompressedMap.get(tHead).get
        val tDI: DimInfo = DimInfo(tHead, newDimInfo.toAccessMap(tHead))
        return (tUS, tRM, tC, tDI)
      }
      val n = tcSeq.length - 1
      val seqInd: Seq[Int] = 2 to n - 1
      val startHead: Access = if (n > 1)  Access(getVar("head"), appendUniqueVars(tcSeq(0).head.vars, tcSeq(1).head.vars).filter(v => nonSizeVariables.contains(v)), Tensor) else head
      val startSoP: SoP = SoP(Seq(Prod(Seq(tcSeq(0).head)), Prod(Seq(tcSeq(1).head))))
      val startTC: Rule = Rule(startHead, startSoP)
      val inf: (Rule, Rule, Rule, DimInfo) = infer(startTC, newDimInfo, newUniqueSet, newRedundancyMap, newCompressedMap)
      if (n == 1) return inf
      val newUS: Map[Exp, Rule] = mergeMap(Seq(newUniqueSet, Map[Exp, Rule](startHead -> inf._1)))((v1, v2) => v2)
      val newRM: Map[Exp, Rule] = mergeMap(Seq(newRedundancyMap, Map[Exp, Rule](startHead -> inf._2)))((v1, v2) => v2)
      val newC: Map[Exp, Rule] = mergeMap(Seq(newCompressedMap, Map[Exp, Rule](startHead -> inf._3)))((v1, v2) => v2)
      val newDI: Seq[DimInfo] = newDimInfo :+ inf._4
      val tcMap: Map[Access, SoP] = mergeMap(Seq(inliningMap, Map(startHead -> startSoP)))((v1, v2) => concatSoP(Seq(v1, v2)))
      val (tc, finalInliningMap, (finalUniqueSet, finalRedundancyMap, finalCompressedMap, finalDimInfo)) = seqInd.foldLeft((startTC, tcMap, (newUS, newRM, newC, newDI)))((acc, i) => {
        val accTC: Rule = acc._1
        val tcMap: Map[Access, SoP] = acc._2
        val us: Map[Exp, Rule] = acc._3._1
        val rm: Map[Exp, Rule] = acc._3._2
        val c: Map[Exp, Rule] = acc._3._3
        val di: Seq[DimInfo] = acc._3._4
        val e: Access = tcSeq(i).head
        val head: Access = Access(getVar("head"), appendUniqueVars(accTC.head.vars, e.vars).filter(v => nonSizeVariables.contains(v)), Tensor)
        val sop: SoP = SoP(Seq(Prod(Seq(accTC.head)), Prod(Seq(e))))
        val tc: Rule = Rule(head, sop)
        val inf: (Rule, Rule, Rule, DimInfo) = infer(tc, di, us, rm, c)
        val newUS: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head -> inf._1)))((v1, v2) => v2)
        val newRM: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head -> inf._2)))((v1, v2) => v2)
        val newC: Map[Exp, Rule] = mergeMap(Seq(c, Map[Exp, Rule](head -> inf._3)))((v1, v2) => v2)
        val newDI: Seq[DimInfo] = di :+ inf._4
        val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head -> sop)))((v1, v2) => concatSoP(Seq(v1, v2)))
        (tc, newTCMap, (newUS, newRM, newC, newDI))
      })
      val sop: SoP = SoP(Seq(Prod(Seq(tc.head)), Prod(Seq(tcSeq(n).head))))
      val finalTC: Rule = Rule(head, sop)
      // println("FIIIIIIIIIIIIIIIIIIIIIIINAAAAAAAAAALLLLLLLLLLLLLLLLLLLLL US RM:")
      // finalUniqueSet.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <US> " + cur._2.prettyFormat))
      // finalRedundancyMap.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <RM> " + cur._2.prettyFormat))
      // println("FIIIIIIIIIIIIIIIIIIIIIIINAAAAAAAAAALLLLLLLLLLLLLLLLLLLLL US RM DONE")
      val finalInf: (Rule, Rule, Rule, DimInfo) = infer(finalTC, finalDimInfo, finalUniqueSet, finalRedundancyMap, finalCompressedMap)
      return finalInf
    }

    (emptyRule(), emptyRule(), emptyRule(), emptyDimInfo())
  }

  def getVariables(index: Index): Seq[Variable] = {
    index match {
      case Variable(name) => Seq(index.asInstanceOf[Variable])
      case Arithmetic(op, index1, index2) => getVariables(index1) ++ getVariables(index2)
      case _ => Seq.empty[Variable]
    }
  }

  def getVariables(prod: Prod): Seq[Variable] = {
    prod.exps.foldLeft(Seq[Variable]())((acc, exp) => {
      val varSeq = exp match {
        case Access(name, vars, kind) => vars
        // case Comparison(op, index, variable) => Seq(variable) ++ getVariables(index) // Maybe I shouldn't consider comparisons since all of them will be moved to US and RM and iterations won't be on them if they are not in an access
        case _ => Seq()
      }
      acc ++ varSeq
    })
  }

  def getVariables(sop: SoP): Seq[Variable] = sop.prods.foldLeft(Seq[Variable]())((acc, prod) => acc ++ getVariables(prod))

  def getVariables(rule: Rule): Seq[Variable] = (rule.head.vars ++ getVariables(rule.body)).distinct

  def getAllVariables(exp: Exp): Seq[Variable] = {
    exp match {
      case Access(_, vars, _) => vars
      case Comparison(_, index, variable) => Seq(variable) ++ getVariables(index)
      case _ => Seq.empty[Variable]
    }
  } 

  def getVariables(exp: Exp): Seq[Variable] = {
    exp match {
      case Access(_, vars, _) => vars
      // case Comparison(_, index, variable) => Seq(variable) ++ getVariables(index)
      case _ => Seq.empty[Variable]
    }
  }

  def opComplement(op: String): String = {
    op match {
      case "=" => "="
      case "<" => ">"
      case "<=" => ">="
      case ">" => "<"
      case ">=" => "<="
      case _ => "???"
    }
  }

  def getEquivSet(arith: Arithmetic): Set[Arithmetic] = {
    (arith.index1, arith.index2) match {
      case (Arithmetic(_, _, _), Arithmetic(_, _, _)) => {
        val arithSet1 = getEquivSet(arith.index1.asInstanceOf[Arithmetic])
        val arithSet2 = getEquivSet(arith.index2.asInstanceOf[Arithmetic])
        if (arith.op == "+" || arith.op == "*") {
          arithSet1.foldLeft(Set(arith))((acc, cur) => {
            acc ++ arithSet2.foldLeft(Set(arith))((acc2, cur2) => {
              acc2 ++ Set(Arithmetic(arith.op, cur, cur2), Arithmetic(arith.op, cur2, cur))
            })
          })
        }
        else {
          arithSet1.foldLeft(Set(arith))((acc, cur) => {
            acc ++ arithSet2.foldLeft(Set(arith))((acc2, cur2) => {
              acc2 ++ Set(Arithmetic(arith.op, cur, cur2))
            })
          })
        }
      }
      case (_, Arithmetic(_, _, _)) => {
        val arithSet = getEquivSet(arith.index2.asInstanceOf[Arithmetic])
        if (arith.op == "+" || arith.op == "*") arithSet.foldLeft(Set(arith))((acc, cur) => acc ++ Set(Arithmetic(arith.op, arith.index1, cur), 
                                                                                                      Arithmetic(arith.op, cur, arith.index1)))
        else arithSet.foldLeft(Set(arith))((acc, cur) => acc ++ Set(Arithmetic(arith.op, arith.index1, cur)))
      }
      case (Arithmetic(_, _, _), _) => {
        val arithSet = getEquivSet(arith.index1.asInstanceOf[Arithmetic])
        if (arith.op == "+" || arith.op == "*") arithSet.foldLeft(Set(arith))((acc, cur) => acc ++ Set(Arithmetic(arith.op, cur, arith.index2), 
                                                                                                      Arithmetic(arith.op, arith.index2, cur)))
        else arithSet.foldLeft(Set(arith))((acc, cur) => acc ++ Set(Arithmetic(arith.op, cur, arith.index2)))
      }
      case _ => {
        if (arith.op == "+" || arith.op == "*") Set(arith, Arithmetic(arith.op, arith.index2, arith.index1))
        else Set(arith)
      }
    }
  }

  def getEquivSet(comp: Comparison): Set[Comparison] = {
    comp.index match {
      case Variable(_) => Set(comp, Comparison(opComplement(comp.op), comp.variable, comp.index.asInstanceOf[Variable]))
      case Arithmetic(_, _, _) => {
        val arithSet = getEquivSet(comp.index.asInstanceOf[Arithmetic])
        arithSet.foldLeft(Set(comp))((acc, cur) => acc ++ Set(Comparison(comp.op, cur, comp.variable)))
      }
      case _ => Set(comp)
    }
  }

  def getEquivSetIndex(index: Index): Set[Index] = {
    index match {
      case Arithmetic(_, _, _) => getEquivSet(index.asInstanceOf[Arithmetic]).asInstanceOf[Set[Index]]
      case _ => Set(index)
    }
  }

  def areExpsEquiv(e1: Exp, e2: Exp): Boolean = {
    if (e1 == e2) return true
    (e1, e2) match {
      case (Comparison(_, _, _), Comparison(_, _, _)) => getEquivSet(e1.asInstanceOf[Comparison]) == getEquivSet(e2.asInstanceOf[Comparison])
      case _ => false
    }
  }

  def uniqueExpSet(expSet: Set[Exp]): Set[Exp] = {
    expSet.zipWithIndex.foldLeft(Set.empty[Exp])((acc, cur) => {
      val repetetive = expSet.zipWithIndex.foldLeft(false)((acc2, cur2) => {
        if (cur._2 > cur2._2) { // comparing each exp with previous exps
          acc2 || areExpsEquiv(cur._1, cur2._1)
        } else acc2
      })
      if (!repetetive) acc ++ Set(cur._1)
      else acc
    })
  }

  def keepDistinct(rule: Rule): Rule = {
    val bodySet: Set[Set[Exp]] = rule.body.prods.map(prod => prod.exps.toSet).toSet
    Rule(rule.head, SoP(bodySet.map(expSet => Prod(uniqueExpSet(expSet).toSeq)).toSeq))
  }

  def getVariableConditionMap(variables: Seq[Variable], rule: Rule): Seq[Map[Variable, Seq[(String, Index)]]] = { 
    val varsAndRed = variables.redundancyVarsInplace
    rule.body.prods.foldLeft(Seq.empty[Map[Variable, Seq[(String, Index)]]])((acc, prod) => {
      val prodMap = prod.exps.foldLeft(Map.empty[Variable, Seq[(String, Index)]])((acc2, exp) => {
        exp match {
          case Comparison(op, index, variable) => {
            if (!varsAndRed.contains(variable) && index.isInstanceOf[Variable] && varsAndRed.contains(index.asInstanceOf[Variable])) 
              mergeMap(Seq(acc2, Map(index.asInstanceOf[Variable] -> Seq((op, variable)))))((v1, v2) => v1 ++ v2)
            else mergeMap(Seq(acc2, Map(variable -> Seq((op, index)))))((v1, v2) => v1 ++ v2)
          }
          case _ => acc2
        }
      })
      acc :+ prodMap
    })
  }

  def getSoP(variableConditionMaps: Seq[Map[Variable, Seq[(String, Index)]]]): SoP = {
    val prods = variableConditionMaps.foldLeft(Seq.empty[Prod])((acc, map) => {
      val prodExps = map.foldLeft(Seq.empty[Comparison])((acc2, cur2) => {
        val variable = cur2._1
        val condSeq = cur2._2
        val compSeq = condSeq.foldLeft(Seq.empty[Comparison])((acc3, cur3) => {
          val op = cur3._1
          val index = cur3._2
          acc3 :+ Comparison(op, index, variable)
        })
        acc2 ++ compSeq
      })
      acc :+ Prod(prodExps)
    })
    SoP(prods)
  }

  def replaceVars(index: Index, equalRepresentative: Map[Variable, Variable]): Index = {
    index match {
      case Variable(_) => equalRepresentative.getOrElse(index.asInstanceOf[Variable], index)
      case Arithmetic(op, index1, index2) => {
        val repInd1 = replaceVars(index1, equalRepresentative)
        val repInd2 = replaceVars(index2, equalRepresentative)
        Arithmetic(op, repInd1, repInd2)
      }
      case _ => index
    }
  }

  def unifyEqualVariableConditionMap(variables: Seq[Variable], variableConditionMap: Map[Variable, Seq[(String, Index)]]): (Map[Variable, Seq[(String, Index)]], Map[Variable, Variable]) = {
    val varsAndRed = variables.redundancyVarsInplace
    val equalityMap: Map[Variable, Set[Variable]] = varsAndRed.foldLeft(Map.empty[Variable, Set[Variable]])((acc, cur) => {
      val condSeq: Seq[(String, Index)] = variableConditionMap.getOrElse(cur, Seq())
      val varMap = condSeq.foldLeft(Set[Variable](cur))((acc2, cur2) => {
        if (cur2._1 == "=" && cur2._2.isInstanceOf[Variable]) acc2 ++ Set(cur2._2.asInstanceOf[Variable])
        else acc2
      })
      mergeMap(Seq(acc, Map(cur -> varMap)))((v1, v2) => v1 ++ v2)
    })

    val equalityMapAll: Map[Variable, Set[Variable]] = equalityMap.foldLeft(Map.empty[Variable, Set[Variable]])((acc, kv) => {
      val allEquals = equalityMap.foldLeft(kv._2)((acc2, kv2) => {
        if (kv._2.intersect(kv2._2).size > 0) acc2 ++ kv2._2
        else acc2
      })
      mergeMap(Seq(acc, Map(kv._1 -> allEquals)))((v1, v2) => v1 ++ v2)
    })

    val nonIterables: Set[Variable] = equalityMapAll.foldLeft(Set.empty[Variable])((acc, kv) => acc ++ Set(kv._1) ++ kv._2).diff(varsAndRed.toSet)

    val equalRepresentativeForNonIterables: Map[Variable, Variable] = nonIterables.foldLeft(Map.empty[Variable, Variable])((acc, v) => {
      val varMap = equalityMapAll.foldLeft(Map.empty[Variable, Variable])((acc2, kv) => {
        if (kv._2.contains(v)) mergeMap(Seq(acc2, Map(v -> kv._1)))((v1, v2) => v1) 
        else acc2
      })
      mergeMap(Seq(acc, varMap))((v1, v2) => v1)
    })

    val equalRepresentative: Map[Variable, Variable] = varsAndRed.foldLeft(equalRepresentativeForNonIterables)((acc, v) => {
      val varMap = equalityMapAll.foldLeft(Map.empty[Variable, Variable])((acc2, kv) => {
        if (kv._2.contains(v)) mergeMap(Seq(acc2, Map(kv._1 -> v)))((v1, v2) => v1) 
        else acc2
      })
      mergeMap(Seq(acc, varMap))((v1, v2) => v1)
    })

    val equalRepresentativeConverted: Map[Variable, Seq[(String, Index)]] = equalRepresentative.foldLeft(Map.empty[Variable, Seq[(String, Index)]])((acc, cur) => {
      if (cur._1 != cur._2) mergeMap(Seq(acc, Map(cur._2 -> Seq(("=", cur._1)))))((v1, v2) => v1 ++ v2)
      else acc
    })

    val newVariableConditionMap: Map[Variable, Seq[(String, Index)]] = variableConditionMap.foldLeft(equalRepresentativeConverted)((acc, cur) => {
      val variable: Variable = cur._1
      val condSeq: Seq[(String, Index)] = cur._2
      val nonEqMap = condSeq.foldLeft(Seq.empty[(String, Index)])((acc2, cur2) => {
        val op: String = cur2._1
        val index: Index = cur2._2
        if (op != "=") acc2 ++ Seq((op, replaceVars(index, equalRepresentative)))
        else if (op == "=" && !index.isInstanceOf[Variable]) acc2 ++ Seq((op, index))
        else acc2
      })
      mergeMap(Seq(acc, Map(replaceVars(variable, equalRepresentative).asInstanceOf[Variable] -> nonEqMap)))((v1, v2) => v1 ++ v2)
    })

    (newVariableConditionMap, equalRepresentative.filter{case(k, v) => k != v})
  }

  def unifyEqualVariableConditionMap(variables: Seq[Variable], variableConditionMaps: Seq[Map[Variable, Seq[(String, Index)]]]): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = {
    variableConditionMaps.foldLeft((Seq.empty[Map[Variable, Seq[(String, Index)]]], Seq.empty[Map[Variable, Variable]]))((acc, cur) => {
      val res = unifyEqualVariableConditionMap(variables, cur)
      (acc._1 :+ res._1, acc._2 :+ res._2)
    })
  }

  def fixConditionOrder(variables: Seq[Variable], unifiedVariableConditionMap: Map[Variable, Seq[(String, Index)]]): Map[Variable, Seq[(String, Index)]] = {
    val varsAndRed = variables.redundancyVarsInplace
    varsAndRed.zipWithIndex.foldLeft(Map.empty[Variable, Seq[(String, Index)]])((acc, varInd) => {
      val variable = varInd._1
      val ind = varInd._2
      val condSeq: Seq[(String, Index)] = unifiedVariableConditionMap.getOrElse(variable, Seq())
      val orderedMap = condSeq.foldLeft(Map.empty[Variable, Seq[(String, Index)]])((acc2, cur2) => {
        val op: String = cur2._1
        val index: Index = cur2._2
        if (index.isInstanceOf[Variable]) {
          val indexVar = index.asInstanceOf[Variable]
          if (varsAndRed.contains(indexVar) && !varsAndRed.slice(0, ind + 1).contains(indexVar)) 
            mergeMap(Seq(acc2, Map(indexVar -> Seq((opComplement(op), variable)))))((v1, v2) => v1 ++ v2)
          else mergeMap(Seq(acc2, Map(variable -> Seq((op, index)))))((v1, v2) => v1 ++ v2)
        } else mergeMap(Seq(acc2, Map(variable -> Seq((op, index)))))((v1, v2) => v1 ++ v2) // this part for arithmetics might cause problem. Ordering should change in a way that if there is an arithmetic based on next variables, we re-order variables properly and fix it.
      })
      mergeMap(Seq(acc, orderedMap))((v1, v2) => v1 ++ v2)
    })
  }

  def fixConditionOrder(variables: Seq[Variable], unifiedVariableConditionMap: Seq[Map[Variable, Seq[(String, Index)]]]): Seq[Map[Variable, Seq[(String, Index)]]] = {
    unifiedVariableConditionMap.foldLeft(Seq.empty[Map[Variable, Seq[(String, Index)]]])((acc, cur) => acc :+ fixConditionOrder(variables, cur))
  }

  def isProdEmpty(e1: Exp, e2: Exp, callCount: Int = 0): Boolean = {
    if (e1 == e2) return false
    (e1, e2) match {
      case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
        val c1 = e1.asInstanceOf[Comparison]
        val seqOp2: Seq[String] = op2 match {
          case "<" => Seq(">", ">=", "=")
          case "<=" => Seq(">")
          case ">=" => Seq("<")
          case ">" => Seq("<", "<=", "=")
          case "=" => Seq("<", ">")
          case _ => Seq()
        }
        val seqC2: Seq[Comparison] = seqOp2.foldLeft(Seq.empty[Comparison])((acc, cur) => acc :+ Comparison(cur, index2, variable2))
        val equivSet1: Set[Comparison] = getEquivSet(c1)
        val equivSet2: Seq[Set[Comparison]] = seqC2.foldLeft(Seq.empty[Set[Comparison]])((acc, cur) => acc :+ getEquivSet(cur))
        val res = equivSet2.foldLeft(false)((acc, cur) => acc || equivSet1.intersect(cur).size > 0)

        val res2 = if (variable1 == variable2 && (index1.isInstanceOf[ConstantInt] || index1.isInstanceOf[ConstantDouble]) && (index2.isInstanceOf[ConstantInt] || index2.isInstanceOf[ConstantDouble])) {
          val val1 = if (index1.isInstanceOf[ConstantInt]) index1.asInstanceOf[ConstantInt].value else index1.asInstanceOf[ConstantDouble].value
          val val2 = if (index2.isInstanceOf[ConstantInt]) index2.asInstanceOf[ConstantInt].value else index2.asInstanceOf[ConstantDouble].value
          (op1, op2) match {
            case ("<", "=") | ("<", ">=") | ("<", ">") | ("<=", ">") | ("=", ">") => val2 <= val1 
            case ("<=", "=") | ("<=", ">=") | ("=", ">=") => val2 < val1 
            case ("=", "<") | (">=", "<") | (">", "<") | (">", "<=") | (">", "=") => val2 >= val1
            case ("=", "<=") | (">=", "<=") | (">=", "=") => val2 > val1
            case ("=", "=") => val1 != val2
            case _ => false
          }
        } else false

        if (callCount == 0) res || res2 || isProdEmpty(e2, e1, 1)
        else res || res2
      }
      case _ => false
    }
  }

  def isComparisonTrivial(comp: Comparison): Boolean = {
    val op: String = comp.op
    val index: Index = comp.index
    val variable: Variable = comp.variable
    if (index.isInstanceOf[Arithmetic]) {
      val arith: Arithmetic = index.asInstanceOf[Arithmetic]
      if (op == ">" && arith.op == "+" && ((arith.index1.isInstanceOf[Variable] && arith.index1.asInstanceOf[Variable] == variable) || (arith.index2.isInstanceOf[Variable] && arith.index2.asInstanceOf[Variable] == variable))) return true
    }
    false
  }

  def simplify(rule: Rule): Rule = {
    val prodSeqNoEmpty = rule.body.prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      val isPEmpty = prod.exps.foldLeft(false)((acc2, exp) => acc2 || prod.exps.foldLeft(false)((acc3, exp2) => acc3 || isProdEmpty(exp, exp2)))
      if (isPEmpty) acc
      else {
        val expSeq: Seq[Exp] = prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => if (exp.isInstanceOf[Comparison] && isComparisonTrivial(exp.asInstanceOf[Comparison])) acc2 else acc2 :+ exp)
        if (expSeq.isEmpty) acc else acc :+ Prod(expSeq)
      }
    })
    // here it just removes products that end up in emptySet + understands that (emptySet + e = e)
    // we don't have (x >= y) * (x <= y) = (x = y). For this we might need to go through unifyEqualVariableConditionMap and simplify multiple rounds.
    Rule(rule.head, SoP(prodSeqNoEmpty))
  }

  def getIntervals(variables: Seq[Variable], fixedConditionOrder: Map[Variable, Seq[(String, Index)]], eqVarMap: Map[Variable, Index]): Map[Variable, Interval] = {
    val varsAndRed = variables.redundancyVarsInplace
    val res: Map[Variable, Interval] = varsAndRed.foldLeft(Map.empty[Variable, Interval])((acc, variable) => {
      val condSeq: Seq[(String, Index)] = fixedConditionOrder.getOrElse(variable, Seq())
      val (begin, end): (Seq[Index], Seq[Index]) = condSeq.foldLeft((Seq.empty[Index], Seq.empty[Index]))((acc2, cur2) => {
        val op: String = cur2._1
        val index: Index = cur2._2
        val (b, e) = op match {
          case "<" => (Seq(Arithmetic("+", index, ConstantInt(1))), Seq())
          case "<=" => (Seq(index), Seq())
          case ">" => (Seq(), Seq(index))
          case ">=" => (Seq(), Seq(Arithmetic("+", index, ConstantInt(1))))
          case "=" => if (eqVarMap.contains(variable)) (Seq(), Seq()) else (Seq(index), Seq(Arithmetic("+", index, ConstantInt(1))))
          case _ => (Seq(), Seq())
        }
        (acc2._1 ++ b, acc2._2 ++ e)
      })
      mergeMap(Seq(acc, Map(variable -> Interval(begin, end))))((v1, v2) => Interval(v1.begin ++ v2.begin, v1.end ++ v2.end))
    })
    res.filter{case (k, v) => !(v.begin.length == 0 || v.end.length == 0)}
  }

  def getIntervals(variables: Seq[Variable], fixedConditionOrder: Seq[Map[Variable, Seq[(String, Index)]]], eqVarMap: Seq[Map[Variable, Index]]): Seq[Map[Variable, Interval]] = {
    (fixedConditionOrder zip eqVarMap).foldLeft(Seq.empty[Map[Variable, Interval]])((acc, cur) => acc :+ getIntervals(variables, cur._1, cur._2))
  }

  def getStringChain(indexSeq: Seq[Index], m: Map[Variable, Index]): String = {
    val str = indexSeq.foldLeft("")((acc, index) => s"$acc, ${index.cFormat(m)}")
    if (str.length > 0) str.substring(2, str.length)
    else str
  }
  
  def getMinMaxMLIR(indexSeq: Seq[Index], m: Map[Variable, Index], minmax: String): (String, String) = {
    val first = indexSeq(0).cFormat(m)
    val firstVar = getVar("op")
    val arithM = if (minmax == "min") "arith.minui" else "arith.maxui"
    val (code, finalOP) = indexSeq.slice(1, indexSeq.length - 1).foldLeft((s"""%$firstVar = "${arithM}"(%$first, """, firstVar))((acc, index) => {
      val str = acc._1
      val v = acc._2
      val op = getVar("op")
      (s"""$acc${index.cFormat(m)}) : (index, index) -> index\n%$op = \"${arithM}\"(%$v, """, op)
    })
    val last = indexSeq(indexSeq.length - 1).cFormat(m)
    (s"$code%$last) : (index, index) -> index\n", finalOP)
  }

  def simplifyMath(arith: Arithmetic): Index = {
    arith match {
      case Arithmetic("+", index, ConstantInt(n)) => {
        index match {
          case Arithmetic("-", index2, ConstantInt(m)) => if (n != m) simplifyMath(Arithmetic("+", index2, ConstantInt(n - m))) else if (index2.isInstanceOf[Arithmetic]) simplifyMath(index2.asInstanceOf[Arithmetic]) else index2
          case _ => arith
        }
      }

      case Arithmetic("-", index, ConstantInt(n)) => {
        index match {
          case Arithmetic("+", index2, ConstantInt(m)) => if (n != m) simplifyMath(Arithmetic("+", index2, ConstantInt(m - n))) else if (index2.isInstanceOf[Arithmetic]) simplifyMath(index2.asInstanceOf[Arithmetic]) else index2
          case _ => arith
        }
      }

      case _ => arith
    }
  }
  
  def areBeginAndEndEqual(interval: Interval): (Boolean, Index, (Int, Int)) = {
    val intervalBeginEquivSet: Set[Index] = interval.begin.foldLeft(Set.empty[Index])((acc, index) => acc ++ getEquivSetIndex(index))
    val intervalEndEquivSet: Set[Index] = interval.end.foldLeft(Set.empty[Index])((acc, index) => acc ++ getEquivSetIndex(index))
    val intervalBeginPlusOneEquivSet: Set[Index] = interval.begin.foldLeft(Set.empty[Index])((acc, index) => acc ++ getEquivSetIndex(Arithmetic("+", index, ConstantInt(1))))
    val intervalEndMinusOneEquivSet: Set[Index] = interval.end.foldLeft(Set.empty[Index])((acc, index) => acc ++ getEquivSetIndex(Arithmetic("-", index, ConstantInt(1))))

    val intersectBEplusOne = intervalBeginPlusOneEquivSet.intersect(intervalEndEquivSet)
    val intersectBEMinusOne = intervalBeginEquivSet.intersect(intervalEndMinusOneEquivSet)

    val (begin, end): (Int, Int) =  if (intersectBEplusOne.size > 0) {
      (interval.begin.zipWithIndex.find(indexID => intersectBEplusOne.contains(Arithmetic("+", indexID._1, ConstantInt(1)))).getOrElse(ConstantInt(0), -1)._2,
      interval.end.zipWithIndex.find(indexID => intersectBEplusOne.contains(indexID._1)).getOrElse(ConstantInt(0), -1)._2)
    } else if (intersectBEMinusOne.size > 0) {
      (interval.begin.zipWithIndex.find(indexID =>intersectBEMinusOne.contains(indexID._1)).getOrElse(ConstantInt(0), -1)._2,
      interval.end.zipWithIndex.find(indexID =>intersectBEMinusOne.contains(Arithmetic("-", indexID._1, ConstantInt(1)))).getOrElse(ConstantInt(0), -1)._2)
    } else (-1, -1)

    val areEquals = intersectBEplusOne.size > 0 || intersectBEMinusOne.size > 0

    (areEquals, if (areEquals) interval.begin(begin) else "??".toVar, (begin, end))
  }

  def getNoComparisonSoP(sop: SoP): SoP = {
    SoP(sop.prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      val expSeq: Seq[Exp] = prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => {
        exp match {
          case Comparison(_, _, _) => acc2
          case _ => acc2 :+ exp
        }
      })
      if (expSeq.length == 0) acc
      else acc :+ Prod(expSeq)
    }))
  }

  def getOnlyComparisonSoP(sop: SoP): SoP = {
    SoP(sop.prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      val expSeq: Seq[Exp] = prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => {
        exp match {
          case Comparison(_, _, _) => acc2 :+ exp
          case _ => acc2
        }
      })
      if (expSeq.length == 0) acc
      else acc :+ Prod(expSeq)
    }))
  }

  def getNoComparisonButEQSoP(sop: SoP): SoP = {
    SoP(sop.prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      val expSeq: Seq[Exp] = prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => {
        exp match {
          case Comparison("=", _, _) => acc2 :+ exp
          case Comparison(_, _, _) => acc2
          case _ => acc2 :+ exp
        }
      })
      if (expSeq.length == 0) acc
      else acc :+ Prod(expSeq)
    }))
  }

  def removeNonLHSEQVars(lhsVars: Seq[Variable], fixedConditionOrderMap: Map[Variable, Seq[(String, Index)]]): (Map[Variable, Seq[(String, Index)]], Map[Variable, Index]) = {
    // we lose information like x0 <= y0 <= y1 <= x1 if y0 and y1 are not in lhs vars
    // it only supports the special case of creating covariance matrix for linear/polynomial regression
    val rhsEQVarsMap: Map[Variable, Index] = fixedConditionOrderMap.foldLeft(Map.empty[Variable, Index])((acc, cur) => {
      val variable = cur._1
      val condSeq: Seq[(String, Index)] = cur._2
      if (lhsVars.contains(variable)) acc else {
        val eq: Seq[(String, Index)] = condSeq.filter(cond => cond._1 == "=")
        if (eq.length > 0) mergeMap(Seq(acc, Map(variable -> eq(0)._2)))((v1, v2) => v2)
        else acc
      }
    })

    // println("rhsEQVarsMap", rhsEQVarsMap)

    val newVarMapNEQ: Map[Variable, Seq[(String, Index)]] = fixedConditionOrderMap.filter(e => !rhsEQVarsMap.keySet.contains(e._1))
    val newVarMapEQ: Map[Variable, Seq[(String, Index)]] = fixedConditionOrderMap.filter(e => rhsEQVarsMap.keySet.contains(e._1))
    
    val replacedVarNEQ: Map[Variable, Seq[(String, Index)]] = newVarMapNEQ.foldLeft(Map.empty[Variable, Seq[(String, Index)]])((acc, cur) => {
      val variable = cur._1
      val condSeq: Seq[(String, Index)] = cur._2
      val newCondSeq: Seq[(String, Index)] = condSeq.foldLeft(Seq.empty[(String, Index)])((acc2, cond) => {
        val op: String = cond._1
        val index: Index = cond._2
        if (index.isInstanceOf[Variable] && rhsEQVarsMap.keySet.contains(index.asInstanceOf[Variable])) acc2 :+ (op, rhsEQVarsMap.get(index.asInstanceOf[Variable]).get)
        else acc2 :+ cond
      })
      mergeMap(Seq(acc, Map(variable -> newCondSeq)))((v1, v2) => v1 ++ v2)
    })

    // println("replacedVarNEQ", replacedVarNEQ)

    val replacedVarEQ: Map[Variable, Seq[(String, Index)]] = newVarMapEQ.foldLeft(replacedVarNEQ)((acc, cur) => {
      val variable = cur._1
      val condSeq: Seq[(String, Index)] = cur._2
      val newCondMap: Map[Variable, Seq[(String, Index)]] = condSeq.foldLeft(Map.empty[Variable, Seq[(String, Index)]])((acc2, cond) => {
        val op: String = cond._1
        val index: Index = cond._2
        if (index.isInstanceOf[Variable] && replacedVarNEQ.keySet.contains(index.asInstanceOf[Variable])) {
          val newVar: Variable = index.asInstanceOf[Variable]
          val newOp: String = opComplement(op)
          val newIndex: Index = rhsEQVarsMap.get(variable).get
          if (newIndex.isInstanceOf[Variable] && newIndex.asInstanceOf[Variable] == newVar) acc2 else mergeMap(Seq(acc2, Map(newVar -> Seq((newOp, newIndex)))))((v1, v2) => v1 ++ v2)
        } else if (index.isInstanceOf[Variable] && rhsEQVarsMap.keySet.contains(index.asInstanceOf[Variable])) {
          val repVar1: Index = rhsEQVarsMap.get(variable).get
          val repVar2: Index = rhsEQVarsMap.get(index.asInstanceOf[Variable]).get
          (repVar1, repVar2) match {
            case (Arithmetic(op1, index11, index12), Arithmetic(op2, index21, index22)) => {
              if (index11.isInstanceOf[Variable] && index21.isInstanceOf[Variable] && replacedVarNEQ.keySet.contains(index11.asInstanceOf[Variable]) && replacedVarNEQ.keySet.contains(index21.asInstanceOf[Variable]) && index12 == index22 && op1 == op2) {
                mergeMap(Seq(acc2, Map(index11.asInstanceOf[Variable] -> Seq((op, index21.asInstanceOf[Variable])))))((v1, v2) => v1 ++ v2)
              } else acc2
            }
            case _ => acc2
          }

        } else acc2
      })
      mergeMap(Seq(acc, newCondMap))((v1, v2) => v1 ++ v2)
    })

    (replacedVarEQ, rhsEQVarsMap)
  }

  def removeNonLHSEQVars(lhsVars: Seq[Variable], fixedConditionOrderMap: Seq[Map[Variable, Seq[(String, Index)]]]): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Index]]) = {
    fixedConditionOrderMap.foldLeft((Seq.empty[Map[Variable, Seq[(String, Index)]]], Seq.empty[Map[Variable, Index]]))((acc, e) => {
      val (m1, m2): (Map[Variable, Seq[(String, Index)]], Map[Variable, Index]) = removeNonLHSEQVars(lhsVars, e)
      (acc._1 :+ m1, acc._2 :+ m2)
    })
  }

  def indexMin(i1: Index, i2: Index): Seq[Index] = {
    (i1, i2) match {
      case (Variable(name), Arithmetic(op, index1, index2)) => if (op == "+" && ((index1.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == i1) || (index2.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == i1))) Seq(i1) else Seq(i1, i2)
      case (Arithmetic(op, index1, index2), Variable(name)) => indexMin(i2, i1)
      case (ConstantInt(0), _) => Seq(i1)
      case (_, ConstantInt(0)) => Seq(i2)
      case _ if (i1 == i2) => Seq(i1)
      case _ => Seq(i1, i2)
    }
  }

  def indexMax(i1: Index, i2: Index): Seq[Index] = {
    (i1, i2) match {
      case (Variable(name), Arithmetic(op, index1, index2)) => if (op == "+" && ((index1.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == i1) || (index2.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == i1))) Seq(i2) else Seq(i1, i2)
      case (Arithmetic(op, index1, index2), Variable(name)) => indexMax(i2, i1)
      case (ConstantInt(0), _) => Seq(i2)
      case (_, ConstantInt(0)) => Seq(i1)
      case _ if (i1 == i2) => Seq(i1)
      case _ => Seq(i1, i2)
    }
  }

  def indexMin(inds: Seq[Index]): Seq[Index] = {
    if (inds.length == 0) return Seq(ConstantInt(0))
    if (inds.length == 1) return Seq(inds(0))
    if (inds.length == 2) return indexMin(inds(0), inds(1))

    
    val i2: Int = inds.zipWithIndex.slice(1, inds.length).foldLeft(-1)((acc2, indI2) => {
      val index2: Index = indI2._1
      val i2: Int = indI2._2
      if (acc2 != -1) acc2
      else {
        val res: Seq[Index] = indexMin(inds(0), index2)
        if (res.length == 1) i2 else acc2
      }
    })
    if (i2 == -1) Seq(inds(0)) ++ indexMin(inds.slice(1, inds.length)) else indexMin(indexMin(inds(0), inds(i2)) ++ inds.zipWithIndex.slice(1, inds.length).filter(e => e._2 != i2).map(e => e._1))
  }

  def indexMax(inds: Seq[Index]): Seq[Index] = {
    if (inds.length == 0) return Seq(ConstantInt(0))
    if (inds.length == 1) return Seq(inds(0))
    if (inds.length == 2) return indexMax(inds(0), inds(1))


    val i2: Int = inds.zipWithIndex.slice(1, inds.length).foldLeft(-1)((acc2, indI2) => {
      val index2: Index = indI2._1
      val i2: Int = indI2._2
      if (acc2 != -1) acc2
      else {
        val res: Seq[Index] = indexMax(inds(0), index2)
        if (res.length == 1) i2 else acc2
      }
    })
    if (i2 == -1) Seq(inds(0)) ++ indexMax(inds.slice(1, inds.length)) else indexMax(indexMax(inds(0), inds(i2)) ++ inds.zipWithIndex.slice(1, inds.length).filter(e => e._2 != i2).map(e => e._1))
  }

  def simplifyIndexSeq(indexSeq: Seq[Index], m: String): Seq[Index] = {
    if (m == "min") indexMin(indexSeq)
    else if (m == "max") indexMax(indexSeq)
    else indexSeq
  }

  def simplifyIntervals(interval: Map[Variable, Interval]): Map[Variable, Interval] = {
    interval.map{case(v, i) => {
      val b: Seq[Index] = i.begin
      val e: Seq[Index] = i.end
      val newB: Seq[Index] = simplifyIndexSeq(b, "max")
      val newE: Seq[Index] = simplifyIndexSeq(e, "min")
      (v -> Interval(newB, newE))
    }}.toMap
  }

  def simplifyIntervals(intervals: Seq[Map[Variable, Interval]]): Seq[Map[Variable, Interval]] = intervals.map(i => simplifyIntervals(i))

  def getSoPFromInterval(intervals: Seq[Map[Variable, Interval]], eqVarMap: Seq[Map[Variable, Index]]): SoP = {
    SoP((intervals zip eqVarMap).map{case(m, vm) => {
        val c1: Seq[Comparison] = m.foldLeft(Seq.empty[Comparison])((acc, cur) => {
          val v: Variable = cur._1
          val i: Interval = cur._2
          val b: Seq[Index] = i.begin
          val e: Seq[Index] = i.end
          val s1: Seq[Comparison] = b.map(l => Comparison("<=", l, v))
          val s2: Seq[Comparison] = e.map(u => Comparison(">", u, v))
          acc ++ s1 ++ s2
        })
        val c2: Seq[Comparison] = vm.foldLeft(Seq.empty[Comparison])((acc, cur) => acc :+ Comparison("=", cur._2, cur._1))
        Prod(c1 ++ c2)
    }})
  }

  def codeGenRule(tensorComputation: Rule, dimInfo: Seq[DimInfo], variables: Seq[Variable], intervals: Seq[Map[Variable, Interval]], equalityVarMap: Seq[Map[Variable, Index]], genType: AccessType, peqMode: Boolean = true, codeMotion: Boolean = true, dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map()): String = {
    // we should make sure that all the variables that are in the right hand side of an addition, we have a condition over them or we don't add them at all. Look at e2eLRDimInfo3.txt, first for loop, for this!
    val vars = if (genType == RedundancyMap) variables.redundancyVarsInplace else variables
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val dimVarMap: Map[Variable, Seq[Dim]] = dimInfo.toVarsMap
    val tcBodya: SoP = getNoComparisonSoP(tensorComputation.body) 
    val tcBodyEQ: SoP = getNoComparisonButEQSoP(tensorComputation.body)

    if (intervals == Seq.empty[Map[Variable, Interval]]) {
      return s"${tensorComputation.head.cFormat} += ${tcBodya.cFormat};"
    }

    (intervals zip equalityVarMap).foldLeft("")((acc, mapEqVar) => {
      val map: Map[Variable, Interval] = mapEqVar._1
      val eqVar: Map[Variable, Index] = mapEqVar._2
      // println("eqVar:")
      // eqVar.foldLeft()((_, cur) => println(cur._1.prettyFormat  + " -> " + cur._2.prettyFormat))
      var cntVars: Seq[Variable] = Seq.empty[Variable]
      val (tc, nestedLoops, di, finalHeadComputation): (Rule, String, Seq[DimInfo], Access) = vars.zipWithIndex.foldLeft((Rule(tensorComputation.head, tcBodya), "", dimInfo, Access("", Seq.empty[Variable], Tensor)))((acc2, variableInd) => {
        val variable: Variable = variableInd._1
        val interval = map.getOrElse(variable, Interval(Seq(), Seq()))
        val (areEquals, index, (b, e)) = areBeginAndEndEqual(interval)
        val newInterval: Interval = if((b, e) == (-1, -1)) interval // new interval without equal value
                          else Interval(interval.begin.zipWithIndex.filter(indexID => indexID._2 != b).map(indexID => indexID._1),
                                interval.end.zipWithIndex.filter(indexID => indexID._2 != e).map(indexID => indexID._1))
        val newInterval2: Interval = newInterval
        val begin = if(newInterval2.begin.size > 1) s"std::max({${getStringChain(newInterval2.begin, eqVar)}})" else if (newInterval2.begin.size == 1) newInterval2.begin(0).cFormat(eqVar) else ""
        val end = if(newInterval2.end.size > 1) s"std::min({${getStringChain(newInterval2.end, eqVar)}})" else if (newInterval2.end.size == 1) newInterval2.end(0).cFormat(eqVar) else ""
        val code = if(eqVar.contains(variable)) {
          cntVars = cntVars :+ variable
          ""
        } else if (areEquals) { // in this case all conditions should not be checked since it might have forward referencing
          val init = if (index.cFormat(eqVar) != variable.cFormat) s"int ${variable.cFormat} = ${index.cFormat(eqVar)};" else s"int ${variable.cFormat} = ${index.cFormat};"
          // eqVar = mergeMap(Seq(eqVar, Map(variable -> index)))((v1, v2) => v2)
          val rest = if (begin != "" && end != "") s"if ($begin <= ${index.cFormat(eqVar)} && ${index.cFormat} < $end) {" 
          else if (begin != "" && end == "") s"if ($begin <= ${index.cFormat(eqVar)}) {" 
          else if (begin == "" && end != "") s"if (${index.cFormat(eqVar)} < $end) {" 
          else {
            cntVars = cntVars :+ variable
            s""
          }
          s"$init\n$rest"
        } else {
            if (begin != "" && end != "") s"for (int ${variable.cFormat} = $begin; ${variable.cFormat} < $end; ++${variable.cFormat}) {"
            else if (begin != "" && end == "") {
              cntVars = cntVars :+ variable
              s"int ${variable.cFormat} = $begin;" 
            }
            else if (begin == "" && end != "") {
              cntVars = cntVars :+ variable
              s"int ${variable.cFormat} = $end - 1;" 
            } 
            else {
              cntVars = cntVars :+ variable
              ""
            }
        }
        if (codeMotion) {
          // if current variable is equal to first element of each of the variables of accesses in the map, do code motion for it
          // update the map in a way that previous variables that include code motion be removed and new variable with .slice(1, length) of variables be in it
          val tc: Rule = acc2._1
          val di: Seq[DimInfo] = acc2._3
          val diMap: Map[Access, Seq[Dim]] = di.toAccessMap

          val (head, headCode): (Access, String) = if ((variableInd._2 != vars.length - 1 && genType == UniqueSet) || (variableInd._2 != vars.length / 2 - 1 && genType == RedundancyMap) || (tc.body.prods.length > 1 && genType != RedundancyMap)) {
            if (tc.head.vars.length > 0 && tc.head.vars(0) == variable) {
              if (tc.head.vars.length == 1) {
                val head = Access("tmp", Seq.empty[Variable], Tensor)
                val headCode = s"double tmp = 0.0;\n"
                (head, headCode)
              } else {
                val head = Access(getVar(s"cm"), tc.head.vars.slice(1, tc.head.vars.length), tc.head.kind) 
                val headCode = s"auto &${head.name} = ${tc.head.name}[${variable.cFormat(eqVar)}];\n"
                (head, headCode) 
              }
            } else (tc.head, "")
          } else (tc.head, "")

          val allVars: Set[Variable] = tc.head.vars.toSet ++ eqVar.keySet
          
          val (bodyProdSeq, bodyCode, newDI): (Seq[Prod], String, Seq[DimInfo]) = if (variableInd._2 != vars.length - 1 && genType != RedundancyMap) {
            tc.body.prods.foldLeft((Seq.empty[Prod], "", di))((acc4, prod) => {
              val allRHSVars: Set[Variable] = prod.exps.foldLeft(Set.empty[Variable])((accRHS, exp) => {
                exp match {
                  case Access(name, vars, kind) => accRHS ++ vars.toSet
                  case _ => accRHS
                }
              })
              val di: Seq[DimInfo] = acc4._3
              val diMap: Map[Access, Seq[Dim]] = di.toAccessMap

              val (newProd, cmCode, newDI): (Seq[Exp], String, Seq[DimInfo]) = // if (allRHSVars.subsetOf(allVars)) {  // --> should the subset be the other way around?
                prod.exps.foldLeft((Seq.empty[Exp], "", Seq.empty[DimInfo]))((acc3, exp) => {
                  val access: Access = exp.asInstanceOf[Access]
                  if (dataLayoutMap.contains(access)) (acc3._1 :+ access, acc3._2, acc3._3)
                  else {
                    val (newAcc, accCode, newDI): (Access, String, Seq[DimInfo]) = if (access.vars.length > 0 && access.vars(0) == variable) {
                      val newAcc = Access(getVar(s"cm"), access.vars.slice(1, access.vars.length), access.kind)
                      val newDims: Seq[Dim] = if (diMap.contains(access)) diMap.get(access).get.slice(1, access.vars.length) else Seq.empty[Dim]
                      val newDI: Seq[DimInfo] = if (newDims.length > 0) Seq(DimInfo(newAcc, newDims)) else Seq.empty[DimInfo]

                      val conds: String = if (diMap.contains(access)) {
                        val v: Variable = variable
                        val d: Dim = diMap.get(access).get(0)
                        val b: Seq[Index] = if (map.contains(v)) map.get(v).get.begin else Seq.empty[Index]
                        val e: Seq[Index] = if (map.contains(v)) map.get(v).get.end else Seq.empty[Index]
                        val fb: Boolean = b.foldLeft(false)((acc, beginInd) => {
                          val res: Seq[Index] = indexMin(beginInd, d)
                          if (res.length == 1 && res(0) == d) acc || true else acc
                        })
                        val fe: Boolean = e.foldLeft(false)((acc, endInd) => {
                          val res: Seq[Index] = indexMin(endInd, d)
                          if (res.length == 1 && res(0) == endInd && res(0) != d) acc || true else acc
                        })
                        if (fb) "NOT!HAPPENING!" else if (fe) s"${v.cFormat(eqVar)} < ${d.cFormat(eqVar)}" else ""
                      } else ""

                      val accCode = if (conds.contains("NOT!HAPPENING!")) "" else if (conds == "") s"auto &${newAcc.name} = ${access.name}[${variable.cFormat(eqVar)}];\n" else s"auto &${newAcc.name} = ($conds) ? ${access.name}[${variable.cFormat(eqVar)}] : 0;\n"
                      (newAcc, accCode, newDI)
                    } else (access, "", Seq.empty[DimInfo])
                    (acc3._1 :+ newAcc, s"${acc3._2}$accCode", acc3._3 ++ newDI)
                  }
                })
              // } else (Seq.empty[Exp], "", Seq.empty[DimInfo]) //
              
              if (!(newProd == Seq.empty[Exp] && cmCode == "")) (acc4._1 :+ Prod(newProd), s"${acc4._2}$cmCode", acc4._3 ++ newDI) else acc4
            })
          } else (tc.body.prods, "", di)
          val body = SoP(bodyProdSeq)

          val newTC: Rule = Rule(head, body)
          val oH: Access = if (head.name == "tmp" && acc2._4.name == "") tc.head else acc2._4
          (newTC, s"${acc2._2}\n$code\n$headCode\n$bodyCode", newDI, oH)
        } else (acc2._1, s"${acc2._2}\n$code", acc2._3, acc2._4)
      })

      val defaultDataLayout = (x: Seq[Variable]) => x

      // why constants are not exp as well? Then I could replace the comparison below by ConstantInt(1) instead.
      val tcBody: SoP = if (tc.body == emptySoP()) SoP(Seq(Prod(Seq(trueComparison())))) else tc.body // if it's only comparison, then it was just a bunch of comparison multiplications so their value is only 1. Their ranges is inside unique set and redundancy maps already.
      val allVars: Set[Variable] = tensorComputation.head.vars.toSet ++ eqVar.keySet
      val body = if (genType == RedundancyMap) s"${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} = ${Access(tensorComputation.head.name, tensorComputation.head.vars.redundancyVars, tensorComputation.head.kind).cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))};" else {
        if (tcBody.prods.length == 1) if(peqMode) s"${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} += ${tcBody.prods(0).cFormat(eqVar, dataLayoutMap)};" else s"${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} = ${tcBody.prods(0).cFormat(eqVar, dataLayoutMap)};"
        else (tcBody.prods zip tcBodya.prods).foldLeft("")((acc, prodAProd) => {
          val prod: Prod = prodAProd._1
          val aProd: Prod = prodAProd._2
          val allRHSVars: Set[Variable] = aProd.exps.foldLeft(Set.empty[Variable])((acc2, exp) => {
            exp match {
              case Access(name, vars, kind) => acc2 ++ vars.toSet
              case _ => acc2
            }
          })
          if (allRHSVars.subsetOf(allVars)) {
            val conds: String = aProd.exps.foldLeft("")((acc2, exp) => {
              exp match {
                case Access(name, vars, kind) => {
                  val access: Access = exp.asInstanceOf[Access]
                  val conds: String = if (dimMap.contains(access)) {
                    (vars zip dimMap.get(access).get).foldLeft("")((acc3, varDim) => {
                      val v: Variable = varDim._1
                      val d: Dim = varDim._2
                      val b: Seq[Index] = if (map.contains(v)) map.get(v).get.begin else Seq.empty[Index]
                      val e: Seq[Index] = if (map.contains(v)) map.get(v).get.end else Seq.empty[Index]
                      val fb: Boolean = b.foldLeft(false)((acc, beginInd) => {
                        val res: Seq[Index] = indexMin(beginInd, d)
                        if (res.length == 1 && res(0) == d) acc || true else acc
                      })
                      val fe: Boolean = e.foldLeft(false)((acc, endInd) => {
                        val res: Seq[Index] = indexMin(endInd, d)
                        if (res.length == 1 && res(0) == endInd && res(0) != d) acc || true else acc
                      })
                      if (fb) "NOT!HAPPENING!" else if (fe) {
                        if (acc3 != "" ) s"$acc3 && ${v.cFormat(eqVar)} < ${d.cFormat(eqVar)}" else s"${v.cFormat(eqVar)} < ${d.cFormat(eqVar)}"
                      } else acc3
                    })
                  } else ""
                  if (acc2 == "") conds else if (conds == "") acc2 else s"$acc2 && $conds"
                }
                case _ => acc2
              }
            })
            if (conds.contains("NOT!HAPPENING!")) acc else if (conds != "") {
              s"$acc\nif ($conds) {\n${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} += ${prod.cFormat(eqVar, dataLayoutMap)};\n}"
            } else s"$acc\n${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} += ${prod.cFormat(eqVar, dataLayoutMap)};\n"
          } else acc
        })
      } // change wrt code motion and use the newest variables with the corresponding list to them
      // val body = if (genType == RedundancyMap) s"${tensorComputation.head.cFormat} = ${tensorComputation.head.cRedFormat};" else tensorComputation.cPeqFormat

      val finalBrackets = vars.reverse.filter(e => !cntVars.contains(e)).foldLeft("")((acc, v) => {
        if (codeMotion && finalHeadComputation.vars.length > 0 && finalHeadComputation.vars(0) == v) s"$acc${finalHeadComputation.cFormat(eqVar, dataLayoutMap.getOrElse(finalHeadComputation, defaultDataLayout))} += tmp;\n}\n"
        else s"$acc}\n"
      })
      
      s"$acc\n$nestedLoops\n$body\n$finalBrackets"
    })
  }

  def codeGenRuleMLIR(tensorComputation: Rule, dimInfo: Seq[DimInfo], variables: Seq[Variable], intervals: Seq[Map[Variable, Interval]], equalityVarMap: Seq[Map[Variable, Index]], genType: AccessType, peqMode: Boolean = true, codeMotion: Boolean = false, dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map()): String = {
    // we should make sure that all the variables that are in the right hand side of an addition, we have a condition over them or we don't add them at all. Look at e2eLRDimInfo3.txt, first for loop, for this!
    val vars = if (genType == RedundancyMap) variables.redundancyVarsInplace else variables
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val dimVarMap: Map[Variable, Seq[Dim]] = dimInfo.toVarsMap
    val tcBodya: SoP = getNoComparisonSoP(tensorComputation.body) 
    val tcBodyEQ: SoP = getNoComparisonButEQSoP(tensorComputation.body)

    if (intervals == Seq.empty[Map[Variable, Interval]]) return tensorComputation.MLIRFormat(peqMode=peqMode, cnt_inc=cnt)

    (intervals zip equalityVarMap).foldLeft("")((acc, mapEqVar) => {
      val map: Map[Variable, Interval] = mapEqVar._1
      val eqVar: Map[Variable, Index] = mapEqVar._2
      // println("eqVar:")
      // eqVar.foldLeft()((_, cur) => println(cur._1.prettyFormat  + " -> " + cur._2.prettyFormat))
      var cntVars: Seq[Variable] = Seq.empty[Variable]
      var beginEndEqVars: Seq[Variable] = Seq.empty[Variable]
      var conditionSetsMap: Map[Variable, (String, String)] = Map.empty[Variable, (String, String)]
      val (tc, nestedLoops, di, finalHeadComputation): (Rule, String, Seq[DimInfo], Access) = vars.zipWithIndex.foldLeft((Rule(tensorComputation.head, tcBodya), "", dimInfo, Access("", Seq.empty[Variable], Tensor)))((acc2, variableInd) => {
        val variable: Variable = variableInd._1
        val interval = map.getOrElse(variable, Interval(Seq(), Seq()))
        val (areEquals, index, (b, e)) = areBeginAndEndEqual(interval)
        val newInterval: Interval = if((b, e) == (-1, -1)) interval // new interval without equal value
                          else Interval(interval.begin.zipWithIndex.filter(indexID => indexID._2 != b).map(indexID => indexID._1),
                                interval.end.zipWithIndex.filter(indexID => indexID._2 != e).map(indexID => indexID._1))
        val newInterval2: Interval = newInterval
        val (beginCode, beginVar) = if(newInterval2.begin.size > 1) {
          getMinMaxMLIR(newInterval2.begin, eqVar, "max")
        } else if (newInterval2.begin.size == 1) {
          ("", newInterval2.begin(0).cFormat(eqVar))
        } else ("", "")
        val (endCode, endVar) = if(newInterval2.end.size > 1) {
          getMinMaxMLIR(newInterval2.end, eqVar, "min")
        } else if (newInterval2.end.size == 1) { 
          ("", newInterval2.end(0).cFormat(eqVar))
        } else ("", "")
        val code = if(eqVar.contains(variable)) {
          cntVars = cntVars :+ variable
          ""
        } else if (areEquals) { // in this case all conditions should not be checked since it might have forward referencing
          beginEndEqVars = beginEndEqVars :+ variable
          val init = if (index.cFormat(eqVar) != variable.cFormat) s"""%${variable.cFormat} = affine.apply affine_map<(i) -> (i)>(%${index.cFormat(eqVar)})""" else s"""%${variable.cFormat} = affine.apply affine_map<(i) -> (i)>(%${index.cFormat})""" 
          // eqVar = mergeMap(Seq(eqVar, Map(variable -> index)))((v1, v2) => v2)
          val rest = if (beginVar != "" && endVar != "") {
            val cmpSet = s"""{condition = affine_set<(d0)[s0, s1]: (s0 <= d0, d0 <= s1 - 1)>}"""
            conditionSetsMap += (variable -> (cmpSet, "index,index,index"))
            s""""affine.if"(%${variable.cFormat}, %$beginVar, %$endVar) ({\n"""
          } else if (beginVar != "" && endVar == "") {
            val cmpSet = s"""{condition = affine_set<(d0)[s0]: (s0 <= d0)>}"""
            conditionSetsMap += (variable -> (cmpSet, "index,index"))
            s""""affine.if"(%${variable.cFormat}, %$beginVar) ({\n"""
          } else if (beginVar == "" && endVar != "") {
            val cmpSet = s"""{condition = affine_set<(d0)[s1]: (d0 <= s1 - 1)>}"""
            conditionSetsMap += (variable -> (cmpSet, "index,index"))
            s""""affine.if"(%${variable.cFormat}, %$endVar) ({\n"""
          } else {
            cntVars = cntVars :+ variable
            s""
          }
          s"$init\n$rest"
        } else {
            if (beginVar != "" && endVar != "") {
              if (!vars.slice(0, variableInd._2 + 1).toSet.subsetOf(tensorComputation.head.vars.toSet) || vars.slice(0, variableInd._2 + 1).toSet == tensorComputation.head.vars.toSet) s"""%${variable.cFormat(eqVar)}_sum = affine.for %${variable.cFormat(eqVar)} = %$beginVar to %$endVar step 1 iter_args(%iter_sum_${variable.cFormat(eqVar)} = %zerof) -> (f64) {\n"""
              else s"""affine.for %${variable.cFormat(eqVar)} = %$beginVar to %$endVar step 1 {\n"""
              // if (!vars.slice(0, variableInd._2 + 1).toSet.subsetOf(tensorComputation.head.vars.toSet)) s"""%${variable.cFormat(eqVar)}_sum = "scf.for"(%$beginVar, %$endVar, %1, %zerof) ({\n^bb0(%${variable.cFormat(eqVar)}: index, %iter_sum_${variable.cFormat(eqVar)}: f64):\n"""
              // else s""""scf.for"(%$beginVar, %$endVar, %1) ({\n^bb0(%${variable.cFormat(eqVar)}: index):\n"""
            }
            else if (beginVar != "" && endVar == "") {
              cntVars = cntVars :+ variable
              s"""%${variable.cFormat} = affine.apply affine_map<(i) -> (i)>(%${beginVar})"""
            }
            else if (beginVar == "" && endVar != "") {
              cntVars = cntVars :+ variable
              s"""%${variable.cFormat} = affine.apply affine_map<(i) -> (i - 1)>(%${endVar})"""
            } 
            else {
              cntVars = cntVars :+ variable
              ""
            }
        }
        (acc2._1, s"${acc2._2}\n$beginCode$endCode$code", acc2._3, acc2._4)
      })

      val defaultDataLayout = (x: Seq[Variable]) => x

      // why constants are not exp as well? Then I could replace the comparison below by ConstantInt(1) instead.
      val tcBody: SoP = if (tc.body == emptySoP()) SoP(Seq(Prod(Seq(trueComparison())))) else tc.body // if it's only comparison, then it was just a bunch of comparison multiplications so their value is only 1. Their ranges is inside unique set and redundancy maps already.
      val allVars: Set[Variable] = tensorComputation.head.vars.toSet ++ eqVar.keySet
      val finalV: String = getVar("finalV")
      val body = if (genType == RedundancyMap) { // TODO: write this in MLIR
        s"${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} = ${Access(tensorComputation.head.name, tensorComputation.head.vars.redundancyVars, tensorComputation.head.kind).cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))};" 
      }
      else {
        if (tcBody.prods.length == 1) {s"${tcBody.prods(0).MLIRFormat(eqVar, finalV, cnt_inc = cnt)}" ; cnt += 200}
        else {tcBody.MLIRFormat(eqVar, finalV, cnt_inc = cnt); cnt += 200}
        // else (tcBody.prods zip tcBodya.prods).foldLeft("")((acc, prodAProd) => {
        //   val prod: Prod = prodAProd._1
        //   val aProd: Prod = prodAProd._2
        //   val allRHSVars: Set[Variable] = aProd.exps.foldLeft(Set.empty[Variable])((acc2, exp) => {
        //     exp match {
        //       case Access(name, vars, kind) => acc2 ++ vars.toSet
        //       case _ => acc2
        //     }
        //   })
        //   if (allRHSVars.subsetOf(allVars)) {
        //     val conds: String = aProd.exps.foldLeft("")((acc2, exp) => {
        //       exp match {
        //         case Access(name, vars, kind) => {
        //           val access: Access = exp.asInstanceOf[Access]
        //           val conds: String = if (dimMap.contains(access)) {
        //             (vars zip dimMap.get(access).get).foldLeft("")((acc3, varDim) => {
        //               val v: Variable = varDim._1
        //               val d: Dim = varDim._2
        //               val b: Seq[Index] = if (map.contains(v)) map.get(v).get.begin else Seq.empty[Index]
        //               val e: Seq[Index] = if (map.contains(v)) map.get(v).get.end else Seq.empty[Index]
        //               val fb: Boolean = b.foldLeft(false)((acc, beginInd) => {
        //                 val res: Seq[Index] = indexMin(beginInd, d)
        //                 if (res.length == 1 && res(0) == d) acc || true else acc
        //               })
        //               val fe: Boolean = e.foldLeft(false)((acc, endInd) => {
        //                 val res: Seq[Index] = indexMin(endInd, d)
        //                 if (res.length == 1 && res(0) == endInd && res(0) != d) acc || true else acc
        //               })
        //               if (fb) "NOT!HAPPENING!" else if (fe) {
        //                 if (acc3 != "" ) s"$acc3 && ${v.cFormat(eqVar)} < ${d.cFormat(eqVar)}" else s"${v.cFormat(eqVar)} < ${d.cFormat(eqVar)}"
        //               } else acc3
        //             })
        //           } else ""
        //           if (acc2 == "") conds else if (conds == "") acc2 else s"$acc2 && $conds"
        //         }
        //         case _ => acc2
        //       }
        //     })
        //     if (conds.contains("NOT!HAPPENING!")) acc else if (conds != "") {
        //       s"$acc\nif ($conds) {\n${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} += ${prod.cFormat(eqVar, dataLayoutMap)};\n}"
        //     } else s"$acc\n${tc.head.cFormat(eqVar, dataLayoutMap.getOrElse(tc.head, defaultDataLayout))} += ${prod.cFormat(eqVar, dataLayoutMap)};\n"
        //   } else acc
        // })
      } // change wrt code motion and use the newest variables with the corresponding list to them
      // val body = if (genType == RedundancyMap) s"${tensorComputation.head.cFormat} = ${tensorComputation.head.cRedFormat};" else tensorComputation.cPeqFormat

      val filteredVars = vars.reverse.filter(e => !cntVars.contains(e))
      val finalBrackets = filteredVars.zipWithIndex.foldLeft("")((acc, vi) => {
        val v = vi._1
        val i = vi._2
        if (codeMotion && finalHeadComputation.vars.length > 0 && finalHeadComputation.vars(0) == v) s"$acc${finalHeadComputation.cFormat(eqVar, dataLayoutMap.getOrElse(finalHeadComputation, defaultDataLayout))} += tmp;\n}\n"
        else {
          val containsV = beginEndEqVars.contains(v)
          val (cmpSet, ind) = conditionSetsMap.getOrElse(v, ("", ""))
          val nc = if (i == 0) {
            if (containsV) s""""affine.yield"(%$finalV): (f64) -> ()\n}, {"affine.yield"(%zerof): (f64) -> ()}) $cmpSet : ($ind) -> f64"""
            else s"""%new_sum_${v.cFormat(eqVar)} = "arith.addf"(%$finalV, %iter_sum_${v.cFormat(eqVar)}) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"affine.yield"(%new_sum_${v.cFormat(eqVar)}): (f64) -> ()\n}"""
          } else if (tensorComputation.head.vars.toSet.subsetOf(filteredVars.slice(i, filteredVars.length).toSet) && filteredVars.slice(i, filteredVars.length).toSet != tensorComputation.head.vars.toSet) {
            if (containsV) s""""affine.yield"(%${filteredVars(i - 1).cFormat(eqVar)}_sum): (f64) -> ()\n}, {"affine.yield"(%zerof): (f64) -> ()}) $cmpSet : ($ind) -> f64"""
            else s"""%new_sum_${v.cFormat(eqVar)} = "arith.addf"(%${filteredVars(i - 1).cFormat(eqVar)}_sum, %iter_sum_${v.cFormat(eqVar)}) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"affine.yield"(%new_sum_${v.cFormat(eqVar)}): (f64) -> ()\n}"""
          } else if (filteredVars.slice(i, filteredVars.length).toSet == tensorComputation.head.vars.toSet) {
            val (varsStr, sizeStr, indexStr) = tensorComputation.head.vars.foldLeft(("", "", ""))((acc2, v) => {
              val (varsStr, sizeStr, indexStr) = acc2
              val newVarStr = if (varsStr.length == 0) s"%${v.cFormat(eqVar)}" else s"$varsStr, %${v.cFormat(eqVar)}"
              val newSizeStr = s"${sizeStr}?x"
              val newIndexStr = if (indexStr.length == 0) s"index" else s"$indexStr, index"
              (newVarStr, newSizeStr, newIndexStr)
            })
            if (peqMode) {
              val peqVal = getVar("peqVal")
              val preVal = getVar("preVal")
              val preValCode = s"""%$preVal = ${tensorComputation.head.loadMLIR(eqVar)}"""
              val peqValCode = s"""%$peqVal = "arith.addf"(%${filteredVars(i - 1).cFormat(eqVar)}_sum, %$preVal) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"""
              s"""$preValCode${peqValCode}affine.store %$peqVal, %${tensorComputation.head.name}[$varsStr] : memref<${sizeStr}f64>\n"affine.yield"() : () -> ()\n}${if (containsV) s""", {"affine.yield"(): () -> ()}) $cmpSet : ($ind) -> ()""" else ""}"""
            } else s"""affine.store %${filteredVars(i - 1).cFormat(eqVar)}_sum, %${tensorComputation.head.name}[$varsStr] : memref<${sizeStr}f64>\n"affine.yield"() : () -> ()\n}${if (containsV) s""", {"affine.yield"(): () -> ()}) $cmpSet : ($ind) -> ()""" else ""}"""
          }
          else s""""affine.yield"() : () -> ()\n}${if (containsV) s""", {"affine.yield"(): () -> ()}) $cmpSet : ($ind) -> ()""" else ""}"""
          s"$acc\n$nc"
        }
      })
      
      s"$acc\n$nestedLoops\n$body\n$finalBrackets"
    })
  }

  def getFinalCodeGenPath(head: Access, finalRule: Rule, intervals: Seq[Map[Variable, Interval]], eqVarMap: Seq[Map[Variable, Index]]): Seq[(Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]])] = {
    if (intervals.length == 0 || getNoComparisonSoP(finalRule.body).prods.length == 0) return Seq((Rule(head, finalRule.body), intervals, eqVarMap))
    val tensorComputation: Seq[Prod] = getNoComparisonSoP(finalRule.body).prods
    val equalIntervalGroups: Seq[Set[Int]] = ((intervals zip eqVarMap).zipWithIndex).foldLeft(Seq.empty[Set[Int]])((acc, cur) => {
      val ((intervals1, eqVarMap1), i): ((Map[Variable, Interval], Map[Variable, Index]), Int) = cur
      val isIInASet = acc.foldLeft(false)((acc2, set) => acc2 || set.contains(i))
      if (!isIInASet) {
        acc :+ ((intervals zip eqVarMap).zipWithIndex.slice(i + 1, intervals.length)).foldLeft(Set(i))((acc2, cur2) => {
          val ((intervals2, eqVarMap2), j): ((Map[Variable, Interval], Map[Variable, Index]), Int) = cur2
          if (intervals1.toSeq.toSet == intervals2.toSeq.toSet && eqVarMap1.toSeq.toSet == eqVarMap2.toSeq.toSet) acc2 ++ Set(i, j)
          else acc2 
        })
      } else acc
    })
    equalIntervalGroups.foldLeft(Seq.empty[(Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]])])((acc, eqSet) => {
      val eqSeq = eqSet.toSeq
      val body: Seq[Prod] = eqSeq.foldLeft(Seq.empty[Prod])((acc2, index) => acc2 :+ tensorComputation(index))
      val rule: Rule = Rule(head, SoP(body))
      val interval: Map[Variable, Interval] = intervals(eqSeq(0))
      val eqMap: Map[Variable, Index] = eqVarMap(eqSeq(0))
      acc :+ (rule, Seq(interval), Seq(eqMap))
    })
  }

  def codeGen(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule], codeGenMode: Int = 0, peqMode: Boolean = true, variableReplacementFlag: Boolean = true, codeMotion: Boolean = true, dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map(), varReverse: Boolean = false, codeLang: String = "CPP", compressionMaps: Map[Exp, Rule] = Map()): String = {
    val variables: Seq[Variable] = if (varReverse) getVariables(tensorComputation).reverse else getVariables(tensorComputation)
    val compressionMap1: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = if (access.vars.length > 0) multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp)))))) else SoP(Seq(Prod(Seq(exp))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap
    val compressionMap: Map[Exp, Rule] = mergeMap(Seq(compressionMaps, compressionMap1))((v1, v2) => v1)
    val dataLayoutMapPrime: Map[Exp, Function[Seq[Variable], Seq[Index]]] = dataLayoutMap.map{case (k, v) => (k.asInstanceOf[Access].vars2RedundancyVars, v)}
    val dlMapFinal: Map[Exp, Function[Seq[Variable], Seq[Index]]] = mergeMap(Seq(dataLayoutMapPrime, dataLayoutMap))((v1, v2) => v2)
    val (outUS, outRM, outC, outDI) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMaps, compressionMap)
    val allDimVars: Seq[Variable] = dimInfo.toVarsMap.values.foldLeft(Seq.empty[Dim])((acc, dimSeq) => acc ++ dimSeq).foldLeft(Seq.empty[Variable])((acc, d) => acc ++ getVariables(d))
    
    val (comparisonsC, tensorComputationC): (SoP, SoP) = (getOnlyComparisonSoP(outC.body), getNoComparisonSoP(outC.body))
    val ruleCompC = Rule(outC.head, comparisonsC)
    val ruleTCC = Rule(outC.head, comparisonsC)
    
    val variableConditionMapUS: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, outUS)
    val variableConditionMapRM: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, outRM)
    val variableConditionMapC: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, ruleCompC)
    

    val (unifiedVariableConditionMapUS, _): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = unifyEqualVariableConditionMap(variables, variableConditionMapUS)
    val (unifiedVariableConditionMapRM, _): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = unifyEqualVariableConditionMap(variables, variableConditionMapRM)
    val (unifiedVariableConditionMapC, _): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = unifyEqualVariableConditionMap(variables, variableConditionMapC)

    val unifiedOutUS: Rule = Rule(outUS.head, getSoP(unifiedVariableConditionMapUS))
    val unifiedOutRM: Rule = Rule(outRM.head, getSoP(unifiedVariableConditionMapRM))
    val unifiedBodyC1: SoP = getSoP(unifiedVariableConditionMapC)
    val unifiedBodyC: SoP = SoP((unifiedBodyC1.prods zip tensorComputationC.prods).foldLeft(Seq.empty[Prod])((acc, prods) => {
      val (compProd, accessProd) = prods
      acc :+ prodTimesProd(compProd, accessProd)
    }))
    val unifiedOutC: Rule = Rule(outC.head, unifiedBodyC)

    val distinctOutUS: Rule = keepDistinct(unifiedOutUS)
    val distinctOutRM: Rule = keepDistinct(unifiedOutRM)
    val distinctOutC: Rule = keepDistinct(unifiedOutC)

    val simplifiedOutUS: Rule = simplify(distinctOutUS)
    val simplifiedOutRM: Rule = simplify(distinctOutRM)
    val simplifiedOutC: Rule = simplify(distinctOutC)

    val (comparisonsC2, tensorComputationC2): (SoP, SoP) = (getOnlyComparisonSoP(simplifiedOutC.body), getNoComparisonSoP(simplifiedOutC.body))
    val ruleCompC2 = Rule(outC.head, comparisonsC2)

    val distinctConditionMapUS: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, simplifiedOutUS)
    val distinctConditionMapRM: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, simplifiedOutRM)
    val distinctConditionMapC: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, ruleCompC2)

    val fixedConditionOrderUS: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, distinctConditionMapUS)
    val fixedConditionOrderRM: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, distinctConditionMapRM)
    val fixedConditionOrderC: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, distinctConditionMapC)

      val (fixedConditionOrderUS2, fixedConditionOrderRM2, fixedConditionOrderC2, eqVarMapUS, eqVarMapRM, eqVarMapC) = if (variableReplacementFlag) {
      val (removedNonLHSVarsUS, equalityVarMapUS): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Index]]) = removeNonLHSEQVars(tensorComputation.head.vars, fixedConditionOrderUS)
      val (removedNonLHSVarsRM, equalityVarMapRM): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Index]]) = removeNonLHSEQVars(tensorComputation.head.vars.redundancyVarsInplace, fixedConditionOrderRM)
      val (removedNonLHSVarsC, equalityVarMapC): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Index]]) = removeNonLHSEQVars(tensorComputation.head.vars, fixedConditionOrderC)

      val (_, eqRepsUS): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = unifyEqualVariableConditionMap(variables, fixedConditionOrderUS)
      val (_, eqRepsRM): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = unifyEqualVariableConditionMap(variables, fixedConditionOrderRM)
      val (_, eqRepsC): (Seq[Map[Variable, Seq[(String, Index)]]], Seq[Map[Variable, Variable]]) = unifyEqualVariableConditionMap(variables, fixedConditionOrderC)

      val eqVarMapUS: Seq[Map[Variable, Index]] = (eqRepsUS zip equalityVarMapUS).map{case(e1, e2) => mergeMap(Seq(e1, e2))((v1, v2) => v1)}
      val eqVarMapRM: Seq[Map[Variable, Index]] = (eqRepsRM zip equalityVarMapRM).map{case(e1, e2) => mergeMap(Seq(e1, e2))((v1, v2) => v1)}
      val eqVarMapC: Seq[Map[Variable, Index]] = (eqRepsC zip equalityVarMapC).map{case(e1, e2) => mergeMap(Seq(e1, e2))((v1, v2) => v1)}

      val fixedConditionOrderUS2: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, removedNonLHSVarsUS)
      val fixedConditionOrderRM2: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, removedNonLHSVarsRM)
      val fixedConditionOrderC2: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, removedNonLHSVarsC)
      (fixedConditionOrderUS2, fixedConditionOrderRM2, fixedConditionOrderC2, eqVarMapUS, eqVarMapRM, eqVarMapC)
    } else (fixedConditionOrderUS, fixedConditionOrderRM, fixedConditionOrderC, fixedConditionOrderUS.map(_ => Map.empty[Variable, Index]), fixedConditionOrderRM.map(_ => Map.empty[Variable, Index]), fixedConditionOrderC.map(_ => Map.empty[Variable, Index]))

    val intervalsUS: Seq[Map[Variable, Interval]] = getIntervals(variables, fixedConditionOrderUS2, eqVarMapUS)
    val intervalsRM: Seq[Map[Variable, Interval]] = getIntervals(variables, fixedConditionOrderRM2, eqVarMapRM)
    val intervalsC: Seq[Map[Variable, Interval]] = getIntervals(variables, fixedConditionOrderC2, eqVarMapC)

    val intervalsSimplifiedUS: Seq[Map[Variable, Interval]] = simplifyIntervals(intervalsUS)
    val intervalsSimplifiedRM: Seq[Map[Variable, Interval]] = simplifyIntervals(intervalsRM)
    val intervalsSimplifiedC: Seq[Map[Variable, Interval]] = simplifyIntervals(intervalsC)

    val finalUS: Rule = Rule(outUS.head, getSoPFromInterval(intervalsSimplifiedUS, eqVarMapUS))
    val finalRM: Rule = Rule(outRM.head, getSoPFromInterval(intervalsSimplifiedRM, eqVarMapRM))
    val finalBodyC1: SoP = getSoPFromInterval(intervalsSimplifiedC, eqVarMapC)
    val finalBodyC15: SoP = SoP((finalBodyC1.prods zip comparisonsC2.prods).foldLeft(Seq.empty[Prod])((acc, prod) => {
      val (fProd, compProd): (Prod, Prod) = prod
      val flag = compProd.exps.foldLeft(false)((acc2, e) => acc2 || e == trueComparison())
      if (flag) acc :+ Prod(fProd.exps ++ Seq(trueComparison))
      else acc :+ fProd
    }))
    val finalBodyC2: SoP = SoP((finalBodyC15.prods zip tensorComputationC2.prods).foldLeft(Seq.empty[Prod])((acc, prods) => {
      val (compProd, accessProd) = prods
      acc :+ prodTimesProd(compProd, accessProd)
    }))
    val finalBodyC: SoP = SoP(finalBodyC2.prods.foldLeft(Seq.empty[Prod])((acc, prod) => acc :+ Prod(prod.exps.filter(e => !e.isInstanceOf[Comparison] || e.asInstanceOf[Comparison] != trueComparison()))))
    val finalC: Rule = Rule(outC.head, finalBodyC)

    val pathC: Seq[(Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]])] = getFinalCodeGenPath(tensorComputation.head, finalC, intervalsSimplifiedC, eqVarMapC)
    val tensorComputationRC = Rule(tensorComputation.head, SoP(Seq(Prod(Seq(tensorComputation.head.vars2RedundancyVars)))))
    

    // println("variables:")
    // println(variables)
    println("==================")
    println("Tensor Computation")
    pprint(tensorComputation)
    println("==================")
    println("outUS")
    pprint(outUS)
    println("------------------")
    println("outRM")
    pprint(outRM)
    println("------------------")
    println("outC")
    pprint(outC)
    // println("------------------")
    // println("outDI")
    // println(dimInfo :+ outDI)
    println("==================")
    // println("variableConditionMapUS")
    // println(variableConditionMapUS)
    // println("------------------")
    // println("variableConditionMapRM")
    // println(variableConditionMapRM)
    // println("------------------")
    println("variableConditionMapC")
    println(variableConditionMapC)
    println("==================")
    // println("unifiedVariableConditionMapUS")
    // println(unifiedVariableConditionMapUS)
    // println("------------------")
    // println("unifiedVariableConditionMapRM")
    // println(unifiedVariableConditionMapRM)
    // println("------------------")
    println("unifiedVariableConditionMapC")
    println(unifiedVariableConditionMapC)
    println("==================")
    // println("unifiedOutUS")
    // pprint(unifiedOutUS)
    // println("------------------")
    // println("unifiedOutRM")
    // pprint(unifiedOutRM)
    // println("------------------")
    println("unifiedOutC")
    pprint(unifiedOutC)
    println("==================")
    // println("distinctOutUS")
    // pprint(distinctOutUS)
    // println("------------------")
    // println("distinctOutRM")
    // pprint(distinctOutRM)
    // println("------------------")
    println("distinctOutC")
    pprint(distinctOutC)
    println("==================")
    println("simplifiedOutUS")
    pprint(simplifiedOutUS)
    println("------------------")
    println("simplifiedOutRM")
    pprint(simplifiedOutRM)
    println("------------------")
    println("simplifiedOutC")
    pprint(simplifiedOutC)
    println("==================")
    // println("distinctConditionMapUS")
    // println(distinctConditionMapUS)
    // println("------------------")
    // println("distinctConditionMapRM")
    // println(distinctConditionMapRM)
    // println("------------------")
    println("distinctConditionMapC")
    println(distinctConditionMapC)
    println("==================")
    // println("fixedConditionOrderUS")
    // println(fixedConditionOrderUS)
    // println("------------------")
    // println("fixedConditionOrderRM")
    // println(fixedConditionOrderRM)
    // println("------------------")
    println("fixedConditionOrderC")
    println(fixedConditionOrderC)
    println("==================")
    // println("removedNonLHSVarsUS")
    // println(removedNonLHSVarsUS)
    // println("------------------")
    // println("removedNonLHSVarsRM")
    // println(removedNonLHSVarsRM)
    // println("------------------")
    // println("removedNonLHSVarsC")
    // println(removedNonLHSVarsC)
    // println("==================")
    // println("eqVarMapUS")
    // println(eqVarMapUS)
    // println("------------------")
    // println("eqVarMapRM")
    // println(eqVarMapRM)
    // println("------------------")
    println("eqVarMapC")
    println(eqVarMapC)
    println("==================")
    // println("intervalsUS")
    // println(intervalsUS)
    // println("------------------")
    // println("intervalsRM")
    // println(intervalsRM)
    // println("------------------")
    println("intervalsC")
    println(intervalsC)
    println("==================")
    // println("intervalsSimplifiedUS")
    // println(intervalsSimplifiedUS)
    // println("------------------")
    // println("intervalsSimplifiedRM")
    // println(intervalsSimplifiedRM)
    // println("------------------")
    println("intervalsSimplifiedC")
    println(intervalsSimplifiedC)
    println("==================")
    // println("finalUS")
    // pprint(finalUS)
    // println("------------------")
    // println("finalRM")
    // pprint(finalRM)
    // println("------------------")
    println("finalC")
    pprint(finalC)
    println("==================")
    println("PathC")
    pathC.foldLeft()((acc, cur) => {
      val (tensorComputationC, intervalC, eqMapC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
      println("********************")
      println("Tensor Computation")
      pprint(tensorComputationC)
      println("Interval")
      println(intervalC(0))
      println("Equality Var Map")
      println(eqMapC(0))
      println("********************")
    })
    // println("------------------")
    // println("PathRC")
    // pathRC.foldLeft()((acc, cur) => {
    //   val (tensorComputationRC, intervalRC, eqMapRC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
    //   println("********************")
    //   println("Tensor Computation")
    //   pprint(tensorComputationRC)
    //   println("Interval")
    //   println(intervalRC(0))
    //   println("Equality Var Map")
    //   println(eqMapRC(0))
    //   println("********************")
    // })
    println("==================")

    if (codeLang == "MLIR") {
      if (codeGenMode == 0) "void compute() {\n" + codeGenRuleMLIR(tensorComputation, dimInfo :+ outDI, variables, intervalsSimplifiedUS, eqVarMapUS, UniqueSet, peqMode, codeMotion, dataLayoutMap) + "\n}\n\n\nvoid reconstruct() {\n" + codeGenRuleMLIR(tensorComputation, dimInfo :+ outDI, variables, intervalsSimplifiedRM, eqVarMapRM, RedundancyMap, peqMode, codeMotion, dataLayoutMap) + "\n}\n"
      else if (codeGenMode == 1) codeGenRuleMLIR(tensorComputation, dimInfo :+ outDI, variables, intervalsSimplifiedUS, eqVarMapUS, UniqueSet, peqMode, codeMotion, dataLayoutMap)
      else if (codeGenMode == 2) codeGenRuleMLIR(tensorComputation, dimInfo :+ outDI, variables, intervalsSimplifiedRM, eqVarMapRM, RedundancyMap, peqMode, codeMotion, dataLayoutMap)
      else ""
    } else {
      val computation: String = pathC.foldLeft(("", false))((acc, cur) => {
        val (tensorComputationC, intervalC, eqMapC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
        val peqC: Boolean = peqMode | acc._2
        val res: String = codeGenRule(tensorComputationC, dimInfo :+ outDI, variables, intervalC, eqMapC, UniqueSet, peqC, codeMotion, dlMapFinal)
        (acc._1 + "\n" + res, true)
      })._1
      // val reconstruction: String = pathRC.foldLeft(("", false))((acc, cur) => {
      //   val (tensorComputationRC, intervalRC, eqMapRC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
      //   val peqRC: Boolean = peqMode | acc._2
      //   val res: String = codeGenRule(tensorComputationRC, dimInfo :+ outDI, variables, intervalRC, eqMapRC, UniqueSet, peqRC, codeMotion, dataLayoutMap)
      //   (acc._1 + "\n" + res, true)
      // })._1
      val reconstruction: String = codeGenRule(tensorComputationRC, dimInfo :+ outDI, variables.redundancyVarsInplace, intervalsSimplifiedRM, eqVarMapRM, UniqueSet, false, codeMotion, dlMapFinal)
      if (codeGenMode == 0) "void compute() {\n" + computation + "\n}\n\n\nvoid reconstruct() {\n" + reconstruction + "\n}\n"
      else if (codeGenMode == 1) computation
      else if (codeGenMode == 2) reconstruction
      else ""
    }
  }

  def getAllVariables(sop: SoP): Seq[Variable] = sop.prods.foldLeft(Seq.empty[Variable])((acc, prod) => acc ++ prod.exps.foldLeft(Seq.empty[Variable])((acc2, exp) => acc2 ++ getAllVariables(exp)))

  def replaceVars(access: Access, varMap: Map[Variable, Variable]): Access = {
    val newVars: Seq[Variable] = access.vars.map(v => varMap.getOrElse(v, v))
    Access(access.name, newVars, access.kind)
  }

  def replaceVars(comp: Comparison, varMap: Map[Variable, Variable]): Comparison = {
    val newIndex: Index = replaceVars(comp.index, varMap)
    val newVar: Variable = varMap.getOrElse(comp.variable, comp.variable)
    Comparison(comp.op, newIndex, newVar)
  }

  def replaceVars(exp: Exp, varMap: Map[Variable, Variable]): Exp = {
    exp match {
      case Access(_, _, _) => replaceVars(exp.asInstanceOf[Access], varMap)
      case Comparison(_, _, _) => replaceVars(exp.asInstanceOf[Comparison], varMap)
      case _ => exp
    }
  }

  def replaceVars(sop: SoP, varMap: Map[Variable, Variable]): SoP = {
    val prodSeq: Seq[Prod] = sop.prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      val expSeq: Seq[Exp] = prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => {
        val newExp: Exp = replaceVars(exp, varMap)
        acc2 :+ newExp
      })
      acc :+ Prod(expSeq)
    })
    SoP(prodSeq)
  }


  def replaceVars(rule: Rule, varMap: Map[Variable, Variable]): Rule = Rule(replaceVars(rule.head, varMap), replaceVars(rule.body, varMap))

  def replaceVars(dim: DimInfo, varMap: Map[Variable, Variable]): DimInfo = {
    val newVars: Seq[Variable] = dim.access.vars.map(v => varMap.getOrElse(v, v))
    val access: Access = Access(dim.access.name, newVars, dim.access.kind)
    DimInfo(access, dim.dims)
  }

  def inlineProgram(tensorProgram: Seq[Rule], dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule], index: Int = 0): (Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule]) = {
    if (tensorProgram.length == 0) return (Seq.empty[Rule], dimInfo, uniqueSets, redundancyMaps)
    if (index == tensorProgram.length - 1) return (tensorProgram, dimInfo, uniqueSets, redundancyMaps)
    val first: Rule = tensorProgram(index)
    val (firstHead, firstBody): (Access, SoP) = (first.head, first.body)
    val bodyHeadVarDiff: Seq[Variable] = getAllVariables(firstBody).toSet.diff(firstHead.vars.toSet).toSeq
    val head: Seq[Rule] = tensorProgram.slice(0, index)
    val tail: Seq[Rule] = tensorProgram.slice(index + 1, tensorProgram.length)
    
    val (replaced, newDimInfo, newUS, newRM, flag): (Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], Boolean) = tail.foldLeft((Seq.empty[Rule], dimInfo, uniqueSets, redundancyMaps, false))((acc, rule) => {
      val (head, body): (Access, SoP) = (rule.head, rule.body)
      val (newBody, newDimInfo, newUS, newRM, flag): (SoP, Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], Boolean) = body.prods.foldLeft((emptySoP, dimInfo, uniqueSets, redundancyMaps, false))((acc2, prod) => {
        val (newSoP, newDimInfo, newUS, newRM, flag): (SoP, Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], Boolean) = prod.exps.foldLeft((emptySoP, dimInfo, uniqueSets, redundancyMaps, false))((acc3, exp) => {
          val (newSoP, newDimInfo, newUS, newRM, flag): (SoP, Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], Boolean) = if (exp.isInstanceOf[Access] && exp.asInstanceOf[Access] == firstHead) {
            if (bodyHeadVarDiff.length == 0) (firstBody, Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], true)
            else {
              val varMap: Map[Variable, Variable] = bodyHeadVarDiff.map(v => (v -> getVar(v.name).toVar)).toMap
              val dim: Seq[DimInfo] = acc3._2.map(d => replaceVars(d, varMap))
              val newUS: Map[Exp, Rule] = acc3._3.map{case (e, r) => (replaceVars(e, varMap) -> replaceVars(r, varMap))}
              val newRM: Map[Exp, Rule] = acc3._4.map{case (e, r) => (replaceVars(e, varMap) -> replaceVars(r, varMap))}
              (replaceVars(firstBody, varMap), dim, newUS, newRM, true)
            }
          } else (SoP(Seq(Prod(Seq(exp)))), Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], false)
          val sop = if (acc3._1 == emptySoP) newSoP else SoPTimesSoP(acc3._1, newSoP)
          val di: Seq[DimInfo] = acc3._2 ++ newDimInfo
          val us: Map[Exp, Rule] = mergeMap(Seq(acc3._3, newUS))((v1, v2) => v2)
          val rm: Map[Exp, Rule] = mergeMap(Seq(acc3._4, newRM))((v1, v2) => v2)
          val fl: Boolean = acc3._5 || flag
          (sop, di, us, rm, fl)
        })
        val sop = if (acc2._1 == emptySoP) newSoP else SoPTimesSoP(acc2._1, newSoP)
        val di: Seq[DimInfo] = acc2._2 ++ newDimInfo
        val us: Map[Exp, Rule] = mergeMap(Seq(acc2._3, newUS))((v1, v2) => v2)
        val rm: Map[Exp, Rule] = mergeMap(Seq(acc2._4, newRM))((v1, v2) => v2)
        val fl: Boolean = acc2._5 || flag
        (sop, di, us, rm, fl)
      })
      val sop = acc._1 :+ Rule(head, newBody)
      val di: Seq[DimInfo] = acc._2 ++ newDimInfo
      val us: Map[Exp, Rule] = mergeMap(Seq(acc._3, newUS))((v1, v2) => v2)
      val rm: Map[Exp, Rule] = mergeMap(Seq(acc._4, newRM))((v1, v2) => v2)
      val fl: Boolean = acc._5 || flag
      (sop, di, us, rm, fl)
    })

    val (newTP, newIndex): (Seq[Rule], Int) = if(flag) (head ++ replaced, index) else (tensorProgram, index + 1)
    return inlineProgram(newTP, newDimInfo, newUS, newRM, newIndex)
  }

  def codeGenProgram(tensorProgram: Seq[Rule], dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule]): String = {
    val (inline, newDimInfo, newUS, newRM): (Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule]) = inlineProgram(tensorProgram, dimInfo, uniqueSets, redundancyMaps)
    println("inline", inline(0).prettyFormat)
    inline.foldLeft("")((acc, tc) => {
      val code = codeGen(tc, newDimInfo, newUS, newRM)
      s"$acc\n$code"
    })
  }

  // // Binary multiplication for 2 tensors check -- worked
  // def test1(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
  //   val var1BodyUS: SoP = multSoP(Seq(SoP(Seq(var1ProdsUS)), dim1.toSoP))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
  //   val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
  //   val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
  //   val var2BodyUS: SoP = multSoP(Seq(SoP(Seq(var2ProdsUS)), dim2.toSoP))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
  //   val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(SoP(Seq(var2ProdsRM)), dim2.toSoP))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Binary addition for 2 tensors check -- worked
  // def test2(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val prod1: Prod = Prod(Seq(var1))
  //   val prod2: Prod = Prod(Seq(var2))
  //   val body: SoP = SoP(Seq(prod1, prod2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
  //   val var1BodyUS: SoP = multSoP(Seq(SoP(Seq(var1ProdsUS)), dim1.toSoP))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
  //   val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
  //   val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
  //   val var2BodyUS: SoP = multSoP(Seq(SoP(Seq(var2ProdsUS)), dim2.toSoP))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
  //   val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(SoP(Seq(var2ProdsRM)), dim2.toSoP))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Self-outer product check -- worked
  // def test3(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x")), Tensor)
  //   val var2: Access = Access("A",  Seq(Variable("y")), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // DTTV check: worked
  // def test4(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
  //   val in2SeqVar = Seq("k".toVar)
  //   val outName = "A"
  //   val in1Name = "M"
  //   val in2Name = "N"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar, "m".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
  //   val var1ExpUS2: Exp = Comparison("=", "j".toVar, "k".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
  //   val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // RMD check: worked -- page 12: M_U should be 0 <= k < n (not j instead of k!!!) also in simplifications should be fixed too!
  // def test5(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar, "k".toVar)
  //   val in2SeqVar = Seq("k".toVar, "j".toVar)
  //   val outName = "A"
  //   val in1Name = "M"
  //   val in2Name = "N"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "i".toVar, "r".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "k".toVar, "j".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // UHS check: worked
  // def test6(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar)
  //   val in2SeqVar = Seq("i".toVar, "j".toVar)
  //   val outName = "A"
  //   val in1Name = "M"
  //   val in2Name = "N"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", "j".toVar, "i".toVar)
  //   val var2ExpRM2: Exp = Comparison("=", "j".redundancyVars, "i".toVar)
  //   val var2ExpRM3: Exp = Comparison("=", "i".redundancyVars, "j".toVar)
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = SoP(Seq(var2ProdsRM))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Example - Structure Inference checked: worked
  // def test7(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("x1".toVar, "x2".toVar, "x3".toVar, "x4".toVar, "x5".toVar)
  //   val in1SeqVar = Seq("x1".toVar, "x2".toVar, "x3".toVar)
  //   val in2SeqVar = Seq("x4".toVar, "x5".toVar)
  //   val outName = "T"
  //   val in1Name = "M"
  //   val in2Name = "V"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("d1".toVar, "d2".toVar, "d3".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("d4".toVar, "d5".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison(">", "x1".toVar, "x2".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("<=", "x4".toVar, "x5".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison(">", "x4".toVar, "x5".toVar)
  //   val var2ExpRM2: Exp = Comparison("=", "x4".redundancyVars, "x5".toVar)
  //   val var2ExpRM3: Exp = Comparison("=", "x5".redundancyVars, "x4".toVar)
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsRM))))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-binary: Example - Unique set computation: worked
  // def test8(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar, "l".toVar)
  //   val in2SeqVar = Seq("i".toVar, "k".toVar)
  //   val in3SeqVar = Seq("j".toVar, "k".toVar)
  //   val in4SeqVar = Seq("i".toVar, "j".toVar)
  //   val outName = "A"
  //   val inter1Name = "F"
  //   val inter2Name = "G"
  //   val in1Name = "B"
  //   val in2Name = "C"
  //   val in3Name = "D"
  //   val in4Name = "E"

  //   val head1: Access = Access(inter1Name, outSeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, outSeqVar, Tensor)
  //   val head3: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Access = Access(in3Name, in3SeqVar, Tensor)
  //   val var4: Access = Access(in4Name, in4SeqVar, Tensor)
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val prods2: Prod = Prod(Seq(var3, var4))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(Prod(Seq(head1)), Prod(Seq(head2))))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar, "n".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar, "n".toVar))
  //   val dimH1: DimInfo = DimInfo(head1, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dimH2: DimInfo = DimInfo(head2, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dimH1, dimH2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "l".toVar, "k".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
  //   val var3BodyUS: SoP = emptySoP()
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
  //   val var4ExpUS1: Exp = Comparison("<=", "i".toVar, "k".toVar)
  //   val var4ProdsUS: Prod = Prod(Seq(var4ExpUS1))
  //   val var4BodyUS: SoP = SoP(Seq(var4ProdsUS))
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))

  //   pprintTest((tensorComputation1, infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)))
  //   pprintTest((tensorComputation2, infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)))

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo ++ Seq(infer1._3, infer2._3)

  //   println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))

  //   (tensorComputation3, infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  // }

  // // Normalised: Example - Unique set computation: worked
  // def test8n(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar, "l".toVar)
  //   val in2SeqVar = Seq("i".toVar, "k".toVar)
  //   val in3SeqVar = Seq("j".toVar, "k".toVar)
  //   val in4SeqVar = Seq("i".toVar, "j".toVar)
  //   val outName = "A"
  //   val in1Name = "B"
  //   val in2Name = "C"
  //   val in3Name = "D"
  //   val in4Name = "E"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Access = Access(in3Name, in3SeqVar, Tensor)
  //   val var4: Access = Access(in4Name, in4SeqVar, Tensor)
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val prods2: Prod = Prod(Seq(var3, var4))
  //   val body: SoP = SoP(Seq(prods1, prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar, "n".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "l".toVar, "k".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
  //   val var3BodyUS: SoP = emptySoP()
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
  //   val var4ExpUS1: Exp = Comparison("<=", "i".toVar, "k".toVar)
  //   val var4ProdsUS: Prod = Prod(Seq(var4ExpUS1))
  //   val var4BodyUS: SoP = multSoP(Seq(dim4.toSoP, SoP(Seq(var4ProdsUS))))
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-binary: Example - Normal Kronecker Product
  // def test9(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val inter1Name = "C"
  //   val inter2Name = "D"
  //   val inter3Name = "E"
  //   val inter4Name = "F"
  //   val inter5Name = "G"
  //   val inter6Name = "H"
  //   val inter7Name = "I"
  //   val inter8Name = "J"
  //   val inter9Name = "K"
  //   val inter10Name = "L"
  //   val inter11Name = "M"
  //   val inter12Name = "N"
  //   val in1Name = "A"
  //   val in2Name = "B"

  //   val head1: Access = Access(inter1Name, in1SeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, in2SeqVar, Tensor)
  //   val head3: Access = Access(inter3Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head4: Access = Access(inter4Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head5: Access = Access(inter5Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head6: Access = Access(inter6Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head7: Access = Access(inter7Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head8: Access = Access(inter8Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head9: Access = Access(inter9Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head10: Access = Access(inter10Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head11: Access = Access(inter11Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head12: Access = Access(inter12Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "x".toVar, "m".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "y".toVar, "n".toVar), "j".toVar)
    
  //   val prods1: Prod = Prod(Seq(var1, var7))
  //   val prods2: Prod = Prod(Seq(var2, var7))
  //   val prods3: Prod = Prod(Seq(head1, var9))
  //   val prods4: Prod = Prod(Seq(head2, var9))
  //   val prods5: Prod = Prod(Seq(head3, var3))
  //   val prods6: Prod = Prod(Seq(head4, var5))
  //   val prods7: Prod = Prod(Seq(head5, var8))
  //   val prods8: Prod = Prod(Seq(head6, var8))
  //   val prods9: Prod = Prod(Seq(head7, var10))
  //   val prods10: Prod = Prod(Seq(head8, var10))
  //   val prods11: Prod = Prod(Seq(head9, var4))
  //   val prods12: Prod = Prod(Seq(head10, var6))
  //   val prods: Prod = Prod(Seq(head11, head12))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(prods3))
  //   val body4: SoP = SoP(Seq(prods4))
  //   val body5: SoP = SoP(Seq(prods5))
  //   val body6: SoP = SoP(Seq(prods6))
  //   val body7: SoP = SoP(Seq(prods7))
  //   val body8: SoP = SoP(Seq(prods8))
  //   val body9: SoP = SoP(Seq(prods9))
  //   val body10: SoP = SoP(Seq(prods10))
  //   val body11: SoP = SoP(Seq(prods11))
  //   val body12: SoP = SoP(Seq(prods12))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)
  //   val tensorComputation4: Rule = Rule(head4, body4)
  //   val tensorComputation5: Rule = Rule(head5, body5)
  //   val tensorComputation6: Rule = Rule(head6, body6)
  //   val tensorComputation7: Rule = Rule(head7, body7)
  //   val tensorComputation8: Rule = Rule(head8, body8)
  //   val tensorComputation9: Rule = Rule(head9, body9)
  //   val tensorComputation10: Rule = Rule(head10, body10)
  //   val tensorComputation11: Rule = Rule(head11, body11)
  //   val tensorComputation12: Rule = Rule(head12, body12)
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("x".toVar, "y".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo ++ Seq(infer1._3, infer2._3)

  //   val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap)
  //   val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap)

  //   val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)
  //   val newDimInfo2: Seq[DimInfo] = newDimInfo ++ Seq(infer3._3, infer4._3)

  //   val infer5: (Rule, Rule, DimInfo) = infer(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2)
  //   val infer6: (Rule, Rule, DimInfo) = infer(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2)

  //   val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
  //   val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)
  //   val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++ Seq(infer5._3, infer6._3)

  //   val infer7: (Rule, Rule, DimInfo) = infer(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3)
  //   val infer8: (Rule, Rule, DimInfo) = infer(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3)

  //   val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
  //   val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)
  //   val newDimInfo4: Seq[DimInfo] = newDimInfo3 ++ Seq(infer7._3, infer8._3)

  //   val infer9: (Rule, Rule, DimInfo) = infer(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4)
  //   val infer10: (Rule, Rule, DimInfo) = infer(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4)

  //   val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
  //   val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)
  //   val newDimInfo5: Seq[DimInfo] = newDimInfo4 ++ Seq(infer9._3, infer10._3)

  //   val infer11: (Rule, Rule, DimInfo) = infer(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5)
  //   val infer12: (Rule, Rule, DimInfo) = infer(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5)

  //   val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
  //   val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)
  //   val newDimInfo6: Seq[DimInfo] = newDimInfo5 ++ Seq(infer11._3, infer12._3)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5))
  //   println(codeGen(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5))

  //   println(codeGen(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))

  //   pprintTest((tensorComputation1, infer1))
  //   pprintTest((tensorComputation2, infer2))
  //   pprintTest((tensorComputation3, infer3))
  //   pprintTest((tensorComputation4, infer4))
  //   pprintTest((tensorComputation5, infer5))
  //   pprintTest((tensorComputation6, infer6))
  //   pprintTest((tensorComputation7, infer7))
  //   pprintTest((tensorComputation8, infer8))
  //   pprintTest((tensorComputation9, infer9))
  //   pprintTest((tensorComputation10, infer10))
  //   pprintTest((tensorComputation11, infer11))
  //   pprintTest((tensorComputation12, infer12))

  //   (tensorComputation, infer(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))
  // }

  // // Normalised: Example - Normal Kronecker Product
  // def test9n(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val in1Name = "A"
  //   val in2Name = "B"
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "x".toVar, "m".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "y".toVar, "n".toVar), "j".toVar)
    
  //   val prods: Prod = Prod(Seq(var1, var7, var9, var3, var8, var10, var4, var2, var7, var9, var5, var8, var10, var6))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("x".toVar, "y".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    
  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-binary: Polynomial Regression Degree 2 -- It's a confusing mess, will check it after all simplifications
  // def test10(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val inSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar)
  //   val in2SeqVar = Seq("j".toVar)
  //   val outSeqVar = Seq("p".toVar, "q".toVar)
  //   val interSeqVar1 = Seq("k".toVar)
  //   val interSeqVar2 = Seq("p".toVar)
  //   val interSeqVar3 = Seq("q".toVar)
  //   val outName = "S"
  //   val inter1Name = "A"
  //   val inter2Name = "B"
  //   val inter3Name = "C"
  //   val inter4Name = "D"
  //   val in1Name = "f"
  //   val in2Name = "f"
  //   val in3Name = "f"
  //   val in4Name = "f"
  //   val in5Name = "f"
  //   val in6Name = "f"
  //   val in7Name = "f"

  //   val head1: Access = Access(inter1Name, inSeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, interSeqVar1, Tensor)
  //   val head3: Access = Access(inter3Name, interSeqVar2, Tensor)
  //   val head4: Access = Access(inter4Name, interSeqVar3, Tensor)
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in1Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("+", Arithmetic("*", "i".toVar, "n".toVar), "j".toVar), "k".toVar)
  //   val var4: Access = Access(in1Name, interSeqVar2, Tensor)
  //   val var5: Comparison = Comparison("=", Arithmetic("-", "p".toVar, "n".toVar), "k".toVar)
  //   val var6: Access = Access(in1Name, interSeqVar3, Tensor)
  //   val var7: Comparison = Comparison("=", Arithmetic("-", "q".toVar, "n".toVar), "k".toVar)
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val prods2: Prod = Prod(Seq(head1, var3))
  //   val prods3: Prod = Prod(Seq(head2, var5))
  //   val prods4: Prod = Prod(Seq(head2, var7))
  //   val prods: Prod = Prod(Seq(head3, head4))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(Prod(Seq(var4)), prods3))
  //   val body4: SoP = SoP(Seq(Prod(Seq(var6)), prods4))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)
  //   val tensorComputation4: Rule = Rule(head4, body4)
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dim3: DimInfo = DimInfo(var4, Seq("n".toVar))
  //   val dim4: DimInfo = DimInfo(var6, Seq("n".toVar))
  //   // val dimH1: DimInfo = DimInfo(head1, Seq("n".toVar, "n".toVar, "n".toVar)) n times n?
  //   val dimH2: DimInfo = DimInfo(head2, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dimH2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1BodyUS: SoP = emptySoP()
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   // since all of them are empty so it doesn't matter
  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

  //   pprintTest((tensorComputation1, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)))
    
  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo :+ infer1._3
    
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, newDimInfo, newUniqueSets, newRedundancyMap)

  //   println(codeGen(tensorComputation2, newDimInfo, newUniqueSets, newRedundancyMap))

  //   pprintTest((tensorComputation2, infer(tensorComputation, newDimInfo, newUniqueSets, newRedundancyMap)))

  //   val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._1), newUniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._2), newRedundancyMap))((v1, v2) => v2)
  //   val newDimInfo2: Seq[DimInfo] = newDimInfo :+ infer2._3

  //   val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo2, newUniqueSets2, newRedundancyMap2)
  //   val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo2, newUniqueSets2, newRedundancyMap2)

  //   println(codeGen(tensorComputation3, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation4, newDimInfo2, newUniqueSets2, newRedundancyMap2))

  //   pprintTest((tensorComputation3, infer(tensorComputation, newDimInfo2, newUniqueSets2, newRedundancyMap2)))
  //   pprintTest((tensorComputation4, infer(tensorComputation, newDimInfo2, newUniqueSets2, newRedundancyMap2)))

  //   val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets2))((v1, v2) => v2)
  //   val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap2))((v1, v2) => v2)
  //   val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++ Seq(infer3._3, infer4._3)

  //   println(codeGen(tensorComputation, newDimInfo3, newUniqueSets3, newRedundancyMap3))

  //   (tensorComputation, infer(tensorComputation, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  // }

  // // Self-outer product 3 check: worked -- need to be checked inside covariance matrices to make sure -- manually checked
  // def test11(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar, "y".toVar, "z".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("A",  Seq("y".toVar), Tensor)
  //   val var3: Access = Access("A",  Seq("z".toVar), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2, var3))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("A".uniqueName,  Seq(Variable("z")), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access("A".redundancyName,  Seq(Variable("z"), Variable("z").redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Self-outer product 4 check: worked  -- need to be checked inside covariance matrices to make sure -- manually checked
  // def test12(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar, "y".toVar, "z".toVar, "p".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("A",  Seq("y".toVar), Tensor)
  //   val var3: Access = Access("A",  Seq("z".toVar), Tensor)
  //   val var4: Access = Access("A",  Seq("p".toVar), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2, var3, var4))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("A".uniqueName,  Seq(Variable("z")), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access("A".redundancyName,  Seq(Variable("z"), Variable("z").redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access("A".uniqueName,  Seq(Variable("p")), UniqueSet)
  //   val var4BodyUS: SoP = dim4.toSoP
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access("A".redundancyName,  Seq(Variable("p"), Variable("p").redundancyVars), RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-Binary Example: Diagonal Kronecker Product
  // def test13(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val inter1Name = "C"
  //   val inter2Name = "D"
  //   val inter3Name = "E"
  //   val inter4Name = "F"
  //   val inter5Name = "G"
  //   val inter6Name = "H"
  //   val inter7Name = "I"
  //   val inter8Name = "J"
  //   val inter9Name = "K"
  //   val inter10Name = "L"
  //   val inter11Name = "M"
  //   val inter12Name = "N"
  //   val in1Name = "A"
  //   val in2Name = "B"

  //   val head1: Access = Access(inter1Name, in1SeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, in2SeqVar, Tensor)
  //   val head3: Access = Access(inter3Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head4: Access = Access(inter4Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head5: Access = Access(inter5Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head6: Access = Access(inter6Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head7: Access = Access(inter7Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head8: Access = Access(inter8Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head9: Access = Access(inter9Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head10: Access = Access(inter10Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head11: Access = Access(inter11Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head12: Access = Access(inter12Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "n".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "n".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "j".toVar)
    
  //   val prods1: Prod = Prod(Seq(var1, var7))
  //   val prods2: Prod = Prod(Seq(var2, var7))
  //   val prods3: Prod = Prod(Seq(head1, var9))
  //   val prods4: Prod = Prod(Seq(head2, var9))
  //   val prods5: Prod = Prod(Seq(head3, var3))
  //   val prods6: Prod = Prod(Seq(head4, var5))
  //   val prods7: Prod = Prod(Seq(head5, var8))
  //   val prods8: Prod = Prod(Seq(head6, var8))
  //   val prods9: Prod = Prod(Seq(head7, var10))
  //   val prods10: Prod = Prod(Seq(head8, var10))
  //   val prods11: Prod = Prod(Seq(head9, var4))
  //   val prods12: Prod = Prod(Seq(head10, var6))
  //   val prods: Prod = Prod(Seq(head11, head12))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(prods3))
  //   val body4: SoP = SoP(Seq(prods4))
  //   val body5: SoP = SoP(Seq(prods5))
  //   val body6: SoP = SoP(Seq(prods6))
  //   val body7: SoP = SoP(Seq(prods7))
  //   val body8: SoP = SoP(Seq(prods8))
  //   val body9: SoP = SoP(Seq(prods9))
  //   val body10: SoP = SoP(Seq(prods10))
  //   val body11: SoP = SoP(Seq(prods11))
  //   val body12: SoP = SoP(Seq(prods12))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)
  //   val tensorComputation4: Rule = Rule(head4, body4)
  //   val tensorComputation5: Rule = Rule(head5, body5)
  //   val tensorComputation6: Rule = Rule(head6, body6)
  //   val tensorComputation7: Rule = Rule(head7, body7)
  //   val tensorComputation8: Rule = Rule(head8, body8)
  //   val tensorComputation9: Rule = Rule(head9, body9)
  //   val tensorComputation10: Rule = Rule(head10, body10)
  //   val tensorComputation11: Rule = Rule(head11, body11)
  //   val tensorComputation12: Rule = Rule(head12, body12)
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "p".toVar, "q".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "r".toVar, "s".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo ++  Seq(infer1._3, infer2._3)

  //   val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap)
  //   val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap)

  //   val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)
  //   val newDimInfo2: Seq[DimInfo] = newDimInfo ++  Seq(infer3._3, infer4._3)

  //   val infer5: (Rule, Rule, DimInfo) = infer(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2)
  //   val infer6: (Rule, Rule, DimInfo) = infer(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2)

  //   val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
  //   val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)
  //   val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++  Seq(infer5._3, infer6._3)

  //   val infer7: (Rule, Rule, DimInfo) = infer(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3)
  //   val infer8: (Rule, Rule, DimInfo) = infer(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3)

  //   val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
  //   val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)
  //   val newDimInfo4: Seq[DimInfo] = newDimInfo3 ++  Seq(infer7._3, infer8._3)

  //   val infer9: (Rule, Rule, DimInfo) = infer(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4)
  //   val infer10: (Rule, Rule, DimInfo) = infer(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4)

  //   val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
  //   val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)
  //   val newDimInfo5: Seq[DimInfo] = newDimInfo4 ++  Seq(infer9._3, infer10._3)

  //   val infer11: (Rule, Rule, DimInfo) = infer(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5)
  //   val infer12: (Rule, Rule, DimInfo) = infer(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5)

  //   val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
  //   val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)
  //   val newDimInfo6: Seq[DimInfo] = newDimInfo5 ++  Seq(infer11._3, infer12._3)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5))
  //   println(codeGen(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5))

  //   println(codeGen(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))

  //   pprintTest((tensorComputation1, infer1))
  //   pprintTest((tensorComputation2, infer2))
  //   pprintTest((tensorComputation3, infer3))
  //   pprintTest((tensorComputation4, infer4))
  //   pprintTest((tensorComputation5, infer5))
  //   pprintTest((tensorComputation6, infer6))
  //   pprintTest((tensorComputation7, infer7))
  //   pprintTest((tensorComputation8, infer8))
  //   pprintTest((tensorComputation9, infer9))
  //   pprintTest((tensorComputation10, infer10))
  //   pprintTest((tensorComputation11, infer11))
  //   pprintTest((tensorComputation12, infer12))

  //   (tensorComputation, infer(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))
  // }

  // // Normalised: Example - Normal Kronecker Product
  // def test13n(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val in1Name = "A"
  //   val in2Name = "B"
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "n".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "n".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "j".toVar)
    
  //   val prods: Prod = Prod(Seq(var1, var7, var9, var3, var8, var10, var4, var2, var7, var9, var5, var8, var10, var6))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "p".toVar, "q".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "r".toVar, "s".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    
  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Vector direct sum - checked
  // def test14(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y".toVar), Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("-", "x".toVar, "n".toVar), "y".toVar)
  //   val prods1: Prod = Prod(Seq(var1))
  //   val prods2: Prod = Prod(Seq(var2, var3))
  //   val body: SoP = SoP(Seq(prods1, prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // a bunch of self mults
  // def test15(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x0".toVar, "y0".toVar, "y1".toVar, "z0".toVar, "y2".toVar, "x1".toVar, "t0".toVar, "z1".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y0".toVar), Tensor)
  //   val var3: Access = Access("B",  Seq("y1".toVar), Tensor)
  //   val var4: Access = Access("C",  Seq("z0".toVar), Tensor)
  //   val var5: Access = Access("B",  Seq("y2".toVar), Tensor)
  //   val var6: Access = Access("A",  Seq("x1".toVar), Tensor)
  //   val var7: Access = Access("D",  Seq("t0".toVar), Tensor)
  //   val var8: Access = Access("C",  Seq("z1".toVar), Tensor)

  //   val prods: Prod = Prod(Seq(var1, var2, var3, var4, var5, var6, var7, var8))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("m".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("p".toVar))
  //   val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
  //   val dim6: DimInfo = DimInfo(var6, Seq("n".toVar))
  //   val dim7: DimInfo = DimInfo(var7, Seq("q".toVar))
  //   val dim8: DimInfo = DimInfo(var8, Seq("p".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dim5, dim6, dim7, dim8)

  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq("x0".toVar), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq("x0".toVar, "x0".toVar.redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq("y0".toVar), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)
    
  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq("y0".toVar, "y0".toVar.redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("B".uniqueName,  Seq("y1".toVar), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
  //   val var3HeadRM: Access = Access("B".redundancyName,  Seq("y1".toVar, "y1".toVar.redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access("C".uniqueName,  Seq("z0".toVar), UniqueSet)
  //   val var4BodyUS: SoP = dim4.toSoP
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)
    
  //   val var4HeadRM: Access = Access("C".redundancyName,  Seq("z0".toVar, "z0".toVar.redundancyVars), RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val var5HeadUS: Access = Access("B".uniqueName,  Seq("y2".toVar), UniqueSet)
  //   val var5BodyUS: SoP = dim5.toSoP
  //   val var5US: Rule = Rule(var5HeadUS, var5BodyUS)
    
  //   val var5HeadRM: Access = Access("B".redundancyName,  Seq("y2".toVar, "y2".toVar.redundancyVars), RedundancyMap)
  //   val var5BodyRM: SoP = emptySoP()
  //   val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

  //   val var6HeadUS: Access = Access("A".uniqueName,  Seq("x1".toVar), UniqueSet)
  //   val var6BodyUS: SoP = dim6.toSoP
  //   val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

  //   val var6HeadRM: Access = Access("A".redundancyName,  Seq("x1".toVar, "x1".toVar.redundancyVars), RedundancyMap)
  //   val var6BodyRM: SoP = emptySoP()
  //   val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

  //   val var7HeadUS: Access = Access("D".uniqueName,  Seq("t0".toVar), UniqueSet)
  //   val var7BodyUS: SoP = dim7.toSoP
  //   val var7US: Rule = Rule(var7HeadUS, var7BodyUS)

  //   val var7HeadRM: Access = Access("D".redundancyName,  Seq("t0".toVar, "t0".toVar.redundancyVars), RedundancyMap)
  //   val var7BodyRM: SoP = emptySoP()
  //   val var7RM: Rule = Rule(var7HeadRM, var7BodyRM)

  //   val var8HeadUS: Access = Access("C".uniqueName,  Seq("z1".toVar), UniqueSet)
  //   val var8BodyUS: SoP = dim8.toSoP
  //   val var8US: Rule = Rule(var8HeadUS, var8BodyUS)
    
  //   val var8HeadRM: Access = Access("C".redundancyName,  Seq("z1".toVar, "z1".toVar.redundancyVars), RedundancyMap)
  //   val var8BodyRM: SoP = emptySoP()
  //   val var8RM: Rule = Rule(var8HeadRM, var8BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US, var5 -> var5US, var6 -> var6US, var7 -> var7US, var8 -> var8US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM, var5 -> var5RM, var6 -> var6RM, var7 -> var7RM, var8 -> var8RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // a bunch of self mults
  // def test16(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x0".toVar, "y0".toVar, "y1".toVar, "y2".toVar, "x1".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y0".toVar), Tensor)
  //   val var3: Access = Access("B",  Seq("y1".toVar), Tensor)
  //   val var5: Access = Access("B",  Seq("y2".toVar), Tensor)
  //   val var6: Access = Access("A",  Seq("x1".toVar), Tensor)

  //   val prods: Prod = Prod(Seq(var1, var2, var3, var5, var6))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("m".toVar))
  //   val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
  //   val dim6: DimInfo = DimInfo(var6, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim5, dim6)

  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq("x0".toVar), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq("x0".toVar, "x0".toVar.redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq("y0".toVar), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)
    
  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq("y0".toVar, "y0".toVar.redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("B".uniqueName,  Seq("y1".toVar), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
  //   val var3HeadRM: Access = Access("B".redundancyName,  Seq("y1".toVar, "y1".toVar.redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var5HeadUS: Access = Access("B".uniqueName,  Seq("y2".toVar), UniqueSet)
  //   val var5BodyUS: SoP = dim5.toSoP
  //   val var5US: Rule = Rule(var5HeadUS, var5BodyUS)
    
  //   val var5HeadRM: Access = Access("B".redundancyName,  Seq("y2".toVar, "y2".toVar.redundancyVars), RedundancyMap)
  //   val var5BodyRM: SoP = emptySoP()
  //   val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

  //   val var6HeadUS: Access = Access("A".uniqueName,  Seq("x1".toVar), UniqueSet)
  //   val var6BodyUS: SoP = dim6.toSoP
  //   val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

  //   val var6HeadRM: Access = Access("A".redundancyName,  Seq("x1".toVar, "x1".toVar.redundancyVars), RedundancyMap)
  //   val var6BodyRM: SoP = emptySoP()
  //   val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var5 -> var5US, var6 -> var6US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var5 -> var5RM, var6 -> var6RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Vector Append test - checked
  // def test17(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar), Tensor)
  //   // val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y".toVar), Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("-", "x".toVar, "n".toVar), "y".toVar)
  //   // val prods1: Prod = Prod(Seq(var1))
  //   val prods2: Prod = Prod(Seq(var2, var3))
  //   // val body: SoP = SoP(Seq(prods1, prods2))
  //   val body: SoP = SoP(Seq(prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   // val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   // val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)
  //   val dimInfo: Seq[DimInfo] = Seq(dim2)


  //   // val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   // val var1BodyUS: SoP = dim1.toSoP
  //   // val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   // val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   // val var1BodyRM: SoP = emptySoP()
  //   // val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   // val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   // val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
  //   val uniqueSets: Map[Exp, Rule] = Map(var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // same computation test - checked
  // def test18(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x0".toVar, "x1".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y1".toVar), Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("-", "x1".toVar, "n".toVar), "y1".toVar)
  //   val var4: Access = Access("A",  Seq("x1".toVar), Tensor)
  //   val var5: Access = Access("B",  Seq("y0".toVar), Tensor)
  //   val var6: Comparison = Comparison("=", Arithmetic("-", "x0".toVar, "n".toVar), "y0".toVar)

  //   val prods1: Prod = Prod(Seq(var1, var2, var3))
  //   val prods2: Prod = Prod(Seq(var4, var5, var6))
  //   val body: SoP = SoP(Seq(prods1, prods2))
  //   // val body: SoP = SoP(Seq(prods1))
  //   // val body: SoP = SoP(Seq(prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar))
  //   val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim4, dim5)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x0")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x0"), Variable("x0").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y1")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y1"), Variable("y1").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var4HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x1")), UniqueSet)
  //   val var4BodyUS: SoP = dim4.toSoP
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x1"), Variable("x1").redundancyVars), RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val var5HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y0")), UniqueSet)
  //   val var5BodyUS: SoP = dim5.toSoP
  //   val var5US: Rule = Rule(var5HeadUS, var5BodyUS)

  //   val var5HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y0"), Variable("y0").redundancyVars), RedundancyMap)
  //   val var5BodyRM: SoP = emptySoP()
  //   val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var4 -> var4US, var5 -> var5US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var4 -> var4RM, var5 -> var5RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // testing input datalayout 
  // def test19(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
  //   val var1BodyUS: SoP = multSoP(Seq(SoP(Seq(var1ProdsUS)), dim1.toSoP))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
  //   val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
  //   val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var1DL = (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "n".toVar), x(1)))

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
  //   val var2BodyUS: SoP = multSoP(Seq(SoP(Seq(var2ProdsUS)), dim2.toSoP))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
  //   val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(SoP(Seq(var2ProdsRM)), dim2.toSoP))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var2DL = (x: Seq[Variable]) => x

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
  //   val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map(var1 -> var1DL, var2 -> var2DL)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // def multiProg1() = {
  //   val head1: Access = Access("T", Seq("x".toVar), Tensor)
  //   val var11: Access = Access("T1",  Seq("x".toVar), Tensor)
  //   val var12: Access = Access("T2",  Seq("x".toVar), Tensor)

  //   val head2: Access = Access("M",  Seq("x".toVar), Tensor)
  //   val var21: Access = Access("U",  Seq("x".toVar), Tensor)

  //   val prods11: Prod = Prod(Seq(var11))
  //   val prods12: Prod = Prod(Seq(var12))
  //   val body1: SoP = SoP(Seq(prods11, prods12))
  //   val tensorComputation1: Rule = Rule(head1, body1)

  //   val prods2: Prod = Prod(Seq(head1, var21))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val tensorComputation2: Rule = Rule(head2, body2)

  //   val tensorComputation: Seq[Rule] = Seq(tensorComputation1, tensorComputation2)

  //   val dim11: DimInfo = DimInfo(var11, Seq("n".toVar))
  //   val dim12: DimInfo = DimInfo(var12, Seq("n".toVar))
  //   val dim21: DimInfo = DimInfo(var21, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim11, dim12, dim21)

  //   val var11HeadUS: Access = Access("T1".uniqueName,  Seq("x".toVar), UniqueSet)
  //   val var11BodyUS: SoP = dim11.toSoP
  //   val var11US: Rule = Rule(var11HeadUS, var11BodyUS)

  //   val var11HeadRM: Access = Access("T1".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
  //   val var11BodyRM: SoP = emptySoP()
  //   val var11RM: Rule = Rule(var11HeadRM, var11BodyRM)

  //   val var12HeadUS: Access = Access("T2".uniqueName,  Seq("x".toVar), UniqueSet)
  //   val var12BodyUS: SoP = dim12.toSoP
  //   val var12US: Rule = Rule(var12HeadUS, var12BodyUS)

  //   val var12HeadRM: Access = Access("T2".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
  //   val var12BodyRM: SoP = emptySoP()
  //   val var12RM: Rule = Rule(var12HeadRM, var12BodyRM)

  //   val var21HeadUS: Access = Access("U".uniqueName,  Seq("x".toVar), UniqueSet)
  //   val var21BodyUS: SoP = dim21.toSoP
  //   val var21US: Rule = Rule(var21HeadUS, var21BodyUS)

  //   val var21HeadRM: Access = Access("U".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
  //   val var21BodyRM: SoP = emptySoP()
  //   val var21RM: Rule = Rule(var21HeadRM, var21BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var11 -> var11US, var12 -> var12US, var21 -> var21US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var11 -> var11RM, var12 -> var12RM, var21 -> var21RM)

  //   println(codeGenProgram(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // def multiProg2() = {
  //   val head1: Access = Access("T", Seq("x".toVar), Tensor)
  //   val var11: Access = Access("T1",  Seq("x".toVar, "y".toVar), Tensor)

  //   val head2: Access = Access("M",  Seq("x".toVar), Tensor)

  //   val prods1: Prod = Prod(Seq(var11))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val tensorComputation1: Rule = Rule(head1, body1)

  //   val prods2: Prod = Prod(Seq(head1, head1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val tensorComputation2: Rule = Rule(head2, body2)

  //   val tensorComputation: Seq[Rule] = Seq(tensorComputation1, tensorComputation2)

  //   val dim11: DimInfo = DimInfo(var11, Seq("n".toVar, "m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim11)

  //   val var11HeadUS: Access = Access("T1".uniqueName,  Seq("x".toVar, "y".toVar), UniqueSet)
  //   val var11BodyUS: SoP = dim11.toSoP
  //   val var11US: Rule = Rule(var11HeadUS, var11BodyUS)

  //   val var11HeadRM: Access = Access("T1".redundancyName,  Seq("x".toVar, "y".toVar, "x".toVar.redundancyVars, "y".toVar.redundancyVars), RedundancyMap)
  //   val var11BodyRM: SoP = emptySoP()
  //   val var11RM: Rule = Rule(var11HeadRM, var11BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var11 -> var11US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var11 -> var11RM)

  //   println(codeGenProgram(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Any degree self-product -- degree 3 to degree 6 tested and seems correct -- for degree 5 and 6 I can't check actually
  // def selfprodMult(n: Int): (Rule, (Rule, Rule, DimInfo)) = {
  //   val indSeq: Seq[Int] = (0 to n - 1)
  //   val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
  //   val head: Access = Access("M", xSeq, Tensor)
  //   val vars: Seq[Access] = xSeq.map(x => Access("A", Seq(x), Tensor))
  //   val prods: Prod = Prod(vars)
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)
  //   val dimInfo: Seq[DimInfo] = vars.map(v => DimInfo(v, Seq("n".toVar)))

  //   val varHeadUS: Seq[Access] = xSeq.map(x => Access("A".uniqueName, Seq(x), UniqueSet)) 
  //   val varBodyUS: Seq[SoP] = dimInfo.map(dim => dim.toSoP)
  //   val varUS: Seq[Rule] = (varHeadUS zip varBodyUS).map{case (head, body) => Rule(head, body)}

  //   val varHeadRM: Seq[Access] = xSeq.map(x => Access("A".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
  //   val varBodyRM: Seq[SoP] = dimInfo.map(dim => emptySoP())
  //   val varRM: Seq[Rule] = (varHeadRM zip varBodyRM).map{case (head, body) => Rule(head, body)}

  //   val uniqueSets: Map[Exp, Rule] = (vars zip varUS).map{case (v, r) => (v -> r)}.toMap
  //   val redundancyMap: Map[Exp, Rule] = (vars zip varRM).map{case (v, r) => (v -> r)}.toMap

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Any degree self-product addition --
  // def selfprodAdd(n: Int): (Rule, (Rule, Rule, DimInfo)) = {
  //   val indSeq1: Seq[Int] = (0 to n - 1)
  //   val xSeq1: Seq[Variable] = indSeq1.map(i => s"x$i".toVar)
  //   val head1: Access = Access("M", xSeq1, Tensor)
  //   val vars1: Seq[Access] = xSeq1.map(x => Access("A", Seq(x), Tensor))
  //   val prods1: Prod = Prod(vars1)
  //   val body1: SoP = SoP(Seq(prods1))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val dimInfo1: Seq[DimInfo] = vars1.map(v => DimInfo(v, Seq("n".toVar)))

  //   val varHeadUS1: Seq[Access] = xSeq1.map(x => Access("A".uniqueName, Seq(x), UniqueSet)) 
  //   val varBodyUS1: Seq[SoP] = dimInfo1.map(dim => dim.toSoP)
  //   val varUS1: Seq[Rule] = (varHeadUS1 zip varBodyUS1).map{case (head, body) => Rule(head, body)}

  //   val varHeadRM1: Seq[Access] = xSeq1.map(x => Access("A".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
  //   val varBodyRM1: Seq[SoP] = dimInfo1.map(dim => emptySoP())
  //   val varRM1: Seq[Rule] = (varHeadRM1 zip varBodyRM1).map{case (head, body) => Rule(head, body)}

  //   val uniqueSets1: Map[Exp, Rule] = (vars1 zip varUS1).map{case (v, r) => (v -> r)}.toMap
  //   val redundancyMap1: Map[Exp, Rule] = (vars1 zip varRM1).map{case (v, r) => (v -> r)}.toMap

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo1, uniqueSets1, redundancyMap1)



  //   val indSeq2: Seq[Int] = (0 to n - 1)
  //   val xSeq2: Seq[Variable] = indSeq2.map(i => s"x$i".toVar)
  //   val head2: Access = Access("N", xSeq2, Tensor)
  //   val vars2: Seq[Access] = xSeq2.map(x => Access("B", Seq(x), Tensor))
  //   val prods2: Prod = Prod(vars2)
  //   val body2: SoP = SoP(Seq(prods2))
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val dimInfo2: Seq[DimInfo] = vars2.map(v => DimInfo(v, Seq("n".toVar)))

  //   val varHeadUS2: Seq[Access] = xSeq2.map(x => Access("B".uniqueName, Seq(x), UniqueSet)) 
  //   val varBodyUS2: Seq[SoP] = dimInfo2.map(dim => dim.toSoP)
  //   val varUS2: Seq[Rule] = (varHeadUS2 zip varBodyUS2).map{case (head, body) => Rule(head, body)}

  //   val varHeadRM2: Seq[Access] = xSeq2.map(x => Access("B".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
  //   val varBodyRM2: Seq[SoP] = dimInfo2.map(dim => emptySoP())
  //   val varRM2: Seq[Rule] = (varHeadRM2 zip varBodyRM2).map{case (head, body) => Rule(head, body)}

  //   val uniqueSets2: Map[Exp, Rule] = (vars2 zip varUS2).map{case (v, r) => (v -> r)}.toMap
  //   val redundancyMap2: Map[Exp, Rule] = (vars2 zip varRM2).map{case (v, r) => (v -> r)}.toMap

  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo2, uniqueSets2, redundancyMap2)

  //   val p1: Prod = Prod(Seq(head1))
  //   val p2: Prod = Prod(Seq(head2))
  //   val head: Access = Access("O", xSeq1, Tensor)
  //   val body: SoP = SoP(Seq(p1, p2))
  //   val tensorComputation: Rule = Rule(head, body)
  //   val uniqueSets: Map[Exp, Rule] = Map(head1 -> infer1._1, head2 -> infer2._1)
  //   val redundancyMap: Map[Exp, Rule] = Map(head1 -> infer1._2, head2 -> infer2._2)
  //   val dimInfo: Seq[DimInfo] = dimInfo1 ++ dimInfo2 ++ Seq(infer1._3, infer2._3)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  def ttm(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP") = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "l".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar, "Q".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("P".toVar, "Q".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag_p" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "uhc" => {
        val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "diag_p" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "Q".toVar), x(2)))
      case "fixed_j" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "Q".toVar), x(2)))
      case "uhc" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", Arithmetic("-", Arithmetic("+", Arithmetic("*", x(0), "N".toVar), x(1)), Arithmetic("/", Arithmetic("*", x(0), Arithmetic("+", x(0), ConstantInt(1))), ConstantInt(2))), "Q".toVar), x(2)))
      case _ => (x: Seq[Variable]) => x
    }

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang)
  }

  def thp(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP") = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var2: Access = Access("C",  Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar, "P".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("M".toVar, "N".toVar, "P".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag_p" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "diag_p" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "P".toVar), x(2)))
      case "fixed_j" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "P".toVar), x(2)))
      case "fixed_i" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(1), "P".toVar), x(2)))
      case _ => (x: Seq[Variable]) => x
    }

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang)
  }

  // def mttkrp(structure: String, mode: Int = 0) = {
  //   val head: Access = Access("A", Seq("i".toVar, "j".toVar), Tensor)
  //   val var1: Access = Access("B",  Seq("i".toVar, "k".toVar, "l".toVar), Tensor)
  //   val var2: Access = Access("C",  Seq("k".toVar, "j".toVar), Tensor)
  //   val var3: Access = Access("D",  Seq("l".toVar, "j".toVar), Tensor)
  //   val head1: Access = Access("E", Seq("i".toVar, "k".toVar, "l".toVar, "j".toVar), Tensor)
    
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val tensorComputation1: Rule = Rule(head1, body1)

  //   val prods: Prod = Prod(Seq(head1, var3))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("ni".toVar, "nk".toVar, "nl".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("nk".toVar, "nj".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("nl".toVar, "nj".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


  //   val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
  //   val var1BodyUS: SoP = structure match {
  //     case "fixed_ij" => {
  //       val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
  //       val var1ExpUS2: Exp = Comparison("=", "j".toVar, "J".toVar)
  //       val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
  //       multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //     }
  //     case "fixed_i" => {
  //       val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
  //       val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //       multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //     }
  //     case "fixed_j" => {
  //       val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
  //       val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //       multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //     }
  //     case _ => dim1.toSoP
  //   } 
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

  //   pprintTest((tensorComputation1, infer1))

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo :+ infer1._3

  //   if (mode == 0) {
  //     println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //     (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  //   } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1)
  // }

  def mttkrp_n(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP") = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "k".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "j".toVar), Tensor)
    val var3: Access = Access("D",  Seq("l".toVar, "j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2, var3))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar, "P".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar, "Q".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("P".toVar, "Q".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "fixed_ij" | "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "fixed_ij" | "fixed_i" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(1), "P".toVar), x(2)))
      case _ => (x: Seq[Variable]) => x
    }

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
    val var3BodyUS: SoP = structure match {
      case "fixed_ij" | "fixed_j" => {
        val var3ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var3ProdsUS: Prod = Prod(Seq(var3ExpUS1))
        multSoP(Seq(dim3.toSoP, SoP(Seq(var3ProdsUS))))
      }      
      case _ => dim3.toSoP
    } 
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var3DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "fixed_ij" | "fixed_j" => (x: Seq[Variable]) => Seq(x(0))
      case _ => (x: Seq[Variable]) => x
    }

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL, var3 -> var3DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang)
  }

  def e2eConstructor(n: Int, mode: Int = 0) = {
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val cont = if (mode == 0) "cont" else "other_cont"
    val head: Access = Access(s"${cont}_degree$n", xSeq, Tensor)
    val vars: Seq[Access] = xSeq.map(x => Access(s"${cont}_sum1", Seq(x), Tensor))
    val prods: Prod = Prod(vars)
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)
    val dimInfo: Seq[DimInfo] = vars.map(v => DimInfo(v, Seq("CONT_SZ".toVar)))

    val varHeadUS: Seq[Access] = xSeq.map(x => Access(s"${cont}_sum1".uniqueName, Seq(x), UniqueSet)) 
    val varBodyUS: Seq[SoP] = dimInfo.map(dim => dim.toSoP)
    val varUS: Seq[Rule] = (varHeadUS zip varBodyUS).map{case (head, body) => Rule(head, body)}

    val varHeadRM: Seq[Access] = xSeq.map(x => Access(s"${cont}_sum1".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
    val varBodyRM: Seq[SoP] = dimInfo.map(dim => emptySoP())
    val varRM: Seq[Rule] = (varHeadRM zip varBodyRM).map{case (head, body) => Rule(head, body)}

    val uniqueSets: Map[Exp, Rule] = (vars zip varUS).map{case (v, r) => (v -> r)}.toMap
    val redundancyMap: Map[Exp, Rule] = (vars zip varRM).map{case (v, r) => (v -> r)}.toMap

    val compressionMap: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp))))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap, compressionMap)

    val us: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val c: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), compressionMap))((v1, v2) => v1)
    val di: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, di, us, rm, c)
  }

  def e2eAddition(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule], mode: Int = 0) = {
    val name = if (n == 0) "count" else if (n == 1) "cont_sum1" else s"cont_degree$n"
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val r = if (mode == 0) "r." else "r_"
    val head: Access = Access(s"$r$name", xSeq, Tensor)
    val other = if (mode == 0) "other." else "other_"
    val var1: Access = Access(name,  xSeq, Tensor)
    val var2: Access = Access(s"$other$name",  xSeq, Tensor)
    val prods1: Prod = Prod(Seq(var1))
    val prods2: Prod = Prod(Seq(var2))
    val body: SoP = SoP(Seq(prods1, prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dimSeq: Seq[Variable] = indSeq.map(i => "CONT_SZ".toVar)

    val dim1: DimInfo = DimInfo(var1, dimSeq)
    val dim2: DimInfo = DimInfo(var2, dimSeq)
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(name.uniqueName,  xSeq, UniqueSet)
    val var1BodyUS: SoP = if(n == 0) SoP(Seq(Prod(Seq(trueComparison())))) else dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(name.redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(s"$other$name".uniqueName,  xSeq, UniqueSet)
    val var2BodyUS: SoP = if(n == 0) SoP(Seq(Prod(Seq(trueComparison())))) else dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(s"$other$name".redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](var1 -> var1US, var2 -> var2US)))((v1, v2) => v1)
    val redundancyMap: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](var1 -> var1RM, var2 -> var2RM)))((v1, v2) => v1)

    val compressionMap: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp))))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap, compressionMap)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val cF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), compressionMap))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, diF, usF, rmF, cF)
  }

  def e2ePlusEqual(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule], c: Map[Exp, Rule], mode: Int = 0) = {
    val name = if (n == 0) "count" else if (n == 1) "cont_sum1" else s"cont_degree$n"
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val head: Access = Access(name, xSeq, Tensor)
    val other = if (mode == 0) "other." else "other_"
    val var2: Access = Access(s"$other$name",  xSeq, Tensor)
    val prods2: Prod = Prod(Seq(var2))
    val body: SoP = SoP(Seq(prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dimSeq: Seq[Variable] = indSeq.map(i => "CONT_SZ".toVar)

    val dim2: DimInfo = DimInfo(var2, dimSeq)
    val dimInfo: Seq[DimInfo] = Seq(dim2)

    val var2HeadUS: Access = Access(s"$other$name".uniqueName,  xSeq, UniqueSet)
    val var2BodyUS: SoP = if(n == 0) SoP(Seq(Prod(Seq(trueComparison())))) else dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(s"$other$name".redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](var2 -> var2US)))((v1, v2) => v1)
    val redundancyMap: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](var2 -> var2RM)))((v1, v2) => v1)

    val compressionMap: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp))))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap, compressionMap)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val cF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), compressionMap))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, diF, usF, rmF, cF)
  }

  def e2eMultiplication(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule], c: Map[Exp, Rule]) = {
    val degrees: Seq[Int] = (0 to n)
    val outName: String = if (n == 0) "r.count" else if (n == 1) "r.cont_sum1" else s"r.cont_degree$n"
    val (prods, dimInfo, newUS, newRM, newC): (Seq[Prod], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], Map[Exp, Rule]) = degrees.foldLeft((Seq.empty[Prod], Seq.empty[DimInfo], us, rm, c))((acc, i) => {
      val (degA, degB): (Int, Int) = (n - i, i)
      val nameA: String = if (degA == 0) "count" else if (degA == 1) "cont_sum1" else s"cont_degree$degA"
      val nameB: String = if (degB == 0) "other.count" else if (degB == 1) "other.cont_sum1" else s"other.cont_degree$degB"
      (0 to n - 1).combinations(degA).foldLeft(acc)((acc2, xIndSeq) => {
        val yIndSeq: Seq[Int] = (0 to n - 1).filter(i => !xIndSeq.contains(i)).toSeq
        val xSeqA: Seq[Variable] = (0 to degA - 1).map(i => s"x${xIndSeq(i)}".toVar)
        val xSeqB: Seq[Variable] = (0 to degB - 1).map(i => s"y${yIndSeq(i)}".toVar)
        val xSeqFakeA: Seq[Variable] = (0 to degA - 1).map(i => s"x$i".toVar)
        val xSeqFakeB: Seq[Variable] = (0 to degB - 1).map(i => s"x$i".toVar)
        val xMapA1: Map[Variable, Variable] = (xSeqFakeA zip xSeqA).toMap
        val xMapA2: Map[Variable, Variable] = xMapA1.map{case(k, v) => (k.redundancyVars -> v.redundancyVars)}.toMap
        val xMapA: Map[Variable, Variable] = mergeMap(Seq(xMapA1, xMapA2))((v1, v2) => v1)
        val xMapB1: Map[Variable, Variable] = mergeMap(Seq((xSeqFakeB zip xSeqB).toMap, Map[Variable, Variable]("CONT_SZ".toVar -> "CONT_SZ2".toVar)))((v1, v2) => v1)
        val xMapB2: Map[Variable, Variable] = xMapB1.map{case(k, v) => (k.redundancyVars -> v.redundancyVars)}.toMap
        val xMapB: Map[Variable, Variable] = mergeMap(Seq(xMapB1, xMapB2))((v1, v2) => v1)
        val headFakeA: Access = Access(nameA, xSeqFakeA, Tensor)
        val headFakeB: Access = Access(nameB, xSeqFakeB, Tensor)
        val (aFakeUS, aFakeRM, aFakeC): (Rule, Rule, Rule) = (acc2._3.getOrElse(headFakeA, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._4.getOrElse(headFakeA, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._5.getOrElse(headFakeA, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison(), headFakeA)))))))
        val (bFakeUS, bFakeRM, bFakeC): (Rule, Rule, Rule) = (acc2._3.getOrElse(headFakeB, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._4.getOrElse(headFakeB, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._5.getOrElse(headFakeB, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison(), headFakeB)))))))
        val (aUS, aRM, aC): (Rule, Rule, Rule) = (replaceVars(aFakeUS, xMapA), replaceVars(aFakeRM, xMapA), replaceVars(aFakeC, xMapA))
        val (bUS, bRM, bC): (Rule, Rule, Rule) = (replaceVars(bFakeUS, xMapB), replaceVars(bFakeRM, xMapB), replaceVars(bFakeC, xMapB))
        val headA: Access = Access(nameA, xSeqA, Tensor)
        val headB: Access = Access(nameB, xSeqB, Tensor)
        val newUS: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headA -> aUS, headB -> bUS), acc2._3))((v1, v2) => v1)
        val newRM: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headA -> aRM, headB -> bRM), acc2._4))((v1, v2) => v1)
        val newC: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headA -> aC, headB -> bC), acc2._5))((v1, v2) => v1)
        val dimSeqA: Seq[Variable] = xSeqA.map(i => "CONT_SZ".toVar)
        val dimSeqB: Seq[Variable] = xSeqB.map(i => "CONT_SZ2".toVar)
        val dimA: DimInfo = DimInfo(headA, dimSeqA)
        val dimB: DimInfo = DimInfo(headB, dimSeqB)
        val dimInfo: Seq[DimInfo] = Seq(dimA, dimB)
        
        val compSeqB: Seq[Variable] = (0 to degB - 1).map(i => s"x${yIndSeq(i)}".toVar)
        val comp: Seq[Comparison] = (compSeqB zip xSeqB).map{case (x, y) => Comparison("=", Arithmetic("-", x, "CONT_SZ".toVar), y)}

        (acc2._1 :+ Prod(Seq(headA, headB) ++ comp), acc2._2 ++ dimInfo, newUS, newRM, newC)
      })
    })
    val xSeq: Seq[Variable] = (0 to n - 1).map(i => s"x$i".toVar)
    val head: Access = Access(outName, xSeq, Tensor)
    val body = SoP(prods)
    val tensorComputation: Rule = Rule(head, body)

    // println("Initial mult us and rm")

    // newUS.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <newus> " + cur._2.prettyFormat))
    // newRM.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <newrm> " + cur._2.prettyFormat))

    // println("Initial mult us and rm DONE")

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, newUS, newRM, newC)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), newUS))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), newRM))((v1, v2) => v1)
    val cF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), newC))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, diF, usF, rmF, cF)
  }

  def e2eLR() = {
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = e2eConstructor(2)
    // println(codeGen(const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap))
    // println("===========================================================")
    val us2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val rm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val c2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val us: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, us2))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, rm2))((v1, v2) => v1)
    val c: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, c2))((v1, v2) => v1)

    // println("Initial us and rm")

    // us.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <us> " + cur._2.prettyFormat))
    // rm.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <rm> " + cur._2.prettyFormat))

    // println("Initial us and rm DONE")

    // val (add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap) = e2eAddition(2, us, rm)
    // println(codeGen(add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap))
    // println("===========================================================")

    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = e2ePlusEqual(2, us, rm, c)
    // println(codeGen(peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap))
    // println("===========================================================")

    val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, mult_compressionMap) = e2eMultiplication(2, us, rm, c)
    println(mult_tensorComputation.prettyFormat)
    println(codeGen(mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, compressionMaps=mult_compressionMap))
    println("===========================================================")
  }

  def e2ePRk(k: Int) = {
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    // const_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap)))
    // println("===========================================================")
    val us2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val rm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val c2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val us: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, us2))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, rm2))((v1, v2) => v1)
    val c: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, c2))((v1, v2) => v1)

    // println("Initial us and rm")

    // us.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <us> " + cur._2.prettyFormat))
    // rm.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <rm> " + cur._2.prettyFormat))

    // println("Initial us and rm DONE")

    // val (add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, us, rm))((acc, d) => {
    //   val res = e2eAddition(d, acc._3, acc._4)
    //   (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    // })
    // add_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, add_dimInfo, add_uniqueSets, add_redundancyMap)))
    // println("===========================================================")

    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, us, rm, c))((acc, d) => {
      val res = e2ePlusEqual(d, acc._3, acc._4, acc._5)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    peq_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, compressionMaps=peq_compressionMap)))
    println("===========================================================")

    // val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, us, rm))((acc, d) => {
    //   val res = e2eMultiplication(d, acc._3, acc._4)
    //   (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    // })
    // mult_tensorComputation.foldLeft()((_, cur) => println(cur.prettyFormat))
    // mult_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, mult_dimInfo, mult_uniqueSets, mult_redundancyMap)))
    // println("===========================================================")
  }

  def e2ePRkWithSkeletone(k: Int) = {
    val initCode: String = s"""
#ifndef RING_COFACTOR_HPP
#define RING_COFACTOR_HPP

#include <array>
#include <unordered_map>
#include "hash.hpp"


template <typename T, int CONT_SZ, int CAT_SZ>
struct RingCofactor {
    long count;
    std::array<double, CONT_SZ> cont_sum1;
    std::array<std::array<double, CONT_SZ>, CONT_SZ> cont_degree2;
    ${if (k == 2) {
      s"""
    std::array<std::array<std::array<double, CONT_SZ>, CONT_SZ>, CONT_SZ> cont_degree3;
    std::array<std::array<std::array<std::array<double, CONT_SZ>, CONT_SZ>, CONT_SZ>, CONT_SZ> cont_degree4;
      """
    } else ""}


    explicit RingCofactor() : count(0) {
      cont_sum1 = {};
      cont_degree2 = {};
      ${if (k == 2) {
        s"""
      cont_degree3 = {};
      cont_degree4 = {};
        """
      } else ""}
    }

    template <typename... Args>
    explicit RingCofactor(Args&&... args): count(1), cont_sum1 { args... } {
        static_assert(CONT_SZ == sizeof...(args) && CAT_SZ == 0, "Incompatible array sizes");
"""

    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val constructorCode: String = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip 
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other." + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)

    val multus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val multrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val multc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), 
    SoP((getOnlyComparisonSoP(v.body).prods zip
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other." + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val multus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, multus2))((v1, v2) => v1)
    val multrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, multrm2))((v1, v2) => v1)
    val multc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, multc2))((v1, v2) => v1)

    val afterConstructorCode: String = s"""
    }
    
    inline bool isZero() const { return count == 0; }

    void finished(double div_val = 0, bool mapping_flag = false) {

    }

    RingCofactor& operator+=(const RingCofactor& other) {
        peqInplace(other);
        return *this;
    }

    void peqInplace(const RingCofactor& other, bool sort_merge_flag = false) {
        if (other.isZero()) return;
"""

    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = (0 to 2 * k).foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2ePlusEqual(d, acc._3, acc._4, acc._5)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val peqCode: String = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")

    val afterPeqCode: String = s"""
    }
    template <int CONT_SZ2, int CAT_SZ2>
    RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> operator*(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other) const {
        if (isZero() || other.isZero()) return RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>();
        return this->multiply(other);
    }

    template <int CONT_SZ2, int CAT_SZ2>
    RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>
    multiply(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other) const {
        RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> r;
        multiplyDPS(other, r);
        return r;
    }

    template <int CONT_SZ2, int CAT_SZ2>
    void
    multiplyDPS(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other, RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>& r) const {    
"""

    val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, mult_compressionMap) = (0 to 2 * k).foldLeft((Seq.empty[Rule], const_dimInfo, multus, multrm, multc))((acc, d) => {
      val res = e2eMultiplication(d, acc._3, acc._4, acc._5)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val multCode: String = mult_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, 1)}")

    val afterMultCode: String = s"""
        }


    void clean() {
      count = 0;

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {
        cont_sum1[i1] = 0;
      }

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {
          cont_degree2[i1][i2] = 0;
        }
      }

      ${if (k == 2) {
        s"""
      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {

          for(int i3 = i2; i3 < CONT_SZ; ++i3) {
            cont_degree3[i1][i2][i3] = 0;
          }
        }
      }

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {

          for(int i3 = i2; i3 < CONT_SZ; ++i3) {

            for(int i4 = i3; i4 < CONT_SZ; ++i4) {
              cont_degree4[i1][i2][i3][i4] = 0;
            }
          }
        }
      }
"""
      } else ""}
    }    
    void reconstruct() {
"""

    val reconstructorCode: String = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 2, compressionMaps=const_compressionMap)}")

    val endCode: String = s"""
        std::cerr << cont_sum1[CONT_SZ - 1];
        std::cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1];
        ${if (k == 2) {
          s"""
        std::cerr << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1];
        std::cerr << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1];
"""
        } else ""}
    }

};

template <typename T, size_t CONT_SZ, size_t CAT_SZ>
RingCofactor<T, CONT_SZ, CAT_SZ> operator*(long int alpha, const RingCofactor<T, CONT_SZ, CAT_SZ>& c) {
    if (alpha == 1L) return c;
    return c.multiply(alpha);
}

template <typename T>
inline double convert(T x) { return x; }

template <typename... Args>
RingCofactor<double, sizeof...(Args), 0> Uliftcont(Args&&... args) {
    return RingCofactor<double, sizeof...(Args), 0>(convert(args)...);
}

template <typename... Args>
RingCofactor<double, 0, sizeof...(Args)> Uliftcat(Args&&... args) {
    return RingCofactor<double, 0, sizeof...(Args)>(true, args...);
}

template <typename T, int CONT_SZ, int CAT_SZ>
std::ostream& operator<<(std::ostream& os, const RingCofactor<T, CONT_SZ, CAT_SZ>& v) {
os << "Cofactor: <CONT_SZ: " << CONT_SZ << ", CAT_SZ: " << CAT_SZ << ">\\n";
  os << v.count << "\\n";
  os << "cont_sum1:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    os << v.cont_sum1[i] << ((i < CONT_SZ - 1) ? ", " : "\\n");
  }

  os << "cont_degree2:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        os << v.cont_degree2[i][j] << ", ";
    }
  }
  os << "\\n";

  ${if (k == 2) {
    s"""
  os << "cont_degree3:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        for (int k = 0; k < CONT_SZ; ++k) {
            os << v.cont_degree3[i][j][k] << ", ";
        }
    }
  }
  os << "\\n";

  os << "cont_degree4:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        for (int k = 0; k < CONT_SZ; ++k) {
            for (int l = 0; l < CONT_SZ; ++l) {
                os << v.cont_degree4[i][j][k][l] << ", ";
            }
        }
    }
  }
  os << "\\n";
"""
  } else ""}
  return os;
}

#endif /* RING_COFACTOR_HPP */
"""
  s"$initCode\n$constructorCode\n$afterConstructorCode\n$peqCode\n$afterPeqCode\n$multCode\n$afterMultCode\n$reconstructorCode\n$endCode"
  }

  // Chess Pattern is not implemented since it was just a unique set with no computation
  // none of vec(.), //, and || are explained in the paper in mathematical terms + don't know how to implement the code for this example
  // Kronecker product explanation in Fig 7. should have * in it (not +)!
  // pprintTest(test1())
  // pprintTest(test2())
  // pprintTest(test3())
  // pprintTest(test4())
  // pprintTest(test5())
  // pprintTest(test6())
  // pprintTest(test7())
  // pprintTest(test8())
  // pprintTest(test8n())
  // pprintTest(test9())
  // pprintTest(test9n())
  // pprintTest(test10()) // do not test this. It is not a valid test.
  // pprintTest(test11())
  // pprintTest(test12())
  // pprintTest(test13())
  // pprintTest(test13n())
  // pprintTest(test14())
  // pprintTest(test15())
  // pprintTest(test16())
  // pprintTest(test17())
  // pprintTest(test18())
  // pprintTest(selfprodMult(3))
  // pprintTest(selfprodMult(4))
  // pprintTest(selfprodMult(5))
  // pprintTest(selfprodMult(6))
  // pprintTest(selfprodAdd(3))
  // pprintTest(selfprodAdd(4))
  // pprintTest(selfprodAdd(5))
  // pprintTest(selfprodAdd(6))
  // multiProg1()
  // multiProg2()
  // e2eLR()
  // e2ePRk(1)
  // e2ePRk(2)

  // println(e2ePRkWithSkeletone(1))
  // println(e2ePRkWithSkeletone(2))

  // println("TTM:")
  // pprintTest(ttm(""))
  // println("TTM Diagonal (Plane):")
  // pprintTest(ttm("diag_p"))
  // println("TTM: Fixed j")
  // pprintTest(ttm("fixed_j"))
  // println("TTM: Upper Half Cube")
  // pprintTest(ttm("uhc"))

  // println("THP:")
  // pprintTest(thp(""))
  // println("THP Diagonal (Plane):")
  // pprintTest(thp("diag_p"))
  // println("THP: Fixed i")
  // pprintTest(thp("fixed_i"))
  // println("THP: Fixed j")
  // pprintTest(thp("fixed_j"))

  // println("MTTKRP:")
  // pprintTest(mttkrp(""))
  // println("MTTKRP Fixed i,j:")
  // pprintTest(mttkrp("fixed_ij"))
  // println("MTTKRP: Fixed i")
  // pprintTest(mttkrp("fixed_i"))
  // println("MTTKRP: Fixed j")
  // pprintTest(mttkrp("fixed_j"))

  // println("MTTKRP_N:")
  // pprintTest(mttkrp_n(""))
  // println("MTTKRP_N Fixed i,j:")
  // pprintTest(mttkrp_n("fixed_ij"))
  // println("MTTKRP_N: Fixed i")
  // pprintTest(mttkrp_n("fixed_i"))
  // println("MTTKRP_N: Fixed j")
  // pprintTest(mttkrp_n("fixed_j"))

  def write2File(filename: String, s: String): Unit = { // taken from https://alvinalexander.com/scala/how-to-write-text-files-in-scala-printwriter-filewriter/
    val file = new File(filename)
    val bw = new BufferedWriter(new FileWriter(file))
    bw.write(s)
    bw.close()
  }


  def LRC() = {
    val c1 =
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val allDegs = (2 to 2)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    delete[] cont_degree2[i];
  }
  delete[] cont_degree2;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File("outputs/LRC.cpp", code)
  }

  def PR2C() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val allDegs = (2 to 4)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] cont_degree4[i][j];
    }
    delete[] cont_degree2[i];
    delete[] cont_degree3[i];
    delete[] cont_degree4[i];
  }
  delete[] cont_degree2;
  delete[] cont_degree3;
  delete[] cont_degree4;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File("outputs/PR2C.cpp", code)
  }

  def PR3C() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double *****cont_degree5 = new double****[CONT_SZ];
  double ******cont_degree6 = new double*****[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    cont_degree5[i] = new double***[CONT_SZ];
    cont_degree6[i] = new double****[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      cont_degree5[i][j] = new double**[CONT_SZ];
      cont_degree6[i][j] = new double***[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        cont_degree5[i][j][k] = new double*[CONT_SZ];
        cont_degree6[i][j][k] = new double**[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          cont_degree5[i][j][k][l] = new double[CONT_SZ];
          cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          for (int p = 0; p < CONT_SZ; p++) {
            cont_degree5[i][j][k][l][p] = 0;
            cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            for (int q = 0; q < CONT_SZ; q++) {
              cont_degree6[i][j][k][l][p][q] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
      cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val allDegs = (2 to 6)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree5[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree6[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
      for (int j = 0; j < CONT_SZ; j++) {
          for (int k = 0; k < CONT_SZ; k++) {
              for (int l = 0; l < CONT_SZ; l++) {
                  for (int p = 0; p < CONT_SZ; p++) {
                      delete[] cont_degree6[i][j][k][l][p];
                  }
                  delete[] cont_degree5[i][j][k][l];
                  delete[] cont_degree6[i][j][k][l];
              }
              delete[] cont_degree4[i][j][k];
              delete[] cont_degree5[i][j][k];
              delete[] cont_degree6[i][j][k];
          }
          delete[] cont_degree3[i][j];
          delete[] cont_degree4[i][j];
          delete[] cont_degree5[i][j];
          delete[] cont_degree6[i][j];
      }
      delete[] cont_degree2[i];
      delete[] cont_degree3[i];
      delete[] cont_degree4[i];
      delete[] cont_degree5[i];
      delete[] cont_degree6[i];
  }
  delete[] cont_degree2;
  delete[] cont_degree3;
  delete[] cont_degree4;
  delete[] cont_degree5;
  delete[] cont_degree6;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File("outputs/PR3C.cpp", code)
  }


  def LRA() = {
    val c1 =
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 1
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, other_const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other_" + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=other_const_compressionMap)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    delete[] cont_degree2[i];
    delete[] other_cont_degree2[i];
    delete[] r_cont_degree2[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/LRA.cpp", code)
  }

  def PR2A() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ***other_cont_degree3 = new double**[CONT_SZ];
  double ***r_cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double ****other_cont_degree4 = new double***[CONT_SZ];
  double ****r_cont_degree4 = new double***[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    other_cont_degree3[i] = new double*[CONT_SZ];
    r_cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    other_cont_degree4[i] = new double**[CONT_SZ];
    r_cont_degree4[i] = new double**[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      other_cont_degree3[i][j] = new double[CONT_SZ];
      r_cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      other_cont_degree4[i][j] = new double*[CONT_SZ];
      r_cont_degree4[i][j] = new double*[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 2
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, other_const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip 
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other_" + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
        delete[] other_cont_degree4[i][j][k];
        delete[] r_cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] other_cont_degree3[i][j];
      delete[] r_cont_degree3[i][j];
      delete[] cont_degree4[i][j];
      delete[] other_cont_degree4[i][j];
      delete[] r_cont_degree4[i][j];
    }
    delete[] cont_degree2[i];
    delete[] other_cont_degree2[i];
    delete[] r_cont_degree2[i];
    delete[] cont_degree3[i];
    delete[] other_cont_degree3[i];
    delete[] r_cont_degree3[i];
    delete[] cont_degree4[i];
    delete[] other_cont_degree4[i];
    delete[] r_cont_degree4[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  delete[] cont_degree3;
  delete[] other_cont_degree3;
  delete[] r_cont_degree3;
  delete[] cont_degree4;
  delete[] other_cont_degree4;
  delete[] r_cont_degree4;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/PR2A.cpp", code)
  }

  def PR3A() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ***other_cont_degree3 = new double**[CONT_SZ];
  double ***r_cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double ****other_cont_degree4 = new double***[CONT_SZ];
  double ****r_cont_degree4 = new double***[CONT_SZ];
  double *****cont_degree5 = new double****[CONT_SZ];
  double *****other_cont_degree5 = new double****[CONT_SZ];
  double *****r_cont_degree5 = new double****[CONT_SZ];
  double ******cont_degree6 = new double*****[CONT_SZ];
  double ******other_cont_degree6 = new double*****[CONT_SZ];
  double ******r_cont_degree6 = new double*****[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    other_cont_degree3[i] = new double*[CONT_SZ];
    r_cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    other_cont_degree4[i] = new double**[CONT_SZ];
    r_cont_degree4[i] = new double**[CONT_SZ];
    cont_degree5[i] = new double***[CONT_SZ];
    other_cont_degree5[i] = new double***[CONT_SZ];
    r_cont_degree5[i] = new double***[CONT_SZ];
    cont_degree6[i] = new double****[CONT_SZ];
    other_cont_degree6[i] = new double****[CONT_SZ];
    r_cont_degree6[i] = new double****[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      other_cont_degree3[i][j] = new double[CONT_SZ];
      r_cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      other_cont_degree4[i][j] = new double*[CONT_SZ];
      r_cont_degree4[i][j] = new double*[CONT_SZ];
      cont_degree5[i][j] = new double**[CONT_SZ];
      other_cont_degree5[i][j] = new double**[CONT_SZ];
      r_cont_degree5[i][j] = new double**[CONT_SZ];
      cont_degree6[i][j] = new double***[CONT_SZ];
      other_cont_degree6[i][j] = new double***[CONT_SZ];
      r_cont_degree6[i][j] = new double***[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        cont_degree5[i][j][k] = new double*[CONT_SZ];
        other_cont_degree5[i][j][k] = new double*[CONT_SZ];
        r_cont_degree5[i][j][k] = new double*[CONT_SZ];
        cont_degree6[i][j][k] = new double**[CONT_SZ];
        other_cont_degree6[i][j][k] = new double**[CONT_SZ];
        r_cont_degree6[i][j][k] = new double**[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
          cont_degree5[i][j][k][l] = new double[CONT_SZ];
          other_cont_degree5[i][j][k][l] = new double[CONT_SZ];
          r_cont_degree5[i][j][k][l] = new double[CONT_SZ];
          cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          other_cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          r_cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          for (int p = 0; p < CONT_SZ; p++) {
            cont_degree5[i][j][k][l][p] = 0;
            other_cont_degree5[i][j][k][l][p] = 0;
            r_cont_degree5[i][j][k][l][p] = 0;
            cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            other_cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            r_cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            for (int q = 0; q < CONT_SZ; q++) {
              cont_degree6[i][j][k][l][p][q] = 0;
              other_cont_degree6[i][j][k][l][p][q] = 0;
              r_cont_degree6[i][j][k][l][p][q] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
      cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
      other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 3
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, other_const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other_" + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=other_const_compressionMap)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree5[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree6[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
      for (int j = 0; j < CONT_SZ; j++) {
          for (int k = 0; k < CONT_SZ; k++) {
              for (int l = 0; l < CONT_SZ; l++) {
                  for (int p = 0; p < CONT_SZ; p++) {
                      delete[] cont_degree6[i][j][k][l][p];
                      delete[] other_cont_degree6[i][j][k][l][p];
                      delete[] r_cont_degree6[i][j][k][l][p];
                  }
                  delete[] cont_degree5[i][j][k][l];
                  delete[] other_cont_degree5[i][j][k][l];
                  delete[] r_cont_degree5[i][j][k][l];
                  delete[] cont_degree6[i][j][k][l];
                  delete[] other_cont_degree6[i][j][k][l];
                  delete[] r_cont_degree6[i][j][k][l];
              }
              delete[] cont_degree4[i][j][k];
              delete[] other_cont_degree4[i][j][k];
              delete[] r_cont_degree4[i][j][k];
              delete[] cont_degree5[i][j][k];
              delete[] other_cont_degree5[i][j][k];
              delete[] r_cont_degree5[i][j][k];
              delete[] cont_degree6[i][j][k];
              delete[] other_cont_degree6[i][j][k];
              delete[] r_cont_degree6[i][j][k];
          }
          delete[] cont_degree3[i][j];
          delete[] other_cont_degree3[i][j];
          delete[] r_cont_degree3[i][j];
          delete[] cont_degree4[i][j];
          delete[] other_cont_degree4[i][j];
          delete[] r_cont_degree4[i][j];
          delete[] cont_degree5[i][j];
          delete[] other_cont_degree5[i][j];
          delete[] r_cont_degree5[i][j];
          delete[] cont_degree6[i][j];
          delete[] other_cont_degree6[i][j];
          delete[] r_cont_degree6[i][j];
      }
      delete[] cont_degree2[i];
      delete[] other_cont_degree2[i];
      delete[] r_cont_degree2[i];
      delete[] cont_degree3[i];
      delete[] other_cont_degree3[i];
      delete[] r_cont_degree3[i];
      delete[] cont_degree4[i];
      delete[] other_cont_degree4[i];
      delete[] r_cont_degree4[i];
      delete[] cont_degree5[i];
      delete[] other_cont_degree5[i];
      delete[] r_cont_degree5[i];
      delete[] cont_degree6[i];
      delete[] other_cont_degree6[i];
      delete[] r_cont_degree6[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  delete[] cont_degree3;
  delete[] other_cont_degree3;
  delete[] r_cont_degree3;
  delete[] cont_degree4;
  delete[] other_cont_degree4;
  delete[] r_cont_degree4;
  delete[] cont_degree5;
  delete[] other_cont_degree5;
  delete[] r_cont_degree5;
  delete[] cont_degree6;
  delete[] other_cont_degree6;
  delete[] r_cont_degree6;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/PR3A.cpp", code)
  }


  def TTM(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "TTM_DP" else if (structure == "fixed_j") "TTM_J" else if (structure == "uhc") "TTM_UT" else "TTM"
    val outName = if(sparse) s"${outName1}_Sparse" else outName1
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]),N = atoi(argv[2]), Q = atoi(argv[3]), P = atoi(argv[4]);
    ${if (structure == "fixed_j") "int J = atoi(argv[5]);" else ""}
    
     /*
        M : third dimension in B, A (i)    
        N : rows in B, A (j)
        Q : columns in B, columns in C (l)

        P : rows  in C (k)

        A(i, j,k) = B(i,j,l),C(k,l)
    */

    ${if (sparse) {
s"""
    ${if (structure == "diag_p" || structure == "fixed_j") "double *B = new double[M * Q];" else if (structure == "uhc") "double *B = new double[((N + 1) * N / 2 - (N - M + 1) * (N - M) / 2) * Q];"}
    for (size_t i = 0; i < M; ++i) {
      ${if (structure == "uhc") "for (size_t j = i; j < N; ++j) {" else ""}
        for(size_t l = 0; l < Q; ++l) {
          ${if (structure == "diag_p" || structure == "fixed_j") "B[i * Q + l]" else if (structure == "uhc") "B[(i * N + j - ((i + 1) * i / 2)) * Q + l]"} = (double) (rand() % 1000000) / 1e6;
        }
      ${if (structure == "uhc") "}" else ""}
    }
"""
    } else {
s"""
    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            B[i][j] = new double[Q];
            for(size_t l =0; l< Q; ++l){
                ${if (structure == "diag_p") "if (i == j){" else if (structure == "fixed_j") "if (j == J){" else if (structure == "uhc") "if (i <= j){" else ""}
                    B[i][j][l] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][j][l] = (double) 0;
                }
            }
        }
    }
"""      
    }}

    double  **C = new double*[P];
    for(size_t k = 0; k < P; ++k){
        C[k] = new double[Q];
        for(size_t l = 0; l < Q; ++l){
            C[k][l] = (double) (rand() % 1000000) / 1e6;
        }
    }


    double  ***A = new double**[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            A[i][j] = new double[P];
            for(size_t k =0; k < P; ++k){
                A[i][j][k] = (double) 0;
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = ttm(structure, 1, sparse)
    val c3 =
s"""
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][N - 1][P - 1] << "\\n";
    cout << time;
    ${if (sparse) "" else {
s"""
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
"""
    }}
    delete[] B;

    for(size_t k = 0; k < P; ++k){
        delete[] C[k];
    }
    delete[] C;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
    
    return 0; 
}
"""

    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def THP(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "THP_DP" else if (structure == "fixed_i") "THP_I" else if (structure == "fixed_j") "THP_J" else "THP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = 
s"""
#include <array>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    
    srand(0);
    int M = atoi(argv[1]), N = atoi(argv[2]), P = atoi(argv[3]);
    ${if (structure == "fixed_i") "int I = atoi(argv[4]);" else if (structure == "fixed_j") "int J = atoi(argv[4]);" else ""}
    
    /*
        M : third dimension (i) in B, C, A
        N : first dimension (j) in B, C, A
        P : second dimension (k) in B, C, A

        A(i,j,k) = B(i,j,k),C(i,j,k)
    */

    ${if (sparse) {
s"""
    double *B = new double${if (structure == "diag_p" || structure == "fixed_j") "[M * P];" else if (structure == "fixed_i") "[N * P];"}
    ${if (structure == "diag_p" || structure == "fixed_j") "for (size_t i = 0; i < M; ++i){" else ""}
      ${if (structure == "diag_p" || structure == "fixed_j") "" else "for(size_t j = 0; j < N; ++j){"}
        for(size_t k =0; k< P; ++k){
          ${if (structure == "diag_p" || structure == "fixed_j") "B[i * P + k]" else "B[j * P + k]"} = (double) (rand() % 1000000) / 1e6;
        }
      }
"""
    } else {
s"""
    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            B[i][j] = new double[P];
            for(size_t k =0; k< P; ++k){
                ${if (structure == "diag_p") "if (i == j){" else if (structure == "fixed_i") "if (i == I){" else if (structure == "fixed_j") "if (j == J){" else "THP"}
                    B[i][j][k] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][j][k] = (double) 0;
                }
            }
        }
    }
"""
    }}

    double  ***C = new double**[M];
    for(size_t i = 0; i < M; ++i){
        C[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            C[i][j] = new double[P];
            for(size_t k =0; k< P; ++k){
                C[i][j][k] = (double) (rand() % 1000000) / 1e6;
            }
        }
    }

    double  ***A = new double**[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            A[i][j] = new double[P];
            for(size_t k =0; k < P; ++k){
                (double) 0;
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = thp(structure, 1, sparse)
    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;
    
    cerr << A[M - 1][N - 1][P - 1] << "\\n";
    cout<<time;

    ${if (sparse) "" else {
s"""
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
"""
    }}
    delete[] B;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] C[i][j];
        }
        delete[] C[i];
    }
    delete[] C;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;

    return 0; 
}
"""

    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }


  def MTTKRP(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "fixed_ij") "MTTKRP_IJ" else if (structure == "fixed_i") "MTTKRP_I" else if (structure == "fixed_j") "MTTKRP_J" else "MTTKRP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]),N = atoi(argv[2]), P = atoi(argv[3]), Q = atoi(argv[4]);
    ${if (structure == "fixed_ij") "int I = atoi(argv[5]), J = atoi(argv[6]);" else if (structure == "fixed_i") "int I = atoi(argv[5]);" else if (structure == "fixed_j") "int J = atoi(argv[5]);" else ""}
    
     /*
        M : third dimension (k vec) in B,   --> rows in A 
        N : first dimension (i vec) in B,   --> rows in C
        P : second dimension (j vec) in B,  --> rows in D

        Q : columns  in C, D, and A 

        A(i, j) = B(i,k,l),C(k,j),D(l,j)
    */


    ${if (sparse && (structure == "fixed_i" || structure == "fixed_ij")) {
s"""
    double *B = new double[N * P];
    for (size_t k = 0; k < N; ++k){
        for (size_t l = 0; l < P; ++l){
            B[k * P + l] = (double) (rand() % 1000000) / 1e6;
        }
    }
"""
    } else {
s"""
    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t k = 0; k < N; ++k){
            B[i][k] = new double[P];
            for(size_t l =0; l< P; ++l){
                ${if (structure == "fixed_i" || structure == "fixed_ij") {
s"""
                if (i == I){
                    B[i][k][l] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][k][l] = (double) 0;
                }
"""
                } else {
                  "B[i][k][l] = (double) (rand() % 1000000) / 1e6;"
                }}
            }
        }
    }
"""
    }}

    double  **C = new double*[N];
    for(size_t k = 0; k < N; ++k){
        C[k] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            C[k][j] = (double) (rand() % 1000000) / 1e6;
        }
    }

    ${if (sparse && (structure == "fixed_j" || structure == "fixed_ij")) {
s"""
    double *D = new double[P];
    for (size_t l = 0; l < P; ++l){
        D[l] = (double) (rand() % 1000000) / 1e6;
    }
"""
    } else {
s"""
    double  **D = new double*[P];
    for(size_t l = 0; l < P; ++l){
        D[l] = new double[Q];
        for(size_t j = 0; j < Q; j++){
            ${if (structure == "fixed_j" || structure == "fixed_ij") {
s"""
            if(j == J){
                D[l][j] = (double) (rand() % 1000000) / 1e6;
            }
            else{
                D[l][j] = (double) 0;

            }
"""
            } else "D[l][j] = (double) (rand() % 1000000) / 1e6;"}
        }
    }
"""
    }}

    double  **A = new double*[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            A[i][j] = (double) 0;
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = mttkrp_n(structure, 1, sparse)
    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][Q - 1] << "\\n";
    cout<<time;
   

    ${if (sparse && (structure == "fixed_i" || structure == "fixed_ij")) "" else {
s"""
    for(size_t i = 0; i < P; i++){
        for(size_t j = 0; j < N; j++){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
"""
    }}
    delete[] B;
    
    for(size_t i = 0; i < N; i++){
        delete[] C[i];
    }
    delete[] C;

    ${if (sparse && (structure == "fixed_j" || structure == "fixed_ij")) "" else {
s"""
    for(size_t i = 0; i < P; i++){
        delete[] D[i];
    }
"""
    }}
    delete[] D;

    for(size_t i = 0; i < M; i++){
        delete[] A[i];
    }
    delete[] A;
    return 0; 
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }


  def E2E_PRK(k: Int) = {
    val code = e2ePRkWithSkeletone(k)
    val outName = "E2E_R"
    write2File(s"outputs/$outName.hpp", code)
  }


  def oneDConvolution(mode: Int = 0, sparse: Boolean = false) = {
    val head: Access = Access("Y", Seq("i".toVar), Tensor)
    val var1: Access = Access("H",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("X",  Seq("j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq(Arithmetic("-", Arithmetic("+", "M".toVar, "N".toVar), ConstantInt(1)), "N".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1ExpUS1: Exp = Comparison(">", "M".toVar, "i".toVar)
    val var1ExpUS2: Exp = Comparison("=", ConstantInt(0), "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
    val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1ExpRM1: Exp = Comparison("<=", ConstantInt(1), "j".toVar)
    val var1ExpRM2: Exp = Comparison("<=", "j".toVar, "i".toVar)
    val var1ExpRM3: Exp = Comparison(">", Arithmetic("+", "j".toVar, "M".toVar), "i".toVar)
    val var1ExpRM4: Exp = Comparison("=", ConstantInt(0), "j".toVar.redundancyVars)
    val var1ExpRM5: Exp = Comparison("=", Arithmetic("-", "i".toVar, "j".toVar), "i".toVar.redundancyVars)
    val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3, var1ExpRM4, var1ExpRM5))
    val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(x(0))

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()
    
    println(infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)._1.prettyFormat)

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, varReverse=true))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, varReverse=true)
  }

  def ODC(sparse: Boolean) = {
    val outName1 = "ODC"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
        val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]), N = atoi(argv[2]);

    ${if (sparse) 
s"""
    double *H = new double[M];
    for(size_t i = 0; i < M; ++i) {
        H[i] = (double) (rand() % 1000000) / 1e6;
    }
""" 
    else {
s"""
    double **H = new double*[M + N - 1];
    for(size_t i = 0; i < M + N - 1; ++i){
        H[i] = new double[N];
        for(size_t j = 0; j < N; ++j){
            if (j == 0 && i < M)
                H[i][j] = (double) (rand() % 1000000) / 1e6;
            else if (j <= i && i < M + j) 
                H[i][j] = H[i - j][0];
            else 
                H[i][j] = (double) 0;
        }
    }
"""
    }}

    double *X = new double[N];
    for(size_t j = 0; j < N; ++j){
        X[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *Y = new double[M + N - 1];
    for (size_t i = 0; i < M + N - 1; ++i) {
        Y[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = oneDConvolution(1, sparse)

    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << Y[M + N - 2] << "\\n";
    cout<<time;

    ${if (sparse) "" else 
s"""
    for(size_t i = 0; i < M + N - 1; ++i){
        delete[] H[i];
    }
""" }
    delete[] H;
    delete[] X;
    delete[] Y;
    return 0;
}
"""

    val code = s"$c1$c2$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def oneDCircularConvolution(mode: Int = 0, sparse: Boolean = false) = {
    val head: Access = Access("Y", Seq("i".toVar), Tensor)
    val var1: Access = Access("H",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("X",  Seq("j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("N".toVar, "N".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1ExpUS1: Exp = Comparison(">", "M".toVar, "i".toVar)
    val var1ExpUS2: Exp = Comparison("=", ConstantInt(0), "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
    val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1ExpRM1: Exp = Comparison("<=", ConstantInt(1), "j".toVar)
    val var1ExpRM2: Exp = Comparison("<=", "j".toVar, "s".toVar)
    val var1ExpRM3: Exp = Comparison(">", Arithmetic("+", "j".toVar, "M".toVar), "s".toVar)
    val var1ExpRM4: Exp = Comparison("=", Arithmetic("%", "s".toVar, "N".toVar), "i".toVar)
    val var1ExpRM5: Exp = Comparison("=", ConstantInt(0), "j".toVar.redundancyVars)
    val var1ExpRM6: Exp = Comparison("=", Arithmetic("-", "s".toVar, "j".toVar), "i".toVar.redundancyVars)
    val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3, var1ExpRM4, var1ExpRM5, var1ExpRM6))
    val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(Arithmetic("-", "s".toVar, x(1)))

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, varReverse=true))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, varReverse=true)
  }

  // 1D circular convolution
  def ODCC(sparse: Boolean) = {
    val outName1 = "ODCC"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
        val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]), N = atoi(argv[2]);

    ${if (sparse) 
s"""
    double *H = new double[M];
    for(size_t i = 0; i < M; ++i) {
        H[i] = (double) (rand() % 1000000) / 1e6;
    }
""" 
    else {
s"""
    double **H = new double*[N];
    for (size_t i = 0; i < N; ++i) {
        H[i] = new double[N];
        for (size_t j = 0; j < N; ++j) {
            H[i][j] = (double) 0;
        }
    }
    for(size_t i = 0; i < M; ++i){
        H[i][0] = (double) (rand() % 1000000) / 1e6;
    }
    for (size_t j = 1; j < N; ++j) {
        for (size_t s = j; s < j + M; ++s) {
            size_t i = s % N;
            H[i][j] = H[s - j][0];
        }
    }
"""
    }}

    double *X = new double[N];
    for(size_t j = 0; j < N; ++j){
        X[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *Y = new double[N];
    for (size_t i = 0; i < N; ++i) {
        Y[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = oneDCircularConvolution(1, sparse)

    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << Y[N - 1] << "\\n";
    cout<<time;

    ${if (sparse) "" else 
s"""
    for(size_t i = 0; i < N; ++i){
        delete[] H[i];
    }
""" }
    delete[] H;
    delete[] X;
    delete[] Y;
    return 0;
}
"""

    val code = s"$c1$c2$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def populationGrowthLeslieMatrix(mode: Int = 0, sparse: Boolean = false) = {
    val head: Access = Access("M", Seq("i".toVar), Tensor)
    val var1: Access = Access("L",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("N",  Seq("j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("W".toVar, "W".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("W".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1ExpUS1: Exp = Comparison("=", ConstantInt(0), "i".toVar)
    val var1ProdsUS1: Prod = Prod(Seq(var1ExpUS1))
    val var1ExpUS2: Exp = Comparison("<=", ConstantInt(1), "i".toVar)
    val var1ExpUS3: Exp = Comparison("=", Arithmetic("-", "i".toVar, ConstantInt(1)), "j".toVar)
    val var1ProdsUS2: Prod = Prod(Seq(var1ExpUS2, var1ExpUS3))
    val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS1, var1ProdsUS2))))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => x

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap)
  }

  def PGLM(sparse: Boolean) = {
    val outName1 = "PGLM"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
        val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int W = atoi(argv[1]);

    ${if (sparse) 
s"""
    double *L1 = new double[W];
    double *L2 = new double[W - 1];
    for(size_t i = 0; i < W; ++i) {
        L1[i] = (double) (rand() % 1000000) / 1e6;
    }
    for(size_t i = 0; i < W - 1; ++i) {
        L2[i] = (double) (rand() % 1000000) / 1e6;
    }
""" 
    else {
s"""
    double **L = new double*[W];
    for (size_t i = 0; i < W; ++i) {
        L[i] = new double[W];
        for (size_t j = 0; j < W; ++j) {
            L[i][j] = (double) 0;
        }
    }
    for(size_t i = 0; i < W; ++i) {
        L[0][i] = (double) (rand() % 1000000) / 1e6;
    }
    for(size_t i = 1; i < W; ++i) {
        L[i][i - 1] = (double) (rand() % 1000000) / 1e6;
    }
"""
    }}

    double *N = new double[W];
    for(size_t j = 0; j < W; ++j){
        N[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *M = new double[W];
    for (size_t i = 0; i < W; ++i) {
        M[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = populationGrowthLeslieMatrix(1, sparse)

    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << M[W - 1] << "\\n";
    cout<<time;

    ${if (sparse) 
s"""
    delete[] L1;
    delete[] L2; 
""" 
    else 
s"""
    for(size_t i = 0; i < W; ++i){
        delete[] L[i];
    }
    delete[] L;
""" }
    delete[] N;
    delete[] M;
    return 0;
}
"""

    val code = s"$c1$c2$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def MLIR_init_code(): String = s"""
"builtin.module"() ({
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "puts", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "atoi", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "srand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i32), sym_name = "rand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "print_i32", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (), sym_name = "print_i64", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (f64) -> (), sym_name = "print_f64_cerr", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i64), sym_name = "timer", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (i64), sym_name = "timer_elapsed", sym_visibility = "private"} : () -> ()

  "func.func"() ({
    ^bb0(%argc : i32, %argv : !llvm.ptr<!llvm.ptr<i8>>):
    %0 = "arith.constant"() {"value" = 0 : index} : () -> index
    %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
    %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
    %1 = "arith.constant"() {"value" = 1 : index} : () -> index
    %oi1 = "arith.constant"() {"value" = 1 : i1} : () -> i1
    %oi0 = "arith.constant"() {"value" = 0 : i1} : () -> i1
    "func.call"(%zi32) {callee = @srand} : (i32) -> ()
    %1000000 = "arith.constant"() {"value" = 1000000 : i32} : () -> i32
    %f1000000 = "arith.constant"() {"value" = 1000000.0 : f64} : () -> f64
"""

  def MLIR_read_argv(argv_names: Seq[String]): String = {
    argv_names.zipWithIndex.foldLeft("")((acc, nameId) => {
      val (name, i) = nameId
      val id = i + 1
      acc + s"""
    %argvv$id = llvm.getelementptr %argv[$id] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv$id = "llvm.load"(%argvv$id) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %${name}i32 = "func.call"(%argv$id) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %$name = arith.index_cast %${name}i32 : i32 to index
"""
    })
  }

  def MLIR_gen_random_number(var_name: String, dimensions: Seq[String], condition: (Int, String, Any, Int)): String = {
    val ivars_nostr = dimensions.map(e => getVar("%i"))
    val cond3 = if (condition._3.isInstanceOf[Int]) ivars_nostr(condition._3.asInstanceOf[Int]) else s"%${condition._3.asInstanceOf[String]}"
    val c0 = if (condition._1 == -1) "" else s"""
    %${condition._2} = "arith.cmpi"(${ivars_nostr(condition._1)}, ${cond3}) {predicate = ${condition._4} : i64} : (index, index) -> i1   
"""
    val c1 = dimensions.zipWithIndex.foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      acc + s"""
    "scf.for"(%0, %$dim, %1) ({
    ^bb0(${ivars_nostr(i)}: index):
"""
    })
    val ivars = ivars_nostr.mkString(", ")
    val qvars = dimensions.map(e => s"?").mkString("x") + "x"
    val index_vars = dimensions.map(e => s"index").mkString(", ")

    val rval1 = getVar("rval")
    val rval2 = getVar("rval")
    val rval3 = getVar("rval")
    val rval4 = getVar("rval")
    val c2 = s"""
    "scf.if"(%${condition._2}) ({
      %$rval1 = "func.call"() {callee = @rand} : () -> i32
      %$rval2 = "arith.remui"(%$rval1, %1000000) : (i32, i32) -> i32
      %$rval3 = "arith.sitofp"(%$rval2) : (i32) -> f64
      %$rval4 = "arith.divf"(%$rval3, %f1000000) : (f64, f64) -> f64
      "memref.store"(%$rval4, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()
"""
    val c3 = dimensions.foldLeft("")((acc, dim) => {
      acc + s"""
    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()
"""
    })
    return c1 + c0 + c2 + c3
  }

  def MLIR_start_timer_code(): String = s"""
    %stime = "func.call"() {callee = @timer} : () -> i64
"""

  def MLIR_end_code(cerr_load: String = ""): String = {
    s"""
    %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
    ${cerr_load}
    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
"""
  }

  def getDefaultCondition(condName: String): (Int, String, String, Int) = (-1, condName, "", -1)

  def MTTKRP_MLIR(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "fixed_ij") "MTTKRP_IJ" else if (structure == "fixed_i") "MTTKRP_I" else if (structure == "fixed_j") "MTTKRP_J" else "MTTKRP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = MLIR_init_code()
    val argv_names = if (structure == "fixed_ij") Seq("M", "N", "P", "Q", "I", "J") else if (structure == "fixed_i") Seq("M", "N", "P", "Q", "I") else if (structure == "fixed_j") Seq("M", "N", "P", "Q", "J") else Seq("M", "N", "P", "Q")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %A = memref.alloc(%M, %Q) : memref<?x?xf64>
    %B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %C = memref.alloc(%N, %Q) : memref<?x?xf64>
    %D = memref.alloc(%P, %Q) : memref<?x?xf64>
"""
    val condition1 = if (structure == "fixed_ij" || structure == "fixed_i") (0, getVar("gen_cond"), "I", 0) else getDefaultCondition("oi1")
    val c4 = MLIR_gen_random_number("B", Seq("M", "N", "P"), condition1)
    val c5 = MLIR_gen_random_number("C", Seq("N", "Q"), getDefaultCondition("oi1"))
    val condition2 = if (structure == "fixed_ij" || structure == "fixed_j") (1, getVar("gen_cond"), "J", 0) else getDefaultCondition("oi1")
    val c6 = MLIR_gen_random_number("D", Seq("P", "Q"), condition2)
    val c7 = MLIR_gen_random_number("A", Seq("M", "Q"), getDefaultCondition("oi0"))
    val c8 = MLIR_start_timer_code()
    val c9 = mttkrp_n(structure, 1, sparse, "MLIR")
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c10 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def TTM_MLIR(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "TTM_DP" else if (structure == "fixed_j") "TTM_J" else if (structure == "uhc") "TTM_UT" else "TTM"
    val outName = if(sparse) s"${outName1}_Sparse" else outName1
    val c1 = MLIR_init_code()
    val argv_names = if (structure == "fixed_j") Seq("M", "N", "Q", "P", "J") else Seq("M", "N", "Q", "P")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %A = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %B = memref.alloc(%M, %N, %Q) : memref<?x?x?xf64>
    %C = memref.alloc(%P, %Q) : memref<?x?xf64>
"""
    val condition1 = if (structure == "diag_p") (0, getVar("gen_cond"), 1, 0) else if (structure == "fixed_j") (1, getVar("gen_cond"), "J", 0) else if (structure == "uhc") (0, getVar("gen_cond"), 1, 3) else getDefaultCondition("oi1")
    val c4 = MLIR_gen_random_number("B", Seq("M", "N", "Q"), condition1)
    val c5 = MLIR_gen_random_number("C", Seq("P", "Q"), getDefaultCondition("oi1"))
    val c6 = MLIR_gen_random_number("A", Seq("M", "N", "P"), getDefaultCondition("oi0"))
    val c7 = MLIR_start_timer_code()
    val c8 = ttm(structure, 1, sparse, "MLIR")
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
"""
    val c9 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def THP_MLIR(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "THP_DP" else if (structure == "fixed_i") "THP_I" else if (structure == "fixed_j") "THP_J" else "THP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = MLIR_init_code()
    val argv_names = if (structure == "fixed_i") Seq("M", "N", "P", "I") else if (structure == "fixed_j") Seq("M", "N", "P", "J") else Seq("M", "N", "P")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %A = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %C = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
"""
    val condition1 = if (structure == "diag_p") (0, getVar("gen_cond"), 1, 0) else if (structure == "fixed_i") (0, getVar("gen_cond"), "I", 0) else if (structure == "fixed_j") (1, getVar("gen_cond"), "J", 0) else getDefaultCondition("oi1")
    val c4 = MLIR_gen_random_number("B", Seq("M", "N", "P"), condition1)
    val c5 = MLIR_gen_random_number("C", Seq("M", "N", "P"), getDefaultCondition("oi1"))
    val c6 = MLIR_gen_random_number("A", Seq("M", "N", "P"), getDefaultCondition("oi0"))
    val c7 = MLIR_start_timer_code()
    val c8 = thp(structure, 1, sparse, "MLIR")
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
"""
    val c9 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def LRC_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "LRC_Sparse" else "LRC"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c6 = MLIR_start_timer_code()
    val allDegs = (2 to 2)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c7 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c8 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def PR2C_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "PR2C_Sparse" else "PR2C"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %cont_degree3 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?xf64>
    %cont_degree4 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c6 = MLIR_gen_random_number("cont_degree3", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c7 = MLIR_gen_random_number("cont_degree4", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c8 = MLIR_start_timer_code()
    val allDegs = (2 to 4)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c9 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last2 = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
    "func.call"(%last2) {callee = @print_f64_cerr} : (f64) -> ()
    %last3 = "memref.load"(%cont_degree3, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
    "func.call"(%last3) {callee = @print_f64_cerr} : (f64) -> ()
    %last = "memref.load"(%cont_degree4, %0, %0, %0, %0) : (memref<?x?x?x?xf64>, index, index, index, index) -> f64
"""
    val c10 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def PR3C_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "PR3C_Sparse" else "PR3C"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %cont_degree3 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?xf64>
    %cont_degree4 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?xf64>
    %cont_degree5 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?x?xf64>
    %cont_degree6 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?x?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c6 = MLIR_gen_random_number("cont_degree3", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c7 = MLIR_gen_random_number("cont_degree4", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c8 = MLIR_gen_random_number("cont_degree5", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c9 = MLIR_gen_random_number("cont_degree6", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c10 = MLIR_start_timer_code()
    val allDegs = (2 to 6)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c11 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last2 = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
    "func.call"(%last2) {callee = @print_f64_cerr} : (f64) -> ()
    %last3 = "memref.load"(%cont_degree3, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
    "func.call"(%last3) {callee = @print_f64_cerr} : (f64) -> ()
    %last4 = "memref.load"(%cont_degree4, %0, %0, %0, %0) : (memref<?x?x?x?xf64>, index, index, index, index) -> f64
    "func.call"(%last4) {callee = @print_f64_cerr} : (f64) -> ()
    %last5 = "memref.load"(%cont_degree5, %0, %0, %0, %0, %0) : (memref<?x?x?x?x?xf64>, index, index, index, index, index) -> f64
    "func.call"(%last5) {callee = @print_f64_cerr} : (f64) -> ()
    %last = "memref.load"(%cont_degree6, %0, %0, %0, %0, %0, %0) : (memref<?x?x?x?x?x?xf64>, index, index, index, index, index, index) -> f64
"""
    val c12 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10\n$c11\n$c12"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def LRA_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "LRA_Sparse" else "LRA"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %other_cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %other_cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("other_cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c6 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c7 = MLIR_gen_random_number("other_cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    
    val k = 1
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c8 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val c9 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, sparse, codeLang="MLIR")}")

    val c10 = MLIR_start_timer_code()
    val c11 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c12 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10\n$c11\n$c12"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }


  val help: String = s"""
Please specify the experiment name and select whether you want sparse datalayout for the input [use `sbt "run <exp> [sparse]"`]:
LRC       = Linear Regression - Creation
PR2C      = Polynomial Regression Degree 2 - Creation
PR3C      = Polynomial Regression Degree 3 - Creation
LRA       = Linear Regression - Addition
PR2A      = Polynomial Regression Degree 2 - Addition
PR3A      = Polynomial Regression Degree 3 - Addition
TTM_DP    = TTM: Diagonal (Plane)
TTM_J     = TTM: Fixed j
TTM_UT    = TTM: Upper Triangular (Half-cube)
THP_DP    = THP: Diagonal (Plane)
THP_I     = THP: Fixed i
THP_J     = THP: Fixed j
MTTKRP_IJ = MTTKRP: Fixed i & j
MTTKRP_I  = MTTKRP: Fixed i
MTTKRP_J  = MTTKRP: Fixed j
E2E_LR    = E2E - Linear Regression
E2E_PR2   = E2E - Polynomial Regression Degree 2
ODC       = One-Dimensional Convolution
ODCC      = One-Dimensional Circular Convolution
PGLM      = Population Growth Leslie Matrix
"""
  if (args.length >= 1) {
    val sparse: Boolean = if (args.length >= 2 && (args(1).toLowerCase() == "sparse" || args(1).toLowerCase() == "s" || args(1).toLowerCase() == "-s") ) true else false
    val codeLang: String = if (args.length >= 3) args(2) else "CPP"
    if (codeLang == "CPP") {
      args(0) match {
        case "LRC" => LRC()
        case "PR2C" => PR2C()
        case "PR3C" => PR3C()
        case "LRA" => LRA()
        case "PR2A" => PR2A()
        case "PR3A" => PR3A()
        case "TTM_DP" => TTM("diag_p", sparse)
        case "TTM_J" => TTM("fixed_j", sparse)
        case "TTM_UT" => TTM("uhc", sparse)
        case "THP_DP" => THP("diag_p", sparse)
        case "THP_I" => THP("fixed_i", sparse)
        case "THP_J" => THP("fixed_j", sparse)
        case "MTTKRP_IJ" => MTTKRP("fixed_ij", sparse)
        case "MTTKRP_I" => MTTKRP("fixed_i", sparse)
        case "MTTKRP_J" => MTTKRP("fixed_j", sparse)
        case "E2E_LR" => E2E_PRK(1)
        case "E2E_PR2" => E2E_PRK(2)
        case "ODC" => ODC(sparse)
        case "ODCC" => ODCC(sparse)
        case "PGLM" => PGLM(sparse)
        case _ => println(help)
      }
    } else if (codeLang == "MLIR") {
      args(0) match {
        case "LRC" => LRC_MLIR()
        case "PR2C" => PR2C_MLIR()
        case "PR3C" => PR3C_MLIR()
        case "LRA" => LRA_MLIR()
        // case "PR2A" => PR2A_MLIR()
        // case "PR3A" => PR3A_MLIR()
        case "TTM_DP" => TTM_MLIR("diag_p", sparse)
        case "TTM_J" => TTM_MLIR("fixed_j", sparse)
        case "TTM_UT" => TTM_MLIR("uhc", sparse)
        case "THP_DP" => THP_MLIR("diag_p", sparse)
        case "THP_I" => THP_MLIR("fixed_i", sparse)
        case "THP_J" => THP_MLIR("fixed_j", sparse)
        case "MTTKRP_IJ" => MTTKRP_MLIR("fixed_ij", sparse)
        case "MTTKRP_I" => MTTKRP_MLIR("fixed_i", sparse)
        case "MTTKRP_J" => MTTKRP_MLIR("fixed_j", sparse)
        // case "E2E_LR" => E2E_PRK_MLIR(1)
        // case "E2E_PR2" => E2E_PRK_MLIR(2)
        // case "ODC" => ODC_MLIR(sparse)
        // case "ODCC" => ODCC_MLIR(sparse)
        // case "PGLM" => PGLM_MLIR(sparse)
        case _ => println(help)
      }
    } else println(help)
  } else println(help)
  

  // println(Variable("a").equals(Variable("a")))

  // val a: Map[String, Seq[Int]] = Map("a" -> Seq(2))
  // println(a.getOrElse("b", 12))
  // val b: Map[String, Seq[Int]] = Map("a" -> Seq(3))
  // println(mergeMap(Seq(a, b))((v1, v2) => v1 ++ v2))

}