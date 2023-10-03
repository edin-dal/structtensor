package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object E2E_PRK {

  def e2eConstructor(n: Int, mode: Int = 0) = {
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val cont = if (mode == 0) "cont" else "other_cont"
    val head: Access = Access(s"${cont}_degree$n", xSeq, Tensor)
    val vars: Seq[Access] = xSeq.map(x => Access(s"${cont}_sum1", Seq(x), Tensor))
    val prods: Prod = Prod(vars)
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)
    val dimInfo: Seq[DimInfo] = vars.map(v => DimInfo(v, Seq("CONT_SZ".toVar)))

    val varHeadUS: Seq[Access] = xSeq.map(x => Access(s"${cont}_sum1".uniqueName, Seq(x), UniqueSet)) 
    val varBodyUS: Seq[SoP] = dimInfo.map(dim => dim.toSoP)
    val varUS: Seq[Rule] = (varHeadUS zip varBodyUS).map{case (head, body) => Rule(head, body)}

    val varHeadRM: Seq[Access] = xSeq.map(x => Access(s"${cont}_sum1".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
    val varBodyRM: Seq[SoP] = dimInfo.map(dim => emptySoP())
    val varRM: Seq[Rule] = (varHeadRM zip varBodyRM).map{case (head, body) => Rule(head, body)}

    val uniqueSets: Map[Exp, Rule] = (vars zip varUS).map{case (v, r) => (v -> r)}.toMap
    val redundancyMap: Map[Exp, Rule] = (vars zip varRM).map{case (v, r) => (v -> r)}.toMap

    val compressionMap: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp))))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap, compressionMap)

    val us: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val c: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), compressionMap))((v1, v2) => v1)
    val di: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, di, us, rm, c)
  }

  def e2eAddition(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule], mode: Int = 0) = {
    val name = if (n == 0) "count" else if (n == 1) "cont_sum1" else s"cont_degree$n"
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val r = if (mode == 0) "r." else "r_"
    val head: Access = Access(s"$r$name", xSeq, Tensor)
    val other = if (mode == 0) "other." else "other_"
    val var1: Access = Access(name,  xSeq, Tensor)
    val var2: Access = Access(s"$other$name",  xSeq, Tensor)
    val prods1: Prod = Prod(Seq(var1))
    val prods2: Prod = Prod(Seq(var2))
    val body: SoP = SoP(Seq(prods1, prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dimSeq: Seq[Variable] = indSeq.map(i => "CONT_SZ".toVar)

    val dim1: DimInfo = DimInfo(var1, dimSeq)
    val dim2: DimInfo = DimInfo(var2, dimSeq)
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(name.uniqueName,  xSeq, UniqueSet)
    val var1BodyUS: SoP = if(n == 0) SoP(Seq(Prod(Seq(trueComparison())))) else dim1.toSoP
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(name.redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(s"$other$name".uniqueName,  xSeq, UniqueSet)
    val var2BodyUS: SoP = if(n == 0) SoP(Seq(Prod(Seq(trueComparison())))) else dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(s"$other$name".redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](var1 -> var1US, var2 -> var2US)))((v1, v2) => v1)
    val redundancyMap: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](var1 -> var1RM, var2 -> var2RM)))((v1, v2) => v1)

    val compressionMap: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp))))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap, compressionMap)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val cF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), compressionMap))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, diF, usF, rmF, cF)
  }

  def e2ePlusEqual(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule], c: Map[Exp, Rule], mode: Int = 0) = {
    val name = if (n == 0) "count" else if (n == 1) "cont_sum1" else s"cont_degree$n"
    val indSeq: Seq[Int] = (0 to n - 1)
    val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
    val head: Access = Access(name, xSeq, Tensor)
    val other = if (mode == 0) "other." else "other_"
    val var2: Access = Access(s"$other$name",  xSeq, Tensor)
    val prods2: Prod = Prod(Seq(var2))
    val body: SoP = SoP(Seq(prods2))
    val tensorComputation: Rule = Rule(head, body)

    val dimSeq: Seq[Variable] = indSeq.map(i => "CONT_SZ".toVar)

    val dim2: DimInfo = DimInfo(var2, dimSeq)
    val dimInfo: Seq[DimInfo] = Seq(dim2)

    val var2HeadUS: Access = Access(s"$other$name".uniqueName,  xSeq, UniqueSet)
    val var2BodyUS: SoP = if(n == 0) SoP(Seq(Prod(Seq(trueComparison())))) else dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(s"$other$name".redundancyName,  xSeq.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = mergeMap(Seq(us, Map[Exp, Rule](var2 -> var2US)))((v1, v2) => v1)
    val redundancyMap: Map[Exp, Rule] = mergeMap(Seq(rm, Map[Exp, Rule](var2 -> var2RM)))((v1, v2) => v1)

    val compressionMap: Map[Exp, Rule] = uniqueSets.foldLeft(Seq.empty[(Exp, Rule)])((acc, kv) => {
      val (exp, us) = kv
      val access = exp.asInstanceOf[Access]
      val compressedHead = Access(access.name.compressedName, access.vars, CompressedTensor)
      val compressedBody = multSoP(Seq(us.body, SoP(Seq(Prod(Seq(exp))))))
      acc :+ (exp -> Rule(compressedHead, compressedBody))
    }).toMap

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, uniqueSets, redundancyMap, compressionMap)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), uniqueSets))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), redundancyMap))((v1, v2) => v1)
    val cF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), compressionMap))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, diF, usF, rmF, cF)
  }

  def e2eMultiplication(n: Int, us: Map[Exp, Rule], rm: Map[Exp, Rule], c: Map[Exp, Rule]) = {
    val degrees: Seq[Int] = (0 to n)
    val outName: String = if (n == 0) "r.count" else if (n == 1) "r.cont_sum1" else s"r.cont_degree$n"
    val (prods, dimInfo, newUS, newRM, newC): (Seq[Prod], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], Map[Exp, Rule]) = degrees.foldLeft((Seq.empty[Prod], Seq.empty[DimInfo], us, rm, c))((acc, i) => {
      val (degA, degB): (Int, Int) = (n - i, i)
      val nameA: String = if (degA == 0) "count" else if (degA == 1) "cont_sum1" else s"cont_degree$degA"
      val nameB: String = if (degB == 0) "other.count" else if (degB == 1) "other.cont_sum1" else s"other.cont_degree$degB"
      (0 to n - 1).combinations(degA).foldLeft(acc)((acc2, xIndSeq) => {
        val yIndSeq: Seq[Int] = (0 to n - 1).filter(i => !xIndSeq.contains(i)).toSeq
        val xSeqA: Seq[Variable] = (0 to degA - 1).map(i => s"x${xIndSeq(i)}".toVar)
        val xSeqB: Seq[Variable] = (0 to degB - 1).map(i => s"y${yIndSeq(i)}".toVar)
        val xSeqFakeA: Seq[Variable] = (0 to degA - 1).map(i => s"x$i".toVar)
        val xSeqFakeB: Seq[Variable] = (0 to degB - 1).map(i => s"x$i".toVar)
        val xMapA1: Map[Variable, Variable] = (xSeqFakeA zip xSeqA).toMap
        val xMapA2: Map[Variable, Variable] = xMapA1.map{case(k, v) => (k.redundancyVars -> v.redundancyVars)}.toMap
        val xMapA: Map[Variable, Variable] = mergeMap(Seq(xMapA1, xMapA2))((v1, v2) => v1)
        val xMapB1: Map[Variable, Variable] = mergeMap(Seq((xSeqFakeB zip xSeqB).toMap, Map[Variable, Variable]("CONT_SZ".toVar -> "CONT_SZ2".toVar)))((v1, v2) => v1)
        val xMapB2: Map[Variable, Variable] = xMapB1.map{case(k, v) => (k.redundancyVars -> v.redundancyVars)}.toMap
        val xMapB: Map[Variable, Variable] = mergeMap(Seq(xMapB1, xMapB2))((v1, v2) => v1)
        val headFakeA: Access = Access(nameA, xSeqFakeA, Tensor)
        val headFakeB: Access = Access(nameB, xSeqFakeB, Tensor)
        val (aFakeUS, aFakeRM, aFakeC): (Rule, Rule, Rule) = (acc2._3.getOrElse(headFakeA, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._4.getOrElse(headFakeA, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._5.getOrElse(headFakeA, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison(), headFakeA)))))))
        val (bFakeUS, bFakeRM, bFakeC): (Rule, Rule, Rule) = (acc2._3.getOrElse(headFakeB, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._4.getOrElse(headFakeB, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison())))))), acc2._5.getOrElse(headFakeB, Rule(headFakeA, SoP(Seq(Prod(Seq(trueComparison(), headFakeB)))))))
        val (aUS, aRM, aC): (Rule, Rule, Rule) = (replaceVars(aFakeUS, xMapA), replaceVars(aFakeRM, xMapA), replaceVars(aFakeC, xMapA))
        val (bUS, bRM, bC): (Rule, Rule, Rule) = (replaceVars(bFakeUS, xMapB), replaceVars(bFakeRM, xMapB), replaceVars(bFakeC, xMapB))
        val headA: Access = Access(nameA, xSeqA, Tensor)
        val headB: Access = Access(nameB, xSeqB, Tensor)
        val newUS: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headA -> aUS, headB -> bUS), acc2._3))((v1, v2) => v1)
        val newRM: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headA -> aRM, headB -> bRM), acc2._4))((v1, v2) => v1)
        val newC: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](headA -> aC, headB -> bC), acc2._5))((v1, v2) => v1)
        val dimSeqA: Seq[Variable] = xSeqA.map(i => "CONT_SZ".toVar)
        val dimSeqB: Seq[Variable] = xSeqB.map(i => "CONT_SZ2".toVar)
        val dimA: DimInfo = DimInfo(headA, dimSeqA)
        val dimB: DimInfo = DimInfo(headB, dimSeqB)
        val dimInfo: Seq[DimInfo] = Seq(dimA, dimB)
        
        val compSeqB: Seq[Variable] = (0 to degB - 1).map(i => s"x${yIndSeq(i)}".toVar)
        val comp: Seq[Comparison] = (compSeqB zip xSeqB).map{case (x, y) => Comparison("=", Arithmetic("-", x, "CONT_SZ".toVar), y)}

        (acc2._1 :+ Prod(Seq(headA, headB) ++ comp), acc2._2 ++ dimInfo, newUS, newRM, newC)
      })
    })
    val xSeq: Seq[Variable] = (0 to n - 1).map(i => s"x$i".toVar)
    val head: Access = Access(outName, xSeq, Tensor)
    val body = SoP(prods)
    val tensorComputation: Rule = Rule(head, body)

    // println("Initial mult us and rm")

    // newUS.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <newus> " + cur._2.prettyFormat))
    // newRM.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <newrm> " + cur._2.prettyFormat))

    // println("Initial mult us and rm DONE")

    val inf: (Rule, Rule, Rule, DimInfo) = infer(tensorComputation, dimInfo, newUS, newRM, newC)

    val usF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._1), newUS))((v1, v2) => v1)
    val rmF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._2), newRM))((v1, v2) => v1)
    val cF: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head -> inf._3), newC))((v1, v2) => v1)
    val diF: Seq[DimInfo] = dimInfo :+ inf._4
    
    (tensorComputation, diF, usF, rmF, cF)
  }

  def e2eLR(codeMotion: Boolean = true) = {
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = e2eConstructor(2)
    // println(codeGen(const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap))
    // println("===========================================================")
    val us2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val rm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val c2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val us: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, us2))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, rm2))((v1, v2) => v1)
    val c: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, c2))((v1, v2) => v1)

    // println("Initial us and rm")

    // us.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <us> " + cur._2.prettyFormat))
    // rm.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <rm> " + cur._2.prettyFormat))

    // println("Initial us and rm DONE")

    // val (add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap) = e2eAddition(2, us, rm)
    // println(codeGen(add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap))
    // println("===========================================================")

    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = e2ePlusEqual(2, us, rm, c)
    // println(codeGen(peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap))
    // println("===========================================================")

    val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, mult_compressionMap) = e2eMultiplication(2, us, rm, c)
    println(mult_tensorComputation.prettyFormat)
    println(codeGen(mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, compressionMaps=mult_compressionMap, codeMotion=codeMotion))
    println("===========================================================")
  }

  def e2ePRk(k: Int, codeMotion: Boolean = true) = {
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    // const_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap)))
    // println("===========================================================")
    val us2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val rm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val c2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val us: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, us2))((v1, v2) => v1)
    val rm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, rm2))((v1, v2) => v1)
    val c: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, c2))((v1, v2) => v1)

    // println("Initial us and rm")

    // us.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <us> " + cur._2.prettyFormat))
    // rm.foldLeft()((acc, cur) => println(cur._1.prettyFormat + " <rm> " + cur._2.prettyFormat))

    // println("Initial us and rm DONE")

    // val (add_tensorComputation, add_dimInfo, add_uniqueSets, add_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, us, rm))((acc, d) => {
    //   val res = e2eAddition(d, acc._3, acc._4)
    //   (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    // })
    // add_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, add_dimInfo, add_uniqueSets, add_redundancyMap)))
    // println("===========================================================")

    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, us, rm, c))((acc, d) => {
      val res = e2ePlusEqual(d, acc._3, acc._4, acc._5)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    peq_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, compressionMaps=peq_compressionMap, codeMotion=codeMotion)))
    println("===========================================================")

    // val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, us, rm))((acc, d) => {
    //   val res = e2eMultiplication(d, acc._3, acc._4)
    //   (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    // })
    // mult_tensorComputation.foldLeft()((_, cur) => println(cur.prettyFormat))
    // mult_tensorComputation.foldLeft()((acc, ctc) => println(codeGen(ctc, mult_dimInfo, mult_uniqueSets, mult_redundancyMap)))
    // println("===========================================================")
  }

  def e2ePRkWithSkeletone(k: Int, codeMotion: Boolean = true) = {
    val initCode: String = s"""
#ifndef RING_COFACTOR_HPP
#define RING_COFACTOR_HPP

#include <array>
#include <unordered_map>
#include "hash.hpp"


template <typename T, int CONT_SZ, int CAT_SZ>
struct RingCofactor {
    long count;
    std::array<double, CONT_SZ> cont_sum1;
    std::array<std::array<double, CONT_SZ>, CONT_SZ> cont_degree2;
    ${if (k == 2) {
      s"""
    std::array<std::array<std::array<double, CONT_SZ>, CONT_SZ>, CONT_SZ> cont_degree3;
    std::array<std::array<std::array<std::array<double, CONT_SZ>, CONT_SZ>, CONT_SZ>, CONT_SZ> cont_degree4;
      """
    } else ""}


    explicit RingCofactor() : count(0) {
      cont_sum1 = {};
      cont_degree2 = {};
      ${if (k == 2) {
        s"""
      cont_degree3 = {};
      cont_degree4 = {};
        """
      } else ""}
    }

    template <typename... Args>
    explicit RingCofactor(Args&&... args): count(1), cont_sum1 { args... } {
        static_assert(CONT_SZ == sizeof...(args) && CAT_SZ == 0, "Incompatible array sizes");
"""

    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val constructorCode: String = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap, codeMotion=codeMotion)}")
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip 
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other." + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)

    val multus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val multrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), v.body), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val multc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other." + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> replaceVars(Rule(Access("other." + v.head.name, v.head.vars, v.head.kind), 
    SoP((getOnlyComparisonSoP(v.body).prods zip
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other." + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})), Map("CONT_SZ".toVar -> "CONT_SZ2".toVar)))}.toMap
    val multus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, multus2))((v1, v2) => v1)
    val multrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, multrm2))((v1, v2) => v1)
    val multc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, multc2))((v1, v2) => v1)

    val afterConstructorCode: String = s"""
    }
    
    inline bool isZero() const { return count == 0; }

    void finished(double div_val = 0, bool mapping_flag = false) {

    }

    RingCofactor& operator+=(const RingCofactor& other) {
        peqInplace(other);
        return *this;
    }

    void peqInplace(const RingCofactor& other, bool sort_merge_flag = false) {
        if (other.isZero()) return;
"""

    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = (0 to 2 * k).foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2ePlusEqual(d, acc._3, acc._4, acc._5)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val peqCode: String = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap, codeMotion=codeMotion)}")

    val afterPeqCode: String = s"""
    }
    template <int CONT_SZ2, int CAT_SZ2>
    RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> operator*(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other) const {
        if (isZero() || other.isZero()) return RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>();
        return this->multiply(other);
    }

    template <int CONT_SZ2, int CAT_SZ2>
    RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>
    multiply(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other) const {
        RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> r;
        multiplyDPS(other, r);
        return r;
    }

    template <int CONT_SZ2, int CAT_SZ2>
    void
    multiplyDPS(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other, RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>& r) const {    
"""

    val (mult_tensorComputation, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, mult_compressionMap) = (0 to 2 * k).foldLeft((Seq.empty[Rule], const_dimInfo, multus, multrm, multc))((acc, d) => {
      val res = e2eMultiplication(d, acc._3, acc._4, acc._5)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val multCode: String = mult_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, mult_dimInfo, mult_uniqueSets, mult_redundancyMap, 1, codeMotion=codeMotion)}")

    val afterMultCode: String = s"""
        }


    void clean() {
      count = 0;

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {
        cont_sum1[i1] = 0;
      }

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {
          cont_degree2[i1][i2] = 0;
        }
      }

      ${if (k == 2) {
        s"""
      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {

          for(int i3 = i2; i3 < CONT_SZ; ++i3) {
            cont_degree3[i1][i2][i3] = 0;
          }
        }
      }

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {

          for(int i3 = i2; i3 < CONT_SZ; ++i3) {

            for(int i4 = i3; i4 < CONT_SZ; ++i4) {
              cont_degree4[i1][i2][i3][i4] = 0;
            }
          }
        }
      }
"""
      } else ""}
    }    
    void reconstruct() {
"""

    val reconstructorCode: String = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 2, compressionMaps=const_compressionMap, codeMotion=codeMotion)}")

    val endCode: String = s"""
        std::cerr << cont_sum1[CONT_SZ - 1];
        std::cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1];
        ${if (k == 2) {
          s"""
        std::cerr << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1];
        std::cerr << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1];
"""
        } else ""}
    }

};

template <typename T, size_t CONT_SZ, size_t CAT_SZ>
RingCofactor<T, CONT_SZ, CAT_SZ> operator*(long int alpha, const RingCofactor<T, CONT_SZ, CAT_SZ>& c) {
    if (alpha == 1L) return c;
    return c.multiply(alpha);
}

template <typename T>
inline double convert(T x) { return x; }

template <typename... Args>
RingCofactor<double, sizeof...(Args), 0> Uliftcont(Args&&... args) {
    return RingCofactor<double, sizeof...(Args), 0>(convert(args)...);
}

template <typename... Args>
RingCofactor<double, 0, sizeof...(Args)> Uliftcat(Args&&... args) {
    return RingCofactor<double, 0, sizeof...(Args)>(true, args...);
}

template <typename T, int CONT_SZ, int CAT_SZ>
std::ostream& operator<<(std::ostream& os, const RingCofactor<T, CONT_SZ, CAT_SZ>& v) {
os << "Cofactor: <CONT_SZ: " << CONT_SZ << ", CAT_SZ: " << CAT_SZ << ">\\n";
  os << v.count << "\\n";
  os << "cont_sum1:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    os << v.cont_sum1[i] << ((i < CONT_SZ - 1) ? ", " : "\\n");
  }

  os << "cont_degree2:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        os << v.cont_degree2[i][j] << ", ";
    }
  }
  os << "\\n";

  ${if (k == 2) {
    s"""
  os << "cont_degree3:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        for (int k = 0; k < CONT_SZ; ++k) {
            os << v.cont_degree3[i][j][k] << ", ";
        }
    }
  }
  os << "\\n";

  os << "cont_degree4:\\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        for (int k = 0; k < CONT_SZ; ++k) {
            for (int l = 0; l < CONT_SZ; ++l) {
                os << v.cont_degree4[i][j][k][l] << ", ";
            }
        }
    }
  }
  os << "\\n";
"""
  } else ""}
  return os;
}

#endif /* RING_COFACTOR_HPP */
"""
  s"$initCode\n$constructorCode\n$afterConstructorCode\n$peqCode\n$afterPeqCode\n$multCode\n$afterMultCode\n$reconstructorCode\n$endCode"
  }

  def apply(k: Int, codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(k, codeMotion)
      case "MLIR" => "Not Implemented"
      case "C" => "Not Implemented"
      case _ => throw new Exception(f"Unknown code language: $codeLang")
    }
  }

  def CPP(k: Int, codeMotion: Boolean = true) = {
    val code = e2ePRkWithSkeletone(k, codeMotion)
    val outName = "E2E_R"
    write2File(s"outputs/$outName.hpp", code)
  }

}