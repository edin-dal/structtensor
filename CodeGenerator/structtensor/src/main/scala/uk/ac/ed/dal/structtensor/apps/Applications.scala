package uk.ac.ed.dal
package structtensor
package apps

import java.io._ 
import compiler._
import STURHelper._
import Compiler._
import Shared._

object Applications {

  import E2E_PRK._

  // // Binary multiplication for 2 tensors check -- worked
  // def test1(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
  //   val var1BodyUS: SoP = multSoP(Seq(SoP(Seq(var1ProdsUS)), dim1.toSoP))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
  //   val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
  //   val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
  //   val var2BodyUS: SoP = multSoP(Seq(SoP(Seq(var2ProdsUS)), dim2.toSoP))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
  //   val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(SoP(Seq(var2ProdsRM)), dim2.toSoP))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Binary addition for 2 tensors check -- worked
  // def test2(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val prod1: Prod = Prod(Seq(var1))
  //   val prod2: Prod = Prod(Seq(var2))
  //   val body: SoP = SoP(Seq(prod1, prod2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
  //   val var1BodyUS: SoP = multSoP(Seq(SoP(Seq(var1ProdsUS)), dim1.toSoP))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
  //   val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
  //   val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
  //   val var2BodyUS: SoP = multSoP(Seq(SoP(Seq(var2ProdsUS)), dim2.toSoP))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
  //   val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(SoP(Seq(var2ProdsRM)), dim2.toSoP))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Self-outer product check -- worked
  // def test3(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x")), Tensor)
  //   val var2: Access = Access("A",  Seq(Variable("y")), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // DTTV check: worked
  // def test4(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
  //   val in2SeqVar = Seq("k".toVar)
  //   val outName = "A"
  //   val in1Name = "M"
  //   val in2Name = "N"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar, "m".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
  //   val var1ExpUS2: Exp = Comparison("=", "j".toVar, "k".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
  //   val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // RMD check: worked -- page 12: M_U should be 0 <= k < n (not j instead of k!!!) also in simplifications should be fixed too!
  // def test5(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar, "k".toVar)
  //   val in2SeqVar = Seq("k".toVar, "j".toVar)
  //   val outName = "A"
  //   val in1Name = "M"
  //   val in2Name = "N"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "i".toVar, "r".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "k".toVar, "j".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // UHS check: worked
  // def test6(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar)
  //   val in2SeqVar = Seq("i".toVar, "j".toVar)
  //   val outName = "A"
  //   val in1Name = "M"
  //   val in2Name = "N"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", "j".toVar, "i".toVar)
  //   val var2ExpRM2: Exp = Comparison("=", "j".redundancyVars, "i".toVar)
  //   val var2ExpRM3: Exp = Comparison("=", "i".redundancyVars, "j".toVar)
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = SoP(Seq(var2ProdsRM))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Example - Structure Inference checked: worked
  // def test7(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("x1".toVar, "x2".toVar, "x3".toVar, "x4".toVar, "x5".toVar)
  //   val in1SeqVar = Seq("x1".toVar, "x2".toVar, "x3".toVar)
  //   val in2SeqVar = Seq("x4".toVar, "x5".toVar)
  //   val outName = "T"
  //   val in1Name = "M"
  //   val in2Name = "V"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("d1".toVar, "d2".toVar, "d3".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("d4".toVar, "d5".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison(">", "x1".toVar, "x2".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("<=", "x4".toVar, "x5".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison(">", "x4".toVar, "x5".toVar)
  //   val var2ExpRM2: Exp = Comparison("=", "x4".redundancyVars, "x5".toVar)
  //   val var2ExpRM3: Exp = Comparison("=", "x5".redundancyVars, "x4".toVar)
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsRM))))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-binary: Example - Unique set computation: worked
  // def test8(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar, "l".toVar)
  //   val in2SeqVar = Seq("i".toVar, "k".toVar)
  //   val in3SeqVar = Seq("j".toVar, "k".toVar)
  //   val in4SeqVar = Seq("i".toVar, "j".toVar)
  //   val outName = "A"
  //   val inter1Name = "F"
  //   val inter2Name = "G"
  //   val in1Name = "B"
  //   val in2Name = "C"
  //   val in3Name = "D"
  //   val in4Name = "E"

  //   val head1: Access = Access(inter1Name, outSeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, outSeqVar, Tensor)
  //   val head3: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Access = Access(in3Name, in3SeqVar, Tensor)
  //   val var4: Access = Access(in4Name, in4SeqVar, Tensor)
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val prods2: Prod = Prod(Seq(var3, var4))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(Prod(Seq(head1)), Prod(Seq(head2))))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar, "n".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar, "n".toVar))
  //   val dimH1: DimInfo = DimInfo(head1, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dimH2: DimInfo = DimInfo(head2, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dimH1, dimH2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = SoP(Seq(var1ProdsUS))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "l".toVar, "k".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = SoP(Seq(var2ProdsUS))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
  //   val var3BodyUS: SoP = emptySoP()
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
  //   val var4ExpUS1: Exp = Comparison("<=", "i".toVar, "k".toVar)
  //   val var4ProdsUS: Prod = Prod(Seq(var4ExpUS1))
  //   val var4BodyUS: SoP = SoP(Seq(var4ProdsUS))
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))

  //   pprintTest((tensorComputation1, infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)))
  //   pprintTest((tensorComputation2, infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)))

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo ++ Seq(infer1._3, infer2._3)

  //   println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))

  //   (tensorComputation3, infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  // }

  // // Normalised: Example - Unique set computation: worked
  // def test8n(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar, "k".toVar)
  //   val in1SeqVar = Seq("i".toVar, "j".toVar, "l".toVar)
  //   val in2SeqVar = Seq("i".toVar, "k".toVar)
  //   val in3SeqVar = Seq("j".toVar, "k".toVar)
  //   val in4SeqVar = Seq("i".toVar, "j".toVar)
  //   val outName = "A"
  //   val in1Name = "B"
  //   val in2Name = "C"
  //   val in3Name = "D"
  //   val in4Name = "E"

  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Access = Access(in3Name, in3SeqVar, Tensor)
  //   val var4: Access = Access(in4Name, in4SeqVar, Tensor)
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val prods2: Prod = Prod(Seq(var3, var4))
  //   val body: SoP = SoP(Seq(prods1, prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar, "n".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar, "n".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "l".toVar, "k".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access(in3Name.uniqueName,  in3SeqVar, UniqueSet)
  //   val var3BodyUS: SoP = emptySoP()
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access(in3Name.redundancyName,  in3SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access(in4Name.uniqueName,  in4SeqVar, UniqueSet)
  //   val var4ExpUS1: Exp = Comparison("<=", "i".toVar, "k".toVar)
  //   val var4ProdsUS: Prod = Prod(Seq(var4ExpUS1))
  //   val var4BodyUS: SoP = multSoP(Seq(dim4.toSoP, SoP(Seq(var4ProdsUS))))
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access(in4Name.redundancyName,  in4SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-binary: Example - Normal Kronecker Product
  // def test9(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val inter1Name = "C"
  //   val inter2Name = "D"
  //   val inter3Name = "E"
  //   val inter4Name = "F"
  //   val inter5Name = "G"
  //   val inter6Name = "H"
  //   val inter7Name = "I"
  //   val inter8Name = "J"
  //   val inter9Name = "K"
  //   val inter10Name = "L"
  //   val inter11Name = "M"
  //   val inter12Name = "N"
  //   val in1Name = "A"
  //   val in2Name = "B"

  //   val head1: Access = Access(inter1Name, in1SeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, in2SeqVar, Tensor)
  //   val head3: Access = Access(inter3Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head4: Access = Access(inter4Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head5: Access = Access(inter5Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head6: Access = Access(inter6Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head7: Access = Access(inter7Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head8: Access = Access(inter8Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head9: Access = Access(inter9Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head10: Access = Access(inter10Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head11: Access = Access(inter11Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head12: Access = Access(inter12Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "x".toVar, "m".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "y".toVar, "n".toVar), "j".toVar)
    
  //   val prods1: Prod = Prod(Seq(var1, var7))
  //   val prods2: Prod = Prod(Seq(var2, var7))
  //   val prods3: Prod = Prod(Seq(head1, var9))
  //   val prods4: Prod = Prod(Seq(head2, var9))
  //   val prods5: Prod = Prod(Seq(head3, var3))
  //   val prods6: Prod = Prod(Seq(head4, var5))
  //   val prods7: Prod = Prod(Seq(head5, var8))
  //   val prods8: Prod = Prod(Seq(head6, var8))
  //   val prods9: Prod = Prod(Seq(head7, var10))
  //   val prods10: Prod = Prod(Seq(head8, var10))
  //   val prods11: Prod = Prod(Seq(head9, var4))
  //   val prods12: Prod = Prod(Seq(head10, var6))
  //   val prods: Prod = Prod(Seq(head11, head12))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(prods3))
  //   val body4: SoP = SoP(Seq(prods4))
  //   val body5: SoP = SoP(Seq(prods5))
  //   val body6: SoP = SoP(Seq(prods6))
  //   val body7: SoP = SoP(Seq(prods7))
  //   val body8: SoP = SoP(Seq(prods8))
  //   val body9: SoP = SoP(Seq(prods9))
  //   val body10: SoP = SoP(Seq(prods10))
  //   val body11: SoP = SoP(Seq(prods11))
  //   val body12: SoP = SoP(Seq(prods12))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)
  //   val tensorComputation4: Rule = Rule(head4, body4)
  //   val tensorComputation5: Rule = Rule(head5, body5)
  //   val tensorComputation6: Rule = Rule(head6, body6)
  //   val tensorComputation7: Rule = Rule(head7, body7)
  //   val tensorComputation8: Rule = Rule(head8, body8)
  //   val tensorComputation9: Rule = Rule(head9, body9)
  //   val tensorComputation10: Rule = Rule(head10, body10)
  //   val tensorComputation11: Rule = Rule(head11, body11)
  //   val tensorComputation12: Rule = Rule(head12, body12)
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("x".toVar, "y".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo ++ Seq(infer1._3, infer2._3)

  //   val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap)
  //   val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap)

  //   val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)
  //   val newDimInfo2: Seq[DimInfo] = newDimInfo ++ Seq(infer3._3, infer4._3)

  //   val infer5: (Rule, Rule, DimInfo) = infer(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2)
  //   val infer6: (Rule, Rule, DimInfo) = infer(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2)

  //   val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
  //   val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)
  //   val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++ Seq(infer5._3, infer6._3)

  //   val infer7: (Rule, Rule, DimInfo) = infer(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3)
  //   val infer8: (Rule, Rule, DimInfo) = infer(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3)

  //   val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
  //   val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)
  //   val newDimInfo4: Seq[DimInfo] = newDimInfo3 ++ Seq(infer7._3, infer8._3)

  //   val infer9: (Rule, Rule, DimInfo) = infer(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4)
  //   val infer10: (Rule, Rule, DimInfo) = infer(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4)

  //   val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
  //   val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)
  //   val newDimInfo5: Seq[DimInfo] = newDimInfo4 ++ Seq(infer9._3, infer10._3)

  //   val infer11: (Rule, Rule, DimInfo) = infer(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5)
  //   val infer12: (Rule, Rule, DimInfo) = infer(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5)

  //   val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
  //   val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)
  //   val newDimInfo6: Seq[DimInfo] = newDimInfo5 ++ Seq(infer11._3, infer12._3)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5))
  //   println(codeGen(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5))

  //   println(codeGen(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))

  //   pprintTest((tensorComputation1, infer1))
  //   pprintTest((tensorComputation2, infer2))
  //   pprintTest((tensorComputation3, infer3))
  //   pprintTest((tensorComputation4, infer4))
  //   pprintTest((tensorComputation5, infer5))
  //   pprintTest((tensorComputation6, infer6))
  //   pprintTest((tensorComputation7, infer7))
  //   pprintTest((tensorComputation8, infer8))
  //   pprintTest((tensorComputation9, infer9))
  //   pprintTest((tensorComputation10, infer10))
  //   pprintTest((tensorComputation11, infer11))
  //   pprintTest((tensorComputation12, infer12))

  //   (tensorComputation, infer(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))
  // }

  // // Normalised: Example - Normal Kronecker Product
  // def test9n(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val in1Name = "A"
  //   val in2Name = "B"
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "m".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "m".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "x".toVar, "m".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "y".toVar, "n".toVar), "j".toVar)
    
  //   val prods: Prod = Prod(Seq(var1, var7, var9, var3, var8, var10, var4, var2, var7, var9, var5, var8, var10, var6))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("x".toVar, "y".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    
  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-binary: Polynomial Regression Degree 2 -- It's a confusing mess, will check it after all simplifications
  // def test10(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val inSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("i".toVar)
  //   val in2SeqVar = Seq("j".toVar)
  //   val outSeqVar = Seq("p".toVar, "q".toVar)
  //   val interSeqVar1 = Seq("k".toVar)
  //   val interSeqVar2 = Seq("p".toVar)
  //   val interSeqVar3 = Seq("q".toVar)
  //   val outName = "S"
  //   val inter1Name = "A"
  //   val inter2Name = "B"
  //   val inter3Name = "C"
  //   val inter4Name = "D"
  //   val in1Name = "f"
  //   val in2Name = "f"
  //   val in3Name = "f"
  //   val in4Name = "f"
  //   val in5Name = "f"
  //   val in6Name = "f"
  //   val in7Name = "f"

  //   val head1: Access = Access(inter1Name, inSeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, interSeqVar1, Tensor)
  //   val head3: Access = Access(inter3Name, interSeqVar2, Tensor)
  //   val head4: Access = Access(inter4Name, interSeqVar3, Tensor)
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in1Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("+", Arithmetic("*", "i".toVar, "n".toVar), "j".toVar), "k".toVar)
  //   val var4: Access = Access(in1Name, interSeqVar2, Tensor)
  //   val var5: Comparison = Comparison("=", Arithmetic("-", "p".toVar, "n".toVar), "k".toVar)
  //   val var6: Access = Access(in1Name, interSeqVar3, Tensor)
  //   val var7: Comparison = Comparison("=", Arithmetic("-", "q".toVar, "n".toVar), "k".toVar)
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val prods2: Prod = Prod(Seq(head1, var3))
  //   val prods3: Prod = Prod(Seq(head2, var5))
  //   val prods4: Prod = Prod(Seq(head2, var7))
  //   val prods: Prod = Prod(Seq(head3, head4))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(Prod(Seq(var4)), prods3))
  //   val body4: SoP = SoP(Seq(Prod(Seq(var6)), prods4))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)
  //   val tensorComputation4: Rule = Rule(head4, body4)
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dim3: DimInfo = DimInfo(var4, Seq("n".toVar))
  //   val dim4: DimInfo = DimInfo(var6, Seq("n".toVar))
  //   // val dimH1: DimInfo = DimInfo(head1, Seq("n".toVar, "n".toVar, "n".toVar)) n times n?
  //   val dimH2: DimInfo = DimInfo(head2, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dimH2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1BodyUS: SoP = emptySoP()
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   // since all of them are empty so it doesn't matter
  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

  //   pprintTest((tensorComputation1, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)))
    
  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo :+ infer1._3
    
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, newDimInfo, newUniqueSets, newRedundancyMap)

  //   println(codeGen(tensorComputation2, newDimInfo, newUniqueSets, newRedundancyMap))

  //   pprintTest((tensorComputation2, infer(tensorComputation, newDimInfo, newUniqueSets, newRedundancyMap)))

  //   val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._1), newUniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head2 -> infer2._2), newRedundancyMap))((v1, v2) => v2)
  //   val newDimInfo2: Seq[DimInfo] = newDimInfo :+ infer2._3

  //   val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo2, newUniqueSets2, newRedundancyMap2)
  //   val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo2, newUniqueSets2, newRedundancyMap2)

  //   println(codeGen(tensorComputation3, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation4, newDimInfo2, newUniqueSets2, newRedundancyMap2))

  //   pprintTest((tensorComputation3, infer(tensorComputation, newDimInfo2, newUniqueSets2, newRedundancyMap2)))
  //   pprintTest((tensorComputation4, infer(tensorComputation, newDimInfo2, newUniqueSets2, newRedundancyMap2)))

  //   val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets2))((v1, v2) => v2)
  //   val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap2))((v1, v2) => v2)
  //   val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++ Seq(infer3._3, infer4._3)

  //   println(codeGen(tensorComputation, newDimInfo3, newUniqueSets3, newRedundancyMap3))

  //   (tensorComputation, infer(tensorComputation, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  // }

  // // Self-outer product 3 check: worked -- need to be checked inside covariance matrices to make sure -- manually checked
  // def test11(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar, "y".toVar, "z".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("A",  Seq("y".toVar), Tensor)
  //   val var3: Access = Access("A",  Seq("z".toVar), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2, var3))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("A".uniqueName,  Seq(Variable("z")), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access("A".redundancyName,  Seq(Variable("z"), Variable("z").redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Self-outer product 4 check: worked  -- need to be checked inside covariance matrices to make sure -- manually checked
  // def test12(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar, "y".toVar, "z".toVar, "p".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("A",  Seq("y".toVar), Tensor)
  //   val var3: Access = Access("A",  Seq("z".toVar), Tensor)
  //   val var4: Access = Access("A",  Seq("p".toVar), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2, var3, var4))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("n".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("A".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("A".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("A".uniqueName,  Seq(Variable("z")), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access("A".redundancyName,  Seq(Variable("z"), Variable("z").redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access("A".uniqueName,  Seq(Variable("p")), UniqueSet)
  //   val var4BodyUS: SoP = dim4.toSoP
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access("A".redundancyName,  Seq(Variable("p"), Variable("p").redundancyVars), RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Non-Binary Example: Diagonal Kronecker Product
  // def test13(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val inter1Name = "C"
  //   val inter2Name = "D"
  //   val inter3Name = "E"
  //   val inter4Name = "F"
  //   val inter5Name = "G"
  //   val inter6Name = "H"
  //   val inter7Name = "I"
  //   val inter8Name = "J"
  //   val inter9Name = "K"
  //   val inter10Name = "L"
  //   val inter11Name = "M"
  //   val inter12Name = "N"
  //   val in1Name = "A"
  //   val in2Name = "B"

  //   val head1: Access = Access(inter1Name, in1SeqVar, Tensor)
  //   val head2: Access = Access(inter2Name, in2SeqVar, Tensor)
  //   val head3: Access = Access(inter3Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head4: Access = Access(inter4Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head5: Access = Access(inter5Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head6: Access = Access(inter6Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head7: Access = Access(inter7Name, Seq("i".toVar, "p".toVar, "q".toVar), Tensor)
  //   val head8: Access = Access(inter8Name, Seq("i".toVar, "r".toVar, "s".toVar), Tensor)
  //   val head9: Access = Access(inter9Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head10: Access = Access(inter10Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head11: Access = Access(inter11Name, outSeqVar ++ in1SeqVar, Tensor)
  //   val head12: Access = Access(inter12Name, outSeqVar ++ in2SeqVar, Tensor)
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "n".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "n".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "j".toVar)
    
  //   val prods1: Prod = Prod(Seq(var1, var7))
  //   val prods2: Prod = Prod(Seq(var2, var7))
  //   val prods3: Prod = Prod(Seq(head1, var9))
  //   val prods4: Prod = Prod(Seq(head2, var9))
  //   val prods5: Prod = Prod(Seq(head3, var3))
  //   val prods6: Prod = Prod(Seq(head4, var5))
  //   val prods7: Prod = Prod(Seq(head5, var8))
  //   val prods8: Prod = Prod(Seq(head6, var8))
  //   val prods9: Prod = Prod(Seq(head7, var10))
  //   val prods10: Prod = Prod(Seq(head8, var10))
  //   val prods11: Prod = Prod(Seq(head9, var4))
  //   val prods12: Prod = Prod(Seq(head10, var6))
  //   val prods: Prod = Prod(Seq(head11, head12))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val body3: SoP = SoP(Seq(prods3))
  //   val body4: SoP = SoP(Seq(prods4))
  //   val body5: SoP = SoP(Seq(prods5))
  //   val body6: SoP = SoP(Seq(prods6))
  //   val body7: SoP = SoP(Seq(prods7))
  //   val body8: SoP = SoP(Seq(prods8))
  //   val body9: SoP = SoP(Seq(prods9))
  //   val body10: SoP = SoP(Seq(prods10))
  //   val body11: SoP = SoP(Seq(prods11))
  //   val body12: SoP = SoP(Seq(prods12))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val tensorComputation3: Rule = Rule(head3, body3)
  //   val tensorComputation4: Rule = Rule(head4, body4)
  //   val tensorComputation5: Rule = Rule(head5, body5)
  //   val tensorComputation6: Rule = Rule(head6, body6)
  //   val tensorComputation7: Rule = Rule(head7, body7)
  //   val tensorComputation8: Rule = Rule(head8, body8)
  //   val tensorComputation9: Rule = Rule(head9, body9)
  //   val tensorComputation10: Rule = Rule(head10, body10)
  //   val tensorComputation11: Rule = Rule(head11, body11)
  //   val tensorComputation12: Rule = Rule(head12, body12)
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "p".toVar, "q".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "r".toVar, "s".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)
  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo, uniqueSets, redundancyMap)

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1, head2 -> infer2._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2, head2 -> infer2._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo ++  Seq(infer1._3, infer2._3)

  //   val infer3: (Rule, Rule, DimInfo) = infer(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap)
  //   val infer4: (Rule, Rule, DimInfo) = infer(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap)

  //   val newUniqueSets2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._1, head4 -> infer4._1), newUniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap2: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head3 -> infer3._2, head4 -> infer4._2), newRedundancyMap))((v1, v2) => v2)
  //   val newDimInfo2: Seq[DimInfo] = newDimInfo ++  Seq(infer3._3, infer4._3)

  //   val infer5: (Rule, Rule, DimInfo) = infer(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2)
  //   val infer6: (Rule, Rule, DimInfo) = infer(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2)

  //   val newUniqueSets3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._1, head6 -> infer6._1), newUniqueSets2))((v1, v2) => v2)
  //   val newRedundancyMap3: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head5 -> infer5._2, head6 -> infer6._2), newRedundancyMap2))((v1, v2) => v2)
  //   val newDimInfo3: Seq[DimInfo] = newDimInfo2 ++  Seq(infer5._3, infer6._3)

  //   val infer7: (Rule, Rule, DimInfo) = infer(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3)
  //   val infer8: (Rule, Rule, DimInfo) = infer(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3)

  //   val newUniqueSets4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._1, head8 -> infer8._1), newUniqueSets3))((v1, v2) => v2)
  //   val newRedundancyMap4: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head7 -> infer7._2, head8 -> infer8._2), newRedundancyMap3))((v1, v2) => v2)
  //   val newDimInfo4: Seq[DimInfo] = newDimInfo3 ++  Seq(infer7._3, infer8._3)

  //   val infer9: (Rule, Rule, DimInfo) = infer(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4)
  //   val infer10: (Rule, Rule, DimInfo) = infer(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4)

  //   val newUniqueSets5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._1, head10 -> infer10._1), newUniqueSets4))((v1, v2) => v2)
  //   val newRedundancyMap5: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head9 -> infer9._2, head10 -> infer10._2), newRedundancyMap4))((v1, v2) => v2)
  //   val newDimInfo5: Seq[DimInfo] = newDimInfo4 ++  Seq(infer9._3, infer10._3)

  //   val infer11: (Rule, Rule, DimInfo) = infer(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5)
  //   val infer12: (Rule, Rule, DimInfo) = infer(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5)

  //   val newUniqueSets6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._1, head12 -> infer12._1), newUniqueSets5))((v1, v2) => v2)
  //   val newRedundancyMap6: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head11 -> infer11._2, head12 -> infer12._2), newRedundancyMap5))((v1, v2) => v2)
  //   val newDimInfo6: Seq[DimInfo] = newDimInfo5 ++  Seq(infer11._3, infer12._3)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation2, dimInfo, uniqueSets, redundancyMap))
  //   println(codeGen(tensorComputation3, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation4, newDimInfo, newUniqueSets, newRedundancyMap))
  //   println(codeGen(tensorComputation5, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation6, newDimInfo2, newUniqueSets2, newRedundancyMap2))
  //   println(codeGen(tensorComputation7, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation8, newDimInfo3, newUniqueSets3, newRedundancyMap3))
  //   println(codeGen(tensorComputation9, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation10, newDimInfo4, newUniqueSets4, newRedundancyMap4))
  //   println(codeGen(tensorComputation11, newDimInfo5, newUniqueSets5, newRedundancyMap5))
  //   println(codeGen(tensorComputation12, newDimInfo5, newUniqueSets5, newRedundancyMap5))

  //   println(codeGen(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))

  //   pprintTest((tensorComputation1, infer1))
  //   pprintTest((tensorComputation2, infer2))
  //   pprintTest((tensorComputation3, infer3))
  //   pprintTest((tensorComputation4, infer4))
  //   pprintTest((tensorComputation5, infer5))
  //   pprintTest((tensorComputation6, infer6))
  //   pprintTest((tensorComputation7, infer7))
  //   pprintTest((tensorComputation8, infer8))
  //   pprintTest((tensorComputation9, infer9))
  //   pprintTest((tensorComputation10, infer10))
  //   pprintTest((tensorComputation11, infer11))
  //   pprintTest((tensorComputation12, infer12))

  //   (tensorComputation, infer(tensorComputation, newDimInfo6, newUniqueSets6, newRedundancyMap6))
  // }

  // // Normalised: Example - Normal Kronecker Product
  // def test13n(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val outSeqVar = Seq("i".toVar, "j".toVar)
  //   val in1SeqVar = Seq("p".toVar, "q".toVar)
  //   val in2SeqVar = Seq("r".toVar, "s".toVar)
  //   val outName = "O"
  //   val in1Name = "A"
  //   val in2Name = "B"
  //   val head: Access = Access(outName, outSeqVar, Tensor)
  //   val var1: Access = Access(in1Name, in1SeqVar, Tensor)
  //   val var2: Access = Access(in2Name, in2SeqVar, Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("//", "i".toVar, "n".toVar), "p".toVar)
  //   val var4: Comparison = Comparison("=", Arithmetic("//", "j".toVar, "n".toVar), "q".toVar)
  //   val var5: Comparison = Comparison("=", Arithmetic("%", "i".toVar, "n".toVar), "r".toVar)
  //   val var6: Comparison = Comparison("=", Arithmetic("%", "j".toVar, "n".toVar), "s".toVar)
  //   val var7: Comparison = Comparison("<=", ConstantInt(0), "i".toVar)
  //   val var8: Comparison = Comparison("<=", ConstantInt(0), "j".toVar)
  //   val var9: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "i".toVar)
  //   val var10: Comparison = Comparison(">", Arithmetic("*", "m".toVar, "n".toVar), "j".toVar)
    
  //   val prods: Prod = Prod(Seq(var1, var7, var9, var3, var8, var10, var4, var2, var7, var9, var5, var8, var10, var6))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "m".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("n".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access(in1Name.uniqueName, in1SeqVar, UniqueSet)
  //   val var1ExpUS1: Exp = Comparison("=", "p".toVar, "q".toVar)
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //   val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(in1Name.redundancyName,  in1SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(in2Name.uniqueName,  in2SeqVar, UniqueSet)
  //   val var2ExpUS1: Exp = Comparison("=", "r".toVar, "s".toVar)
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS1))
  //   val var2BodyUS: SoP = multSoP(Seq(dim2.toSoP, SoP(Seq(var2ProdsUS))))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(in2Name.redundancyName,  in2SeqVar.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    
  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Vector direct sum - checked
  // def test14(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y".toVar), Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("-", "x".toVar, "n".toVar), "y".toVar)
  //   val prods1: Prod = Prod(Seq(var1))
  //   val prods2: Prod = Prod(Seq(var2, var3))
  //   val body: SoP = SoP(Seq(prods1, prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // a bunch of self mults
  // def test15(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x0".toVar, "y0".toVar, "y1".toVar, "z0".toVar, "y2".toVar, "x1".toVar, "t0".toVar, "z1".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y0".toVar), Tensor)
  //   val var3: Access = Access("B",  Seq("y1".toVar), Tensor)
  //   val var4: Access = Access("C",  Seq("z0".toVar), Tensor)
  //   val var5: Access = Access("B",  Seq("y2".toVar), Tensor)
  //   val var6: Access = Access("A",  Seq("x1".toVar), Tensor)
  //   val var7: Access = Access("D",  Seq("t0".toVar), Tensor)
  //   val var8: Access = Access("C",  Seq("z1".toVar), Tensor)

  //   val prods: Prod = Prod(Seq(var1, var2, var3, var4, var5, var6, var7, var8))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("m".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("p".toVar))
  //   val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
  //   val dim6: DimInfo = DimInfo(var6, Seq("n".toVar))
  //   val dim7: DimInfo = DimInfo(var7, Seq("q".toVar))
  //   val dim8: DimInfo = DimInfo(var8, Seq("p".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim4, dim5, dim6, dim7, dim8)

  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq("x0".toVar), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq("x0".toVar, "x0".toVar.redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq("y0".toVar), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)
    
  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq("y0".toVar, "y0".toVar.redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("B".uniqueName,  Seq("y1".toVar), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
  //   val var3HeadRM: Access = Access("B".redundancyName,  Seq("y1".toVar, "y1".toVar.redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var4HeadUS: Access = Access("C".uniqueName,  Seq("z0".toVar), UniqueSet)
  //   val var4BodyUS: SoP = dim4.toSoP
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)
    
  //   val var4HeadRM: Access = Access("C".redundancyName,  Seq("z0".toVar, "z0".toVar.redundancyVars), RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val var5HeadUS: Access = Access("B".uniqueName,  Seq("y2".toVar), UniqueSet)
  //   val var5BodyUS: SoP = dim5.toSoP
  //   val var5US: Rule = Rule(var5HeadUS, var5BodyUS)
    
  //   val var5HeadRM: Access = Access("B".redundancyName,  Seq("y2".toVar, "y2".toVar.redundancyVars), RedundancyMap)
  //   val var5BodyRM: SoP = emptySoP()
  //   val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

  //   val var6HeadUS: Access = Access("A".uniqueName,  Seq("x1".toVar), UniqueSet)
  //   val var6BodyUS: SoP = dim6.toSoP
  //   val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

  //   val var6HeadRM: Access = Access("A".redundancyName,  Seq("x1".toVar, "x1".toVar.redundancyVars), RedundancyMap)
  //   val var6BodyRM: SoP = emptySoP()
  //   val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

  //   val var7HeadUS: Access = Access("D".uniqueName,  Seq("t0".toVar), UniqueSet)
  //   val var7BodyUS: SoP = dim7.toSoP
  //   val var7US: Rule = Rule(var7HeadUS, var7BodyUS)

  //   val var7HeadRM: Access = Access("D".redundancyName,  Seq("t0".toVar, "t0".toVar.redundancyVars), RedundancyMap)
  //   val var7BodyRM: SoP = emptySoP()
  //   val var7RM: Rule = Rule(var7HeadRM, var7BodyRM)

  //   val var8HeadUS: Access = Access("C".uniqueName,  Seq("z1".toVar), UniqueSet)
  //   val var8BodyUS: SoP = dim8.toSoP
  //   val var8US: Rule = Rule(var8HeadUS, var8BodyUS)
    
  //   val var8HeadRM: Access = Access("C".redundancyName,  Seq("z1".toVar, "z1".toVar.redundancyVars), RedundancyMap)
  //   val var8BodyRM: SoP = emptySoP()
  //   val var8RM: Rule = Rule(var8HeadRM, var8BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var4 -> var4US, var5 -> var5US, var6 -> var6US, var7 -> var7US, var8 -> var8US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var4 -> var4RM, var5 -> var5RM, var6 -> var6RM, var7 -> var7RM, var8 -> var8RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // a bunch of self mults
  // def test16(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x0".toVar, "y0".toVar, "y1".toVar, "y2".toVar, "x1".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y0".toVar), Tensor)
  //   val var3: Access = Access("B",  Seq("y1".toVar), Tensor)
  //   val var5: Access = Access("B",  Seq("y2".toVar), Tensor)
  //   val var6: Access = Access("A",  Seq("x1".toVar), Tensor)

  //   val prods: Prod = Prod(Seq(var1, var2, var3, var5, var6))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("m".toVar))
  //   val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
  //   val dim6: DimInfo = DimInfo(var6, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3, dim5, dim6)

  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq("x0".toVar), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq("x0".toVar, "x0".toVar.redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq("y0".toVar), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)
    
  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq("y0".toVar, "y0".toVar.redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access("B".uniqueName,  Seq("y1".toVar), UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
  //   val var3HeadRM: Access = Access("B".redundancyName,  Seq("y1".toVar, "y1".toVar.redundancyVars), RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val var5HeadUS: Access = Access("B".uniqueName,  Seq("y2".toVar), UniqueSet)
  //   val var5BodyUS: SoP = dim5.toSoP
  //   val var5US: Rule = Rule(var5HeadUS, var5BodyUS)
    
  //   val var5HeadRM: Access = Access("B".redundancyName,  Seq("y2".toVar, "y2".toVar.redundancyVars), RedundancyMap)
  //   val var5BodyRM: SoP = emptySoP()
  //   val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

  //   val var6HeadUS: Access = Access("A".uniqueName,  Seq("x1".toVar), UniqueSet)
  //   val var6BodyUS: SoP = dim6.toSoP
  //   val var6US: Rule = Rule(var6HeadUS, var6BodyUS)

  //   val var6HeadRM: Access = Access("A".redundancyName,  Seq("x1".toVar, "x1".toVar.redundancyVars), RedundancyMap)
  //   val var6BodyRM: SoP = emptySoP()
  //   val var6RM: Rule = Rule(var6HeadRM, var6BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US, var5 -> var5US, var6 -> var6US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM, var5 -> var5RM, var6 -> var6RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Vector Append test - checked
  // def test17(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x".toVar), Tensor)
  //   // val var1: Access = Access("A",  Seq("x".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y".toVar), Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("-", "x".toVar, "n".toVar), "y".toVar)
  //   // val prods1: Prod = Prod(Seq(var1))
  //   val prods2: Prod = Prod(Seq(var2, var3))
  //   // val body: SoP = SoP(Seq(prods1, prods2))
  //   val body: SoP = SoP(Seq(prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   // val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   // val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)
  //   val dimInfo: Seq[DimInfo] = Seq(dim2)


  //   // val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x")), UniqueSet)
  //   // val var1BodyUS: SoP = dim1.toSoP
  //   // val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   // val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("x").redundancyVars), RedundancyMap)
  //   // val var1BodyRM: SoP = emptySoP()
  //   // val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y"), Variable("y").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   // val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   // val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
  //   val uniqueSets: Map[Exp, Rule] = Map(var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var2 -> var2RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // same computation test - checked
  // def test18(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq("x0".toVar, "x1".toVar), Tensor)
  //   val var1: Access = Access("A",  Seq("x0".toVar), Tensor)
  //   val var2: Access = Access("B",  Seq("y1".toVar), Tensor)
  //   val var3: Comparison = Comparison("=", Arithmetic("-", "x1".toVar, "n".toVar), "y1".toVar)
  //   val var4: Access = Access("A",  Seq("x1".toVar), Tensor)
  //   val var5: Access = Access("B",  Seq("y0".toVar), Tensor)
  //   val var6: Comparison = Comparison("=", Arithmetic("-", "x0".toVar, "n".toVar), "y0".toVar)

  //   val prods1: Prod = Prod(Seq(var1, var2, var3))
  //   val prods2: Prod = Prod(Seq(var4, var5, var6))
  //   val body: SoP = SoP(Seq(prods1, prods2))
  //   // val body: SoP = SoP(Seq(prods1))
  //   // val body: SoP = SoP(Seq(prods2))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar))
  //   val dim4: DimInfo = DimInfo(var4, Seq("n".toVar))
  //   val dim5: DimInfo = DimInfo(var5, Seq("m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim4, dim5)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x0")), UniqueSet)
  //   val var1BodyUS: SoP = dim1.toSoP
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x0"), Variable("x0").redundancyVars), RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y1")), UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y1"), Variable("y1").redundancyVars), RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var4HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x1")), UniqueSet)
  //   val var4BodyUS: SoP = dim4.toSoP
  //   val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

  //   val var4HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x1"), Variable("x1").redundancyVars), RedundancyMap)
  //   val var4BodyRM: SoP = emptySoP()
  //   val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

  //   val var5HeadUS: Access = Access("B".uniqueName,  Seq(Variable("y0")), UniqueSet)
  //   val var5BodyUS: SoP = dim5.toSoP
  //   val var5US: Rule = Rule(var5HeadUS, var5BodyUS)

  //   val var5HeadRM: Access = Access("B".redundancyName,  Seq(Variable("y0"), Variable("y0").redundancyVars), RedundancyMap)
  //   val var5BodyRM: SoP = emptySoP()
  //   val var5RM: Rule = Rule(var5HeadRM, var5BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var4 -> var4US, var5 -> var5US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var4 -> var4RM, var5 -> var5RM)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // testing input datalayout 
  // def test19(): (Rule, (Rule, Rule, DimInfo)) = {
  //   val head: Access = Access("M", Seq(Variable("x"), Variable("y")), Tensor)
  //   val var1: Access = Access("A",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val var2: Access = Access("B",  Seq(Variable("x"), Variable("y")), Tensor)
  //   val prods: Prod = Prod(Seq(var1, var2))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("m".toVar, "n".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("m".toVar, "n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


  //   val var1HeadUS: Access = Access("A".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var1ExpUS: Exp = Comparison("<=", Variable("x"), Variable("y"))
  //   val var1ProdsUS: Prod = Prod(Seq(var1ExpUS))
  //   val var1BodyUS: SoP = multSoP(Seq(SoP(Seq(var1ProdsUS)), dim1.toSoP))
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access("A".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var1ExpRM1: Exp = Comparison(">", Variable("x"), Variable("y"))
  //   val var1ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var1ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3))
  //   val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var1DL = (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "n".toVar), x(1)))

  //   val var2HeadUS: Access = Access("B".uniqueName,  Seq(Variable("x"), Variable("y")), UniqueSet)
  //   val var2ExpUS: Exp = Comparison(">=", Variable("x"), Variable("y"))
  //   val var2ProdsUS: Prod = Prod(Seq(var2ExpUS))
  //   val var2BodyUS: SoP = multSoP(Seq(SoP(Seq(var2ProdsUS)), dim2.toSoP))
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access("B".redundancyName,  Seq(Variable("x"), Variable("y"), Variable("x").redundancyVars, Variable("y").redundancyVars), RedundancyMap)
  //   val var2ExpRM1: Exp = Comparison("<", Variable("x"), Variable("y"))
  //   val var2ExpRM2: Exp = Comparison("=", Variable("x").redundancyVars, Variable("y"))
  //   val var2ExpRM3: Exp = Comparison("=", Variable("y").redundancyVars, Variable("x"))
  //   val var2ProdsRM: Prod = Prod(Seq(var2ExpRM1, var2ExpRM2, var2ExpRM3))
  //   val var2BodyRM: SoP = multSoP(Seq(SoP(Seq(var2ProdsRM)), dim2.toSoP))
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var2DL = (x: Seq[Variable]) => x

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
  //   val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = Map(var1 -> var1DL, var2 -> var2DL)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap))

  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // def multiProg1() = {
  //   val head1: Access = Access("T", Seq("x".toVar), Tensor)
  //   val var11: Access = Access("T1",  Seq("x".toVar), Tensor)
  //   val var12: Access = Access("T2",  Seq("x".toVar), Tensor)

  //   val head2: Access = Access("M",  Seq("x".toVar), Tensor)
  //   val var21: Access = Access("U",  Seq("x".toVar), Tensor)

  //   val prods11: Prod = Prod(Seq(var11))
  //   val prods12: Prod = Prod(Seq(var12))
  //   val body1: SoP = SoP(Seq(prods11, prods12))
  //   val tensorComputation1: Rule = Rule(head1, body1)

  //   val prods2: Prod = Prod(Seq(head1, var21))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val tensorComputation2: Rule = Rule(head2, body2)

  //   val tensorComputation: Seq[Rule] = Seq(tensorComputation1, tensorComputation2)

  //   val dim11: DimInfo = DimInfo(var11, Seq("n".toVar))
  //   val dim12: DimInfo = DimInfo(var12, Seq("n".toVar))
  //   val dim21: DimInfo = DimInfo(var21, Seq("n".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim11, dim12, dim21)

  //   val var11HeadUS: Access = Access("T1".uniqueName,  Seq("x".toVar), UniqueSet)
  //   val var11BodyUS: SoP = dim11.toSoP
  //   val var11US: Rule = Rule(var11HeadUS, var11BodyUS)

  //   val var11HeadRM: Access = Access("T1".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
  //   val var11BodyRM: SoP = emptySoP()
  //   val var11RM: Rule = Rule(var11HeadRM, var11BodyRM)

  //   val var12HeadUS: Access = Access("T2".uniqueName,  Seq("x".toVar), UniqueSet)
  //   val var12BodyUS: SoP = dim12.toSoP
  //   val var12US: Rule = Rule(var12HeadUS, var12BodyUS)

  //   val var12HeadRM: Access = Access("T2".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
  //   val var12BodyRM: SoP = emptySoP()
  //   val var12RM: Rule = Rule(var12HeadRM, var12BodyRM)

  //   val var21HeadUS: Access = Access("U".uniqueName,  Seq("x".toVar), UniqueSet)
  //   val var21BodyUS: SoP = dim21.toSoP
  //   val var21US: Rule = Rule(var21HeadUS, var21BodyUS)

  //   val var21HeadRM: Access = Access("U".redundancyName,  Seq("x".toVar, "x".toVar.redundancyVars), RedundancyMap)
  //   val var21BodyRM: SoP = emptySoP()
  //   val var21RM: Rule = Rule(var21HeadRM, var21BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var11 -> var11US, var12 -> var12US, var21 -> var21US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var11 -> var11RM, var12 -> var12RM, var21 -> var21RM)

  //   println(codeGenProgram(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // def multiProg2() = {
  //   val head1: Access = Access("T", Seq("x".toVar), Tensor)
  //   val var11: Access = Access("T1",  Seq("x".toVar, "y".toVar), Tensor)

  //   val head2: Access = Access("M",  Seq("x".toVar), Tensor)

  //   val prods1: Prod = Prod(Seq(var11))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val tensorComputation1: Rule = Rule(head1, body1)

  //   val prods2: Prod = Prod(Seq(head1, head1))
  //   val body2: SoP = SoP(Seq(prods2))
  //   val tensorComputation2: Rule = Rule(head2, body2)

  //   val tensorComputation: Seq[Rule] = Seq(tensorComputation1, tensorComputation2)

  //   val dim11: DimInfo = DimInfo(var11, Seq("n".toVar, "m".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim11)

  //   val var11HeadUS: Access = Access("T1".uniqueName,  Seq("x".toVar, "y".toVar), UniqueSet)
  //   val var11BodyUS: SoP = dim11.toSoP
  //   val var11US: Rule = Rule(var11HeadUS, var11BodyUS)

  //   val var11HeadRM: Access = Access("T1".redundancyName,  Seq("x".toVar, "y".toVar, "x".toVar.redundancyVars, "y".toVar.redundancyVars), RedundancyMap)
  //   val var11BodyRM: SoP = emptySoP()
  //   val var11RM: Rule = Rule(var11HeadRM, var11BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var11 -> var11US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var11 -> var11RM)

  //   println(codeGenProgram(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Any degree self-product -- degree 3 to degree 6 tested and seems correct -- for degree 5 and 6 I can't check actually
  // def selfprodMult(n: Int): (Rule, (Rule, Rule, DimInfo)) = {
  //   val indSeq: Seq[Int] = (0 to n - 1)
  //   val xSeq: Seq[Variable] = indSeq.map(i => s"x$i".toVar)
  //   val head: Access = Access("M", xSeq, Tensor)
  //   val vars: Seq[Access] = xSeq.map(x => Access("A", Seq(x), Tensor))
  //   val prods: Prod = Prod(vars)
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)
  //   val dimInfo: Seq[DimInfo] = vars.map(v => DimInfo(v, Seq("n".toVar)))

  //   val varHeadUS: Seq[Access] = xSeq.map(x => Access("A".uniqueName, Seq(x), UniqueSet)) 
  //   val varBodyUS: Seq[SoP] = dimInfo.map(dim => dim.toSoP)
  //   val varUS: Seq[Rule] = (varHeadUS zip varBodyUS).map{case (head, body) => Rule(head, body)}

  //   val varHeadRM: Seq[Access] = xSeq.map(x => Access("A".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
  //   val varBodyRM: Seq[SoP] = dimInfo.map(dim => emptySoP())
  //   val varRM: Seq[Rule] = (varHeadRM zip varBodyRM).map{case (head, body) => Rule(head, body)}

  //   val uniqueSets: Map[Exp, Rule] = (vars zip varUS).map{case (v, r) => (v -> r)}.toMap
  //   val redundancyMap: Map[Exp, Rule] = (vars zip varRM).map{case (v, r) => (v -> r)}.toMap

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  // // Any degree self-product addition --
  // def selfprodAdd(n: Int): (Rule, (Rule, Rule, DimInfo)) = {
  //   val indSeq1: Seq[Int] = (0 to n - 1)
  //   val xSeq1: Seq[Variable] = indSeq1.map(i => s"x$i".toVar)
  //   val head1: Access = Access("M", xSeq1, Tensor)
  //   val vars1: Seq[Access] = xSeq1.map(x => Access("A", Seq(x), Tensor))
  //   val prods1: Prod = Prod(vars1)
  //   val body1: SoP = SoP(Seq(prods1))
  //   val tensorComputation1: Rule = Rule(head1, body1)
  //   val dimInfo1: Seq[DimInfo] = vars1.map(v => DimInfo(v, Seq("n".toVar)))

  //   val varHeadUS1: Seq[Access] = xSeq1.map(x => Access("A".uniqueName, Seq(x), UniqueSet)) 
  //   val varBodyUS1: Seq[SoP] = dimInfo1.map(dim => dim.toSoP)
  //   val varUS1: Seq[Rule] = (varHeadUS1 zip varBodyUS1).map{case (head, body) => Rule(head, body)}

  //   val varHeadRM1: Seq[Access] = xSeq1.map(x => Access("A".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
  //   val varBodyRM1: Seq[SoP] = dimInfo1.map(dim => emptySoP())
  //   val varRM1: Seq[Rule] = (varHeadRM1 zip varBodyRM1).map{case (head, body) => Rule(head, body)}

  //   val uniqueSets1: Map[Exp, Rule] = (vars1 zip varUS1).map{case (v, r) => (v -> r)}.toMap
  //   val redundancyMap1: Map[Exp, Rule] = (vars1 zip varRM1).map{case (v, r) => (v -> r)}.toMap

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo1, uniqueSets1, redundancyMap1)



  //   val indSeq2: Seq[Int] = (0 to n - 1)
  //   val xSeq2: Seq[Variable] = indSeq2.map(i => s"x$i".toVar)
  //   val head2: Access = Access("N", xSeq2, Tensor)
  //   val vars2: Seq[Access] = xSeq2.map(x => Access("B", Seq(x), Tensor))
  //   val prods2: Prod = Prod(vars2)
  //   val body2: SoP = SoP(Seq(prods2))
  //   val tensorComputation2: Rule = Rule(head2, body2)
  //   val dimInfo2: Seq[DimInfo] = vars2.map(v => DimInfo(v, Seq("n".toVar)))

  //   val varHeadUS2: Seq[Access] = xSeq2.map(x => Access("B".uniqueName, Seq(x), UniqueSet)) 
  //   val varBodyUS2: Seq[SoP] = dimInfo2.map(dim => dim.toSoP)
  //   val varUS2: Seq[Rule] = (varHeadUS2 zip varBodyUS2).map{case (head, body) => Rule(head, body)}

  //   val varHeadRM2: Seq[Access] = xSeq2.map(x => Access("B".redundancyName, Seq(x, x.redundancyVars), UniqueSet)) 
  //   val varBodyRM2: Seq[SoP] = dimInfo2.map(dim => emptySoP())
  //   val varRM2: Seq[Rule] = (varHeadRM2 zip varBodyRM2).map{case (head, body) => Rule(head, body)}

  //   val uniqueSets2: Map[Exp, Rule] = (vars2 zip varUS2).map{case (v, r) => (v -> r)}.toMap
  //   val redundancyMap2: Map[Exp, Rule] = (vars2 zip varRM2).map{case (v, r) => (v -> r)}.toMap

  //   val infer2: (Rule, Rule, DimInfo) = infer(tensorComputation2, dimInfo2, uniqueSets2, redundancyMap2)

  //   val p1: Prod = Prod(Seq(head1))
  //   val p2: Prod = Prod(Seq(head2))
  //   val head: Access = Access("O", xSeq1, Tensor)
  //   val body: SoP = SoP(Seq(p1, p2))
  //   val tensorComputation: Rule = Rule(head, body)
  //   val uniqueSets: Map[Exp, Rule] = Map(head1 -> infer1._1, head2 -> infer2._1)
  //   val redundancyMap: Map[Exp, Rule] = Map(head1 -> infer1._2, head2 -> infer2._2)
  //   val dimInfo: Seq[DimInfo] = dimInfo1 ++ dimInfo2 ++ Seq(infer1._3, infer2._3)

  //   println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  //   (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  // }

  def ttm(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP") = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "l".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar, "Q".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("P".toVar, "Q".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag_p" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "uhc" => {
        val var1ExpUS1: Exp = Comparison("<=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "diag_p" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "Q".toVar), x(2)))
      case "fixed_j" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "Q".toVar), x(2)))
      case "uhc" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", Arithmetic("-", Arithmetic("+", Arithmetic("*", x(0), "N".toVar), x(1)), Arithmetic("/", Arithmetic("*", x(0), Arithmetic("+", x(0), ConstantInt(1))), ConstantInt(2))), "Q".toVar), x(2)))
      case _ => (x: Seq[Variable]) => x
    }

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang)
  }

  def thp(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP") = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val var2: Access = Access("C",  Seq("i".toVar, "j".toVar, "k".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar, "P".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("M".toVar, "N".toVar, "P".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag_p" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "fixed_j" => {
        val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "diag_p" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "P".toVar), x(2)))
      case "fixed_j" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(0), "P".toVar), x(2)))
      case "fixed_i" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(1), "P".toVar), x(2)))
      case _ => (x: Seq[Variable]) => x
    }

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang)
  }

  // def mttkrp(structure: String, mode: Int = 0) = {
  //   val head: Access = Access("A", Seq("i".toVar, "j".toVar), Tensor)
  //   val var1: Access = Access("B",  Seq("i".toVar, "k".toVar, "l".toVar), Tensor)
  //   val var2: Access = Access("C",  Seq("k".toVar, "j".toVar), Tensor)
  //   val var3: Access = Access("D",  Seq("l".toVar, "j".toVar), Tensor)
  //   val head1: Access = Access("E", Seq("i".toVar, "k".toVar, "l".toVar, "j".toVar), Tensor)
    
  //   val prods1: Prod = Prod(Seq(var1, var2))
  //   val body1: SoP = SoP(Seq(prods1))
  //   val tensorComputation1: Rule = Rule(head1, body1)

  //   val prods: Prod = Prod(Seq(head1, var3))
  //   val body: SoP = SoP(Seq(prods))
  //   val tensorComputation: Rule = Rule(head, body)

  //   val dim1: DimInfo = DimInfo(var1, Seq("ni".toVar, "nk".toVar, "nl".toVar))
  //   val dim2: DimInfo = DimInfo(var2, Seq("nk".toVar, "nj".toVar))
  //   val dim3: DimInfo = DimInfo(var3, Seq("nl".toVar, "nj".toVar))
  //   val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


  //   val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
  //   val var1BodyUS: SoP = structure match {
  //     case "fixed_ij" => {
  //       val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
  //       val var1ExpUS2: Exp = Comparison("=", "j".toVar, "J".toVar)
  //       val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
  //       multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //     }
  //     case "fixed_i" => {
  //       val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
  //       val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //       multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //     }
  //     case "fixed_j" => {
  //       val var1ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
  //       val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
  //       multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
  //     }
  //     case _ => dim1.toSoP
  //   } 
  //   val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

  //   val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
  //   val var1BodyRM: SoP = emptySoP()
  //   val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

  //   val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
  //   val var2BodyUS: SoP = dim2.toSoP
  //   val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

  //   val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
  //   val var2BodyRM: SoP = emptySoP()
  //   val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

  //   val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
  //   val var3BodyUS: SoP = dim3.toSoP
  //   val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

  //   val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
  //   val var3BodyRM: SoP = emptySoP()
  //   val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

  //   val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
  //   val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)

  //   val infer1: (Rule, Rule, DimInfo) = infer(tensorComputation1, dimInfo, uniqueSets, redundancyMap)

  //   println(codeGen(tensorComputation1, dimInfo, uniqueSets, redundancyMap))

  //   pprintTest((tensorComputation1, infer1))

  //   val newUniqueSets: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._1), uniqueSets))((v1, v2) => v2)
  //   val newRedundancyMap: Map[Exp, Rule] = mergeMap(Seq(Map[Exp, Rule](head1 -> infer1._2), redundancyMap))((v1, v2) => v2)
  //   val newDimInfo: Seq[DimInfo] = dimInfo :+ infer1._3

  //   if (mode == 0) {
  //     println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap))

  //     (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
  //   } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1)
  // }

  // Chess Pattern is not implemented since it was just a unique set with no computation
  // none of vec(.), //, and || are explained in the paper in mathematical terms + don't know how to implement the code for this example
  // Kronecker product explanation in Fig 7. should have * in it (not +)!
  // pprintTest(test1())
  // pprintTest(test2())
  // pprintTest(test3())
  // pprintTest(test4())
  // pprintTest(test5())
  // pprintTest(test6())
  // pprintTest(test7())
  // pprintTest(test8())
  // pprintTest(test8n())
  // pprintTest(test9())
  // pprintTest(test9n())
  // pprintTest(test10()) // do not test this. It is not a valid test.
  // pprintTest(test11())
  // pprintTest(test12())
  // pprintTest(test13())
  // pprintTest(test13n())
  // pprintTest(test14())
  // pprintTest(test15())
  // pprintTest(test16())
  // pprintTest(test17())
  // pprintTest(test18())
  // pprintTest(selfprodMult(3))
  // pprintTest(selfprodMult(4))
  // pprintTest(selfprodMult(5))
  // pprintTest(selfprodMult(6))
  // pprintTest(selfprodAdd(3))
  // pprintTest(selfprodAdd(4))
  // pprintTest(selfprodAdd(5))
  // pprintTest(selfprodAdd(6))
  // multiProg1()
  // multiProg2()
  // e2eLR()
  // e2ePRk(1)
  // e2ePRk(2)

  // println(e2ePRkWithSkeletone(1))
  // println(e2ePRkWithSkeletone(2))

  // println("TTM:")
  // pprintTest(ttm(""))
  // println("TTM Diagonal (Plane):")
  // pprintTest(ttm("diag_p"))
  // println("TTM: Fixed j")
  // pprintTest(ttm("fixed_j"))
  // println("TTM: Upper Half Cube")
  // pprintTest(ttm("uhc"))

  // println("THP:")
  // pprintTest(thp(""))
  // println("THP Diagonal (Plane):")
  // pprintTest(thp("diag_p"))
  // println("THP: Fixed i")
  // pprintTest(thp("fixed_i"))
  // println("THP: Fixed j")
  // pprintTest(thp("fixed_j"))

  // println("MTTKRP:")
  // pprintTest(mttkrp(""))
  // println("MTTKRP Fixed i,j:")
  // pprintTest(mttkrp("fixed_ij"))
  // println("MTTKRP: Fixed i")
  // pprintTest(mttkrp("fixed_i"))
  // println("MTTKRP: Fixed j")
  // pprintTest(mttkrp("fixed_j"))

  // println("MTTKRP_N:")
  // pprintTest(mttkrp_n(""))
  // println("MTTKRP_N Fixed i,j:")
  // pprintTest(mttkrp_n("fixed_ij"))
  // println("MTTKRP_N: Fixed i")
  // pprintTest(mttkrp_n("fixed_i"))
  // println("MTTKRP_N: Fixed j")
  // pprintTest(mttkrp_n("fixed_j"))


  

  def PR2C() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val allDegs = (2 to 4)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] cont_degree4[i][j];
    }
    delete[] cont_degree2[i];
    delete[] cont_degree3[i];
    delete[] cont_degree4[i];
  }
  delete[] cont_degree2;
  delete[] cont_degree3;
  delete[] cont_degree4;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File("outputs/PR2C.cpp", code)
  }

  def PR3C() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double *****cont_degree5 = new double****[CONT_SZ];
  double ******cont_degree6 = new double*****[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    cont_degree5[i] = new double***[CONT_SZ];
    cont_degree6[i] = new double****[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      cont_degree5[i][j] = new double**[CONT_SZ];
      cont_degree6[i][j] = new double***[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        cont_degree5[i][j][k] = new double*[CONT_SZ];
        cont_degree6[i][j][k] = new double**[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          cont_degree5[i][j][k][l] = new double[CONT_SZ];
          cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          for (int p = 0; p < CONT_SZ; p++) {
            cont_degree5[i][j][k][l][p] = 0;
            cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            for (int q = 0; q < CONT_SZ; q++) {
              cont_degree6[i][j][k][l][p][q] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
      cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val allDegs = (2 to 6)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree5[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree6[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
      for (int j = 0; j < CONT_SZ; j++) {
          for (int k = 0; k < CONT_SZ; k++) {
              for (int l = 0; l < CONT_SZ; l++) {
                  for (int p = 0; p < CONT_SZ; p++) {
                      delete[] cont_degree6[i][j][k][l][p];
                  }
                  delete[] cont_degree5[i][j][k][l];
                  delete[] cont_degree6[i][j][k][l];
              }
              delete[] cont_degree4[i][j][k];
              delete[] cont_degree5[i][j][k];
              delete[] cont_degree6[i][j][k];
          }
          delete[] cont_degree3[i][j];
          delete[] cont_degree4[i][j];
          delete[] cont_degree5[i][j];
          delete[] cont_degree6[i][j];
      }
      delete[] cont_degree2[i];
      delete[] cont_degree3[i];
      delete[] cont_degree4[i];
      delete[] cont_degree5[i];
      delete[] cont_degree6[i];
  }
  delete[] cont_degree2;
  delete[] cont_degree3;
  delete[] cont_degree4;
  delete[] cont_degree5;
  delete[] cont_degree6;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File("outputs/PR3C.cpp", code)
  }


  def LRA() = {
    val c1 =
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 1
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, other_const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other_" + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=other_const_compressionMap)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    delete[] cont_degree2[i];
    delete[] other_cont_degree2[i];
    delete[] r_cont_degree2[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/LRA.cpp", code)
  }

  def PR2A() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ***other_cont_degree3 = new double**[CONT_SZ];
  double ***r_cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double ****other_cont_degree4 = new double***[CONT_SZ];
  double ****r_cont_degree4 = new double***[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    other_cont_degree3[i] = new double*[CONT_SZ];
    r_cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    other_cont_degree4[i] = new double**[CONT_SZ];
    r_cont_degree4[i] = new double**[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      other_cont_degree3[i][j] = new double[CONT_SZ];
      r_cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      other_cont_degree4[i][j] = new double*[CONT_SZ];
      r_cont_degree4[i][j] = new double*[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 2
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, other_const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip 
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other_" + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
        delete[] other_cont_degree4[i][j][k];
        delete[] r_cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] other_cont_degree3[i][j];
      delete[] r_cont_degree3[i][j];
      delete[] cont_degree4[i][j];
      delete[] other_cont_degree4[i][j];
      delete[] r_cont_degree4[i][j];
    }
    delete[] cont_degree2[i];
    delete[] other_cont_degree2[i];
    delete[] r_cont_degree2[i];
    delete[] cont_degree3[i];
    delete[] other_cont_degree3[i];
    delete[] r_cont_degree3[i];
    delete[] cont_degree4[i];
    delete[] other_cont_degree4[i];
    delete[] r_cont_degree4[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  delete[] cont_degree3;
  delete[] other_cont_degree3;
  delete[] r_cont_degree3;
  delete[] cont_degree4;
  delete[] other_cont_degree4;
  delete[] r_cont_degree4;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/PR2A.cpp", code)
  }

  def PR3A() = {
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ***other_cont_degree3 = new double**[CONT_SZ];
  double ***r_cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double ****other_cont_degree4 = new double***[CONT_SZ];
  double ****r_cont_degree4 = new double***[CONT_SZ];
  double *****cont_degree5 = new double****[CONT_SZ];
  double *****other_cont_degree5 = new double****[CONT_SZ];
  double *****r_cont_degree5 = new double****[CONT_SZ];
  double ******cont_degree6 = new double*****[CONT_SZ];
  double ******other_cont_degree6 = new double*****[CONT_SZ];
  double ******r_cont_degree6 = new double*****[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    other_cont_degree3[i] = new double*[CONT_SZ];
    r_cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    other_cont_degree4[i] = new double**[CONT_SZ];
    r_cont_degree4[i] = new double**[CONT_SZ];
    cont_degree5[i] = new double***[CONT_SZ];
    other_cont_degree5[i] = new double***[CONT_SZ];
    r_cont_degree5[i] = new double***[CONT_SZ];
    cont_degree6[i] = new double****[CONT_SZ];
    other_cont_degree6[i] = new double****[CONT_SZ];
    r_cont_degree6[i] = new double****[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      other_cont_degree3[i][j] = new double[CONT_SZ];
      r_cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      other_cont_degree4[i][j] = new double*[CONT_SZ];
      r_cont_degree4[i][j] = new double*[CONT_SZ];
      cont_degree5[i][j] = new double**[CONT_SZ];
      other_cont_degree5[i][j] = new double**[CONT_SZ];
      r_cont_degree5[i][j] = new double**[CONT_SZ];
      cont_degree6[i][j] = new double***[CONT_SZ];
      other_cont_degree6[i][j] = new double***[CONT_SZ];
      r_cont_degree6[i][j] = new double***[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        cont_degree5[i][j][k] = new double*[CONT_SZ];
        other_cont_degree5[i][j][k] = new double*[CONT_SZ];
        r_cont_degree5[i][j][k] = new double*[CONT_SZ];
        cont_degree6[i][j][k] = new double**[CONT_SZ];
        other_cont_degree6[i][j][k] = new double**[CONT_SZ];
        r_cont_degree6[i][j][k] = new double**[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
          cont_degree5[i][j][k][l] = new double[CONT_SZ];
          other_cont_degree5[i][j][k][l] = new double[CONT_SZ];
          r_cont_degree5[i][j][k][l] = new double[CONT_SZ];
          cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          other_cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          r_cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          for (int p = 0; p < CONT_SZ; p++) {
            cont_degree5[i][j][k][l][p] = 0;
            other_cont_degree5[i][j][k][l][p] = 0;
            r_cont_degree5[i][j][k][l][p] = 0;
            cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            other_cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            r_cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            for (int q = 0; q < CONT_SZ; q++) {
              cont_degree6[i][j][k][l][p][q] = 0;
              other_cont_degree6[i][j][k][l][p][q] = 0;
              r_cont_degree6[i][j][k][l][p][q] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
      cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
      other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 3
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, other_const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addc2: Map[Exp, Rule] = const_compressionMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), 
        SoP((getOnlyComparisonSoP(v.body).prods zip
        getNoComparisonSoP(v.body).prods.foldLeft(Seq.empty[Prod])((acc, prod) => 
        acc :+ Prod(prod.exps.map(e => Access("other_" + e.asInstanceOf[Access].name, e.asInstanceOf[Access].vars, e.asInstanceOf[Access].kind))))).
        map{case (e1, e2) => prodTimesProd(e1, e2)})))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val addc: Map[Exp, Rule] = mergeMap(Seq(const_compressionMap, addc2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, peq_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm, addc))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=other_const_compressionMap)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree5[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree6[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
      for (int j = 0; j < CONT_SZ; j++) {
          for (int k = 0; k < CONT_SZ; k++) {
              for (int l = 0; l < CONT_SZ; l++) {
                  for (int p = 0; p < CONT_SZ; p++) {
                      delete[] cont_degree6[i][j][k][l][p];
                      delete[] other_cont_degree6[i][j][k][l][p];
                      delete[] r_cont_degree6[i][j][k][l][p];
                  }
                  delete[] cont_degree5[i][j][k][l];
                  delete[] other_cont_degree5[i][j][k][l];
                  delete[] r_cont_degree5[i][j][k][l];
                  delete[] cont_degree6[i][j][k][l];
                  delete[] other_cont_degree6[i][j][k][l];
                  delete[] r_cont_degree6[i][j][k][l];
              }
              delete[] cont_degree4[i][j][k];
              delete[] other_cont_degree4[i][j][k];
              delete[] r_cont_degree4[i][j][k];
              delete[] cont_degree5[i][j][k];
              delete[] other_cont_degree5[i][j][k];
              delete[] r_cont_degree5[i][j][k];
              delete[] cont_degree6[i][j][k];
              delete[] other_cont_degree6[i][j][k];
              delete[] r_cont_degree6[i][j][k];
          }
          delete[] cont_degree3[i][j];
          delete[] other_cont_degree3[i][j];
          delete[] r_cont_degree3[i][j];
          delete[] cont_degree4[i][j];
          delete[] other_cont_degree4[i][j];
          delete[] r_cont_degree4[i][j];
          delete[] cont_degree5[i][j];
          delete[] other_cont_degree5[i][j];
          delete[] r_cont_degree5[i][j];
          delete[] cont_degree6[i][j];
          delete[] other_cont_degree6[i][j];
          delete[] r_cont_degree6[i][j];
      }
      delete[] cont_degree2[i];
      delete[] other_cont_degree2[i];
      delete[] r_cont_degree2[i];
      delete[] cont_degree3[i];
      delete[] other_cont_degree3[i];
      delete[] r_cont_degree3[i];
      delete[] cont_degree4[i];
      delete[] other_cont_degree4[i];
      delete[] r_cont_degree4[i];
      delete[] cont_degree5[i];
      delete[] other_cont_degree5[i];
      delete[] r_cont_degree5[i];
      delete[] cont_degree6[i];
      delete[] other_cont_degree6[i];
      delete[] r_cont_degree6[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  delete[] cont_degree3;
  delete[] other_cont_degree3;
  delete[] r_cont_degree3;
  delete[] cont_degree4;
  delete[] other_cont_degree4;
  delete[] r_cont_degree4;
  delete[] cont_degree5;
  delete[] other_cont_degree5;
  delete[] r_cont_degree5;
  delete[] cont_degree6;
  delete[] other_cont_degree6;
  delete[] r_cont_degree6;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/PR3A.cpp", code)
  }


  def TTM(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "TTM_DP" else if (structure == "fixed_j") "TTM_J" else if (structure == "uhc") "TTM_UT" else "TTM"
    val outName = if(sparse) s"${outName1}_Sparse" else outName1
    val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]),N = atoi(argv[2]), Q = atoi(argv[3]), P = atoi(argv[4]);
    ${if (structure == "fixed_j") "int J = atoi(argv[5]);" else ""}
    
     /*
        M : third dimension in B, A (i)    
        N : rows in B, A (j)
        Q : columns in B, columns in C (l)

        P : rows  in C (k)

        A(i, j,k) = B(i,j,l),C(k,l)
    */

    ${if (sparse) {
s"""
    ${if (structure == "diag_p" || structure == "fixed_j") "double *B = new double[M * Q];" else if (structure == "uhc") "double *B = new double[((N + 1) * N / 2 - (N - M + 1) * (N - M) / 2) * Q];"}
    for (size_t i = 0; i < M; ++i) {
      ${if (structure == "uhc") "for (size_t j = i; j < N; ++j) {" else ""}
        for(size_t l = 0; l < Q; ++l) {
          ${if (structure == "diag_p" || structure == "fixed_j") "B[i * Q + l]" else if (structure == "uhc") "B[(i * N + j - ((i + 1) * i / 2)) * Q + l]"} = (double) (rand() % 1000000) / 1e6;
        }
      ${if (structure == "uhc") "}" else ""}
    }
"""
    } else {
s"""
    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            B[i][j] = new double[Q];
            for(size_t l =0; l< Q; ++l){
                ${if (structure == "diag_p") "if (i == j){" else if (structure == "fixed_j") "if (j == J){" else if (structure == "uhc") "if (i <= j){" else ""}
                    B[i][j][l] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][j][l] = (double) 0;
                }
            }
        }
    }
"""      
    }}

    double  **C = new double*[P];
    for(size_t k = 0; k < P; ++k){
        C[k] = new double[Q];
        for(size_t l = 0; l < Q; ++l){
            C[k][l] = (double) (rand() % 1000000) / 1e6;
        }
    }


    double  ***A = new double**[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            A[i][j] = new double[P];
            for(size_t k =0; k < P; ++k){
                A[i][j][k] = (double) 0;
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = ttm(structure, 1, sparse)
    val c3 =
s"""
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][N - 1][P - 1] << "\\n";
    cout << time;
    ${if (sparse) "" else {
s"""
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
"""
    }}
    delete[] B;

    for(size_t k = 0; k < P; ++k){
        delete[] C[k];
    }
    delete[] C;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
    
    return 0; 
}
"""

    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def THP(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "THP_DP" else if (structure == "fixed_i") "THP_I" else if (structure == "fixed_j") "THP_J" else "THP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = 
s"""
#include <array>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    
    srand(0);
    int M = atoi(argv[1]), N = atoi(argv[2]), P = atoi(argv[3]);
    ${if (structure == "fixed_i") "int I = atoi(argv[4]);" else if (structure == "fixed_j") "int J = atoi(argv[4]);" else ""}
    
    /*
        M : third dimension (i) in B, C, A
        N : first dimension (j) in B, C, A
        P : second dimension (k) in B, C, A

        A(i,j,k) = B(i,j,k),C(i,j,k)
    */

    ${if (sparse) {
s"""
    double *B = new double${if (structure == "diag_p" || structure == "fixed_j") "[M * P];" else if (structure == "fixed_i") "[N * P];"}
    ${if (structure == "diag_p" || structure == "fixed_j") "for (size_t i = 0; i < M; ++i){" else ""}
      ${if (structure == "diag_p" || structure == "fixed_j") "" else "for(size_t j = 0; j < N; ++j){"}
        for(size_t k =0; k< P; ++k){
          ${if (structure == "diag_p" || structure == "fixed_j") "B[i * P + k]" else "B[j * P + k]"} = (double) (rand() % 1000000) / 1e6;
        }
      }
"""
    } else {
s"""
    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            B[i][j] = new double[P];
            for(size_t k =0; k< P; ++k){
                ${if (structure == "diag_p") "if (i == j){" else if (structure == "fixed_i") "if (i == I){" else if (structure == "fixed_j") "if (j == J){" else "THP"}
                    B[i][j][k] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][j][k] = (double) 0;
                }
            }
        }
    }
"""
    }}

    double  ***C = new double**[M];
    for(size_t i = 0; i < M; ++i){
        C[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            C[i][j] = new double[P];
            for(size_t k =0; k< P; ++k){
                C[i][j][k] = (double) (rand() % 1000000) / 1e6;
            }
        }
    }

    double  ***A = new double**[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            A[i][j] = new double[P];
            for(size_t k =0; k < P; ++k){
                (double) 0;
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = thp(structure, 1, sparse)
    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;
    
    cerr << A[M - 1][N - 1][P - 1] << "\\n";
    cout<<time;

    ${if (sparse) "" else {
s"""
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
"""
    }}
    delete[] B;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] C[i][j];
        }
        delete[] C[i];
    }
    delete[] C;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;

    return 0; 
}
"""

    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }


  def oneDConvolution(mode: Int = 0, sparse: Boolean = false) = {
    val head: Access = Access("Y", Seq("i".toVar), Tensor)
    val var1: Access = Access("H",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("X",  Seq("j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq(Arithmetic("-", Arithmetic("+", "M".toVar, "N".toVar), ConstantInt(1)), "N".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1ExpUS1: Exp = Comparison(">", "M".toVar, "i".toVar)
    val var1ExpUS2: Exp = Comparison("=", ConstantInt(0), "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
    val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1ExpRM1: Exp = Comparison("<=", ConstantInt(1), "j".toVar)
    val var1ExpRM2: Exp = Comparison("<=", "j".toVar, "i".toVar)
    val var1ExpRM3: Exp = Comparison(">", Arithmetic("+", "j".toVar, "M".toVar), "i".toVar)
    val var1ExpRM4: Exp = Comparison("=", ConstantInt(0), "j".toVar.redundancyVars)
    val var1ExpRM5: Exp = Comparison("=", Arithmetic("-", "i".toVar, "j".toVar), "i".toVar.redundancyVars)
    val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3, var1ExpRM4, var1ExpRM5))
    val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(x(0))

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()
    
    println(infer(tensorComputation, dimInfo, uniqueSets, redundancyMap)._1.prettyFormat)

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, varReverse=true))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, varReverse=true)
  }

  def ODC(sparse: Boolean) = {
    val outName1 = "ODC"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
        val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]), N = atoi(argv[2]);

    ${if (sparse) 
s"""
    double *H = new double[M];
    for(size_t i = 0; i < M; ++i) {
        H[i] = (double) (rand() % 1000000) / 1e6;
    }
""" 
    else {
s"""
    double **H = new double*[M + N - 1];
    for(size_t i = 0; i < M + N - 1; ++i){
        H[i] = new double[N];
        for(size_t j = 0; j < N; ++j){
            if (j == 0 && i < M)
                H[i][j] = (double) (rand() % 1000000) / 1e6;
            else if (j <= i && i < M + j) 
                H[i][j] = H[i - j][0];
            else 
                H[i][j] = (double) 0;
        }
    }
"""
    }}

    double *X = new double[N];
    for(size_t j = 0; j < N; ++j){
        X[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *Y = new double[M + N - 1];
    for (size_t i = 0; i < M + N - 1; ++i) {
        Y[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = oneDConvolution(1, sparse)

    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << Y[M + N - 2] << "\\n";
    cout<<time;

    ${if (sparse) "" else 
s"""
    for(size_t i = 0; i < M + N - 1; ++i){
        delete[] H[i];
    }
""" }
    delete[] H;
    delete[] X;
    delete[] Y;
    return 0;
}
"""

    val code = s"$c1$c2$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def oneDCircularConvolution(mode: Int = 0, sparse: Boolean = false) = {
    val head: Access = Access("Y", Seq("i".toVar), Tensor)
    val var1: Access = Access("H",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("X",  Seq("j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("N".toVar, "N".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1ExpUS1: Exp = Comparison(">", "M".toVar, "i".toVar)
    val var1ExpUS2: Exp = Comparison("=", ConstantInt(0), "j".toVar)
    val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1, var1ExpUS2))
    val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1ExpRM1: Exp = Comparison("<=", ConstantInt(1), "j".toVar)
    val var1ExpRM2: Exp = Comparison("<=", "j".toVar, "s".toVar)
    val var1ExpRM3: Exp = Comparison(">", Arithmetic("+", "j".toVar, "M".toVar), "s".toVar)
    val var1ExpRM4: Exp = Comparison("=", Arithmetic("%", "s".toVar, "N".toVar), "i".toVar)
    val var1ExpRM5: Exp = Comparison("=", ConstantInt(0), "j".toVar.redundancyVars)
    val var1ExpRM6: Exp = Comparison("=", Arithmetic("-", "s".toVar, "j".toVar), "i".toVar.redundancyVars)
    val var1ProdsRM: Prod = Prod(Seq(var1ExpRM1, var1ExpRM2, var1ExpRM3, var1ExpRM4, var1ExpRM5, var1ExpRM6))
    val var1BodyRM: SoP = multSoP(Seq(SoP(Seq(var1ProdsRM)), dim1.toSoP))
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(Arithmetic("-", "s".toVar, x(1)))

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, varReverse=true))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, varReverse=true)
  }

  // 1D circular convolution
  def ODCC(sparse: Boolean) = {
    val outName1 = "ODCC"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
        val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]), N = atoi(argv[2]);

    ${if (sparse) 
s"""
    double *H = new double[M];
    for(size_t i = 0; i < M; ++i) {
        H[i] = (double) (rand() % 1000000) / 1e6;
    }
""" 
    else {
s"""
    double **H = new double*[N];
    for (size_t i = 0; i < N; ++i) {
        H[i] = new double[N];
        for (size_t j = 0; j < N; ++j) {
            H[i][j] = (double) 0;
        }
    }
    for(size_t i = 0; i < M; ++i){
        H[i][0] = (double) (rand() % 1000000) / 1e6;
    }
    for (size_t j = 1; j < N; ++j) {
        for (size_t s = j; s < j + M; ++s) {
            size_t i = s % N;
            H[i][j] = H[s - j][0];
        }
    }
"""
    }}

    double *X = new double[N];
    for(size_t j = 0; j < N; ++j){
        X[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *Y = new double[N];
    for (size_t i = 0; i < N; ++i) {
        Y[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = oneDCircularConvolution(1, sparse)

    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << Y[N - 1] << "\\n";
    cout<<time;

    ${if (sparse) "" else 
s"""
    for(size_t i = 0; i < N; ++i){
        delete[] H[i];
    }
""" }
    delete[] H;
    delete[] X;
    delete[] Y;
    return 0;
}
"""

    val code = s"$c1$c2$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def populationGrowthLeslieMatrix(mode: Int = 0, sparse: Boolean = false) = {
    val head: Access = Access("M", Seq("i".toVar), Tensor)
    val var1: Access = Access("L",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("N",  Seq("j".toVar), Tensor)
    val var3: Access = Access("L1",  Seq("i".toVar, "j".toVar), Tensor)
    val var4: Access = Access("L2",  Seq("i".toVar, "j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2))
    val prods1: Prod = Prod(Seq(var3, var2))
    val prods2: Prod = Prod(Seq(var4, var2))
    val body: SoP = if (sparse) SoP(Seq(prods1, prods2)) else SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("W".toVar, "W".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("W".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("W".toVar, "W".toVar))
    val dim4: DimInfo = DimInfo(var4, Seq("W".toVar, "W".toVar))
    val dimInfo: Seq[DimInfo] = if (sparse) Seq(dim2, dim3, dim4) else Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1ExpUS1: Exp = Comparison("=", ConstantInt(0), "i".toVar)
    val var1ProdsUS1: Prod = Prod(Seq(var1ExpUS1))
    val var1ExpUS2: Exp = Comparison("<=", ConstantInt(1), "i".toVar)
    val var1ExpUS3: Exp = Comparison("=", Arithmetic("-", "i".toVar, ConstantInt(1)), "j".toVar)
    val var1ProdsUS2: Prod = Prod(Seq(var1ExpUS2, var1ExpUS3))
    val var1BodyUS: SoP = multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS1, var1ProdsUS2))))
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
    val var3ExpUS1: Exp = Comparison("=", ConstantInt(0), "i".toVar)
    val var3ProdsUS1: SoP = SoP(Seq(Prod(Seq(var3ExpUS1))))
    val var3BodyUS: SoP = multSoP(Seq(dim3.toSoP, var3ProdsUS1))
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)
    
    val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var3DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(x(0))

    val var4HeadUS: Access = Access(var4.name.uniqueName, var4.vars, UniqueSet)
    val var4ExpUS1: Exp = Comparison("<=", ConstantInt(1), "i".toVar)
    val var4ExpUS2: Exp = Comparison("=", Arithmetic("-", "i".toVar, ConstantInt(1)), "j".toVar)
    val var4ProdsUS1: SoP = SoP(Seq(Prod(Seq(var4ExpUS1, var4ExpUS2))))
    val var4BodyUS: SoP = multSoP(Seq(dim4.toSoP, var4ProdsUS1))
    val var4US: Rule = Rule(var4HeadUS, var4BodyUS)

    val var4HeadRM: Access = Access(var4.name.redundancyName, var4.vars.redundancyVarsInplace, RedundancyMap)
    val var4BodyRM: SoP = emptySoP()
    val var4RM: Rule = Rule(var4HeadRM, var4BodyRM)

    val var4DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(x(1))

    val uniqueSets: Map[Exp, Rule] = if (sparse) Map(var2 -> var2US, var3 -> var3US, var4 -> var4US) else Map(var1 -> var1US, var2 -> var2US)
    val redundancyMap: Map[Exp, Rule] = if (sparse) Map(var2 -> var2RM, var3 -> var3RM, var4 -> var4RM) else Map(var1 -> var1RM, var2 -> var2RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var3 -> var3DL, var4 -> var4DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap)
  }

  def PGLM(sparse: Boolean) = {
    val outName1 = "PGLM"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
        val c1 = 
s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int W = atoi(argv[1]);

    ${if (sparse) 
s"""
    double *L1 = new double[W];
    double *L2 = new double[W - 1];
    for(size_t i = 0; i < W; ++i) {
        L1[i] = (double) (rand() % 1000000) / 1e6;
    }
    for(size_t i = 0; i < W - 1; ++i) {
        L2[i] = (double) (rand() % 1000000) / 1e6;
    }
""" 
    else {
s"""
    double **L = new double*[W];
    for (size_t i = 0; i < W; ++i) {
        L[i] = new double[W];
        for (size_t j = 0; j < W; ++j) {
            L[i][j] = (double) 0;
        }
    }
    for(size_t i = 0; i < W; ++i) {
        L[0][i] = (double) (rand() % 1000000) / 1e6;
    }
    for(size_t i = 1; i < W; ++i) {
        L[i][i - 1] = (double) (rand() % 1000000) / 1e6;
    }
"""
    }}

    double *N = new double[W];
    for(size_t j = 0; j < W; ++j){
        N[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *M = new double[W];
    for (size_t i = 0; i < W; ++i) {
        M[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = populationGrowthLeslieMatrix(1, sparse)

    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << M[W - 1] << "\\n";
    cout<<time;

    ${if (sparse) 
s"""
    delete[] L1;
    delete[] L2; 
""" 
    else 
s"""
    for(size_t i = 0; i < W; ++i){
        delete[] L[i];
    }
    delete[] L;
""" }
    delete[] N;
    delete[] M;
    return 0;
}
"""

    val code = s"$c1$c2$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  
  def TTM_MLIR(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "TTM_DP" else if (structure == "fixed_j") "TTM_J" else if (structure == "uhc") "TTM_UT" else "TTM"
    val outName = if(sparse) s"${outName1}_Sparse" else outName1
    val c1 = MLIR_init_code()
    val argv_names = if (structure == "fixed_j") Seq("M", "N", "Q", "P", "J") else Seq("M", "N", "Q", "P")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %A = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %B = memref.alloc(%M, %N, %Q) : memref<?x?x?xf64>
    %C = memref.alloc(%P, %Q) : memref<?x?xf64>
"""
    val condition1 = if (structure == "diag_p") (0, getVar("gen_cond"), 1, 0) else if (structure == "fixed_j") (1, getVar("gen_cond"), "J", 0) else if (structure == "uhc") (0, getVar("gen_cond"), 1, 3) else getDefaultCondition("oi1")
    val c4 = MLIR_gen_random_number("B", Seq("M", "N", "Q"), condition1)
    val c5 = MLIR_gen_random_number("C", Seq("P", "Q"), getDefaultCondition("oi1"))
    val c6 = MLIR_gen_random_number("A", Seq("M", "N", "P"), getDefaultCondition("oi0"))
    val c7 = MLIR_start_timer_code()
    val c8 = ttm(structure, 1, sparse, "MLIR")
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
"""
    val c9 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def THP_MLIR(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "diag_p") "THP_DP" else if (structure == "fixed_i") "THP_I" else if (structure == "fixed_j") "THP_J" else "THP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = MLIR_init_code()
    val argv_names = if (structure == "fixed_i") Seq("M", "N", "P", "I") else if (structure == "fixed_j") Seq("M", "N", "P", "J") else Seq("M", "N", "P")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %A = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %C = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
"""
    val condition1 = if (structure == "diag_p") (0, getVar("gen_cond"), 1, 0) else if (structure == "fixed_i") (0, getVar("gen_cond"), "I", 0) else if (structure == "fixed_j") (1, getVar("gen_cond"), "J", 0) else getDefaultCondition("oi1")
    val c4 = MLIR_gen_random_number("B", Seq("M", "N", "P"), condition1)
    val c5 = MLIR_gen_random_number("C", Seq("M", "N", "P"), getDefaultCondition("oi1"))
    val c6 = MLIR_gen_random_number("A", Seq("M", "N", "P"), getDefaultCondition("oi0"))
    val c7 = MLIR_start_timer_code()
    val c8 = thp(structure, 1, sparse, "MLIR")
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
"""
    val c9 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def PR2C_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "PR2C_Sparse" else "PR2C"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %cont_degree3 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?xf64>
    %cont_degree4 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c6 = MLIR_gen_random_number("cont_degree3", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c7 = MLIR_gen_random_number("cont_degree4", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c8 = MLIR_start_timer_code()
    val allDegs = (2 to 4)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c9 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last2 = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
    "func.call"(%last2) {callee = @print_f64_cerr} : (f64) -> ()
    %last3 = "memref.load"(%cont_degree3, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
    "func.call"(%last3) {callee = @print_f64_cerr} : (f64) -> ()
    %last = "memref.load"(%cont_degree4, %0, %0, %0, %0) : (memref<?x?x?x?xf64>, index, index, index, index) -> f64
"""
    val c10 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def PR3C_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "PR3C_Sparse" else "PR3C"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %cont_degree3 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?xf64>
    %cont_degree4 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?xf64>
    %cont_degree5 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?x?xf64>
    %cont_degree6 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?x?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c6 = MLIR_gen_random_number("cont_degree3", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c7 = MLIR_gen_random_number("cont_degree4", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c8 = MLIR_gen_random_number("cont_degree5", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c9 = MLIR_gen_random_number("cont_degree6", Seq("CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c10 = MLIR_start_timer_code()
    val allDegs = (2 to 6)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c11 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last2 = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
    "func.call"(%last2) {callee = @print_f64_cerr} : (f64) -> ()
    %last3 = "memref.load"(%cont_degree3, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
    "func.call"(%last3) {callee = @print_f64_cerr} : (f64) -> ()
    %last4 = "memref.load"(%cont_degree4, %0, %0, %0, %0) : (memref<?x?x?x?xf64>, index, index, index, index) -> f64
    "func.call"(%last4) {callee = @print_f64_cerr} : (f64) -> ()
    %last5 = "memref.load"(%cont_degree5, %0, %0, %0, %0, %0) : (memref<?x?x?x?x?xf64>, index, index, index, index, index) -> f64
    "func.call"(%last5) {callee = @print_f64_cerr} : (f64) -> ()
    %last = "memref.load"(%cont_degree6, %0, %0, %0, %0, %0, %0) : (memref<?x?x?x?x?x?xf64>, index, index, index, index, index, index) -> f64
"""
    val c12 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10\n$c11\n$c12"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }

  def LRA_MLIR(sparse: Boolean = false) = {
    val outName = if (sparse) "LRA_Sparse" else "LRA"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %other_cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %other_cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("other_cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c6 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c7 = MLIR_gen_random_number("other_cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    
    val k = 1
    val allDegs = (2 to 2 * k)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val (other_const_tensorComputation, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val addus2: Map[Exp, Rule] = const_uniqueSets.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addrm2: Map[Exp, Rule] = const_redundancyMap.map{case (k, v) => (Access("other_" + k.asInstanceOf[Access].name, k.asInstanceOf[Access].vars, k.asInstanceOf[Access].kind) -> Rule(Access("other_" + v.head.name, v.head.vars, v.head.kind), v.body))}.toMap
    val addus: Map[Exp, Rule] = mergeMap(Seq(const_uniqueSets, addus2))((v1, v2) => v1)
    val addrm: Map[Exp, Rule] = mergeMap(Seq(const_redundancyMap, addrm2))((v1, v2) => v1)
    val (peq_tensorComputation, peq_dimInfo, peq_uniqueSets, peq_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], const_dimInfo, addus, addrm))((acc, d) => {
      val res = e2eAddition(d, acc._3, acc._4, 1)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c8 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val c9 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, sparse, codeLang="MLIR")}")

    val c10 = MLIR_start_timer_code()
    val c11 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, sparse, codeLang="MLIR")}")
    val cerr_load = s"""
    %last = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c12 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10\n$c11\n$c12"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }
}