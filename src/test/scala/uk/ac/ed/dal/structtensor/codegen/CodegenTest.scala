package uk.ac.ed.dal
package structtensor
package codegen

import utils._
import Utils._

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

class CodegenTest extends AnyFlatSpec with Matchers {
  "Codegen" should "generate code for SpMV_D without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_D.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_D_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_D_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/SpMV_D_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_D with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_D.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_D_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_D_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/SpMV_D_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_D without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_D_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_D_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_D_wo_body_DataLayout.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/SpMV_D_wo_body_DataLayout_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_D with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_D_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_D_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_D_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/SpMV_D_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_UT without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_UT.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_UT_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_D_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/SpMV_D_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_UT with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_UT.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_UT_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_UT_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/SpMV_UT_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_UT without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_UT_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_UT_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_UT_wo_body_DataLayout.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/SpMV_UT_wo_body_DataLayout_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for SpMV_UT with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/SpMV_UT_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/SpMV_UT_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/SpMV_UT_w_body_DataLayout.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/SpMV_UT_w_body_DataLayout_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PGLM without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PGLM.stur",
        "-o",
        "src/test/resources/test_outputs/PGLM_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PGLM_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PGLM_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PGLM with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PGLM.stur",
        "-o",
        "src/test/resources/test_outputs/PGLM_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/PGLM_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PGLM_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PGLM without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PGLM_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/PGLM_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PGLM_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/PGLM_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PGLM with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PGLM_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/PGLM_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PGLM_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/PGLM_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_DP without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_DP.stur",
        "-o",
        "src/test/resources/test_outputs/THP_DP_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_DP_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/THP_DP_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_DP with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_DP.stur",
        "-o",
        "src/test/resources/test_outputs/THP_DP_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_DP_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/THP_DP_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_DP without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_DP_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/THP_DP_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_DP_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/THP_DP_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_DP with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_DP_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/THP_DP_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_DP_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/THP_DP_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_I without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_I.stur",
        "-o",
        "src/test/resources/test_outputs/THP_I_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_I_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/THP_I_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_I with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_I.stur",
        "-o",
        "src/test/resources/test_outputs/THP_I_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_I_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/THP_I_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_I without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_I_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/THP_I_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_I_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/THP_I_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_I with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_I_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/THP_I_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_I_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/THP_I_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_J without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_J.stur",
        "-o",
        "src/test/resources/test_outputs/THP_J_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_J_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/THP_J_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_J with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_J.stur",
        "-o",
        "src/test/resources/test_outputs/THP_J_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_J_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/THP_J_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_J without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_J_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/THP_J_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_J_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/THP_J_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for THP_J with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/THP_J_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/THP_J_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/THP_J_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/THP_J_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_UT without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_UT.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_UT_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_UT_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/TTM_UT_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_UT with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_UT.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_UT_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_UT_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/TTM_UT_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_UT without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_UT_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_UT_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_UT_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/TTM_UT_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_UT with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_UT_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_UT_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_UT_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/TTM_UT_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_DP without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_DP.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_DP_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_DP_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/TTM_DP_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_DP with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_DP.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_DP_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_DP_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/TTM_DP_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_DP without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_DP_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_DP_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_DP_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/TTM_DP_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_DP with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_DP_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_DP_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_DP_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/TTM_DP_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_J without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_J.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_J_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_J_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/TTM_J_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_J with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_J.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_J_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_J_w_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/TTM_J_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_J without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_J_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_J_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_J_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/TTM_J_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for TTM_J with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/TTM_J_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/TTM_J_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/TTM_J_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/TTM_J_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_I without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_I.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_I_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_I_wo_body.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_I_wo_body_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_I with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_I.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_I_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_I_w_body.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_I_w_body_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_I without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_I_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_I_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_I_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_I_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_I with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_I_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_I_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_I_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_I_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_J without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_J.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_J_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_J_wo_body.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_J_wo_body_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_J with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_J.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_J_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_J_w_body.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_J_w_body_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_J without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_J_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_J_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_J_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_J_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_J with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_J_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_J_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_J_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_J_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_IJ without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_IJ.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_IJ_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_IJ_wo_body.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_IJ_wo_body_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_IJ with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_IJ.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_IJ_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_IJ_w_body.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_IJ_w_body_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_IJ without the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_IJ_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_IJ_wo_body_DataLayout_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_IJ_wo_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_IJ_wo_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for MTTKRP_IJ with the body with data layout compression" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/MTTKRP_IJ_DataLayout.stur",
        "-o",
        "src/test/resources/test_outputs/MTTKRP_IJ_w_body_DataLayout_test.cpp",
        "--init-tensors"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/MTTKRP_IJ_w_body_DataLayout.cpp"
      )
    val file2 =
      scala.io.Source.fromFile(
        "src/test/resources/test_outputs/MTTKRP_IJ_w_body_DataLayout_test.cpp"
      )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for LRC without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/LRC.stur",
        "-o",
        "src/test/resources/test_outputs/LRC_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/LRC_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/LRC_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for LRC with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/LRC.stur",
        "-o",
        "src/test/resources/test_outputs/LRC_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/LRC_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/LRC_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for LRA without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/LRA.stur",
        "-o",
        "src/test/resources/test_outputs/LRA_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/LRA_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/LRA_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for LRA with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/LRA.stur",
        "-o",
        "src/test/resources/test_outputs/LRA_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/LRA_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/LRA_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR2C without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR2C.stur",
        "-o",
        "src/test/resources/test_outputs/PR2C_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PR2C_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR2C_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR2C with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR2C.stur",
        "-o",
        "src/test/resources/test_outputs/PR2C_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/PR2C_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR2C_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR2A without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR2A.stur",
        "-o",
        "src/test/resources/test_outputs/PR2A_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PR2A_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR2A_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR2A with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR2A.stur",
        "-o",
        "src/test/resources/test_outputs/PR2A_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/PR2A_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR2A_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR3C without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR3C.stur",
        "-o",
        "src/test/resources/test_outputs/PR3C_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PR3C_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR3C_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR3C with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR3C.stur",
        "-o",
        "src/test/resources/test_outputs/PR3C_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/PR3C_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR3C_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR3A without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR3A.stur",
        "-o",
        "src/test/resources/test_outputs/PR3A_wo_body_test.cpp"
      )
    )

    val file1 =
      scala.io.Source.fromFile(
        "src/test/resources/correct_test_outputs/PR3A_wo_body.cpp"
      )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR3A_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for PR3A with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/PR3A.stur",
        "-o",
        "src/test/resources/test_outputs/PR3A_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/PR3A_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/PR3A_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when the structure information is provided independent of the iterators with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/independent-iterator.stur",
        "-o",
        "src/test/resources/test_outputs/independent-iterator_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/independent-iterator_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/independent-iterator_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when there is a scalar tensor in the computation without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/scalar-tensor-op.stur",
        "-o",
        "src/test/resources/test_outputs/scalar-tensor-op_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/scalar-tensor-op_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/scalar-tensor-op_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when there is a scalar tensor in the computation with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/scalar-tensor-op.stur",
        "-o",
        "src/test/resources/test_outputs/scalar-tensor-op_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/scalar-tensor-op_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/scalar-tensor-op_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when there is subtraction in form of multiplication in the computation without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/subtraction.stur",
        "-o",
        "src/test/resources/test_outputs/subtraction_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/subtraction_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/subtraction_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when there is subtraction in form of multiplication in the computation with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/subtraction.stur",
        "-o",
        "src/test/resources/test_outputs/subtraction_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/subtraction_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/subtraction_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when there is mixture of scalar tensors and constants in the computation without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/scalar-constant-mixture.stur",
        "-o",
        "src/test/resources/test_outputs/scalar-constant-mixture_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/scalar-constant-mixture_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/scalar-constant-mixture_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when there is mixture of scalar tensors and constants in the computation with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/scalar-constant-mixture.stur",
        "-o",
        "src/test/resources/test_outputs/scalar-constant-mixture_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/scalar-constant-mixture_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/scalar-constant-mixture_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when the iterators are renamed later on in the computation without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/independent-iterator-renaming.stur",
        "-o",
        "src/test/resources/test_outputs/independent-iterator-renaming_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/independent-iterator-renaming_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/independent-iterator-renaming_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when the iterators are renamed later on in the computation with the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/independent-iterator-renaming.stur",
        "-o",
        "src/test/resources/test_outputs/independent-iterator-renaming_w_body_test.cpp",
        "--init-tensors"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/independent-iterator-renaming_w_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/independent-iterator-renaming_w_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }

  it should "generate code for when the same scalar appears in the computation without the body" in {
    Utils.cnt = 0
    Main.main(
      Array(
        "-i",
        "examples/same-scalar.stur",
        "-o",
        "src/test/resources/test_outputs/same-scalar_wo_body_test.cpp"
      )
    )

    val file1 = scala.io.Source.fromFile(
      "src/test/resources/correct_test_outputs/same-scalar_wo_body.cpp"
    )
    val file2 = scala.io.Source.fromFile(
      "src/test/resources/test_outputs/same-scalar_wo_body_test.cpp"
    )
    val lines1 = file1.getLines().toList
    val lines2 = file2.getLines().toList
    lines2 should be(lines1)
  }
}
