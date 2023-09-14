package uk.ac.ed.dal
package structtensor
package apps

import java.io._ 
import compiler._
import Compiler._

object Shared {
  def write2File(filename: String, s: String): Unit = { // taken from https://alvinalexander.com/scala/how-to-write-text-files-in-scala-printwriter-filewriter/
    val file = new File(filename)
    val bw = new BufferedWriter(new FileWriter(file))
    bw.write(s)
    bw.close()
  }

  def MLIR_init_code(): String = s"""
"builtin.module"() ({
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "puts", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "atoi", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "srand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i32), sym_name = "rand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "print_i32", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (), sym_name = "print_i64", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (f64) -> (), sym_name = "print_f64_cerr", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i64), sym_name = "timer", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (i64), sym_name = "timer_elapsed", sym_visibility = "private"} : () -> ()

  "func.func"() ({
    ^bb0(%argc : i32, %argv : !llvm.ptr<!llvm.ptr<i8>>):
    %0 = "arith.constant"() {"value" = 0 : index} : () -> index
    %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
    %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
    %1 = "arith.constant"() {"value" = 1 : index} : () -> index
    %oi1 = "arith.constant"() {"value" = 1 : i1} : () -> i1
    %oi0 = "arith.constant"() {"value" = 0 : i1} : () -> i1
    "func.call"(%zi32) {callee = @srand} : (i32) -> ()
    %1000000 = "arith.constant"() {"value" = 1000000 : i32} : () -> i32
    %f1000000 = "arith.constant"() {"value" = 1000000.0 : f64} : () -> f64
"""

  def MLIR_read_argv(argv_names: Seq[String]): String = {
    argv_names.zipWithIndex.foldLeft("")((acc, nameId) => {
      val (name, i) = nameId
      val id = i + 1
      acc + s"""
    %argvv$id = llvm.getelementptr %argv[$id] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv$id = "llvm.load"(%argvv$id) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %${name}i32 = "func.call"(%argv$id) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %$name = arith.index_cast %${name}i32 : i32 to index
"""
    })
  }

  def MLIR_gen_random_number(var_name: String, dimensions: Seq[String], condition: (Int, String, Any, Int)): String = {
    val ivars_nostr = dimensions.map(e => getVar("%i"))
    val cond3 = if (condition._3.isInstanceOf[Int]) ivars_nostr(condition._3.asInstanceOf[Int]) else s"%${condition._3.asInstanceOf[String]}"
    val c0 = if (condition._1 == -1) "" else s"""
    %${condition._2} = "arith.cmpi"(${ivars_nostr(condition._1)}, ${cond3}) {predicate = ${condition._4} : i64} : (index, index) -> i1   
"""
    val c1 = dimensions.zipWithIndex.foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      acc + s"""
    "scf.for"(%0, %$dim, %1) ({
    ^bb0(${ivars_nostr(i)}: index):
"""
    })
    val ivars = ivars_nostr.mkString(", ")
    val qvars = dimensions.map(e => s"?").mkString("x") + "x"
    val index_vars = dimensions.map(e => s"index").mkString(", ")

    val rval1 = getVar("rval")
    val rval2 = getVar("rval")
    val rval3 = getVar("rval")
    val rval4 = getVar("rval")
    val c2 = s"""
    "scf.if"(%${condition._2}) ({
      %$rval1 = "func.call"() {callee = @rand} : () -> i32
      %$rval2 = "arith.remui"(%$rval1, %1000000) : (i32, i32) -> i32
      %$rval3 = "arith.sitofp"(%$rval2) : (i32) -> f64
      %$rval4 = "arith.divf"(%$rval3, %f1000000) : (f64, f64) -> f64
      "memref.store"(%$rval4, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()
"""
    val c3 = dimensions.foldLeft("")((acc, dim) => {
      acc + s"""
    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()
"""
    })
    return c1 + c0 + c2 + c3
  }

  def MLIR_start_timer_code(): String = s"""
    %stime = "func.call"() {callee = @timer} : () -> i64
"""

  def MLIR_end_code(cerr_load: String = ""): String = {
    s"""
    %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
    ${cerr_load}
    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
"""
  }

  def getDefaultCondition(condName: String): (Int, String, String, Int) = (-1, condName, "", -1)



  def CPP_init_code(): String = s"""
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

"""

  def CPP_read_argv(argv_names: Seq[String]): String = argv_names.zipWithIndex.foldLeft("")((acc, nameId) => {
    val (name, i) = nameId
    val id = i + 1
    acc + s"const int $name = atoi(argv[$id]);\n"
  })

  // sprase_indexing must either return the same values or linearize the dimensions
  def CPP_alloc_and_gen_random_number(var_name: String, dimensions: Seq[String], condition: Function[Seq[String], String], sprase_indexing: Function[Seq[String], Seq[String]] = (x: Seq[String]) => x): String = {
    val flag = sprase_indexing(dimensions) == dimensions 
    val c0 = if (flag) {
      s"double " + "*" * dimensions.length + s"$var_name = new double" + "*" * (dimensions.length - 1) + s"[${dimensions(0)}];\n"
    } else {
      s"double *$var_name = new double[" + dimensions.mkString(" * ") + s"];\n" 
    }
    val iter_seq: Seq[String] = dimensions.zipWithIndex.map(dimId => s"i${dimId._2}")
    val c1 = dimensions.zipWithIndex.foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      val c_sub1 = s"for (size_t i$i = 0; i$i < $dim; ++i$i) {\n"
      val c_sub2 = if (flag && i != dimensions.length - 1) s"$var_name[${iter_seq.slice(0, i + 1).mkString("][")}] = new double" + "*" * (dimensions.length - 2 - i) + s"[${dimensions(i + 1)}];\n" else ""
      acc + c_sub1 + c_sub2
    })
    val c2 = s"if (${condition(iter_seq)}) {\n" + s"$var_name[${sprase_indexing(iter_seq).mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${sprase_indexing(iter_seq).mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c2$c3"
  }

  def CPP_timer_start(): String = "long time = 0, start, end;\nstart = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"

  def CPP_timer_end(): String = "end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();\ntime = end - start;\ncout << time << endl;"

  def CPP_printerr(var_name: String, dimensions: Seq[String]) = s"cerr << $var_name[${dimensions.map(e => s"$e - 1").mkString("][")}] << endl;"

  def CPP_free(var_name: String, dimensions: Seq[String], is_sparse: Boolean) = {
    if (is_sparse) s"delete[] $var_name;" else {
      val c0 = dimensions.slice(1, dimensions.length).zipWithIndex.foldLeft("")((acc, dimId) => {
        val (dim, i) = dimId
        val c_sub1 = s"for (size_t i$i = 0; i$i < $dim; ++i$i) {\n"
        acc + c_sub1
      })
      val iter_seq: Seq[String] = dimensions.slice(1, dimensions.length).zipWithIndex.map(dimId => s"i${dimId._2}")
      val c1 = iter_seq.zipWithIndex.foldLeft("")((acc, iterId) => {
        val (iter, i) = iterId
        val c_sub1 = s"delete[] $var_name[${iter_seq.slice(0, iter_seq.length - i).mkString("][")}];\n}\n"
        acc + c_sub1
      })
      val c2 = s"delete[] $var_name;"
      s"$c0$c1$c2"
    }
  }

  def CPP_return(): String = "return 0;\n}"

  def C_init_code(): String = s"""
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// call this function to start a nanosecond-resolution timer
struct timespec timer_start(){
  struct timespec start_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
  return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
  struct timespec end_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
  long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
  return diffInNanos / 1000;
}

int main(int argc, char **argv){
  srand(0);
"""

  def C_read_argv(argv_names: Seq[String]): String = CPP_read_argv(argv_names)

  def C_alloc_and_gen_random_number(var_name: String, dimensions: Seq[String], condition: Function[Seq[String], String], sprase_indexing: Function[Seq[String], Seq[String]] = (x: Seq[String]) => x): String = {
    val flag = sprase_indexing(dimensions) == dimensions 
    val c0 = if (flag) {
      if (dimensions.length == 1) s"double (*$var_name) = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n"
      else s"double (*$var_name)[${dimensions.slice(1, dimensions.length).mkString("][")}] = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n"
    } else {
      s"double (*$var_name) = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n"
    }
    val c1 = dimensions.zipWithIndex.foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      val c_sub1 = s"for (size_t i$i = 0; i$i < $dim; ++i$i) {\n"
      acc + c_sub1
    })
    val iter_seq: Seq[String] = dimensions.zipWithIndex.map(dimId => s"i${dimId._2}")
    val c2 = s"if (${condition(iter_seq)}) {\n" + s"$var_name[${sprase_indexing(iter_seq).mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${sprase_indexing(iter_seq).mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c2$c3"
  }

  def C_timer_start(): String = "struct timespec start = timer_start();"

  def C_timer_end(): String = "long time = timer_end(start);\nprintf(\"%ld\\n\", time);"

  def C_printerr(var_name: String, dimensions: Seq[String]): String = s"""
fprintf(stderr, "%f\\n", $var_name[${dimensions.map(e => s"$e - 1").mkString("][")}]);"""

  def C_free(var_name: String): String = s"free($var_name);"

  def C_free(var_names: Seq[String]): String = var_names.foldLeft("")((acc, var_name) => s"$acc${C_free(var_name)}\n")

  def C_return(): String = CPP_return()
  
  def default_sparse_indexing = (x: Seq[String]) => x

  def const_condition(bool: Boolean) = (x: Seq[String]) => if (bool) "1" else "0"

  def const_condition(bool: String) = (x: Seq[String]) => if (bool == "true") "1" else "0"

}