sealed trait Exp {
  def prettyFormat(): String
}

sealed trait Index {
  def prettyFormat(): String
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


case class Variable(name: String) extends Index with Dim {
  def prettyFormat(): String = name
}

case class ConstantDouble(value: Double) extends Index {
  def prettyFormat(): String = value.toString
}

case class ConstantInt(value: Int) extends Index with Dim {
  def prettyFormat(): String = value.toString
}

case class Arithmetic(op: String, index1: Index, index2: Index) extends Index {
  def prettyFormat(): String = s"(${index1.prettyFormat} $op ${index2.prettyFormat})"
}

case class Access(name: String, vars: Seq[Variable], kind: AccessType) extends Exp {
  def prettyFormat(): String = {
    val pr = vars.foldLeft("")((acc, cur) => s"$acc, ${cur.prettyFormat}")
    s"${name}(${pr.substring(2, pr.length)})"
  }
}

case class Comparison(op: String, index: Index, variable: Variable) extends Exp {
  def prettyFormat(): String = s"(${index.prettyFormat} $op ${variable.prettyFormat})"
}

case class Prod(exps: Seq[Exp]) {
  def prettyFormat(): String = {
    val pr = exps.foldLeft("")((acc, cur) => s"$acc * ${cur.prettyFormat}")
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
}

case class Rule(head: Access, body: SoP) {
  def prettyFormat(): String = s"${head.prettyFormat} := ${body.prettyFormat}"
}

case class DimInfo(access: Access, dims: Seq[Dim]) // how to assert that dims.size == access.vars.size?

object Main extends App {

  def emptyProd(): Prod = Prod(Seq[Exp]())

  def emptySoP(): SoP = SoP(Seq[Prod]())

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

  def includeBoundaries(us: SoP, bounds: Map[Access, Prod], e: Access): SoP = {
    if (!bounds.contains(e)) us
    else if (us == emptySoP()) SoP(Seq(bounds.get(e).get))
    else SoPTimesSoP(us, SoP(Seq(bounds.get(e).get)))
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
    def toMap: Map[Access, Seq[Dim]] = Map[Access, Seq[Dim]](d.access -> d.dims)
    def toVarsMap: Map[Variable, Seq[Dim]] = (d.access.vars zip d.dims).foldLeft(Map.empty[Variable, Seq[Dim]])((acc, cur) => acc + (cur._1 -> Seq(cur._2)))
    def toComparisonVariableProdMap: Map[Variable, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Variable, Prod])((acc, cur) => 
    mergeMap(Seq(acc, Map(cur._1 -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonAccessProdMap: Map[Access, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Access, Prod])((acc, cur) => 
    mergeMap(Seq(acc, Map(d.access -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonProd: Prod = Prod((d.access.vars zip d.dims).foldLeft(Seq[Exp]())((acc, cur) => 
    acc ++ Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))
  }

  implicit class SeqDimInfoOps(d: Seq[DimInfo]) {
    def toMap: Map[Access, Seq[Dim]] = d.foldLeft(Map.empty[Access, Seq[Dim]])((acc, cur) => mergeMap(Seq(acc, cur.toMap))((v1, v2) => v1 ++ v2))
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
          val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access]) // if .get result is None leads to an error
          val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access]) // if .get result is None leads to an error
          if (isIntersectEmpty(vars1, vars2)) {
            if (name1 == name2) {
              val bodyUS: SoP = multSoP(Seq(e1US, e2US, SoP(Seq(vectorizeComparisonMultiplication("<=", vars1, vars2)))))
              val bodyRM: SoP = concatSoP(Seq(SoPTimesSoP(inp1RM.body, inp2RM.body), 
              multSoP(Seq(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1)))), inp2RM.body)), 
              multSoP(Seq(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2)))), inp1RM.body)), 
              multSoP(Seq(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1)))), e2US, 
                          SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2)))), 
                          SoP(Seq(vectorizeComparisonMultiplication(">", vars1, vars2)))))))
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
            } else {
              val bodyUS: SoP = SoPTimesSoP(e1US, e2US)
              val bodyRM: SoP = concatSoP(Seq(SoPTimesSoP(inp1RM.body, inp2RM.body), 
              SoPTimesSoP(SoPTimesSoP(e1US, SoP(Seq(vectorizeComparisonMultiplication("=", vars1, inp1RM.head.vars.diff(vars1))))), inp2RM.body), 
              SoPTimesSoP(SoPTimesSoP(e2US, SoP(Seq(vectorizeComparisonMultiplication("=", vars2, inp2RM.head.vars.diff(vars2))))), inp1RM.body)))
              return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
            }
          } else {
            val bodyUS: SoP = concatSoP(Seq(SoPTimesSoP(e1US, e2US), SoPTimesSoP(inp1RM.body, e2US), SoPTimesSoP(inp1US.body, inp2RM.body)))
            val bodyRM: SoP = SoPTimesSoP(inp1RM.body, inp2RM.body)
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          }
        } else {
          val headP: Access = Access(head.name.redundancyVars.name, vars1.union(vars2), head.kind)
          val us_rm: (Rule, Rule) = binMult(headP, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
          return project(head, dimInfo, headP, us_rm._1, us_rm._2)
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binMult(head, dimInfo, e2, e1, inp2US, inp2RM, inp1US, inp1RM)
      case (Comparison(op1, index1, variable1), Comparison(op2, index2, variable2)) => {
        if (op1 == "<=" && op2 == "<" && variable1 == index2) { // I should put different conditions that are equivalent
          val bodyUS: SoP = SoP(Seq(Prod(Seq(Comparison("=", index1, variable1)))))
          val bodyRM: SoP = SoP(Seq(Prod(Seq(Comparison("<", index1, variable1), e2, Comparison("=", index1, variable1.redundancyVars))))) // inp1RM.head.vars.diff(Seq(variable1))??
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
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access]) // if .get result is None leads to an error
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access]) // if .get result is None leads to an error
        if (vars1 == vars2) {
          if (isSoPEquals(e1US, e2US) && isSoPEquals(inp1RM.body, inp2RM.body)) {
            val bodyUS: SoP = e1US
            val bodyRM: SoP = inp1RM.body
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          } else {
            val bodyUS: SoP = concatSoP(Seq(e1US, e2US, inp1RM.body, inp2RM.body))
            val bodyRM: SoP = SoP(Seq())
            return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
          }
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
        val eUS: SoP = includeBoundaries(inp1US.body, bounds, e.asInstanceOf[Access]) // if .get result is None leads to an error
        if(outVars.toSet.subsetOf(varsE.toSet)) {
          val bodyUS: SoP = concatSoP(Seq(eUS, inp1RM.body))
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
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => { 
        val e1US: SoP = includeBoundaries(inp1US.body, bounds, e1.asInstanceOf[Access]) // if .get result is None leads to an error
        val e2US: SoP = includeBoundaries(inp2US.body, bounds, e2.asInstanceOf[Access]) // if .get result is None leads to an error
        val bodyUS: SoP = concatSoP(Seq(e1US, SoPTimesSoP(e2US, SoP(Seq(Prod(e2Seq))))))
        val bodyRM: SoP = concatSoP(Seq(inp1RM.body, multSoP(Seq(inp2RM.body, SoP(Seq(Prod(e2Seq))), SoP(Seq(Prod(replaceVarsWithRedundancyVars(e2Seq))))))))
        return (Rule(headUS, bodyUS), Rule(headRM, bodyRM))
      }
    }
    (inp1US, inp1RM)
  }

  def infer(tensorComputation: Rule, dimInfo: Seq[DimInfo], inp1US: Rule, inp1RM: Rule, inp2US: Rule, inp2RM: Rule): (Rule, Rule) = {
    val prods: Seq[Prod] = tensorComputation.body.prods
    val head: Access = tensorComputation.head
    if (prods.length == 1) {
      val exps: Seq[Exp] = prods(0).exps
      if (exps.length == 1) {
        val e: Exp = exps(0)
        return project(head, dimInfo, e, inp1US, inp1RM)
      } else if (exps.length == 2) {
        val e1: Exp = exps(0)
        val e2: Exp = exps(1)
        return binMult(head, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
      } else {

      }
    } else if (prods.length == 2) {
      val exps1: Seq[Exp] = prods(0).exps
      val exps2: Seq[Exp] = prods(1).exps
      if (exps1.length == 1 && exps2.length == 1) {
        val e1 = exps1(0)
        val e2 = exps2(0)
        return binAdd(head, dimInfo, e1, e2, inp1US, inp1RM, inp2US, inp2RM)
      } else if (exps1.length == 1 && exps2.length >= 2 && isDirectSum(exps2.slice(1, exps2.length), dimInfo, exps1(0), exps2(0))) {
        val e1 = exps1(0)
        val e2 = exps2(0)
        val e2Seq = exps2.slice(1, exps2.length).asInstanceOf[Seq[Comparison]]
        return binDirectSum(head, dimInfo, e1, e2, e2Seq, inp1US, inp1RM, inp2US, inp2RM)
      } else {

      }
    } else {

    }
    (inp1US, inp2US)
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

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
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

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
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
    val var1BodyUS: SoP = emptySoP()
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
    val var2BodyUS: SoP = emptySoP()
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
  }

  // DTTV -- checked: w/o simplifications
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
    val var2BodyUS: SoP = emptySoP()
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
  }

  // RMD -- checked w/o simplification and inlining: page 12: M_U should be 0 <= k < n (not j instead of k!!!) also in simplifications should be fixed too!
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

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
  }

  // UHS -- checked: w/o simplifications
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

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
  }

  // Example - Structure Inference -- checked
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

    (tensorComputation, infer(tensorComputation, dimInfo, var1US, var1RM, var2US, var2RM))
  }

  // Non-binary: Example - Unique set computation
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

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, var1US, var1RM, var2US, var2RM)
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, var3US, var3RM, var4US, var4RM)

    (tensorComputation3, infer(tensorComputation3, dimInfo, infer1._1, infer1._2, infer2._1, infer2._2))
  }

  // Non-binary: Example - Diagonal Kronecker Product -- this one is wrong, should comparison directly go and be a part of unique set instead?
  def test9(): (Rule, (Rule, Rule)) = {
    val outSeqVar = Seq("i".toVar, "j".toVar)
    val in1SeqVar = Seq("p".toVar, "q".toVar)
    val in2SeqVar = Seq("r".toVar, "s".toVar)
    val in3SeqVar = Seq("i".toVar, "p".toVar)
    val in4SeqVar = Seq("j".toVar, "q".toVar)
    val in5SeqVar = Seq("i".toVar, "r".toVar)
    val in6SeqVar = Seq("j".toVar, "s".toVar)
    val outName = "M"
    val inter1Name = "C"
    val inter2Name = "D"
    val inter3Name = "E"
    val inter4Name = "F"
    val inter5Name = "G"
    val inter6Name = "H"
    val in1Name = "A"
    val in2Name = "B"
    val in3Name = "C1"
    val in4Name = "C2"
    val in5Name = "C3"
    val in6Name = "C4"

    val head1: Access = Access(inter1Name, in1SeqVar ++ outSeqVar, Tensor)
    val head2: Access = Access(inter2Name, in2SeqVar ++ outSeqVar, Tensor)
    val head3: Access = Access(inter3Name, in1SeqVar, Tensor)
    val head4: Access = Access(inter4Name, in2SeqVar, Tensor)
    val head: Access = Access(outName, outSeqVar, Tensor)
    val var1: Access = Access(in1Name, in1SeqVar, Tensor)
    val var2: Access = Access(in2Name, in2SeqVar, Tensor)
    val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
    val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
    val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
    val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
    
    val prods1: Prod = Prod(Seq(var3, var4))
    val prods2: Prod = Prod(Seq(var5, var6))
    val prods3: Prod = Prod(Seq(var1, head1))
    val prods4: Prod = Prod(Seq(var2, head2))
    val prods: Prod = Prod(Seq(head3, head4))
    val body1: SoP = SoP(Seq(prods1))
    val body2: SoP = SoP(Seq(prods2))
    val body3: SoP = SoP(Seq(prods3))
    val body4: SoP = SoP(Seq(prods4))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation1: Rule = Rule(head1, body1)
    val tensorComputation2: Rule = Rule(head2, body2)
    val tensorComputation3: Rule = Rule(head3, body3)
    val tensorComputation4: Rule = Rule(head4, body4)
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

    val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
    val var3BodyUS: SoP = emptySoP()
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
    val var4BodyUS: SoP = emptySoP()
    val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
    val var4BodyRM: SoP = emptySoP()
    val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    val var5HeadUS: Access = Access(in5Name.uniqueName,  in5SeqVar, UniqueSet)
    val var5BodyUS: SoP = emptySoP()
    val var5US: Rule = Rule(var5HeadUS, var5BodyUS)

    val var5HeadRM: Access = Access(in5Name.redundancyName,  in5SeqVar.redundancyVarsInplace, RedundancyMap)
    val var5BodyRM: SoP = emptySoP()
    val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

    val var6HeadUS: Access = Access(in6Name.uniqueName,  in6SeqVar, UniqueSet)
    val var6BodyUS: SoP = emptySoP()
    val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

    val var6HeadRM: Access = Access(in6Name.redundancyName,  in6SeqVar.redundancyVarsInplace, RedundancyMap)
    val var6BodyRM: SoP = emptySoP()
    val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, var3US, var3RM, var4US, var4RM)
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, var5US, var5RM, var6US, var6RM)
    val infer3: (Rule, Rule) = infer(tensorComputation3, dimInfo, var1US, var1RM, infer1._1, infer1._2)
    val infer4: (Rule, Rule) = infer(tensorComputation4, dimInfo, var2US, var2RM, infer2._1, infer2._2)

    pprintTest((tensorComputation1, infer1))
    pprintTest((tensorComputation2, infer2))
    pprintTest((tensorComputation3, infer3))
    pprintTest((tensorComputation4, infer4))

    (tensorComputation, infer(tensorComputation, dimInfo, infer3._1, infer3._2, infer4._1, infer4._2))
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

    val infer1: (Rule, Rule) = infer(tensorComputation1, dimInfo, var1US, var1RM, var1US, var1RM)
    val infer2: (Rule, Rule) = infer(tensorComputation2, dimInfo, infer1._1, infer1._2, var1US, var1RM)
    val infer3: (Rule, Rule) = infer(tensorComputation1, dimInfo, var1US, var1RM, infer2._1, infer2._2)
    val infer4: (Rule, Rule) = infer(tensorComputation1, dimInfo, var1US, var1RM, infer2._1, infer2._2)

    (tensorComputation, infer(tensorComputation, dimInfo, infer3._1, infer3._2, infer4._1, infer4._2))
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
  pprintTest(test10())
  // println(Variable("a").equals(Variable("a")))

  // val a: Map[String, Seq[Int]] = Map("a" -> Seq(2))
  // val b: Map[String, Seq[Int]] = Map("a" -> Seq(3))
  // println(mergeMap(Seq(a, b))((v1, v2) => v1 ++ v2))

}