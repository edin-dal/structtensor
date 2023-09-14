package uk.ac.ed.dal
package structtensor

import apps._

object Main extends App {
  val help: String = s"""
Please specify the experiment name and select whether you want sparse datalayout for the input [use `sbt "run <exp> [sparse]"`]:
LRC       = Linear Regression - Creation
PR2C      = Polynomial Regression Degree 2 - Creation
PR3C      = Polynomial Regression Degree 3 - Creation
LRA       = Linear Regression - Addition
PR2A      = Polynomial Regression Degree 2 - Addition
PR3A      = Polynomial Regression Degree 3 - Addition
TTM_DP    = TTM: Diagonal (Plane)
TTM_J     = TTM: Fixed j
TTM_UT    = TTM: Upper Triangular (Half-cube)
THP_DP    = THP: Diagonal (Plane)
THP_I     = THP: Fixed i
THP_J     = THP: Fixed j
MTTKRP_IJ = MTTKRP: Fixed i & j
MTTKRP_I  = MTTKRP: Fixed i
MTTKRP_J  = MTTKRP: Fixed j
E2E_LR    = E2E - Linear Regression
E2E_PR2   = E2E - Polynomial Regression Degree 2
ODC       = One-Dimensional Convolution
ODCC      = One-Dimensional Circular Convolution
PGLM      = Population Growth Leslie Matrix
"""
  if (args.length >= 1) {
    val sparse: Boolean = if (args.length >= 2 && (args(1).toLowerCase() == "sparse" || args(1).toLowerCase() == "s" || args(1).toLowerCase() == "-s") ) true else false
    val codeLang: String = if (args.length >= 3) args(2) else "CPP"
    val codeMotion: Boolean = if (args.contains("no-cm")) false else true
    if (codeLang == "CPP") {
      args(0) match {
        case "LRC" => LRC(codeMotion=codeMotion)
        case "PR2C" => PR2C(codeMotion=codeMotion)
        case "PR3C" => PR3C(codeMotion=codeMotion)
        case "LRA" => LRA(codeMotion=codeMotion)
        case "PR2A" => PR2A(codeMotion=codeMotion)
        case "PR3A" => PR3A(codeMotion=codeMotion)
        case "TTM_DP" => TTM("diag_p", sparse, codeMotion=codeMotion)
        case "TTM_J" => TTM("fixed_j", sparse, codeMotion=codeMotion)
        case "TTM_UT" => TTM("uhc", sparse, codeMotion=codeMotion)
        case "THP_DP" => THP("diag_p", sparse, codeMotion=codeMotion)
        case "THP_I" => THP("fixed_i", sparse, codeMotion=codeMotion)
        case "THP_J" => THP("fixed_j", sparse, codeMotion=codeMotion)
        case "MTTKRP_IJ" => MTTKRP("fixed_ij", sparse, codeMotion=codeMotion)
        case "MTTKRP_I" => MTTKRP("fixed_i", sparse, codeMotion=codeMotion)
        case "MTTKRP_J" => MTTKRP("fixed_j", sparse, codeMotion=codeMotion)
        case "E2E_LR" => E2E_PRK(1, codeMotion=codeMotion)
        case "E2E_PR2" => E2E_PRK(2, codeMotion=codeMotion)
        case "ODC" => ODC(sparse, codeMotion=codeMotion)
        case "ODCC" => ODCC(sparse, codeMotion=codeMotion)
        case "PGLM" => PGLM(sparse, codeMotion=codeMotion)
        case "SpMV_UT" => SpMV("ut", sparse, codeMotion=codeMotion)
        case "SpMV_D" => SpMV("diag", sparse, codeMotion=codeMotion)
        case _ => println(help)
      }
    } else if (codeLang == "C") {
      args(0) match {
        // case "LRC" => LRC(codeMotion=codeMotion)
        // case "PR2C" => PR2C(codeMotion=codeMotion)
        // case "PR3C" => PR3C(codeMotion=codeMotion)
        // case "LRA" => LRA(codeMotion=codeMotion)
        // case "PR2A" => PR2A(codeMotion=codeMotion)
        // case "PR3A" => PR3A(codeMotion=codeMotion)
        // case "TTM_DP" => TTM("diag_p", sparse, codeMotion=codeMotion)
        // case "TTM_J" => TTM("fixed_j", sparse, codeMotion=codeMotion)
        // case "TTM_UT" => TTM("uhc", sparse, codeMotion=codeMotion)
        // case "THP_DP" => THP("diag_p", sparse, codeMotion=codeMotion)
        // case "THP_I" => THP("fixed_i", sparse, codeMotion=codeMotion)
        // case "THP_J" => THP("fixed_j", sparse, codeMotion=codeMotion)
        case "MTTKRP_IJ" => MTTKRP.C("fixed_ij", sparse, codeMotion=codeMotion)
        case "MTTKRP_I" => MTTKRP.C("fixed_i", sparse, codeMotion=codeMotion)
        case "MTTKRP_J" => MTTKRP.C("fixed_j", sparse, codeMotion=codeMotion)
        // case "E2E_LR" => E2E_PRK(1, codeMotion=codeMotion)
        // case "E2E_PR2" => E2E_PRK(2, codeMotion=codeMotion)
        // case "ODC" => ODC(sparse, codeMotion=codeMotion)
        // case "ODCC" => ODCC(sparse, codeMotion=codeMotion)
        // case "PGLM" => PGLM(sparse, codeMotion=codeMotion)
        // case "SpMV_UT" => SpMV("ut", sparse, codeMotion=codeMotion)
        // case "SpMV_D" => SpMV("diag", sparse, codeMotion=codeMotion)
        case _ => println(help)
      }
    } else if (codeLang == "MLIR") {
      args(0) match {
        case "LRC" => LRC.MLIR()
        case "PR2C" => PR2C.MLIR()
        case "PR3C" => PR3C.MLIR()
        case "LRA" => LRA.MLIR()
        // case "PR2A" => PR2A.MLIR()
        // case "PR3A" => PR3A.MLIR()
        case "TTM_DP" => TTM.MLIR("diag_p", sparse)
        case "TTM_J" => TTM.MLIR("fixed_j", sparse)
        case "TTM_UT" => TTM.MLIR("uhc", sparse) // Still doesn't work
        case "THP_DP" => THP.MLIR("diag_p", sparse)
        case "THP_I" => THP.MLIR("fixed_i", sparse)
        case "THP_J" => THP.MLIR("fixed_j", sparse)
        case "MTTKRP_IJ" => MTTKRP.MLIR("fixed_ij", sparse)
        case "MTTKRP_I" => MTTKRP.MLIR("fixed_i", sparse)
        case "MTTKRP_J" => MTTKRP.MLIR("fixed_j", sparse)
        // case "E2E_LR" => E2E_PRK.MLIR(1)
        // case "E2E_PR2" => E2E_PRK.MLIR(2)
        // case "ODC" => ODC.MLIR(sparse)
        // case "ODCC" => ODCC.MLIR(sparse)
        // case "PGLM" => PGLM.MLIR(sparse)
        case _ => println(help)
      }
    } else println(help)
  } else println(help)
  

  // println(Variable("a").equals(Variable("a")))

  // val a: Map[String, Seq[Int]] = Map("a" -> Seq(2))
  // println(a.getOrElse("b", 12))
  // val b: Map[String, Seq[Int]] = Map("a" -> Seq(3))
  // println(mergeMap(Seq(a, b))((v1, v2) => v1 ++ v2))

}