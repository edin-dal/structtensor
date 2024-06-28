package uk.ac.ed.dal
package structtensor
package compiler

import utils._
import Utils._

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

  it should "alpha rename the variables in a SoP based on an alpha rename map" in {
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
            Comparison(
              "<",
              Arithmetic("+", Variable("p"), Variable("i")),
              Variable("l")
            )
          )
        )
      )
    )
    val alphaRenameMap = Map(
      Variable("i") -> Variable("i2"),
      Variable("k") -> Variable("k2"),
      Variable("l") -> Variable("l2")
    )
    val expectedSop = SoP(
      Seq(
        Prod(
          Seq(
            Access("B", Seq(Variable("i2"), Variable("j")), Tensor),
            Access("C", Seq(Variable("j"), Variable("l2")), Tensor),
            Comparison("<=", ConstantInt(0), Variable("p")),
            Comparison("<", Variable("p"), Variable("l2"))
          )
        ),
        Prod(
          Seq(
            Access("B", Seq(Variable("i2"), Variable("k2")), Tensor),
            Access("C", Seq(Variable("k2"), Variable("l2")), Tensor),
            Comparison("<=", ConstantInt(0), Variable("p")),
            Comparison(
              "<",
              Arithmetic("+", Variable("p"), Variable("i2")),
              Variable("l2")
            )
          )
        )
      )
    )
    Optimizer.alphaRename(sop, alphaRenameMap) shouldBe expectedSop
  }

  it should "alpha rename an arithmetic based on the alpha rename map" in {
    val arithmetic = Arithmetic("+", Variable("i"), Variable("j"))
    val alphaRenameMap = Map(Variable("i") -> Variable("i2"))
    val expectedArithmetic = Arithmetic("+", Variable("i2"), Variable("j"))
    Optimizer.alphaRename(
      arithmetic,
      alphaRenameMap
    ) shouldBe expectedArithmetic
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

    Utils.cnt = 0
    val actual = Optimizer.getByNameAndAlphaRename(m, access)

    val expected = Some(
      SoP(
        Seq(
          Prod(
            Seq(
              Access("V", Seq(Variable("i"), Variable("i1")), Tensor)
            )
          )
        )
      )
    )

    actual shouldBe expected
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

    Utils.cnt = 0
    val actual = Optimizer.denormalizeSingle(body, denormMap)
    val expected = SoP(
      Seq(
        Prod(
          Seq(
            Comparison("<=", ConstantInt(0), Variable("i")),
            Comparison(">", Variable("N"), Variable("i")),
            Comparison("<=", ConstantInt(0), Variable("i1")),
            Comparison(">", Variable("N"), Variable("i1")),
            Access("V", Seq(Variable("i"), Variable("i1")), Tensor),
            Comparison("<=", ConstantInt(0), Variable("i")),
            Comparison(">", Variable("N"), Variable("i")),
            Comparison("<=", ConstantInt(0), Variable("i2")),
            Comparison(">", Variable("N"), Variable("i2")),
            Access("V", Seq(Variable("i"), Variable("i2")), Tensor)
          )
        )
      )
    )

    actual shouldBe expected
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
      Access("A", Seq(Variable("i")), Tensor),
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

    Utils.cnt = 0
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

  it should "remove equivalent comparisons in a single product" in {
    // Keeps the last one only
    val prod = Prod(
      Seq(
        Comparison(">", Variable("j"), Variable("i")),
        Comparison("<", Variable("i"), Variable("j")),
        Comparison("<", Variable("i"), Variable("j"))
      )
    )
    Optimizer.removeEquivalentComparisonsOpt(prod) shouldBe Prod(
      Seq(
        Comparison("<", Variable("i"), Variable("j"))
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

}
