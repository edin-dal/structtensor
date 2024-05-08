package uk.ac.ed.dal
package structtensor
package compiler

import apps.Shared

object Matrix {
  import Shared._

  def varSeq(): Seq[Variable] = Seq("i".toVar, "j".toVar)

  def zero(name: String): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBody: SoP = emptySoP()
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 

  def general(name: String, dim1: Dim, dim2: Dim): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBC1: Comparison = Comparison("<=", ConstantInt(0), varSeq()(0))
    val usBC2: Comparison = Comparison(">", dim1, varSeq()(0))
    val usBC3: Comparison = Comparison("<=", ConstantInt(0), varSeq()(1))
    val usBC4: Comparison = Comparison(">", dim2, varSeq()(1))
    val usBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4))
    val usBody: SoP = SoP(Seq(usBP1))
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 

  def singletone(name: String, dim1: Dim, dim2: Dim, n1: Index, n2: Index): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBC1: Comparison = Comparison("<=", ConstantInt(0), varSeq()(0))
    val usBC2: Comparison = Comparison(">", dim1, varSeq()(0))
    val usBC3: Comparison = Comparison("<=", ConstantInt(0), varSeq()(1))
    val usBC4: Comparison = Comparison(">", dim2, varSeq()(1))
    val usBC5: Comparison = Comparison("=", n1, varSeq()(0))
    val usBC6: Comparison = Comparison("=", n2, varSeq()(1))
    val usBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4, usBC5, usBC6))
    val usBody: SoP = SoP(Seq(usBP1))
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 

  def diagonal(name: String, dim1: Dim, dim2: Dim): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBC1: Comparison = Comparison("<=", ConstantInt(0), varSeq()(0))
    val usBC2: Comparison = Comparison(">", dim1, varSeq()(0))
    val usBC3: Comparison = Comparison("<=", ConstantInt(0), varSeq()(1))
    val usBC4: Comparison = Comparison(">", dim2, varSeq()(1))
    val usBC5: Comparison = Comparison("=", varSeq()(1), varSeq()(0))
    val usBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4, usBC5))
    val usBody: SoP = SoP(Seq(usBP1))
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 

  def row(name: String, dim1: Dim, dim2: Dim, r: Index): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBC1: Comparison = Comparison("<=", ConstantInt(0), varSeq()(0))
    val usBC2: Comparison = Comparison(">", dim1, varSeq()(0))
    val usBC3: Comparison = Comparison("<=", ConstantInt(0), varSeq()(1))
    val usBC4: Comparison = Comparison(">", dim2, varSeq()(1))
    val usBC5: Comparison = Comparison("=", r, varSeq()(0))
    val usBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4, usBC5))
    val usBody: SoP = SoP(Seq(usBP1))
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 

  def column(name: String, dim1: Dim, dim2: Dim, c: Index): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBC1: Comparison = Comparison("<=", ConstantInt(0), varSeq()(0))
    val usBC2: Comparison = Comparison(">", dim1, varSeq()(0))
    val usBC3: Comparison = Comparison("<=", ConstantInt(0), varSeq()(1))
    val usBC4: Comparison = Comparison(">", dim2, varSeq()(1))
    val usBC5: Comparison = Comparison("=", c, varSeq()(1))
    val usBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4, usBC5))
    val usBody: SoP = SoP(Seq(usBP1))
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBody: SoP = emptySoP()
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 

  def symmetric(name: String, dim: Dim): (Rule, Rule) = {
    val usHead: Access = Access(name.uniqueName, varSeq(), UniqueSet)
    val usBC1: Comparison = Comparison("<=", ConstantInt(0), varSeq()(0))
    val usBC2: Comparison = Comparison(">", dim, varSeq()(0))
    val usBC3: Comparison = Comparison("<=", ConstantInt(0), varSeq()(1))
    val usBC4: Comparison = Comparison(">", dim, varSeq()(1))
    val usBC5: Comparison = Comparison("<=", varSeq()(0), varSeq()(1))
    val usBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4, usBC5))
    val usBody: SoP = SoP(Seq(usBP1))
    val us: Rule = Rule(usHead, usBody)

    val rmHead: Access = Access(name.redundancyName, varSeq().redundancyVarsInplace, RedundancyMap)
    val rmBC5: Comparison = Comparison("<", varSeq()(1), varSeq()(0))
    val rmBP1: Prod = Prod(Seq(usBC1, usBC2, usBC3, usBC4, rmBC5))
    val rmBody: SoP = SoP(Seq(rmBP1))
    val rm: Rule = Rule(rmHead, rmBody)
    
    return (us, rm)
  } 
}