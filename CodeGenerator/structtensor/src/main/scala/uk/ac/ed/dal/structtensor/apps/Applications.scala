package uk.ac.ed.dal
package structtensor
package apps

import java.io._ 
import compiler._
import STURHelper._
import Compiler._
import Shared._

object Applications {
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
}