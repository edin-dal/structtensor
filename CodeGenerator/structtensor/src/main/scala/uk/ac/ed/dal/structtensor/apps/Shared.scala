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

}