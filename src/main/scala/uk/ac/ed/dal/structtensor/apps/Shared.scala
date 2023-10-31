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

  def C_convert_index(index: Index): String = {
    index match {
      case Variable(name) => name
      case Arithmetic(op, i1, i2) => s"(${C_convert_index(i1)} ${op} ${C_convert_index(i2)})"
      case ConstantInt(i) => i.toString
      case ConstantDouble(d) => d.toString
      case _ => throw new Exception("Invalid index")
    }
  }

  def C_convert_condition(condition: SoP): (String, String) = {
    val res = condition.prods.foldLeft("")((acc, p) => {
      val res2 = p.exps.foldLeft("")((acc2, e) => {
        e match {
          case Comparison(op, index, variable) => {
            acc2 + " && " + C_convert_index(index) + " " + (if (op == "=") "==" else op) + " " + variable.name
          }
          case _ => acc2
        }
      })
      acc + " || " + res2.slice(4, res2.length)
    })
    val flag = getVar("flag")
    val fl_code = "int " + flag + " = " + (if (res.slice(4, res.length).length == 0) "0" else res.slice(4, res.length)) + ";\n"
    (flag, fl_code)
  }

  def CPP_convert_condition(condition: SoP): (String, String) = C_convert_condition(condition)


  def C_alloc_and_gen_random_number(head: Access, dims: Seq[Dim], sopCond: SoP): String = {
    val var_name = head.name
    val vars = head.vars
    val iter_seq = vars.map(_.name)
    val dimensions = dims.map(C_convert_index(_))
    val (flag, c11) = C_convert_condition(sopCond)    
    val c0 = if (dimensions.length == 1) s"double (*$var_name) = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n" else s"double (*$var_name)[${dimensions.slice(1, dimensions.length).mkString("][")}] = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n"
    val c1 = dimensions.zip(iter_seq).foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
      acc + c_sub1
    })
    val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c11$c2$c3"
  }

  def CPP_alloc_and_gen_random_number(head: Access, dims: Seq[Dim], sopCond: SoP): String = {
    val var_name = head.name
    val vars = head.vars
    val iter_seq = vars.map(_.name)
    val dimensions = dims.map(C_convert_index(_)).toSeq
    val (flag, c11) = CPP_convert_condition(sopCond)
    val c0 = s"double " + "*" * dimensions.length + s"$var_name = new double" + "*" * (dimensions.length - 1) + s"[${dimensions(0)}];\n"
    val c1 = dimensions.zip(iter_seq).zipWithIndex.foldLeft("")((acc, dimIdNum) => {
      val ((dim, i), n) = dimIdNum
      val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
      val c_sub2 = if (n != dimensions.length - 1) s"$var_name[${iter_seq.slice(0, n + 1).mkString("][")}] = new double" + "*" * (dimensions.length - 2 - n) + s"[${dimensions(n + 1)}];\n" else ""
      acc + c_sub1 + c_sub2
    })
    val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c11$c2$c3"
  }

  def MLIR_generate_arith(op: String, i1: String, i2: String, output_var: String, op_type: Int = 0): String = {
    val tp = if (op_type == 0) "i32" else "index"
    op match {
      case "%" => s"""$output_var = "arith.remui"($i1, $i2) : ($tp, $tp) -> $tp"""
      case "+" => s"""$output_var = "arith.addi"($i1, $i2) : ($tp, $tp) -> $tp"""
      case "-" => s"""$output_var = "arith.subi"($i1, $i2) : ($tp, $tp) -> $tp"""
      case "*" => s"""$output_var = "arith.muli"($i1, $i2) : ($tp, $tp) -> $tp"""
      case "/" => s"""$output_var = "arith.divui"($i1, $i2) : ($tp, $tp) -> $tp"""
      case _ => throw new Exception("Invalid arithmetic operator")
    }
  }

  def MLIR_convert_index(index: Index, op_type: Int = 0): (String, String) = {
    index match {
      case Variable(name) => (s"%$name", "")
      case Arithmetic(op, i1, i2) => {
        val (arith_var1, arith_code1) = MLIR_convert_index(i1, op_type)
        val (arith_var2, arith_code2) = MLIR_convert_index(i2, op_type)
        val arith_var = getVar("%arith_var")
        val arith_code = MLIR_generate_arith(op, arith_var1, arith_var2, arith_var, op_type)
        (arith_var, arith_code1 + "\n" + arith_code2 + "\n" + arith_code + "\n")
      }
      case ConstantInt(i) => {
        val tp = if (op_type == 0) "i32" else "index"
        val var_name = getVar("%consti")
        (var_name, s"""$var_name = "arith.constant"() {value = $i : $tp} : () -> $tp""")
      }
      case ConstantDouble(d) => {
        val tp = "f64"
        val var_name = getVar("%constf")
        (var_name, s"""$var_name = "arith.constant"() {value = $d : $tp} : () -> $tp""")
      }
      case _ => throw new Exception("Invalid index")
    }
  }

  def MLIR_comp_to_predicate(op: String): String = op match {
    case "<" => "2" // "slt"
    case ">" => "4" // "sgt"
    case "<=" => "3" // "sle"
    case ">=" => "5" // "sge"
    case "==" => "0" // "eq"
    case "=" => "0" //"eq"
    case "!=" => "1" // "ne"
    case _ => throw new Exception("Invalid comparison operator")
  }

  def MLIR_convert_condition(condition: SoP): (String, String) = {
    val orFlag = getVar("%orFlag")
    val andFlag = getVar("%andFlag")
    val orFlagCode = s"""$orFlag = "arith.constant"() {value = 0 : i1} : () -> i1"""
    val andFlagCode = s"""$andFlag = "arith.constant"() {value = 1 : i1} : () -> i1"""
    val (flag, res) = condition.prods.foldLeft((orFlag, ""))((acc, p) => {
      val (flag2, res2) = p.exps.foldLeft((andFlag, ""))((acc2, e) => {
        e match {
          case Comparison(op, index, variable) => {
            val f = getVar("%andFlag")
            val cmp_var = getVar("%cmpFlag")
            val pred = MLIR_comp_to_predicate(op)
            val (arith_var, arith_code) = MLIR_convert_index(index, 1)
            val cmp_code = s"""$cmp_var = "arith.cmpi"($arith_var, %${variable.name}) {predicate = $pred : i64} : (index, index) -> i1"""
            val and_code = s"""$f = "arith.andi"(${acc2._1}, $cmp_var) : (i1, i1) -> i1"""
            (f, acc2._2 + "\n" + arith_code + "\n" + cmp_code + "\n" + and_code + "\n")
          }
          case _ => acc2
        }
      })
      val fflag = getVar("%orFlag")
      val or_code = s"""$fflag = "arith.ori"(${acc._1}, $flag2) : (i1, i1) -> i1"""
      (fflag, acc._2 + "\n" + res2 + "\n" + or_code + "\n")
    })
    (flag, orFlagCode + "\n" + andFlagCode + "\n" + res)
  }

  def MLIR_alloc_and_gen_random_number(head: Access, dims: Seq[Dim], sopCond: SoP): String = {
    val var_name = head.name
    val vars = head.vars
    val iter_seq = vars.map(_.name)
    val dimsAndCode: Seq[(String, String)] = dims.map(MLIR_convert_index(_))
    val dimensions = dimsAndCode.map(_._1)
    val dimensions_code = dimsAndCode.map(_._2).mkString("\n")
    val c0 = s"%$var_name = memref.alloc(${dimensions.mkString(", ")}) : memref<${"?x" * dimensions.length}f64>"

    val (flag, c11) = MLIR_convert_condition(sopCond)
    
    val c1 = dimensions.zip(iter_seq).foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      acc + s"""
    "scf.for"(%0, $dim, %1) ({
    ^bb0(%$i: index):
"""
    })
    val ivars = iter_seq.map(e => s"%$e").mkString(", ")
    val qvars = dimensions.map(e => s"?").mkString("x") + "x"
    val index_vars = dimensions.map(e => s"index").mkString(", ")

    val rval1 = getVar("rval")
    val rval2 = getVar("rval")
    val rval3 = getVar("rval")
    val rval4 = getVar("rval")
    val c2 = s"""
    "scf.if"(${flag}) ({
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
    return s"$dimensions_code\n$c0\n$c1\n$c11\n$c2\n$c3"
  }

  def MLIR_timer_end(): String = """
%time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
"func.call"(%time) {callee = @print_i64} : (i64) -> ()"""

  def CPP_printerr(access: Access): String = s"cerr << ${access.name}[${access.vars.map(e => s"0").mkString("][")}] << endl;"

  def C_printerr(access: Access): String = s"""fprintf(stderr, "%f\\n", ${access.name}[${access.vars.map(e => s"0").mkString("][")}]);"""

  def MLIR_printerr(access: Access): String = s"""
  %last = "memref.load"(%${access.name}${", %0" * access.vars.length}) : (memref<${"?x" * access.vars.length}f64>${", index" * access.vars.length}) -> f64
  "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
  """

  def CPP_free(var_name: String, dims: Seq[Dim]) = {
    val dimensions = dims.map(C_convert_index(_))
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

  def MLIR_return(): String = """"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
"""
  
  
  def init_code(lang: String): String = lang match {
    case "C" => C_init_code()
    case "CPP" => CPP_init_code()
    case "MLIR" => MLIR_init_code()
    case _ => throw new Exception("Unknown code language")
  }

  def read_argv(lang: String, argv_names: Seq[String]): String = lang match {
    case "C" => C_read_argv(argv_names)
    case "CPP" => CPP_read_argv(argv_names)
    case "MLIR" => MLIR_read_argv(argv_names)
    case _ => throw new Exception("Unknown code language")
  }

  def alloc_and_gen_random_number(lang: String, head: Access, dims: Seq[Dim], sopCond: SoP): String = lang match {
    case "C" => C_alloc_and_gen_random_number(head, dims, sopCond)
    case "CPP" => CPP_alloc_and_gen_random_number(head, dims, sopCond)
    case "MLIR" => MLIR_alloc_and_gen_random_number(head, dims, sopCond)
    case _ => throw new Exception("Unknown code language")
  }

  def init_timer(lang: String): String = lang match {
    case "C" => C_timer_start()
    case "CPP" => CPP_timer_start()
    case "MLIR" => MLIR_start_timer_code()
    case _ => throw new Exception("Unknown code language")
  }

  def end_timer(lang: String): String = lang match {
    case "C" => C_timer_end()
    case "CPP" => CPP_timer_end()
    case "MLIR" => MLIR_timer_end()
    case _ => throw new Exception("Unknown code language")
  }

  def printerr(lang: String, head: Access): String = lang match {
    case "C" => C_printerr(head)
    case "CPP" => CPP_printerr(head)
    case "MLIR" => MLIR_printerr(head)
    case _ => throw new Exception("Unknown code language")
  }

  def free(lang: String, var_name: String, dims: Seq[Dim]) = lang match {
    case "C" => C_free(var_name)
    case "CPP" => CPP_free(var_name, dims)
    case "MLIR" => ""
    case _ => throw new Exception("Unknown code language")
  }

  def return_code(lang: String): String = lang match {
    case "C" => C_return()
    case "CPP" => CPP_return()
    case "MLIR" => MLIR_return()
    case _ => throw new Exception("Unknown code language")
  }

}