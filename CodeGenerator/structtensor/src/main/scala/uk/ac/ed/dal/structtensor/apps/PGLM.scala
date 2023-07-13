package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object PGLM {
  def populationGrowthLeslieMatrix(mode: Int = 0, sparse: Boolean = false, codeMotion: Boolean = true) = {
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

    val var3DL: Function[Seq[Variable], Seq[Index]] = (x: Seq[Variable]) => Seq(x(1))

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
      println(codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, dataLayoutMap=dataLayoutMap, codeMotion=codeMotion))

      (tensorComputation, infer(tensorComputation, dimInfo, uniqueSets, redundancyMap))
    } else codeGen(tensorComputation, dimInfo, uniqueSets, redundancyMap, 1, dataLayoutMap=dataLayoutMap, codeMotion=codeMotion)
  }

  def apply(sparse: Boolean, codeMotion: Boolean = true) = {
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
    val c2 = populationGrowthLeslieMatrix(1, sparse, codeMotion=codeMotion)

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
}