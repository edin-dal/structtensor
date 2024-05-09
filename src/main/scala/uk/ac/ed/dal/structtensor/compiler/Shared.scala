package uk.ac.ed.dal
package structtensor
package compiler

import java.io._ 

object Shared {
  def write2File(filename: String, s: String, append: Boolean = false): Unit = {
    val bw = new BufferedWriter(new FileWriter(new File(filename), append))
    bw.write(s)
    bw.close()
  }

  var cnt = 0
  def getVar(name: String): String = {
    cnt += 1
    return s"$name$cnt"
  }

  def emptyProd(): Prod = Prod(Seq[Exp]())

  def emptySoP(): SoP = SoP(Seq[Prod]())

  def emptyAccess(): Access = Access("", Seq[Variable](), Tensor)

  def emptyRule(): Rule = Rule(emptyAccess(), emptySoP())

  def emptyDimInfo(): DimInfo = DimInfo(emptyAccess(), Seq.empty[Dim])

  def trueComparison(): Comparison = Comparison("<=", "0".toVar, "0".toVar)

  def prodTimesProd(prod1: Prod, prod2: Prod): Prod = {
    if (prod1.exps.size == 0 || prod2.exps.size == 0) emptyProd()
    else Prod(prod1.exps ++ prod2.exps)
  } 

  def prodMult(prods: Seq[Prod]): Prod = {
    if (prods.size == 0) emptyProd()
    else prods.slice(1, prods.size).foldLeft(prods(0))((acc, cur) => prodTimesProd(acc, cur))
  }

  def prodTimesSoP(prod: Prod, sop: SoP): SoP = {
    if (prod.exps.size == 0 || sop.prods.size == 0) emptySoP()
    else {
      val prods: Seq[Prod] = sop.prods.foldLeft(Seq[Prod]())((acc, cur) => acc :+ prodTimesProd(prod, cur))
      SoP(prods)
    }
  }

  def SoPTimesSoP(sop1: SoP, sop2: SoP): SoP = {
    if (sop1.prods.size == 0 || sop2.prods.size == 0) emptySoP()
    else {
      val prods: Seq[Prod] = sop1.prods.foldLeft(Seq[Prod]())((acc, cur) => acc ++ prodTimesSoP(cur, sop2).prods)
      SoP(prods)
    }
  }

  def multSoP(sops: Seq[SoP]): SoP = {
    if (sops.size == 0) emptySoP()
    else sops.slice(1, sops.length).foldLeft(sops(0))((acc, cur) => SoPTimesSoP(acc, cur))
  } 

  def mergeMap[A, B](ms: Seq[Map[A, B]])(f: (B, B) => B): Map[A, B] = ms.flatten.foldLeft(Map[A, B]())((a, kv) => a + (if (a.contains(kv._1)) (kv._1 -> f(a(kv._1), kv._2)) else kv))

  implicit class DimInfoOps(d: DimInfo) {
    def toAccessMap: Map[Access, Seq[Dim]] = Map[Access, Seq[Dim]](d.access -> d.dims)
    def toVarsMap: Map[Variable, Seq[Dim]] = (d.access.vars zip d.dims).foldLeft(Map.empty[Variable, Seq[Dim]])((acc, cur) => acc + (cur._1 -> Seq(cur._2)))
    def toComparisonVariableProdMap: Map[Variable, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Variable, Prod])((acc, cur) => 
    mergeMap(Seq(acc, Map(cur._1 -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonAccessProdMap: Map[Access, Prod] = (d.access.vars zip d.dims).foldLeft(Map.empty[Access, Prod])((acc, cur) => 
    mergeMap(Seq(acc, Map(d.access -> Prod(Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonProd: Prod = Prod((d.access.vars zip d.dims).foldLeft(Seq[Exp]())((acc, cur) => 
    acc ++ Seq(Comparison("<=", ConstantInt(0), cur._1), Comparison(">", cur._2, cur._1))))
    def toSoP: SoP = SoP(Seq(Prod((d.access.vars zip d.dims).foldLeft(Seq.empty[Exp])((acc, varDim) => acc ++ Seq(Comparison("<=", ConstantInt(0), varDim._1), Comparison(">", varDim._2, varDim._1))))))
  }

  implicit class SeqDimInfoOps(d: Seq[DimInfo]) {
    def toAccessMap: Map[Access, Seq[Dim]] = d.foldLeft(Map.empty[Access, Seq[Dim]])((acc, cur) => mergeMap(Seq(acc, cur.toAccessMap))((v1, v2) => v1 ++ v2))
    def toVarsMap: Map[Variable, Seq[Dim]] = d.foldLeft(Map.empty[Variable, Seq[Dim]])((acc, cur) => mergeMap(Seq(acc, cur.toVarsMap))((v1, v2) => v1 ++ v2))
    def toComparisonVariableProdMap: Map[Variable, Prod] = d.foldLeft(Map.empty[Variable, Prod])((acc, cur) => mergeMap(Seq(acc, cur.toComparisonVariableProdMap))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonAccessProdMap: Map[Access, Prod] = d.foldLeft(Map.empty[Access, Prod])((acc, cur) => mergeMap(Seq(acc, cur.toComparisonAccessProdMap))((v1, v2) => prodTimesProd(v1, v2)))
    def toComparisonProd: Prod = prodMult(d.foldLeft(Seq[Prod]())((acc, cur) => acc :+ cur.toComparisonProd))
  }

  implicit class StringOps(s: String) {
    def uniqueName = s"${s}_US"
    def redundancyName = s"${s}_RM"
    def compressedName = s"${s}_C"
    def dimensionName = s"${s}_D"
    def toVar: Variable = Variable(s)
    def redundancyVars: Variable = s.toVar.redundancyVars
  }

  implicit class VariableOps(v: Variable) {
    def redundancyVars = Variable(s"${v.name}p")
    def toAccess(kind: AccessType): Access = Access("", Seq(v), kind)
  }

  implicit class SeqVariableOps(v: Seq[Variable]) {
    def redundancyVars = v.foldLeft(Seq[Variable]())((acc, cur) => acc :+ cur.redundancyVars)
    def redundancyVarsInplace = v ++ v.redundancyVars
    def toAccess(kind: AccessType): Access = Access("", v, kind)
  }

  def concatSoP(sops: Seq[SoP]): SoP = {
    val prods: Seq[Prod] = sops.foldLeft(Seq[Prod]())((acc, cur) => acc ++ cur.prods)
    SoP(prods)
  }

  def MLIR_init_code(): String = s"""
"builtin.module"() ({
  "func.func"() ({}) {function_type = (!llvm.ptr) -> i32, sym_name = "atoi", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "srand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i32), sym_name = "rand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "print_i32", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (), sym_name = "print_i64", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (f64) -> (), sym_name = "print_f64_cerr", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i64), sym_name = "timer", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (i64), sym_name = "timer_elapsed", sym_visibility = "private"} : () -> ()

  "func.func"() ({
    ^bb0(%argc : i32, %argv : !llvm.ptr):
    %const_val_0 = "arith.constant"() {"value" = 0 : index} : () -> index
    %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
    %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
    %onef = "arith.constant"() {"value" = 1.0 : f64} : () -> f64
    %const_val_1 = "arith.constant"() {"value" = 1 : index} : () -> index
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
    %argvv$id = llvm.getelementptr %argv[$id] : (!llvm.ptr) -> !llvm.ptr, !llvm.ptr
    %argv$id = "llvm.load"(%argvv$id) : (!llvm.ptr) -> !llvm.ptr
    %${name}i32 = "func.call"(%argv$id) {callee = @atoi} : (!llvm.ptr) -> i32
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
    "scf.for"(%const_val_0, %$dim, %const_val_1) ({
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
//     val c2 = s"""
//     "scf.if"(%${condition._2}) ({
//       "memref.store"(%onef, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
//       "scf.yield"() : () -> ()
//     }, {
//       "memref.store"(%zerof, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
//       "scf.yield"() : () -> ()
//     }) : (i1) -> ()
// """
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

  def MLIR_start_timer_code(postfix: String = ""): String = s"""
    %stime$postfix = "func.call"() {callee = @timer} : () -> i64
"""

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

  def CPP_timer_start(postfix: String = ""): String = s"long time$postfix = 0, start$postfix, end$postfix;\nstart$postfix = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();"

  def CPP_timer_end(postfix: String = ""): String = s"end$postfix = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();\ntime$postfix = end$postfix - start$postfix;\ncout << time$postfix << endl;"

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

size_t min2(size_t a, size_t b) {
  return a < b ? a : b;
}

size_t min(size_t arr[], size_t size) {
  if (size == 0) {
    // Return some sentinel value or handle error
    return -1;
  }

  size_t min_val = arr[0];
  for (size_t i = 1; i < size; i++) {
    min_val = min2(min_val, arr[i]);
  }

  return min_val;
}


int main(int argc, char **argv){
  srand(0);
"""

  def C_read_argv(argv_names: Seq[String]): String = CPP_read_argv(argv_names)

  def C_timer_start(postfix: String = ""): String = s"struct timespec start$postfix = timer_start();"

  def C_timer_end(postfix: String = ""): String = s"long time$postfix = timer_end(start$postfix);" + "\nprintf(\"%ld\\n\", " + s"time$postfix);"

  def C_free(var_name: String): String = s"free($var_name);"

  def C_free(var_names: Seq[String]): String = var_names.foldLeft("")((acc, var_name) => s"$acc${C_free(var_name)}\n")

  def C_return(): String = CPP_return()
  
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
    // val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) 1.0;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c11$c2$c3"
  }

  def C_alloc_and_gen_zero(head: Access, dims: Seq[Dim]): String = {
    val var_name = head.name
    val vars = head.vars
    val iter_seq = vars.map(_.name)
    val dimensions = dims.map(C_convert_index(_))
    val c0 = if (dimensions.length == 1) s"double (*$var_name) = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n" else s"double (*$var_name)[${dimensions.slice(1, dimensions.length).mkString("][")}] = malloc(sizeof(double) * ${dimensions.mkString(" * ")});\n"
    val c1 = dimensions.zip(iter_seq).foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
      acc + c_sub1
    })
    // val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c2 = s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c2$c3"
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
    // val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) 1.0;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c11$c2$c3"
  }

  def CPP_alloc_and_gen_zero(head: Access, dims: Seq[Dim]): String = {
    val var_name = head.name
    val vars = head.vars
    val iter_seq = vars.map(_.name)
    val dimensions = dims.map(C_convert_index(_)).toSeq
    val c0 = s"double " + "*" * dimensions.length + s"$var_name = new double" + "*" * (dimensions.length - 1) + s"[${dimensions(0)}];\n"
    val c1 = dimensions.zip(iter_seq).zipWithIndex.foldLeft("")((acc, dimIdNum) => {
      val ((dim, i), n) = dimIdNum
      val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
      val c_sub2 = if (n != dimensions.length - 1) s"$var_name[${iter_seq.slice(0, n + 1).mkString("][")}] = new double" + "*" * (dimensions.length - 2 - n) + s"[${dimensions(n + 1)}];\n" else ""
      acc + c_sub1 + c_sub2
    })
    val c2 = s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n"
    // val c2 = s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) 1.0;\n" + s"} else {\n" + s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n" + s"}\n"
    val c3 = dimensions.foldLeft("")((acc, dim) => acc + "}\n")
    s"$c0$c1$c2$c3"
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
    val dimsAndCode: Seq[(String, String)] = dims.map(d => MLIR_convert_index(d, 1))
    val dimensions = dimsAndCode.map(_._1)
    val dimensions_code = dimsAndCode.map(_._2).mkString("\n")
    val c0 = s"%$var_name = memref.alloc(${dimensions.mkString(", ")}) : memref<${"?x" * dimensions.length}f64>"

    val (flag, c11) = MLIR_convert_condition(sopCond)
    
    val c1 = dimensions.zip(iter_seq).foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      acc + s"""
    "scf.for"(%const_val_0, $dim, %const_val_1) ({
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


  def MLIR_alloc_and_gen_zero(head: Access, dims: Seq[Dim]): String = {
    val var_name = head.name
    val vars = head.vars
    val iter_seq = vars.map(_.name)
    val dimsAndCode: Seq[(String, String)] = dims.map(d => MLIR_convert_index(d, 1))
    val dimensions = dimsAndCode.map(_._1)
    val dimensions_code = dimsAndCode.map(_._2).mkString("\n")
    val c0 = s"%$var_name = memref.alloc(${dimensions.mkString(", ")}) : memref<${"?x" * dimensions.length}f64>"

    
    val c1 = dimensions.zip(iter_seq).foldLeft("")((acc, dimId) => {
      val (dim, i) = dimId
      acc + s"""
    "scf.for"(%const_val_0, $dim, %const_val_1) ({
    ^bb0(%$i: index):
"""
    })
    val ivars = iter_seq.map(e => s"%$e").mkString(", ")
    val qvars = dimensions.map(e => s"?").mkString("x") + "x"
    val index_vars = dimensions.map(e => s"index").mkString(", ")

     val c2 = s"""
      "memref.store"(%zerof, %$var_name, $ivars): (f64, memref<${qvars}f64>, $index_vars) -> ()
"""

    val c3 = dimensions.foldLeft("")((acc, dim) => {
      acc + s"""
    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()
"""
    })
    return s"$dimensions_code\n$c0\n$c1\n$c2\n$c3"
  }

  def MLIR_timer_end(postfix: String = ""): String = s"""
%time$postfix = "func.call"(%stime$postfix) {callee = @timer_elapsed} : (i64) -> i64
"func.call"(%time$postfix) {callee = @print_i64} : (i64) -> ()"""

  def CPP_printerr(access: Access): String = s"cerr << ${access.name}[${access.vars.map(e => s"0").mkString("][")}] << endl;"

  def C_printerr(access: Access): String = s"""fprintf(stderr, "%f\\n", ${access.name}[${access.vars.map(e => s"0").mkString("][")}]);"""

  def MLIR_printerr(access: Access): String = {
    val last = getVar("%last")
    s"""
$last = "memref.load"(%${access.name}${", %const_val_0" * access.vars.length}) : (memref<${"?x" * access.vars.length}f64>${", index" * access.vars.length}) -> f64
"func.call"($last) {callee = @print_f64_cerr} : (f64) -> ()
"""
  }

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

  def MLIR_free(var_name: String, dims: Seq[Dim]) = {
    val dim_str = "?x" * dims.length
    s""""memref.dealloc"(%$var_name) : (memref<${dim_str}f64>) -> ()"""
  }

  def MLIR_return(): String = """"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
"""
  
  
  def init_code(lang: String): String = lang.toUpperCase() match {
    case "C" => C_init_code()
    case "CPP" => CPP_init_code()
    case "MLIR" => MLIR_init_code()
    case "SNIPPETS" => MLIR_init_code()
    case _ => throw new Exception("Unknown code language")
  }

  def read_argv(lang: String, argv_names: Seq[String]): String = lang.toUpperCase() match {
    case "C" => C_read_argv(argv_names)
    case "CPP" => CPP_read_argv(argv_names)
    case "MLIR" => MLIR_read_argv(argv_names)
    case "SNIPPETS" => MLIR_read_argv(argv_names)
    case _ => throw new Exception("Unknown code language")
  }

  def alloc_and_gen_random_number(lang: String, head: Access, dims: Seq[Dim], sopCond: SoP): String = lang.toUpperCase() match {
    case "C" => C_alloc_and_gen_random_number(head, dims, sopCond)
    case "CPP" => CPP_alloc_and_gen_random_number(head, dims, sopCond)
    case "MLIR" => MLIR_alloc_and_gen_random_number(head, dims, sopCond)
    case "SNIPPETS" => MLIR_alloc_and_gen_random_number(head, dims, sopCond)
    case _ => throw new Exception("Unknown code language")
  }

  def alloc_and_gen_zero(lang: String, head: Access, dims: Seq[Dim]): String = lang.toUpperCase() match {
    case "C" => C_alloc_and_gen_zero(head, dims)
    case "CPP" => CPP_alloc_and_gen_zero(head, dims)
    case "MLIR" => MLIR_alloc_and_gen_zero(head, dims)
    case "SNIPPETS" => MLIR_alloc_and_gen_zero(head, dims)
    case _ => throw new Exception("Unknown code language")
  }

  def init_timer(lang: String, postfix: String = ""): String = lang.toUpperCase() match {
    case "C" => C_timer_start(postfix=postfix)
    case "CPP" => CPP_timer_start(postfix=postfix)
    case "MLIR" => MLIR_start_timer_code(postfix=postfix)
    case "SNIPPETS" => MLIR_start_timer_code(postfix=postfix)
    case _ => throw new Exception("Unknown code language")
  }

  def end_timer(lang: String, postfix: String = ""): String = lang.toUpperCase() match {
    case "C" => C_timer_end(postfix=postfix)
    case "CPP" => CPP_timer_end(postfix=postfix)
    case "MLIR" => MLIR_timer_end(postfix=postfix)
    case "SNIPPETS" => MLIR_timer_end(postfix=postfix)
    case _ => throw new Exception("Unknown code language")
  }

  def printerr(lang: String, head: Access): String = lang.toUpperCase() match {
    case "C" => C_printerr(head)
    case "CPP" => CPP_printerr(head)
    case "MLIR" => MLIR_printerr(head)
    case "SNIPPETS" => MLIR_printerr(head)
    case _ => throw new Exception("Unknown code language")
  }

  def free(lang: String, var_name: String, dims: Seq[Dim]) = lang.toUpperCase() match {
    case "C" => C_free(var_name)
    case "CPP" => CPP_free(var_name, dims)
    case "MLIR" => MLIR_free(var_name, dims)
    case "SNIPPETS" => MLIR_free(var_name, dims)
    case _ => throw new Exception("Unknown code language")
  }

  def return_code(lang: String): String = lang.toUpperCase() match {
    case "C" => C_return()
    case "CPP" => CPP_return()
    case "MLIR" => MLIR_return()
    case "SNIPPETS" => MLIR_return()
    case _ => throw new Exception("Unknown code language")
  }

  def unboundVariables(rules: Seq[Rule]): Set[String] = allVariables(rules).diff(boundVariables(rules))

  def allVariables(index: Index): Set[String] = {
    index match {
      case Variable(name) => Set(name)
      case Arithmetic(_, i1, i2) => allVariables(i1) ++ allVariables(i2)
      case _ => Set.empty[String]
    }
  }

  def allVariables(rules: Seq[Rule]): Set[String] = {
    rules.flatMap { r =>
      r.head.vars.map(_.name).toSet ++ 
      r.body.prods.flatMap(_.exps.collect {
        case Access(_, vars, _) => vars.map(_.name).toSet
        case Comparison(_, index, variable) => allVariables(index) + variable.name
      }).flatten.toSet
    }.toSet
  }

  def boundVariables(rules: Seq[Rule]): Set[String] = {
    rules.flatMap { r =>
      r.head.vars.map(_.name).toSet ++
      r.body.prods.flatMap(_.exps.collect {
        case Access(_, vars, _) => vars.map(_.name).toSet
      }).flatten
    }.toSet
  }

}