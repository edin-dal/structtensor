package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object LRA {
  import E2E_PRK._
    def apply(codeMotion: Boolean = true) = {
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
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap, codeMotion=codeMotion)}")
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=other_const_compressionMap, codeMotion=codeMotion)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap, codeMotion=codeMotion)}")
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

  def MLIR(sparse: Boolean = false) = {
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