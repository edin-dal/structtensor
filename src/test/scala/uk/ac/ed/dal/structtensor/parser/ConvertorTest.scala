package uk.ac.ed.dal
package structtensor
package parser

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

import compiler._
import utils._

import scala.collection.mutable.LinkedHashMap
import uk.ac.ed.dal.structtensor.utils.Shared.emptySoP

class ConvertorTest
    extends AnyFlatSpec
    with Matchers
    with ParallelTestExecution {

  "Convertor" should "group rules correctly" in {
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

  it should "get heads that require dimension correctly" in {
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

  it should "check dimensions available correctly" in {
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

  it should "find upper bound of a variable correctly" in {
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

  it should "add 1 to the upper bound of the variable, if the variable is less than equal to the bound" in {
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

  it should "add 1 from the upper bound of the variable, if the bound is greater than equal to the variable" in {
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

}
