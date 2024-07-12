package uk.ac.ed.dal
package structtensor
package compiler

import utils._

object Compiler {
  import Utils._
  import Optimizer._
  import scala.annotation.tailrec

  def getAllVariables(index: Index): Seq[Variable] = {
    index match {
      case v @ Variable(name) => Seq(v)
      case Arithmetic(op, index1, index2) =>
        getAllVariables(index1) ++ getAllVariables(index2)
      case _ => Seq()
    }
  }

  def getAllVariables(exp: Exp): Seq[Variable] = {
    exp match {
      case Access(_, vars, _) => vars
      case Comparison(_, index, variable) =>
        Seq(variable) ++ getAllVariables(index)
      case _ => Seq[Variable]()
    }
  }

  def appendDistinctVars(v1: Seq[Variable], v2: Seq[Variable]): Seq[Variable] =
    (v1.distinct ++ v2.distinct).distinct

  def isPairwiseIntersectEmpty(vars: Seq[Seq[Variable]]): Boolean =
    vars.zipWithIndex
      .flatMap { case (seq1, index1) =>
        vars.zipWithIndex.collect {
          case (seq2, index2) if index1 < index2 => seq1.intersect(seq2).isEmpty
        }
      }
      .forall(_ == true)

  def groupBySameName(
      exp: Exp,
      rest: Seq[Exp],
      isThereAnySameNameLeft: Boolean = true,
      init_exp: Exp = null
  ): (Seq[Exp], Boolean) = {
    if (!isThereAnySameNameLeft || rest.isEmpty)
      if (init_exp == null) (Seq(exp), false)
      else (Seq(init_exp), false)
    else {
      val real_init_exp = if (init_exp == null) exp else init_exp
      exp match {
        case acc @ Access(name, _, _) => {
          val sameNameList = rest.collect {
            case access @ Access(name2, _, _) if name2 == name => access
          } ++ Seq(acc)
          if (sameNameList.length == 1)
            groupBySameName(
              rest.head,
              rest.tail,
              isThereAnySameNameLeft = true,
              init_exp = real_init_exp
            )
          else if (isPairwiseIntersectEmpty(sameNameList.map(e => e.vars)))
            (sameNameList, true)
          else
            groupBySameName(
              rest.head,
              rest.tail,
              isThereAnySameNameLeft = true,
              init_exp = real_init_exp
            )
        }
        case _ => (Seq(exp), true)
      }
    }
  }

  def normalizeSingleProdRule(
      r: Rule,
      isThereAnySameNameLeft: Boolean = true
  ): Seq[Rule] = {
    assert(r.body.prods.length == 1)
    val prod = r.body.prods.head
    val nonSizeVariables = getNonDimensionVariables(r).distinct
    if (prod.exps.length < 2) Seq(r)
    else if (
      prod.exps.length == 2 && r.head.vars.toSet == appendDistinctVars(
        getAllVariables(prod.exps.head),
        getAllVariables(prod.exps(1))
      ).filter(nonSizeVariables.contains).toSet
    ) Seq(r)
    else {
      val (sameNameExpsList, itasnl) =
        groupBySameName(prod.exps.head, prod.exps.tail, isThereAnySameNameLeft)
      if (sameNameExpsList.length == 1) {
        prod.exps.head match {
          case acc @ Access(_, vars, _)
              if (prod.exps.length > vars.length && isShift(
                r.head,
                prod.exps.slice(0, vars.length + 1)
              )) => {
            val newHead = Access(getVar("shiftHead"), r.head.vars, Tensor)
            val newBody = SoP(Seq(Prod(prod.exps.slice(0, vars.length + 1))))
            val newRule = Rule(newHead, newBody)

            val restBody = SoP(
              Seq(
                Prod(
                  Seq(newHead) ++ prod.exps
                    .slice(vars.length + 1, prod.exps.length)
                )
              )
            )
            Seq(newRule) ++ normalizeSingleProdRule(
              Rule(r.head, restBody),
              itasnl
            )
          }
          case _ => {
            val newVariables = appendDistinctVars(
              getAllVariables(prod.exps.head),
              getAllVariables(prod.exps(1))
            ).filter(nonSizeVariables.contains)
            val newHead = Access(getVar("prodHead"), newVariables, Tensor)
            val newBody = SoP(Seq(Prod(Seq(prod.exps.head, prod.exps(1)))))
            val newRule = Rule(newHead, newBody)

            val restBody = SoP(
              Seq(Prod(Seq(newHead) ++ prod.exps.slice(2, prod.exps.length)))
            )
            Seq(newRule) ++ normalizeSingleProdRule(
              Rule(r.head, restBody),
              itasnl
            )
          }
        }
      } else {
        val newVariables = sameNameExpsList.flatMap {
          case acc @ Access(_, vars, _) => vars
        } // This one does not distinct since the intersection of the variables is empty
        val newHead = Access(getVar("sameNameProdHead"), newVariables, Tensor)
        val newBody = SoP(Seq(Prod(sameNameExpsList)))
        val newRule = Rule(newHead, newBody)

        val restBody = SoP(
          Seq(
            Prod(
              Seq(newHead) ++ prod.exps.diff(sameNameExpsList)
            )
          )
        )
        Seq(newRule) ++ normalizeSingleProdRule(Rule(r.head, restBody), itasnl)
      }
    }
  }

  def normalizeSumOfAccessSeq(head: Access, accSeq: Seq[Access]): Seq[Rule] = {
    // We made sure in the previous function that all of them have the exact same variables as head
    if (accSeq.length == 1) Seq(Rule(head, SoP(Seq(Prod(Seq(accSeq.head))))))
    else {
      val newHead = Access(getVar("sumHead"), head.vars, Tensor)
      val newBody = SoP(Seq(Prod(Seq(accSeq(0))), Prod(Seq(accSeq(1)))))
      val newRule = Rule(newHead, newBody)

      val restAccessSeq = Seq(newHead) ++ accSeq.slice(2, accSeq.length)
      Seq(newRule) ++ normalizeSumOfAccessSeq(head, restAccessSeq)
    }
  }

  def normalize(r: Rule): Seq[Rule] = {
    if (r.body.prods.length == 1) normalizeSingleProdRule(r)
    else {
      val normalizedProdsANDIntermediateHeads: Seq[(Seq[Rule], Access)] =
        r.body.prods.map(prod => {
          val intermediateHead =
            Access(getVar("interHead"), r.head.vars, Tensor)
          val inputRule = Rule(intermediateHead, SoP(Seq(prod)))
          (normalizeSingleProdRule(inputRule), intermediateHead)
        })
      val normalizedProds = normalizedProdsANDIntermediateHeads.flatMap(_._1)
      val intermediateHeads = normalizedProdsANDIntermediateHeads.map(_._2)
      normalizedProds ++ normalizeSumOfAccessSeq(r.head, intermediateHeads)
    }
  }

  def isShift(lhs: Access, exps: Seq[Exp]): Boolean = {
    if (exps.length == 1) false
    else {
      val areAllExpsComparison = exps.tail.forall {
        case _: Comparison => true
        case _             => false
      }
      if (areAllExpsComparison) {
        exps.head match {
          case Access(_, vars, _) =>
            exps.tail.forall {
              case Comparison("=", index: Arithmetic, variable)
                  if vars.contains(variable) => {
                index match {
                  case Arithmetic("-", index1: Variable, _) =>
                    lhs.vars.contains(index1)
                  case _ => false
                }
              }
              case _ => false
            }
          case _ => false
        }
      } else false
    }
  }

  def shift(lhs: Access, rhs: Access, exps: Seq[Exp]): (Rule, Rule, Rule) = {
    val usBody = SoP(Seq(Prod(Seq(rhs.uniqueHead) ++ exps)))
    val us = Rule(lhs.uniqueHead, usBody)

    val redExps = exps.map {
      case Comparison(
            "=",
            Arithmetic("-", index1: Variable, index2),
            variable
          ) =>
        Comparison(
          "=",
          Arithmetic("-", index1.vars2RedundancyVars, index2),
          variable.vars2RedundancyVars
        )
      case exp => exp
    }
    val rmBody = SoP(Seq(Prod(Seq(rhs.redundancyHead) ++ exps ++ redExps)))
    val rm = Rule(lhs.redundancyHead, rmBody)

    val cBody = SoP(Seq(Prod(Seq(rhs.compressedHead) ++ exps)))
    val c = Rule(lhs.compressedHead, cBody)

    (us, rm, c)
  }

  def project(lhs: Access, rhs: Access): (Rule, Rule, Rule) = {
    assert(lhs.vars.toSet.subsetOf(rhs.vars.toSet))
    if (lhs.vars.toSet == rhs.vars.toSet) {
      val us = Rule(lhs.uniqueHead, SoP(Seq(Prod(Seq(rhs.uniqueHead)))))
      val rm = Rule(lhs.redundancyHead, SoP(Seq(Prod(Seq(rhs.redundancyHead)))))
      val c = Rule(lhs.compressedHead, SoP(Seq(Prod(Seq(rhs.compressedHead)))))
      (us, rm, c)
    } else {
      val us = Rule(
        lhs.uniqueHead,
        SoP(Seq(Prod(Seq(rhs.uniqueHead)), Prod(Seq(rhs.redundancyHead))))
      )
      val rm = Rule(lhs.redundancyHead, emptySoP())
      val c = Rule(
        lhs.compressedHead,
        SoP(
          Seq(
            Prod(Seq(rhs.compressedHead)),
            Prod(
              Seq(rhs.redundancyHead, rhs.vars2RedundancyVars.compressedHead())
            )
          )
        )
      )
      (us, rm, c)
    }
  }

  def isIntersectEmpty(
      inpVars1: Seq[Variable],
      inpVars2: Seq[Variable]
  ): Boolean = inpVars1.intersect(inpVars2).isEmpty

  def vectorizeComparisonMultiplication(
      op: String,
      varsLeft: Seq[Variable],
      varsRight: Seq[Variable]
  ): Seq[Comparison] = (varsLeft zip varsRight).map { case (v1, v2) =>
    Comparison(op, v1, v2)
  }

  def binMult(lhs: Access, e1: Exp, e2: Exp): (Rule, Rule, Rule) = {
    (e1, e2) match {
      case (
            acc1 @ Access(name1, vars1, Tensor),
            acc2 @ Access(name2, vars2, Tensor)
          ) => {
        if (
          name1 == name2 && lhs.vars.toSet == vars1
            .union(vars2)
            .toSet && isIntersectEmpty(vars1, vars2)
        ) {
          val usBody = SoP(
            Seq(
              Prod(
                Seq(
                  acc1.uniqueHead,
                  acc2.uniqueHead
                ) ++ vectorizeComparisonMultiplication("<=", vars1, vars2)
              )
            )
          )
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(
            Seq(
              Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)),
              Prod(
                Seq(
                  acc1.uniqueHead,
                  acc2.redundancyHead
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars1,
                  vars1.redundancyVars
                )
              ),
              Prod(
                Seq(
                  acc1.redundancyHead,
                  acc2.uniqueHead
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars2,
                  vars2.redundancyVars
                )
              ),
              Prod(
                Seq(
                  acc1.uniqueHead,
                  acc2.uniqueHead
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars1,
                  vars2.redundancyVars
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars2,
                  vars1.redundancyVars
                ) ++ vectorizeComparisonMultiplication(">", vars1, vars2)
              )
            )
          )
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(
            Seq(
              Prod(
                Seq(
                  acc1.compressedHead,
                  acc2.compressedHead
                ) ++ vectorizeComparisonMultiplication("<=", vars1, vars2)
              )
            )
          )
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        } else if (
          lhs.vars.toSet == vars1.union(vars2).toSet && isIntersectEmpty(
            vars1,
            vars2
          )
        ) {
          val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead, acc2.uniqueHead))))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(
            Seq(
              Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)),
              Prod(
                Seq(
                  acc1.uniqueHead,
                  acc2.redundancyHead
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars1,
                  vars1.redundancyVars
                )
              ),
              Prod(
                Seq(
                  acc1.redundancyHead,
                  acc2.uniqueHead
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars2,
                  vars2.redundancyVars
                )
              )
            )
          )
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(
            Seq(Prod(Seq(acc1.compressedHead, acc2.compressedHead)))
          )
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        } else if (lhs.vars.toSet == vars1.union(vars2).toSet) {
          val usBody = SoP(
            Seq(
              Prod(Seq(acc1.uniqueHead, acc2.uniqueHead)),
              Prod(Seq(acc1.uniqueHead, acc2.redundancyHead)),
              Prod(Seq(acc1.redundancyHead, acc2.uniqueHead))
            )
          )
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(
            Seq(Prod(Seq(acc1.redundancyHead, acc2.redundancyHead)))
          )
          val rm: Rule = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(
            Seq(
              Prod(Seq(acc1.compressedHead, acc2.compressedHead)),
              Prod(
                Seq(
                  acc1.compressedHead,
                  acc2.redundancyHead,
                  acc2.vars2RedundancyVars.compressedHead()
                )
              ),
              Prod(
                Seq(
                  acc1.redundancyHead,
                  acc2.compressedHead,
                  acc1.vars2RedundancyVars.compressedHead()
                )
              )
            )
          )
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        } else
          throw new Exception(
            "This case should never happen in access-access multiplication. Function: binMult"
          )
      }
      case (
            acc1 @ Access(name1, vars1, Tensor),
            Comparison(op2, index2, variable2)
          ) => {
        val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead, e2))))
        val us = Rule(lhs.uniqueHead, usBody)

        val rmBody = SoP(Seq(Prod(Seq(acc1.redundancyHead, e2))))
        val rm = Rule(lhs.redundancyHead, rmBody)

        val cBody = SoP(Seq(Prod(Seq(acc1.compressedHead, e2))))
        val c = Rule(lhs.compressedHead, cBody)

        (us, rm, c)
      }
      case (Comparison(op1, index1, variable1), Access(name2, vars2, Tensor)) =>
        binMult(lhs, e2, e1)
      case (
            Comparison(op1, index1, variable1),
            Comparison(op2, index2, variable2)
          ) => {
        // These flags check for a <= x < b case
        val flag1 = op1 == "<=" && op2 == "<" && (index2 match {
          case v: Variable if variable1 == v => true
          case _                             => false
        })
        val flag2 = op1 == "<=" && op2 == ">" && variable1 == variable2
        val flag3 = op1 == ">=" && op2 == "<" && ((index1, index2) match {
          case (v1: Variable, v2: Variable) if v1 == v2 => true
          case _                                        => false
        })
        val flag4 = op1 == ">=" && op2 == ">" && (index1 match {
          case v: Variable if variable2 == v => true
          case _                             => false
        })

        val flag5 = op1 == "<" && op2 == "<=" && (index1 match {
          case v: Variable if variable2 == v => true
          case _                             => false
        })
        val flag6 = op1 == ">" && op2 == "<=" && variable2 == variable1
        val flag7 = op1 == "<" && op2 == ">=" && ((index1, index2) match {
          case (v1: Variable, v2: Variable) if v1 == v2 => true
          case _                                        => false
        })
        val flag8 = op1 == ">" && op2 == ">=" && (index2 match {
          case v: Variable if variable1 == v => true
          case _                             => false
        })

        if (
          flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8
        ) {
          val variable = if (flag1 || flag2 || flag8) {
            variable1
          } else if (flag3 || flag7) {
            index1 match {
              case v: Variable => v
              case _ =>
                throw new IllegalArgumentException("Expected a Variable")
            }
          } else {
            variable2
          }
          val indexEq =
            if (flag1 || flag2) index1
            else if (flag3 || flag4) variable1
            else if (flag5 || flag6) index2
            else variable2
          val indexGt =
            if (flag1 || flag3) variable2
            else if (flag2 || flag4) index2
            else if (flag5 || flag7) variable1
            else index1

          val usBody = SoP(Seq(Prod(Seq(Comparison("=", indexEq, variable)))))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(
            Seq(
              Prod(
                Seq(
                  Comparison("<", indexEq, variable),
                  Comparison(">", indexGt, variable),
                  Comparison("=", indexEq, variable.redundancyVars)
                )
              )
            )
          )
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(Seq(Prod(Seq(Comparison("=", indexEq, variable)))))
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        } else {
          val usBody = SoP(Seq(Prod(Seq(e1, e2))))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = emptySoP()
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(Seq(Prod(Seq(e1, e2))))
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        }
      }
      case _ =>
        throw new Exception(
          "Expression is either a comparison or an access. This error should never happen. Function: binMult"
        )
    }
  }

  def selfOuterProduct(lhs: Access, eSeq: Seq[Exp]): (Rule, Rule, Rule) = {
    val accSeq = eSeq.collect {
      case acc: Access => acc
      case _ =>
        throw new IllegalArgumentException(
          "All elements in the sequence must be of type Access."
        )
    }

    // we made sure in the normalization step that all the accesses have the same name and their variable pairwise intersection is empty
    val bodyUSComparisonSeq = (0 to accSeq.length - 2).flatMap(ind =>
      vectorizeComparisonMultiplication(
        "<=",
        accSeq(ind).vars,
        accSeq(ind + 1).vars
      )
    )
    val usBody = SoP(
      Seq(Prod(accSeq.map(acc => acc.uniqueHead) ++ bodyUSComparisonSeq))
    )
    val us = Rule(lhs.uniqueHead, usBody)

    val vectorizedMultVarEqualsRedundancyVarSeq = accSeq.map(acc =>
      vectorizeComparisonMultiplication("=", acc.vars, acc.vars.redundancyVars)
    )
    val bodyRMProdSeq1 = (0 to accSeq.length - 1).flatMap(i => {
      (0 to accSeq.length - 1)
        .combinations(i)
        .map(indexList => {
          Prod(
            (accSeq.zipWithIndex)
              .collect {
                case (acc, ind) if indexList.contains(ind) =>
                  vectorizedMultVarEqualsRedundancyVarSeq(ind) :+ acc.uniqueHead
                case (acc, ind) if !indexList.contains(ind) =>
                  Seq(acc.redundancyHead)
              }
              .flatten
              .toSeq
          )
        })
    })

    val allUSMult = accSeq.map(acc => acc.uniqueHead)
    val bodyRMSeq21: Seq[Prod] = (0 to accSeq.length - 1).permutations
      .map(iters => {
        val conds = (0 to iters.length - 2).flatMap(i =>
          vectorizeComparisonMultiplication(
            "<=",
            accSeq(iters(i)).vars,
            accSeq(iters(i + 1)).vars
          )
        )
        val swaps = (0 to iters.length - 1).flatMap(i =>
          vectorizeComparisonMultiplication(
            "=",
            accSeq(i).vars,
            accSeq(iters(i)).vars.redundancyVars
          )
        )
        Prod(conds ++ swaps ++ allUSMult)
      })
      .toSeq
    val bodyRMProdSeq2 = bodyRMSeq21.tail

    val rmBody = SoP(bodyRMProdSeq1 ++ bodyRMProdSeq2)
    val rm = Rule(lhs.redundancyHead, rmBody)

    val cBody = SoP(
      Seq(Prod(accSeq.map(acc => acc.compressedHead) ++ bodyUSComparisonSeq))
    )
    val c = Rule(lhs.compressedHead, cBody)

    (us, rm, c)
  }

  def locallyDenormalizeAndReturnBody(
      access: Access,
      ctx: Seq[(Rule, Rule, Rule, Rule)]
  ): SoP = {
    val requiredCtx = access.kind match {
      case UniqueSet     => ctx.map(_._1)
      case RedundancyMap => ctx.map(_._2)
      case _ =>
        throw new Exception(
          "You are not allowed to denormalize a compressed or a tensor access during inference."
        )
    }
    val denormMap = requiredCtx.foldLeft(Map[Access, SoP]())((acc, cur) => {
      val body = cur.head.kind match {
        case UniqueSet => Optimizer.denormalizeSingle(cur.body, acc, UniqueSet)
        case RedundancyMap =>
          Optimizer.denormalizeSingle(cur.body, acc, RedundancyMap)
        case _ =>
          throw new Exception("Must be a unique set or redundancy map type")
      }
      acc + (cur.head -> body)
    })
    denormMap(access)
  }

  def isSoPEquals(sop1: SoP, sop2: SoP): Boolean = {
    val prodsSet1 = sop1.prods.toSet
    val prodsSet2 = sop2.prods.toSet
    val prodsSetExpsSet1 = prodsSet1.map(s => s.exps.toSet)
    val prodsSetExpsSet2 = prodsSet2.map(s => s.exps.toSet)
    prodsSetExpsSet1 == prodsSetExpsSet2
  }

  def isSoPDisjoint(sop1: SoP, sop2: SoP): Boolean = {
    val sop = SoPTimesSoP(sop1, sop2)
    sop.prods.forall(isExpOrProductEmpty)
  }

  def binAdd(
      lhs: Access,
      e1: Exp,
      e2: Exp,
      ctx: Seq[(Rule, Rule, Rule, Rule)]
  ): (Rule, Rule, Rule) = {
    (e1, e2) match {
      case (acc1 @ Access(_, vars1, _), acc2 @ Access(_, vars2, _))
          if (vars1.toSet == vars2.toSet) => {
        val acc1UniqueSetBody =
          locallyDenormalizeAndReturnBody(acc1.uniqueHead, ctx)
        val acc2UniqueSetBody =
          locallyDenormalizeAndReturnBody(acc2.uniqueHead, ctx)
        val acc1RedundancyMapBody =
          locallyDenormalizeAndReturnBody(acc1.redundancyHead, ctx)
        val acc2RedundancyMapBody =
          locallyDenormalizeAndReturnBody(acc2.redundancyHead, ctx)

        if (
          isSoPEquals(acc1UniqueSetBody, acc2UniqueSetBody) && isSoPEquals(
            acc1RedundancyMapBody,
            acc2RedundancyMapBody
          )
        ) {
          val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead))))
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(Seq(Prod(Seq(acc1.redundancyHead))))
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(
            Seq(Prod(Seq(acc1.compressedHead)), Prod(Seq(acc2.compressedHead)))
          )
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        } else if (
          isSoPDisjoint(acc1UniqueSetBody, acc2UniqueSetBody) && isSoPDisjoint(
            acc1RedundancyMapBody,
            acc2RedundancyMapBody
          )
        ) {
          val usBody = SoP(
            Seq(Prod(Seq(acc1.uniqueHead)), Prod(Seq(acc2.uniqueHead)))
          )
          val us = Rule(lhs.uniqueHead, usBody)

          val rmBody = SoP(
            Seq(Prod(Seq(acc1.redundancyHead)), Prod(Seq(acc2.redundancyHead)))
          )
          val rm = Rule(lhs.redundancyHead, rmBody)

          val cBody = SoP(
            Seq(Prod(Seq(acc1.compressedHead)), Prod(Seq(acc2.compressedHead)))
          )
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        } else {
          val usBody = SoP(
            Seq(
              Prod(Seq(acc1.uniqueHead)),
              Prod(Seq(acc2.uniqueHead)),
              Prod(Seq(acc1.redundancyHead)),
              Prod(Seq(acc2.redundancyHead))
            )
          )
          val us = Rule(lhs.uniqueHead, usBody)

          val rm = Rule(lhs.redundancyHead, emptySoP())

          val cBody = SoP(
            Seq(
              Prod(Seq(acc1.compressedHead)),
              Prod(Seq(acc2.compressedHead)),
              Prod(
                Seq(
                  acc1.redundancyHead,
                  acc1.vars2RedundancyVars.compressedHead()
                )
              ),
              Prod(
                Seq(
                  acc2.redundancyHead,
                  acc2.vars2RedundancyVars.compressedHead()
                )
              )
            )
          )
          val c = Rule(lhs.compressedHead, cBody)

          (us, rm, c)
        }
      }
      case _ =>
        throw new Exception(
          "Input expressions to binary addition must be accesses with equal set of variables."
        )
    }
  }

  def infer(r: Rule, ctx: Seq[(Rule, Rule, Rule, Rule)]): (Rule, Rule, Rule) = {
    val head: Access = r.head
    val prods: Seq[Prod] = r.body.prods
    assert(prods.length <= 2)
    if (prods.length == 1) {
      val exps: Seq[Exp] = prods.head.exps
      if (isShift(head, exps)) {
        exps.head match {
          case access: Access => shift(head, access, exps.tail)
          case _ =>
            throw new IllegalArgumentException("Expected an Access expression")
        }
      } else if (exps.length == 1) {
        exps.head match {
          case access: Access => project(head, access)
          case _ => throw new AssertionError("Expected an Access expression")
        }
      } else if (exps.length == 2) {
        binMult(head, exps(0), exps(1))
      } else {
        // We made sure in the normalization step that all the accesses have the same name and their variable pairwise intersection is empty
        // So if sth ends up here, it must be a self outer product
        selfOuterProduct(head, exps)
      }
    } else if (prods.length == 2) {
      // We made sure in the normalization step that all the products that reach here have only 1 expression and they are all accesses
      assert(prods(0).exps.length == 1 && prods(1).exps.length == 1)
      binAdd(head, prods(0).exps.head, prods(1).exps.head, ctx)
    } else
      throw new Exception(
        "Only binary computations or self-outer product must be passed to infer function"
      )
  }

  @scala.annotation.tailrec
  def fixedPointOpt(
      us: Rule,
      rm: Rule,
      cc: Rule,
      symbols: Seq[Variable]
  ): (Rule, Rule, Rule) = {
    val (idempotentOptUS, idempotentOptRM, idempotentOptCC) =
      (setIdempotentOpt(us), setIdempotentOpt(rm), setIdempotentOpt(cc))
    val (removeEmptyProdOptUS, removeEmptyProdOptRM, removeEmptyProdOptCC) = (
      removeEmptyProductsOpt(idempotentOptUS),
      removeEmptyProductsOpt(idempotentOptRM),
      removeEmptyProductsOpt(idempotentOptCC)
    )
    val (
      replacedEqualVariablesOptUS,
      replacedEqualVariablesOptRM,
      replacedEqualVariablesOptCC
    ) = (
      replaceEqualVariables(removeEmptyProdOptUS, symbols),
      replaceEqualVariables(removeEmptyProdOptRM, symbols),
      replaceEqualVariables(removeEmptyProdOptCC, symbols)
    )
    if (
      isSoPEquals(replacedEqualVariablesOptUS.body, us.body) && isSoPEquals(
        replacedEqualVariablesOptRM.body,
        rm.body
      ) && isSoPEquals(replacedEqualVariablesOptCC.body, cc.body)
    )
      (
        replacedEqualVariablesOptUS,
        replacedEqualVariablesOptRM,
        replacedEqualVariablesOptCC
      )
    else
      fixedPointOpt(
        replacedEqualVariablesOptUS,
        replacedEqualVariablesOptRM,
        replacedEqualVariablesOptCC,
        symbols
      )
  }

  def compile(
      computation: Rule,
      inputs: Seq[(Rule, Rule, Rule, Rule)],
      symbols: Seq[Variable],
      outputs_names: Seq[String] = Seq()
  ): (Rule, Rule, Rule) = {
    val norm = normalize(computation)
    val us_rm_cc_tc_seq = norm.foldLeft(inputs)((ctx, r) => {
      val (us, rm, cc) = infer(r, ctx)
      ctx ++ Seq((us, rm, cc, r))
    })

    // Optimization
    val (denormUS, denormRM, denormCC, denormTC) =
      denormalize(computation.head, inputs ++ us_rm_cc_tc_seq, outputs_names)
    val (idempotentOptUS, idempotentOptRM, idempotentOptCC) = (
      setIdempotentOpt(denormUS),
      setIdempotentOpt(denormRM),
      setIdempotentOpt(denormCC)
    )
    val (removeEmptyProdOptUS, removeEmptyProdOptRM, removeEmptyProdOptCC) = (
      removeEmptyProductsOpt(idempotentOptUS),
      removeEmptyProductsOpt(idempotentOptRM),
      removeEmptyProductsOpt(idempotentOptCC)
    )
    val (
      replacedEqualVariablesOptUS,
      replacedEqualVariablesOptRM,
      replacedEqualVariablesOptCC
    ) = (
      replaceEqualVariables(removeEmptyProdOptUS, symbols),
      replaceEqualVariables(removeEmptyProdOptRM, symbols),
      replaceEqualVariables(removeEmptyProdOptCC, symbols)
    )
    val (fixedUS, fixedRM, fixedCC) = fixedPointOpt(
      replacedEqualVariablesOptUS,
      replacedEqualVariablesOptRM,
      replacedEqualVariablesOptCC,
      symbols
    )

    (fixedUS, fixedRM, fixedCC)
  }
}
