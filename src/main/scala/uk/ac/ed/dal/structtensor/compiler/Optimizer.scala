package uk.ac.ed.dal
package structtensor
package compiler

object Optimizer {
  import STURHelper._

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