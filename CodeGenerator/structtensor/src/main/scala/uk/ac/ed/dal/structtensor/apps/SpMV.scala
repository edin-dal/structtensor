package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object SpMV {
  def spmv(structure: String, mode: Int = 0, sparse: Boolean = false, codeLang: String = "CPP", codeMotion: Boolean = true) = {
    val head: Access = Access("A", Seq("i".toVar), Tensor)
    val var1: Access = Access("B",  Seq("i".toVar, "j".toVar), Tensor)
    val var2: Access = Access("C",  Seq("j".toVar), Tensor)
    val prods: Prod = Prod(Seq(var1, var2))
    val body: SoP = SoP(Seq(prods))
    val tensorComputation: Rule = Rule(head, body)

    val dim1: DimInfo = DimInfo(var1, Seq("M".toVar, "N".toVar))
    val dim2: DimInfo = DimInfo(var2, Seq("N".toVar))
    val dimInfo: Seq[DimInfo] = Seq(dim1, dim2)


    val var1HeadUS: Access = Access(var1.name.uniqueName, var1.vars, UniqueSet)
    val var1BodyUS: SoP = structure match {
      case "diag" => {
        val var1ExpUS1: Exp = Comparison("=", "i".toVar, "j".toVar)
        val var1ProdsUS: Prod = Prod(Seq(var1ExpUS1))
        multSoP(Seq(dim1.toSoP, SoP(Seq(var1ProdsUS))))
      }
      case "ut" => {
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
      case "diag" => (x: Seq[Variable]) => Seq(x(1))
      case "ut" => (x: Seq[Variable]) => Seq(Arithmetic("-", Arithmetic("+", Arithmetic("*", x(0), "M".toVar), x(1)), Arithmetic("/", Arithmetic("*", x(0), Arithmetic("+", x(0), ConstantInt(1))), ConstantInt(2))))
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

  def apply(structure: String, codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(structure, sparse, codeMotion)
      case "MLIR" => "Not Implemented"
      case "C" => "Not Implemented"
      case _ => throw new Exception(f"Unknown code language: $codeLang")
    }
  }

  def CPP(structure: String, sparse: Boolean, codeMotion: Boolean = true) = {
    val outName1 = if (structure == "diag") "SpMV_D" else if (structure == "ut") "SpMV_UT" else "SpMV"
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
    int M = atoi(argv[1]), N = atoi(argv[2]);
    
    /*
        M : first dimension (i) in A, B
        N : second dimension (j) in B, C

        A(i) = B(i,j),C(j)
    */

    ${if (sparse) {
s"""
    double *B = new double${if (structure == "ut") "[M * (M + 1) / 2];" else if (structure == "diag") "[M];"}
    for (size_t i = 0; i < M; ++i){
      ${if (structure == "diag") "" else if (structure == "ut") "for(size_t j = i; j < N; ++j){" else ""}
        ${if (structure == "diag") "B[i]" else if (structure == "ut") "B[i * M + j - (i * (i + 1) / 2)]" else ""} = (double) (rand() % 1000000) / 1e6;
      }
    }
"""
    } else {
s"""
    double  **B = new double*[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double[N];
        for(size_t j = 0; j < N; ++j){
            ${if (structure == "diag") "if (i == j){" else if (structure == "ut") "if (i <= j){" else ""}
                B[i][j] = (double) (rand() % 1000000) / 1e6;
            }
            else{
                B[i][j] = (double) 0;
            }
        }
    }
"""
    }}

    double  *C = new double[N];
    for(size_t i = 0; i < N; ++i){
        C[i] = (double) (rand() % 1000000) / 1e6;
    }

    double  *A = new double[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val c2 = spmv(structure, 1, sparse, codeMotion=codeMotion)
    val c3 = 
s"""
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;
    
    cerr << A[M - 1] << "\\n";
    cout<<time;

    ${if (sparse) "" else {
s"""
    for(size_t i = 0; i < M; ++i){
        delete[] B[i];
    }
"""
    }}
    delete[] B;
    delete[] C;
    delete[] A;

    return 0; 
}
"""

    val code = s"$c1\n$c2\n$c3"
    write2File(s"outputs/$outName.cpp", code)
  }
}