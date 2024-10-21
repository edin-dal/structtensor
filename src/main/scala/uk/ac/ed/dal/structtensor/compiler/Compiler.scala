package uk.ac.ed.dal
package structtensor
package compiler

import utils._

import uk.ac.ed.dal.structtensor.parser.Parser.variableSeq

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

  def isSubSelfOuterProduct(vars: Seq[Seq[Variable]]): Boolean = {
    val all_intersects =
      vars.tail.foldLeft(vars.head)((acc, cur) => acc.intersect(cur))
    val vars_wo_intersects = vars.map(_.diff(all_intersects))
    val cond1 = isPairwiseIntersectEmpty(vars_wo_intersects)
    val all_intersect_indecies = vars.map(v =>
      v.zipWithIndex.collect {
        case (variable, index) if all_intersects.contains(variable) => index
      }
    )
    val cond2 = all_intersect_indecies.tail.forall(
      _.toSet == all_intersect_indecies.head.toSet
    )
    cond1 && cond2
  }

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
          else if (
            isPairwiseIntersectEmpty(
              sameNameList.map(e => e.vars)
            ) || isSubSelfOuterProduct(sameNameList.map(e => e.vars))
          )
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
        }.distinct
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
    val usBody = SoP(Seq(Prod(Seq(rhs.uniqueHead()) ++ exps)))
    val us = Rule(lhs.uniqueHead(), usBody)

    val redExps = exps.map {
      case Comparison(
            "=",
            Arithmetic("-", index1: Variable, index2),
            variable
          ) =>
        Comparison(
          "=",
          Arithmetic("-", index1.vars2RedundancyVars(), index2),
          variable.vars2RedundancyVars()
        )
      case exp => exp
    }
    val rmBody = SoP(Seq(Prod(Seq(rhs.redundancyHead()) ++ exps ++ redExps)))
    val rm = Rule(lhs.redundancyHead(), rmBody)

    val cBody = SoP(Seq(Prod(Seq(rhs.compressedHead()) ++ exps)))
    val c = Rule(lhs.compressedHead(), cBody)

    (us, rm, c)
  }

  def checkIfItsOptimalProject(
      lhs: Access,
      rhs: Access,
      ctx: Seq[(Rule, Rule, Rule, Rule)]
  ): Boolean = {
    val uncommon_vars = rhs.vars.diff(lhs.vars)
    val vecMult = vectorizeComparisonMultiplication(
      "=",
      uncommon_vars,
      uncommon_vars.redundancyVars
    )
    val denormRM = locallyDenormalizeAndReturnBody(rhs.redundancyHead(), ctx)
    denormRM.prods
      .forall(p => p.exps.intersect(vecMult).toSet == vecMult.toSet)
  }

  def project(
      lhs: Access,
      rhs: Access,
      ctx: Seq[(Rule, Rule, Rule, Rule)]
  ): (Rule, Rule, Rule) = {
    assert(lhs.vars.toSet.subsetOf(rhs.vars.toSet))
    if (
      lhs.vars.toSet == rhs.vars.toSet || checkIfItsOptimalProject(
        lhs,
        rhs,
        ctx
      )
    ) {
      val us = Rule(lhs.uniqueHead(), SoP(Seq(Prod(Seq(rhs.uniqueHead())))))
      val rm = Rule(lhs.redundancyHead(), SoP(Seq(Prod(Seq(rhs.redundancyHead())))))
      val c = Rule(lhs.compressedHead(), SoP(Seq(Prod(Seq(rhs.compressedHead())))))
      (us, rm, c)
    } else {
      val us = Rule(
        lhs.uniqueHead(),
        SoP(Seq(Prod(Seq(rhs.uniqueHead())), Prod(Seq(rhs.redundancyHead()))))
      )
      val rm = Rule(lhs.redundancyHead(), emptySoP())
      val c = Rule(
        lhs.compressedHead(),
        SoP(
          Seq(
            Prod(Seq(rhs.compressedHead())),
            Prod(
              Seq(rhs.redundancyHead(), rhs.vars2RedundancyVars().compressedHead())
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
          selfOuterProduct(lhs, Seq(acc1, acc2))
        } else if (name1 == name2 && isSubSelfOuterProduct(Seq(vars1, vars2))) {
          selfOuterProduct(lhs, Seq(acc1, acc2))
        } else if (
          lhs.vars.toSet == vars1.union(vars2).toSet && isIntersectEmpty(
            vars1,
            vars2
          )
        ) {
          val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead(), acc2.uniqueHead()))))
          val us = Rule(lhs.uniqueHead(), usBody)

          val rmBody = SoP(
            Seq(
              Prod(Seq(acc1.redundancyHead(), acc2.redundancyHead())),
              Prod(
                Seq(
                  acc1.uniqueHead(),
                  acc2.redundancyHead()
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars1,
                  vars1.redundancyVars
                )
              ),
              Prod(
                Seq(
                  acc1.redundancyHead(),
                  acc2.uniqueHead()
                ) ++ vectorizeComparisonMultiplication(
                  "=",
                  vars2,
                  vars2.redundancyVars
                )
              )
            )
          )
          val rm = Rule(lhs.redundancyHead(), rmBody)

          val cBody = SoP(
            Seq(Prod(Seq(acc1.compressedHead(), acc2.compressedHead())))
          )
          val c = Rule(lhs.compressedHead(), cBody)

          (us, rm, c)
        } else if (lhs.vars.toSet == vars1.union(vars2).toSet) {
          val usBody = SoP(
            Seq(
              Prod(Seq(acc1.uniqueHead(), acc2.uniqueHead())),
              Prod(Seq(acc1.uniqueHead(), acc2.redundancyHead())),
              Prod(Seq(acc1.redundancyHead(), acc2.uniqueHead()))
            )
          )
          val us = Rule(lhs.uniqueHead(), usBody)

          val rmBody = SoP(
            Seq(Prod(Seq(acc1.redundancyHead(), acc2.redundancyHead())))
          )
          val rm: Rule = Rule(lhs.redundancyHead(), rmBody)

          val cBody = SoP(
            Seq(
              Prod(Seq(acc1.compressedHead(), acc2.compressedHead())),
              Prod(
                Seq(
                  acc1.compressedHead(),
                  acc2.redundancyHead(),
                  acc2.vars2RedundancyVars().compressedHead()
                )
              ),
              Prod(
                Seq(
                  acc1.redundancyHead(),
                  acc2.compressedHead(),
                  acc1.vars2RedundancyVars().compressedHead()
                )
              )
            )
          )
          val c = Rule(lhs.compressedHead(), cBody)

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
        val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead(), e2))))
        val us = Rule(lhs.uniqueHead(), usBody)

        val rmBody = SoP(Seq(Prod(Seq(acc1.redundancyHead(), e2))))
        val rm = Rule(lhs.redundancyHead(), rmBody)

        val cBody = SoP(Seq(Prod(Seq(acc1.compressedHead(), e2))))
        val c = Rule(lhs.compressedHead(), cBody)

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
          val us = Rule(lhs.uniqueHead(), usBody)

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
          val rm = Rule(lhs.redundancyHead(), rmBody)

          val cBody = SoP(Seq(Prod(Seq(Comparison("=", indexEq, variable)))))
          val c = Rule(lhs.compressedHead(), cBody)

          (us, rm, c)
        } else {
          val usBody = SoP(Seq(Prod(Seq(e1, e2))))
          val us = Rule(lhs.uniqueHead(), usBody)

          val rmBody = emptySoP()
          val rm = Rule(lhs.redundancyHead(), rmBody)

          val cBody = SoP(Seq(Prod(Seq(e1, e2))))
          val c = Rule(lhs.compressedHead(), cBody)

          (us, rm, c)
        }
      }
      case _ =>
        throw new Exception(
          "Expression is either a comparison or an access. This error should never happen. Function: binMult"
        )
    }
  }

  def inject(
      comparisonSeq: Seq[Comparison],
      variableSeq: Seq[Variable],
      right_index: Int,
      variable: Variable
  ): Seq[Comparison] = {
    if (right_index == variableSeq.length) {
      // find the only variable that never appears on the lhs of a comparison.
      val lhs_varibles = comparisonSeq
        .collect { case Comparison(op, index, _) =>
          index match {
            case v: Variable => v
          }
        }
      // There must be only one variable that doesn't appear on the lhs and it's the maximum.
      val max_variable = variableSeq.diff(lhs_varibles)(0)

      comparisonSeq :+ Comparison("<=", max_variable, variable)
    } else {
      val (containsRightIndexVariable, rest) = comparisonSeq.partition {
        case Comparison(op, index, v) =>
          v == variableSeq(right_index)
      }
      // if it is not on the rhs of any comparsion, it's the smallest.
      containsRightIndexVariable.isEmpty match {
        case true =>
          Comparison("<", variable, variableSeq(right_index)) +: comparisonSeq
        case false => {
          // The length must be 1 since each of them only appear in one rhs (at most).
          val cur_comp = containsRightIndexVariable(0)
          rest ++ Seq(
            Comparison("<=", cur_comp.index, variable),
            Comparison("<", variable, cur_comp.variable)
          )
        }
      }
    }
  }

  def injectSingleVariableInProd(
      comparisonSeq: Seq[Comparison],
      varSeq: Seq[Variable],
      last_variable_index: Int,
      last: Access,
      kind: AccessType
  ): SoP = {
    val range = kind match {
      case RedundancyMap => varSeq.length
      case UniqueSet     => varSeq.length - 1
      case _ => throw new Exception(s"kind: $kind should not appear here!")
    }

    val prodSeq = (0 to range).toSeq.map(index =>
      Prod(inject(comparisonSeq, varSeq, index, last.vars(last_variable_index)))
    )

    SoP(prodSeq)
  }

  def injectVariablesInProd(
      prod: Prod,
      groupByIdxVars: Seq[Seq[Variable]],
      last: Access,
      kind: AccessType
  ): SoP = {
    val sopSeq = groupByIdxVars.zipWithIndex.map {
      case (varSeq, index) => {
        val filteredProd = prod.exps.collect {
          case c @ Comparison(op, i, v)
              if (varSeq.contains(v) || varSeq.contains(i)) =>
            c
        }
        injectSingleVariableInProd(filteredProd, varSeq, index, last, kind)
      }
    }

    val concatenatedSoP = concatSoP(sopSeq)
    concatenatedSoP
  }

  def injectVariables(
      usOrRmBody: SoP,
      all_vars_minus_last: Seq[Seq[Variable]],
      last: Access,
      kind: AccessType
  ): SoP = {
    val groupByIdxVars = all_vars_minus_last.transpose
    val sopSeq = usOrRmBody.prods.map(prod =>
      injectVariablesInProd(prod, groupByIdxVars, last, kind)
    )
    concatSoP(sopSeq)
  }

  def selfOuterProduct2(
      lhs: Access,
      accSeq: Seq[Access]
  ): (Rule, Rule, Rule) = {
    if (accSeq.length == 2) {
      val comparisonSeq =
        vectorizeComparisonMultiplication("<=", accSeq(0).vars, accSeq(1).vars)
      val us = Rule(
        lhs.uniqueHead(),
        SoP(Seq(Prod(comparisonSeq)))
      )
      val rm = Rule(
        lhs.redundancyHead(),
        SoP(
          Seq(
            Prod(
              vectorizeComparisonMultiplication(
                "<",
                accSeq(1).vars,
                accSeq(0).vars
              )
            )
          )
        )
      )
      val c = Rule(
        lhs.compressedHead(),
        SoP(Seq(Prod(comparisonSeq)))
      )
      (us, rm, c)
    } else {
      val init = accSeq.init
      val (us_minus_last, rm_minus_last, c_minus_last) =
        selfOuterProduct2(lhs, init)
      val last = accSeq.last

      val comparisonSeq =
        vectorizeComparisonMultiplication("<=", init.last.vars, last.vars)

      val usBody = SoPTimesSoP(
        us_minus_last.body,
        SoP(Seq(Prod(comparisonSeq)))
      )
      val us = Rule(lhs.uniqueHead(), usBody)

      val all_vars_minus_last = init.map(_.vars)
      val rmBody1 =
        injectVariables(
          us_minus_last.body,
          all_vars_minus_last,
          last,
          UniqueSet
        )
      val rmBody2 =
        injectVariables(
          rm_minus_last.body,
          all_vars_minus_last,
          last,
          RedundancyMap
        )
      val rm = Rule(lhs.redundancyHead(), concatSoP(Seq(rmBody1, rmBody2)))

      val cBody = SoPTimesSoP(
        c_minus_last.body,
        SoP(Seq(Prod(comparisonSeq)))
      )
      val c = Rule(lhs.compressedHead(), cBody)

      (us, rm, c)
    }
  }

  def findAllVariables(prod: Prod): Seq[Variable] = {
    val comparisonSeq = prod.exps.collect {
      case c: Comparison => c
      case _ => throw new Exception("all expressions here must be comparsion")
    }
    comparisonSeq
      .collect {
        case c @ Comparison(op, i, v) if (op == "<" || op == "<=") =>
          i match {
            case variable: Variable => Seq(variable, v)
          }
        case c2 @ Comparison(op, _, _) =>
          throw new Exception(s"op cannot be $op. It must be < or <=.")
      }
      .flatten
      .distinct
  }

  def findMinVariable(prod: Prod): Variable = {
    val allVars = findAllVariables(prod)
    val comparisonSeq = prod.exps.collect {
      case c: Comparison => c
      case _ => throw new Exception("all expressions here must be comparsion")
    }
    val rhsVars = comparisonSeq.collect {
      case c @ Comparison(op, _, v) if (op == "<" || op == "<=") => v
      case c2 @ Comparison(op, _, _) =>
        throw new Exception(s"op cannot be $op. It must be < or <=.")
    }
    // It must be only one element based on construction.
    val result = allVars.diff(rhsVars)
    assert(result.length == 1)
    result(0)
  }

  def findMaxVariable(prod: Prod): Variable = {
    val comparisonSeq = prod.exps.collect {
      case c: Comparison => c
      case _ => throw new Exception("all expressions here must be comparsion")
    }
    val lhsVars = comparisonSeq.collect {
      case c @ Comparison(op, i, _) if (op == "<" || op == "<=") =>
        i match {
          case v: Variable => v
        }
      case c2 @ Comparison(op, _, _) =>
        throw new Exception(s"op cannot be $op. It must be < or <=.")
    }

    val allVars = findAllVariables(prod)
    // It must be only one element based on construction.
    val result = allVars.diff(lhsVars)
    assert(result.length == 1)
    result(0)
  }

  def injectInFilteredRM(
      rmBody: SoP,
      usBody: Prod
  ): SoP = {
    if (usBody.exps.length == 1) {
      val (minUSVar, maxUSVar) = usBody.exps(0) match {
        case Comparison(op, index, variable) =>
          index match {
            case v: Variable => (v, variable)
          }
      }
      SoP(rmBody.prods.map(prod => {
        val (prodMinVar, prodMaxVar) = prod.exps(0) match {
          case Comparison(op, index, variable) =>
            index match {
              case v: Variable => (v, variable)
            }
        }
        Prod(
          Seq(
            Comparison("=", prodMinVar, minUSVar.redundancyVars),
            Comparison("=", prodMaxVar, maxUSVar.redundancyVars),
            prod.exps(0)
          )
        )
      }))
    } else {
      val minUSVar = findMinVariable(usBody)
      val (minProd, restRM) = rmBody.prods
        .map(prod => {
          val prodMinVar = findMinVariable(prod)
          val mapping = Comparison("=", prodMinVar, minUSVar.redundancyVars)
          val (minimum_comp, rest) = prod.exps.partition {
            case Comparison(op, i, _) => i == prodMinVar
          }
          (Prod(mapping +: minimum_comp), Prod(rest))
        })
        .unzip

      val newUSBody = Prod(usBody.exps.filter { case Comparison(op, i, _) =>
        i != minUSVar
      })

      val injectRest =
        injectInFilteredRM(
          SoP(restRM),
          newUSBody
        )

      SoP(injectRest.prods.zip(minProd).map { case (prod, mProd) =>
        Prod(prod.exps ++ mProd.exps)
      })
    }
  }

  def injectRM(
      rmBody: SoP,
      usBody: Prod,
      groupByIdxVars: Seq[Seq[Variable]]
  ): SoP = {
    // In self-outer product and before inlining, body of the unique set must be just a single product.
    val sopSeq =
      groupByIdxVars.map(varSeq => injectInFilteredRM(rmBody, usBody))

    SoP(sopSeq.tail.foldLeft(sopSeq(0).prods)((acc, cur) => {
      cur.prods.zip(acc).map { case (p1, p2) => prodTimesProd(p1, p2) }
    }))
  }

  def selfOuterProduct(lhs: Access, accSeq: Seq[Access]): (Rule, Rule, Rule) = {
    if (lhs.vars.isEmpty) {
      val us =
        Rule(lhs.uniqueHead(), SoP(Seq(Prod(accSeq.map(_.uniqueHead())))))
      val rm =
        Rule(
          lhs.redundancyHead(),
          SoP(Seq(Prod(accSeq.map(_.redundancyHead()))))
        )
      val c =
        Rule(
          lhs.compressedHead(),
          SoP(Seq(Prod(accSeq.map(_.compressedHead()))))
        )
      (us, rm, c)
    } else if (isPairwiseIntersectEmpty(accSeq.map(acc => acc.vars))) { // we made sure in the normalization step that all the accesses have the same name and their variable pairwise intersection is empty
      val (us2, rm2, c2) = selfOuterProduct2(lhs, accSeq)
      val allUniqueHeads = accSeq.map(_.uniqueHead())

      val usBody = prodTimesSoP(Prod(allUniqueHeads), us2.body)
      val us = Rule(lhs.uniqueHead(), usBody)

      val vectorizedMultVarEqualsRedundancyVarSeq = accSeq.map(acc =>
        vectorizeComparisonMultiplication(
          "=",
          acc.vars,
          acc.vars.redundancyVars
        )
      )
      val bodyRMProdSeq1 = (0 to accSeq.length - 1).flatMap(i => {
        (0 to accSeq.length - 1)
          .combinations(i)
          .map(indexList => {
            Prod(
              (accSeq.zipWithIndex)
                .collect {
                  case (acc, ind) if indexList.contains(ind) =>
                    vectorizedMultVarEqualsRedundancyVarSeq(
                      ind
                    ) :+ acc.uniqueHead()
                  case (acc, ind) if !indexList.contains(ind) =>
                    Seq(acc.redundancyHead())
                }
                .flatten
                .toSeq
            )
          })
      })

      val injectedMapRM =
        injectRM(rm2.body, us2.body.prods.head, accSeq.map(_.vars).transpose)
      val uniqueHeadIncludedInRM =
        prodTimesSoP(Prod(allUniqueHeads), injectedMapRM)

      val rmBody = concatSoP(Seq(SoP(bodyRMProdSeq1), uniqueHeadIncludedInRM))
      val rm = Rule(lhs.redundancyHead(), rmBody)

      val cBody = prodTimesSoP(Prod(accSeq.map(_.compressedHead())), c2.body)
      val c = Rule(lhs.compressedHead(), cBody)

      (us, rm, c)
    } else { // We assured that if the pairwise intersection is not empty, then the isSubSelfOuter function has returned true to be here.
      val vars = accSeq.map(_.vars)
      val all_intersect =
        vars.tail.foldLeft(vars.head)((acc, cur) => acc.intersect(cur))

      val (usSoPSeq, rmSoPSeq, cSoPSeq) = (0 to accSeq.length - 1)
        .flatMap(i => {
          (0 to accSeq.length - 1)
            .combinations(i)
            .map(indexList => {
              val prodAndVectorizedMult = Prod(
                accSeq.zipWithIndex
                  .collect {
                    case (acc, ind) if !indexList.contains(ind) =>
                      vectorizeComparisonMultiplication(
                        "=",
                        all_intersect,
                        all_intersect.redundancyVars
                      ) :+
                        acc.uniqueHead()
                    case (acc, ind) if indexList.contains(ind) =>
                      Seq(acc.redundancyHead())
                  }
                  .flatten
                  .toSeq
              )

              val (prodExps, vecMult) = prodAndVectorizedMult.exps.partition {
                case _: Access => true
                case _         => false
              }
              val prod = Prod(prodExps)

              val (uniqueAccesses, rest) = prod.exps.partition {
                case _ @Access(_, _, UniqueSet) => true
                case _                          => false
              }

              if (uniqueAccesses.length == 1) {
                val us = SoP(Seq(prod))
                val rm = emptySoP()
                val c11 = uniqueAccesses.collect { case u: Access =>
                  Access(
                    u.name.substring(0, u.name.length() - 2) + "C",
                    u.vars,
                    CompressedTensor
                  )
                }
                val c12 = rest.collect { case r: Access =>
                  Access(
                    r.name.substring(0, r.name.length() - 2) + "C",
                    r.vars.drop(r.vars.length / 2),
                    CompressedTensor
                  )
                }
                val c = SoP(Seq(Prod(c11 ++ c12 ++ rest)))

                (us, rm, c)
              } else {
                val all_unique_accesses_minus_intersect =
                  uniqueAccesses.collect {
                    case _ @Access(name, variables, kind) =>
                      Access(name, variables.diff(all_intersect), kind)
                  }

                val (us2, rm2, c2) =
                  selfOuterProduct2(lhs, all_unique_accesses_minus_intersect)

                val us = prodTimesSoP(prod, us2.body)
                val injectedMapRM =
                  injectRM(
                    rm2.body,
                    us2.body.prods.head,
                    all_unique_accesses_minus_intersect.map(_.vars).transpose
                  )
                val rm =
                  prodTimesSoP(prodAndVectorizedMult, injectedMapRM)

                val c11 = uniqueAccesses.collect { case u: Access =>
                  Access(
                    u.name.substring(0, u.name.length() - 2) + "C",
                    u.vars,
                    CompressedTensor
                  )
                }
                val c12 = rest.collect { case r: Access =>
                  Access(
                    r.name.substring(0, r.name.length() - 2) + "C",
                    r.vars.drop(r.vars.length / 2),
                    CompressedTensor
                  )
                }
                val c = prodTimesSoP(Prod(c11 ++ c12 ++ rest), c2.body)

                (us, rm, c)
              }
            })
        })
        .unzip3

      val us = Rule(lhs.uniqueHead(), concatSoP(usSoPSeq))
      val rm = Rule(
        lhs.redundancyHead(),
        concatSoP(rmSoPSeq :+ SoP(Seq(Prod(accSeq.map(_.redundancyHead())))))
      )
      val c = Rule(lhs.compressedHead(), concatSoP(cSoPSeq))

      (us, rm, c)
    }
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
          locallyDenormalizeAndReturnBody(acc1.uniqueHead(), ctx)
        val acc2UniqueSetBody =
          locallyDenormalizeAndReturnBody(acc2.uniqueHead(), ctx)
        val acc1RedundancyMapBody =
          locallyDenormalizeAndReturnBody(acc1.redundancyHead(), ctx)
        val acc2RedundancyMapBody =
          locallyDenormalizeAndReturnBody(acc2.redundancyHead(), ctx)

        if (
          isSoPEquals(acc1UniqueSetBody, acc2UniqueSetBody) && isSoPEquals(
            acc1RedundancyMapBody,
            acc2RedundancyMapBody
          )
        ) {
          val usBody = SoP(Seq(Prod(Seq(acc1.uniqueHead()))))
          val us = Rule(lhs.uniqueHead(), usBody)

          val rmBody = SoP(Seq(Prod(Seq(acc1.redundancyHead()))))
          val rm = Rule(lhs.redundancyHead(), rmBody)

          val cBody = SoP(
            Seq(Prod(Seq(acc1.compressedHead())), Prod(Seq(acc2.compressedHead())))
          )
          val c = Rule(lhs.compressedHead(), cBody)

          (us, rm, c)
        } else if (
          isSoPDisjoint(acc1UniqueSetBody, acc2UniqueSetBody) && isSoPDisjoint(
            acc1RedundancyMapBody,
            acc2RedundancyMapBody
          )
        ) {
          val usBody = SoP(
            Seq(Prod(Seq(acc1.uniqueHead())), Prod(Seq(acc2.uniqueHead())))
          )
          val us = Rule(lhs.uniqueHead(), usBody)

          val rmBody = SoP(
            Seq(Prod(Seq(acc1.redundancyHead())), Prod(Seq(acc2.redundancyHead())))
          )
          val rm = Rule(lhs.redundancyHead(), rmBody)

          val cBody = SoP(
            Seq(Prod(Seq(acc1.compressedHead())), Prod(Seq(acc2.compressedHead())))
          )
          val c = Rule(lhs.compressedHead(), cBody)

          (us, rm, c)
        } else {
          val usBody = SoP(
            Seq(
              Prod(Seq(acc1.uniqueHead())),
              Prod(Seq(acc2.uniqueHead())),
              Prod(Seq(acc1.redundancyHead())),
              Prod(Seq(acc2.redundancyHead()))
            )
          )
          val us = Rule(lhs.uniqueHead(), usBody)

          val rm = Rule(lhs.redundancyHead(), emptySoP())

          val cBody = SoP(
            Seq(
              Prod(Seq(acc1.compressedHead())),
              Prod(Seq(acc2.compressedHead())),
              Prod(
                Seq(
                  acc1.redundancyHead(),
                  acc1.vars2RedundancyVars().compressedHead()
                )
              ),
              Prod(
                Seq(
                  acc2.redundancyHead(),
                  acc2.vars2RedundancyVars().compressedHead()
                )
              )
            )
          )
          val c = Rule(lhs.compressedHead(), cBody)

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
          case access: Access => project(head, access, ctx)
          case _ => throw new AssertionError("Expected an Access expression")
        }
      } else if (exps.length == 2) {
        binMult(head, exps(0), exps(1))
      } else {
        // We made sure in the normalization step that all the accesses have the same name and their variable pairwise intersection is empty
        // So if sth ends up here, it must be a self outer product
        selfOuterProduct(
          head,
          exps.collect {
            case acc: Access => acc
            case _ =>
              throw new IllegalArgumentException(
                "All elements in the sequence must be of type Access."
              )
          }
        )
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
      symbols: Seq[Variable],
      iters: Seq[Variable]
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
      replaceEqualVariables(removeEmptyProdOptCC, symbols, iters)
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
        symbols,
        iters
      )
  }

  def compile(
      computation: Rule,
      inputs: Seq[(Rule, Rule, Rule, Rule)],
      symbols: Seq[Variable],
      outputs_names: Seq[String] = Seq(),
      iters: Seq[Variable] = Seq()
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
      replaceEqualVariables(removeEmptyProdOptCC, symbols, iters)
    )
    val (fixedUS, fixedRM, fixedCC) = fixedPointOpt(
      replacedEqualVariablesOptUS,
      replacedEqualVariablesOptRM,
      replacedEqualVariablesOptCC,
      symbols,
      iters
    )

    (fixedUS, fixedRM, fixedCC)
  }
}
