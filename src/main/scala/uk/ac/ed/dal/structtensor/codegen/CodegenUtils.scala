package uk.ac.ed.dal
package structtensor
package codegen

import utils._
import compiler._
import Utils._

object CodegenUtils {

  def CPP_read_argv(argv_names: Seq[String]): String = argv_names.zipWithIndex
    .map { case (name, i) => s"const int $name = atoi(argv[${i + 1}]);" }
    .mkString("\n")

  def CPP_printerr(var_name: String, dimensions: Seq[String]) =
    s"cerr << $var_name[${dimensions.map(e => s"$e - 1").mkString("][")}] << endl;"

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
    return -1;
  }

  size_t min_val = arr[0];
  for (size_t i = 1; i < size; i++) {
    min_val = min2(min_val, arr[i]);
  }

  return min_val;
}

size_t max2(size_t a, size_t b) {
  return a > b ? a : b;
}

size_t max(size_t arr[], size_t size) {
  if (size == 0) {
    return -1;
  }

  size_t max_val = arr[0];
  for (size_t i = 1; i < size; i++) {
    max_val = max2(max_val, arr[i]);
  }

  return max_val;
}


int main(int argc, char **argv){
  srand(0);
"""

  def C_read_argv(argv_names: Seq[String]): String = CPP_read_argv(argv_names)

  def C_free(var_name: String): String = s"free($var_name);"

  def C_free(var_names: Seq[String]): String =
    var_names.map(C_free).mkString("\n")

  def C_return(): String = CPP_return()

  def C_convert_index(index: Index): String = {
    index match {
      case Variable(name) => name
      case Arithmetic(op, i1, i2) =>
        s"(${C_convert_index(i1)} ${op} ${C_convert_index(i2)})"
      case ConstantInt(i)    => i.toString
      case ConstantDouble(d) => d.toString
      case _                 => throw new Exception("Invalid index")
    }
  }

  def C_convert_condition(condition: SoP): (String, String) = {
    val conditions = condition.prods.flatMap { prod =>
      val expressions = prod.exps.collect {
        case Comparison(op, index, variable) =>
          s"${C_convert_index(index)} ${if (op == "=") "==" else op} ${variable.name}"
      }
      if (expressions.nonEmpty) Some(expressions.mkString(" && ")) else None
    }

    val flag = getVar("flag")
    val flagCode =
      if (conditions.nonEmpty) s"int $flag = ${conditions.mkString(" || ")};\n"
      else s"int $flag = 0;\n"
    (flag, flagCode)
  }

  def CPP_convert_condition(condition: SoP): (String, String) =
    C_convert_condition(condition)

  def C_alloc_and_gen_random_number(
      head: Access,
      dims: Seq[Dim],
      sopCond: SoP
  ): String = {
    dims match {
      case Nil => s"double ${head.name} = (double) (rand() % 1000000) / 1e6;"
      case _ => {
        val var_name = head.name
        val vars = head.vars
        val iter_seq = vars.map(_.name)
        val dimensions = dims.map(C_convert_index(_))
        val (flag, c11) = C_convert_condition(sopCond)
        val c0 =
          s"double ${"*" * dimensions.length} $var_name = malloc(sizeof(double ${"*" * (dimensions.length - 1)}) * ${dimensions.head});\n"
        val c1 = dimensions
          .zip(iter_seq)
          .zipWithIndex
          .map {
            case ((dim, i), n) => {
              val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
              val c_sub2 = if (n != dimensions.length - 1)
                s"$var_name[${iter_seq.slice(0, n + 1).mkString("][")}] = malloc(sizeof(double " + "*" * (dimensions.length - 2 - n) + s") * ${dimensions(n + 1)});\n"
              else ""
              c_sub1 + c_sub2
            }
          }
          .mkString("\n")
        val c2 =
          s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${iter_seq
              .mkString("][")}] = 0.0;\n" + s"}\n"
        val c3 = dimensions.map(_ => "}").mkString("\n")
        s"$c0$c1$c11$c2$c3"
      }
    }
  }

  def C_alloc_and_gen_zero(head: Access, dims: Seq[Dim]): String = {
    dims match {
      case Nil => s"double ${head.name} = 0.0;"
      case _ => {
        val var_name = head.name
        val vars = head.vars
        val iter_seq = vars.map(_.name)
        val dimensions = dims.map(C_convert_index(_))
        val c0 =
          s"double ${"*" * dimensions.length} $var_name = malloc(sizeof(double ${"*" * (dimensions.length - 1)}) * ${dimensions.head});\n"
        val c1 = dimensions
          .zip(iter_seq)
          .zipWithIndex
          .map {
            case ((dim, i), n) => {
              val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
              val c_sub2 = if (n != dimensions.length - 1)
                s"$var_name[${iter_seq.slice(0, n + 1).mkString("][")}] = malloc(sizeof(double " + "*" * (dimensions.length - 2 - n) + s") * ${dimensions(n + 1)});\n"
              else ""
              c_sub1 + c_sub2
            }
          }
          .mkString("\n")
        val c2 = s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n"
        val c3 = dimensions.map(_ => "}").mkString("\n")
        s"$c0$c1$c2$c3"
      }
    }
  }

  def CPP_alloc_and_gen_random_number(
      head: Access,
      dims: Seq[Dim],
      sopCond: SoP
  ): String = {
    dims match {
      case Nil => s"double ${head.name} = (double) (rand() % 1000000) / 1e6;"
      case _ => {
        val var_name = head.name
        val vars = head.vars
        val iter_seq = vars.map(_.name)
        val dimensions = dims.map(C_convert_index(_)).toSeq
        val (flag, c11) = CPP_convert_condition(sopCond)
        val c0 =
          s"double " + "*" * dimensions.length + s"$var_name = new double" + "*" * (dimensions.length - 1) + s"[${dimensions.head}];\n"
        val c1 = dimensions
          .zip(iter_seq)
          .zipWithIndex
          .map {
            case ((dim, i), n) => {
              val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
              val c_sub2 = if (n != dimensions.length - 1)
                s"$var_name[${iter_seq.slice(0, n + 1).mkString("][")}] = new double" + "*" * (dimensions.length - 2 - n) + s"[${dimensions(n + 1)}];\n"
              else ""
              c_sub1 + c_sub2
            }
          }
          .mkString("\n")
        val c2 =
          s"if ($flag) {\n" + s"$var_name[${iter_seq.mkString("][")}] = (double) (rand() % 1000000) / 1e6;\n" + s"} else {\n" + s"$var_name[${iter_seq
              .mkString("][")}] = 0.0;\n" + s"}\n"
        val c3 = dimensions.map(_ => "}").mkString("\n")
        s"$c0$c1$c11$c2$c3"
      }
    }
  }

  def CPP_alloc_and_gen_zero(head: Access, dims: Seq[Dim]): String = {
    dims match {
      case Nil => s"double ${head.name} = 0.0;"
      case _ => {
        val var_name = head.name
        val vars = head.vars
        val iter_seq = vars.map(_.name)
        val dimensions = dims.map(C_convert_index(_)).toSeq
        val c0 =
          s"double " + "*" * dimensions.length + s"$var_name = new double" + "*" * (dimensions.length - 1) + s"[${dimensions.head}];\n"
        val c1 = dimensions
          .zip(iter_seq)
          .zipWithIndex
          .map {
            case ((dim, i), n) => {
              val c_sub1 = s"for (size_t $i = 0; $i < $dim; ++$i) {\n"
              val c_sub2 = if (n != dimensions.length - 1)
                s"$var_name[${iter_seq.slice(0, n + 1).mkString("][")}] = new double" + "*" * (dimensions.length - 2 - n) + s"[${dimensions(n + 1)}];\n"
              else ""
              c_sub1 + c_sub2
            }
          }
          .mkString("\n")
        val c2 = s"$var_name[${iter_seq.mkString("][")}] = 0.0;\n"
        val c3 = dimensions.map(_ => "}").mkString("\n")
        s"$c0$c1$c2$c3"
      }
    }
  }

  def CPP_printerr(access: Access): String = access.vars.isEmpty match {
    case true => s"cerr << ${access.name} << endl;"
    case false =>
      s"cerr << ${access.name}[${access.vars.map(e => s"0").mkString("][")}] << endl;"
  }

  def C_printerr(access: Access): String = access.vars.isEmpty match {
    case true => s"""fprintf(stderr, "%f\\n", ${access.name});"""
    case false =>
      s"""fprintf(stderr, "%f\\n", ${access.name}[${access.vars
          .map(e => s"0")
          .mkString("][")}]);"""
  }

  def CPP_free(var_name: String, dims: Seq[Dim]) = {
    val dimensions = dims.map(C_convert_index(_))
    val c0 = dimensions.init.zipWithIndex
      .map { case (dim, i) => s"for (size_t i$i = 0; i$i < $dim; ++i$i) {" }
      .mkString("\n")
    val iter_seq: Seq[String] = dimensions.tail.zipWithIndex.map {
      case (_, id) => s"i$id"
    }
    val c1 = iter_seq.zipWithIndex
      .map { case (iter, i) =>
        s"delete[] $var_name[${iter_seq.slice(0, iter_seq.length - i).mkString("][")}];\n}"
      }
      .mkString("\n")
    val c2 = s"delete[] $var_name;"
    s"$c0$c1$c2"
  }

  def init_code(lang: String): String = lang.toUpperCase() match {
    case "C"   => C_init_code()
    case "CPP" => CPP_init_code()
    case _     => throw new Exception("Unknown code language")
  }

  def read_argv(lang: String, argv_names: Seq[String]): String =
    lang.toUpperCase() match {
      case "C"   => C_read_argv(argv_names)
      case "CPP" => CPP_read_argv(argv_names)
      case _     => throw new Exception("Unknown code language")
    }

  def alloc_and_gen_random_number(
      lang: String,
      head: Access,
      dims: Seq[Dim],
      sopCond: SoP
  ): String = lang.toUpperCase() match {
    case "C"   => C_alloc_and_gen_random_number(head, dims, sopCond)
    case "CPP" => CPP_alloc_and_gen_random_number(head, dims, sopCond)
    case _     => throw new Exception("Unknown code language")
  }

  def alloc_and_gen_zero(lang: String, head: Access, dims: Seq[Dim]): String =
    lang.toUpperCase() match {
      case "C"   => C_alloc_and_gen_zero(head, dims)
      case "CPP" => CPP_alloc_and_gen_zero(head, dims)
      case _     => throw new Exception("Unknown code language")
    }

  def printerr(lang: String, head: Access): String = lang.toUpperCase() match {
    case "C"   => C_printerr(head)
    case "CPP" => CPP_printerr(head)
    case _     => throw new Exception("Unknown code language")
  }

  def free(lang: String, var_name: String, dims: Seq[Dim]) =
    lang.toUpperCase() match {
      case "C"   => C_free(var_name)
      case "CPP" => CPP_free(var_name, dims)
      case _     => throw new Exception("Unknown code language")
    }

  def return_code(lang: String): String = lang.toUpperCase() match {
    case "C"   => C_return()
    case "CPP" => CPP_return()
    case _     => throw new Exception("Unknown code language")
  }

}
