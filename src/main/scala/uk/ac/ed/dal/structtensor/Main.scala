package uk.ac.ed.dal
package structtensor

import apps._
import parser._
import fastparse._
import compiler._

import java.io.File
import scopt.OParser

object Main extends App {
  case class Config(
    sparse: Boolean = false,
    codeLang: String = "CPP",
    codeMotion: Boolean = true,
    inFilePath: String = "",
    sturOpt: Boolean = false,
    applicationName: String = "",
    tool: String = "",
    initTensors: Boolean = false,
    enforceDimensions: Boolean = false,
    outFilePath: String = "",
    compress: Boolean = false,
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

      opt[Unit]("stur-opt-code-gen")
        .action((_, c) => c.copy(sturOpt = true))
        .text("send the code through stur-opt path for code generation"),

      help("help").text("prints this usage text"),

      cmd("app")
        .action((_, c) => c.copy(tool = "app"))
        .text("run an existing application")
        .children(
          opt[String]("name")
            .action((x, c) => c.copy(applicationName = x))
            .text("name of the selected application to run")
            .valueName("<name>")
        ),

      cmd("coalesce")
        .action((_, c) => c.copy(tool = "coalesce"))
        .text("run the coalescing pass on the input file"),

      cmd("stur")
        .action((_, c) => c.copy(tool = "input"))
        .text("generate code for input file (written in stur)")
        .children(
          opt[String]("inf")
            .action((x, c) => c.copy(inFilePath = x))
            .text("path to the stur input file")
            .valueName("<path>"),
          opt[String]("outf")
            .action((x, c) => c.copy(outFilePath = x))
            .text("where to stored the generated code")
            .valueName("<path>"),
          opt[Unit]("init-tensors")
            .action((_, c) => c.copy(initTensors = true))
            .text("initialize the tensors randomly in the generated code"),
          opt[Unit]("enforce-dims")
            .action((_, c) => c.copy(enforceDimensions = true))
            .text("enforce the dimensions of the tensors in the generated code by multiplying dimensions by unique set (if false, we assume unique set is in the dimension boundaries)"),
          opt[Unit]("compress")
            .action((_, c) => c.copy(compress = true))
            .text("generate the compressed code")
        )
    )
  }

  // OParser.parse returns Option[Config]
  OParser.parse(parser1, args, Config()) match {
    case Some(config) => {
      config.tool match {
        case "app" => {
          config.applicationName match {
            case "LRC" => LRC(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "PR2C" => PR2C(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "PR3C" => PR3C(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "LRA" => LRA(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "PR2A" => PR2A(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "PR3A" => PR3A(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "TTM_DP" => TTM(structure="diag_p", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "TTM_J" => TTM(structure="fixed_j", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "TTM_UT" => TTM(structure="uhc", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "THP_DP" => THP(structure="diag_p", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "THP_I" => THP(structure="fixed_i", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "THP_J" => THP(structure="fixed_j", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "MTTKRP_IJ" => MTTKRP(structure="fixed_ij", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "MTTKRP_I" => MTTKRP(structure="fixed_i", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "MTTKRP_J" => MTTKRP(structure="fixed_j", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "E2E_LR" => E2E_PRK(1, codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "E2E_PR2" => E2E_PRK(2, codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "ODC" => ODC(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "ODCC" => ODCC(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "PGLM" => PGLM(codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "SpMV_UT" => SpMV(structure="ut", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case "SpMV_D" => SpMV(structure="diag", codeMotion=config.codeMotion, codeLang=config.codeLang, sparse=config.sparse, sturOpt=config.sturOpt)
            case _ => println(config.applicationHelp)
          }
        }
        case "coalesce" => {

        }
        case "input" => {
          if (config.inFilePath != "") {
            import Parser._
            import Convertor._
            import Compiler.codeGen
            import Shared._
            val lines = scala.io.Source.fromFile(config.inFilePath).mkString
            val lineSeq: Seq[String] = lines.split("\n").toSeq
            val parsedRules: Seq[Rule] = lineSeq.map(line => {
              val Parsed.Success(res, _) = parse(line, parser(_))
              res(0)
            }).toSeq
            // parsedRules.map(r => println(r.prettyFormat))
            val (init_str, tensorComputations, dimInfo, uniqueSets, redundancyMaps, end_str): (String, Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], String) = convertRules(parsedRules, config.initTensors, config.enforceDimensions, config.codeLang, config.sturOpt)
            // println(init_str)
            val code_strs = tensorComputations.zipWithIndex.map{case(tc, i) => {
              if (tensorComputations.length == 1) codeGen(tc, dimInfo, uniqueSets, redundancyMaps, codeGenMode=1, codeMotion=config.codeMotion, codeLang=config.codeLang, sturOpt=config.sturOpt, compress=config.compress, append_stur_opt_file=false, run_stur_opt=true)
              else if (i == 0) codeGen(tc, dimInfo, uniqueSets, redundancyMaps, codeGenMode=1, codeMotion=config.codeMotion, codeLang=config.codeLang, sturOpt=config.sturOpt, compress=config.compress, append_stur_opt_file=false, run_stur_opt=false)
              else if (i == tensorComputations.length - 1) codeGen(tc, dimInfo, uniqueSets, redundancyMaps, codeGenMode=1, codeMotion=config.codeMotion, codeLang=config.codeLang, sturOpt=config.sturOpt, compress=config.compress, append_stur_opt_file=true, run_stur_opt=true)
              else codeGen(tc, dimInfo, uniqueSets, redundancyMaps, codeGenMode=1, codeMotion=config.codeMotion, codeLang=config.codeLang, sturOpt=config.sturOpt, compress=config.compress, append_stur_opt_file=true, run_stur_opt=false)
            }}
            // println(end_str)
            write2File(config.outFilePath, init_str + "\n" + code_strs.mkString("\n") + "\n" + end_str)
          } else {
            println("Please specify the stur code or the file path")
          }
        }
      }
    }
    case _ => println("Error parsing arguments")
  }
  
  // import Parser._
  // val p = "A(i, j, k) := C(k, l) * B(i, j, l) * (0 <= l * 2 + 5 % 2) * (Q > l) * (0 <= i) * (M > i) * (N > i) * (0 <= k) * (P > k) * (i = j)"
  // val Parsed.Success(res, _) = parse(p, parser(_))
  // println(res(0).prettyFormat)
  // println(p)
  // println(res)
}