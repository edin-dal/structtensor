sealed trait Exp {
  def prettyFormat(): String
  def cFormat(): String
}

sealed trait Index {
  def prettyFormat(): String
  def cFormat(): String
}

sealed trait Dim extends Index

sealed trait AccessType {
  def prettyFormat(): String
  def cFormat(): String
}

case object Tensor extends AccessType {
  def prettyFormat(): String = "T"
  def cFormat(): String = "T"
}

case object CompressedTensor extends AccessType {
  def prettyFormat(): String = "C"
  def cFormat(): String = "C"
}

case object UniqueSet extends AccessType {
  def prettyFormat(): String = "U"
  def cFormat(): String = "U"
}

case object RedundancyMap extends AccessType {
  def prettyFormat(): String = "R"
  def cFormat(): String = "R"
}


case class Variable(name: String) extends Index with Dim {
  def prettyFormat(): String = name
  def cFormat(): String = if (name.endsWith("'")) name.substring(0, name.size - 1) + "p" else name // renames redundancy vars to a writable format in C
}

case class ConstantDouble(value: Double) extends Index {
  def prettyFormat(): String = value.toString
  def cFormat(): String = value.toString
}

case class ConstantInt(value: Int) extends Index with Dim {
  def prettyFormat(): String = value.toString
  def cFormat(): String = value.toString
}

case class Arithmetic(op: String, index1: Index, index2: Index) extends Index with Dim {
  def prettyFormat(): String = s"(${index1.prettyFormat} $op ${index2.prettyFormat})"
  def cFormat(): String = s"(${index1.cFormat} $op ${index2.cFormat})"
}

case class Access(name: String, vars: Seq[Variable], kind: AccessType) extends Exp {
  def prettyFormat(): String = {
    val pr = vars.foldLeft("")((acc, cur) => s"$acc, ${cur.prettyFormat}")
    if (pr == "") name else s"${name}(${pr.substring(2, pr.length)})"
  }
  def cFormat(): String = vars.foldLeft(name)((acc, cur) => s"$acc[${cur.cFormat}]")
  def cRedFormat(): String = vars.foldLeft(name)((acc, cur) => s"$acc[${cur.cFormat}p]")  // renames redundancy vars to a writable format in C
}

case class Comparison(op: String, index: Index, variable: Variable) extends Exp {
  def prettyFormat(): String = if (!(!index.isInstanceOf[Variable] && op == "=")) s"(${index.prettyFormat} $op ${variable.prettyFormat})" else s"(${variable.prettyFormat} $op ${index.prettyFormat})"
  def cFormat(): String = if (!(!index.isInstanceOf[Variable] && op == "=")) s"(${index.cFormat} $op ${variable.cFormat})" else s"(${variable.cFormat} $op ${index.cFormat})"
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
  
}

case class SoP(prods: Seq[Prod]) {
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
}

case class Rule(head: Access, body: SoP) {
  def prettyFormat(): String = s"${head.prettyFormat} := ${body.prettyFormat}"
  def cFormat(): String = s"${head.cFormat} = ${body.cFormat}"
  def cPeqFormat(): String = s"${head.cFormat} += ${body.cFormat};"
}

case class Interval(begin: Seq[Index], end: Seq[Index])

case class DimInfo(access: Access, dims: Seq[Dim]) // how to assert that dims.size == access.vars.size?

object Main extends App {

  def emptyProd(): Prod = Prod(Seq[Exp]())

  def emptySoP(): SoP = SoP(Seq[Prod]())

  def emptyRule(): Rule = Rule(Access("", Seq[Variable](), Tensor), emptySoP())

  def emptyDimInfo(): DimInfo = DimInfo(Access("", Seq.empty[Variable], Tensor), Seq.empty[Dim])

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
      case _ => dim1 // random output
    }
  }

  def dimMax(dim1: Dim, dim2: Dim): Dim = {
    (dim1, dim2) match {
      case (Variable(name), Arithmetic(op, index1, index2)) => if (op == "+" && ((index1.isInstanceOf[Variable] && index1.asInstanceOf[Variable] == dim1) || (index2.isInstanceOf[Variable] && index2.asInstanceOf[Variable] == dim1))) dim2 else dim2 // this is just random else which is false
      case (Arithmetic(op, index1, index2), Variable(name)) => dimMin(dim2, dim1)
      case _ => dim1 // random output
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

  def binMult(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val outDimInfo: DimInfo = getBinOpDimInfo(e1, e2, head, dimInfo, "mult")
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => {
        if (vars1.union(vars2).toSet == head.vars.toSet) {
          val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet) 
          val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet) 
          val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
          val e2RM: SoP = includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap) 
          if (isIntersectEmpty(vars1, vars2)) {
            if (name1 == name2) {
              val bodyUS: SoP = multSoP(Seq(e1US, e2US, SoP(Seq(vectorizeComparisonMultiplication("<=", vars1, vars2)))))
              val bodyRM: SoP = concatSoP(Seq(SoPTimesSoP(e1RM, e2RM), 
              multSoP(Seq(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1)))), e2RM)), 
              multSoP(Seq(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2)))), e1RM)), 
              multSoP(Seq(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp1RM.head.vars.diff(vars1)))), e2US, 
                          SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp2RM.head.vars.diff(vars2)))), 
                          SoP(Seq(vectorizeComparisonMultiplication(">", vars1, vars2)))))))
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
            } else {
              val bodyUS: SoP = if(vars2.length == 0) e1US else if (vars1.length == 0) e2US else SoPTimesSoP(e1US, e2US)
              val bodyRM: SoP = if(vars2.length == 0) e1RM else if (vars1.length == 0) e2RM else concatSoP(Seq(SoPTimesSoP(e1RM, e2RM), 
              SoPTimesSoP(SoPTimesSoP(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1))))), e2RM), 
              SoPTimesSoP(SoPTimesSoP(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2))))), e1RM)))
              println("binMultUS: ", Rule(headUS, bodyUS).prettyFormat)
              println("binMultRM: ", Rule(headRM, bodyRM).prettyFormat)
              println("binMultDimInfo: ", outDimInfo)
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
            }
          } else {
            val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e2US), SoPTimesSoP(e1RM, e2US), SoPTimesSoP(e1US, e2RM)))
            val bodyRM: SoP = SoPTimesSoP(e1RM, e2RM)
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
          }
        } else {
          val headP: Access = Access(head.name.redundancyVars.name, vars1.union(vars2), head.kind)
          val us_rm_dim: (Rule, Rule, DimInfo) = binMult(headP, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
          return project(head, dimInfo :+ us_rm_dim._3, headP, us_rm_dim._1, us_rm_dim._2)
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet)
        val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap)
        val bodyUS: SoP = SoPTimesSoP(e1US, SoP(Seq(Prod(Seq(e2)))))
        val bodyRM: SoP = SoPTimesSoP(e1RM, SoP(Seq(Prod(Seq(e2)))))
        return project(head, dimInfo, e1, Rule(headUS, bodyUS), Rule(headRM, bodyRM))
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binMult(head, dimInfo, e2, e1, inp2US, inp2RM, inp1US, inp1RM)
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
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
        } else {
          val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(inp1US.body, inp2US.body), SoPTimesSoP(inp1RM.body, inp2US.body), SoPTimesSoP(inp1US.body, inp2RM.body), SoP(Seq(Prod(Seq(e1, e2))))))
          val bodyRM: SoP = SoPTimesSoP(inp1RM.body, inp2RM.body)
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
        }
      }
    }
    (inp1US, inp1RM, emptyDimInfo)
  }

  def isSoPDisjoint(sop1: SoP, sop2: SoP): Boolean = {
    val sop: SoP = SoPTimesSoP(sop1, sop2)
    sop.prods.foldLeft(true)((acc, prod) => {
      val isPEmpty = prod.exps.foldLeft(false)((acc2, exp) => acc2 || prod.exps.foldLeft(false)((acc3, exp2) => acc3 || isProdEmpty(exp, exp2)))
      acc && isPEmpty
    })
  }

  def binAdd(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val outDimInfo: DimInfo = getBinOpDimInfo(e1, e2, head, dimInfo, "add")
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet) 
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet) 
        val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
        val e2RM: SoP = includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap) 
        if (vars1 == vars2) {
          if (isSoPEquals(e1US, e2US) && isSoPEquals(e1RM, e2RM)) {
            val bodyUS: SoP = e1US
            val bodyRM: SoP = e1RM
            println("binAddUS_SOPEQ: ", Rule(headUS, bodyUS).prettyFormat)
            println("binAddRM_SOPEQ: ", Rule(headRM, bodyRM).prettyFormat)
            println("binAddDimInfo_SOPEQ: ", outDimInfo)
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
          } else if (isSoPDisjoint(e1US, e2US) && isSoPDisjoint(e1RM, e2RM)) {
            val bodyUS: SoP = concatSoP(Seq(e1US, e2US))
            val bodyRM: SoP = concatSoP(Seq(e1RM, e2RM))
            println("binAddUS_SOP_Disjoint: ", Rule(headUS, bodyUS).prettyFormat)
            println("binAddRM_SOP_Disjoint: ", Rule(headRM, bodyRM).prettyFormat)
            println("binAddDimInfo_SOP_Disjoint: ", outDimInfo)
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
          } else {
            val bodyUS: SoP = concatSoP(Seq(e1US, e2US, e1RM, e2RM))
            val bodyRM: SoP = SoP(Seq())
            println("binAddUS_SOPNEQ: ", Rule(headUS, bodyUS).prettyFormat)
            println("binAddRM_SOPNEQ: ", Rule(headRM, bodyRM).prettyFormat)
            println("binAddDimInfo_SOPNEQ: ", outDimInfo)
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
          }
        } else { // a fake else
          val bodyUS: SoP = concatSoP(Seq(e1US, e2US, e1RM, e2RM))
          val bodyRM: SoP = SoP(Seq())
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binAdd(head, dimInfo, e2, e1, inp2US, inp2RM, inp1US, inp1RM)
      case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
        
      }
    }
    (inp1US, inp1RM, emptyDimInfo)
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

  def project(head: Access, dimInfo: Seq[DimInfo], e: Exp, inp1US: Rule, inp1RM: Rule): (Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    e match {
      case Access(nameE, varsE, Tensor) => {
        val outDimInfo: DimInfo = getProjectDimInfo(e.asInstanceOf[Access], head, dimInfo)
        val eUS: SoP = includeBoundaries(inp1US.body, bounds, e.asInstanceOf[Access], UniqueSet) 
        val eRM: SoP = includeBoundaries(inp1RM.body, bounds, e.asInstanceOf[Access], RedundancyMap) 
        if (varsE.toSet.subsetOf(outVars.toSet)) return (Rule(headUS, eUS), Rule(headRM, eRM), outDimInfo)
        else if(outVars.toSet.subsetOf(varsE.toSet)) {
          val bodyUS: SoP = concatSoP(Seq(eUS, eRM))
          val bodyRM: SoP = SoP(Seq())
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
        }
      }
      case Comparison(op, index, variable) => {

      }
    }
    (inp1US, inp1RM, emptyDimInfo)
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

  def shift(head: Access, dimInfo: Seq[DimInfo], e: Exp, eSeq: Seq[Comparison], inpUS: Rule, inpRM: Rule): (Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val minusVarMap: Map[Variable, Dim] = eSeq.map(comp => comp.index.asInstanceOf[Arithmetic].index1.asInstanceOf[Variable] -> comp.index.asInstanceOf[Arithmetic].index2.asInstanceOf[Dim]).toMap
    // println(minusVarMap)
    e match {
      case (Access(name, vars, Tensor)) => { 
        val eUS: SoP = includeBoundaries(inpUS.body, bounds, e.asInstanceOf[Access], UniqueSet) 
        val eRM: SoP = includeBoundaries(inpRM.body, bounds, e.asInstanceOf[Access], RedundancyMap) 
        val eDimSeq: Seq[Dim] = dimMap.get(e.asInstanceOf[Access]).getOrElse(Seq.empty)
        val headDimSeq: Seq[Dim] = (outVars zip eDimSeq).map{case (v, d) => if (minusVarMap.contains(v)) Arithmetic("+", d, minusVarMap.get(v).get) else d}
        // println(outVars)
        // println(headDimSeq)
        val headDimInfo: DimInfo = DimInfo(head, headDimSeq)
        val headDimSoP: SoP = headDimInfo.toSoP
        val headDimSoP2: SoP = SoP(Seq(Prod((outVars zip headDimSeq).foldLeft(Seq.empty[Exp])((acc, varDim) => if (varDim._2.isInstanceOf[Arithmetic]) acc :+ Comparison("<=", varDim._2.asInstanceOf[Arithmetic].index2, varDim._1) else acc))))
        // println(headDimSoP2.prettyFormat)
        val bodyUS: SoP = multSoP(Seq(eUS, SoP(Seq(Prod(eSeq))), headDimSoP, headDimSoP2))
        val bodyRM: SoP = multSoP(Seq(eRM, SoP(Seq(Prod(eSeq))), SoP(Seq(Prod(replaceVarsWithRedundancyVars(eSeq)))), headDimSoP, headDimSoP2))
        println("appendUS: ", Rule(headUS, bodyUS).prettyFormat)
        println("appendRM: ", Rule(headRM, bodyRM).prettyFormat)
        println("appendDimInfo: ", headDimInfo)
        return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), headDimInfo)
      }
    }
    (inpUS, inpRM, emptyDimInfo)
  }

  def binDirectSum(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, e2Seq: Seq[Comparison], inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet) 
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet) 
        val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
        val e2RM: SoP = includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap) 
        val e1DimSeq: Seq[Dim] = dimMap.get(e1.asInstanceOf[Access]).getOrElse(Seq.empty)
        val e2DimSeq: Seq[Dim] = dimMap.get(e2.asInstanceOf[Access]).getOrElse(Seq.empty)
        val headDimSeq: Seq[Dim] = (e1DimSeq zip e2DimSeq).foldLeft(Seq.empty[Dim])((acc, cur) => acc :+ Arithmetic("+", cur._1, cur._2))
        val headDimInfo: DimInfo = DimInfo(head, headDimSeq)
        val headDimSoP: SoP = headDimInfo.toSoP
        val headDimSoP2: SoP = SoP(Seq(Prod((outVars zip e1DimSeq).foldLeft(Seq.empty[Exp])((acc, varDim) => acc :+ Comparison("<=", varDim._2, varDim._1)))))
        val bodyUS: SoP = concatSoP(Seq(e1US, multSoP(Seq(e2US, SoP(Seq(Prod(e2Seq))), headDimSoP, headDimSoP2))))
        val bodyRM: SoP = concatSoP(Seq(e1RM, multSoP(Seq(e2RM, SoP(Seq(Prod(e2Seq))), SoP(Seq(Prod(replaceVarsWithRedundancyVars(e2Seq)))), headDimSoP, headDimSoP2))))
        return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), headDimInfo)
      }
    }
    (inp1US, inp1RM, emptyDimInfo)
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
  def mult(head: Access, dimInfo: Seq[DimInfo], eSeq: Seq[Exp], inpUSSeq: Seq[Rule], inpRMSeq: Seq[Rule]): (Rule, Rule, DimInfo) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    val accessFlag: Boolean = eSeq.foldLeft(true)((acc, cur) => acc && cur.isInstanceOf[Access])
    if (accessFlag) {
      val eAccessSeq: Seq[Access] = eSeq.map(e => e.asInstanceOf[Access])
      val nameSeq: Seq[String] = eAccessSeq.map(e => e.name)
      val varsSeq: Seq[Seq[Variable]] = eAccessSeq.map(e => e.vars)
      val eUS: Seq[SoP] = (inpUSSeq zip eAccessSeq).map{case (r, e) => includeBoundaries(r.body, bounds, e, UniqueSet)}
      val eRM: Seq[SoP] = (inpRMSeq zip eAccessSeq).map{case (r, e) => includeBoundaries(r.body, bounds, e, RedundancyMap)}
      val outDimInfo: DimInfo = getSelfProdDimInfo(eAccessSeq, head, dimInfo)
      val n: Int = eUS.length - 1
      val indSeq: Seq[Int] = (0 to n)
      if (isPairwiseIntersectEmpty(varsSeq)) {
        val nameFlag: Boolean = (0 to n - 1).foldLeft(true)((acc, i) => acc && nameSeq(i) == nameSeq(i + 1))
        if (nameFlag) {
          val eRed = (inpRMSeq zip varsSeq).map{case (r, v) => r.head.vars.diff(v)}
          val eUS_allvars: Seq[SoP] = (eUS zip varsSeq zip eRed).map{case ((us, v), red) => SoPTimesSoP(us, SoP(Seq(vectorizeComparisonMultiplication("=", v, red))))}
          val cRed: Seq[Seq[SoP]] = eRed.map(red => varsSeq.map(v => SoP(Seq(vectorizeComparisonMultiplication("=", red, v)))))
          val clt: Seq[Seq[SoP]] = varsSeq.map(v1 => varsSeq.map(v2 => SoP(Seq(vectorizeComparisonMultiplication("<", v1, v2)))))
          val ceq: Seq[Seq[SoP]] = varsSeq.map(v1 => varsSeq.map(v2 => SoP(Seq(vectorizeComparisonMultiplication("=", v1, v2)))))

          val bodyUSSeq: Seq[SoP] = (0 to n - 1).map(ind => SoP(Seq(vectorizeComparisonMultiplication("<=", varsSeq(ind), varsSeq(ind + 1)))))
          val bodyUS: SoP = multSoP(eUS ++ bodyUSSeq)

          
          val bodyRMSeq1: Seq[SoP] = indSeq.foldLeft(Seq.empty[SoP])((acc, i) => {
            val usInd: Iterator[Seq[Int]] = indSeq.combinations(i)
            acc ++ usInd.map(indList => {
              val usSeq: Seq[SoP] = (eUS_allvars.zipWithIndex).filter{case (us, ind) => indList.contains(ind)}.map{case (us, ind) => us}
              val rmSeq: Seq[SoP] = (eRM.zipWithIndex).filter{case (rm, ind) => !indList.contains(ind)}.map{case (rm, ind) => rm}
              multSoP(usSeq ++ rmSeq)
            })
          })
          val indeSeqPerm: Iterator[Seq[Int]] = indSeq.permutations
          val sg: List[List[String]] = (0 to n - 1).map(ind => List("=", "<")).toList
          val travOps: Traversable[Traversable[String]] = crossJoin(sg)
          val ops: Seq[Seq[String]] = travOps.map(s => s.toSeq).toSeq
          val bodyRMSeq2: Seq[SoP] = indeSeqPerm.zipWithIndex.foldLeft(Seq.empty[SoP])((acc, cur) => {
            val (iters, x) = (cur._1, cur._2)
            if (x != 0) acc ++ ops.zipWithIndex.foldLeft(Seq.empty[SoP])((acc2, cur2) => {
              val (op, x_sg) = (cur2._1, cur2._2)
              if (x_sg != 0) {
                val conds: Seq[SoP] = (0 to iters.length - 2).map(i => {
                  if (op(i) == "<") clt(iters(i))(iters(i + 1))
                  else ceq(iters(i))(iters(i + 1))
                })
                val cReds: Seq[SoP] = iters.zipWithIndex.map{case (iter, i) => cRed(i)(iter)}
                acc2 :+ multSoP(eUS ++ conds ++ cReds)
              } else acc2
            })
            else acc
          })
          val bodyRM: SoP = concatSoP(bodyRMSeq1 ++ bodyRMSeq2)
          
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM), outDimInfo)
        } else (inpUSSeq(0), inpRMSeq(0), emptyDimInfo)
      } else (inpUSSeq(0), inpRMSeq(0), emptyDimInfo)
    }
    else (inpUSSeq(0), inpRMSeq(0), emptyDimInfo)
  }

  def appendUniqueVars(v1: Seq[Variable], v2: Seq[Variable]): Seq[Variable] = v2.foldLeft(v1)((acc, cur) => if (v1.contains(cur)) acc else acc :+ cur)

  def infer(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule]): (Rule, Rule, DimInfo) = {
    val prods: Seq[Prod] = tensorComputation.body.prods
    val head: Access = tensorComputation.head
    val nonSizeVariables: Seq[Variable] = getVariables(tensorComputation)
    // println("!@#$%^&*(@!#$%^&*(!@#$%^&*()!@#$%^&*(!@#$%^&*(")
    // println("US:", uniqueSets)
    // println("RM:", redundancyMaps)
    println(tensorComputation.prettyFormat)
    // println("!@#$%^&*(@!#$%^&*(!@#$%^&*()!@#$%^&*(!@#$%^&*(")
    if (prods.length == 1) {
      val exps: Seq[Exp] = prods(0).exps
      if (isShift(exps, dimInfo, head)) {
        val e: Exp = exps(0)
        val inpUS: Rule = uniqueSets.getOrElse(e, emptyRule())
        val inpRM: Rule = redundancyMaps.getOrElse(e, emptyRule())
        return shift(head, dimInfo, e.asInstanceOf[Access], exps.slice(1, exps.length).map(elem => elem.asInstanceOf[Comparison]), inpUS, inpRM)
      }
      else if (exps.length == 1) {
        val e: Exp = exps(0)
        val inp1US: Rule = uniqueSets.getOrElse(e, emptyRule())
        val inp1RM: Rule = redundancyMaps.getOrElse(e, emptyRule())
        return project(head, dimInfo, e, inp1US, inp1RM)
      } else if (exps.length == 2) {
        val e1: Exp = exps(0)
        val e2: Exp = exps(1)
        val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
        val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
        val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
        val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
        return binMult(head, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
      } else {
        val eAccessIndexSeq: Seq[(Access, Int)] = exps.zipWithIndex.filter(eI => eI._1.isInstanceOf[Access]).map(eI => (eI._1.asInstanceOf[Access], eI._2))
        val nameMap: Map[String, Seq[(Access, Int)]] = eAccessIndexSeq.foldLeft(Map.empty[String, Seq[(Access, Int)]])((acc, cur) => mergeMap(Seq(acc, Map(cur._1.name -> Seq(cur))))((v1, v2) => v1 ++ v2))
        val similarNameMap: Map[String, Seq[(Access, Int)]] = nameMap.filter{case (name, accessIdSeq) => accessIdSeq.length > 1}.filter{case (name, accessIdSeq) => {
          val varsSeq: Seq[Seq[Variable]] = accessIdSeq.map(eI => eI._1.vars)
          isPairwiseIntersectEmpty(varsSeq)
        }}
        val multInfers: Map[Access, (Rule, Rule, DimInfo)] = similarNameMap.foldLeft(Map.empty[Access, (Rule, Rule, DimInfo)])((acc, cur) => {
          val accessIdSeq: Seq[(Access, Int)] = cur._2
          val varsSeq: Seq[Variable] = accessIdSeq.foldLeft(Seq.empty[Variable])((acc, eI) => appendUniqueVars(acc, eI._1.vars).filter(v => nonSizeVariables.contains(v)))
          val head: Access = Access(getVar("head"), varsSeq, Tensor)
          val similarExps: Seq[Access] = accessIdSeq.map{case (access, id) => access}
          val inpUS: Seq[Rule] = similarExps.map(e => uniqueSets.getOrElse(e, emptyRule()))
          val inpRM: Seq[Rule] = similarExps.map(e => redundancyMaps.getOrElse(e, emptyRule()))
          mergeMap(Seq(acc, Map(head -> mult(head, dimInfo, similarExps, inpUS, inpRM))))((v1, v2) => v2)
        })
        
        val similarNameIndices: Seq[Int] = similarNameMap.foldLeft(Seq.empty[Int])((acc, cur) => acc ++ cur._2.map{case (access, i) => i})
        val newExps: Seq[Exp] = exps.zipWithIndex.filter(eI => !similarNameIndices.contains(eI._2)).map(eI => eI._1) ++ multInfers.keySet.toSeq
        val similarUSMap: Map[Exp, Rule] = multInfers.map{case (access, us_rm_dim) => (access -> us_rm_dim._1)}
        val similarRMMap: Map[Exp, Rule] = multInfers.map{case (access, us_rm_dim) => (access -> us_rm_dim._2)}
        val similarDimInfoSeq: Seq[DimInfo] = multInfers.map{case (access, us_rm_dim) => us_rm_dim._3}.toSeq
        val uniqueSetsSim = mergeMap(Seq(uniqueSets, similarUSMap))((v1, v2) => v2)
        val redundancyMapsSim = mergeMap(Seq(redundancyMaps, similarRMMap))((v1, v2) => v2)
        val dimInfoSim = dimInfo ++ similarDimInfoSeq

        if (newExps.length == 1) return (multInfers.values.toSeq)(0)
        else if (newExps.length == 2) {
          val sop: SoP = SoP(Seq(Prod(Seq(newExps(0), newExps(1)))))
          val finalTC: Rule = Rule(head, sop)
          return infer(finalTC, dimInfoSim, uniqueSetsSim, redundancyMapsSim)
        }

        // else if (newExp.length > 2) or in other words else
        val n = newExps.length - 1
        val seqInd: Seq[Int] = 2 to n - 1
        val startHead: Access = Access(getVar("head"), appendUniqueVars(getAllVariables(newExps(0)), getAllVariables(newExps(1))).filter(v => nonSizeVariables.contains(v)), Tensor)
        val startSoP: SoP = SoP(Seq(Prod(Seq(newExps(0), newExps(1)))))
        val startTC: Rule = Rule(startHead, startSoP)
        val inf: (Rule, Rule, DimInfo) = infer(startTC, dimInfoSim, uniqueSetsSim, redundancyMapsSim)
        val newUS: Map[Exp, Rule] = mergeMap(Seq(uniqueSetsSim, Map[Exp, Rule](startHead -> inf._1)))((v1, v2) => v2)
        val newRM: Map[Exp, Rule] = mergeMap(Seq(redundancyMapsSim, Map[Exp, Rule](startHead -> inf._2)))((v1, v2) => v2)
        val newDI: Seq[DimInfo] = dimInfoSim :+ inf._3
        val tcMap: Map[Access, SoP] = Map(startHead -> startSoP)
        val (tc, inliningMap, (newUniqueSet, newRedundancyMap, newDimInfo)) = seqInd.foldLeft((startTC, tcMap, (newUS, newRM, newDI)))((acc, i) => {
          val accTC: Rule = acc._1
          val tcMap: Map[Access, SoP] = acc._2
          val us: Map[Exp, Rule] = acc._3._1
          val rm: Map[Exp, Rule] = acc._3._2
          val di: Seq[DimInfo] = acc._3._3
          val e: Exp = newExps(i)
          val head: Access = Access(getVar("head"), appendUniqueVars(accTC.head.vars, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)), Tensor)
          val sop: SoP = SoP(Seq(Prod(Seq(accTC.head, e))))
          val tc: Rule = Rule(head, sop)
          val inf: (Rule, Rule, DimInfo) = infer(tc, di, us, rm)
          val newUS: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head -> inf._1)))((v1, v2) => v2)
          val newRM: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head -> inf._2)))((v1, v2) => v2)
          val newDimInfo: Seq[DimInfo] = di :+ inf._3
          val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head -> sop)))((v1, v2) => concatSoP(Seq(v1, v2)))
          (tc, newTCMap, (newUS, newRM, newDimInfo))
        })
        val sop: SoP = SoP(Seq(Prod(Seq(tc.head, newExps(n)))))
        val finalTC: Rule = Rule(head, sop)
        return infer(finalTC, newDimInfo, newUniqueSet, newRedundancyMap)
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
          val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
          val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
          return binAdd(head, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
        } else if (exps1.length == 1 && exps2.length >= 2 && isDirectSum(exps2.slice(1, exps2.length), dimInfo, exps1(0), exps2(0))) {
          val e1 = exps1(0)
          val e2 = exps2(0)
          val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
          val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
          val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
          val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
          val e2Seq = exps2.slice(1, exps2.length).asInstanceOf[Seq[Comparison]]
          return binDirectSum(head, dimInfo, e1, e2, e2Seq, inp1US, inp1RM, inp2US, inp2RM)
        } 
      }

      // else
      val (tcSeq, inliningMap, (newUniqueSet, newRedundancyMap, newDimInfo)) = prods.foldLeft((Seq.empty[Rule], Map.empty[Access, SoP], (uniqueSets, redundancyMaps, dimInfo)))((acc, prod) => {
        val accTCSeq: Seq[Rule] = acc._1
        val tcMap: Map[Access, SoP] = acc._2
        val us: Map[Exp, Rule] = acc._3._1
        val rm: Map[Exp, Rule] = acc._3._2
        val di: Seq[DimInfo] = acc._3._3
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
          val inf: (Rule, Rule, DimInfo) = infer(tc, di, us, rm)
          val newUS: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head -> inf._1)))((v1, v2) => v2)
          val newRM: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head -> inf._2)))((v1, v2) => v2)
          val newDI: Seq[DimInfo] = di :+ inf._3
          val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head -> sop)))((v1, v2) => concatSoP(Seq(v1, v2)))
          (accTCSeq :+ tc, newTCMap, (newUS, newRM, newDI))
        } else {
          val sop1: SoP = SoP(Seq(Prod(prod.exps.slice(0, ind + 1))))
          val head1Vars: Seq[Variable] = prod.exps.slice(0, ind + 1).foldLeft(Seq.empty[Variable])((acc2, e) => appendUniqueVars(acc2, getAllVariables(e)).filter(v => nonSizeVariables.contains(v)))
          val head1: Access = Access(getVar("head"), head1Vars, Tensor)
          val tc1: Rule = Rule(head1, sop1)
          val sop2: SoP = SoP(Seq(Prod(Seq(head1) ++ prod.exps.slice(ind + 1, prod.exps.length))))
          val tc2: Rule = Rule(head, sop2)
          val inf1: (Rule, Rule, DimInfo) = infer(tc1, di, us, rm)
          val us2: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head1 -> inf1._1)))((v1, v2) => v2)
          val rm2: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head1 -> inf1._2)))((v1, v2) => v2)
          val di2: Seq[DimInfo] = di :+ inf1._3
          val tcMap1: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head1 -> sop1)))((v1, v2) => concatSoP(Seq(v1, v2)))
          val inf2: (Rule, Rule, DimInfo) = infer(tc2, di2, us2, rm2)
          val newUS: Map[Exp, Rule] = mergeMap(Seq(us2, Map[Exp, Rule](head -> inf2._1)))((v1, v2) => v2)
          val newRM: Map[Exp, Rule] = mergeMap(Seq(rm2, Map[Exp, Rule](head -> inf2._2)))((v1, v2) => v2)
          val newDI: Seq[DimInfo] = di2 :+ inf2._3
          val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap1, Map(head -> sop2)))((v1, v2) => concatSoP(Seq(v1, v2)))
          (accTCSeq :+ tc2, newTCMap, (newUS, newRM, newDI))
        }
      })
      val n = prods.length - 1
      val seqInd: Seq[Int] = 2 to n - 1
      val startHead: Access = Access(getVar("head"), appendUniqueVars(tcSeq(0).head.vars, tcSeq(1).head.vars).filter(v => nonSizeVariables.contains(v)), Tensor)
      val startSoP: SoP = SoP(Seq(Prod(Seq(tcSeq(0).head)), Prod(Seq(tcSeq(1).head))))
      val startTC: Rule = Rule(startHead, startSoP)
      val inf: (Rule, Rule, DimInfo) = infer(startTC, newDimInfo, newUniqueSet, newRedundancyMap)
      val newUS: Map[Exp, Rule] = mergeMap(Seq(newUniqueSet, Map[Exp, Rule](startHead -> inf._1)))((v1, v2) => v2)
      val newRM: Map[Exp, Rule] = mergeMap(Seq(newRedundancyMap, Map[Exp, Rule](startHead -> inf._2)))((v1, v2) => v2)
      val newDI: Seq[DimInfo] = newDimInfo :+ inf._3
      val tcMap: Map[Access, SoP] = mergeMap(Seq(inliningMap, Map(startHead -> startSoP)))((v1, v2) => concatSoP(Seq(v1, v2)))
      val (tc, finalInliningMap, (finalUniqueSet, finalRedundancyMap, finalDimInfo)) = seqInd.foldLeft((startTC, tcMap, (newUS, newRM, newDI)))((acc, i) => {
        val accTC: Rule = acc._1
        val tcMap: Map[Access, SoP] = acc._2
        val us: Map[Exp, Rule] = acc._3._1
        val rm: Map[Exp, Rule] = acc._3._2
        val di: Seq[DimInfo] = acc._3._3
        val e: Access = tcSeq(i).head
        val head: Access = Access(getVar("head"), appendUniqueVars(accTC.head.vars, e.vars).filter(v => nonSizeVariables.contains(v)), Tensor)
        val sop: SoP = SoP(Seq(Prod(Seq(accTC.head)), Prod(Seq(e))))
        val tc: Rule = Rule(head, sop)
        val inf: (Rule, Rule, DimInfo) = infer(tc, di, us, rm)
        val newUS: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](head -> inf._1)))((v1, v2) => v2)
        val newRM: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](head -> inf._2)))((v1, v2) => v2)
        val newDI: Seq[DimInfo] = di :+ inf._3
        val newTCMap: Map[Access, SoP] = mergeMap(Seq(tcMap, Map(head -> sop)))((v1, v2) => concatSoP(Seq(v1, v2)))
        (tc, newTCMap, (newUS, newRM, newDI))
      })
      val sop: SoP = SoP(Seq(Prod(Seq(tc.head)), Prod(Seq(tcSeq(n).head))))
      val finalTC: Rule = Rule(head, sop)
      val finalInf: (Rule, Rule, DimInfo) = infer(finalTC, finalDimInfo, finalUniqueSet, finalRedundancyMap)
      return finalInf
    }

    (emptyRule(), emptyRule(), emptyDimInfo())
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

  def getVariableConditionMap(variables: Seq[Variable], rule:Rule): Seq[Map[Variable, Seq[(String, Index)]]] = { 
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

  def unifyEqualVariableConditionMap(variables: Seq[Variable], variableConditionMap: Map[Variable, Seq[(String, Index)]]): Map[Variable, Seq[(String, Index)]] = {
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

    newVariableConditionMap
  }

  def unifyEqualVariableConditionMap(variables: Seq[Variable], variableConditionMaps: Seq[Map[Variable, Seq[(String, Index)]]]): Seq[Map[Variable, Seq[(String, Index)]]] = {
    variableConditionMaps.foldLeft(Seq.empty[Map[Variable, Seq[(String, Index)]]])((acc, cur) => acc :+ unifyEqualVariableConditionMap(variables, cur))
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
          case _ => Seq()
        }
        val seqC2: Seq[Comparison] = seqOp2.foldLeft(Seq.empty[Comparison])((acc, cur) => acc :+ Comparison(cur, index2, variable2))
        val equivSet1: Set[Comparison] = getEquivSet(c1)
        val equivSet2: Seq[Set[Comparison]] = seqC2.foldLeft(Seq.empty[Set[Comparison]])((acc, cur) => acc :+ getEquivSet(cur))
        val res = equivSet2.foldLeft(false)((acc, cur) => acc || equivSet1.intersect(cur).size > 0)
        if (callCount == 0) res || isProdEmpty(e2, e1, 1)
        else res
      }
      case _ => false
    }
  }

  def simplify(rule: Rule): Rule = {
    val prodSeqNoEmpty = rule.body.prods.foldLeft(Seq.empty[Prod])((acc, prod) => {
      val isPEmpty = prod.exps.foldLeft(false)((acc2, exp) => acc2 || prod.exps.foldLeft(false)((acc3, exp2) => acc3 || isProdEmpty(exp, exp2)))
      if (isPEmpty) acc
      else acc :+ prod
    })
    // here it just removes products that end up in emptySet + understands that (emptySet + e = e)
    // we don't have (x >= y) * (x <= y) = (x = y). For this we might need to go through unifyEqualVariableConditionMap and simplify multiple rounds.
    Rule(rule.head, SoP(prodSeqNoEmpty))
  }

  def getIntervals(variables: Seq[Variable], fixedConditionOrder: Map[Variable, Seq[(String, Index)]]): Map[Variable, Interval] = {
    val varsAndRed = variables.redundancyVarsInplace
    varsAndRed.foldLeft(Map.empty[Variable, Interval])((acc, variable) => {
      val condSeq: Seq[(String, Index)] = fixedConditionOrder.getOrElse(variable, Seq())
      val (begin, end): (Seq[Index], Seq[Index]) = condSeq.foldLeft((Seq.empty[Index], Seq.empty[Index]))((acc2, cur2) => {
        val op: String = cur2._1
        val index: Index = cur2._2
        val (b, e) = op match {
          case "<" => (Seq(Arithmetic("+", index, ConstantInt(1))), Seq())
          case "<=" => (Seq(index), Seq())
          case ">" => (Seq(), Seq(index))
          case ">=" => (Seq(), Seq(Arithmetic("+", index, ConstantInt(1))))
          case "=" => (Seq(index), Seq(Arithmetic("+", index, ConstantInt(1))))
          case _ => (Seq(), Seq())
        }
        (acc2._1 ++ b, acc2._2 ++ e)
      })
      mergeMap(Seq(acc, Map(variable -> Interval(begin, end))))((v1, v2) => Interval(v1.begin ++ v2.begin, v1.end ++ v2.end))
    })
  }

  def getIntervals(variables: Seq[Variable], fixedConditionOrder: Seq[Map[Variable, Seq[(String, Index)]]]): Seq[Map[Variable, Interval]] = {
    fixedConditionOrder.foldLeft(Seq.empty[Map[Variable, Interval]])((acc, cur) => acc :+ getIntervals(variables, cur))
  }

  def getStringChain(indexSeq: Seq[Index]): String = {
    val str = indexSeq.foldLeft("")((acc, index) => s"$acc, ${index.cFormat}")
    if (str.length > 0) str.substring(2, str.length)
    else str
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
      acc :+ Prod(prod.exps.foldLeft(Seq.empty[Exp])((acc2, exp) => {
        exp match {
          case Comparison(_, _, _) => acc2
          case _ => acc2 :+ exp
        }
      }))
    }))
  }

  def codeGenRule(tensorComputation: Rule, dimInfo: Seq[DimInfo], variables: Seq[Variable], intervals: Seq[Map[Variable, Interval]], genType: AccessType, codeMotion: Boolean = false): String = {
    // we should make sure that all the variables that are in the right hand side of an addition, we have a condition over them or we don't add them at all. Look at e2eLRDimInfo3.txt, first for loop, for this!
    val vars = if (genType == RedundancyMap) variables.redundancyVarsInplace else variables
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val dimVarMap: Map[Variable, Seq[Dim]] = dimInfo.toVarsMap
    val tcBodya: SoP = getNoComparisonSoP(tensorComputation.body) 

    intervals.foldLeft("")((acc, map) => {
      var cnt = 0
      val (tc, nestedLoops): (Rule, String) = vars.zipWithIndex.foldLeft((Rule(tensorComputation.head, tcBodya), ""))((acc2, variableInd) => {
        val variable: Variable = variableInd._1
        val interval = map.get(variable).get // Interval(Seq(), Seq()) is output if there's no condition on the variable
        val (areEquals, index, (b, e)) = areBeginAndEndEqual(interval)
        val newInterval: Interval = if((b, e) == (-1, -1)) interval // new interval without equal value
                          else Interval(interval.begin.zipWithIndex.filter(indexID => indexID._2 != b).map(indexID => indexID._1),
                                interval.end.zipWithIndex.filter(indexID => indexID._2 != e).map(indexID => indexID._1))
        val newInterval2: Interval = if (tensorComputation.body.prods.length > 1) { // if there's an addition, remove dimension information from intervals so later we can use it in if for boundary checking
          if (interval.begin.toSet != Set(ConstantInt(0).asInstanceOf[Index]) && interval.end.toSet != dimVarMap.get(variable).getOrElse(Seq.empty).toSet &&
          newInterval.begin.toSet.diff(Set(ConstantInt(0).asInstanceOf[Index])).toSeq.length > 0 && newInterval.end.toSet.diff(dimVarMap.get(variable).getOrElse(Seq.empty[Dim]).toSet).toSeq.length > 0) // : This thing malfunctions for some reason -> new conditions to fix it -> I need to fix the if else checks properly now we have too many of them
            Interval(newInterval.begin.toSet.diff(Set(ConstantInt(0).asInstanceOf[Index])).toSeq, newInterval.end.toSet.diff(dimVarMap.get(variable).getOrElse(Seq.empty[Dim]).toSet).toSeq)
          else newInterval
        } else newInterval
        val begin = if(newInterval2.begin.size > 1) s"std::max({${getStringChain(newInterval2.begin)}})" else if (newInterval2.begin.size == 1) newInterval2.begin(0).cFormat else ""
        val end = if(newInterval2.end.size > 1) s"std::min({${getStringChain(newInterval2.end)}})" else if (newInterval2.end.size == 1) newInterval2.end(0).cFormat else ""
        val code = if(areEquals) {
          val init = s"int ${variable.cFormat} = ${index.cFormat};"
          val rest = if (begin != "" && end != "") s"if ($begin <= ${variable.cFormat} && ${variable.cFormat} < $end) {" 
          else if (begin != "" && end == "") s"if ($begin <= ${variable.cFormat}) {" 
          else if (begin == "" && end != "") s"if (${variable.cFormat} < $end) {" 
          else {
            cnt += 1
            s""
          }
          s"$init\n$rest"
        } else {
            if (begin != "" && end != "") s"for (int ${variable.cFormat} = $begin; ${variable.cFormat} < $end; ++${variable.cFormat}) {"
            else if (begin != "" && end == "") {
              cnt += 1
              s"int ${variable.cFormat} = $begin; // WTF?" 
            }
            else if (begin == "" && end != "") {
              cnt += 1
              s"int ${variable.cFormat} = $end - 1;" 
            } 
            else {
              cnt += 1
              s""
            }
        }
        if (codeMotion) {
          // if current variable is equal to first element of each of the variables of accesses in the map, do code motion for it
          // update the map in a way that previous variables that include code motion be removed and new variable with .slice(1, length) of variables be in it
          val tc: Rule = acc2._1
          val (head, headCode): (Access, String) = if (variableInd._2 != vars.length - 1 || tc.body.prods.length > 1) {
            if (tc.head.vars.length > 0 && tc.head.vars(0) == variable) {
              val head = Access(getVar(s"CM_${tc.head.name}"), tc.head.vars.slice(1, tc.head.vars.length), tc.head.kind) 
              val headCode = s"auto ${head.name} = ${tc.head.name}[${variable.cFormat}];\n"
              (head, headCode)
            } else (tc.head, "")
          } else (tc.head, "")
          
          val (bodyProdSeq, bodyCode): (Seq[Prod], String) = if (variableInd._2 != vars.length - 1) {
            tc.body.prods.foldLeft((Seq.empty[Prod], ""))((acc, prod) => {
              val (newProd, cmCode): (Seq[Exp], String) = prod.exps.foldLeft((Seq.empty[Exp], ""))((acc2, exp) => {
                val access: Access = exp.asInstanceOf[Access]
                val (newAcc, accCode): (Access, String) = if (access.vars.length > 0 && access.vars(0) == variable) {
                  val newAcc = Access(getVar(s"CM_${access.name}"), access.vars.slice(1, access.vars.length), access.kind)
                  val accCode = s"auto ${newAcc.name} = ${access.name}[${variable.cFormat}];\n"
                  (newAcc, accCode)
                } else (access, "")
                (acc2._1 :+ newAcc, s"${acc2._2}$accCode")
              })
              (acc._1 :+ Prod(newProd), s"${acc._2}$cmCode")
            })
          } else (tc.body.prods, "")
          val body = SoP(bodyProdSeq)

          val newTC: Rule = Rule(head, body)
          (newTC, s"${acc2._2}\n$code\n$headCode\n$bodyCode")
        } else (acc2._1, s"${acc2._2}\n$code")
      })

      // why constants are not exp as well? Then I could replace the comparison below by ConstantInt(1) instead.
      val tcBody: SoP = if (tc.body == emptySoP()) SoP(Seq(Prod(Seq(Comparison("=", ConstantInt(0), getVar("rndVar").toVar))))) else tc.body // if it's only comparison, then it was just a bunch of comparison multiplications so their value is only 1. Their ranges is inside unique set and redundancy maps already.
      val body = if (genType == RedundancyMap) s"${tc.head.cFormat} = ${tc.head.cRedFormat};" else {
        if (tcBody.prods.length == 1) s"${tc.head.cFormat} += ${tcBody.cFormat};"
        else tcBody.prods.foldLeft("")((acc, prod) => {
          val conds = prod.exps.foldLeft("")((acc2, exp) => {
            exp match {
              case Access(name, vars, kind) => {
                val c = if (dimMap.contains(exp.asInstanceOf[Access])) {
                  (vars zip dimMap.get(exp.asInstanceOf[Access]).getOrElse(Seq.empty)).foldLeft("")((acc3, varDim) => {
                    val (flag, cond) = if (map.get(varDim._1).get == Interval(Seq(ConstantInt(0)), Seq(varDim._2))) (true, "")
                    else if (map.get(varDim._1).get != Interval(Seq(), Seq())) {
                      val interval = map.get(varDim._1).get
                      val isProdEmptyBegin = interval.begin.foldLeft(false)((isE, cur) => isE || isProdEmpty(Comparison("<=", cur, varDim._1), Comparison(">", varDim._2, varDim._1)))
                      val isProdEmptyEnd = interval.end.foldLeft(false)((isE, cur) => isE || isProdEmpty(Comparison(">", cur, varDim._1), Comparison("<=", ConstantInt(0), varDim._1)))
                      if (isProdEmptyBegin || isProdEmptyEnd) (false, "")
                      else if (acc3 == "remif") (false, s" && 0 <= ${varDim._1.cFormat} && ${varDim._1.cFormat} < ${varDim._2.cFormat}")
                      else (false, s"$acc3 && 0 <= ${varDim._1.cFormat} && ${varDim._1.cFormat} < ${varDim._2.cFormat}")
                    }
                    else (false, "")
                    
                    if (flag == true) "remif"
                    else cond
                  })
                } else "remif"
                if (acc2 == "" || acc2 == "remif") c else if (c == "remif") acc2 else acc2 + c
              }
              case _ => s"$acc2"
            }
          })
          if (conds == "remif") s"$acc\n${tc.head.cFormat} += ${prod.cFormat};" 
          else if (conds.length < 5) s"$acc" 
          else s"$acc\nif (${conds.substring(4, conds.length)}) {\n${tc.head.cFormat} += ${prod.cFormat};\n}" 
        })
      } // change wrt code motion and use the newest variables with the corresponding list to them
      // val body = if (genType == RedundancyMap) s"${tensorComputation.head.cFormat} = ${tensorComputation.head.cRedFormat};" else tensorComputation.cPeqFormat

      val finalBrackets = vars.slice(cnt, vars.size).foldLeft("")((acc, _) => s"$acc}\n")
      
      s"$acc\n$nestedLoops\n$body\n$finalBrackets"
    })
  }

  def codeGen(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule]): String = {
    val variables: Seq[Variable] = getVariables(tensorComputation)
    val (outUS, outRM, outDI) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMaps)
    
    val variableConditionMapUS: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, outUS)
    val variableConditionMapRM: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, outRM)

    val unifiedVariableConditionMapUS: Seq[Map[Variable, Seq[(String, Index)]]] = unifyEqualVariableConditionMap(variables, variableConditionMapUS)
    val unifiedVariableConditionMapRM: Seq[Map[Variable, Seq[(String, Index)]]] = unifyEqualVariableConditionMap(variables, variableConditionMapRM)

    val unifiedOutUS: Rule = Rule(outUS.head, getSoP(unifiedVariableConditionMapUS))
    val unifiedOutRM: Rule = Rule(outRM.head, getSoP(unifiedVariableConditionMapRM))

    val distinctOutUS: Rule = keepDistinct(unifiedOutUS)
    val distinctOutRM: Rule = keepDistinct(unifiedOutRM)

    val simplifiedOutUS: Rule = simplify(distinctOutUS)
    val simplifiedOutRM: Rule = simplify(distinctOutRM)

    val distinctConditionMapUS: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, simplifiedOutUS)
    val distinctConditionMapRM: Seq[Map[Variable, Seq[(String, Index)]]] = getVariableConditionMap(variables, simplifiedOutRM)

    val fixedConditionOrderUS: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, distinctConditionMapUS)
    val fixedConditionOrderRM: Seq[Map[Variable, Seq[(String, Index)]]] = fixConditionOrder(variables, distinctConditionMapRM)

    val intervalsUS: Seq[Map[Variable, Interval]] = getIntervals(variables, fixedConditionOrderUS)
    val intervalsRM: Seq[Map[Variable, Interval]] = getIntervals(variables, fixedConditionOrderRM)

    // println("variables:")
    // println(variables)
    // println("==================")
    // println("outUS")
    // pprint(outUS)
    // println("------------------")
    // println("outRM")
    // pprint(outRM)
    // println("------------------")
    // println("outDI")
    // println(dimInfo :+ outDI)
    // println("==================")
    // println("variableConditionMapUS")
    // println(variableConditionMapUS)
    // println("------------------")
    // println("variableConditionMapRM")
    // println(variableConditionMapRM)
    // println("==================")
    // println("unifiedVariableConditionMapUS")
    // println(unifiedVariableConditionMapUS)
    // println("------------------")
    // println("unifiedVariableConditionMapRM")
    // println(unifiedVariableConditionMapRM)
    // println("==================")
    // println("unifiedOutUS")
    // pprint(unifiedOutUS)
    // println("------------------")
    // println("unifiedOutRM")
    // pprint(unifiedOutRM)
    // println("==================")
    // println("distinctOutUS")
    // pprint(distinctOutUS)
    // println("------------------")
    // println("distinctOutRM")
    // pprint(distinctOutRM)
    println("==================")
    println("simplifiedOutUS")
    pprint(simplifiedOutUS)
    println("------------------")
    println("simplifiedOutRM")
    pprint(simplifiedOutRM)
    println("==================")
    // println("distinctConditionMapUS")
    // println(distinctConditionMapUS)
    // println("------------------")
    // println("distinctConditionMapRM")
    // println(distinctConditionMapRM)
    // println("==================")
    // println("fixedConditionOrderUS")
    // println(fixedConditionOrderUS)
    // println("------------------")
    // println("fixedConditionOrderRM")
    // println(fixedConditionOrderRM)
    // println("==================")
    // println("intervalsUS")
    // println(intervalsUS)
    // println("------------------")
    // println("intervalsRM")
    // println(intervalsRM)
    // println("==================")

    "void compute() {\n" + codeGenRule(tensorComputation, dimInfo :+ outDI, variables, intervalsUS, UniqueSet) + "\n}\n\n\nvoid reconstruct() {\n" + codeGenRule(tensorComputation, dimInfo :+ outDI, variables, intervalsRM, RedundancyMap) + "\n}\n"
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

  // Binary multiplication for 2 tensors check -- worked
  def test1(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
    val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
    val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
    val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
    val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
    val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
    val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
    val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
    val var1BodyRM: SoP = SoP(Seq(var1ProdsRM))
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
    val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
    val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
    val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
    val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
    val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
    val var2BodyRM: SoP = SoP(Seq(var2ProdsRM))
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Binary addition for 2 tensors check -- worked
  def test2(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
    val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
    val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
    val prod1: Prod = Prod(Seq(var1))
    val prod2: Prod = Prod(Seq(var2))
    val body: SoP = SoP(Seq(prod1, prod2))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
    val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
    val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
    val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
    val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
    val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
    val var1BodyRM: SoP = SoP(Seq(var1ProdsRM))
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
    val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
    val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
    val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
    val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
    val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
    val var2BodyRM: SoP = SoP(Seq(var2ProdsRM))
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Self-outer product check -- worked
  def test3(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
    val var1: Access = Access("A",  Seq(Variable("x")), Tensor)
    val var2: Access = Access("A",  Seq(Variable("y")), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // DTTV check: worked
  def test4(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
    val in2SeqVar = Seq("k".toVar)
    val outName = "A"
    val in1Name = "M"
    val in2Name = "N"

    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar, "m".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
    val var1ExpUS2: Exp = Comparison("=", "j".toVar, "k".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // RMD check: worked -- page 12: M_U should be 0 <= k < n (not j instead of k!!!) also in simplifications should be fixed too!
  def test5(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("i".toVar, "k".toVar)
    val in2SeqVar = Seq("k".toVar, "j".toVar)
    val outName = "A"
    val in1Name = "M"
    val in2Name = "N"

    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("=", "i".toVar, "r".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("=", "k".toVar, "j".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // UHS check: worked
  def test6(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("i".toVar, "j".toVar)
    val in2SeqVar = Seq("i".toVar, "j".toVar)
    val outName = "A"
    val in1Name = "M"
    val in2Name = "N"

    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2ExpRM1: Exp = Comparison("<", "j".toVar, "i".toVar)
    val var2ExpRM2: Exp = Comparison("=", "j".redundancyVars, "i".toVar)
    val var2ExpRM3: Exp = Comparison("=", "i".redundancyVars, "j".toVar)
    val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
    val var2BodyRM: SoP = SoP(Seq(var2ProdsRM))
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Example - Structure Inference checked: worked
  def test7(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("x1".toVar, "x2".toVar, "x3".toVar, "x4".toVar, "x5".toVar)
    val in1SeqVar = Seq("x1".toVar, "x2".toVar, "x3".toVar)
    val in2SeqVar = Seq("x4".toVar, "x5".toVar)
    val outName = "T"
    val in1Name = "M"
    val in2Name = "V"

    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("d1".toVar, "d2".toVar, "d3".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("d4".toVar, "d5".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison(">", "x1".toVar, "x2".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("<=", "x4".toVar, "x5".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2ExpRM1: Exp = Comparison(">", "x4".toVar, "x5".toVar)
    val var2ExpRM2: Exp = Comparison("=", "x4".redundancyVars, "x5".toVar)
    val var2ExpRM3: Exp = Comparison("=", "x5".redundancyVars, "x4".toVar)
    val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
    val var2BodyRM: SoP = SoP(Seq(var2ProdsRM))
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Non-binary: Example - Unique set computation: worked
  def test8(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
    val in1SeqVar = Seq("i".toVar, "j".toVar, "l".toVar)
    val in2SeqVar = Seq("i".toVar, "k".toVar)
    val in3SeqVar = Seq("j".toVar, "k".toVar)
    val in4SeqVar = Seq("i".toVar, "j".toVar)
    val outName = "A"
    val inter1Name = "F"
    val inter2Name = "G"
    val in1Name = "B"
    val in2Name = "C"
    val in3Name = "D"
    val in4Name = "E"

    val head1: Access = Access(inter1Name, outSeqVar, Tensor)
    val head2: Access = Access(inter2Name, outSeqVar, Tensor)
    val head3: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Access = Access(in3Name, in3SeqVar, Tensor)
    val var4: Access = Access(in4Name, in4SeqVar, Tensor)
    val prods1: Prod = Prod(Seq(var1, var2))
    val prods2: Prod = Prod(Seq(var3, var4))
    val body1: SoP = SoP(Seq(prods1))
    val body2: SoP = SoP(Seq(prods2))
    val body3: SoP = SoP(Seq(Prod(Seq(head1)), Prod(Seq(head2))))
    val tensorComputation1: Rule = Rule(head1, body1)
    val tensorComputation2: Rule = Rule(head2, body2)
    val tensorComputation3: Rule = Rule(head3, body3)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar, "n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("n".toVar, "n".toVar))
    val dim4: DimInfo = DimInfo(var4, Seq("n".toVar, "n".toVar))
    val dimH1: DimInfo = DimInfo(head1, Seq("n".toVar, "n".toVar, "n".toVar))
    val dimH2: DimInfo = DimInfo(head2, Seq("n".toVar, "n".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dimH1, dimH2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("=", "l".toVar, "k".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
    val var3BodyUS: SoP = emptySoP()
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
    val var4ExpUS1: Exp = Comparison("<=", "i".toVar, "k".toVar)
    val var4ProdsUS: Prod = Prod(Seq(var4ExpUS1))
    val var4BodyUS: SoP = SoP(Seq(var4ProdsUS))
    val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
    val var4BodyRM: SoP = emptySoP()
    val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

    val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
    val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))

    pprintTest((tensorComputation1, infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)))
    pprintTest((tensorComputation2, infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)))

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
    val newDimInfo: Seq[DimInfo] = dimInfo ++ Seq(infer1._3, infer2._3)

    println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))

    (tensorComputation3, infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  }

  // Normalised: Example - Unique set computation: worked
  def test8n(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
    val in1SeqVar = Seq("i".toVar, "j".toVar, "l".toVar)
    val in2SeqVar = Seq("i".toVar, "k".toVar)
    val in3SeqVar = Seq("j".toVar, "k".toVar)
    val in4SeqVar = Seq("i".toVar, "j".toVar)
    val outName = "A"
    val in1Name = "B"
    val in2Name = "C"
    val in3Name = "D"
    val in4Name = "E"

    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Access = Access(in3Name, in3SeqVar, Tensor)
    val var4: Access = Access(in4Name, in4SeqVar, Tensor)
    val prods1: Prod = Prod(Seq(var1, var2))
    val prods2: Prod = Prod(Seq(var3, var4))
    val body: SoP = SoP(Seq(prods1, prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar, "n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("n".toVar, "n".toVar))
    val dim4: DimInfo = DimInfo(var4, Seq("n".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("=", "l".toVar, "k".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
    val var3BodyUS: SoP = emptySoP()
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
    val var4ExpUS1: Exp = Comparison("<=", "i".toVar, "k".toVar)
    val var4ProdsUS: Prod = Prod(Seq(var4ExpUS1))
    val var4BodyUS: SoP = SoP(Seq(var4ProdsUS))
    val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
    val var4BodyRM: SoP = emptySoP()
    val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Non-binary: Example - Normal Kronecker Product
  def test9(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("p".toVar, "q".toVar)
    val in2SeqVar = Seq("r".toVar, "s".toVar)
    val outName = "O"
    val inter1Name = "C"
    val inter2Name = "D"
    val inter3Name = "E"
    val inter4Name = "F"
    val inter5Name = "G"
    val inter6Name = "H"
    val inter7Name = "I"
    val inter8Name = "J"
    val inter9Name = "K"
    val inter10Name = "L"
    val inter11Name = "M"
    val inter12Name = "N"
    val in1Name = "A"
    val in2Name = "B"

    val head1: Access = Access(inter1Name, in1SeqVar, Tensor)
    val head2: Access = Access(inter2Name, in2SeqVar, Tensor)
    val head3: Access = Access(inter3Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
    val head4: Access = Access(inter4Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
    val head5: Access = Access(inter5Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
    val head6: Access = Access(inter6Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
    val head7: Access = Access(inter7Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
    val head8: Access = Access(inter8Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
    val head9: Access = Access(inter9Name, outSeqVar ++ in1SeqVar, Tensor)
    val head10: Access = Access(inter10Name, outSeqVar ++ in2SeqVar, Tensor)
    val head11: Access = Access(inter11Name, outSeqVar ++ in1SeqVar, Tensor)
    val head12: Access = Access(inter12Name, outSeqVar ++ in2SeqVar, Tensor)
    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
    val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
    val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
    val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
    val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
    val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
    val var9: Comparison = Comparison(">", Arithmetic("*", "x".toVar, "m".toVar), "i".toVar)
    val var10: Comparison = Comparison(">", Arithmetic("*", "y".toVar, "n".toVar), "j".toVar)
    
    val prods1: Prod = Prod(Seq(var1, var7))
    val prods2: Prod = Prod(Seq(var2, var7))
    val prods3: Prod = Prod(Seq(head1, var9))
    val prods4: Prod = Prod(Seq(head2, var9))
    val prods5: Prod = Prod(Seq(head3, var3))
    val prods6: Prod = Prod(Seq(head4, var5))
    val prods7: Prod = Prod(Seq(head5, var8))
    val prods8: Prod = Prod(Seq(head6, var8))
    val prods9: Prod = Prod(Seq(head7, var10))
    val prods10: Prod = Prod(Seq(head8, var10))
    val prods11: Prod = Prod(Seq(head9, var4))
    val prods12: Prod = Prod(Seq(head10, var6))
    val prods: Prod = Prod(Seq(head11, head12))
    val body1: SoP = SoP(Seq(prods1))
    val body2: SoP = SoP(Seq(prods2))
    val body3: SoP = SoP(Seq(prods3))
    val body4: SoP = SoP(Seq(prods4))
    val body5: SoP = SoP(Seq(prods5))
    val body6: SoP = SoP(Seq(prods6))
    val body7: SoP = SoP(Seq(prods7))
    val body8: SoP = SoP(Seq(prods8))
    val body9: SoP = SoP(Seq(prods9))
    val body10: SoP = SoP(Seq(prods10))
    val body11: SoP = SoP(Seq(prods11))
    val body12: SoP = SoP(Seq(prods12))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation1: Rule = Rule(head1, body1)
    val tensorComputation2: Rule = Rule(head2, body2)
    val tensorComputation3: Rule = Rule(head3, body3)
    val tensorComputation4: Rule = Rule(head4, body4)
    val tensorComputation5: Rule = Rule(head5, body5)
    val tensorComputation6: Rule = Rule(head6, body6)
    val tensorComputation7: Rule = Rule(head7, body7)
    val tensorComputation8: Rule = Rule(head8, body8)
    val tensorComputation9: Rule = Rule(head9, body9)
    val tensorComputation10: Rule = Rule(head10, body10)
    val tensorComputation11: Rule = Rule(head11, body11)
    val tensorComputation12: Rule = Rule(head12, body12)
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("x".toVar, "y".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
    val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
    val newDimInfo: Seq[DimInfo] = dimInfo ++ Seq(infer1._3, infer2._3)

    val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap)
    val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap)

    val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
    val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)
    val newDimInfo2: Seq[DimInfo] = newDimInfo ++ Seq(infer3._3, infer4._3)

    val infer5: (Rule, Rule, DimInfo) = infer(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2)
    val infer6: (Rule, Rule, DimInfo) = infer(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2)

    val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
    val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)
    val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++ Seq(infer5._3, infer6._3)

    val infer7: (Rule, Rule, DimInfo) = infer(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3)
    val infer8: (Rule, Rule, DimInfo) = infer(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3)

    val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
    val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)
    val newDimInfo4: Seq[DimInfo] = newDimInfo3 ++ Seq(infer7._3, infer8._3)

    val infer9: (Rule, Rule, DimInfo) = infer(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4)
    val infer10: (Rule, Rule, DimInfo) = infer(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4)

    val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
    val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)
    val newDimInfo5: Seq[DimInfo] = newDimInfo4 ++ Seq(infer9._3, infer10._3)

    val infer11: (Rule, Rule, DimInfo) = infer(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5)
    val infer12: (Rule, Rule, DimInfo) = infer(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5)

    val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
    val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)
    val newDimInfo6: Seq[DimInfo] = newDimInfo5 ++ Seq(infer11._3, infer12._3)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5))
    println(codeGen(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5))

    println(codeGen(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))

    pprintTest((tensorComputation1, infer1))
    pprintTest((tensorComputation2, infer2))
    pprintTest((tensorComputation3, infer3))
    pprintTest((tensorComputation4, infer4))
    pprintTest((tensorComputation5, infer5))
    pprintTest((tensorComputation6, infer6))
    pprintTest((tensorComputation7, infer7))
    pprintTest((tensorComputation8, infer8))
    pprintTest((tensorComputation9, infer9))
    pprintTest((tensorComputation10, infer10))
    pprintTest((tensorComputation11, infer11))
    pprintTest((tensorComputation12, infer12))

    (tensorComputation, infer(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))
  }

  // Normalised: Example - Normal Kronecker Product
  def test9n(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("p".toVar, "q".toVar)
    val in2SeqVar = Seq("r".toVar, "s".toVar)
    val outName = "O"
    val in1Name = "A"
    val in2Name = "B"
    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
    val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
    val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
    val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
    val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
    val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
    val var9: Comparison = Comparison(">", Arithmetic("*", "x".toVar, "m".toVar), "i".toVar)
    val var10: Comparison = Comparison(">", Arithmetic("*", "y".toVar, "n".toVar), "j".toVar)
    
    val prods: Prod = Prod(Seq(var1, var7, var9, var3, var8, var10, var4, var2, var7, var9, var5, var8, var10, var6))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("x".toVar, "y".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    
    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Non-binary: Polynomial Regression Degree 2 -- It's a confusing mess, will check it after all simplifications
  def test10(): (Rule, (Rule, Rule, DimInfo)) = {
    val inSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("i".toVar)
    val in2SeqVar = Seq("j".toVar)
    val outSeqVar = Seq("p".toVar, "q".toVar)
    val interSeqVar1 = Seq("k".toVar)
    val interSeqVar2 = Seq("p".toVar)
    val interSeqVar3 = Seq("q".toVar)
    val outName = "S"
    val inter1Name = "A"
    val inter2Name = "B"
    val inter3Name = "C"
    val inter4Name = "D"
    val in1Name = "f"
    val in2Name = "f"
    val in3Name = "f"
    val in4Name = "f"
    val in5Name = "f"
    val in6Name = "f"
    val in7Name = "f"

    val head1: Access = Access(inter1Name, inSeqVar, Tensor)
    val head2: Access = Access(inter2Name, interSeqVar1, Tensor)
    val head3: Access = Access(inter3Name, interSeqVar2, Tensor)
    val head4: Access = Access(inter4Name, interSeqVar3, Tensor)
    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in1Name, in2SeqVar, Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("+", Arithmetic("*", "i".toVar, "n".toVar), "j".toVar), "k".toVar)
    val var4: Access = Access(in1Name, interSeqVar2, Tensor)
    val var5: Comparison = Comparison("=", Arithmetic("-", "p".toVar, "n".toVar), "k".toVar)
    val var6: Access = Access(in1Name, interSeqVar3, Tensor)
    val var7: Comparison = Comparison("=", Arithmetic("-", "q".toVar, "n".toVar), "k".toVar)
    val prods1: Prod = Prod(Seq(var1, var2))
    val prods2: Prod = Prod(Seq(head1, var3))
    val prods3: Prod = Prod(Seq(head2, var5))
    val prods4: Prod = Prod(Seq(head2, var7))
    val prods: Prod = Prod(Seq(head3, head4))
    val body1: SoP = SoP(Seq(prods1))
    val body2: SoP = SoP(Seq(prods2))
    val body3: SoP = SoP(Seq(Prod(Seq(var4)), prods3))
    val body4: SoP = SoP(Seq(Prod(Seq(var6)), prods4))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation1: Rule = Rule(head1, body1)
    val tensorComputation2: Rule = Rule(head2, body2)
    val tensorComputation3: Rule = Rule(head3, body3)
    val tensorComputation4: Rule = Rule(head4, body4)
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
    val dim3: DimInfo = DimInfo(var4, Seq("n".toVar))
    val dim4: DimInfo = DimInfo(var6, Seq("n".toVar))
    // val dimH1: DimInfo = DimInfo(head1, Seq("n".toVar, "n".toVar, "n".toVar)) n times n?
    val dimH2: DimInfo = DimInfo(head2, Seq("n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dimH2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1BodyUS: SoP = emptySoP()
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    // since all of them are empty so it doesn't matter
    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM)

    val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

    pprintTest((tensorComputation1, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)))
    
    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
    val newDimInfo: Seq[DimInfo] = dimInfo :+ infer1._3
    
    val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, newDimInfo, newUniqueSets, newRedundancyMap)

    println(codeGen(tensorComputation2, newDimInfo, newUniqueSets, newRedundancyMap))

    pprintTest((tensorComputation2, infer(tensorComputation, newDimInfo, newUniqueSets, newRedundancyMap)))

    val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._1), newUniqueSets))((v1, v2) => v2)
    val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._2), newRedundancyMap))((v1, v2) => v2)
    val newDimInfo2: Seq[DimInfo] = newDimInfo :+ infer2._3

    val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo2, newUniqueSets2, newRedundancyMap2)
    val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo2, newUniqueSets2, newRedundancyMap2)

    println(codeGen(tensorComputation3, newDimInfo2, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation4, newDimInfo2, newUniqueSets2, newRedundancyMap2))

    pprintTest((tensorComputation3, infer(tensorComputation, newDimInfo2, newUniqueSets2, newRedundancyMap2)))
    pprintTest((tensorComputation4, infer(tensorComputation, newDimInfo2, newUniqueSets2, newRedundancyMap2)))

    val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets2))((v1, v2) => v2)
    val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap2))((v1, v2) => v2)
    val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++ Seq(infer3._3, infer4._3)

    println(codeGen(tensorComputation, newDimInfo3, newUniqueSets3, newRedundancyMap3))

    (tensorComputation, infer(tensorComputation, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  }

  // Self-outer product 3 check: worked -- need to be checked inside covariance matrices to make sure -- manually checked
  def test11(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq("x".toVar, "y".toVar, "z".toVar), Tensor)
    val var1: Access = Access("A",  Seq("x".toVar), Tensor)
    val var2: Access = Access("A",  Seq("y".toVar), Tensor)
    val var3: Access = Access("A",  Seq("z".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2, var3))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


    val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access("A".uniqueName,  Seq(Variable("z")), UniqueSet)
    val var3BodyUS: SoP = dim3.toSoP
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access("A".redundancyName,  Seq(Variable("z"), Variable("z").redundancyVars), RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Self-outer product 4 check: worked  -- need to be checked inside covariance matrices to make sure -- manually checked
  def test12(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq("x".toVar, "y".toVar, "z".toVar, "p".toVar), Tensor)
    val var1: Access = Access("A",  Seq("x".toVar), Tensor)
    val var2: Access = Access("A",  Seq("y".toVar), Tensor)
    val var3: Access = Access("A",  Seq("z".toVar), Tensor)
    val var4: Access = Access("A",  Seq("p".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2, var3, var4))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("n".toVar))
    val dim4: DimInfo = DimInfo(var4, Seq("n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4)


    val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access("A".uniqueName,  Seq(Variable("z")), UniqueSet)
    val var3BodyUS: SoP = dim3.toSoP
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access("A".redundancyName,  Seq(Variable("z"), Variable("z").redundancyVars), RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var4HeadUS: Access = Access("A".uniqueName,  Seq(Variable("p")), UniqueSet)
    val var4BodyUS: SoP = dim4.toSoP
    val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    val var4HeadRM: Access = Access("A".redundancyName,  Seq(Variable("p"), Variable("p").redundancyVars), RedundancyMap)
    val var4BodyRM: SoP = emptySoP()
    val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Non-Binary Example: Diagonal Kronecker Product
  def test13(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("p".toVar, "q".toVar)
    val in2SeqVar = Seq("r".toVar, "s".toVar)
    val outName = "O"
    val inter1Name = "C"
    val inter2Name = "D"
    val inter3Name = "E"
    val inter4Name = "F"
    val inter5Name = "G"
    val inter6Name = "H"
    val inter7Name = "I"
    val inter8Name = "J"
    val inter9Name = "K"
    val inter10Name = "L"
    val inter11Name = "M"
    val inter12Name = "N"
    val in1Name = "A"
    val in2Name = "B"

    val head1: Access = Access(inter1Name, in1SeqVar, Tensor)
    val head2: Access = Access(inter2Name, in2SeqVar, Tensor)
    val head3: Access = Access(inter3Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
    val head4: Access = Access(inter4Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
    val head5: Access = Access(inter5Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
    val head6: Access = Access(inter6Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
    val head7: Access = Access(inter7Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
    val head8: Access = Access(inter8Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
    val head9: Access = Access(inter9Name, outSeqVar ++ in1SeqVar, Tensor)
    val head10: Access = Access(inter10Name, outSeqVar ++ in2SeqVar, Tensor)
    val head11: Access = Access(inter11Name, outSeqVar ++ in1SeqVar, Tensor)
    val head12: Access = Access(inter12Name, outSeqVar ++ in2SeqVar, Tensor)
    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "n".toVar), "p".toVar)
    val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
    val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "n".toVar), "r".toVar)
    val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
    val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
    val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
    val var9: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "i".toVar)
    val var10: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "j".toVar)
    
    val prods1: Prod = Prod(Seq(var1, var7))
    val prods2: Prod = Prod(Seq(var2, var7))
    val prods3: Prod = Prod(Seq(head1, var9))
    val prods4: Prod = Prod(Seq(head2, var9))
    val prods5: Prod = Prod(Seq(head3, var3))
    val prods6: Prod = Prod(Seq(head4, var5))
    val prods7: Prod = Prod(Seq(head5, var8))
    val prods8: Prod = Prod(Seq(head6, var8))
    val prods9: Prod = Prod(Seq(head7, var10))
    val prods10: Prod = Prod(Seq(head8, var10))
    val prods11: Prod = Prod(Seq(head9, var4))
    val prods12: Prod = Prod(Seq(head10, var6))
    val prods: Prod = Prod(Seq(head11, head12))
    val body1: SoP = SoP(Seq(prods1))
    val body2: SoP = SoP(Seq(prods2))
    val body3: SoP = SoP(Seq(prods3))
    val body4: SoP = SoP(Seq(prods4))
    val body5: SoP = SoP(Seq(prods5))
    val body6: SoP = SoP(Seq(prods6))
    val body7: SoP = SoP(Seq(prods7))
    val body8: SoP = SoP(Seq(prods8))
    val body9: SoP = SoP(Seq(prods9))
    val body10: SoP = SoP(Seq(prods10))
    val body11: SoP = SoP(Seq(prods11))
    val body12: SoP = SoP(Seq(prods12))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation1: Rule = Rule(head1, body1)
    val tensorComputation2: Rule = Rule(head2, body2)
    val tensorComputation3: Rule = Rule(head3, body3)
    val tensorComputation4: Rule = Rule(head4, body4)
    val tensorComputation5: Rule = Rule(head5, body5)
    val tensorComputation6: Rule = Rule(head6, body6)
    val tensorComputation7: Rule = Rule(head7, body7)
    val tensorComputation8: Rule = Rule(head8, body8)
    val tensorComputation9: Rule = Rule(head9, body9)
    val tensorComputation10: Rule = Rule(head10, body10)
    val tensorComputation11: Rule = Rule(head11, body11)
    val tensorComputation12: Rule = Rule(head12, body12)
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("=", "p".toVar, "q".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("=", "r".toVar, "s".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
    val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
    val newDimInfo: Seq[DimInfo] = dimInfo ++  Seq(infer1._3, infer2._3)

    val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap)
    val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap)

    val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
    val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)
    val newDimInfo2: Seq[DimInfo] = newDimInfo ++  Seq(infer3._3, infer4._3)

    val infer5: (Rule, Rule, DimInfo) = infer(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2)
    val infer6: (Rule, Rule, DimInfo) = infer(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2)

    val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
    val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)
    val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++  Seq(infer5._3, infer6._3)

    val infer7: (Rule, Rule, DimInfo) = infer(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3)
    val infer8: (Rule, Rule, DimInfo) = infer(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3)

    val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
    val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)
    val newDimInfo4: Seq[DimInfo] = newDimInfo3 ++  Seq(infer7._3, infer8._3)

    val infer9: (Rule, Rule, DimInfo) = infer(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4)
    val infer10: (Rule, Rule, DimInfo) = infer(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4)

    val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
    val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)
    val newDimInfo5: Seq[DimInfo] = newDimInfo4 ++  Seq(infer9._3, infer10._3)

    val infer11: (Rule, Rule, DimInfo) = infer(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5)
    val infer12: (Rule, Rule, DimInfo) = infer(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5)

    val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
    val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)
    val newDimInfo6: Seq[DimInfo] = newDimInfo5 ++  Seq(infer11._3, infer12._3)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5))
    println(codeGen(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5))

    println(codeGen(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))

    pprintTest((tensorComputation1, infer1))
    pprintTest((tensorComputation2, infer2))
    pprintTest((tensorComputation3, infer3))
    pprintTest((tensorComputation4, infer4))
    pprintTest((tensorComputation5, infer5))
    pprintTest((tensorComputation6, infer6))
    pprintTest((tensorComputation7, infer7))
    pprintTest((tensorComputation8, infer8))
    pprintTest((tensorComputation9, infer9))
    pprintTest((tensorComputation10, infer10))
    pprintTest((tensorComputation11, infer11))
    pprintTest((tensorComputation12, infer12))

    (tensorComputation, infer(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))
  }

  // Normalised: Example - Normal Kronecker Product
  def test13n(): (Rule, (Rule, Rule, DimInfo)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("p".toVar, "q".toVar)
    val in2SeqVar = Seq("r".toVar, "s".toVar)
    val outName = "O"
    val in1Name = "A"
    val in2Name = "B"
    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "n".toVar), "p".toVar)
    val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
    val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "n".toVar), "r".toVar)
    val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
    val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
    val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
    val var9: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "i".toVar)
    val var10: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "j".toVar)
    
    val prods: Prod = Prod(Seq(var1, var7, var9, var3, var8, var10, var4, var2, var7, var9, var5, var8, var10, var6))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
    val var1ExpUS1: Exp = Comparison("=", "p".toVar, "q".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
    val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
    val var2ExpUS1: Exp = Comparison("=", "r".toVar, "s".toVar)
    val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
    val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    
    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Vector direct sum - checked
  def test14(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq("x".toVar), Tensor)
    val var1: Access = Access("A",  Seq("x".toVar), Tensor)
    val var2: Access = Access("B",  Seq("y".toVar), Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("-", "x".toVar, "n".toVar), "y".toVar)
    val prods1: Prod = Prod(Seq(var1))
    val prods2: Prod = Prod(Seq(var2, var3))
    val body: SoP = SoP(Seq(prods1, prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y")), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // a bunch of self mults
  def test15(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq("x0".toVar, "y0".toVar, "y1".toVar, "z0".toVar, "y2".toVar, "x1".toVar, "t0".toVar, "z1".toVar), Tensor)
    val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
    val var2: Access = Access("B",  Seq("y0".toVar), Tensor)
    val var3: Access = Access("B",  Seq("y1".toVar), Tensor)
    val var4: Access = Access("C",  Seq("z0".toVar), Tensor)
    val var5: Access = Access("B",  Seq("y2".toVar), Tensor)
    val var6: Access = Access("A",  Seq("x1".toVar), Tensor)
    val var7: Access = Access("D",  Seq("t0".toVar), Tensor)
    val var8: Access = Access("C",  Seq("z1".toVar), Tensor)

    val prods: Prod = Prod(Seq(var1, var2, var3, var4, var5, var6, var7, var8))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("m".toVar))
    val dim4: DimInfo = DimInfo(var4, Seq("p".toVar))
    val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
    val dim6: DimInfo = DimInfo(var6, Seq("n".toVar))
    val dim7: DimInfo = DimInfo(var7, Seq("q".toVar))
    val dim8: DimInfo = DimInfo(var8, Seq("p".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dim5, dim6, dim7, dim8)

    val var1HeadUS: Access = Access("A".uniqueName,  Seq("x0".toVar), UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq("x0".toVar, "x0".toVar.redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("B".uniqueName,  Seq("y0".toVar), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)
    
    val var2HeadRM: Access = Access("B".redundancyName,  Seq("y0".toVar, "y0".toVar.redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access("B".uniqueName,  Seq("y1".toVar), UniqueSet)
    val var3BodyUS: SoP = dim3.toSoP
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
    val var3HeadRM: Access = Access("B".redundancyName,  Seq("y1".toVar, "y1".toVar.redundancyVars), RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var4HeadUS: Access = Access("C".uniqueName,  Seq("z0".toVar), UniqueSet)
    val var4BodyUS: SoP = dim4.toSoP
    val var4US: Rule = Rule(var4HeadUS, var4BodyUS)
    
    val var4HeadRM: Access = Access("C".redundancyName,  Seq("z0".toVar, "z0".toVar.redundancyVars), RedundancyMap)
    val var4BodyRM: SoP = emptySoP()
    val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    val var5HeadUS: Access = Access("B".uniqueName,  Seq("y2".toVar), UniqueSet)
    val var5BodyUS: SoP = dim5.toSoP
    val var5US: Rule = Rule(var5HeadUS, var5BodyUS)
    
    val var5HeadRM: Access = Access("B".redundancyName,  Seq("y2".toVar, "y2".toVar.redundancyVars), RedundancyMap)
    val var5BodyRM: SoP = emptySoP()
    val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

    val var6HeadUS: Access = Access("A".uniqueName,  Seq("x1".toVar), UniqueSet)
    val var6BodyUS: SoP = dim6.toSoP
    val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

    val var6HeadRM: Access = Access("A".redundancyName,  Seq("x1".toVar, "x1".toVar.redundancyVars), RedundancyMap)
    val var6BodyRM: SoP = emptySoP()
    val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

    val var7HeadUS: Access = Access("D".uniqueName,  Seq("t0".toVar), UniqueSet)
    val var7BodyUS: SoP = dim7.toSoP
    val var7US: Rule = Rule(var7HeadUS, var7BodyUS)

    val var7HeadRM: Access = Access("D".redundancyName,  Seq("t0".toVar, "t0".toVar.redundancyVars), RedundancyMap)
    val var7BodyRM: SoP = emptySoP()
    val var7RM: Rule = Rule(var7HeadRM, var7BodyRM)

    val var8HeadUS: Access = Access("C".uniqueName,  Seq("z1".toVar), UniqueSet)
    val var8BodyUS: SoP = dim8.toSoP
    val var8US: Rule = Rule(var8HeadUS, var8BodyUS)
    
    val var8HeadRM: Access = Access("C".redundancyName,  Seq("z1".toVar, "z1".toVar.redundancyVars), RedundancyMap)
    val var8BodyRM: SoP = emptySoP()
    val var8RM: Rule = Rule(var8HeadRM, var8BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US, var5 -> var5US, var6 -> var6US, var7 -> var7US, var8 -> var8US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM, var5 -> var5RM, var6 -> var6RM, var7 -> var7RM, var8 -> var8RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // a bunch of self mults
  def test16(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq("x0".toVar, "y0".toVar, "y1".toVar, "y2".toVar, "x1".toVar), Tensor)
    val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
    val var2: Access = Access("B",  Seq("y0".toVar), Tensor)
    val var3: Access = Access("B",  Seq("y1".toVar), Tensor)
    val var5: Access = Access("B",  Seq("y2".toVar), Tensor)
    val var6: Access = Access("A",  Seq("x1".toVar), Tensor)

    val prods: Prod = Prod(Seq(var1, var2, var3, var5, var6))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("m".toVar))
    val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
    val dim6: DimInfo = DimInfo(var6, Seq("n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim5, dim6)

    val var1HeadUS: Access = Access("A".uniqueName,  Seq("x0".toVar), UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq("x0".toVar, "x0".toVar.redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("B".uniqueName,  Seq("y0".toVar), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)
    
    val var2HeadRM: Access = Access("B".redundancyName,  Seq("y0".toVar, "y0".toVar.redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access("B".uniqueName,  Seq("y1".toVar), UniqueSet)
    val var3BodyUS: SoP = dim3.toSoP
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
    val var3HeadRM: Access = Access("B".redundancyName,  Seq("y1".toVar, "y1".toVar.redundancyVars), RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var5HeadUS: Access = Access("B".uniqueName,  Seq("y2".toVar), UniqueSet)
    val var5BodyUS: SoP = dim5.toSoP
    val var5US: Rule = Rule(var5HeadUS, var5BodyUS)
    
    val var5HeadRM: Access = Access("B".redundancyName,  Seq("y2".toVar, "y2".toVar.redundancyVars), RedundancyMap)
    val var5BodyRM: SoP = emptySoP()
    val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

    val var6HeadUS: Access = Access("A".uniqueName,  Seq("x1".toVar), UniqueSet)
    val var6BodyUS: SoP = dim6.toSoP
    val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

    val var6HeadRM: Access = Access("A".redundancyName,  Seq("x1".toVar, "x1".toVar.redundancyVars), RedundancyMap)
    val var6BodyRM: SoP = emptySoP()
    val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var5 -> var5US, var6 -> var6US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var5 -> var5RM, var6 -> var6RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Vector Append test - checked
  def test17(): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("M", Seq("x".toVar), Tensor)
    // val var1: Access = Access("A",  Seq("x".toVar), Tensor)
    val var2: Access = Access("B",  Seq("y".toVar), Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("-", "x".toVar, "n".toVar), "y".toVar)
    // val prods1: Prod = Prod(Seq(var1))
    val prods2: Prod = Prod(Seq(var2, var3))
    // val body: SoP = SoP(Seq(prods1, prods2))
    val body: SoP = SoP(Seq(prods2))
    val tensorComputation: Rule = Rule(head, body)

    // val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
    // val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)
    val dimInfo: Seq[DimInfo] = Seq(dim2)


    // val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
    // val var1BodyUS: SoP = dim1.toSoP
    // val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    // val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
    // val var1BodyRM: SoP = emptySoP()
    // val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y")), UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    // val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    // val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val uniqueSets: Map[Exp, Rule] = Map(var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  def multiProg1() = {
    val head1: Access = Access("T", Seq("x".toVar), Tensor)
    val var11: Access = Access("T1",  Seq("x".toVar), Tensor)
    val var12: Access = Access("T2",  Seq("x".toVar), Tensor)

    val head2: Access = Access("M",  Seq("x".toVar), Tensor)
    val var21: Access = Access("U",  Seq("x".toVar), Tensor)

    val prods11: Prod = Prod(Seq(var11))
    val prods12: Prod = Prod(Seq(var12))
    val body1: SoP = SoP(Seq(prods11, prods12))
    val tensorComputation1: Rule = Rule(head1, body1)

    val prods2: Prod = Prod(Seq(head1, var21))
    val body2: SoP = SoP(Seq(prods2))
    val tensorComputation2: Rule = Rule(head2, body2)

    val tensorComputation: Seq[Rule] = Seq(tensorComputation1, tensorComputation2)

    val dim11: DimInfo = DimInfo(var11, Seq("n".toVar))
    val dim12: DimInfo = DimInfo(var12, Seq("n".toVar))
    val dim21: DimInfo = DimInfo(var21, Seq("n".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim11, dim12, dim21)

    val var11HeadUS: Access = Access("T1".uniqueName,  Seq("x".toVar), UniqueSet)
    val var11BodyUS: SoP = dim11.toSoP
    val var11US: Rule = Rule(var11HeadUS, var11BodyUS)

    val var11HeadRM: Access = Access("T1".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
    val var11BodyRM: SoP = emptySoP()
    val var11RM: Rule = Rule(var11HeadRM, var11BodyRM)

    val var12HeadUS: Access = Access("T2".uniqueName,  Seq("x".toVar), UniqueSet)
    val var12BodyUS: SoP = dim12.toSoP
    val var12US: Rule = Rule(var12HeadUS, var12BodyUS)

    val var12HeadRM: Access = Access("T2".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
    val var12BodyRM: SoP = emptySoP()
    val var12RM: Rule = Rule(var12HeadRM, var12BodyRM)

    val var21HeadUS: Access = Access("U".uniqueName,  Seq("x".toVar), UniqueSet)
    val var21BodyUS: SoP = dim21.toSoP
    val var21US: Rule = Rule(var21HeadUS, var21BodyUS)

    val var21HeadRM: Access = Access("U".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
    val var21BodyRM: SoP = emptySoP()
    val var21RM: Rule = Rule(var21HeadRM, var21BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var11 -> var11US, var12 -> var12US, var21 -> var21US)
    val redundancyMap: Map[Exp, Rule] = Map(var11 -> var11RM, var12 -> var12RM, var21 -> var21RM)

    println(codeGenProgram(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  def multiProg2() = {
    val head1: Access = Access("T", Seq("x".toVar), Tensor)
    val var11: Access = Access("T1",  Seq("x".toVar, "y".toVar), Tensor)

    val head2: Access = Access("M",  Seq("x".toVar), Tensor)

    val prods1: Prod = Prod(Seq(var11))
    val body1: SoP = SoP(Seq(prods1))
    val tensorComputation1: Rule = Rule(head1, body1)

    val prods2: Prod = Prod(Seq(head1, head1))
    val body2: SoP = SoP(Seq(prods2))
    val tensorComputation2: Rule = Rule(head2, body2)

    val tensorComputation: Seq[Rule] = Seq(tensorComputation1, tensorComputation2)

    val dim11: DimInfo = DimInfo(var11, Seq("n".toVar, "m".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim11)

    val var11HeadUS: Access = Access("T1".uniqueName,  Seq("x".toVar, "y".toVar), UniqueSet)
    val var11BodyUS: SoP = dim11.toSoP
    val var11US: Rule = Rule(var11HeadUS, var11BodyUS)

    val var11HeadRM: Access = Access("T1".redundancyName,  Seq("x".toVar, "y".toVar, "x".toVar.redundancyVars, "y".toVar.redundancyVars), RedundancyMap)
    val var11BodyRM: SoP = emptySoP()
    val var11RM: Rule = Rule(var11HeadRM, var11BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var11 -> var11US)
    val redundancyMap: Map[Exp, Rule] = Map(var11 -> var11RM)

    println(codeGenProgram(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Any degree self-product -- degree 3 to degree 6 tested and seems correct -- for degree 5 and 6 I can't check actually
  def selfprodMult(n: Int): (Rule, (Rule, Rule, DimInfo)) = {
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val head: Access = Access("M", xSeq, Tensor)
    val vars: Seq[Access] = xSeq.map(x => Access("A", Seq(x), Tensor))
    val prods: Prod = Prod(vars)
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)
    val dimInfo: Seq[DimInfo] = vars.map(v => DimInfo(v, Seq("n".toVar)))

    val varHeadUS: Seq[Access] = xSeq.map(x => Access("A".uniqueName, Seq(x), UniqueSet)) 
    val varBodyUS: Seq[SoP] = dimInfo.map(dim => dim.toSoP)
    val varUS: Seq[Rule] = (varHeadUS zip varBodyUS).map{case (head, body) => Rule(head, body)}

    val varHeadRM: Seq[Access] = xSeq.map(x => Access("A".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
    val varBodyRM: Seq[SoP] = dimInfo.map(dim => emptySoP())
    val varRM: Seq[Rule] = (varHeadRM zip varBodyRM).map{case (head, body) => Rule(head, body)}

    val uniqueSets: Map[Exp, Rule] = (vars zip varUS).map{case (v, r) => (v -> r)}.toMap
    val redundancyMap: Map[Exp, Rule] = (vars zip varRM).map{case (v, r) => (v -> r)}.toMap

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  // Any degree self-product addition --
  def selfprodAdd(n: Int): (Rule, (Rule, Rule, DimInfo)) = {
    val indSeq1: Seq[Int] = (0 to n - 1)
    val xSeq1: Seq[Variable] = indSeq1.map(i => s"x$i".toVar)
    val head1: Access = Access("M", xSeq1, Tensor)
    val vars1: Seq[Access] = xSeq1.map(x => Access("A", Seq(x), Tensor))
    val prods1: Prod = Prod(vars1)
    val body1: SoP = SoP(Seq(prods1))
    val tensorComputation1: Rule = Rule(head1, body1)
    val dimInfo1: Seq[DimInfo] = vars1.map(v => DimInfo(v, Seq("n".toVar)))

    val varHeadUS1: Seq[Access] = xSeq1.map(x => Access("A".uniqueName, Seq(x), UniqueSet)) 
    val varBodyUS1: Seq[SoP] = dimInfo1.map(dim => dim.toSoP)
    val varUS1: Seq[Rule] = (varHeadUS1 zip varBodyUS1).map{case (head, body) => Rule(head, body)}

    val varHeadRM1: Seq[Access] = xSeq1.map(x => Access("A".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
    val varBodyRM1: Seq[SoP] = dimInfo1.map(dim => emptySoP())
    val varRM1: Seq[Rule] = (varHeadRM1 zip varBodyRM1).map{case (head, body) => Rule(head, body)}

    val uniqueSets1: Map[Exp, Rule] = (vars1 zip varUS1).map{case (v, r) => (v -> r)}.toMap
    val redundancyMap1: Map[Exp, Rule] = (vars1 zip varRM1).map{case (v, r) => (v -> r)}.toMap

    val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo1, uniqueSets1, redundancyMap1)



    val indSeq2: Seq[Int] = (0 to n - 1)
    val xSeq2: Seq[Variable] = indSeq2.map(i => s"x$i".toVar)
    val head2: Access = Access("N", xSeq2, Tensor)
    val vars2: Seq[Access] = xSeq2.map(x => Access("B", Seq(x), Tensor))
    val prods2: Prod = Prod(vars2)
    val body2: SoP = SoP(Seq(prods2))
    val tensorComputation2: Rule = Rule(head2, body2)
    val dimInfo2: Seq[DimInfo] = vars2.map(v => DimInfo(v, Seq("n".toVar)))

    val varHeadUS2: Seq[Access] = xSeq2.map(x => Access("B".uniqueName, Seq(x), UniqueSet)) 
    val varBodyUS2: Seq[SoP] = dimInfo2.map(dim => dim.toSoP)
    val varUS2: Seq[Rule] = (varHeadUS2 zip varBodyUS2).map{case (head, body) => Rule(head, body)}

    val varHeadRM2: Seq[Access] = xSeq2.map(x => Access("B".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
    val varBodyRM2: Seq[SoP] = dimInfo2.map(dim => emptySoP())
    val varRM2: Seq[Rule] = (varHeadRM2 zip varBodyRM2).map{case (head, body) => Rule(head, body)}

    val uniqueSets2: Map[Exp, Rule] = (vars2 zip varUS2).map{case (v, r) => (v -> r)}.toMap
    val redundancyMap2: Map[Exp, Rule] = (vars2 zip varRM2).map{case (v, r) => (v -> r)}.toMap

    val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo2, uniqueSets2, redundancyMap2)

    val p1: Prod = Prod(Seq(head1))
    val p2: Prod = Prod(Seq(head2))
    val head: Access = Access("O", xSeq1, Tensor)
    val body: SoP = SoP(Seq(p1, p2))
    val tensorComputation: Rule = Rule(head, body)
    val uniqueSets: Map[Exp, Rule] = Map(head1 -> infer1._1, head2 -> infer2._1)
    val redundancyMap: Map[Exp, Rule] = Map(head1 -> infer1._2, head2 -> infer2._2)
    val dimInfo: Seq[DimInfo] = dimInfo1 ++ dimInfo2 ++ Seq(infer1._3, infer2._3)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  def ttm(structure: String): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "l".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("ni".toVar, "nj".toVar, "nl".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("nk".toVar, "nl".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag_p" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case "uhc" => {
        val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  def thp(structure: String): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var2: Access = Access("C",  Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("ni".toVar, "nj".toVar, "nk".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("ni".toVar, "nj".toVar, "nk".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag_p" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  def mttkrp(structure: String): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "k".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "j".toVar), Tensor)
    val var3: Access = Access("D",  Seq("l".toVar, "j".toVar), Tensor)
    val head1: Access = Access("E", Seq("i".toVar, "k".toVar, "l".toVar, "j".toVar), Tensor)
    
    val prods1: Prod = Prod(Seq(var1, var2))
    val body1: SoP = SoP(Seq(prods1))
    val tensorComputation1: Rule = Rule(head1, body1)

    val prods: Prod = Prod(Seq(head1, var3))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("ni".toVar, "nk".toVar, "nl".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("nk".toVar, "nj".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("nl".toVar, "nj".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "fixed_ij" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ExpUS2: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
    val var3BodyUS: SoP = dim3.toSoP
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

    val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

    pprintTest((tensorComputation1, infer1))

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
    val newDimInfo: Seq[DimInfo] = dimInfo :+ infer1._3

    println(codeGen(tensorComputation, newDimInfo, newUniqueSets, newRedundancyMap))

    (tensorComputation, infer(tensorComputation, newDimInfo, newUniqueSets, newRedundancyMap))
  }

  def mttkrp_n(structure: String): (Rule, (Rule, Rule, DimInfo)) = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "k".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "j".toVar), Tensor)
    val var3: Access = Access("D",  Seq("l".toVar, "j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2, var3))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("ni".toVar, "nk".toVar, "nl".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("nk".toVar, "nj".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("nl".toVar, "nj".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "fixed_ij" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ExpUS2: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        SoP(Seq(var1ProdsUS))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
    val var3BodyUS: SoP = dim3.toSoP
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

    println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  }

  def e2eConstructor(n: Int) = {
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val head: Access = Access(s"cont_degree$n", xSeq, Tensor)
    val vars: Seq[Access] = xSeq.map(x => Access("cont_sum1", Seq(x), Tensor))
    val prods: Prod = Prod(vars)
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)
    val dimInfo: Seq[DimInfo] = vars.map(v => DimInfo(v, Seq("CONT_SZ".toVar)))

    val varHeadUS: Seq[Access] = xSeq.map(x => Access("cont_sum1".uniqueName, Seq(x), UniqueSet)) 
    val varBodyUS: Seq[SoP] = dimInfo.map(dim => dim.toSoP)
    val varUS: Seq[Rule] = (varHeadUS zip varBodyUS).map{case (head, body) => Rule(head, body)}

    val varHeadRM: Seq[Access] = xSeq.map(x => Access("cont_sum1".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
    val varBodyRM: Seq[SoP] = dimInfo.map(dim => emptySoP())
    val varRM: Seq[Rule] = (varHeadRM zip varBodyRM).map{case (head, body) => Rule(head, body)}

    val uniqueSets: Map[Exp, Rule] = (vars zip varUS).map{case (v, r) => (v -> r)}.toMap
    val redundancyMap: Map[Exp, Rule] = (vars zip varRM).map{case (v, r) => (v -> r)}.toMap

    val inf: (Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)

    val us: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val di: Seq[DimInfo] = dimInfo :+ inf._3
    
    (tensorComputation, di, us, rm)
  }

  def e2eAddition(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule]) = {
    val name = if (n == 0) "count" else if (n == 1) "cont_sum1" else s"cont_degree$n"
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val head: Access = Access(s"r.$name", xSeq, Tensor)
    val var1: Access = Access(name,  xSeq, Tensor)
    val var2: Access = Access(s"other.$name",  xSeq, Tensor)
    val prods1: Prod = Prod(Seq(var1))
    val prods2: Prod = Prod(Seq(var2))
    val body: SoP = SoP(Seq(prods1, prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dimSeq: Seq[Variable] = indSeq.map(i => "CONT_SZ".toVar)

    val dim1: DimInfo = DimInfo(var1, dimSeq)
    val dim2: DimInfo = DimInfo(var2, dimSeq)
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(name.uniqueName,  xSeq, UniqueSet)
    val var1BodyUS: SoP = dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(name.redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(s"other.$name".uniqueName,  xSeq, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(s"other.$name".redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](var1 -> var1US, var2 -> var2US)))((v1, v2) => v1)
    val redundancyMap: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](var1 -> var1RM, var2 -> var2RM)))((v1, v2) => v1)

    val inf: (Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._3
    
    (tensorComputation, diF, usF, rmF)
  }

  def e2eMultiplication(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule]) = {
    val degrees: Seq[Int] = (0 to n)
    val outName: String = if (n == 0) "r.count" else if (n == 1) "r.cont_sum1" else s"r.cont_degree$n"
    val (prods, dimInfo, newUS, newRM): (Seq[Prod], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule]) = degrees.foldLeft((Seq.empty[Prod], Seq.empty[DimInfo], us, rm))((acc, i) => {
      val (degA, degB): (Int, Int) = (n - i, i)
      val nameA: String = if (degA == 0) "count" else if (degA == 1) "cont_sum1" else s"cont_degree$degA"
      val nameB: String = if (degB == 0) "other.count" else if (degB == 1) "other.cont_sum1" else s"other.cont_degree$degB"
      val xSeqA: Seq[Variable] = (0 to degA - 1).map(i => s"x$i".toVar)
      val xSeqB: Seq[Variable] = (degA to n - 1).map(i => s"y$i".toVar)
      val xSeqFakeB: Seq[Variable] = (0 to degB - 1).map(i => s"x$i".toVar)
      val xMapB: Map[Variable, Variable] = mergeMap(Seq((xSeqFakeB zip xSeqB).toMap, Map[Variable, Variable]("CONT_SZ".toVar -> "CONT_SZ2".toVar)))((v1, v2) => v1)
      val headFakeB: Access = Access(nameB, xSeqFakeB, Tensor)
      val (bFakeUS, bFakeRM): (Rule, Rule) = (acc._3.getOrElse(headFakeB, emptyRule), acc._4.getOrElse(headFakeB, emptyRule))
      val (bUS, bRM): (Rule, Rule) = if (degB != 0) (replaceVars(bFakeUS, xMapB), replaceVars(bFakeRM, xMapB)) else (bFakeUS, bFakeRM)
      val headA: Access = Access(nameA, xSeqA, Tensor)
      val headB: Access = Access(nameB, xSeqB, Tensor)
      val newUS: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headB -> bUS), acc._3))((v1, v2) => v1)
      val newRM: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headB -> bRM), acc._4))((v1, v2) => v1)
      val dimSeqA: Seq[Variable] = xSeqA.map(i => "CONT_SZ".toVar)
      val dimSeqB: Seq[Variable] = xSeqB.map(i => "CONT_SZ2".toVar)
      val dimA: DimInfo = DimInfo(headA, dimSeqA)
      val dimB: DimInfo = DimInfo(headB, dimSeqB)
      val dimInfo: Seq[DimInfo] = Seq(dimA, dimB)
      
      val compSeqB: Seq[Variable] = (degA to n - 1).map(i => s"x$i".toVar)
      val comp: Seq[Comparison] = (compSeqB zip xSeqB).map{case (x, y) => Comparison("=", Arithmetic("-", x, "CONT_SZ".toVar), y)}

      (acc._1 :+ Prod(Seq(headA, headB) ++ comp), acc._2 ++ dimInfo, newUS, newRM)
    })
    val xSeq: Seq[Variable] = (0 to n - 1).map(i => s"x$i".toVar)
    val head: Access = Access(outName, xSeq, Tensor)
    val body = SoP(prods)
    val tensorComputation: Rule = Rule(head, body)

    val inf: (Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, newUS, newRM)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), newUS))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), newRM))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._3
    
    (tensorComputation, diF, usF, rmF)
  }

  def e2eLR() = {
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = e2eConstructor(2)
    // println(codeGen(const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap))
    // println("===========================================================")
    val us2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> v)}.toMap
    val rm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> v)}.toMap
    val us: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, us2))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, rm2))((v1, v2) => v1)

    val (add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap) = e2eAddition(2, us, rm)
    // println(codeGen(add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap))
    // println("===========================================================")

    val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap) = e2eMultiplication(2, us, rm)
    println("##########################")
    println("Dim_Info:", mult_dimInfo)
    println("newUS:", mult_uniqueSets)
    println("newRM:", mult_redundancyMap)
    println(mult_tensorComputation.prettyFormat)
    println(codeGen(mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap))
    println("===========================================================")
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
  // pprintTest(test10())
  // pprintTest(test11())
  // pprintTest(test12())
  // pprintTest(test13())
  // pprintTest(test13n())
  // pprintTest(test14())
  // pprintTest(test15())
  // pprintTest(test16())
  // pprintTest(test17())
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
  e2eLR()

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

  // println(Variable("a").equals(Variable("a")))

  // val a: Map[String, Seq[Int]] = Map("a" -> Seq(2))
  // println(a.getOrElse("b", 12))
  // val b: Map[String, Seq[Int]] = Map("a" -> Seq(3))
  // println(mergeMap(Seq(a, b))((v1, v2) => v1 ++ v2))

}