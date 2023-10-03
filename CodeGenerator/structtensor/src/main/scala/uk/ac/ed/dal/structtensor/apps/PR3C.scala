package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object PR3C {
  import E2E_PRK._
  def apply(codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(codeMotion)
      case "MLIR" => MLIR(sparse)
      case "C" => "Not Implemented"
      case _ => throw new Exception(f"Unknown code language: $codeLang")
    }
  }

  def CPP(codeMotion: Boolean = true) = {
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
    val c2 = const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, const_dimInfo, const_uniqueSets, const_redundancyMap, 1, false, compressionMaps=const_compressionMap, codeMotion=codeMotion)}")
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

  def MLIR(sparse: Boolean = false) = {
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
}