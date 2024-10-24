package uk.ac.ed.dal
package structtensor
package codegen

import utils._
import Utils._
import compiler._
import CodegenUtils._

import scala.util.matching.Regex

object Bodygen {
  def apply(
      codeLang: String,
      rules: Seq[Rule],
      all_tensors: Seq[Access],
      all_dimensions: Map[Access, Seq[Dim]],
      uniqueSets: Map[Access, Rule],
      initTensors: Boolean,
      symbols: Seq[Variable],
      outputs_names: Seq[String]
  ): (String, String) = {
    (
      generateInit(
        codeLang,
        rules,
        all_tensors,
        all_dimensions,
        uniqueSets,
        initTensors,
        symbols,
        outputs_names
      ),
      generateEnd(
        codeLang,
        rules,
        all_tensors,
        all_dimensions,
        initTensors,
        outputs_names
      )
    )
  }

  def generateInit(
      codeLang: String,
      rules: Seq[Rule],
      all_tensors: Seq[Access],
      all_dimensions: Map[Access, Seq[Dim]],
      uniqueSets: Map[Access, Rule],
      initTensors: Boolean,
      symbols: Seq[Variable],
      outputs_names: Seq[String]
  ): String = {
    initTensors match {
      case true => {
        val c1 = init_code(codeLang)
        val dim_names: Seq[String] = all_dimensions.values
          .flatMap(_.collect { case Variable(name) =>
            name
          })
          .toSeq
        val argv_names =
          if (symbols.nonEmpty) symbols.map(_.name)
          else
            (dim_names ++ unboundVariables(rules).toSeq.diff(
              dim_names
            )).distinct
        val only_lhs_heads =
          rules.map(_.head).filter(_.kind == Tensor).distinctBy(_.name)
        val all_vars = allVariables(rules).toSeq
        val c2 = read_argv(codeLang, argv_names)
        val decimal_pattern = """-?\d+(\.\d+)?""".r
        val c3 = all_tensors
          .map(_.deinversifiedHead())
          .distinctBy(_.name)
          .filter(_.kind == Tensor)
          .filterNot(only_lhs_heads.contains)
          .filterNot(t => symbols.contains(t.name.deinversifiedName.toVar))
          .filterNot(t => decimal_pattern.matches(t.name))
          .map(t =>
            alloc_and_gen_random_number(
              codeLang,
              t,
              all_dimensions.getOrElse(t, Seq[Dim]()),
              uniqueSets.getOrElse(t, emptyRule()).body
            )
          )
          .mkString("\n")
        val c4 = outputs_names.isEmpty match {
          case true =>
            only_lhs_heads
              .map(t =>
                alloc_and_gen_zero(
                  codeLang,
                  t,
                  all_dimensions.getOrElse(t, Seq[Dim]())
                )
              )
              .mkString("\n")
          case false =>
            only_lhs_heads
              .filter(e => outputs_names.contains(e.name))
              .map(t =>
                alloc_and_gen_zero(
                  codeLang,
                  t,
                  all_dimensions.getOrElse(t, Seq[Dim]())
                )
              )
              .mkString("\n")
        }
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

extern "C"
"""
        val only_lhs_heads_not_in_output = outputs_names.isEmpty match {
          case true => Seq()
          case false =>
            rules
              .map(_.head)
              .filter(_.kind == Tensor)
              .distinctBy(_.name)
              .filterNot(e => outputs_names.contains(e.name))
        }
        val decimal_pattern = """-?\d+(\.\d+)?""".r
        val tensor_to_str = all_tensors
          .distinctBy(_.name)
          .filterNot(only_lhs_heads_not_in_output.contains)
          .filterNot(t => symbols.contains(t.name.deinversifiedName.toVar))
          .filterNot(t => decimal_pattern.matches(t.name.deinversifiedName))
          .map(t =>
            "double " + (if (t.vars.isEmpty) "&"
                         else
                           "*" * t.vars.length) + " " + t.name.deinversifiedName
          )
          .distinct
          .mkString(", ")
        val symbols_to_str = symbols.map(v => "int " + v.name).mkString(", ")
        val c2 =
          if (symbols_to_str.length() > 0)
            s"void fn($tensor_to_str, $symbols_to_str) {\n"
          else s"void fn($tensor_to_str) {\n"
        c1 + c2
      }
    }

  }

  def generateEnd(
      codeLang: String,
      rules: Seq[Rule],
      all_tensors: Seq[Access],
      all_dimensions: Map[Access, Seq[Dim]],
      initTensors: Boolean,
      outputs_names: Seq[String]
  ): String = {
    initTensors match {
      case true => {
        val only_lhs_heads_not_in_output = outputs_names.isEmpty match {
          case true => Seq()
          case false =>
            rules
              .map(_.head)
              .filter(_.kind == Tensor)
              .distinctBy(_.name)
              .filterNot(e => outputs_names.contains(e.name))
        }
        val c1 = outputs_names.isEmpty match {
          case true =>
            all_tensors
              .map(_.deinversifiedHead())
              .distinctBy(_.name)
              .map(t => printerr(codeLang, t))
              .mkString("\n")
          case false =>
            all_tensors
              .filter(e => outputs_names.contains(e.name))
              .map(t => printerr(codeLang, t.deinversifiedHead()))
              .mkString("\n")
        }
        val c2 = all_tensors
          .distinctBy(_.name)
          .filterNot(only_lhs_heads_not_in_output.contains)
          .map(_.deinversifiedHead())
          .distinctBy(_.name)
          .filter(all_dimensions.contains)
          .map(t => free(codeLang, t.name, all_dimensions(t)))
          .mkString("\n")
        val c3 = return_code(codeLang)
        c1 + "\n" + c2 + "\n" + c3
      }
      case false => "\n}"
    }
  }
}
