package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object MTTKRP {
  def mttkrp_n(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP", codeMotion: Boolean = true, sturOpt: Boolean = false) = {
    val head: Access = Access("A", Seq("i".toVar, "j".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "k".toVar, "l".toVar), Tensor)
    val var2: Access = Access("C",  Seq("k".toVar, "j".toVar), Tensor)
    val var3: Access = Access("D",  Seq("l".toVar, "j".toVar), Tensor)
    

    val prods: Prod = Prod(Seq(var1, var2, var3))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar, "P".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar, "Q".toVar))
    val dim3: DimInfo = DimInfo(var3, Seq("P".toVar, "Q".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2, dim3)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "fixed_ij" | "fixed_i" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "I".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "JIK" => {
        val var1ExpUS1: Exp = Comparison("<", "i".toVar, "k".toVar)
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
      case "fixed_ij" | "fixed_i" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(1), "P".toVar), x(2)))
      case "JIK" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic(
        "*", Arithmetic(
          "/", Arithmetic("*", "N".toVar, Arithmetic("-", "N".toVar, ConstantInt(1))), ConstantInt(2)
        ), Arithmetic(
          "+", Arithmetic(
            "*", x(0), "N".toVar
          ), Arithmetic(
            "-", x(1), Arithmetic(
              "/", Arithmetic(
                "*", Arithmetic("+", x(0), ConstantInt(1)), Arithmetic("+", x(0), ConstantInt(2))
              ), ConstantInt(2)
            )
          )
        )
      ), x(2)))
      case _ => (x: Seq[Variable]) => x
    }

    val var2HeadUS: Access = Access(var2.name.uniqueName, var2.vars, UniqueSet)
    val var2BodyUS: SoP = dim2.toSoP
    val var2US: Rule = Rule(var2HeadUS, var2BodyUS)

    val var2HeadRM: Access = Access(var2.name.redundancyName, var2.vars.redundancyVarsInplace, RedundancyMap)
    val var2BodyRM: SoP = emptySoP()
    val var2RM: Rule = Rule(var2HeadRM, var2BodyRM)

    val var3HeadUS: Access = Access(var3.name.uniqueName, var3.vars, UniqueSet)
    val var3BodyUS: SoP = structure match {
      case "fixed_ij" | "fixed_j" | "JIK" => {
        val var3ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
        val var3ProdsUS: Prod = Prod(Seq(var3ExpUS1))
        multSoP(Seq(dim3.toSoP, SoP(Seq(var3ProdsUS))))
      }      
      case "JL" => {
        val var3ExpUS1: Exp = Comparison("=", "j".toVar, "l".toVar)
        val var3ProdsUS: Prod = Prod(Seq(var3ExpUS1))
        multSoP(Seq(dim3.toSoP, SoP(Seq(var3ProdsUS))))
      }
      case _ => dim3.toSoP
    } 
    val var3US: Rule = Rule(var3HeadUS, var3BodyUS)

    val var3HeadRM: Access = Access(var3.name.redundancyName, var3.vars.redundancyVarsInplace, RedundancyMap)
    val var3BodyRM: SoP = emptySoP()
    val var3RM: Rule = Rule(var3HeadRM, var3BodyRM)

    val var3DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "fixed_ij" | "fixed_j" | "JIK" | "JL" => (x: Seq[Variable]) => Seq(x(0))
      case _ => (x: Seq[Variable]) => x
    }

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL, var3 -> var3DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang, codeMotion=codeMotion, sturOpt=sturOpt))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang, codeMotion=codeMotion, sturOpt=sturOpt)
  }

  def apply(structure: String, codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false, sturOpt: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(structure=structure, sparse=sparse, codeMotion=codeMotion, sturOpt=sturOpt)
      case "MLIR" => MLIR(structure=structure, sparse=sparse, sturOpt=sturOpt)
      case "C" => C(structure=structure, sparse=sparse, codeMotion=codeMotion, sturOpt=sturOpt)
      case _ => throw new Exception(f"Unknown code language: $codeLang")
    }
  }

  def CPP(structure: String, sparse: Boolean, codeMotion: Boolean = true, sturOpt: Boolean = false) = {
    val outName1 = if (structure == "fixed_ij") "MTTKRP_IJ" else if (structure == "fixed_i") "MTTKRP_I" else if (structure == "fixed_j") "MTTKRP_J" else if (structure == "JL") "MTTKRP_JL" else if (structure == "JIK") "MTTKRP_JIK" else "MTTKRP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = CPP_init_code()
    val argv_names = if (structure == "fixed_ij") Seq("M", "N", "P", "Q", "I", "J") else if (structure == "fixed_i") Seq("M", "N", "P", "Q", "I") else if (structure == "fixed_j" || structure == "JIK") Seq("M", "N", "P", "Q", "J") else Seq("M", "N", "P", "Q")
    val c2 = CPP_read_argv(argv_names)
    val dims3 = if ((structure == "fixed_i" || structure == "fixed_ij") && sparse) Seq("N", "P") else Seq("M", "N", "P")
    val cond3 = (x: Seq[String]) => if ((structure == "fixed_i" || structure == "fixed_ij") && !sparse) s"${x(0)} == I" else "1"
    val func3 = if ((structure == "fixed_i" || structure == "fixed_ij") && sparse) (x: Seq[String]) => Seq(s"${x(0)} * P + ${x(1)}") else (x: Seq[String]) => x
    val c3 = CPP_alloc_and_gen_random_number("B", dims3, cond3, func3)

    val c4 = CPP_alloc_and_gen_random_number("C", Seq("N", "Q"), const_condition("true"))

    val dims5 = if ((structure == "fixed_j" || structure == "fixed_ij") && sparse) Seq("P") else Seq("P", "Q")
    val cond5 = (x: Seq[String]) => if ((structure == "fixed_j" || structure == "fixed_ij") && !sparse) s"${x(1)} == J" else "1"
    val c5 = CPP_alloc_and_gen_random_number("D", dims5, cond5)

    val c6 = CPP_alloc_and_gen_random_number("A", Seq("M", "Q"), const_condition("false"))

    val c7 = CPP_timer_start()
    val c8 = mttkrp_n(structure, 1, sparse, codeMotion=codeMotion, sturOpt=sturOpt)
    val c9 = CPP_timer_end()
    val c10 = CPP_printerr("A", Seq("M", "Q"))
    val c11 = CPP_free("A", Seq("M", "Q"), sparse)
    val c12 = CPP_free("B", dims3, sparse)
    val c13 = CPP_free("C", Seq("N", "Q"), sparse)
    val c14 = CPP_free("D", dims5, sparse)
    val c15 = CPP_return()
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10\n$c11\n$c12\n$c13\n$c14\n$c15"
    write2File(s"outputs/$outName.cpp", code)
  }

  def C(structure: String, sparse: Boolean, codeMotion: Boolean, sturOpt: Boolean = false) = {
    val outName1 = if (structure == "fixed_ij") "MTTKRP_IJ" else if (structure == "fixed_i") "MTTKRP_I" else if (structure == "fixed_j") "MTTKRP_J" else "MTTKRP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = C_init_code()
    val argv_names = if (structure == "fixed_ij") Seq("M", "N", "P", "Q", "I", "J") else if (structure == "fixed_i") Seq("M", "N", "P", "Q", "I") else if (structure == "fixed_j") Seq("M", "N", "P", "Q", "J") else Seq("M", "N", "P", "Q")
    val c2 = C_read_argv(argv_names)
    val dims3 = if ((structure == "fixed_i" || structure == "fixed_ij") && sparse) Seq("N", "P") else Seq("M", "N", "P")
    val cond3 = (x: Seq[String]) => if ((structure == "fixed_i" || structure == "fixed_ij") && !sparse) s"${x(0)} == I" else "1"
    val func3 = if ((structure == "fixed_i" || structure == "fixed_ij") && sparse) (x: Seq[String]) => Seq(s"${x(0)} * P + ${x(1)}") else (x: Seq[String]) => x
    val c3 = C_alloc_and_gen_random_number("B", dims3, cond3, func3)

    val c4 = C_alloc_and_gen_random_number("C", Seq("N", "Q"), const_condition("true"))

    val dims5 = if ((structure == "fixed_j" || structure == "fixed_ij") && sparse) Seq("P") else Seq("P", "Q")
    val cond5 = (x: Seq[String]) => if ((structure == "fixed_j" || structure == "fixed_ij") && !sparse) s"${x(1)} == J" else "1"
    val c5 = C_alloc_and_gen_random_number("D", dims5, cond5)

    val c6 = C_alloc_and_gen_random_number("A", Seq("M", "Q"), const_condition("false"))
    val c7 = C_timer_start()
    val c8 = mttkrp_n(structure, 1, sparse, codeMotion=codeMotion, sturOpt=sturOpt)
    val c9 = C_timer_end()
    val c10 = C_printerr("A", Seq("M", "Q"))
    val c11 = C_free(Seq("A", "B", "C", "D"))
    val c12 = C_return()
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10\n$c11\n$c12"
    write2File(s"outputs_c/$outName.c", code)
  }

  def MLIR(structure: String, sparse: Boolean, sturOpt: Boolean = false) = {
    val outName1 = if (structure == "fixed_ij") "MTTKRP_IJ" else if (structure == "fixed_i") "MTTKRP_I" else if (structure == "fixed_j") "MTTKRP_J" else "MTTKRP"
    val outName = if (sparse) s"${outName1}_Sparse" else outName1
    val c1 = MLIR_init_code()
    val argv_names = if (structure == "fixed_ij") Seq("M", "N", "P", "Q", "I", "J") else if (structure == "fixed_i") Seq("M", "N", "P", "Q", "I") else if (structure == "fixed_j") Seq("M", "N", "P", "Q", "J") else Seq("M", "N", "P", "Q")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %A = memref.alloc(%M, %Q) : memref<?x?xf64>
    %B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %C = memref.alloc(%N, %Q) : memref<?x?xf64>
    %D = memref.alloc(%P, %Q) : memref<?x?xf64>
"""
    val condition1 = if (structure == "fixed_ij" || structure == "fixed_i") (0, getVar("gen_cond"), "I", 0) else getDefaultCondition("oi1")
    val c4 = MLIR_gen_random_number("B", Seq("M", "N", "P"), condition1)
    val c5 = MLIR_gen_random_number("C", Seq("N", "Q"), getDefaultCondition("oi1"))
    val condition2 = if (structure == "fixed_ij" || structure == "fixed_j") (1, getVar("gen_cond"), "J", 0) else getDefaultCondition("oi1")
    val c6 = MLIR_gen_random_number("D", Seq("P", "Q"), condition2)
    val c7 = MLIR_gen_random_number("A", Seq("M", "Q"), getDefaultCondition("oi0"))
    val c8 = MLIR_start_timer_code()
    val c9 = mttkrp_n(structure, 1, sparse, "MLIR", sturOpt=sturOpt)
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c10 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }
}