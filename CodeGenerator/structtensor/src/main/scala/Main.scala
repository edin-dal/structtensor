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
    s"${name}(${pr.substring(2, pr.length)})"
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

  def pprint(r: Rule): Unit = println(r.prettyFormat)

  def pprintTest(rTUR: (Rule, (Rule, Rule))): Unit = {
    println("=========================================")
    println("Computation:")
    pprint(rTUR._1)
    println("Unique Set:")
    pprint(rTUR._2._1)
    println("Redundancy Map:")
    pprint(rTUR._2._2)
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

  def binMult(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
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
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
            } else {
              val bodyUS: SoP = SoPTimesSoP(e1US, e2US)
              val bodyRM: SoP = concatSoP(Seq(SoPTimesSoP(e1RM, e2RM), 
              SoPTimesSoP(SoPTimesSoP(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1))))), e2RM), 
              SoPTimesSoP(SoPTimesSoP(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2))))), e1RM)))
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
            }
          } else {
            val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e2US), SoPTimesSoP(e1RM, e2US), SoPTimesSoP(e1US, e2RM)))
            val bodyRM: SoP = SoPTimesSoP(e1RM, e2RM)
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          }
        } else {
          val headP: Access = Access(head.name.redundancyVars.name, vars1.union(vars2), head.kind)
          val us_rm: (Rule, Rule) = binMult(headP, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
          return project(head, dimInfo, headP, us_rm._1, us_rm._2)
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
        if (op1 == "<=" && op2 == "<" && variable1 == index2) { // I should put different conditions that are equivalent
          val bodyUS: SoP = SoP(Seq(Prod(Seq(Comparison("=", index1, variable1)))))
          val bodyRM: SoP = SoP(Seq(Prod(Seq(Comparison("<", index1, variable1), e2, Comparison("=", index1, variable1.redundancyVars))))) // inp1RM.head.vars.diff(Seq(variable1))??
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
        } else {
          val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(inp1US.body, inp2US.body), SoPTimesSoP(inp1RM.body, inp2US.body), SoPTimesSoP(inp1US.body, inp2RM.body), SoP(Seq(Prod(Seq(e1, e2))))))
          val bodyRM: SoP = SoPTimesSoP(inp1RM.body, inp2RM.body)
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
        }
      }
    }
    (inp1US, inp1RM)
  }

  def binAdd(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    println(bounds)
    println(inp1US.prettyFormat)
    println(inp2US.prettyFormat)
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet) 
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet) 
        val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
        val e2RM: SoP = includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap) 
        println(e1US.prettyFormat)
        println(e2US.prettyFormat)
        if (vars1 == vars2) {
          if (isSoPEquals(e1US, e2US) && isSoPEquals(e1RM, e2RM)) {
            val bodyUS: SoP = e1US
            val bodyRM: SoP = e1RM
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          } else {
            val bodyUS: SoP = concatSoP(Seq(e1US, e2US, e1RM, e2RM))
            val bodyRM: SoP = SoP(Seq())
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          }
        } else { // a fake else
          val bodyUS: SoP = concatSoP(Seq(e1US, e2US, e1RM, e2RM))
          val bodyRM: SoP = SoP(Seq())
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binAdd(head, dimInfo, e2, e1, inp2US, inp2RM, inp1US, inp1RM)
      case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
        
      }
    }
    (inp1US, inp1RM)
  }

  def project(head: Access, dimInfo: Seq[DimInfo], e: Exp, inp1US: Rule, inp1RM: Rule): (Rule, Rule) = {
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    e match {
      case Access(nameE, varsE, Tensor) => {
        val eUS: SoP = includeBoundaries(inp1US.body, bounds, e.asInstanceOf[Access], UniqueSet) 
        val eRM: SoP = includeBoundaries(inp1RM.body, bounds, e.asInstanceOf[Access], RedundancyMap) 
        if (varsE.toSet.subsetOf(outVars.toSet)) return (Rule(headUS, eUS), Rule(headRM, eRM))
        else if(outVars.toSet.subsetOf(varsE.toSet)) {
          val bodyUS: SoP = concatSoP(Seq(eUS, eRM))
          val bodyRM: SoP = SoP(Seq())
          return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
        }
      }
      case Comparison(op, index, variable) => {

      }
    }
    (inp1US, inp1RM)
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

  def binDirectSum(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, e2Seq: Seq[Comparison], inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule) = {
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
        return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
      }
    }
    (inp1US, inp1RM)
  }

  def isPairwiseIntersectEmpty(vars: Seq[Seq[Variable]]): Boolean = {
    vars.foldLeft(true)((acc, cur) => {
      acc && vars.foldLeft(true)((acc2, cur2) => {
        if(cur != cur2) acc2 && isIntersectEmpty(cur, cur2)
        else acc2
      })
    })
  }

  def mult3(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, e3: Exp, inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule, inp3US: Rule, inp3RM: Rule): (Rule, Rule) = { 
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    (e1, e2, e3) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor), Access(name3, vars3, Tensor)) => {
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet)
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet)
        val e3US: SoP = includeBoundaries(inp3US.body, bounds, e3.asInstanceOf[Access], UniqueSet)
        val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
        val e2RM: SoP = includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap)
        val e3RM: SoP = includeBoundaries(inp3RM.body, bounds, e3.asInstanceOf[Access], RedundancyMap) 
        if (isPairwiseIntersectEmpty(Seq(vars1, vars2, vars3))) {
          if (name1 == name2 && name2 == name3) {
            val e1Red = inp1RM.head.vars.diff(vars1)
            val e2Red = inp2RM.head.vars.diff(vars2)
            val e3Red = inp3RM.head.vars.diff(vars3)
            val e1US_allvars: SoP = SoPTimesSoP(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, e1Red))))
            val e2US_allvars: SoP = SoPTimesSoP(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, e2Red))))
            val e3US_allvars: SoP = SoPTimesSoP(e3US, SoP(Seq(vectorizeComparisonMultiplication("=", vars3, e3Red))))
            val c11Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars1)))
            val c12Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars2)))
            val c12lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars1, vars2)))
            val c12eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars1, vars2)))
            val c13Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars3)))
            val c13lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars1, vars3)))
            val c13eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars1, vars3)))
            val c21Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars1)))
            val c21lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars2, vars1)))
            val c21eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars2, vars1)))
            val c22Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars2)))
            val c23Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars3)))
            val c23lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars2, vars3)))
            val c23eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars2, vars3)))
            val c31Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars1)))
            val c31lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars3, vars1)))
            val c31eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars3, vars1)))
            val c32Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars2)))
            val c32lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars3, vars2)))
            val c32eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars3, vars2)))
            val c33Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars3)))

            
            val bodyUS: SoP = multSoP(Seq(e1US, e2US, e3US, SoP(Seq(vectorizeComparisonMultiplication("<=", vars1, vars2))), SoP(Seq(vectorizeComparisonMultiplication("<=", vars2, vars3)))))
            val bodyRM: SoP = concatSoP(Seq(
              multSoP(Seq(e1RM, e2RM, e3RM)), 
              
              multSoP(Seq(e1US_allvars, e2RM, e3RM)), 
              multSoP(Seq(e1RM, e2US_allvars, e3RM)), 
              multSoP(Seq(e1RM, e2RM, e3US_allvars)), 
              
              multSoP(Seq(e1US_allvars, e2US_allvars, e3RM)), 
              multSoP(Seq(e1US_allvars, e2RM, e3US_allvars)), 
              multSoP(Seq(e1RM, e2US_allvars, e3US_allvars)), 
            
              multSoP(Seq(e1US, e2US, e3US, c13eq, c32lt, c11Red, c23Red, c32Red)), 
              multSoP(Seq(e1US, e2US, e3US, c13lt, c32eq, c11Red, c23Red, c32Red)), 
              multSoP(Seq(e1US, e2US, e3US, c13lt, c32lt, c11Red, c23Red, c32Red)), 
              multSoP(Seq(e1US, e2US, e3US, c21eq, c13lt, c12Red, c21Red, c33Red)), 
              multSoP(Seq(e1US, e2US, e3US, c21lt, c13eq, c12Red, c21Red, c33Red)), 
              multSoP(Seq(e1US, e2US, e3US, c21lt, c13lt, c12Red, c21Red, c33Red)), 
              multSoP(Seq(e1US, e2US, e3US, c23eq, c31lt, c12Red, c23Red, c31Red)), 
              multSoP(Seq(e1US, e2US, e3US, c23lt, c31eq, c12Red, c23Red, c31Red)), 
              multSoP(Seq(e1US, e2US, e3US, c23lt, c31lt, c12Red, c23Red, c31Red)), 
              multSoP(Seq(e1US, e2US, e3US, c31eq, c12lt, c13Red, c21Red, c32Red)), 
              multSoP(Seq(e1US, e2US, e3US, c31lt, c12eq, c13Red, c21Red, c32Red)), 
              multSoP(Seq(e1US, e2US, e3US, c31lt, c12lt, c13Red, c21Red, c32Red)), 
              multSoP(Seq(e1US, e2US, e3US, c32eq, c21lt, c13Red, c22Red, c31Red)), 
              multSoP(Seq(e1US, e2US, e3US, c32lt, c21eq, c13Red, c22Red, c31Red)), 
              multSoP(Seq(e1US, e2US, e3US, c32lt, c21lt, c13Red, c22Red, c31Red))
            ))
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          }
        }
      }
    }
    (inp1US, inp1RM)
  }

  def mult4(head: Access, dimInfo: Seq[DimInfo], e1: Exp, e2: Exp, e3: Exp, e4: Exp, inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule, inp3US: Rule, inp3RM: Rule, inp4US: Rule, inp4RM: Rule): (Rule, Rule) = { 
    val outVars: Seq[Variable] = head.vars
    val name: String = head.name
    val headUS: Access = Access(name.uniqueName, outVars, UniqueSet)
    val headRM: Access = Access(name.redundancyName, outVars.redundancyVarsInplace, RedundancyMap)
    val bounds: Map[Access, Prod] = dimInfo.toComparisonAccessProdMap
    (e1, e2, e3, e4) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor), Access(name3, vars3, Tensor), Access(name4, vars4, Tensor)) => {
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access], UniqueSet)
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access], UniqueSet)
        val e3US: SoP = includeBoundaries(inp3US.body, bounds, e3.asInstanceOf[Access], UniqueSet)
        val e4US: SoP = includeBoundaries(inp4US.body, bounds, e4.asInstanceOf[Access], UniqueSet)
        val e1RM: SoP = includeBoundaries(inp1RM.body, bounds, e1.asInstanceOf[Access], RedundancyMap) 
        val e2RM: SoP = includeBoundaries(inp2RM.body, bounds, e2.asInstanceOf[Access], RedundancyMap)
        val e3RM: SoP = includeBoundaries(inp3RM.body, bounds, e3.asInstanceOf[Access], RedundancyMap) 
        val e4RM: SoP = includeBoundaries(inp4RM.body, bounds, e4.asInstanceOf[Access], RedundancyMap) 
        if (isPairwiseIntersectEmpty(Seq(vars1, vars2, vars3, vars4))) {
          if (name1 == name2 && name2 == name3 && name3 == name4) {
            val e1Red = inp1RM.head.vars.diff(vars1)
            val e2Red = inp2RM.head.vars.diff(vars2)
            val e3Red = inp3RM.head.vars.diff(vars3)
            val e4Red = inp4RM.head.vars.diff(vars4)
            val e1US_allvars: SoP = SoPTimesSoP(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, e1Red))))
            val e2US_allvars: SoP = SoPTimesSoP(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, e2Red))))
            val e3US_allvars: SoP = SoPTimesSoP(e3US, SoP(Seq(vectorizeComparisonMultiplication("=", vars3, e3Red))))
            val e4US_allvars: SoP = SoPTimesSoP(e4US, SoP(Seq(vectorizeComparisonMultiplication("=", vars4, e4Red))))
            val c11Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars1)))
            val c12Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars2)))
            val c12lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars1, vars2)))
            val c12eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars1, vars2)))
            val c13Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars3)))
            val c13lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars1, vars3)))
            val c13eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars1, vars3)))
            val c14Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e1Red, vars4)))
            val c14lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars1, vars4)))
            val c14eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars1, vars4)))
            val c21Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars1)))
            val c21lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars2, vars1)))
            val c21eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars2, vars1)))
            val c22Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars2)))
            val c23Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars3)))
            val c23lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars2, vars3)))
            val c23eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars2, vars3)))
            val c24Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e2Red, vars4)))
            val c24lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars2, vars4)))
            val c24eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars2, vars4)))
            val c31Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars1)))
            val c31lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars3, vars1)))
            val c31eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars3, vars1)))
            val c32Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars2)))
            val c32lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars3, vars2)))
            val c32eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars3, vars2)))
            val c33Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars3)))
            val c34Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e3Red, vars4)))
            val c34lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars3, vars4)))
            val c34eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars3, vars4)))
            val c41Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e4Red, vars1)))
            val c41lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars4, vars1)))
            val c41eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars4, vars1)))
            val c42Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e4Red, vars2)))
            val c42lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars4, vars2)))
            val c42eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars4, vars2)))
            val c43Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e4Red, vars3)))
            val c43lt: SoP = SoP(Seq(vectorizeComparisonMultiplication("<", vars4, vars3)))
            val c43eq: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", vars4, vars3)))
            val c44Red: SoP = SoP(Seq(vectorizeComparisonMultiplication("=", e4Red, vars4)))
            
            val bodyUS: SoP = multSoP(Seq(e1US, e2US, e3US, e4US, SoP(Seq(vectorizeComparisonMultiplication("<=", vars1, vars2))), SoP(Seq(vectorizeComparisonMultiplication("<=", vars2, vars3))), SoP(Seq(vectorizeComparisonMultiplication("<=", vars3, vars4)))))
            val bodyRM: SoP = concatSoP(Seq(
              multSoP(Seq(e1RM, e2RM, e3RM, e4RM)), 
              
              multSoP(Seq(e1US_allvars, e2RM, e3RM, e4RM)), 
              multSoP(Seq(e1RM, e2US_allvars, e3RM, e4RM)), 
              multSoP(Seq(e1RM, e2RM, e3US_allvars, e4RM)),
              multSoP(Seq(e1RM, e2RM, e3RM, e4US_allvars)), 
              
              multSoP(Seq(e1US_allvars, e2US_allvars, e3RM, e4RM)), 
              multSoP(Seq(e1US_allvars, e2RM, e3US_allvars, e4RM)), 
              multSoP(Seq(e1US_allvars, e2RM, e3RM, e4US_allvars)), 
              multSoP(Seq(e1RM, e2US_allvars, e3US_allvars, e4RM)), 
              multSoP(Seq(e1RM, e2US_allvars, e3RM, e4US_allvars)), 
              multSoP(Seq(e1RM, e2RM, e3US_allvars, e4US_allvars)), 

              multSoP(Seq(e1US_allvars, e2US_allvars, e3US_allvars, e4RM)), 
              multSoP(Seq(e1US_allvars, e2US_allvars, e3RM, e4US_allvars)), 
              multSoP(Seq(e1US_allvars, e2RM, e3US_allvars, e4US_allvars)),
              multSoP(Seq(e1RM, e2US_allvars, e3US_allvars, e4US_allvars)),
            
              multSoP(Seq(e1US, e2US, e3US, e4US, c12eq, c24eq, c43lt, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c12eq, c24lt, c43eq, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c12eq, c24lt, c43lt, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c12lt, c24eq, c43eq, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c12lt, c24eq, c43lt, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c12lt, c24lt, c43eq, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c12lt, c24lt, c43lt, c11Red, c22Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13eq, c32eq, c24lt, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13eq, c32lt, c24eq, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13eq, c32lt, c24lt, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c32eq, c24eq, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c32eq, c24lt, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c32lt, c24eq, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c32lt, c24lt, c11Red, c23Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13eq, c34eq, c42lt, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13eq, c34lt, c42eq, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13eq, c34lt, c42lt, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c34eq, c42eq, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c34eq, c42lt, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c34lt, c42eq, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c13lt, c34lt, c42lt, c11Red, c23Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14eq, c42eq, c23lt, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14eq, c42lt, c23eq, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14eq, c42lt, c23lt, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c42eq, c23eq, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c42eq, c23lt, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c42lt, c23eq, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c42lt, c23lt, c11Red, c24Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14eq, c43eq, c32lt, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14eq, c43lt, c32eq, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14eq, c43lt, c32lt, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c43eq, c32eq, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c43eq, c32lt, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c43lt, c32eq, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c14lt, c43lt, c32lt, c11Red, c24Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21eq, c13eq, c34lt, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21eq, c13lt, c34eq, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21eq, c13lt, c34lt, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c13eq, c34eq, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c13eq, c34lt, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c13lt, c34eq, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c13lt, c34lt, c12Red, c21Red, c33Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21eq, c14eq, c43lt, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21eq, c14lt, c43eq, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21eq, c14lt, c43lt, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c14eq, c43eq, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c14eq, c43lt, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c14lt, c43eq, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c21lt, c14lt, c43lt, c12Red, c21Red, c34Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23eq, c31eq, c14lt, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23eq, c31lt, c14eq, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23eq, c31lt, c14lt, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c31eq, c14eq, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c31eq, c14lt, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c31lt, c14eq, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c31lt, c14lt, c12Red, c23Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23eq, c34eq, c41lt, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23eq, c34lt, c41eq, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23eq, c34lt, c41lt, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c34eq, c41eq, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c34eq, c41lt, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c34lt, c41eq, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c23lt, c34lt, c41lt, c12Red, c23Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24eq, c41eq, c13lt, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24eq, c41lt, c13eq, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24eq, c41lt, c13lt, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c41eq, c13eq, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c41eq, c13lt, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c41lt, c13eq, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c41lt, c13lt, c12Red, c24Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24eq, c43eq, c31lt, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24eq, c43lt, c31eq, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24eq, c43lt, c31lt, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c43eq, c31eq, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c43eq, c31lt, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c43lt, c31eq, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c24lt, c43lt, c31lt, c12Red, c24Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31eq, c12eq, c24lt, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31eq, c12lt, c24eq, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31eq, c12lt, c24lt, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c12eq, c24eq, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c12eq, c24lt, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c12lt, c24eq, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c12lt, c24lt, c13Red, c21Red, c32Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31eq, c14eq, c42lt, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31eq, c14lt, c42eq, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31eq, c14lt, c42lt, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c14eq, c42eq, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c14eq, c42lt, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c14lt, c42eq, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c31lt, c14lt, c42lt, c13Red, c21Red, c34Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32eq, c21eq, c14lt, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32eq, c21lt, c14eq, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32eq, c21lt, c14lt, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c21eq, c14eq, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c21eq, c14lt, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c21lt, c14eq, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c21lt, c14lt, c13Red, c22Red, c31Red, c44Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32eq, c24eq, c41lt, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32eq, c24lt, c41eq, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32eq, c24lt, c41lt, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c24eq, c41eq, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c24eq, c41lt, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c24lt, c41eq, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c32lt, c24lt, c41lt, c13Red, c22Red, c34Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34eq, c41eq, c12lt, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34eq, c41lt, c12eq, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34eq, c41lt, c12lt, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c41eq, c12eq, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c41eq, c12lt, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c41lt, c12eq, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c41lt, c12lt, c13Red, c24Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34eq, c42eq, c21lt, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34eq, c42lt, c21eq, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34eq, c42lt, c21lt, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c42eq, c21eq, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c42eq, c21lt, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c42lt, c21eq, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c34lt, c42lt, c21lt, c13Red, c24Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41eq, c12eq, c23lt, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41eq, c12lt, c23eq, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41eq, c12lt, c23lt, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c12eq, c23eq, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c12eq, c23lt, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c12lt, c23eq, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c12lt, c23lt, c14Red, c21Red, c32Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41eq, c13eq, c32lt, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41eq, c13lt, c32eq, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41eq, c13lt, c32lt, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c13eq, c32eq, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c13eq, c32lt, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c13lt, c32eq, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c41lt, c13lt, c32lt, c14Red, c21Red, c33Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42eq, c21eq, c13lt, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42eq, c21lt, c13eq, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42eq, c21lt, c13lt, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c21eq, c13eq, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c21eq, c13lt, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c21lt, c13eq, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c21lt, c13lt, c14Red, c22Red, c31Red, c43Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42eq, c23eq, c31lt, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42eq, c23lt, c31eq, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42eq, c23lt, c31lt, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c23eq, c31eq, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c23eq, c31lt, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c23lt, c31eq, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c42lt, c23lt, c31lt, c14Red, c22Red, c33Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43eq, c31eq, c12lt, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43eq, c31lt, c12eq, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43eq, c31lt, c12lt, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c31eq, c12eq, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c31eq, c12lt, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c31lt, c12eq, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c31lt, c12lt, c14Red, c23Red, c31Red, c42Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43eq, c32eq, c21lt, c14Red, c23Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43eq, c32lt, c21eq, c14Red, c23Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43eq, c32lt, c21lt, c14Red, c23Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c32eq, c21eq, c14Red, c23Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c32eq, c21lt, c14Red, c23Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c32lt, c21eq, c14Red, c23Red, c32Red, c41Red)), 
              multSoP(Seq(e1US, e2US, e3US, e4US, c43lt, c32lt, c21lt, c14Red, c23Red, c32Red, c41Red))
            ))
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          }
        }
      }
    }
    (inp1US, inp1RM)
  }


  def infer(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule]): (Rule, Rule) = {
    val prods: Seq[Prod] = tensorComputation.body.prods
    val head: Access = tensorComputation.head
    if (prods.length == 1) {
      val exps: Seq[Exp] = prods(0).exps
      if (exps.length == 1) {
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
      } else if (exps.length == 3) {
        val e1: Exp = exps(0)
        val e2: Exp = exps(1)
        val e3: Exp = exps(2)
        val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
        val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
        val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
        val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
        val inp3US: Rule = uniqueSets.getOrElse(e3, emptyRule())
        val inp3RM: Rule = redundancyMaps.getOrElse(e3, emptyRule())
        return mult3(head, dimInfo, e1, e2, e3, inp1US, inp1RM, inp2US, inp2RM, inp3US, inp3RM)
      } else if (exps.length == 4) {
        val e1: Exp = exps(0)
        val e2: Exp = exps(1)
        val e3: Exp = exps(2)
        val e4: Exp = exps(3)
        val inp1US: Rule = uniqueSets.getOrElse(e1, emptyRule())
        val inp1RM: Rule = redundancyMaps.getOrElse(e1, emptyRule())
        val inp2US: Rule = uniqueSets.getOrElse(e2, emptyRule())
        val inp2RM: Rule = redundancyMaps.getOrElse(e2, emptyRule())
        val inp3US: Rule = uniqueSets.getOrElse(e3, emptyRule())
        val inp3RM: Rule = redundancyMaps.getOrElse(e3, emptyRule())
        val inp4US: Rule = uniqueSets.getOrElse(e4, emptyRule())
        val inp4RM: Rule = redundancyMaps.getOrElse(e4, emptyRule())
        return mult4(head, dimInfo, e1, e2, e3, e4, inp1US, inp1RM, inp2US, inp2RM, inp3US, inp3RM, inp4US, inp4RM)
      }
    } else if (prods.length == 2) {
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
      } else {

      }
    } else {

    }
    (emptyRule(), emptyRule())
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
    val vars = if (genType == RedundancyMap) variables.redundancyVarsInplace else variables
    val dimMap: Map[Access, Seq[Dim]] = dimInfo.toAccessMap
    val dimVarMap: Map[Variable, Seq[Dim]] = dimInfo.toVarsMap
    if (codeMotion) {
      // get a access -> variable map for all head and body accesses
    }
    intervals.foldLeft("")((acc, map) => {
      var cnt = 0
      val nestedLoops = vars.foldLeft("")((acc2, variable) => {
        val interval = map.get(variable).get // Interval(Seq(), Seq()) is output if there's no condition on the variable
        val (areEquals, index, (b, e)) = areBeginAndEndEqual(interval)
        val newInterval: Interval = if((b, e) == (-1, -1)) interval 
                          else Interval(interval.begin.zipWithIndex.filter(indexID => indexID._2 != b).map(indexID => indexID._1),
                                interval.end.zipWithIndex.filter(indexID => indexID._2 != e).map(indexID => indexID._1))
        val newInterval2: Interval = if (tensorComputation.body.prods.length > 1) {
          if (interval.begin.toSet == Set(ConstantInt(0).asInstanceOf[Index]) && interval.end.toSet == dimVarMap.get(variable).get.toSet) newInterval
          else Interval(newInterval.begin.toSet.diff(Set(ConstantInt(0).asInstanceOf[Index])).toSeq, newInterval.end.toSet.diff(dimVarMap.get(variable).get.toSet).toSeq)
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
              s"int ${variable.cFormat} = $begin;" 
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
        val cm = if (codeMotion) {
          // if current variable is equal to first element of each of the variables of accesses in the map, do code motion for it
          // update the map in a way that previous variables that include code motion be removed and new variable with .slice(1, length) of variables be in it
        } else ""
        s"$acc2\n$code\n$cm"
      })

      val tcBodya: SoP = getNoComparisonSoP(tensorComputation.body) 
      // why constants are not exp as well? Then I could replace the comparison below by ConstantInt(1) instead.
      val tcBody: SoP = if (tcBodya == emptySoP()) SoP(Seq(Prod(Seq(Comparison("=", ConstantInt(0), getVar("rndVar").toVar))))) else tcBodya // if it's only comparison, then it was just a bunch of comparison multiplications so their value is only 1. Their ranges is inside unique set and redundancy maps already.
      val body = if (genType == RedundancyMap) s"${tensorComputation.head.cFormat} = ${tensorComputation.head.cRedFormat};" else {
        if (tcBody.prods.length == 1) s"${tensorComputation.head.cFormat} += ${tcBody.cFormat};"
        else tcBody.prods.foldLeft("")((acc, prod) => {
          val conds = prod.exps.foldLeft("")((acc2, exp) => {
            exp match {
              case Access(name, vars, kind) => acc2 + (vars zip dimMap.get(exp.asInstanceOf[Access]).get).foldLeft("")((acc3, varDim) => {
                val (flag, cond) = if (map.get(varDim._1).get == Interval(Seq(ConstantInt(0)), Seq(varDim._2))) (true, "")
                else if (map.get(varDim._1).get != Interval(Seq(), Seq())) {
                  val interval = map.get(varDim._1).get
                  val isProdEmptyBegin = interval.begin.foldLeft(false)((acc, cur) => acc || isProdEmpty(Comparison("<=", cur, varDim._1), Comparison(">", varDim._2, varDim._1)))
                  val isProdEmptyEnd = interval.end.foldLeft(false)((acc, cur) => acc || isProdEmpty(Comparison(">", cur, varDim._1), Comparison("<=", ConstantInt(0), varDim._1)))
                  if (isProdEmptyBegin || isProdEmptyEnd) (false, "")
                  else (false, s"$acc3 && 0 <= ${varDim._1.cFormat} && ${varDim._1.cFormat} < ${varDim._2.cFormat}")
                }
                else (false, "")
                
                if (flag == true) "remif"
                else cond
              })
              case _ => s"$acc2"
            }
          })
          if (conds == "remif") s"$acc\n${tensorComputation.head.cFormat} += ${prod.cFormat};" 
          else if (conds.length < 5) s"$acc" 
          else s"$acc\nif (${conds.substring(4, conds.length)}) {\n${tensorComputation.head.cFormat} += ${prod.cFormat};\n}" 
        })
      } // change wrt code motion and use the newest variables with the corresponding list to them
      // val body = if (genType == RedundancyMap) s"${tensorComputation.head.cFormat} = ${tensorComputation.head.cRedFormat};" else tensorComputation.cPeqFormat

      val finalBrackets = vars.slice(cnt, vars.size).foldLeft("")((acc, _) => s"$acc}\n")
      
      s"$acc\n$nestedLoops\n$body\n$finalBrackets"
    })
  }

  def codeGen(tensorComputation: Rule, dimInfo: Seq[DimInfo], uniqueSets: Map[Exp, Rule], redundancyMaps: Map[Exp, Rule]): String = {
    val variables: Seq[Variable] = getVariables(tensorComputation)
    val (outUS, outRM) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMaps)
    
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
    // println("fixedConditionOrderUS")
    // println(fixedConditionOrderUS)
    // println("------------------")
    // println("fixedConditionOrderRM")
    // println(fixedConditionOrderRM)
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

    "void compute() {\n" + codeGenRule(tensorComputation, dimInfo, variables, intervalsUS, UniqueSet) + "\n}\n\n\nvoid reconstruct() {\n" + codeGenRule(tensorComputation, dimInfo, variables, intervalsRM, RedundancyMap) + "\n}\n"
  }

  // Binary multiplication for 2 tensors check -- worked
  def test1(): (Rule, (Rule, Rule)) = {
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
  def test2(): (Rule, (Rule, Rule)) = {
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
  def test3(): (Rule, (Rule, Rule)) = {
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
  def test4(): (Rule, (Rule, Rule)) = {
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
  def test5(): (Rule, (Rule, Rule)) = {
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
  def test6(): (Rule, (Rule, Rule)) = {
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
  def test7(): (Rule, (Rule, Rule)) = {
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
  def test8(): (Rule, (Rule, Rule)) = {
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

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))

    pprintTest((tensorComputation1, infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)))
    pprintTest((tensorComputation2, infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)))

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)

    println(codeGen(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap))

    (tensorComputation3, infer(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap))
  }

  // Non-binary: Example - Normal Kronecker Product
  def test9(): (Rule, (Rule, Rule)) = {
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

    // val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
    // val var3BodyUS: SoP = emptySoP()
    // val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    // val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var3BodyRM: SoP = emptySoP()
    // val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    // val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
    // val var4BodyUS: SoP = emptySoP()
    // val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    // val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var4BodyRM: SoP = emptySoP()
    // val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    // val var5HeadUS: Access = Access(in5Name.uniqueName,  in5SeqVar, UniqueSet)
    // val var5BodyUS: SoP = emptySoP()
    // val var5US: Rule = Rule(var5HeadUS, var5BodyUS)

    // val var5HeadRM: Access = Access(in5Name.redundancyName,  in5SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var5BodyRM: SoP = emptySoP()
    // val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

    // val var6HeadUS: Access = Access(in6Name.uniqueName,  in6SeqVar, UniqueSet)
    // val var6BodyUS: SoP = emptySoP()
    // val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

    // val var6HeadRM: Access = Access(in6Name.redundancyName,  in6SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var6BodyRM: SoP = emptySoP()
    // val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

    // println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    // println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))

    // pprintTest((tensorComputation1, infer1))
    // pprintTest((tensorComputation2, infer2))

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)

    val infer3: (Rule, Rule) = infer(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap)
    val infer4: (Rule, Rule) = infer(tensorComputation4, dimInfo, newUniqueSets, newRedundancyMap)

    // println(codeGen(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap))
    // println(codeGen(tensorComputation4, dimInfo, newUniqueSets, newRedundancyMap))

    // pprintTest((tensorComputation3, infer3))
    // pprintTest((tensorComputation4, infer4))

    val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
    val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)

    val infer5: (Rule, Rule) = infer(tensorComputation5, dimInfo, newUniqueSets2, newRedundancyMap2)
    val infer6: (Rule, Rule) = infer(tensorComputation6, dimInfo, newUniqueSets2, newRedundancyMap2)

    // println(codeGen(tensorComputation5, dimInfo, newUniqueSets2, newRedundancyMap2))
    // println(codeGen(tensorComputation6, dimInfo, newUniqueSets2, newRedundancyMap2))

    // pprintTest((tensorComputation5, infer5))
    // pprintTest((tensorComputation6, infer6))

    val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
    val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)

    val infer7: (Rule, Rule) = infer(tensorComputation7, dimInfo, newUniqueSets3, newRedundancyMap3)
    val infer8: (Rule, Rule) = infer(tensorComputation8, dimInfo, newUniqueSets3, newRedundancyMap3)

    // println(codeGen(tensorComputation7, dimInfo, newUniqueSets3, newRedundancyMap3))
    // println(codeGen(tensorComputation8, dimInfo, newUniqueSets3, newRedundancyMap3))

    // pprintTest((tensorComputation7, infer7))
    // pprintTest((tensorComputation8, infer8))

    val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
    val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)

    val infer9: (Rule, Rule) = infer(tensorComputation9, dimInfo, newUniqueSets4, newRedundancyMap4)
    val infer10: (Rule, Rule) = infer(tensorComputation10, dimInfo, newUniqueSets4, newRedundancyMap4)

    // println(codeGen(tensorComputation9, dimInfo, newUniqueSets4, newRedundancyMap4))
    // println(codeGen(tensorComputation10, dimInfo, newUniqueSets4, newRedundancyMap4))

    // pprintTest((tensorComputation9, infer9))
    // pprintTest((tensorComputation10, infer10))

    val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
    val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)

    val infer11: (Rule, Rule) = infer(tensorComputation11, dimInfo, newUniqueSets5, newRedundancyMap5)
    val infer12: (Rule, Rule) = infer(tensorComputation12, dimInfo, newUniqueSets5, newRedundancyMap5)

    // println(codeGen(tensorComputation11, dimInfo, newUniqueSets5, newRedundancyMap5))
    // println(codeGen(tensorComputation12, dimInfo, newUniqueSets5, newRedundancyMap5))

    // pprintTest((tensorComputation11, infer11))
    // pprintTest((tensorComputation12, infer12))

    val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
    val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation4, dimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation5, dimInfo, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation6, dimInfo, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation7, dimInfo, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation8, dimInfo, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation9, dimInfo, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation10, dimInfo, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation11, dimInfo, newUniqueSets5, newRedundancyMap5))
    println(codeGen(tensorComputation12, dimInfo, newUniqueSets5, newRedundancyMap5))

    println(codeGen(tensorComputation, dimInfo, newUniqueSets6, newRedundancyMap6))

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

    (tensorComputation, infer(tensorComputation, dimInfo, newUniqueSets6, newRedundancyMap6))
  }

  // Non-binary: Polynomial Regression Degree 2 -- It's a confusing mess, will check it after all simplifications
  def test10(): (Rule, (Rule, Rule)) = {
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

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

    pprintTest((tensorComputation1, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)))
    
    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
    
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, newUniqueSets, newRedundancyMap)

    println(codeGen(tensorComputation2, dimInfo, newUniqueSets, newRedundancyMap))

    pprintTest((tensorComputation2, infer(tensorComputation, dimInfo, newUniqueSets, newRedundancyMap)))

    val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._1), newUniqueSets))((v1, v2) => v2)
    val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._2), newRedundancyMap))((v1, v2) => v2)

    val infer3: (Rule, Rule) = infer(tensorComputation3, dimInfo, newUniqueSets2, newRedundancyMap2)
    val infer4: (Rule, Rule) = infer(tensorComputation4, dimInfo, newUniqueSets2, newRedundancyMap2)

    println(codeGen(tensorComputation3, dimInfo, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation4, dimInfo, newUniqueSets2, newRedundancyMap2))

    pprintTest((tensorComputation3, infer(tensorComputation, dimInfo, newUniqueSets2, newRedundancyMap2)))
    pprintTest((tensorComputation4, infer(tensorComputation, dimInfo, newUniqueSets2, newRedundancyMap2)))

    val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets2))((v1, v2) => v2)
    val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap2))((v1, v2) => v2)

    println(codeGen(tensorComputation, dimInfo, newUniqueSets3, newRedundancyMap3))

    (tensorComputation, infer(tensorComputation, dimInfo, newUniqueSets3, newRedundancyMap3))
  }

  // Self-outer product 3 check: worked -- need to be checked inside covariance matrices to make sure -- manually checked
  def test11(): (Rule, (Rule, Rule)) = {
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
  def test12(): (Rule, (Rule, Rule)) = {
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
  def test13(): (Rule, (Rule, Rule)) = {
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

    // val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
    // val var3BodyUS: SoP = emptySoP()
    // val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    // val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var3BodyRM: SoP = emptySoP()
    // val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    // val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
    // val var4BodyUS: SoP = emptySoP()
    // val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    // val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var4BodyRM: SoP = emptySoP()
    // val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    // val var5HeadUS: Access = Access(in5Name.uniqueName,  in5SeqVar, UniqueSet)
    // val var5BodyUS: SoP = emptySoP()
    // val var5US: Rule = Rule(var5HeadUS, var5BodyUS)

    // val var5HeadRM: Access = Access(in5Name.redundancyName,  in5SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var5BodyRM: SoP = emptySoP()
    // val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

    // val var6HeadUS: Access = Access(in6Name.uniqueName,  in6SeqVar, UniqueSet)
    // val var6BodyUS: SoP = emptySoP()
    // val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

    // val var6HeadRM: Access = Access(in6Name.redundancyName,  in6SeqVar.redundancyVarsInplace, RedundancyMap)
    // val var6BodyRM: SoP = emptySoP()
    // val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

    // println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    // println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))

    // pprintTest((tensorComputation1, infer1))
    // pprintTest((tensorComputation2, infer2))

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)

    val infer3: (Rule, Rule) = infer(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap)
    val infer4: (Rule, Rule) = infer(tensorComputation4, dimInfo, newUniqueSets, newRedundancyMap)

    // println(codeGen(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap))
    // println(codeGen(tensorComputation4, dimInfo, newUniqueSets, newRedundancyMap))

    // pprintTest((tensorComputation3, infer3))
    // pprintTest((tensorComputation4, infer4))

    val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
    val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)

    val infer5: (Rule, Rule) = infer(tensorComputation5, dimInfo, newUniqueSets2, newRedundancyMap2)
    val infer6: (Rule, Rule) = infer(tensorComputation6, dimInfo, newUniqueSets2, newRedundancyMap2)

    // println(codeGen(tensorComputation5, dimInfo, newUniqueSets2, newRedundancyMap2))
    // println(codeGen(tensorComputation6, dimInfo, newUniqueSets2, newRedundancyMap2))

    // pprintTest((tensorComputation5, infer5))
    // pprintTest((tensorComputation6, infer6))

    val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
    val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)

    val infer7: (Rule, Rule) = infer(tensorComputation7, dimInfo, newUniqueSets3, newRedundancyMap3)
    val infer8: (Rule, Rule) = infer(tensorComputation8, dimInfo, newUniqueSets3, newRedundancyMap3)

    // println(codeGen(tensorComputation7, dimInfo, newUniqueSets3, newRedundancyMap3))
    // println(codeGen(tensorComputation8, dimInfo, newUniqueSets3, newRedundancyMap3))

    // pprintTest((tensorComputation7, infer7))
    // pprintTest((tensorComputation8, infer8))

    val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
    val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)

    val infer9: (Rule, Rule) = infer(tensorComputation9, dimInfo, newUniqueSets4, newRedundancyMap4)
    val infer10: (Rule, Rule) = infer(tensorComputation10, dimInfo, newUniqueSets4, newRedundancyMap4)

    // println(codeGen(tensorComputation9, dimInfo, newUniqueSets4, newRedundancyMap4))
    // println(codeGen(tensorComputation10, dimInfo, newUniqueSets4, newRedundancyMap4))

    // pprintTest((tensorComputation9, infer9))
    // pprintTest((tensorComputation10, infer10))

    val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
    val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)

    val infer11: (Rule, Rule) = infer(tensorComputation11, dimInfo, newUniqueSets5, newRedundancyMap5)
    val infer12: (Rule, Rule) = infer(tensorComputation12, dimInfo, newUniqueSets5, newRedundancyMap5)

    // println(codeGen(tensorComputation11, dimInfo, newUniqueSets5, newRedundancyMap5))
    // println(codeGen(tensorComputation12, dimInfo, newUniqueSets5, newRedundancyMap5))

    // pprintTest((tensorComputation11, infer11))
    // pprintTest((tensorComputation12, infer12))

    val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
    val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
    println(codeGen(tensorComputation3, dimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation4, dimInfo, newUniqueSets, newRedundancyMap))
    println(codeGen(tensorComputation5, dimInfo, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation6, dimInfo, newUniqueSets2, newRedundancyMap2))
    println(codeGen(tensorComputation7, dimInfo, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation8, dimInfo, newUniqueSets3, newRedundancyMap3))
    println(codeGen(tensorComputation9, dimInfo, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation10, dimInfo, newUniqueSets4, newRedundancyMap4))
    println(codeGen(tensorComputation11, dimInfo, newUniqueSets5, newRedundancyMap5))
    println(codeGen(tensorComputation12, dimInfo, newUniqueSets5, newRedundancyMap5))

    println(codeGen(tensorComputation, dimInfo, newUniqueSets6, newRedundancyMap6))

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

    (tensorComputation, infer(tensorComputation, dimInfo, newUniqueSets6, newRedundancyMap6))
  }

  // Vector direct - checked
  def test14(): (Rule, (Rule, Rule)) = {
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

  def ttm(structure: String): (Rule, (Rule, Rule)) = {
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

  def thp(structure: String): (Rule, (Rule, Rule)) = {
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

  def mttkrp(structure: String): (Rule, (Rule, Rule)) = {
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

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

    println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

    pprintTest((tensorComputation1, infer1))

    val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
    val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)

    println(codeGen(tensorComputation, dimInfo, newUniqueSets, newRedundancyMap))

    (tensorComputation, infer(tensorComputation, dimInfo, newUniqueSets, newRedundancyMap))
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
  // pprintTest(test9())
  // pprintTest(test10())
  // pprintTest(test11())
  // pprintTest(test12())
  pprintTest(test13())
  // pprintTest(test14())

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

  // println(Variable("a").equals(Variable("a")))

  // val a: Map[String, Seq[Int]] = Map("a" -> Seq(2))
  // println(a.getOrElse("b", 12))
  // val b: Map[String, Seq[Int]] = Map("a" -> Seq(3))
  // println(mergeMap(Seq(a, b))((v1, v2) => v1 ++ v2))

}