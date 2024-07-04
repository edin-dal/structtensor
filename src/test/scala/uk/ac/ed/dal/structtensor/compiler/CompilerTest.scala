package uk.ac.ed.dal
package structtensor
package compiler

import utils._
import Utils._
import Optimizer._

import scala.util.matching.Regex

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution
import uk.ac.ed.dal.structtensor.compiler.Compiler.shift

class CompilerTest
    extends AnyFlatSpec
    with Matchers
    with ParallelTestExecution {

  "Compiler" should "get all the variables in an access" in {
    val access = Access("a", Seq(Variable("i"), Variable("j")), Tensor)
    val vars = Compiler.getAllVariables(access)
    vars should contain theSameElementsAs Seq(Variable("i"), Variable("j"))
  }

  it should "get all the variables in a comparison" in {
    val comp = Comparison("<", Variable("i"), Variable("j"))
    val vars = Compiler.getAllVariables(comp)
    vars should contain theSameElementsAs Seq(Variable("i"), Variable("j"))
  }

  it should "get all the variables in an arithmetic" in {
    val arithmetic = Arithmetic("+", Variable("i"), Variable("j"))
    val vars = Compiler.getAllVariables(arithmetic)
    vars should contain theSameElementsAs Seq(Variable("i"), Variable("j"))
  }

  it should "check whether the pairwise intersection of a sequnece of sequences is empty" in {
    val seq =
      Seq(Seq(Variable("i"), Variable("j")), Seq(Variable("k"), Variable("l")))
    val res = Compiler.isPairwiseIntersectEmpty(seq)
    res shouldBe true
  }

  it should "group accesses with the same name" in {
    val exprs = Seq(
      Access("a", Seq(Variable("i"), Variable("j")), Tensor),
      Access("a", Seq(Variable("k"), Variable("l")), Tensor),
      Access("b", Seq(Variable("m"), Variable("n")), Tensor),
      Access("b", Seq(Variable("o"), Variable("p")), Tensor),
      Access("a", Seq(Variable("q"), Variable("r")), Tensor)
    )
    val res = Compiler.groupBySameName(exprs.head, exprs.tail)
    res should contain theSameElementsAs Seq(
      Access("a", Seq(Variable("i"), Variable("j")), Tensor),
      Access("a", Seq(Variable("k"), Variable("l")), Tensor),
      Access("a", Seq(Variable("q"), Variable("r")), Tensor)
    )
  }

  it should "whether a rule is a shift rule" in {
    val rule = Rule(
      Access("a", Seq(Variable("p"), Variable("q")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("b", Seq(Variable("i"), Variable("j")), Tensor),
              Comparison(
                "=",
                Arithmetic("-", Variable("p"), ConstantInt(5)),
                Variable("i")
              ),
              Comparison(
                "=",
                Arithmetic("-", Variable("q"), Variable("N")),
                Variable("j")
              )
            )
          )
        )
      )
    )
    val res = Compiler.isShift(rule.head, rule.body.prods.head.exps)
    res shouldBe true
  }

  it should "normalize a rule that only has one product" in {
    val rule = Rule(
      Access("a", Seq(Variable("p"), Variable("q")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("b", Seq(Variable("i"), Variable("j")), Tensor),
              Comparison(
                "=",
                Arithmetic("-", Variable("p"), ConstantInt(5)),
                Variable("i")
              ),
              Comparison(
                "=",
                Arithmetic("-", Variable("q"), Variable("N")),
                Variable("j")
              ),
              Access("c", Seq(Variable("p"), Variable("q")), Tensor)
            )
          )
        )
      )
    )
    val res = Compiler.normalizeSingleProdRule(rule)
    val pattern = """shiftHead\d+""".r
    val test_value = res match {
      case Seq(
            Rule(
              Access(sh_head1, Seq(Variable("p"), Variable("q")), Tensor),
              SoP(
                Seq(
                  Prod(
                    Seq(
                      Access("b", Seq(Variable("i"), Variable("j")), Tensor),
                      Comparison(
                        "=",
                        Arithmetic("-", Variable("p"), ConstantInt(5)),
                        Variable("i")
                      ),
                      Comparison(
                        "=",
                        Arithmetic("-", Variable("q"), Variable("N")),
                        Variable("j")
                      )
                    )
                  )
                )
              )
            ),
            Rule(
              Access("a", Seq(Variable("p"), Variable("q")), Tensor),
              SoP(
                Seq(
                  Prod(
                    Seq(
                      Access(
                        sh_head2,
                        Seq(Variable("p"), Variable("q")),
                        Tensor
                      ),
                      Access("c", Seq(Variable("p"), Variable("q")), Tensor)
                    )
                  )
                )
              )
            )
          )
          if (pattern matches sh_head1) && (pattern matches sh_head2) && sh_head1 == sh_head2 =>
        true
      case _ => false
    }
    test_value shouldEqual true
  }

  it should "normalize sum of accesses sequence" in {
    val head = Access("t", Seq(Variable("i"), Variable("j")), Tensor)
    val accesses = Seq(
      Access("a", Seq(Variable("i"), Variable("j")), Tensor),
      Access("b", Seq(Variable("i"), Variable("j")), Tensor),
      Access("c", Seq(Variable("i"), Variable("j")), Tensor)
    )
    val res = Compiler.normalizeSumOfAccessSeq(head, accesses)
    val pattern = """sumHead\d+""".r
    val test_value = res match {
      case Seq(
            Rule(
              Access(sumHead1, Seq(Variable("i"), Variable("j")), Tensor),
              SoP(
                Seq(
                  Prod(
                    Seq(Access(a, Seq(Variable("i"), Variable("j")), Tensor))
                  ),
                  Prod(
                    Seq(Access(b, Seq(Variable("i"), Variable("j")), Tensor))
                  )
                )
              )
            ),
            Rule(
              Access(sumHead2, Seq(Variable("i"), Variable("j")), Tensor),
              SoP(
                Seq(
                  Prod(
                    Seq(
                      Access(
                        sumHead11,
                        Seq(Variable("i"), Variable("j")),
                        Tensor
                      )
                    )
                  ),
                  Prod(
                    Seq(Access(c, Seq(Variable("i"), Variable("j")), Tensor))
                  )
                )
              )
            ),
            Rule(
              Access(t, Seq(Variable("i"), Variable("j")), Tensor),
              SoP(
                Seq(
                  Prod(
                    Seq(
                      Access(
                        sumHead21,
                        Seq(Variable("i"), Variable("j")),
                        Tensor
                      )
                    )
                  )
                )
              )
            )
          )
          if (pattern matches sumHead1) && (pattern matches sumHead2) && sumHead1 == sumHead11 && sumHead2 == sumHead21 =>
        true
      case _ => false
    }
    test_value shouldEqual true
  }

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
