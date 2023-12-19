package uk.ac.ed.dal
package structtensor
package compiler

object Optimizer {
  import STURHelper._

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
    def filterFN(exp: Exp): Boolean = exp match {
      case acc @ Access(_, _, _) => denormMap.contains(acc)
      case _ => false
    }

    body.prods.foldLeft(emptySoP())((acc1, prod) => {
      val (epxsInMap, epxsNotInMap): (Seq[Exp], Seq[Exp]) = prod.exps.partition(filterFN)
      val denormalizedSoPSeq = epxsInMap.map(exp => denormMap(exp.asInstanceOf[Access]))
      val singleAllExpSoP = SoP(Seq(Prod(epxsNotInMap)))
      val allExpSoP = if (epxsNotInMap.length == 0) multSoP(denormalizedSoPSeq) else if (epxsInMap.length == 0) singleAllExpSoP else multSoP(singleAllExpSoP +: denormalizedSoPSeq) 
      concatSoP(Seq(acc1, allExpSoP))
    })
  }

  def denormalize(head: Access, ctx: Seq[(Rule, Rule, Rule, Rule)], idempotent: Boolean = true): (Rule, Rule, Rule, Rule) = {
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
    val intersectOpt = setIdempotentIntersectionOpt(r)
    intersectOpt
  }
}