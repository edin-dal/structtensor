package uk.ac.ed.dal
package structtensor
package compiler

import scala.collection.mutable.ArraySeq
import scala.sys.process._
import scala.io.Source
import apps.Shared

object Compiler {
  import STURHelper._
  import Shared._

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

  def mergeMap[A, B](ms: Seq[Map[A, B]])(f: (B, B) => B): Map[A, B] = ms.flatten.foldLeft(Map[A, B]())((a, kv) => a + (if (a.contains(kv._1)) (kv._1 -> f(a(kv._1), kv._2)) else kv))

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
      // println(s"i1: $i1, i2: $i2")
      // println(s"e1: $e1, e2: $e2")
      // println(accessMap)
      // println(inp1DimSeq)
      // println(inp2DimSeq)
      if (i1 == -1 && i2 == -1) Arithmetic("+", ConstantInt(1), v) else if (i2 == -1) inp1DimSeq(i1) else if (i1 == -1) inp2DimSeq(i2) else if (multOrAdd == "mult") dimMin(inp1DimSeq(i1), inp2DimSeq(i2)) else if (multOrAdd == "add") dimMax(inp1DimSeq(i1), inp2DimSeq(i2)) else if (inp1DimSeq.length > i1) inp1DimSeq(i1) else inp2DimSeq(i2) // last 2 else shouldn't happen normally
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
        if (areProdTCsEqiv(tc, firstTC) && !isSoPDisjoint(us1.body, us2.body) && !isSoPDisjoint(rm1.body, rm2.body)) {
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
    // println("infer:")
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
          case "==" => if (eqVarMap.contains(variable)) (Seq(), Seq()) else (Seq(index), Seq(Arithmetic("+", index, ConstantInt(1))))
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

  def linearizedIndexes(US : Rule, dimVars : Set[Variable]) : Seq[String] = {
    // println("Target unique set:")
    // println(US.prettyFormat()+"\n")
    val it_names = US.head.vars
    val nit = it_names.size

    // Extract parameters from the products

    def index_add_param(i : Index, set : Set[Variable]) : Set[Variable] = {
      i match {
        case Variable(name) => if (it_names contains i) set else set + i.asInstanceOf[Variable]
        case Arithmetic(_, index1, index2) =>
          index_add_param(index1, index_add_param(index2, set))
        case _ => set
      }
    }
    val exp_add_param = (e : Exp, set : Set[Variable]) => {
      e match {
        case Comparison(op, index, variable) => index_add_param(index, set)
        case _ => throw new Exception("Should be only Comparison here ?")
      }
    }

    val params = US.body.prods.map((bUS : Prod) => {
      val init = Set.empty[Variable]
      bUS.exps.foldRight(init)(exp_add_param)
    }).fold(Set.empty[Variable])(_|_).toList

    // println("Detected linearized index parameters:")
    // println(params)

    // Generate constraints matrices

    val np = params.size

    val var_indices : Map[Variable, Int] = (it_names.zipWithIndex.map{case(v,i) => (v,i+1)} ++ params.zipWithIndex.map{case(v,i) => (v,i+1+it_names.size)}).toMap
    // println("var indices:")
    // println(var_indices)

    // Translate all that to ISL-syntax
    // Iterate over top level sum (~ over polyhedras)
    US.body.prods.map((bUS : Prod) => {
      // Iterate over each factor (~ constraint)
      val isl_unique_set = "[" + params.map(_.name).mkString(",") + "] -> {[" + it_names.map(_.name).mkString(",") + "] : " +
      bUS.exps.filter((e : Exp) => {
        val ec = e.asInstanceOf[Comparison]
        ec.op match {
          case "=" => it_names contains ec.index
          case _ => it_names contains ec.variable
        }
      }).map(_.prettyFormat()).mkString(" and ") + "}"
      println(isl_unique_set)
    (s"echo ${"S := " + isl_unique_set + "; card (S << S);"}" #|("iscc")).!!.trim()
    })
  }

  def codeGenRule(tensorComputation: Rule, dimInfo: Seq[DimInfo], variables: Seq[Variable], intervals: Seq[Map[Variable, Interval]], equalityVarMap: Seq[Map[Variable, Index]], genType: AccessType, peqMode: Boolean = true, codeMotion: Boolean = true, dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map()): String = {
    // we should make sure that all the variables that are in the right hand side of an addition, we have a condition over them or we don't add them at all. Look at e2eLRDimInfo3.txt, first for loop, for this!
    val vars = if (genType == RedundancyMap) variables.redundancyVarsInplace else variables
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val dimVarMap: Map[Variable, Seq[Dim]] = dimInfo.toVarsMap
    val tcBodya: SoP = getNoComparisonSoP(tensorComputation.body) 
    val tcBodyEQ: SoP = getNoComparisonButEQSoP(tensorComputation.body)

    if (intervals == Seq.empty[Map[Variable, Interval]]) {
      if (tensorComputation.head.vars == Seq.empty[Variable]) return s"${tensorComputation.head.cFormat} += ${tcBodya.cFormat};"
      else return ""
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
              if (vars.slice(0, variableInd._2 + 1).toSet == tensorComputation.head.vars.toSet) s"""affine.for %${variable.cFormat(eqVar)} = %$beginVar to %$endVar step 1 {\n"""
              else if (!vars.slice(0, variableInd._2 + 1).toSet.subsetOf(tensorComputation.head.vars.toSet)) s"""%${variable.cFormat(eqVar)}_sum = affine.for %${variable.cFormat(eqVar)} = %$beginVar to %$endVar step 1 iter_args(%iter_sum_${variable.cFormat(eqVar)} = %zerof) -> (f64) {\n"""
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

      val body = if (tcBody.prods.length == 1) s"${tcBody.prods(0).MLIRFormat(eqVar, finalV, cnt_inc = cnt)}" else tcBody.MLIRFormat(eqVar, finalV, cnt_inc = cnt)
      cnt += 200

      val filteredVars = vars.reverse.filter(e => !cntVars.contains(e))
      val reverseVars = vars.reverse
      val finalBrackets = filteredVars.zipWithIndex.foldLeft("")((acc, vi) => {
        val v = vi._1
        val i = vi._2
        if (codeMotion && finalHeadComputation.vars.length > 0 && finalHeadComputation.vars(0) == v) s"$acc${finalHeadComputation.cFormat(eqVar, dataLayoutMap.getOrElse(finalHeadComputation, defaultDataLayout))} += tmp;\n}\n"
        else {
          val containsV = beginEndEqVars.contains(v)
          val (cmpSet, ind) = conditionSetsMap.getOrElse(v, ("", ""))
          val nc = if (reverseVars.slice(i, reverseVars.length).toSet == tensorComputation.head.vars.toSet) {
            val (varsStr, sizeStr, indexStr) = tensorComputation.head.vars.foldLeft(("", "", ""))((acc2, v) => {
              val (varsStr, sizeStr, indexStr) = acc2
              val newVarStr = if (varsStr.length == 0) s"%${v.cFormat(eqVar)}" else s"$varsStr, %${v.cFormat(eqVar)}"
              val newSizeStr = s"${sizeStr}?x"
              val newIndexStr = if (indexStr.length == 0) s"index" else s"$indexStr, index"
              (newVarStr, newSizeStr, newIndexStr)
            })
            if (peqMode) {
              val preVal = getVar("preVal")
              val peqVal = getVar("peqVal")
              val preValCode = s"""%$preVal = ${tensorComputation.head.loadMLIR(eqVar)}"""
              val peqValCode = if (i != 0) s"""%$peqVal = "arith.addf"(%${filteredVars(i - 1).cFormat(eqVar)}_sum, %$preVal) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n""" else s"""%$peqVal = "arith.addf"(%$finalV, %$preVal) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"""
              s"""$preValCode${peqValCode}affine.store %$peqVal, %${tensorComputation.head.name}[$varsStr] : memref<${sizeStr}f64>\n"affine.yield"() : () -> ()\n}${if (containsV) s""", {"affine.yield"(): () -> ()}) $cmpSet : ($ind) -> ()""" else ""}"""
            } else s"""affine.store %${filteredVars(i - 1).cFormat(eqVar)}_sum, %${tensorComputation.head.name}[$varsStr] : memref<${sizeStr}f64>\n"affine.yield"() : () -> ()\n}${if (containsV) s""", {"affine.yield"(): () -> ()}) $cmpSet : ($ind) -> ()""" else ""}"""
          }
          else if (i == 0) {
            if (containsV) s""""affine.yield"(%$finalV): (f64) -> ()\n}, {"affine.yield"(%zerof): (f64) -> ()}) $cmpSet : ($ind) -> f64"""
            else s"""%new_sum_${v.cFormat(eqVar)} = "arith.addf"(%$finalV, %iter_sum_${v.cFormat(eqVar)}) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"affine.yield"(%new_sum_${v.cFormat(eqVar)}): (f64) -> ()\n}"""
          } else if (tensorComputation.head.vars.toSet.subsetOf(filteredVars.slice(i, filteredVars.length).toSet) && filteredVars.slice(i, filteredVars.length).toSet != tensorComputation.head.vars.toSet) {
            if (containsV) s""""affine.yield"(%${filteredVars(i - 1).cFormat(eqVar)}_sum): (f64) -> ()\n}, {"affine.yield"(%zerof): (f64) -> ()}) $cmpSet : ($ind) -> f64"""
            else s"""%new_sum_${v.cFormat(eqVar)} = "arith.addf"(%${filteredVars(i - 1).cFormat(eqVar)}_sum, %iter_sum_${v.cFormat(eqVar)}) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64\n"affine.yield"(%new_sum_${v.cFormat(eqVar)}): (f64) -> ()\n}"""
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

  def sturOptCodeGen(stur: String, codeLang: String, compress: Boolean, append_stur_opt_file: Boolean, run_stur_opt: Boolean): String = {
    if (stur.contains("∅")) return ""
    write2File(s"stur_output/ex.stur", stur, append_stur_opt_file)
    if (run_stur_opt) {
      val newCodeLang = if (codeLang == "default") "C" else if (codeLang == "CPP") "C++" else codeLang
      val compress_flag = if(compress) "--compress" else ""
      s"stur-opt stur_output/ex.stur -t $newCodeLang --print-op-generic --timer $compress_flag".!!
    }
    else ""
  }

  def codeGen(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule], codeGenMode: Int = 0, peqMode: Boolean = true, variableReplacementFlag: Boolean = true, codeMotion: Boolean = true, dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map(), varReverse: Boolean = false, codeLang: String = "default", compressionMaps: Map[Exp, Rule] = Map(), sturOpt: Boolean = false, compress: Boolean = false, append_stur_opt_file: Boolean = false, run_stur_opt: Boolean = true): String = {
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


    // val map = linearizedIndexes(finalUS, allDimVars.toSet)
    // println("\n\n\nComputed maps:")
    // println(map.map(_.toString()).mkString("\n\n"))

    // println(finalC.prettyFormat)
    

    // // println("variables:")
    // // println(variables)
    // println("==================")
    // println("Tensor Computation")
    // pprint(tensorComputation)
    // println("==================")
    // println("outUS")
    // pprint(outUS)
    // println("------------------")
    // println("outRM")
    // pprint(outRM)
    // println("------------------")
    // println("outC")
    // pprint(outC)
    // // println("------------------")
    // // println("outDI")
    // // println(dimInfo :+ outDI)
    // println("==================")
    // // println("variableConditionMapUS")
    // // println(variableConditionMapUS)
    // // println("------------------")
    // // println("variableConditionMapRM")
    // // println(variableConditionMapRM)
    // // println("------------------")
    // println("variableConditionMapC")
    // println(variableConditionMapC)
    // println("==================")
    // // println("unifiedVariableConditionMapUS")
    // // println(unifiedVariableConditionMapUS)
    // // println("------------------")
    // // println("unifiedVariableConditionMapRM")
    // // println(unifiedVariableConditionMapRM)
    // // println("------------------")
    // println("unifiedVariableConditionMapC")
    // println(unifiedVariableConditionMapC)
    // println("==================")
    // // println("unifiedOutUS")
    // // pprint(unifiedOutUS)
    // // println("------------------")
    // // println("unifiedOutRM")
    // // pprint(unifiedOutRM)
    // // println("------------------")
    // println("unifiedOutC")
    // pprint(unifiedOutC)
    // println("==================")
    // // println("distinctOutUS")
    // // pprint(distinctOutUS)
    // // println("------------------")
    // // println("distinctOutRM")
    // // pprint(distinctOutRM)
    // // println("------------------")
    // println("distinctOutC")
    // pprint(distinctOutC)
    // println("==================")
    // println("simplifiedOutUS")
    // pprint(simplifiedOutUS)
    // println("------------------")
    // println("simplifiedOutRM")
    // pprint(simplifiedOutRM)
    // println("------------------")
    // println("simplifiedOutC")
    // pprint(simplifiedOutC)
    // println("==================")
    // // println("distinctConditionMapUS")
    // // println(distinctConditionMapUS)
    // // println("------------------")
    // // println("distinctConditionMapRM")
    // // println(distinctConditionMapRM)
    // // println("------------------")
    // println("distinctConditionMapC")
    // println(distinctConditionMapC)
    // println("==================")
    // // println("fixedConditionOrderUS")
    // // println(fixedConditionOrderUS)
    // // println("------------------")
    // // println("fixedConditionOrderRM")
    // // println(fixedConditionOrderRM)
    // // println("------------------")
    // println("fixedConditionOrderC")
    // println(fixedConditionOrderC)
    // println("==================")
    // // println("removedNonLHSVarsUS")
    // // println(removedNonLHSVarsUS)
    // // println("------------------")
    // // println("removedNonLHSVarsRM")
    // // println(removedNonLHSVarsRM)
    // // println("------------------")
    // // println("removedNonLHSVarsC")
    // // println(removedNonLHSVarsC)
    // // println("==================")
    // // println("eqVarMapUS")
    // // println(eqVarMapUS)
    // // println("------------------")
    // // println("eqVarMapRM")
    // // println(eqVarMapRM)
    // // println("------------------")
    // println("eqVarMapC")
    // println(eqVarMapC)
    // println("==================")
    // // println("intervalsUS")
    // // println(intervalsUS)
    // // println("------------------")
    // // println("intervalsRM")
    // // println(intervalsRM)
    // // println("------------------")
    // println("intervalsC")
    // println(intervalsC)
    // println("==================")
    // // println("intervalsSimplifiedUS")
    // // println(intervalsSimplifiedUS)
    // // println("------------------")
    // // println("intervalsSimplifiedRM")
    // // println(intervalsSimplifiedRM)
    // // println("------------------")
    // println("intervalsSimplifiedC")
    // println(intervalsSimplifiedC)
    // println("==================")
    // // println("finalUS")
    // // pprint(finalUS)
    // // println("------------------")
    // // println("finalRM")
    // // pprint(finalRM)
    // // println("------------------")
    // println("finalC")
    // pprint(finalC)
    // println("==================")
    // println("PathC")
    // pathC.foldLeft()((acc, cur) => {
    //   val (tensorComputationC, intervalC, eqMapC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
    //   println("********************")
    //   println("Tensor Computation")
    //   pprint(tensorComputationC)
    //   println("Interval")
    //   println(intervalC(0))
    //   println("Equality Var Map")
    //   println(eqMapC(0))
    //   println("********************")
    // })
    // // println("------------------")
    // // println("PathRC")
    // // pathRC.foldLeft()((acc, cur) => {
    // //   val (tensorComputationRC, intervalRC, eqMapRC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
    // //   println("********************")
    // //   println("Tensor Computation")
    // //   pprint(tensorComputationRC)
    // //   println("Interval")
    // //   println(intervalRC(0))
    // //   println("Equality Var Map")
    // //   println(eqMapRC(0))
    // //   println("********************")
    // // })
    // println("==================")

    // println("JSON>>>")
    // println(codegen.JsonGenerator.codegen(pathC.last._1.head))




    if (sturOpt) {
      // Makes a call to stur-opt and gets the generated code.

      val (computation_stur, computation_stur2p, _): (String, String, Boolean) = pathC.foldLeft(("", "", false))((acc, cur) => {
        val (tensorComputationC, intervalC, eqMapC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
        val comps: SoP = getSoPFromInterval(intervalC, eqMapC)
        val head: Access = tensorComputationC.head
        val body: SoP = SoPTimesSoP(tensorComputationC.body, comps)
        val finalRule: Rule = Rule(head, body)
        val res: String = finalRule.prettyFormat
        val res2: String = finalRule.body.prettyFormat
        // val peqC: Boolean = peqMode | acc._2
        // val res: String = codeGenRuleMLIR(tensorComputationC, dimInfo :+ outDI, variables, intervalC, eqMapC, UniqueSet, peqC, codeMotion, dlMapFinal)
        (acc._1 + res + "\n", acc._2 + res2 + " + ", true)
      })
      val finalRC: Rule = Rule(tensorComputationRC.head, SoPTimesSoP(tensorComputationRC.body, getSoPFromInterval(intervalsSimplifiedRM, eqVarMapRM)))
      val pathRC: Seq[(Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]])] = getFinalCodeGenPath(tensorComputation.head, finalRC, intervalsSimplifiedRM, eqVarMapRM)
      val (reconstruction_stur, reconstruction_stur2p, _): (String, String, Boolean) = pathRC.foldLeft(("", "", false))((acc, cur) => {
        val (tensorComputationRC, intervalRC, eqMapRC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
        val comps: SoP = getSoPFromInterval(intervalRC, eqMapRC)
        val head: Access = tensorComputationRC.head
        val body: SoP = SoPTimesSoP(tensorComputationRC.body, comps)
        val finalRule: Rule = Rule(head, body)
        val res: String = finalRule.prettyFormat
        val res2: String = finalRule.body.prettyFormat
        // val peqC: Boolean = peqMode | acc._2
        (acc._1 + res + "\n", acc._2 + res2 + " + ", true)
      })
      // val compsRC = getSoPFromInterval(intervalsSimplifiedRM, eqVarMapRM)
      // val headRC: Access = tensorComputationRC.head
      // val bodyRC: SoP = SoPTimesSoP(tensorComputationRC.body, compsRC)
      // val finalRuleRC: Rule = Rule(headRC, bodyRC)
      // val reconstruction_stur: String = finalRuleRC.prettyFormat
      
      val computation_stur2 = tensorComputation.head.prettyFormat + " := " + computation_stur2p.dropRight(3) + "\n"
      val reconstruction_stur2 = tensorComputation.head.prettyFormat + " := " + reconstruction_stur2p.dropRight(3) + "\n"

      println("Computation:")
      println(computation_stur)
      println("Reconstruction:")
      println(reconstruction_stur)

      println("Computation2:")
      println(computation_stur2)
      println("Reconstruction2:")
      println(reconstruction_stur2)

      val computation_stur_code2: String = sturOptCodeGen(computation_stur2, codeLang, compress, append_stur_opt_file, run_stur_opt)
      val reconstruction_stur_code2: String = sturOptCodeGen(reconstruction_stur2, codeLang, compress, append_stur_opt_file, run_stur_opt)
      
      println("Computation Code:")
      println(computation_stur_code2)
      println("Reconstruction Code:")
      println(reconstruction_stur_code2)

      codeGenMode match {
        case 0 => "void compute() {\n" + computation_stur_code2 + "\n}\n\n\nvoid reconstruct() {\n" + reconstruction_stur_code2 + "\n}\n"
        case 1 => computation_stur_code2
        case 2 => reconstruction_stur_code2
        case _ => ""
      }      
    } else {
      if (codeLang == "MLIR") {
        val computation: String = pathC.foldLeft(("", false))((acc, cur) => {
          val (tensorComputationC, intervalC, eqMapC): (Rule, Seq[Map[Variable, Interval]], Seq[Map[Variable, Index]]) = cur
          val peqC: Boolean = peqMode | acc._2
          val res: String = codeGenRuleMLIR(tensorComputationC, dimInfo :+ outDI, variables, intervalC, eqMapC, UniqueSet, peqC, codeMotion, dlMapFinal)
          (acc._1 + "\n" + res, true)
        })._1
        val reconstruction: String = codeGenRuleMLIR(tensorComputationRC, dimInfo :+ outDI, variables.redundancyVarsInplace, intervalsSimplifiedRM, eqVarMapRM, UniqueSet, false, codeMotion, dlMapFinal)

        if (codeGenMode == 0) "void compute() {\n" + computation + "\n}\n\n\nvoid reconstruct() {\n" + reconstruction + "\n}\n"
        else if (codeGenMode == 1) computation
        else if (codeGenMode == 2) reconstruction
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
}