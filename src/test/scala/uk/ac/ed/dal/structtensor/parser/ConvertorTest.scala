package uk.ac.ed.dal
package structtensor
package parser

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

import compiler._
import utils._

import scala.collection.mutable.LinkedHashMap
import utils.Utils.emptySoP

class ConvertorTest
    extends AnyFlatSpec
    with Matchers
    with ParallelTestExecution {

  "Convertor" should "group rules" in {
    val rules = Seq(
      Rule(Access("foo", Seq(Variable("x")), Tensor), emptySoP()),
      Rule(Access("bar", Seq(Variable("y")), UniqueSet), emptySoP()),
      Rule(Access("baz", Seq(Variable("z")), RedundancyMap), emptySoP()),
      Rule(Access("qux", Seq(Variable("w")), DimensionType), emptySoP())
    )
    val (
      headToTensorMap,
      headToUniqueSetMap,
      headToRedundancyMapMap,
      headToDimensionTypeMap
    ) = Convertor.groupRules(rules)
    headToTensorMap should contain theSameElementsAs Map(
      Access("foo", Seq(Variable("x")), Tensor) -> Rule(
        Access("foo", Seq(Variable("x")), Tensor),
        emptySoP()
      )
    )
    headToUniqueSetMap should contain theSameElementsAs Map(
      Access("bar", Seq(Variable("y")), Tensor) -> Rule(
        Access("bar", Seq(Variable("y")), UniqueSet),
        emptySoP()
      )
    )
    headToRedundancyMapMap should contain theSameElementsAs Map(
      Access("baz", Seq(Variable("z")), Tensor) -> Rule(
        Access("baz", Seq(Variable("z")), RedundancyMap),
        emptySoP()
      )
    )
    headToDimensionTypeMap should contain theSameElementsAs Map(
      Access("qux", Seq(Variable("w")), Tensor) -> Rule(
        Access("qux", Seq(Variable("w")), DimensionType),
        emptySoP()
      )
    )
  }

  it should "get heads that require dimension" in {
    val headToTensorMap = LinkedHashMap(
      Access("foo", Seq(Variable("z"), Variable("y")), Tensor) -> Rule(
        Access("foo", Seq(Variable("z"), Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("bar", Seq(Variable("y")), Tensor),
                Access("baz", Seq(Variable("z")), Tensor)
              )
            )
          )
        )
      ),
      Access("qux", Seq(Variable("y")), Tensor) -> Rule(
        Access("qux", Seq(Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(Seq(Access("foo", Seq(Variable("z"), Variable("y")), Tensor)))
          )
        )
      )
    )
    val heads = Convertor.getHeadsThatRequireDim(headToTensorMap)
    heads should contain theSameElementsAs Seq(
      Access("bar", Seq(Variable("y")), Tensor),
      Access("baz", Seq(Variable("z")), Tensor)
    )
  }

  it should "check dimensions available" in {
    val headToTensorMap = LinkedHashMap(
      Access("foo", Seq(Variable("z"), Variable("y")), Tensor) -> Rule(
        Access("foo", Seq(Variable("z"), Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("bar", Seq(Variable("y")), Tensor),
                Access("baz", Seq(Variable("z")), Tensor)
              )
            )
          )
        )
      ),
      Access("qux", Seq(Variable("y")), Tensor) -> Rule(
        Access("qux", Seq(Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(Seq(Access("foo", Seq(Variable("z"), Variable("y")), Tensor)))
          )
        )
      )
    )
    val headToDimensionMap = Map(
      Access("bar", Seq(Variable("y")), Tensor) -> Rule(
        Access("bar", Seq(Variable("y")), Tensor),
        emptySoP()
      ),
      Access("baz", Seq(Variable("z")), Tensor) -> Rule(
        Access("baz", Seq(Variable("z")), Tensor),
        emptySoP()
      )
    )
    val result =
      Convertor.checkDimsAvailable(headToTensorMap, headToDimensionMap)
    result shouldBe true
  }

  it should "detect when dimension is not available" in {
    val headToTensorMap = LinkedHashMap(
      Access("foo", Seq(Variable("z"), Variable("y")), Tensor) -> Rule(
        Access("foo", Seq(Variable("z"), Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("bar", Seq(Variable("y")), Tensor),
                Access("baz", Seq(Variable("z")), Tensor)
              )
            )
          )
        )
      ),
      Access("qux", Seq(Variable("y")), Tensor) -> Rule(
        Access("qux", Seq(Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(Seq(Access("foo", Seq(Variable("z"), Variable("y")), Tensor)))
          )
        )
      )
    )
    val headToDimensionMap = Map(
      Access("bar", Seq(Variable("y")), Tensor) -> Rule(
        Access("bar", Seq(Variable("y")), Tensor),
        emptySoP()
      )
    )
    val result =
      Convertor.checkDimsAvailable(headToTensorMap, headToDimensionMap)
    result should not be true
  }

  it should "find upper bound of a variable" in {
    val sop = SoP(
      Seq(
        Prod(
          Seq(
            Comparison(">=", Variable("x"), Variable("y")),
            Comparison("<", Variable("x"), Variable("z"))
          )
        )
      )
    )
    val result = Convertor.findUpperBound(Variable("x"), sop)
    result shouldBe Variable("z")
  }

  it should "find upper bound of a variable, if the variable is less than equal to the bound" in {
    val sop = SoP(
      Seq(
        Prod(
          Seq(
            Comparison(">=", Variable("x"), Variable("y")),
            Comparison("<=", Variable("x"), Variable("z"))
          )
        )
      )
    )
    val result = Convertor.findUpperBound(Variable("x"), sop)
    result shouldBe Arithmetic("+", Variable("z"), ConstantInt(1))
  }

  it should "find upper bound of a variable, if the bound is greater than equal to the variable" in {
    val sop = SoP(
      Seq(
        Prod(
          Seq(
            Comparison("<=", Variable("y"), Variable("x")),
            Comparison(">=", Variable("z"), Variable("x"))
          )
        )
      )
    )
    val result = Convertor.findUpperBound(Variable("x"), sop)
    result shouldBe Arithmetic("+", Variable("z"), ConstantInt(1))
  }

  it should "find the upper bound of a variable in an arithmetic with the first operand being the variable" in {
    val sop = SoP(
      Seq(
        Prod(
          Seq(
            Comparison(">", Variable("z"), Variable("t")),
            Comparison(
              "=",
              Arithmetic("-", Variable("x"), Variable("y")),
              Variable("t")
            )
          )
        )
      )
    )
    val result = Convertor.findUpperBound(Variable("x"), sop)
    result shouldBe Arithmetic("+", Variable("z"), Variable("y"))
  }

  it should "extract unique set" in {
    val headToUniqueSetMap = Map(
      Access("foo", Seq(Variable("y"), Variable("z")), UniqueSet) -> Rule(
        Access("foo", Seq(Variable("y"), Variable("z")), UniqueSet),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("bar", Seq(Variable("y")), Tensor),
                Access("baz", Seq(Variable("z")), Tensor)
              )
            )
          )
        )
      )
    )

    val dimInfoMap = Map(
      Access("bar", Seq(Variable("y")), Tensor) -> DimInfo(
        Access("bar", Seq(Variable("y")), Tensor),
        Seq(Variable("N"))
      ),
      Access("baz", Seq(Variable("z")), Tensor) -> DimInfo(
        Access("baz", Seq(Variable("z")), Tensor),
        Seq(Variable("M"))
      )
    )

    val result = Convertor.extractSet(headToUniqueSetMap, dimInfoMap, UniqueSet)
    result should contain theSameElementsAs Map(
      Access("bar", Seq(Variable("y")), Tensor) -> Rule(
        Access("bar", Seq(Variable("y")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("y")),
                Comparison(">", Variable("N"), Variable("y"))
              )
            )
          )
        )
      ),
      Access("baz", Seq(Variable("z")), Tensor) -> Rule(
        Access("baz", Seq(Variable("z")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("z")),
                Comparison(">", Variable("M"), Variable("z"))
              )
            )
          )
        )
      )
    )
  }

  it should "get all tensors" in {
    val rules = Seq(
      Rule(
        Access("foo", Seq(Variable("x")), Tensor),
        SoP(Seq(Prod(Seq(Access("qux", Seq(Variable("x")), Tensor)))))
      ),
      Rule(
        Access("bar", Seq(Variable("y")), Tensor),
        SoP(Seq(Prod(Seq(Access("awd", Seq(Variable("y")), Tensor)))))
      ),
      Rule(
        Access("baz", Seq(Variable("z")), Tensor),
        SoP(Seq(Prod(Seq(Access("lop", Seq(Variable("z")), Tensor)))))
      )
    )
    val result = Convertor.getAllTensors(rules)
    result should contain theSameElementsAs Seq(
      Access("foo", Seq(Variable("x")), Tensor),
      Access("bar", Seq(Variable("y")), Tensor),
      Access("baz", Seq(Variable("z")), Tensor),
      Access("qux", Seq(Variable("x")), Tensor),
      Access("awd", Seq(Variable("y")), Tensor),
      Access("lop", Seq(Variable("z")), Tensor)
    )
  }

  it should "convert rules" in {
    val rules = Seq(
      Rule(
        Access("A", Seq(Variable("i"), Variable("j")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("f", Seq(Variable("i")), Tensor),
                Access("f", Seq(Variable("j")), Tensor)
              )
            )
          )
        )
      ),
      Rule(
        Access("B", Seq(Variable("i"), Variable("j"), Variable("k")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("f", Seq(Variable("i")), Tensor),
                Access("f", Seq(Variable("j")), Tensor),
                Access("f", Seq(Variable("k")), Tensor)
              )
            )
          )
        )
      ),
      Rule(
        Access(
          "C",
          Seq(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
          Tensor
        ),
        SoP(
          Seq(
            Prod(
              Seq(
                Access("f", Seq(Variable("i")), Tensor),
                Access("f", Seq(Variable("j")), Tensor),
                Access("f", Seq(Variable("k")), Tensor),
                Access("f", Seq(Variable("l")), Tensor)
              )
            )
          )
        )
      ),
      Rule(
        Access("f", Seq(Variable("i")), DimensionType),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison("<", Variable("i"), Variable("N"))
              )
            )
          )
        )
      ),
      Rule(
        Access("f", Seq(Variable("j")), DimensionType),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison("<", Variable("j"), Variable("N"))
              )
            )
          )
        )
      ),
      Rule(
        Access("f", Seq(Variable("k")), DimensionType),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("k")),
                Comparison("<", Variable("k"), Variable("N"))
              )
            )
          )
        )
      ),
      Rule(
        Access("f", Seq(Variable("l")), DimensionType),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("l")),
                Comparison("<", Variable("l"), Variable("N"))
              )
            )
          )
        )
      ),
      Rule(
        Access("A", Seq(Variable("i"), Variable("j")), DimensionType),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison("<", Variable("i"), Variable("N")),
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison("<", Variable("j"), Variable("N"))
              )
            )
          )
        )
      ),
      Rule(
        Access(
          "B",
          Seq(Variable("i"), Variable("j"), Variable("k")),
          DimensionType
        ),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison("<", Variable("i"), Variable("N")),
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison("<", Variable("j"), Variable("N")),
                Comparison("<=", ConstantInt(0), Variable("k")),
                Comparison("<", Variable("k"), Variable("N"))
              )
            )
          )
        )
      ),
      Rule(
        Access(
          "C",
          Seq(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
          DimensionType
        ),
        SoP(
          Seq(
            Prod(
              Seq(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison("<", Variable("i"), Variable("N")),
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison("<", Variable("j"), Variable("N")),
                Comparison("<=", ConstantInt(0), Variable("k")),
                Comparison("<", Variable("k"), Variable("N")),
                Comparison("<=", ConstantInt(0), Variable("l")),
                Comparison("<", Variable("l"), Variable("N"))
              )
            )
          )
        )
      )
    )

    val result = Convertor.convertRules(rules)

    result._1 should contain theSameElementsAs List(
      Access("A", List(Variable("i"), Variable("j")), Tensor),
      Access("f", List(Variable("i")), Tensor),
      Access("f", List(Variable("j")), Tensor),
      Access("B", List(Variable("i"), Variable("j"), Variable("k")), Tensor),
      Access("f", List(Variable("k")), Tensor),
      Access(
        "C",
        List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
        Tensor
      ),
      Access("f", List(Variable("l")), Tensor)
    )

    result._2 should contain theSameElementsAs List(
      Rule(
        Access("A", List(Variable("i"), Variable("j")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Access("f", List(Variable("i")), Tensor),
                Access("f", List(Variable("j")), Tensor)
              )
            )
          )
        )
      ),
      Rule(
        Access("B", List(Variable("i"), Variable("j"), Variable("k")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Access("f", List(Variable("i")), Tensor),
                Access("f", List(Variable("j")), Tensor),
                Access("f", List(Variable("k")), Tensor)
              )
            )
          )
        )
      ),
      Rule(
        Access(
          "C",
          List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
          Tensor
        ),
        SoP(
          List(
            Prod(
              List(
                Access("f", List(Variable("i")), Tensor),
                Access("f", List(Variable("j")), Tensor),
                Access("f", List(Variable("k")), Tensor),
                Access("f", List(Variable("l")), Tensor)
              )
            )
          )
        )
      )
    )

    result._3 should contain theSameElementsAs List(
      DimInfo(Access("f", List(Variable("l")), Tensor), List(Variable("N"))),
      DimInfo(
        Access("B", List(Variable("i"), Variable("j"), Variable("k")), Tensor),
        List(Variable("N"), Variable("N"), Variable("N"))
      ),
      DimInfo(Access("f", List(Variable("j")), Tensor), List(Variable("N"))),
      DimInfo(
        Access(
          "C",
          List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
          Tensor
        ),
        List(Variable("N"), Variable("N"), Variable("N"), Variable("N"))
      ),
      DimInfo(Access("f", List(Variable("i")), Tensor), List(Variable("N"))),
      DimInfo(
        Access("A", List(Variable("i"), Variable("j")), Tensor),
        List(Variable("N"), Variable("N"))
      ),
      DimInfo(Access("f", List(Variable("k")), Tensor), List(Variable("N")))
    )

    result._4 should contain theSameElementsAs Map(
      Access("f", List(Variable("l")), Tensor) -> Rule(
        Access("f", List(Variable("l")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("l")),
                Comparison(">", Variable("N"), Variable("l"))
              )
            )
          )
        )
      ),
      Access(
        "B",
        List(Variable("i"), Variable("j"), Variable("k")),
        Tensor
      ) -> Rule(
        Access("B", List(Variable("i"), Variable("j"), Variable("k")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison(">", Variable("N"), Variable("i")),
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison(">", Variable("N"), Variable("j")),
                Comparison("<=", ConstantInt(0), Variable("k")),
                Comparison(">", Variable("N"), Variable("k"))
              )
            )
          )
        )
      ),
      Access("f", List(Variable("j")), Tensor) -> Rule(
        Access("f", List(Variable("j")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison(">", Variable("N"), Variable("j"))
              )
            )
          )
        )
      ),
      Access(
        "C",
        List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
        Tensor
      ) -> Rule(
        Access(
          "C",
          List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
          Tensor
        ),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison(">", Variable("N"), Variable("i")),
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison(">", Variable("N"), Variable("j")),
                Comparison("<=", ConstantInt(0), Variable("k")),
                Comparison(">", Variable("N"), Variable("k")),
                Comparison("<=", ConstantInt(0), Variable("l")),
                Comparison(">", Variable("N"), Variable("l"))
              )
            )
          )
        )
      ),
      Access("f", List(Variable("i")), Tensor) -> Rule(
        Access("f", List(Variable("i")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison(">", Variable("N"), Variable("i"))
              )
            )
          )
        )
      ),
      Access("A", List(Variable("i"), Variable("j")), Tensor) -> Rule(
        Access("A", List(Variable("i"), Variable("j")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("i")),
                Comparison(">", Variable("N"), Variable("i")),
                Comparison("<=", ConstantInt(0), Variable("j")),
                Comparison(">", Variable("N"), Variable("j"))
              )
            )
          )
        )
      ),
      Access("f", List(Variable("k")), Tensor) -> Rule(
        Access("f", List(Variable("k")), Tensor),
        SoP(
          List(
            Prod(
              List(
                Comparison("<=", ConstantInt(0), Variable("k")),
                Comparison(">", Variable("N"), Variable("k"))
              )
            )
          )
        )
      )
    )

    result._5 should contain theSameElementsAs Map(
      Access("f", List(Variable("l")), Tensor) -> Rule(
        Access("f", List(Variable("l")), Tensor),
        SoP(List())
      ),
      Access(
        "B",
        List(Variable("i"), Variable("j"), Variable("k")),
        Tensor
      ) -> Rule(
        Access("B", List(Variable("i"), Variable("j"), Variable("k")), Tensor),
        SoP(List())
      ),
      Access("f", List(Variable("j")), Tensor) -> Rule(
        Access("f", List(Variable("j")), Tensor),
        SoP(List())
      ),
      Access(
        "C",
        List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
        Tensor
      ) -> Rule(
        Access(
          "C",
          List(Variable("i"), Variable("j"), Variable("k"), Variable("l")),
          Tensor
        ),
        SoP(List())
      ),
      Access("f", List(Variable("i")), Tensor) -> Rule(
        Access("f", List(Variable("i")), Tensor),
        SoP(List())
      ),
      Access("A", List(Variable("i"), Variable("j")), Tensor) -> Rule(
        Access("A", List(Variable("i"), Variable("j")), Tensor),
        SoP(List())
      ),
      Access("f", List(Variable("k")), Tensor) -> Rule(
        Access("f", List(Variable("k")), Tensor),
        SoP(List())
      )
    )

  }
}