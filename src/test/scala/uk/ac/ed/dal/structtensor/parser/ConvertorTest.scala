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

}
