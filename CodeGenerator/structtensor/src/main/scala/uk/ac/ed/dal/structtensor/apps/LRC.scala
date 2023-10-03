package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object LRC {
  import E2E_PRK._
  def apply(codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false, sturOpt: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(codeMotion=codeMotion, sturOpt=sturOpt)
      case "MLIR" => MLIR(sparse=sparse, sturOpt=sturOpt)
      case "C" => "Not Implemented"
      case _ => throw new Exception(f"Unknown code language: $codeLang")
    }
  }

  def CPP(codeMotion: Boolean = true, sturOpt: Boolean = false) = {
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
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
"""
    val allDegs = (2 to 2)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap, const_compressionMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2), mergeMap(Seq(acc._5, res._5))((v1, v2) => v2))
    })
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap, codeMotion=codeMotion, sturOpt=sturOpt)}")
    val c3 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    delete[] cont_degree2[i];
  }
  delete[] cont_degree2;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3"
    write2File("outputs/LRC.cpp", code)
  }

  def MLIR(sparse: Boolean = false, sturOpt: Boolean = false) = {
    val outName = if (sparse) "LRC_Sparse" else "LRC"
    val c1 = MLIR_init_code()
    val argv_names = Seq("CONT_SZ")
    val c2 = MLIR_read_argv(argv_names)
    val c3 = s"""
    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
"""
    val c4 = MLIR_gen_random_number("cont_sum1", Seq("CONT_SZ"), getDefaultCondition("oi1"))
    val c5 = MLIR_gen_random_number("cont_degree2", Seq("CONT_SZ", "CONT_SZ"), getDefaultCondition("oi0"))
    val c6 = MLIR_start_timer_code()
    val allDegs = (2 to 2)
    val (const_tensorComputation, const_dimInfo, const_uniqueSets, const_redundancyMap) = allDegs.foldLeft((Seq.empty[Rule], Seq.empty[DimInfo], Map.empty[Exp, Rule], Map.empty[Exp, Rule]))((acc, d) => {
      val res = e2eConstructor(d)
      (acc._1 :+ res._1, acc._2 ++ res._2, mergeMap(Seq(acc._3, res._3))((v1, v2) => v2), mergeMap(Seq(acc._4, res._4))((v1, v2) => v2))
    })
    val c7 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, sparse, codeLang="MLIR", sturOpt=sturOpt)}")
    val cerr_load = s"""
    %last = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
"""
    val c8 = MLIR_end_code(cerr_load)
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6\n$c7\n$c8"
    write2File(s"outputs_mlir/$outName.mlir", code)
  }
}