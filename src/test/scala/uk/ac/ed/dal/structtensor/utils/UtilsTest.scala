package uk.ac.ed.dal
package structtensor
package utils

import compiler._

import java.io._
import scala.util.matching.Regex

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution
import uk.ac.ed.dal.structtensor.utils.Utils.DimInfoOps
import uk.ac.ed.dal.structtensor.utils.Utils.SeqDimInfoOps

class UtilsTest extends AnyFlatSpec with Matchers with ParallelTestExecution {
  "Utils" should "write correct values to file" in {
    Utils.write2File("test.txt", "test", append = false)
    val file = new File("test.txt")
    file.exists() should be(true)
    val source = scala.io.Source.fromFile("test.txt")
    val lines =
      try source.mkString
      finally source.close()
    lines should be("test")
    file.delete()
  }

  it should "return correct variable name" in {
    val test_digit = """test\d+""".r
    test_digit matches Utils.getVar("test") should be(true)
    test_digit matches Utils.getVar("test") should be(true)
  }

  it should "return empty Prod" in {
    Utils.emptyProd() should be(Prod(Seq[Exp]()))
  }

  it should "return empty SoP" in {
    Utils.emptySoP() should be(SoP(Seq[Prod]()))
  }

  it should "return empty Access" in {
    Utils.emptyAccess() should be(Access("", Seq[Variable](), Tensor))
  }

  it should "return empty Rule" in {
    Utils.emptyRule() should be(Rule(Utils.emptyAccess(), Utils.emptySoP()))
  }

  it should "return correct Prod times Prod" in {
    Utils.prodTimesProd(
      Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))),
      Prod(Seq[Exp](Access(("y"), Seq[Variable](), Tensor)))
    ) should be(
      Prod(
        Seq[Exp](
          Access("x", Seq[Variable](), Tensor),
          Access("y", Seq[Variable](), Tensor)
        )
      )
    )
  }

  it should "return empty if prod1 or prod2 is empty" in {
    Utils.prodTimesProd(
      Prod(Seq[Exp]()),
      Prod(Seq[Exp](Access("y", Seq[Variable](), Tensor)))
    ) should be(Prod(Seq[Exp]()))
    Utils.prodTimesProd(
      Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))),
      Prod(Seq[Exp]())
    ) should be(Prod(Seq[Exp]()))
  }

  it should "return correct Prod times SoP" in {
    Utils.prodTimesSoP(
      Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))),
      SoP(Seq[Prod](Prod(Seq[Exp](Access("y", Seq[Variable](), Tensor)))))
    ) should be(
      SoP(
        Seq[Prod](
          Prod(
            Seq[Exp](
              Access("x", Seq[Variable](), Tensor),
              Access("y", Seq[Variable](), Tensor)
            )
          )
        )
      )
    )
  }

  it should "return empty if prod or sop is empty" in {
    Utils.prodTimesSoP(
      Prod(Seq[Exp]()),
      SoP(Seq[Prod](Prod(Seq[Exp](Access("y", Seq[Variable](), Tensor)))))
    ) should be(SoP(Seq[Prod]()))
    Utils.prodTimesSoP(
      Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))),
      SoP(Seq[Prod]())
    ) should be(SoP(Seq[Prod]()))
  }

  it should "return correct SoP times SoP" in {
    Utils.SoPTimesSoP(
      SoP(Seq[Prod](Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))))),
      SoP(Seq[Prod](Prod(Seq[Exp](Access("y", Seq[Variable](), Tensor)))))
    ) should be(
      SoP(
        Seq[Prod](
          Prod(
            Seq[Exp](
              Access("x", Seq[Variable](), Tensor),
              Access("y", Seq[Variable](), Tensor)
            )
          )
        )
      )
    )
  }

  it should "return empty if sop1 or sop2 is empty" in {
    Utils.SoPTimesSoP(
      SoP(Seq[Prod]()),
      SoP(Seq[Prod](Prod(Seq[Exp](Access("y", Seq[Variable](), Tensor)))))
    ) should be(SoP(Seq[Prod]()))
    Utils.SoPTimesSoP(
      SoP(Seq[Prod](Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))))),
      SoP(Seq[Prod]())
    ) should be(SoP(Seq[Prod]()))
  }

  it should "return correct multiplication of a sequence of SoPs" in {
    Utils.multSoP(
      Seq[SoP](
        SoP(Seq[Prod](Prod(Seq[Exp](Access("x", Seq[Variable](), Tensor))))),
        SoP(Seq[Prod](Prod(Seq[Exp](Access("y", Seq[Variable](), Tensor))))),
        SoP(Seq[Prod](Prod(Seq[Exp](Access("z", Seq[Variable](), Tensor)))))
      )
    ) should be(
      SoP(
        Seq[Prod](
          Prod(
            Seq[Exp](
              Access("x", Seq[Variable](), Tensor),
              Access("y", Seq[Variable](), Tensor),
              Access("z", Seq[Variable](), Tensor)
            )
          )
        )
      )
    )
  }

  it should "merge a sequence of maps" in {
    val map1 = Map(
      (Access("x", Seq[Variable](), Tensor) -> Prod(
        Seq(Access("x", Seq[Variable](), Tensor))
      ))
    )
    val map2 = Map(
      (Access("y", Seq[Variable](), Tensor) -> Prod(
        Seq(Access("y", Seq[Variable](), Tensor))
      ))
    )
    val map3 = Map(
      (Access("z", Seq[Variable](), Tensor) -> Prod(
        Seq(Access("z", Seq[Variable](), Tensor))
      ))
    )
    val map4 = Map(
      (Access("x", Seq[Variable](), Tensor) -> Prod(
        Seq(Access("z", Seq[Variable](), Tensor))
      ))
    )
    val mapSeq = Seq(map1, map2, map3, map4)
    Utils.mergeMap(mapSeq)((v1, v2) =>
      Utils.prodTimesProd(v1, v2)
    ) should contain theSameElementsAs Map(
      Access("x", Seq[Variable](), Tensor) -> Prod(
        Seq(
          Access("x", Seq[Variable](), Tensor),
          Access("z", Seq[Variable](), Tensor)
        )
      ),
      Access("y", Seq[Variable](), Tensor) -> Prod(
        Seq(Access("y", Seq[Variable](), Tensor))
      ),
      Access("z", Seq[Variable](), Tensor) -> Prod(
        Seq(Access("z", Seq[Variable](), Tensor))
      )
    )
  }

  it should "convert a DimInfo to access map" in {
    val dimInfo = DimInfo(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      Seq(Variable("N"), ConstantInt(100))
    )
    dimInfo.toAccessMap should contain theSameElementsAs Map(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor) -> Seq(
        Variable("N"),
        ConstantInt(100)
      )
    )
  }

  it should "convert a DimInfo to access SoP" in {
    val dimInfo = DimInfo(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      Seq(Variable("N"), ConstantInt(100))
    )
    dimInfo.toSoP shouldBe SoP(
      Seq(
        Prod(
          Seq(
            Comparison("<=", ConstantInt(0), Variable("x")),
            Comparison(">", Variable("N"), Variable("x")),
            Comparison("<=", ConstantInt(0), Variable("y")),
            Comparison(">", ConstantInt(100), Variable("y"))
          )
        )
      )
    )
  }

  it should "convert a sequence of DimInfos to an access map" in {
    val dimInfo1 = DimInfo(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      Seq(Variable("N"), ConstantInt(100))
    )
    val dimInfo2 = DimInfo(
      Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor),
      Seq(Variable("M"), ConstantInt(1000))
    )
    val dimInfo3 = DimInfo(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      Seq(Variable("P"), ConstantInt(10000))
    )
    val dimInfoSeq = Seq[DimInfo](dimInfo1, dimInfo2, dimInfo3)
    dimInfoSeq.toAccessMap should contain theSameElementsAs Map(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor) ->
        Seq(Variable("N"), ConstantInt(100), Variable("P"), ConstantInt(10000)),
      Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor) ->
        Seq(Variable("M"), ConstantInt(1000))
    )
  }

  it should "get variables of an access" in {
    val exp = Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor)

    Utils.getVariables(exp) should contain theSameElementsAs Seq(
      Variable("x"),
      Variable("y")
    )
  }

  it should "get variables of a comparison" in {
    val exp = Comparison("<=", ConstantInt(0), Variable("x"))

    Utils.getVariables(exp) should contain theSameElementsAs Seq(
      Variable("x")
    )
  }

  it should "get variables of an index" in {
    val ind = Arithmetic(
      "+",
      Variable("x"),
      Arithmetic("*", Variable("y"), ConstantInt(2))
    )

    Utils.getVariablesInIndex(ind) should contain theSameElementsAs Seq(
      Variable("x"),
      Variable("y")
    )
  }

  it should "get all the variables in a rule" in {
    val rule = Seq(
      Rule(
        Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("x")),
                Comparison(">", Variable("N"), Variable("x")),
                Comparison("<=", ConstantInt(0), Variable("y")),
                Comparison(">", ConstantInt(100), Variable("y"))
              )
            )
          )
        )
      )
    )

    Utils.allVariables(rule) should contain theSameElementsAs Set("x", "y", "N")
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
    Utils.getNonDimensionVariables(rule) shouldBe Seq(
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
    Utils.getNonDimensionVariables(sop) shouldBe Seq(
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
    Utils.getNonDimensionVariables(prod) shouldBe Seq(
      Variable("i"),
      Variable("j"),
      Variable("l")
    )
  }

  it should "get all the variables in a sequence of rules" in {
    val rule1 = Rule(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("N"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(100), Variable("y"))
            )
          )
        )
      )
    )
    val rule2 = Rule(
      Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("M"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("z")),
              Comparison(">", ConstantInt(1000), Variable("z"))
            )
          )
        )
      )
    )
    val rule3 = Rule(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("P"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(10000), Variable("y"))
            )
          )
        )
      )
    )
    val rules = Seq(rule1, rule2, rule3)

    Utils.allVariables(rules) should contain theSameElementsAs Set(
      "x",
      "y",
      "z",
      "N",
      "M",
      "P"
    )
  }

  it should "get bounded variables in a rule" in {
    val rule = Seq(
      Rule(
        Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("x")),
                Comparison(">", Variable("N"), Variable("x")),
                Comparison("<=", ConstantInt(0), Variable("y")),
                Comparison(">", ConstantInt(100), Variable("y"))
              )
            )
          )
        )
      )
    )

    Utils.boundVariables(rule) should contain theSameElementsAs Set("x", "y")
  }

  it should "get bounded variables in a sequence of rules" in {
    val rule1 = Rule(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("N"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(100), Variable("y"))
            )
          )
        )
      )
    )
    val rule2 = Rule(
      Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("M"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("z")),
              Comparison(">", ConstantInt(1000), Variable("z"))
            )
          )
        )
      )
    )
    val rule3 = Rule(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("P"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(10000), Variable("y"))
            )
          )
        )
      )
    )
    val rules = Seq(rule1, rule2, rule3)

    Utils.boundVariables(rules) should contain theSameElementsAs Set(
      "x",
      "y",
      "z"
    )
  }

  it should "get unbounded variables in a rule" in {
    val rule = Seq(
      Rule(
        Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("x")),
                Comparison(">", Variable("N"), Variable("x")),
                Comparison("<=", ConstantInt(0), Variable("y")),
                Comparison(">", ConstantInt(100), Variable("y"))
              )
            )
          )
        )
      )
    )

    Utils.unboundVariables(rule) should contain theSameElementsAs Set("N")
  }

  it should "get unbounded variables in a sequence of rules" in {
    val rule1 = Rule(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("N"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(100), Variable("y"))
            )
          )
        )
      )
    )
    val rule2 = Rule(
      Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("M"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("z")),
              Comparison(">", ConstantInt(1000), Variable("z"))
            )
          )
        )
      )
    )
    val rule3 = Rule(
      Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("P"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(10000), Variable("y"))
            )
          )
        )
      )
    )
    val rules = Seq(rule1, rule2, rule3)

    Utils.unboundVariables(rules) should contain theSameElementsAs Set(
      "N",
      "M",
      "P"
    )
  }

  it should "concatenate a sequence of SoPs in one SoP" in {
    val sop1 = SoP(
      Seq(
        Prod(
          Seq(
            Comparison("<=", ConstantInt(0), Variable("x")),
            Comparison(">", Variable("N"), Variable("x")),
            Comparison("<=", ConstantInt(0), Variable("y")),
            Comparison(">", ConstantInt(100), Variable("y"))
          )
        )
      )
    )
    val sop2 = SoP(
      Seq(
        Prod(
          Seq(
            Comparison("<=", ConstantInt(0), Variable("x")),
            Comparison(">", Variable("M"), Variable("x")),
            Comparison("<=", ConstantInt(0), Variable("z")),
            Comparison(">", ConstantInt(1000), Variable("z"))
          )
        )
      )
    )
    val sop3 = SoP(
      Seq(
        Prod(
          Seq(
            Comparison("<=", ConstantInt(0), Variable("x")),
            Comparison(">", Variable("P"), Variable("x")),
            Comparison("<=", ConstantInt(0), Variable("y")),
            Comparison(">", ConstantInt(10000), Variable("y"))
          )
        )
      )
    )
    val sops = Seq(sop1, sop2, sop3)

    Utils.concatSoP(sops) should be(
      SoP(
        Seq(
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("N"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(100), Variable("y"))
            )
          ),
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("M"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("z")),
              Comparison(">", ConstantInt(1000), Variable("z"))
            )
          ),
          Prod(
            Seq(
              Comparison("<=", ConstantInt(0), Variable("x")),
              Comparison(">", Variable("P"), Variable("x")),
              Comparison("<=", ConstantInt(0), Variable("y")),
              Comparison(">", ConstantInt(10000), Variable("y"))
            )
          )
        )
      )
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
    Utils.alphaRename(sop, alphaRenameMap) shouldBe expectedSop
  }

  it should "alpha rename an arithmetic based on the alpha rename map" in {
    val arithmetic = Arithmetic("+", Variable("i"), Variable("j"))
    val alphaRenameMap = Map(Variable("i") -> Variable("i2"))
    val expectedArithmetic = Arithmetic("+", Variable("i2"), Variable("j"))
    Utils.alphaRename(
      arithmetic,
      alphaRenameMap
    ) shouldBe expectedArithmetic
  }

}
