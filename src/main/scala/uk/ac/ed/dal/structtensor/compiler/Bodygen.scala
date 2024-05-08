package uk.ac.ed.dal
package structtensor
package compiler

object Bodygen {
  import Shared._
  def apply(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], uniqueSets: Map[Access, Rule], sturOpt: Boolean): (String, String) = {
    (generateInit(codeLang, rules, all_tensors, all_dimensions, uniqueSets, sturOpt), generateEnd(codeLang, rules, all_tensors, all_dimensions, sturOpt))
  }

  def generateInit(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], uniqueSets: Map[Access, Rule], sturOpt: Boolean): String = {
    val c1 = init_code(codeLang)
    val dim_names: Seq[String] = all_dimensions.values.flatMap(_.collect {
      case Variable(name) => name
    }).toSeq
    val argv_names = (dim_names ++ unboundVariables(rules).toSeq.diff(dim_names)).distinct
    // println("argv_names: ", argv_names)
    val only_lhs_heads = rules.map(_.head).distinctBy(_.name).filter(_.kind == Tensor)
    val all_vars = allVariables(rules).toSeq
    val c2 = read_argv(codeLang, argv_names)
    val c3 = all_tensors.distinctBy(_.name).filter(_.kind == Tensor).filterNot(only_lhs_heads.contains).map(t => alloc_and_gen_random_number(codeLang, t, all_dimensions(t), uniqueSets.getOrElse(t, emptyRule()).body)).mkString("\n")
    val c35 = only_lhs_heads.map(t => alloc_and_gen_zero(codeLang, t, all_dimensions(t))).mkString("\n")
    val c4 = if (sturOpt) "" else init_timer(codeLang) 
    return c1 + "\n" + c2 + "\n" + c3 + "\n" + c35 + "\n" + c4    
  }

  def generateEnd(codeLang: String, rules: Seq[Rule], all_tensors: Seq[Access], all_dimensions: Map[Access, Seq[Dim]], sturOpt: Boolean): String = {
    val c1 = if(sturOpt) "" else end_timer(codeLang)
    // val c2 = if(sturOpt) "" else rules.map(r => printerr(codeLang, r.head)).mkString("\n")
    val c2 = all_tensors.map(t => printerr(codeLang, t)).mkString("\n")
    val c3 = all_tensors.distinctBy(_.name).map(t => free(codeLang, t.name, all_dimensions(t))).mkString("\n")
    val c4 = return_code(codeLang)
    return c1 + "\n" + c2 + "\n" + c3 + "\n" + c4
  }
}