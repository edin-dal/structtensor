package uk.ac.ed.dal
package structtensor
package parser

import compiler._
import apps._

object Bodygen {
  import Shared._
  def apply(codeLang: String): (String, String) = {
    (generateInit(codeLang), generateEnd(codeLang))
  }

  def generateInit(codeLang: String): String = {
    val c1 = init_code(codeLang)
    val argv_names = unboundVariables().toSeq
    val c2 = read_argv(codeLang, argv_names)
    val c3 = alloc_and_gen_random_number(codeLang, ) // TODO: extract the information needed from the rules/unique set/dimensions
    // TODO: have versions with and without timers/cout/cerr
  }

  def generateEnd(codeLang: String): String = {
    // TODO: implement this
    // TODO: have versions with and without timers/cout/cerr
    // It is needed if we don't send the code to stur-opt
  }

  def unboundVariables(): Seq[String] = allVariables().diff(boundVariables())

  def allVariables(index: Index): Set[String] = {
    index match {
      case Variable(name) => Set(name)
      case Arithmetic(_, i1, i2) => allVariables(i1) ++ allVariables(i2)
      case _ => Set.empty[String]
    }
  }

  def allVariables(rules: Seq[Rule]): Set[String] = {
    rules.foldLeft(Set.empty[String])((acc, r) => {
      acc ++ r.head.vars ++ r.body.prods.foldLeft(Set.empty[String])((acc2, p) => acc2 ++ p.exps.foldLeft(Set.empty[String])((acc3, e) => e match {
        case Access(_, vars, _) => acc3 ++ vars.map(_.name).toSet
        case Comparison(_, index, variable) => acc3 ++ allVariables(index) :+ variable.name
      }))
    })
  }

  def boundVariables(rules: Seq[Rule]): Set[String] = {
    rules.foldLeft(Set.empty[String])((acc, r) => {
      acc ++ r.head.vars ++ r.body.prods.foldLeft(Set.empty[String])((acc2, p) => acc2 ++ p.exps.foldLeft(Set.empty[String])((acc3, e) => e match {
        case Access(_, vars, _) => acc3 ++ vars.map(_.name).toSet
        case _ => acc3
      }))
    })
  }
}