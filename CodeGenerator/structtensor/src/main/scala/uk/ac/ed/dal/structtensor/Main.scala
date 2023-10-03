package uk.ac.ed.dal
package structtensor

import apps._
import parser.Parser
import fastparse._

import java.io.File
import scopt.OParser

object Main extends App {
  case class Config(
    sparse: Boolean = false,
    codeLang: String = "CPP",
    codeMotion: Boolean = true,
    filePath: String = "",
    sturOpt: Boolean = false,
    applicationName: String = "",
    tool: String = "",
    applicationHelp: String = s"""
Please specify the experiment name:
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
  )

  val builder = OParser.builder[Config]
  val parser1 = {
    import builder._
    OParser.sequence(
      programName("sturct-tensor"),
      head("struct-tensor", "0.1"),

      opt[Unit]('s', "sparse")
        .action((_, c) => c.copy(sparse = true))
        .text("use sparse data layout for the input"),

      opt[String]('l', "lang")
        .action((x, c) => c.copy(codeLang = x))
        .text("select the target language for the generated code").
        valueName("<lang>"),

      opt[Unit]("no-cm")
        .action((_, c) => c.copy(codeMotion = false))
        .text("disable code motion"), 
      
      opt[String]('f', "file")
        .action((x, c) => c.copy(filePath = x))
        .text("path to the input file")
        .valueName("<path>"),  

      opt[Unit]("stur-opt-code-gen")
        .action((_, c) => c.copy(sturOpt = true))
        .text("send the code through stur-opt path for code generation"),

      help("help").text("prints this usage text"),

      cmd("app")
        .action((_, c) => c.copy(tool = "app"))
        .text("run an existing application")
        .children(
          opt[String]("app-name")
            .action((x, c) => c.copy(applicationName = x))
            .text("name of the selected application to run")
            .valueName("<name>")
        ),

      cmd("coalesce")
        .action((_, c) => c.copy(tool = "coalesce"))
        .text("run the coalescing pass on the input file"),

      cmd("stur")
        .action((_, c) => c.copy(tool = "input"))
        .text("generate code for input file (written in stur)"),
    )
  }

  // OParser.parse returns Option[Config]
  OParser.parse(parser1, args, Config()) match {
    case Some(config) => {
      config.tool match {
        case "app" => {
          config.applicationName match {
            case "LRC" => LRC(config.codeMotion, config.codeLang, config.sparse)
            case "PR2C" => PR2C(config.codeMotion, config.codeLang, config.sparse)
            case "PR3C" => PR3C(config.codeMotion, config.codeLang, config.sparse)
            case "LRA" => LRA(config.codeMotion, config.codeLang, config.sparse)
            case "PR2A" => PR2A(config.codeMotion, config.codeLang, config.sparse)
            case "PR3A" => PR3A(config.codeMotion, config.codeLang, config.sparse)
            case "TTM_DP" => TTM("diag_p", config.codeMotion, config.codeLang, config.sparse)
            case "TTM_J" => TTM("fixed_j", config.codeMotion, config.codeLang, config.sparse)
            case "TTM_UT" => TTM("uhc", config.codeMotion, config.codeLang, config.sparse)
            case "THP_DP" => THP("diag_p", config.codeMotion, config.codeLang, config.sparse)
            case "THP_I" => THP("fixed_i", config.codeMotion, config.codeLang, config.sparse)
            case "THP_J" => THP("fixed_j", config.codeMotion, config.codeLang, config.sparse)
            case "MTTKRP_IJ" => MTTKRP("fixed_ij", config.codeMotion, config.codeLang, config.sparse)
            case "MTTKRP_I" => MTTKRP("fixed_i", config.codeMotion, config.codeLang, config.sparse)
            case "MTTKRP_J" => MTTKRP("fixed_j", config.codeMotion, config.codeLang, config.sparse)
            case "E2E_LR" => E2E_PRK(1, config.codeMotion, config.codeLang, config.sparse)
            case "E2E_PR2" => E2E_PRK(2, config.codeMotion, config.codeLang, config.sparse)
            case "ODC" => ODC(config.codeMotion, config.codeLang, config.sparse)
            case "ODCC" => ODCC(config.codeMotion, config.codeLang, config.sparse)
            case "PGLM" => PGLM(config.codeMotion, config.codeLang, config.sparse)
            case "SpMV_UT" => SpMV("ut", config.codeMotion, config.codeLang, config.sparse)
            case "SpMV_D" => SpMV("diag", config.codeMotion, config.codeLang, config.sparse)
            case _ => println(config.applicationHelp)
          }
        }
        case "coalesce" => {

        }
        case "input" => {

        }
      }
    }
    case _ => println("Error parsing arguments")
  }
  
  import Parser._
  val p = "A(i, j, k) := C(k, l) * B(i, j, l) * (0 <= l * 2 + 5 % 2) * (Q > l) * (0 <= i) * (M > i) * (N > i) * (0 <= k) * (P > k) * (i = j)"
  val Parsed.Success(res, _) = parse(p, parser(_))
  println(res(0).prettyFormat)
  println(p)
  println(res)
}