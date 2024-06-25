package uk.ac.ed.dal
package structtensor
package utils

import compiler._

import java.io._

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

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
    Utils.getVar("test") should be("test1")
    Utils.getVar("test") should be("test2")
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
}
