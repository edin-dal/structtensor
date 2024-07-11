package uk.ac.ed.dal
package structtensor
package compiler

import utils._

object Optimizer {
  import Utils._

  def denormalizeSingle(
      body: SoP,
      denormMap: Map[Access, SoP],
      kind: AccessType
  ): SoP = {
    def extractAccessesInDenormalizationMapByName(exp: Exp): Boolean =
      exp match {
        case acc: Access => denormMap.containsByName(acc.name)
        case _           => false
      }

    body.prods.foldLeft(emptySoP())((acc1, prod) => {
      val (epxsInMap, expsNotInMap): (Seq[Exp], Seq[Exp]) =
        prod.exps.partition(extractAccessesInDenormalizationMapByName)
      val denormalizedSoPSeq = epxsInMap.map(exp =>
        exp match {
          case acc: Access => denormMap.getByAccessNameAndReplaceVars(acc).get
          case _           => throw new Exception("Unknown expression")
        }
      )
      val (processedExpNotInMap, multEmptySetFlag) = kind match {
        case UniqueSet | RedundancyMap =>
          expsNotInMap.exists(e =>
            e match {
              case Access(_, v, k) if k == RedundancyMap => v.isEmpty
              case _                                     => false
            }
          ) match {
            case true => (Seq(), true)
            case false =>
              (
                expsNotInMap.filter(exp =>
                  exp match {
                    case acc @ Access(_, v, _) if v.isEmpty => false
                    case _                                  => true
                  }
                ),
                false
              )
          }
        case CompressedTensor =>
          expsNotInMap.exists(e =>
            e match {
              case Access(_, v, k) if k == RedundancyMap => v.isEmpty
              case _                                     => false
            }
          ) match {
            case true => (Seq(), true)
            case false =>
              (
                expsNotInMap.map(exp =>
                  exp match {
                    case acc @ Access(n, v, k)
                        if v.isEmpty && n.endsWith("_C") =>
                      Access(n.substring(0, n.length() - 2), v, k)
                    case comp: Comparison => comp
                    case _                => exp
                  }
                ),
                false
              )
          }

        case _ => (expsNotInMap, false)
      }
      val singleAllExpSoP = SoP(Seq(Prod(processedExpNotInMap)))
      val allExpSoP =
        if (multEmptySetFlag) emptySoP()
        else if (processedExpNotInMap.length == 0) multSoP(denormalizedSoPSeq)
        else if (epxsInMap.length == 0) singleAllExpSoP
        else multSoP(singleAllExpSoP +: denormalizedSoPSeq)
      concatSoP(Seq(acc1, allExpSoP))
    })
  }

  def denormalize(
      head: Access,
      ctx: Seq[(Rule, Rule, Rule, Rule)]
  ): (Rule, Rule, Rule, Rule) = {
    val denormMap = ctx.foldLeft(Map[Access, SoP]())((acc, cur) => {
      val (us, rm, cc, tc) = cur
      val (usBody, rmBody, ccBody, tcBody) = (
        denormalizeSingle(us.body, acc, UniqueSet),
        denormalizeSingle(rm.body, acc, RedundancyMap),
        denormalizeSingle(cc.body, acc, CompressedTensor),
        denormalizeSingle(tc.body, acc, Tensor)
      )
      acc + (us.head -> usBody) + (rm.head -> rmBody) + (cc.head -> ccBody) + (tc.head -> tcBody)
    })

    val denormUS = Rule(head, denormMap(head.uniqueHead))
    val denormRM = Rule(
      Access(head.name, head.vars.redundancyVarsInplace, head.kind),
      denormMap(head.redundancyHead)
    )
    val denormCC = Rule(head, denormMap(head.compressedHead))
    val denormTC = Rule(head, denormMap(head))

    (denormUS, denormRM, denormCC, denormTC)
  }

  def extractBooleanDomainComputation(exp: Exp): Boolean = {
    exp match {
      case Access(_, _, kind) if (kind == UniqueSet || kind == RedundancyMap) =>
        true
      case Comparison(_, _, _) => true
      case _                   => false
    }
  }

  def singleProdIdempotence(prod: Prod): Prod = {
    val p = Prod(
      prod.exps.zipWithIndex
        .filterNot { case (e1, i) =>
          prod.exps
            .slice(i + 1, prod.exps.length)
            .exists(e2 =>
              e1 != e2 && ((e1, e2) match {
                case (c1: Comparison, c2: Comparison) =>
                  isComparisonEquivalent(c1, c2)
                case _ => false
              })
            )
        }
        .map(_._1)
    )
    val (booleanDomain, realDomain) =
      p.exps.partition(extractBooleanDomainComputation)
    Prod(booleanDomain.distinct ++ realDomain)
  }

  def setIdempotentIntersectionOpt(r: Rule): Rule =
    Rule(r.head, SoP(r.body.prods.map(singleProdIdempotence)))

  def isComparisonEquivalent(c1: Comparison, c2: Comparison): Boolean = {
    (c1, c2) match {
      case (Comparison(op1, i1, v1), Comparison(op2, i2, v2)) => {
        if (op1 == op2 && i1 == i2 && v1 == v2) true
        else if (op1 == "<" && op2 == ">" && i1 == v2 && i2 == v1) true
        else if (op1 == ">" && op2 == "<" && i1 == v2 && i2 == v1) true
        else if (op1 == "<=" && op2 == ">=" && i1 == v2 && i2 == v1) true
        else if (op1 == ">=" && op2 == "<=" && i1 == v2 && i2 == v1) true
        else if (op1 == "=" && op2 == "=" && i1 == v2 && i2 == v1) true
        else false
      }
      case _ => false
    }
  }

  def setIdempotentOpt(r: Rule): Rule = {
    val areAllComparison = r.body.prods.forall(p =>
      p.exps.forall(e =>
        e match {
          case _: Comparison => true
          case _             => false
        }
      )
    )

    areAllComparison match {
      case true => {
        val prodSetOfExpSet = r.body.prods
          .map(p => singleProdIdempotence(p).exps.distinct)
          .distinct
        Rule(r.head, SoP(prodSetOfExpSet.map(p => Prod(p.toSeq)).toSeq))
      }
      case false => setIdempotentIntersectionOpt(r)
    }
  }

  def opEmpty(op: String): Seq[String] = op match {
    case "<"  => Seq(">", ">=", "=")
    case "<=" => Seq(">")
    case ">=" => Seq("<")
    case ">"  => Seq("<", "<=", "=")
    case "="  => Seq("<", ">")
    case _    => Seq()
  }

  def opComplement(op: String): String = op match {
    case "="  => "="
    case "<"  => ">"
    case "<=" => ">="
    case ">"  => "<"
    case ">=" => "<="
    case _    => "???"
  }

  def isBinaryProductWithConstantBoundsEmpty(
      op1: String,
      op2: String,
      v1: Double,
      v2: Double
  ): Boolean = (op1, op2) match {
    case ("<", "=") | ("<", ">=") | ("<", ">") | ("<=", ">") | ("=", ">") =>
      v2 <= v1
    case ("<=", "=") | ("<=", ">=") | ("=", ">=") => v2 < v1
    case ("=", "<") | (">=", "<") | (">", "<") | (">", "<=") | (">", "=") =>
      v2 >= v1
    case ("=", "<=") | (">=", "<=") | (">=", "=") => v2 > v1
    case ("=", "=")                               => v1 != v2
    case _                                        => false
  }

  def isBinaryProductEmpty(e1: Exp, e2: Exp): Boolean = {
    if (e1 == e2) false
    else {
      (e1, e2) match {
        case (
              c1 @ Comparison(op1, index1, variable1),
              c2 @ Comparison(op2, index2, variable2)
            ) => {
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
            case (ConstantInt(v1), ConstantInt(v2)) if variable1 == variable2 =>
              isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case (ConstantInt(v1), ConstantDouble(v2))
                if variable1 == variable2 =>
              isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case (ConstantDouble(v1), ConstantInt(v2))
                if variable1 == variable2 =>
              isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
            case (ConstantDouble(v1), ConstantDouble(v2))
                if variable1 == variable2 =>
              isBinaryProductWithConstantBoundsEmpty(op1, op2, v1, v2)
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

  def isExpEmpty(exp: Exp): Boolean = exp match {
    case Comparison(op, index, variable) =>
      index match {
        case v: Variable => {
          if (v == variable) {
            op match {
              case "=" | "<=" | ">=" => false
              case "<" | ">" | "!="  => true
              case _                 => false
            }
          } else false
        }
        case Arithmetic(opArith, i1, i2) => {
          op match {
            case "=" => {
              opArith match {
                case "+" | "-" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v != 0
                    case ConstantDouble(v) => v != 0
                    case _                 => false
                  }
                  else if (i2 == variable) i1 match {
                    case ConstantInt(v)    => v != 0
                    case ConstantDouble(v) => v != 0
                    case _                 => false
                  }
                  else false
                } // We can't have something similar for * and / (e.g., v = 5 * v holds true if v == 0)
                case _ => false
              }
            }
            case "<" => {
              opArith match {
                case "+" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v >= 0
                    case ConstantDouble(v) => v >= 0
                    case _                 => false
                  }
                  else if (i2 == variable) i1 match {
                    case ConstantInt(v)    => v >= 0
                    case ConstantDouble(v) => v >= 0
                    case _                 => false
                  }
                  else false
                }
                case "-" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v <= 0
                    case ConstantDouble(v) => v <= 0
                    case _                 => false
                  }
                  else false
                }
                case _ => false
              }
            }
            case "<=" => {
              opArith match {
                case "+" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v > 0
                    case ConstantDouble(v) => v > 0
                    case _                 => false
                  }
                  else if (i2 == variable) i1 match {
                    case ConstantInt(v)    => v > 0
                    case ConstantDouble(v) => v > 0
                    case _                 => false
                  }
                  else false
                }
                case "-" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v < 0
                    case ConstantDouble(v) => v < 0
                    case _                 => false
                  }
                  else false
                }
                case _ => false
              }
            }
            case ">" => {
              opArith match {
                case "+" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v <= 0
                    case ConstantDouble(v) => v <= 0
                    case _                 => false
                  }
                  else if (i2 == variable) i1 match {
                    case ConstantInt(v)    => v <= 0
                    case ConstantDouble(v) => v <= 0
                    case _                 => false
                  }
                  else false
                }
                case "-" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v >= 0
                    case ConstantDouble(v) => v >= 0
                    case _                 => false
                  }
                  else false
                }
                case _ => false
              }
            }
            case ">=" => {
              opArith match {
                case "+" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v < 0
                    case ConstantDouble(v) => v < 0
                    case _                 => false
                  }
                  else if (i2 == variable) i1 match {
                    case ConstantInt(v)    => v < 0
                    case ConstantDouble(v) => v < 0
                    case _                 => false
                  }
                  else false
                }
                case "-" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v > 0
                    case ConstantDouble(v) => v > 0
                    case _                 => false
                  }
                  else false
                }
                case _ => false
              }
            }
            case "!=" => {
              opArith match {
                case "+" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v == 0
                    case ConstantDouble(v) => v == 0
                    case _                 => false
                  }
                  else if (i2 == variable) i1 match {
                    case ConstantInt(v)    => v == 0
                    case ConstantDouble(v) => v == 0
                    case _                 => false
                  }
                  else false
                }
                case "-" => {
                  if (i1 == variable) i2 match {
                    case ConstantInt(v)    => v == 0
                    case ConstantDouble(v) => v == 0
                    case _                 => false
                  }
                  else false
                }
                case _ => false
              }
            }
            case _ => false
          }
        }
        case _ => false
      }
    case _ => false
  }

  def isProductEmpty(prod: Prod): Boolean = prod.exps.combinations(2).exists {
    case Seq(e1, e2) => isBinaryProductEmpty(e1, e2)
  }

  def isExpOrProductEmpty(prod: Prod): Boolean =
    prod.exps.exists(isExpEmpty) || isProductEmpty(prod)

  def removeEmptyProductsOpt(r: Rule): Rule =
    Rule(r.head, SoP(r.body.prods.filterNot(isExpOrProductEmpty)))

  def getEqualVariables(rule: Rule): Seq[Seq[Seq[Variable]]] = {
    val binaryEqualSets = rule.body.prods.map(p => {
      p.exps.flatMap {
        case Comparison("=", i1, i2) => {
          (i1, i2) match {
            case (v1: Variable, v2: Variable) => Seq(Seq(v1, v2))
            case _                            => Seq()
          }
        }
        case _ => Seq()
      }
    })

    // Merge equal binary sets:
    val mergedSets = binaryEqualSets.map(setOfSets =>
      setOfSets.foldLeft(Seq[Seq[Variable]]()) { (merged, current) =>
        val (toMerge, rest) = merged.partition(_.intersect(current).nonEmpty)
        val mergedSet = (toMerge.flatten ++ current).distinct
        mergedSet +: rest
      }
    )

    mergedSets
  }

  def replaceEqualVariableInIndex(
      index: Index,
      equalVariablesSet: Seq[Seq[Variable]]
  ): Index = index match {
    case v: Variable => {
      val equalSet = equalVariablesSet.find(_.contains(v))
      equalSet match {
        case Some(set) => set.head
        case None      => v
      }
    }
    case a @ Arithmetic(op, i1, i2) =>
      Arithmetic(
        op,
        replaceEqualVariableInIndex(i1, equalVariablesSet),
        replaceEqualVariableInIndex(i2, equalVariablesSet)
      )
    case _ => index
  }

  def replaceEqualVariablesInExp(
      exp: Exp,
      equalVariablesSet: Seq[Seq[Variable]]
  ): Seq[Exp] = exp match {
    case Access(n, v, k) =>
      Seq(
        Access(
          n,
          v.map(v2 => {
            val equalSet = equalVariablesSet.find(_.contains(v2))
            equalSet match {
              case Some(set) => set.head
              case None      => v2
            }
          }),
          k
        )
      )
    case c @ Comparison(op, i, v) =>
      op match {
        // In case it is equality and one of the variables is head of the set,
        // don't replace it since the variables in head are not being replace to keep the number the rules one
        case "=" =>
          (i, v) match {
            case (v1: Variable, v2: Variable) => {
              val equalSet1 = equalVariablesSet.find(_.contains(v1))
              val equalSet2 = equalVariablesSet.find(_.contains(v2))
              (equalSet1, equalSet2) match {
                case (Some(set1), _) if set1.head == v1 => Seq(c)
                case (_, Some(set2)) if set2.head == v2 => Seq(c)
                case (Some(set1), None) => Seq(Comparison("=", set1.head, v2))
                case (None, Some(set2)) => Seq(Comparison("=", v1, set2.head))
                case (Some(set1), Some(set2)) if set1.head == set2.head =>
                  Seq(
                    Comparison("=", set1.head, v2),
                    Comparison("=", v1, set2.head)
                  )
                case (Some(set1), Some(set2)) =>
                  Seq(Comparison("=", set1.head, set2.head))
                case (None, None) => Seq(c)
              }
            }
            case _ =>
              Seq(
                Comparison(
                  op,
                  replaceEqualVariableInIndex(i, equalVariablesSet), {
                    val equalSet = equalVariablesSet.find(_.contains(v))
                    equalSet match {
                      case Some(set) => set.head
                      case None      => v
                    }
                  }
                )
              )
          }
        case _ =>
          Seq(
            Comparison(
              op,
              replaceEqualVariableInIndex(i, equalVariablesSet), {
                val equalSet = equalVariablesSet.find(_.contains(v))
                equalSet match {
                  case Some(set) => set.head
                  case None      => v
                }
              }
            )
          )
      }
    case _ => throw new Exception("Unknown expression")
  }

  def replaceEqualVariables(rule: Rule, symbols: Seq[Variable]): Rule = {
    val equalVariablesSet = getEqualVariables(rule)
    val newBody = SoP(rule.body.prods.zip(equalVariablesSet).map {
      case (p, eSet) => {
        Prod(p.exps.map(exp => replaceEqualVariablesInExp(exp, eSet)).flatten)
      }
    })

    val all_variable_names =
      (symbols.map(_.name) ++ boundVariables(Seq(rule))).distinct
    val finalBody = SoP(newBody.prods.map(p => {
      Prod(
        p.exps.filter(e =>
          getVariables(e).map(_.name).forall(all_variable_names.contains(_))
        )
      )
    }))

    if (rule.head.vars.isEmpty) Rule(rule.head, newBody)
    else Rule(rule.head, finalBody)
  }
}
