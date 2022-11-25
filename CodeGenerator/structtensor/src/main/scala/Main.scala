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
    acc + (cur._1 -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1)))))
    def toComparisonAccessProdMap: Map[Access, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Access, Prod])((acc, cur) => 
    acc + (d.access -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1)))))
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
        val e1US: SoP = concatSoP(Seq(inp1US.body, SoP(Seq(bounds.get(e1.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
        val e2US: SoP = concatSoP(Seq(inp2US.body, SoP(Seq(bounds.get(e2.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
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
        val e1US: SoP = concatSoP(Seq(inp1US.body, SoP(Seq(bounds.get(e1.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
        val e2US: SoP = concatSoP(Seq(inp2US.body, SoP(Seq(bounds.get(e2.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
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
        val eUS: SoP = concatSoP(Seq(inp1US.body, SoP(Seq(bounds.get(e.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
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
        val e1US: SoP = concatSoP(Seq(inp1US.body, SoP(Seq(bounds.get(e1.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
        val e2US: SoP = concatSoP(Seq(inp2US.body, SoP(Seq(bounds.get(e2.asInstanceOf[Access]).get)))) // if .get result is None leads to an error
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

  // Self-outer product check
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

  

  // pprintTest(test1())
  // pprintTest(test2())
  pprintTest(test3())
  // println(Variable("a").equals(Variable("a")))

  // val a: Map[String, Seq[Int]] = Map("a" -> Seq(2))
  // val b: Map[String, Seq[Int]] = Map("a" -> Seq(3))
  // println(mergeMap(Seq(a, b))((v1, v2) => v1 ++ v2))

}