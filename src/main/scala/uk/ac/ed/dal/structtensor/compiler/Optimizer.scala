package uk.ac.ed.dal
package structtensor
package compiler

object Optimizer {
  import STURHelper._

  var cnt = 0
  def getVar(name: String): String = {
    cnt += 1
    return s"$name$cnt"
  }

  def concatSoP(sops: Seq[SoP]): SoP = SoP(sops.flatMap(sop => sop.prods))

  def prodTimesProd(prod1: Prod, prod2: Prod): Prod = {
    if (prod1.exps.size == 0 || prod2.exps.size == 0) emptyProd()
    else Prod(prod1.exps ++ prod2.exps)
  } 

  def prodTimesSoP(prod: Prod, sop: SoP): SoP = {
    if (prod.exps.size == 0 || sop.prods.size == 0) emptySoP()
    else SoP(sop.prods.map(cur => prodTimesProd(prod, cur)))
  }

  def SoPTimesSoP(sop1: SoP, sop2: SoP): SoP = {
    if (sop1.prods.size == 0 || sop2.prods.size == 0) emptySoP()
    else SoP(sop1.prods.flatMap(cur => prodTimesSoP(cur, sop2).prods))
  }

  def multSoP(sops: Seq[SoP]): SoP = {
    if (sops.size == 0) emptySoP()
    else sops.slice(1, sops.length).foldLeft(sops(0))((acc, cur) => SoPTimesSoP(acc, cur))
  } 

  def denormalizeSingle(body: SoP, denormMap: Map[Access, SoP]): SoP = {
    def extractAccessesInDenormalizationMapByName(exp: Exp): Boolean = exp match {
      case acc: Access => containsByName(denormMap, acc)
      case _ => false
    }

    body.prods.foldLeft(emptySoP())((acc1, prod) => {
      val (epxsInMap, epxsNotInMap): (Seq[Exp], Seq[Exp]) = prod.exps.partition(extractAccessesInDenormalizationMapByName)
      val denormalizedSoPSeq = epxsInMap.map(exp => exp match {
        case acc: Access => getByNameAndAlphaRename(denormMap, acc).get
        case _ => throw new Exception("Unknown expression")
      })
      val singleAllExpSoP = SoP(Seq(Prod(epxsNotInMap)))
      val allExpSoP = if (epxsNotInMap.length == 0) multSoP(denormalizedSoPSeq) else if (epxsInMap.length == 0) singleAllExpSoP else multSoP(singleAllExpSoP +: denormalizedSoPSeq) 
      concatSoP(Seq(acc1, allExpSoP))
    })
  }

  def denormalize(head: Access, ctx: Seq[(Rule, Rule, Rule, Rule)]): (Rule, Rule, Rule, Rule) = {
    val denormMap = ctx.foldLeft(Map[Access, SoP]())((acc, cur) => {
      val (us, rm, cc, tc) = cur
      val (usBody, rmBody, ccBody, tcBody) = (denormalizeSingle(us.body, acc), denormalizeSingle(rm.body, acc), denormalizeSingle(cc.body, acc), denormalizeSingle(tc.body, acc))
      acc + (us.head -> usBody) + (rm.head -> rmBody) + (cc.head -> ccBody) + (tc.head -> tcBody)
    })
    
    // denormMap.foreach{case (k, v) => println(s"**************************\nDenormalized:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // val compressedComputation = Rule(head, denormMap(head.compressedHead))
    // val reconstructionComputation = Rule(head, SoPTimesSoP(SoP(Seq(Prod(Seq(head.vars2RedundancyVars)))), denormMap(head.redundancyHead)))

    val denormUS = Rule(head, denormMap(head.uniqueHead))
    val denormRM = Rule(head, denormMap(head.redundancyHead))
    val denormCC = Rule(head, denormMap(head.compressedHead))
    val denormTC = Rule(head, denormMap(head))

    // (compressedComputation, reconstructionComputation)
    (denormUS, denormRM, denormCC, denormTC)
  }

  def denormalizeDim(head: Access, ctx: Seq[Rule]): Rule = {
    val denormMap = ctx.foldLeft(Map[Access, SoP]())((acc, dc) => {
      val dcBody = denormalizeSingle(dc.body, acc)
      acc + (dc.head -> dcBody)
    })
    Rule(head, denormMap(head))
  }

  def singleProdIdempotence(p: Prod): Prod = {
    def extractBooleanDomainComputation(exp: Exp): Boolean = {
      exp match {
        case Access(_, _, kind) if (kind == UniqueSet || kind == RedundancyMap) => true
        case Comparison(_, _, _) => true
        case _ => false
      }
    }
    
    val (boolDomainExps, realDomainExps) = p.exps.partition(extractBooleanDomainComputation)
    val distinctBoolDomainExps = boolDomainExps.distinct

    // println("^^^^^^^^^^^^^^^^^^")
    // println("boolDomainExps: " + boolDomainExps)
    // println("distinctBoolDomainExps: " + distinctBoolDomainExps)
    // println("realDomainExps: " + realDomainExps)
    
    Prod(distinctBoolDomainExps ++ realDomainExps)
  }

  def setIdempotentIntersectionOpt(r: Rule): Rule = Rule(r.head, SoP(r.body.prods.map(singleProdIdempotence)))

  def setIdempotentOpt(r: Rule): Rule = {
    val areAllComparison = r.body.prods.forall(p => p.exps.forall(e => e match {
      case _: Comparison => true
      case _ => false
    }))

    areAllComparison match {
      case true => {
        val prodSetOfExpSet = r.body.prods.map(p => p.exps.toSet).toSet
        Rule(r.head, SoP(prodSetOfExpSet.map(p => Prod(p.toSeq)).toSeq))
      }
      case false => setIdempotentIntersectionOpt(r)
    }
  }

  def opEmpty(op: String): Seq[String] = op match {
    case "<" => Seq(">", ">=", "=")
    case "<=" => Seq(">")
    case ">=" => Seq("<")
    case ">" => Seq("<", "<=", "=")
    case "=" => Seq("<", ">")
    case _ => Seq()
  }

  def opComplement(op: String): String = op match {
    case "=" => "="
    case "<" => ">"
    case "<=" => ">="
    case ">" => "<"
    case ">=" => "<="
    case _ => "???"
  }

  def isBinaryProductWithConstantBoundsEmpty(op1: String, op2: String, v1: Double, v2: Double): Boolean = (op1, op2) match {
    case ("<", "=") | ("<", ">=") | ("<", ">") | ("<=", ">") | ("=", ">") => v2 <= v1 
    case ("<=", "=") | ("<=", ">=") | ("=", ">=") => v2 < v1 
    case ("=", "<") | (">=", "<") | (">", "<") | (">", "<=") | (">", "=") => v2 >= v1
    case ("=", "<=") | (">=", "<=") | (">=", "=") => v2 > v1
    case ("=", "=") => v1 != v2
    case _ => false
  }

  def isBinaryProductEmpty(e1: Exp, e2: Exp): Boolean = {
    if (e1 == e2) false
    else {
      (e1, e2) match {
        case (c1 @ Comparison(op1, index1, variable1), c2 @ Comparison(op2, index2, variable2)) => {
          (index1, index2) match {
            case (i1 @ Variable(_), i2 @ Variable(_)) => {
              if (i1 == i2 && variable1 == variable2) {
                if (opEmpty(op1).contains(op2)) true
                else false
              } else if (i1 == variable2 && i2 == variable1) {
                if (opEmpty(op1).contains(opComplement(op2))) true
                else false
              } else false
            }
            case (ConstantInt(v1), ConstantInt(v2)) => isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case (ConstantInt(v1), ConstantDouble(v2)) => isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case (ConstantDouble(v1), ConstantInt(v2)) => isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case (ConstantDouble(v1), ConstantDouble(v2)) => isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case _ => {
              if (index1 == index2 && variable1 == variable2) {
                if (opEmpty(op1).contains(op2)) true
                else false
              } else false
            }
          }
        }
        case _ => false
      }
    }
  }

  def isProductEmpty(prod: Prod): Boolean = prod.exps.combinations(2).exists { case Seq(e1, e2) => isBinaryProductEmpty(e1, e2) }

  def removeEmptyProductsOpt(r: Rule): Rule = Rule(r.head, SoP(r.body.prods.filterNot(isProductEmpty)))

  def getNonDimensionVariables(prod: Prod): Seq[Variable] = prod.exps.flatMap {
      case Access(_, vars, _) => vars.distinct
      case _ => Seq()
    }.distinct

  def getNonDimensionVariables(sop: SoP): Seq[Variable] = sop.prods.flatMap(getNonDimensionVariables).distinct

  def getNonDimensionVariables(rule: Rule): Seq[Variable] = (rule.head.vars ++ getNonDimensionVariables(rule.body)).distinct

  def alphaRename(index: Index, alphaRenameMap: Map[Variable, Variable]): Index = index match {
    case v: Variable => alphaRenameMap.getOrElse(v, v)
    case Arithmetic(op, i1, i2) => Arithmetic(op, alphaRename(i1, alphaRenameMap), alphaRename(i2, alphaRenameMap))
    case _ => index
  }

  def alphaRename(sop: SoP, alphaRenameMap: Map[Variable, Variable]): SoP = {
    SoP(sop.prods.map(p => {
      Prod(p.exps.map {
        case Access(n, v, k) => Access(n, v.map(v2 => alphaRenameMap.getOrElse(v2, v2)), k)
        case Comparison(op, i, v) => Comparison(op, alphaRename(i, alphaRenameMap), alphaRenameMap.getOrElse(v, v))
        case _ => throw new Exception("Unknown expression")
      })
    }))
  }

  def containsByName(m: Map[Access, SoP], access: Access): Boolean = m.exists {
    case (key, _) if key.name == access.name => true
    case _ => false
  }

  def getByNameAndAlphaRename(m: Map[Access, SoP], access: Access): Option[SoP] = m.collectFirst {
    case (key, value) if key.name == access.name => {
      val nonDimVarsValue = getNonDimensionVariables(value)
      val alphaRenameRequiredVars = nonDimVarsValue.diff(key.vars)
      val alphaRenameMap = (key.vars.zip(access.vars) ++ alphaRenameRequiredVars.map(v => (v -> Variable(getVar("i"))))).toMap
      alphaRename(value, alphaRenameMap)
    } 
  }

  def getEqualVariables(rule: Rule): Seq[Seq[Seq[Variable]]] = {
    val binaryEqualSets = rule.body.prods.map(p => {
      p.exps.flatMap {
        case Comparison("=", i1, i2) => {
          (i1, i2) match {
            case (v1: Variable, v2: Variable) => Set(Set(v1, v2))
            case _ => Set()
          }
        }
        case _ => Set()
      }.toSet
    }).distinct

    // Merge equal binary sets:
    val mergedSets = binaryEqualSets.map(setOfSets => setOfSets.foldLeft(Set[Set[Variable]]()) { (merged, current) =>
      val (toMerge, rest) = merged.partition(_.intersect(current).nonEmpty)
      val mergedSet = toMerge.flatten ++ current
      rest + mergedSet
    })

    // Transform the set of sets to seq of seq of variables
    mergedSets.map(_.map(_.toSeq).toSeq)
  }

  def replaceEqualVariableInIndex(index: Index, equalVariablesSet: Seq[Seq[Variable]]): Index = index match {
    case v: Variable => {
      val equalSet = equalVariablesSet.find(_.contains(v))
      equalSet match {
        case Some(set) => set.head
        case None => v
      }
    }
    case a @ Arithmetic(op, i1, i2) => Arithmetic(op, replaceEqualVariableInIndex(i1, equalVariablesSet), replaceEqualVariableInIndex(i2, equalVariablesSet))
    case _ => index
  }

  def replaceEqualVariablesInExp(exp: Exp, equalVariablesSet: Seq[Seq[Variable]]): Seq[Exp] = exp match {
    case Access(n, v, k) => Seq(Access(n, v.map(v2 => {
      val equalSet = equalVariablesSet.find(_.contains(v2))
      equalSet match {
        case Some(set) => set.head
        case None => v2
      }
    }), k))
    case c @ Comparison(op, i, v) => op match {
      // In case it is equality and one of the variables is head of the set, 
      // don't replace it since the variables in head are not being replace to keep the number the rules one
      case "=" => (i, v) match {
        case (v1: Variable, v2: Variable) => {
          val equalSet1 = equalVariablesSet.find(_.contains(v1))
          val equalSet2 = equalVariablesSet.find(_.contains(v2))
          (equalSet1, equalSet2) match {
            case (Some(set1), _) if set1.head == v1 => Seq(c)
            case (_, Some(set2)) if set2.head == v2 => Seq(c)
            case (Some(set1), None) => Seq(Comparison("=", set1.head, v2))
            case (None, Some(set2)) => Seq(Comparison("=", v1, set2.head))
            case (Some(set1), Some(set2)) if set1.head == set2.head => Seq(Comparison("=", set1.head, v2), Comparison("=", v1, set2.head))
            case (Some(set1), Some(set2)) => Seq(Comparison("=", set1.head, set2.head))
            case (None, None) => Seq(c)
          }
        }
        case _ => Seq(Comparison(op, replaceEqualVariableInIndex(i, equalVariablesSet), {
          val equalSet = equalVariablesSet.find(_.contains(v))
          equalSet match {
            case Some(set) => set.head
            case None => v
          }
        }))
      }
      case _ => Seq(Comparison(op, replaceEqualVariableInIndex(i, equalVariablesSet), {
        val equalSet = equalVariablesSet.find(_.contains(v))
        equalSet match {
          case Some(set) => set.head
          case None => v
        }
      }))
    }
    case _ => throw new Exception("Unknown expression")
  }

  def replaceEqualVariables(rule: Rule): Rule = {
    val equalVariablesSet = getEqualVariables(rule)
    val newBody = SoP(rule.body.prods.zip(equalVariablesSet).map{ case (p, eSet) => {
      Prod(p.exps.map(exp => replaceEqualVariablesInExp(exp, eSet)).flatten)
    }})
    
    Rule(rule.head, newBody)
  }
}