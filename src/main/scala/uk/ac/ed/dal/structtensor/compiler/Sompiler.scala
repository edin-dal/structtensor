package uk.ac.ed.dal
package structtensor
package compiler

object Sompiler {
  import STURHelper._
  import Optimizer._

  var cnt = 0
  def getVar(name: String): String = {
    cnt += 1
    return s"$name$cnt"
  }

  def getNonDimensionVariables(prod: Prod): Seq[Variable] = prod.exps.flatMap {
      case Access(_, vars, _) => vars.distinct
      case _ => Seq()
    }.distinct

  def getNonDimensionVariables(sop: SoP): Seq[Variable] = sop.prods.flatMap(getNonDimensionVariables).distinct

  def getNonDimensionVariables(rule: Rule): Seq[Variable] = (rule.head.vars ++ getNonDimensionVariables(rule.body)).distinct


  def getAllVariables(index: Index): Seq[Variable] = {
    index match {
      case v @ Variable(name) => Seq(v)
      case Arithmetic(op, index1, index2) => getAllVariables(index1) ++ getAllVariables(index2)
      case _ => Seq()
    }
  }

  def getAllVariables(exp: Exp): Seq[Variable] = {
    exp match {
      case Access(_, vars, _) => vars
      case Comparison(_, index, variable) => Seq(variable) ++ getAllVariables(index)
      case _ => Seq[Variable]()
    }
  }

  def appendDistinctVars(v1: Seq[Variable], v2: Seq[Variable]): Seq[Variable] = (v1.distinct ++ v2.distinct).distinct

  def isPairwiseIntersectEmpty(vars: Seq[Seq[Variable]]): Boolean = vars.zipWithIndex.flatMap { case (seq1, index1) =>
        vars.zipWithIndex.collect {
          case (seq2, index2) if index1 < index2 => seq1.intersect(seq2).isEmpty
        }
      }.forall(_ == true)

  def groupBySameName(exp: Exp, rest: Seq[Exp]): Seq[Exp] = {
    exp match {
      case acc @ Access(name, _, _) => {
        val sameNameList = rest.collect {
          case access @ Access(name2, _, _) if name2 == name => access
        } ++ Seq(acc)
        if (sameNameList.length == 1) Seq(exp)
        else if (isPairwiseIntersectEmpty(sameNameList.map(e => e.vars))) sameNameList
        else Seq(exp)
      }
      case _ => Seq(exp)
    }
  }


  def normalizeSingleProdRule(r: Rule): Seq[Rule] = {
    assert(r.body.prods.length == 1)
    val prod = r.body.prods(0)
    val nonSizeVariables = getNonDimensionVariables(r).distinct
    if (prod.exps.length < 2) Seq(r)
    else if (prod.exps.length == 2 && r.head.vars.toSet == appendDistinctVars(getAllVariables(prod.exps(0)), getAllVariables(prod.exps(1))).filter(nonSizeVariables.contains).toSet) Seq(r)
    else {
      val sameNameExpsList = groupBySameName(prod.exps(0), prod.exps.slice(1, prod.exps.length))
      if (sameNameExpsList.length == 1) {
        val newVariables = appendDistinctVars(getAllVariables(prod.exps(0)), getAllVariables(prod.exps(1))).filter(nonSizeVariables.contains)
        val newHead = Access(getVar("prodHead"), newVariables, Tensor)
        val newBody = SoP(Seq(Prod(Seq(prod.exps(0), prod.exps(1)))))
        val newRule = Rule(newHead, newBody)

        val restBody = SoP(Seq(Prod(Seq(newHead) ++ prod.exps.slice(2, prod.exps.length))))
        Seq(newRule) ++ normalizeSingleProdRule(Rule(r.head, restBody))
      } else {
        val newVariables = sameNameExpsList.flatMap{case acc @ Access(_, vars, _) => vars} // This one does not distinct since the intersection of the variables is empty
        val newHead = Access(getVar("sameNameProdHead"), newVariables, Tensor)
        val newBody = SoP(Seq(Prod(sameNameExpsList)))
        val newRule = Rule(newHead, newBody)

        val restBody = SoP(Seq(Prod(Seq(newHead) ++ prod.exps.filter(!sameNameExpsList.contains(_)))))
        Seq(newRule) ++ normalizeSingleProdRule(Rule(r.head, restBody))
      }
    }
  }

  def normalizeSingleSumRule(r: Rule): Seq[Rule] = {
    Seq(r)
  }

  def normalize(r: Rule): Seq[Rule] = {
    val seqOfSeqOfRules = r.body.prods.map(prod => normalizeSingleProdRule(Rule(Access(getVar("interHead"), r.head.vars, Tensor), SoP(Seq(prod)))))
    seqOfSeqOfRules(0)
  }

  def isShift(exps: Seq[Exp], outAccess: Access): Boolean = {
    if (exps.length == 1) return false
    val e: Exp = exps(0)
    val flag: Boolean = exps.slice(1, exps.length).foldLeft(e.isInstanceOf[Access])((acc, cur) => acc && cur.isInstanceOf[Comparison])
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

  def shift(lhs: Access, rhs: Access, exps: Seq[Exp]): (Rule, Rule, Rule) = {
    val usBody: SoP = SoP(Seq(Prod(Seq(rhs.uniqueHead) ++ exps)))
    val us: Rule = Rule(lhs.uniqueHead, usBody)

    val redExps: Seq[Exp] = exps.map(e => e.asInstanceOf[Comparison]).map(e => 
                            Comparison("=", Arithmetic("-", e.index.asInstanceOf[Arithmetic].index1.asInstanceOf[Variable].vars2RedundancyVars, 
                                                            e.index.asInstanceOf[Arithmetic].index2), 
                                      e.variable.vars2RedundancyVars))
    val rmBody: SoP = SoP(Seq(Prod(Seq(rhs.redundancyHead) ++ exps ++ redExps)))
    val rm: Rule = Rule(lhs.redundancyHead, rmBody)

    val cBody: SoP = SoP(Seq(Prod(Seq(rhs.compressedHead, rhs.uniqueHead) ++ exps)))
    val c: Rule = Rule(lhs.compressedHead, cBody)

    return (us, rm, c)
  }

  def project(lhs: Access, rhs: Access): (Rule, Rule, Rule) = {
    assert(lhs.vars.toSet.subsetOf(rhs.vars.toSet))
    if (lhs.vars.toSet == rhs.vars.toSet) {
      val us = Rule(lhs.uniqueHead, SoP(Seq(Prod(Seq(rhs.uniqueHead)))))
      val rm = Rule(lhs.redundancyHead, SoP(Seq(Prod(Seq(rhs.redundancyHead)))))
      val c = Rule(lhs.compressedHead, SoP(Seq(Prod(Seq(rhs.compressedHead)))))
      (us, rm, c)
    } else {
      val us = Rule(lhs.uniqueHead, SoP(Seq(Prod(Seq(rhs.uniqueHead)), Prod(Seq(rhs.redundancyHead)))))
      val rm = Rule(lhs.redundancyHead, emptySoP())
      val c = Rule(lhs.compressedHead, SoP(Seq(Prod(Seq(rhs.compressedHead)), Prod(Seq(rhs.redundancyHead, rhs.compressedHead.vars2RedundancyVars)))))      
      (us, rm, c)
    }
  }

  def isIntersectEmpty(inpVars1: Seq[Variable], inpVars2: Seq[Variable]): Boolean = inpVars1.intersect(inpVars2).isEmpty

  def vectorizeComparisonMultiplication(op: String, varsLeft: Seq[Variable], varsRight: Seq[Variable]): Seq[Comparison] = (varsLeft zip varsRight).map{case(v1, v2) => Comparison(op, v1, v2)}


  def binMult(lhs: Access, e1: Exp, e2: Exp): (Rule, Rule, Rule) = {
    (e1, e2) match {
      case (acc1 @ Access(name1, vars1, Tensor), acc2 @ Access(name2, vars2, Tensor)) => {
        if (name1 == name2 && lhs.vars.toSet == vars1.union(vars2).toSet && isIntersectEmpty(vars1, vars2)) {
          val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("<=", vars1, vars2))))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(Seq(
            Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars)),
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars)),
            Prod(Seq(acc1.uniqueHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars) ++ vectorizeComparisonMultiplication(">", vars1, vars2))
          ))
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(Seq(Prod(Seq(acc1.compressedHead, acc2.compressedHead) ++ vectorizeComparisonMultiplication("<=", vars1, vars2))))
          val c = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        } else if (lhs.vars.toSet == vars1.union(vars2).toSet && isIntersectEmpty(vars1, vars2)) {
          val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead))))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(Seq(
            Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars)),
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars))
          ))
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(Seq(Prod(Seq(acc1.compressedHead, acc2.compressedHead))))
          val c = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        } else if (lhs.vars.toSet == vars1.union(vars2).toSet) {
          val usBody = SoP(Seq(
            Prod(Seq(acc1.uniqueHead, acc2.uniqueHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead)),
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead))
          ))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(Seq(Prod(Seq(acc1.redundancyHead, acc2.redundancyHead))))
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(Seq(
            Prod(Seq(acc1.compressedHead, acc2.compressedHead)),
            Prod(Seq(acc1.compressedHead, acc2.redundancyHead, acc2.vars2RedundancyVars)),
            Prod(Seq(acc1.redundancyHead, acc2.compressedHead, acc1.vars2RedundancyVars))
          ))
          val c = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        }
      }
      case (Access(name1, vars1, Tensor), Comparison(op2, index2, variable2)) => {
        val acc1: Access = e1.asInstanceOf[Access]
        val usBody: SoP = SoP(Seq(Prod(Seq(acc1.uniqueHead, e2))))
        val us: Rule = Rule(lhs.uniqueHead, usBody)

        val rmBody: SoP = SoP(Seq(Prod(Seq(acc1.redundancyHead, e2))))
        val rm: Rule = Rule(lhs.redundancyHead, rmBody)

        val cBody: SoP = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc1.compressedHead, e2))))
        val c: Rule = Rule(lhs.compressedHead, cBody)

        return (us, rm, c)
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) => binMult(lhs, e2, e1)
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

          val usBody: SoP = SoP(Seq(Prod(Seq(Comparison("=", indEq, variable)))))
          val us: Rule = Rule(lhs.uniqueHead, usBody)

          val rmBody: SoP = SoP(Seq(Prod(Seq(Comparison("<", indEq, variable), Comparison(">", indGt, variable), Comparison("=", indEq, variable.redundancyVars)))))
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody: SoP = SoP(Seq(Prod(Seq(Comparison("=", indEq, variable)))))
          val c: Rule = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        } else {
          val usBody: SoP = SoP(Seq(Prod(Seq(e1, e2))))
          val us: Rule = Rule(lhs.uniqueHead, usBody)

          val rmBody: SoP = emptySoP()
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody: SoP = SoP(Seq(Prod(Seq(e1, e2))))
          val c: Rule = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        }
      }
    }
    (Rule(lhs.uniqueHead, emptySoP()), Rule(lhs.redundancyHead, emptySoP()), Rule(lhs.compressedHead, emptySoP()))
  }

  def infer(r: Rule): (Rule, Rule, Rule) = {
    val head: Access = r.head
    val prods: Seq[Prod] = r.body.prods
    assert(prods.length <= 2)
    if (prods.length == 1) {
      val exps: Seq[Exp] = prods(0).exps
      if (isShift(exps, head)) {
        return shift(head, exps(0).asInstanceOf[Access], exps.slice(1, exps.length))
      } else if (exps.length == 1) {
        assert(exps(0).isInstanceOf[Access])
        return project(head, exps(0).asInstanceOf[Access])
      } else if (exps.length == 2) {
        return binMult(head, exps(0), exps(1))
      } else {
        throw new Exception("Not implemented yet")
      }
    } else if (prods.length == 2) {
      throw new Exception("Not implemented yet")
    } else throw new Exception("Only binary computation must be passed to infer function")
  }

  def compile(computation: Rule, inputs: Seq[(Rule, Rule, Rule, Rule)]): (Rule, Rule) = {
    // println(s"------------------\nComputation:\n${computation.prettyFormat}\n")
    val norm = normalizeSingleProdRule(computation)
    
    val us_rm_cc_tc_seq = norm.map(infer).zip(norm).map{case((r1, r2, r3), r4) => (r1, r2, r3, r4)}
    us_rm_cc_tc_seq.map{case(r1, r2, r3, r4) => println(s"====================\nUnique:\n${r1.prettyFormat}\nRedundancy:\n${r2.prettyFormat}\nCompressed:\n${r3.prettyFormat}\nComputation:\n${r4.prettyFormat}\n")}

    
    
    // Optimization
    val (denormUS, denormRM, denormCC, denormTC) = denormalize(computation.head, inputs ++ us_rm_cc_tc_seq)
    // println(s"------------------\nDenormalized:\n${denormCC.prettyFormat}\n${denormRM.prettyFormat}\n")
    
    val (idempotentOptCC, idempotentOptRC) = (setIdempotentOpt(denormCC), setIdempotentOpt(denormRM))
    println(s"=================================\nOptimized:\n${idempotentOptCC.prettyFormat}\n${idempotentOptRC.prettyFormat}\n")

    (denormCC, denormRM)
  }
}