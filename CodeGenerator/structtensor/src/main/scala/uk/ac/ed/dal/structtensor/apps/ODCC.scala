package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object ODCC {
  def oneDCircularConvolution(mode: Int = 0, sparse: Boolean = false, codeMotion: Boolean = true) = {
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
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, varReverse=true, codeMotion=codeMotion))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, varReverse=true, codeMotion=codeMotion)
  }

  def apply(codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(sparse, codeMotion)
      case "MLIR" => "Not Implemented"
      case "C" => "Not Implemented"
      case _ => throw new Exception(f"Unknown code language: $codeLang")
    }
  }

  // 1D circular convolution
  def CPP(sparse: Boolean, codeMotion: Boolean = true) = {
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
    val c2 = oneDCircularConvolution(1, sparse, codeMotion=codeMotion)

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
}