package uk.ac.ed.dal
package structtensor
package codegen

import utils._
import compiler._

object Bodygen {
  import Shared._
  def apply(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], uniqueSets: Map[Access, Rule], initTensors: Boolean, symbols: Seq[Variable]): (String, String) = {
    (generateInit(codeLang, rules, all_tensors, all_dimensions, uniqueSets, initTensors, symbols), generateEnd(codeLang, rules, all_tensors, all_dimensions, initTensors))
  }

  def generateInit(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], uniqueSets: Map[Access, Rule], initTensors: Boolean, symbols: Seq[Variable]): String = {
    initTensors match {
      case true => {
        val c1 = init_code(codeLang)
        val dim_names: Seq[String] = all_dimensions.values.flatMap(_.collect {
          case Variable(name) => name
        }).toSeq
        val argv_names = (dim_names ++ unboundVariables(rules).toSeq.diff(dim_names)).distinct
        val only_lhs_heads = rules.map(_.head).distinctBy(_.name).filter(_.kind == Tensor)
        val all_vars = allVariables(rules).toSeq
        val c2 = read_argv(codeLang, argv_names)
        val c3 = all_tensors.distinctBy(_.name).filter(_.kind == Tensor).filterNot(only_lhs_heads.contains).map(t => alloc_and_gen_random_number(codeLang, t, all_dimensions(t), uniqueSets.getOrElse(t, emptyRule()).body)).mkString("\n")
        val c4 = only_lhs_heads.map(t => alloc_and_gen_zero(codeLang, t, all_dimensions(t))).mkString("\n")
        c1 + "\n" + c2 + "\n" + c3 + "\n" + c4  
      }
      case false => {
        val c1 = """
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;
"""
      val tensor_to_str = all_tensors.distinctBy(_.name).map(t => "double " + (if (t.vars.isEmpty) "&" else "*" * t.vars.length) + " " + t.name).mkString(", ")
      val symbols_to_str = symbols.map(v => "int " + v.name).mkString(", ")
      val c2 = s"void fn($tensor_to_str, $symbols_to_str) {\n"
      c1 + c2
      }
    }
    
  }

  def generateEnd(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], initTensors: Boolean): String = {
    initTensors match {
      case true => {
        val c1 = all_tensors.map(t => printerr(codeLang, t)).mkString("\n")
        val c2 = all_tensors.distinctBy(_.name).map(t => free(codeLang, t.name, all_dimensions(t))).mkString("\n")
        val c3 = return_code(codeLang)
        c1 + "\n" + c2 + "\n" + c3
      }
      case false => "\n}"
    }
  }
}