package uk.ac.ed.dal
package structtensor
package compiler

object Sompiler {
  import STURHelper._

  def normalize(r: Rule): Seq[Rule] = {
    return r
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

  def shift(lhs: Access, rhs: Access, exps: Seq[Exp]): (Rule, Rule, Rule) = {
    val usBody: SoP = SoP(Seq(Prod(Seq(Seq(rhs.uniqueHead) ++ exps))))
    val us: Rule = Rule(lhs.uniqueHead, usBody)

    val redExps: Seq[Exp] = exps.map(e => e.asInstanceOf[Comparison]).map(e => 
                            Comparison("=", Arithmetic("-", e.index.asInstanceOf[Arithmetic].index1.asInstanceOf[Variable].vars2RedundancyVars, 
                                                            e.index.asInstanceOf[Arithmetic].index2), 
                                      e.variable.vars2RedundancyVars))
    val rmBody: SoP = SoP(Seq(Prod(Seq(Seq(rhs.redundancyHead) ++ exps ++ redExps))))
    val rm: Rule = Rule(lhs.redundancyHead, rmBody)

    val cBody: SoP = SoP(Seq(Prod(Seq(Seq(rhs.compressedHead, rhs.uniqueHead) ++ exps))))
    val c: Rule = Rule(lhs.compressedHead, cBody)

    return (us, rm, c)
  }

  def project(lhs: Access, rhs: Access): (Rule, Rule, Rule) = {
    assert(rhs.vars.toSet.subsetOf(lhs.vars.toSet))
    if (lhs.vars.toSet == rhs.vars.toSet) {
      val us: Rule = Rule(lhs.uniqueHead, rhs.uniqueHead)
      val rm: Rule = Rule(lhs.redundancyHead, rhs.redundancyHead)
      val c: Rule = Rule(lhs.compressedHead, rhs.compressedHead)
      return (us, rm, c)
    }

    val usBody: SoP = SoP(Seq(Prod(Seq(rhs.uniqueHead)), Prod(Seq(rhs.redundancyHead))))
    val us: Rule = Rule(lhs.uniqueHead, usBody)

    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(lhs.redundancyHead, rmBody)

    val cBody: SoP = SoP(Seq(Prod(Seq(rhs.uniqueHead, rhs.compressedHead)), Prod(Seq(rhs.redundancyHead, rhs.compressedHead.vars2RedundancyVars))))
    val c: Rule = Rule(lhs.compressedHead, cBody)

    return (us, rm, c)
  }

  def isIntersectEmpty(inpVars1: Seq[Variable], inpVars2: Seq[Variable]): Boolean = inpVars1.intersect(inpVars2).isEmpty

  def vectorizeComparisonMultiplication(op: String, varsLeft: Seq[Variable], varsRight: Seq[Variable]): Seq[Comparison] = (varsLeft zip varsRight).map{case(v1, v2) => Comparison(op, v1, v2)}


  def binMult(lhs: Access, e1: Exp, e2: Exp): (Rule, Rule, Rule) = {
    (e1, e2) match {
      case (Access(name1, vars1, Tensor), Access(name2, vars2, Tensor)) => {
        val acc1: Access = e1.asInstanceOf[Access]
        val acc2: Access = e2.asInstanceOf[Access]
        if (name1 == name2 && lhs.vars.toSet == vars1.union(vars2).toSet && isIntersectEmpty(vars1, vars2)) {          
          val usBody: SoP = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("<=", vars1, vars2))))
          val us: Rule = Rule(lhs.uniqueHead, usBody)

          val rmBody: SoP = SoP(Seq(
            Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars)),
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars)),
            Prod(Seq(acc1.uniqueHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars) ++ vectorizeComparisonMultiplication(">", vars1, vars2))
          ))
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody: SoP = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead, acc1.compressedHead, acc2.compressedHead) ++ vectorizeComparisonMultiplication("<=", vars1, vars2))))
          val c: Rule = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        } else if (lhs.vars.toSet == vars1.union(vars2).toSet && isIntersectEmpty(vars1, vars2)) {
          val usBody: SoP = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead))))
          val us: Rule = Rule(lhs.uniqueHead, usBody)

          val rmBody: SoP = SoP(Seq(
            Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars)),
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars)),
            Prod(Seq(acc1.uniqueHead, acc2.uniqueHead) ++ vectorizeComparisonMultiplication("=", vars1, vars1.redundancyVars) ++ vectorizeComparisonMultiplication("=", vars2, vars2.redundancyVars))
          ))
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody: SoP = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead, acc1.compressedHead, acc2.compressedHead))))
          val c: Rule = Rule(lhs.compressedHead, cBody)

          return (us, rm, c)
        } else if (lhs.vars.toSet == vars1.union(vars2).toSet) {
          val usBody: SoP = SoP(Seq(
            Prod(Seq(acc1.uniqueHead, acc2.uniqueHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead))
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead))
          ))
          val us: Rule = Rule(lhs.uniqueHead, usBody)

          val rmBody: SoP = SoP(Seq(Prod(Seq(acc1.redundancyHead, acc2.redundancyHead))))
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody: SoP = SoP(Seq(
            Prod(Seq(acc1.uniqueHead, acc2.uniqueHead, acc1.compressedHead, acc2.compressedHead)),
            Prod(Seq(acc1.uniqueHead, acc2.redundancyHead, acc1.compressedHead, acc2.compressedHead.redundancyVars))
            Prod(Seq(acc1.redundancyHead, acc2.uniqueHead, acc1.compressedHead.redudancyVars, acc2.compressedHead))
          ))
          val c: Rule = Rule(lhs.compressedHead, cBody)

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
        
      }
    } else if (prods.length == 2) {
      

    }
    return (r, r, r)
  }

  def denormalize(head: Access, ctx: Seq[(Rule, Rule, Rule, Rule)]): Rule = {
    return ctx(0)._1
  }

  def compile(computation: Rule, inputs: Seq[(Rule, Rule, Rule, Rule)]): Rule = {
    val norm: Seq[Rule] = normalize(computation)
    val rules: Seq[(Rule, Rule, Rule, Rule)] = norm.map(infer).zip(norm)
    val denorm: Rule = denormalize(computation.head, inputs ++ rules)
  }
}