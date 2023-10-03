package uk.ac.ed.dal
package structtensor
package apps

import compiler._
import STURHelper._
import Compiler._
import Shared._

object PR2A {
  import E2E_PRK._
  def apply(codeMotion: Boolean = true, codeLang: String = "CPP", sparse: Boolean = false) = {
    codeLang match {
      case "CPP" => CPP(codeMotion)
      case "MLIR" => "Not Implemented"
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
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  double ***cont_degree3 = new double**[CONT_SZ];
  double ***other_cont_degree3 = new double**[CONT_SZ];
  double ***r_cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double ****other_cont_degree4 = new double***[CONT_SZ];
  double ****r_cont_degree4 = new double***[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    other_cont_degree3[i] = new double*[CONT_SZ];
    r_cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    other_cont_degree4[i] = new double**[CONT_SZ];
    r_cont_degree4[i] = new double**[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      other_cont_degree3[i][j] = new double[CONT_SZ];
      r_cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      other_cont_degree4[i][j] = new double*[CONT_SZ];
      r_cont_degree4[i][j] = new double*[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
"""
    val k = 2
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
    val c3 = other_const_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, other_const_dimInfo, other_const_uniqueSets, other_const_redundancyMap, 1, false, compressionMaps=const_compressionMap, codeMotion=codeMotion)}")
    val c4 = "  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"
    val c5 = peq_tensorComputation.foldLeft("")((acc, ctc) => s"$acc\n${codeGen(ctc, peq_dimInfo, peq_uniqueSets, peq_redundancyMap, 1, compressionMaps=peq_compressionMap, codeMotion=codeMotion)}")
    val c6 = 
s"""
  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
        delete[] other_cont_degree4[i][j][k];
        delete[] r_cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] other_cont_degree3[i][j];
      delete[] r_cont_degree3[i][j];
      delete[] cont_degree4[i][j];
      delete[] other_cont_degree4[i][j];
      delete[] r_cont_degree4[i][j];
    }
    delete[] cont_degree2[i];
    delete[] other_cont_degree2[i];
    delete[] r_cont_degree2[i];
    delete[] cont_degree3[i];
    delete[] other_cont_degree3[i];
    delete[] r_cont_degree3[i];
    delete[] cont_degree4[i];
    delete[] other_cont_degree4[i];
    delete[] r_cont_degree4[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  delete[] cont_degree3;
  delete[] other_cont_degree3;
  delete[] r_cont_degree3;
  delete[] cont_degree4;
  delete[] other_cont_degree4;
  delete[] r_cont_degree4;
  cout << end - start << endl;
  return 0;
}
"""
    val code = s"$c1\n$c2\n$c3\n$c4\n$c5\n$c6"
    write2File("outputs/PR2A.cpp", code)
  }
}