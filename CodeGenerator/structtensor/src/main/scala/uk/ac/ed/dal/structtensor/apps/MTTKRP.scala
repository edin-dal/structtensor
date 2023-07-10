package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object MTTKRP {
  def mttkrp_n(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP") = {
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
      case _ => dim1.toSoP
    } 
    val var1US: Rule = Rule(var1HeadUS, var1BodyUS)

    val var1HeadRM: Access = Access(var1.name.redundancyName, var1.vars.redundancyVarsInplace, RedundancyMap)
    val var1BodyRM: SoP = emptySoP()
    val var1RM: Rule = Rule(var1HeadRM, var1BodyRM)

    val var1DL: Function[Seq[Variable], Seq[Index]] = structure match {
      case "fixed_ij" | "fixed_i" => (x: Seq[Variable]) => Seq(Arithmetic("+", Arithmetic("*", x(1), "P".toVar), x(2)))
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
      case "fixed_ij" | "fixed_j" => {
        val var3ExpUS1: Exp = Comparison("=", "j".toVar, "J".toVar)
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
      case "fixed_ij" | "fixed_j" => (x: Seq[Variable]) => Seq(x(0))
      case _ => (x: Seq[Variable]) => x
    }

    val uniqueSets: Map[Exp, Rule] = Map(var1 -> var1US, var2 -> var2US, var3 -> var3US)
    val redundancyMap: Map[Exp, Rule] = Map(var1 -> var1RM, var2 -> var2RM, var3 -> var3RM)
    val dataLayoutMap: Map[Exp, Function[Seq[Variable], Seq[Index]]] = if (sparse) Map(var1 -> var1DL, var3 -> var3DL) else Map()

    if (mode == 0) {
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang)
  }


  def apply(structure: String, sparse: Boolean) = {
    val outName1 = if (structure == "fixed_ij") "MTTKRP_IJ" else if (structure == "fixed_i") "MTTKRP_I" else if (structure == "fixed_j") "MTTKRP_J" else "MTTKRP"
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

    int M = atoi(argv[1]),N = atoi(argv[2]), P = atoi(argv[3]), Q = atoi(argv[4]);
    ${if (structure == "fixed_ij") "int I = atoi(argv[5]), J = atoi(argv[6]);" else if (structure == "fixed_i") "int I = atoi(argv[5]);" else if (structure == "fixed_j") "int J = atoi(argv[5]);" else ""}
    
     /*
        M : third dimension (k vec) in B,   --> rows in A 
        N : first dimension (i vec) in B,   --> rows in C
        P : second dimension (j vec) in B,  --> rows in D

        Q : columns  in C, D, and A 

        A(i, j) = B(i,k,l),C(k,j),D(l,j)
    */


    ${if (sparse && (structure == "fixed_i" || structure == "fixed_ij")) {
s"""
    double *B = new double[N * P];
    for (size_t k = 0; k < N; ++k){
        for (size_t l = 0; l < P; ++l){
            B[k * P + l] = (double) (rand() % 1000000) / 1e6;
        }
    }
"""
    } else {
s"""
    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t k = 0; k < N; ++k){
            B[i][k] = new double[P];
            for(size_t l =0; l< P; ++l){
                ${if (structure == "fixed_i" || structure == "fixed_ij") {
s"""
                if (i == I){
                    B[i][k][l] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][k][l] = (double) 0;
                }
"""
                } else {
                  "B[i][k][l] = (double) (rand() % 1000000) / 1e6;"
                }}
            }
        }
    }
"""
    }}

    double  **C = new double*[N];
    for(size_t k = 0; k < N; ++k){
        C[k] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            C[k][j] = (double) (rand() % 1000000) / 1e6;
        }
    }

    ${if (sparse && (structure == "fixed_j" || structure == "fixed_ij")) {
s"""
    double *D = new double[P];
    for (size_t l = 0; l < P; ++l){
        D[l] = (double) (rand() % 1000000) / 1e6;
    }
"""
    } else {
s"""
    double  **D = new double*[P];
    for(size_t l = 0; l < P; ++l){
        D[l] = new double[Q];
        for(size_t j = 0; j < Q; j++){
            ${if (structure == "fixed_j" || structure == "fixed_ij") {
s"""
            if(j == J){
                D[l][j] = (double) (rand() % 1000000) / 1e6;
            }
            else{
                D[l][j] = (double) 0;

            }
"""
            } else "D[l][j] = (double) (rand() % 1000000) / 1e6;"}
        }
    }
"""
    }}

    double  **A = new double*[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            A[i][j] = (double) 0;
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = mttkrp_n(structure, 1, sparse)
    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][Q - 1] << "\\n";
    cout<<time;
   

    ${if (sparse && (structure == "fixed_i" || structure == "fixed_ij")) "" else {
s"""
    for(size_t i = 0; i < P; i++){
        for(size_t j = 0; j < N; j++){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
"""
    }}
    delete[] B;
    
    for(size_t i = 0; i < N; i++){
        delete[] C[i];
    }
    delete[] C;

    ${if (sparse && (structure == "fixed_j" || structure == "fixed_ij")) "" else {
s"""
    for(size_t i = 0; i < P; i++){
        delete[] D[i];
    }
"""
    }}
    delete[] D;

    for(size_t i = 0; i < M; i++){
        delete[] A[i];
    }
    delete[] A;
    return 0; 
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }

  def MLIR(structure: String, sparse: Boolean) = {
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
    val c9 = mttkrp_n(structure, 1, sparse, "MLIR")
    val cerr_load = s"""
    %last = "memref.load"(%A, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c10 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8\n$c9\n$c10"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }
}