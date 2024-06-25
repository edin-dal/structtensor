package uk.ac.ed.dal
package structtensor
package utils

import compiler._

import java.io._

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution
import uk.ac.ed.dal.structtensor.utils.Utils.DimInfoOps

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

  // it should "convert a sequence of DimInfos to an access map" in {
  //   val dimInfo1 = DimInfo(
  //     Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
  //     Seq(Variable("N"), ConstantInt(100))
  //   )
  //   val dimInfo2 = DimInfo(
  //     Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor),
  //     Seq(Variable("M"), ConstantInt(1000))
  //   )
  //   val dimInfo3 = DimInfo(
  //     Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor),
  //     Seq(Variable("P"), ConstantInt(10000))
  //   )
  //   val dimInfoSeq = Seq[DimInfo](dimInfo1, dimInfo2, dimInfo3)
  //   dimInfoSeq.toAccessMap should contain theSameElementsAs Map(
  //     Access("T", Seq[Variable](Variable("x"), Variable("y")), Tensor) ->
  //       Seq(Variable("N"), ConstantInt(100), Variable("P"), ConstantInt(10000)),
  //     Access("V", Seq[Variable](Variable("x"), Variable("z")), Tensor) ->
  //       Seq(Variable("M"), ConstantInt(1000))
  //   )
  // }

}
