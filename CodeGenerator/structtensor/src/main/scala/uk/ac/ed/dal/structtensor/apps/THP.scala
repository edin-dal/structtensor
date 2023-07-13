package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object THP {
  def thp(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP", codeMotion: Boolean = true) = {
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
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeLang=codeLang, codeMotion=codeMotion))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeLang=codeLang, codeMotion=codeMotion)
  }

  def apply(structure: String, sparse: Boolean, codeMotion: Boolean = true) = {
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
    val c2 = thp(structure, 1, sparse, codeMotion=codeMotion)
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

  def MLIR(structure: String, sparse: Boolean) = {
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
}