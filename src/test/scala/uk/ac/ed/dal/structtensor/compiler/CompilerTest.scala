package uk.ac.ed.dal
package structtensor
package compiler

import utils._
import Utils._
import Optimizer._

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

class CompilerTest
    extends AnyFlatSpec
    with Matchers
    with ParallelTestExecution {

  "Compiler" should "get all the variables in an expression" in {}

  it should "get all the variables in an index" in {}

  it should "check whether the pairwise intersection of a sequnece of sequences is empty" in {}

  it should "group expressions with the same name" in {}

  it should "whether a rule is a shift rule" in {}

  it should "normalize a rule that only has one product" in {}

  it should "normalize sum of accesses sequence" in {}

  it should "normalize a rule" in {}

  it should "infer the structure for shift" in {}

  it should "infer the structure for project" in {}

  it should "be able to generate a vectorize comparison multiplication" in {}

  it should "infer the structure for binary multiplication" in {}

  it should "infer the structure for self outer product" in {}

  it should "detect whether to SoPs are equal" in {}

  it should "detect whether two SoPs are disjoint" in {}

  it should "infer the structure for binary addition" in {}

  it should "infer the structure of tensor's head for a normalized rule given a context" in {}

  it should "compile a a computation, given all inputs and symbols" in {}
}
