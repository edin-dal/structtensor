package uk.ac.ed.dal
package structtensor
package compiler

import utils._
import Utils._

import scala.util.matching.Regex

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution
import scala.collection.immutable.Map.Map3

class OptimizerTest
    extends AnyFlatSpec
    with Matchers
    with ParallelTestExecution {

  "Optimizer" should "find an access in a map only by name" in {
    val map = Map(
      Access("A", Seq(Variable("i")), UniqueSet) -> SoP(Seq())
    )
    val access = Access("A", Seq(Variable("j")), Tensor)
    Optimizer.containsByName(map, access) shouldBe true
  }

  it should "get non dimension variables of a rule correctly" in {
    val rule = Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Access("C", Seq(Variable("j"), Variable("l")), Tensor),
              Comparison("<=", ConstantInt(0), Variable("p")),
              Comparison("<", Variable("p"), Variable("l"))
            )
          )
        )
      )
    )
    Optimizer.getNonDimensionVariables(rule) shouldBe Seq(
      Variable("i"),
      Variable("j"),
      Variable("l")
    )
  }

  it should "get non dimension variables of a SoP correctly" in {
    val sop = SoP(
      Seq(
        Prod(
          Seq(
            Access("B", Seq(Variable("i"), Variable("j")), Tensor),
            Access("C", Seq(Variable("j"), Variable("l")), Tensor),
            Comparison("<=", ConstantInt(0), Variable("p")),
            Comparison("<", Variable("p"), Variable("l"))
          )
        ),
        Prod(
          Seq(
            Access("B", Seq(Variable("i"), Variable("k")), Tensor),
            Access("C", Seq(Variable("k"), Variable("l")), Tensor),
            Comparison("<=", ConstantInt(0), Variable("p")),
            Comparison("<", Variable("p"), Variable("l"))
          )
        )
      )
    )
    Optimizer.getNonDimensionVariables(sop) shouldBe Seq(
      Variable("i"),
      Variable("j"),
      Variable("l"),
      Variable("k")
    )
  }

  it should "get non dimension variables of a product correctly" in {
    val prod = Prod(
      Seq(
        Access("B", Seq(Variable("i"), Variable("j")), Tensor),
        Access("C", Seq(Variable("j"), Variable("l")), Tensor),
        Comparison("<=", ConstantInt(0), Variable("p")),
        Comparison("<", Variable("p"), Variable("l"))
      )
    )
    Optimizer.getNonDimensionVariables(prod) shouldBe Seq(
      Variable("i"),
      Variable("j"),
      Variable("l")
    )
  }

  it should "alpha rename the variables in a body of a rule, based on the access and given the denormalization map" in {
    val m = Map(
      Access("T", Seq(Variable("i")), Tensor) -> SoP(
        Seq(
          Prod(
            Seq(
              Access("V", Seq(Variable("i"), Variable("j")), Tensor)
            )
          )
        )
      )
    )

    val access = Access("T", Seq(Variable("i")), Tensor)

    val actual = Optimizer.getByNameAndAlphaRename(m, access)

    val pattern = """i\d+""".r
    val test_value = actual match {
      case None => false
      case Some(value) =>
        value match {
          case SoP(
                Seq(
                  Prod(
                    Seq(
                      Access("V", Seq(Variable("i"), Variable(i)), Tensor)
                    )
                  )
                )
              ) if pattern matches i =>
            true
          case _ => false
        }
    }

    test_value shouldBe true
  }

  it should "denormalize a single SoP based on the denormalization map" in {
    // Example based on, only for it's CC:
    // symbols: N
    // T(i) := V(i, j)
    // A(i) := T(i) * T(i)
    // A:D(i) := (0 <= i < N)
    // T:D(i) := (0 <= i < N)
    // V:D(i, j) := (0 <= i < N) *(0 <= j < N)

    val body = SoP(
      Seq(
        Prod(
          Seq(
            Access("T_C", Seq(Variable("i")), CompressedTensor),
            Access("T_C", Seq(Variable("i")), CompressedTensor)
          )
        ),
        Prod(
          Seq(
            Access("T_C", Seq(Variable("i")), CompressedTensor),
            Access("T_RM", Seq(Variable("i"), Variable("ip")), RedundancyMap),
            Access("T", Seq(Variable("ip")), Tensor)
          )
        ),
        Prod(
          Seq(
            Access("T_RM", Seq(Variable("i"), Variable("ip")), RedundancyMap),
            Access("T_C", Seq(Variable("i")), CompressedTensor),
            Access("T", Seq(Variable("ip")), Tensor)
          )
        )
      )
    )
    val denormMap = Map(
      Access("T_US", Seq(Variable("i")), UniqueSet) -> SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("i")),
              Comparison(">", Variable("N"), Variable("i"))
            )
          )
        )
      ),
      Access("T_RM", Seq(Variable("i"), Variable("ip")), RedundancyMap) -> SoP(
        Seq()
      ),
      Access("T_C", Seq(Variable("i")), CompressedTensor) -> SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("i")),
              Comparison(">", Variable("N"), Variable("i")),
              Comparison("<=", ConstantInt(0), Variable("j")),
              Comparison(">", Variable("N"), Variable("j")),
              Access("V", Seq(Variable("i"), Variable("j")), Tensor)
            )
          )
        )
      ),
      Access("T", Seq(Variable("i")), Tensor) -> SoP(
        Seq(Prod(Seq(Access("T", Seq(Variable("i")), Tensor))))
      )
    )

    val actual = Optimizer.denormalizeSingle(body, denormMap, UniqueSet)
    val pattern = """i\d+""".r
    val test_value = actual match {
      case SoP(
            Seq(
              Prod(
                Seq(
                  Comparison("<=", ConstantInt(0), Variable("i")),
                  Comparison(">", Variable("N"), Variable("i")),
                  Comparison("<=", ConstantInt(0), Variable(i1)),
                  Comparison(">", Variable("N"), Variable(i11)),
                  Access("V", Seq(Variable("i"), Variable(i12)), Tensor),
                  Comparison("<=", ConstantInt(0), Variable("i")),
                  Comparison(">", Variable("N"), Variable("i")),
                  Comparison("<=", ConstantInt(0), Variable(i2)),
                  Comparison(">", Variable("N"), Variable(i21)),
                  Access("V", Seq(Variable("i"), Variable(i22)), Tensor)
                )
              )
            )
          )
          if (pattern matches i1) && i1 == i11 && i1 == i12 && (pattern matches i2) && i2 == i21 && i2 == i22 =>
        true
      case _ => false
    }

    test_value shouldBe true
  }

  it should "denormalize all rules given a head and context" in {
    // This example is based on SpMV_D
    val head = Access("A", Seq(Variable("i")), Tensor)
    val context = Seq(
      (
        Rule(
          Access("B_US", Seq(Variable("i"), Variable("j")), UniqueSet),
          SoP(
            Seq(
              Prod(
                Seq(
                  Comparison("<=", ConstantInt(0), Variable("i")),
                  Comparison(">", Variable("M"), Variable("i")),
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j")),
                  Comparison("=", Variable("i"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access(
            "B_RM",
            Seq(Variable("i"), Variable("j"), Variable("ip"), Variable("jp")),
            RedundancyMap
          ),
          SoP(Seq())
        ),
        Rule(
          Access("B_C", Seq(Variable("i"), Variable("j")), CompressedTensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("B", Seq(Variable("i"), Variable("j")), Tensor),
                  Comparison("<=", ConstantInt(0), Variable("i")),
                  Comparison(">", Variable("M"), Variable("i")),
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j")),
                  Comparison("=", Variable("i"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access("B", Seq(Variable("i"), Variable("j")), Tensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("B", Seq(Variable("i"), Variable("j")), Tensor)
                )
              )
            )
          )
        )
      ),
      (
        Rule(
          Access("C_US", Seq(Variable("j")), UniqueSet),
          SoP(
            Seq(
              Prod(
                Seq(
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access("C_RM", Seq(Variable("j"), Variable("jp")), RedundancyMap),
          SoP(Seq())
        ),
        Rule(
          Access("C_C", Seq(Variable("j")), CompressedTensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("C", Seq(Variable("j")), Tensor),
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access("C", Seq(Variable("j")), Tensor),
          SoP(Seq(Prod(Seq(Access("C", Seq(Variable("j")), Tensor)))))
        )
      ),
      (
        Rule(
          Access("B_US", Seq(Variable("i"), Variable("j")), UniqueSet),
          SoP(
            Seq(
              Prod(
                Seq(
                  Comparison("<=", ConstantInt(0), Variable("i")),
                  Comparison(">", Variable("M"), Variable("i")),
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j")),
                  Comparison("=", Variable("i"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access(
            "B_RM",
            Seq(Variable("i"), Variable("j"), Variable("ip"), Variable("jp")),
            RedundancyMap
          ),
          SoP(Seq())
        ),
        Rule(
          Access("B_C", Seq(Variable("i"), Variable("j")), CompressedTensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("B", Seq(Variable("i"), Variable("j")), Tensor),
                  Comparison("<=", ConstantInt(0), Variable("i")),
                  Comparison(">", Variable("M"), Variable("i")),
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j")),
                  Comparison("=", Variable("i"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access("B", Seq(Variable("i"), Variable("j")), Tensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("B", Seq(Variable("i"), Variable("j")), Tensor)
                )
              )
            )
          )
        )
      ),
      (
        Rule(
          Access("C_US", Seq(Variable("j")), UniqueSet),
          SoP(
            Seq(
              Prod(
                Seq(
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access("C_RM", Seq(Variable("j"), Variable("jp")), RedundancyMap),
          SoP(Seq())
        ),
        Rule(
          Access("C_C", Seq(Variable("j")), CompressedTensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("C", Seq(Variable("j")), Tensor),
                  Comparison("<=", ConstantInt(0), Variable("j")),
                  Comparison(">", Variable("N"), Variable("j"))
                )
              )
            )
          )
        ),
        Rule(
          Access("C", Seq(Variable("j")), Tensor),
          SoP(Seq(Prod(Seq(Access("C", Seq(Variable("j")), Tensor)))))
        )
      ),
      (
        Rule(
          Access("prodHead3_US", Seq(Variable("i"), Variable("j")), UniqueSet),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("B_US", Seq(Variable("i"), Variable("j")), UniqueSet),
                  Access("C_US", Seq(Variable("j")), UniqueSet)
                )
              ),
              Prod(
                Seq(
                  Access("B_US", Seq(Variable("i"), Variable("j")), UniqueSet),
                  Access(
                    "C_RM",
                    Seq(Variable("j"), Variable("jp")),
                    RedundancyMap
                  )
                )
              ),
              Prod(
                Seq(
                  Access(
                    "B_RM",
                    Seq(
                      Variable("i"),
                      Variable("j"),
                      Variable("ip"),
                      Variable("jp")
                    ),
                    RedundancyMap
                  ),
                  Access("C_US", Seq(Variable("j")), UniqueSet)
                )
              )
            )
          )
        ),
        Rule(
          Access(
            "prodHead3_RM",
            Seq(Variable("i"), Variable("j"), Variable("ip"), Variable("jp")),
            RedundancyMap
          ),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access(
                    "B_RM",
                    Seq(
                      Variable("i"),
                      Variable("j"),
                      Variable("ip"),
                      Variable("jp")
                    ),
                    RedundancyMap
                  ),
                  Access(
                    "C_RM",
                    Seq(Variable("j"), Variable("jp")),
                    RedundancyMap
                  )
                )
              )
            )
          )
        ),
        Rule(
          Access(
            "prodHead3_C",
            Seq(Variable("i"), Variable("j")),
            CompressedTensor
          ),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access(
                    "B_C",
                    Seq(Variable("i"), Variable("j")),
                    CompressedTensor
                  ),
                  Access("C_C", Seq(Variable("j")), CompressedTensor)
                )
              ),
              Prod(
                Seq(
                  Access(
                    "B_C",
                    Seq(Variable("i"), Variable("j")),
                    CompressedTensor
                  ),
                  Access(
                    "C_RM",
                    Seq(Variable("j"), Variable("jp")),
                    RedundancyMap
                  ),
                  Access("C", Seq(Variable("jp")), Tensor)
                )
              ),
              Prod(
                Seq(
                  Access(
                    "B_RM",
                    Seq(
                      Variable("i"),
                      Variable("j"),
                      Variable("ip"),
                      Variable("jp")
                    ),
                    RedundancyMap
                  ),
                  Access("C_C", Seq(Variable("j")), CompressedTensor),
                  Access("B", Seq(Variable("ip"), Variable("jp")), Tensor)
                )
              )
            )
          )
        ),
        Rule(
          Access("prodHead3", Seq(Variable("i"), Variable("j")), Tensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("B", Seq(Variable("i"), Variable("j")), Tensor),
                  Access("C", Seq(Variable("j")), Tensor)
                )
              )
            )
          )
        )
      ),
      (
        Rule(
          Access("A_US", Seq(Variable("i")), UniqueSet),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access(
                    "prodHead3_US",
                    Seq(Variable("i"), Variable("j")),
                    UniqueSet
                  )
                )
              ),
              Prod(
                Seq(
                  Access(
                    "prodHead3_RM",
                    Seq(
                      Variable("i"),
                      Variable("j"),
                      Variable("ip"),
                      Variable("jp")
                    ),
                    RedundancyMap
                  )
                )
              )
            )
          )
        ),
        Rule(
          Access("A_RM", Seq(Variable("i"), Variable("ip")), RedundancyMap),
          SoP(Seq())
        ),
        Rule(
          Access("A_C", Seq(Variable("i")), CompressedTensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access(
                    "prodHead3_C",
                    Seq(Variable("i"), Variable("j")),
                    CompressedTensor
                  )
                )
              ),
              Prod(
                Seq(
                  Access(
                    "prodHead3_RM",
                    Seq(
                      Variable("i"),
                      Variable("j"),
                      Variable("ip"),
                      Variable("jp")
                    ),
                    RedundancyMap
                  ),
                  Access(
                    "prodHead3",
                    Seq(Variable("ip"), Variable("jp")),
                    Tensor
                  )
                )
              )
            )
          )
        ),
        Rule(
          Access("A", Seq(Variable("i")), Tensor),
          SoP(
            Seq(
              Prod(
                Seq(
                  Access("prodHead3", Seq(Variable("i"), Variable("j")), Tensor)
                )
              )
            )
          )
        )
      )
    )

    val expectedUS = Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("i")),
              Comparison(">", Variable("M"), Variable("i")),
              Comparison("<=", ConstantInt(0), Variable("j")),
              Comparison(">", Variable("N"), Variable("j")),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("<=", ConstantInt(0), Variable("j")),
              Comparison(">", Variable("N"), Variable("j"))
            )
          )
        )
      )
    )

    val expectedRM = Rule(
      Access("A", Seq(Variable("i"), Variable("ip")), Tensor),
      SoP(Seq())
    )

    val expectedCC = Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("i")),
              Comparison(">", Variable("M"), Variable("i")),
              Comparison("<=", ConstantInt(0), Variable("j")),
              Comparison(">", Variable("N"), Variable("j")),
              Comparison("=", Variable("i"), Variable("j")),
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Comparison("<=", ConstantInt(0), Variable("j")),
              Comparison(">", Variable("N"), Variable("j")),
              Access("C", Seq(Variable("j")), Tensor)
            )
          )
        )
      )
    )

    val expectedTC = Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Access("C", Seq(Variable("j")), Tensor)
            )
          )
        )
      )
    )

    val (denormUS, denormRM, denormCC, denormTC) =
      Optimizer.denormalize(head, context)
    denormUS shouldBe expectedUS
    denormRM shouldBe expectedRM
    denormCC shouldBe expectedCC
    denormTC shouldBe expectedTC
  }

  it should "detect equivalent comparisons 1" in {
    val c1 = Comparison("<", Variable("i"), Variable("j"))
    val c2 = Comparison("<", Variable("i"), Variable("j"))

    Optimizer.isComparisonEquivalent(c1, c2) shouldBe true
  }

  it should "detect equivalent comparisons 2" in {
    val c1 = Comparison("<", Variable("i"), Variable("j"))
    val c2 = Comparison(">", Variable("j"), Variable("i"))

    Optimizer.isComparisonEquivalent(c1, c2) shouldBe true
  }

  it should "detect equivalent comparisons 3" in {
    val c1 = Comparison(">", Variable("j"), Variable("i"))
    val c2 = Comparison("<", Variable("i"), Variable("j"))

    Optimizer.isComparisonEquivalent(c1, c2) shouldBe true
  }

  it should "detect equivalent comparisons 4" in {
    val c1 = Comparison("<=", Variable("i"), Variable("j"))
    val c2 = Comparison(">=", Variable("j"), Variable("i"))

    Optimizer.isComparisonEquivalent(c1, c2) shouldBe true
  }

  it should "detect equivalent comparisons 5" in {
    val c1 = Comparison(">=", Variable("j"), Variable("i"))
    val c2 = Comparison("<=", Variable("i"), Variable("j"))

    Optimizer.isComparisonEquivalent(c1, c2) shouldBe true
  }

  it should "detect equivalent comparisons 6" in {
    val c1 = Comparison("=", Variable("i"), Variable("j"))
    val c2 = Comparison("=", Variable("j"), Variable("i"))

    Optimizer.isComparisonEquivalent(c1, c2) shouldBe true
  }

  it should "remove equivalent comparisons in a single product using single product set idempotence" in {
    // Keeps the last one only
    val prod = Prod(
      Seq(
        Comparison(">", Variable("j"), Variable("i")),
        Comparison("<", Variable("i"), Variable("j")),
        Comparison("<", Variable("i"), Variable("j"))
      )
    )
    Optimizer.singleProdIdempotence(prod) shouldBe Prod(
      Seq(
        Comparison("<", Variable("i"), Variable("j"))
      )
    )
  }

  it should "not remove equal tensors in a single product using single product set idempotence" in {
    // Keeps the last one only
    val prod = Prod(
      Seq(
        Access("T", Seq(Variable("i")), Tensor),
        Access("T", Seq(Variable("i")), Tensor),
        Access("T", Seq(Variable("i")), Tensor)
      )
    )
    Optimizer.singleProdIdempotence(prod) shouldBe Prod(
      Seq(
        Access("T", Seq(Variable("i")), Tensor),
        Access("T", Seq(Variable("i")), Tensor),
        Access("T", Seq(Variable("i")), Tensor)
      )
    )
  }

  it should "perform set idempotence optimization on a single product" in {
    val prod = Prod(
      Seq(
        Comparison(">", Variable("j"), Variable("i")),
        Comparison("<", Variable("i"), Variable("j")),
        Comparison("<", Variable("i"), Variable("j")),
        Access("A", Seq(Variable("i")), Tensor)
      )
    )
    Optimizer.singleProdIdempotence(prod) shouldBe Prod(
      Seq(
        Comparison("<", Variable("i"), Variable("j")),
        Access("A", Seq(Variable("i")), Tensor)
      )
    )
  }

  it should "perform set idempotence optimization only on products in a rule" in {
    val rule = Rule(
      Access("B", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison(">", Variable("j"), Variable("i")),
              Comparison("<", Variable("i"), Variable("j")),
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          ),
          Prod(
            Seq(
              Comparison(">", Variable("j"), Variable("i")),
              Comparison("<", Variable("i"), Variable("j")),
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          )
        )
      )
    )
    Optimizer.setIdempotentIntersectionOpt(rule) shouldBe Rule(
      Access("B", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          ),
          Prod(
            Seq(
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          )
        )
      )
    )
  }

  it should "perform set idempotence optimization for intersection when there is both boolean and real domains" in {
    val rule = Rule(
      Access("B", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison(">", Variable("j"), Variable("i")),
              Comparison("<", Variable("i"), Variable("j")),
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          ),
          Prod(
            Seq(
              Comparison(">", Variable("j"), Variable("i")),
              Comparison("<", Variable("i"), Variable("j")),
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          )
        )
      )
    )
    Optimizer.setIdempotentOpt(rule) shouldBe Rule(
      Access("B", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          ),
          Prod(
            Seq(
              Comparison("<", Variable("i"), Variable("j")),
              Access("A", Seq(Variable("i")), Tensor)
            )
          )
        )
      )
    )
  }

  it should "perform set idempotence for both intersection and union optimization when there is only boolean domain" in {
    val rule = Rule(
      Access("B", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison(">", Variable("j"), Variable("i")),
              Comparison("<", Variable("i"), Variable("j")),
              Comparison("<", Variable("i"), Variable("j"))
            )
          ),
          Prod(
            Seq(
              Comparison(">", Variable("j"), Variable("i")),
              Comparison("<", Variable("i"), Variable("j")),
              Comparison("<", Variable("i"), Variable("j"))
            )
          )
        )
      )
    )
    Optimizer.setIdempotentOpt(rule) shouldBe Rule(
      Access("B", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<", Variable("i"), Variable("j"))
            )
          )
        )
      )
    )
  }

  it should "detect whether a binray product with constant bound is empty 1" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      "<",
      "=",
      12.5,
      12
    ) shouldBe true
  }

  it should "detect whether a binray product with constant bound is empty 2" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      "<",
      ">=",
      12.5,
      12
    ) shouldBe true
  }

  it should "detect whether a binray product with constant bound is empty 3" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      "<=",
      "=",
      12.5,
      12
    ) shouldBe true
  }

  it should "detect whether a binray product with constant bound is empty 4" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      "<=",
      "=",
      12.5,
      12.5
    ) shouldBe false
  }

  it should "detect whether a binray product with constant bound is empty 5" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      ">=",
      "<",
      12,
      12.5
    ) shouldBe true
  }

  it should "detect whether a binray product with constant bound is empty 6" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      ">=",
      "<=",
      12,
      12.5
    ) shouldBe true
  }

  it should "detect whether a binray product with constant bound is empty 7" in {
    Optimizer.isBinaryProductWithConstantBoundsEmpty(
      "=",
      "=",
      12.5,
      12
    ) shouldBe true
  }

  it should "detect whether a binray product is empty 1" in {
    Optimizer.isBinaryProductEmpty(
      Comparison("<", Variable("i"), Variable("j")),
      Comparison(">", Variable("i"), Variable("j"))
    ) shouldBe true
  }

  it should "detect whether a binray product is empty 2" in {
    Optimizer.isBinaryProductEmpty(
      Comparison("<", Variable("i"), Variable("j")),
      Comparison(">=", Variable("i"), Variable("j"))
    ) shouldBe true
  }

  it should "detect whether a binray product is empty 3" in {
    Optimizer.isBinaryProductEmpty(
      Comparison(
        "<",
        Arithmetic("+", Variable("x"), Variable("y")),
        Variable("j")
      ),
      Comparison(
        ">",
        Arithmetic("+", Variable("x"), Variable("y")),
        Variable("j")
      )
    ) shouldBe true
  }

  it should "detect whether a binray product is empty 4" in {
    Optimizer.isBinaryProductEmpty(
      Comparison("<", Variable("i"), Variable("j")),
      Comparison("<", Variable("j"), Variable("i"))
    ) shouldBe true
  }

  it should "detect whether a product is empty" in {
    Optimizer.isProductEmpty(
      Prod(
        Seq(
          Comparison("<", Variable("i"), Variable("j")),
          Comparison(">", Variable("i"), Variable("j"))
        )
      )
    ) shouldBe true
  }

  it should "detect whether an expression is empty 1" in {
    Optimizer.isExpEmpty(
      Comparison("<", Variable("i"), Variable("i"))
    ) shouldBe true
  }

  it should "detect whether an expression is empty 2" in {
    Optimizer.isExpEmpty(
      Comparison("<=", Variable("i"), Variable("i"))
    ) shouldBe false
  }

  it should "detect whether an expression is empty 3" in {
    Optimizer.isExpEmpty(
      Comparison(
        "=",
        Arithmetic("+", Variable("i"), ConstantDouble(2.4)),
        Variable("i")
      )
    ) shouldBe true
  }

  it should "detect whether an expression is empty 4" in {
    Optimizer.isExpEmpty(
      Comparison(
        "=",
        Arithmetic("+", Variable("i"), ConstantDouble(0)),
        Variable("i")
      )
    ) shouldBe false
  }

  it should "detect whether an expression is empty 5" in {
    Optimizer.isExpEmpty(
      Comparison(
        "<",
        Arithmetic("+", Variable("i"), ConstantDouble(10)),
        Variable("i")
      )
    ) shouldBe true
  }

  it should "detect whether an expression is empty 6" in {
    Optimizer.isExpEmpty(
      Comparison(
        ">=",
        Arithmetic("-", Variable("i"), ConstantDouble(10)),
        Variable("i")
      )
    ) shouldBe true
  }

  it should "remove empty products from a Rule" in {
    Optimizer.removeEmptyProductsOpt(
      Rule(
        Access("A", Seq(Variable("i")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<", Variable("i"), Variable("j")),
                Comparison(">", Variable("i"), Variable("j"))
              )
            ),
            Prod(
              Seq(
                Comparison("<", Variable("i"), Variable("j")),
                Comparison("<", Variable("j"), Variable("i"))
              )
            )
          )
        )
      )
    ) shouldBe Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq()
      )
    )
  }

  it should "get equal variables in a rule" in {
    val rule = Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Access("C", Seq(Variable("j"), Variable("l")), Tensor),
              Access("D", Seq(Variable("p"), Variable("q")), Tensor),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("=", Variable("j"), Variable("l"))
            )
          ),
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Access("C", Seq(Variable("p"), Variable("l")), Tensor),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("=", Variable("p"), Variable("l"))
            )
          )
        )
      )
    )

    val actual = Optimizer.getEqualVariables(rule)

    actual.length shouldBe 2

    actual(0).length shouldBe 1
    actual(0)(0) should contain theSameElementsAs Seq(
      Variable("i"),
      Variable("j"),
      Variable("l")
    )
    actual(1).length shouldBe 2
    actual(1) should contain theSameElementsAs Seq(
      Seq(Variable("i"), Variable("j")),
      Seq(Variable("p"), Variable("l"))
    )
  }

  it should "replace equal variables in an expression 1" in {
    Optimizer.replaceEqualVariablesInExp(
      Access("A", Seq(Variable("l")), Tensor),
      Seq(
        Seq(Variable("i"), Variable("j"), Variable("l"))
      )
    ) shouldBe Seq(Access("A", Seq(Variable("i")), Tensor))
  }

  it should "replace equal variables in an expression 2" in {
    Optimizer.replaceEqualVariablesInExp(
      Comparison("<", Variable("l"), Variable("M")),
      Seq(
        Seq(Variable("i"), Variable("j"), Variable("l"))
      )
    ) shouldBe Seq(Comparison("<", Variable("i"), Variable("M")))
  }

  it should "replace equal variables in a variable" in {
    Optimizer.replaceEqualVariableInIndex(
      Variable("l"),
      Seq(
        Seq(Variable("i"), Variable("j"), Variable("l"))
      )
    ) shouldBe Variable("i")
  }

  it should "replace equal variables in an arithmetic" in {
    Optimizer.replaceEqualVariableInIndex(
      Arithmetic("+", Variable("l"), Variable("j")),
      Seq(
        Seq(Variable("i"), Variable("j"), Variable("l"))
      )
    ) shouldBe Arithmetic("+", Variable("i"), Variable("i"))
  }

  it should "replace equal variables in a rule" in {
    val rule = Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Access("C", Seq(Variable("j"), Variable("l")), Tensor),
              Access("D", Seq(Variable("p"), Variable("q")), Tensor),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("=", Variable("j"), Variable("l"))
            )
          ),
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("j")), Tensor),
              Access("C", Seq(Variable("p"), Variable("l")), Tensor),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("=", Variable("p"), Variable("l"))
            )
          )
        )
      )
    )

    val actual = Optimizer.replaceEqualVariables(rule, Seq())

    actual shouldBe Rule(
      Access("A", Seq(Variable("i")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("i")), Tensor),
              Access("C", Seq(Variable("i"), Variable("i")), Tensor),
              Access("D", Seq(Variable("p"), Variable("q")), Tensor),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("=", Variable("i"), Variable("l")),
              Comparison("=", Variable("j"), Variable("i"))
            )
          ),
          Prod(
            Seq(
              Access("B", Seq(Variable("i"), Variable("i")), Tensor),
              Access("C", Seq(Variable("p"), Variable("p")), Tensor),
              Comparison("=", Variable("i"), Variable("j")),
              Comparison("=", Variable("p"), Variable("l"))
            )
          )
        )
      )
    )
  }
}
