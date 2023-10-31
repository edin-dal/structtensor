package uk.ac.ed.dal
package structtensor
package parser

import compiler._
import apps._

object Bodygen {
  import Shared._
  import STURHelper.emptyRule
  def apply(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], uniqueSets: Map[Exp, Rule], sturOpt: Boolean): (String, String) = {
    (generateInit(codeLang, rules, all_tensors, all_dimensions, uniqueSets, sturOpt), generateEnd(codeLang, rules, all_tensors, all_dimensions, sturOpt))
  }

  def generateInit(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], uniqueSets: Map[Exp, Rule], sturOpt: Boolean): String = {
    val c1 = init_code(codeLang)
    val argv_names = unboundVariables(rules).toSeq
    val all_vars = allVariables(rules).toSeq
    println("rules: " + rules)
    println("all_vars: " + all_vars)
    println("argv_names: " + argv_names)
    val c2 = read_argv(codeLang, argv_names)
    val c3 = all_tensors.map(t => alloc_and_gen_random_number(codeLang, t, all_dimensions(t), uniqueSets.getOrElse(t, emptyRule()).body)).mkString("\n")
    val c4 = if (!sturOpt) init_timer(codeLang) else ""
    return c1 + "\n" + c2 + "\n" + c3 + "\n" + c4    
  }

  def generateEnd(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], sturOpt: Boolean): String = {
    val c1 = if(sturOpt) "" else end_timer(codeLang)
    val c2 = if(sturOpt) "" else rules.map(r => printerr(codeLang, r.head)).mkString("\n")
    val c3 = all_tensors.map(t => free(codeLang, t.name, all_dimensions(t))).mkString("\n")
    val c4 = return_code(codeLang)
    return c1 + "\n" + c2 + "\n" + c3 + "\n" + c4
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
    rules.foldLeft(Set.empty[String])((acc, r) => {
      acc ++ r.head.vars.map(_.name).toSet ++ r.body.prods.foldLeft(Set.empty[String])((acc2, p) => acc2 ++ p.exps.foldLeft(Set.empty[String])((acc3, e) => e match {
        case Access(_, vars, _) => acc3 ++ vars.map(_.name).toSet
        case Comparison(_, index, variable) => acc3 ++ allVariables(index) ++ Set(variable.name)
      }))
    })
  }

  def boundVariables(rules: Seq[Rule]): Set[String] = {
    rules.foldLeft(Set.empty[String])((acc, r) => {
      acc ++ r.head.vars.map(_.name).toSet ++ r.body.prods.foldLeft(Set.empty[String])((acc2, p) => acc2 ++ p.exps.foldLeft(Set.empty[String])((acc3, e) => e match {
        case Access(_, vars, _) => acc3 ++ vars.map(_.name).toSet
        case _ => acc3
      }))
    })
  }
}