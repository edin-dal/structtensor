package uk.ac.ed.dal
package structtensor

import parser._
import fastparse._
import compiler._

import java.io.File
import scopt.OParser

object Main extends App {
  import Optimizer._
  import Shared._

  def getInps(tc: Rule, usMap: Map[Access, Rule], rmMap: Map[Access, Rule], ccMap: Map[Access, Rule]): Seq[(Rule, Rule, Rule, Rule)] = {
    tc.body.prods.flatMap(prod => prod.exps.map(e => {
      e match {
        case access: Access => {
          val us = Rule(usMap(access).head.uniqueHead, usMap(access).body)
          val rm = Rule(rmMap(access).head.redundancyHead, rmMap(access).body)
          val cc = if (ccMap.contains(access)) {
            Rule(ccMap(access).head.compressedHead, ccMap(access).body)
          } else Rule(usMap(access).head.compressedHead, SoPTimesSoP(SoP(Seq(Prod(Seq(e)))), usMap(access).body))
          // val cc = Rule(usMap(access).head.compressedHead, SoPTimesSoP(SoP(Seq(Prod(Seq(e)))), SoP(Seq(Prod(Seq(usMap(access).head.uniqueHead))))))
          val t = Rule(access, SoP(Seq(Prod(Seq(e)))))
          (us, rm, cc, t)
        }
        case _ => {
          val h = Access("", Seq(), Tensor)
          val us = Rule(h.uniqueHead, SoP(Seq(Prod(Seq(e)))))
          val rm = Rule(h.redundancyHead, SoP(Seq(Prod(Seq(e)))))
          val cc = Rule(h.compressedHead, SoP(Seq(Prod(Seq(e)))))
          val t = Rule(h, SoP(Seq(Prod(Seq(e)))))
          (us, rm, cc, t)
        }
      }
    }))
  }

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
    sturOptArgs: Seq[String] = Seq(),
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
            .text("generate the compressed code"),
          opt[Seq[String]]("stur-opt-args")
            .action((x, c) => c.copy(sturOptArgs = x))
            .text("arguments to be passed to stur-opt")
            .valueName("<args>")
        )
    )
  }

  // OParser.parse returns Option[Config]
  OParser.parse(parser1, args, Config()) match {
    case Some(config) => {
      config.tool match {
        case "input" => {
          if (config.inFilePath != "") {
            import Parser._
            import Convertor._
            import Shared._
            import Compiler._
            import Optimizer._
            import Codegen._
            val lines = scala.io.Source.fromFile(config.inFilePath).mkString
            val lineSeqInit = lines.split("\n").toSeq
            val (symbols_lines, index) = lineSeqInit.zipWithIndex.filter(_._1.startsWith("symbols:")).unzip
            val symbols = symbols_lines.map(e => e.slice(8, e.length)).flatMap(_.split(",").map(_.trim).toSeq).map(Variable(_))
            val lineSeq = lineSeqInit.zipWithIndex.filterNot(x => index.contains(x._2)).map(_._1)
            val preprocess_start_index = lineSeq.indexOf("@preprocess_start")
            val preprocess_end_index = lineSeq.indexOf("@preprocess_end")
            val preprocess_lines = lineSeq.slice(preprocess_start_index + 1, preprocess_end_index)
            val computation_lines =  lineSeq.slice(0, preprocess_start_index) ++ lineSeq.slice(preprocess_end_index + 1, lineSeq.length)
            
            val parsedPreprocess = preprocess_lines.map(line => {
              val Parsed.Success(res, _) = parse(line, parser(_))
              res(0)
            }).toSeq
            val parsedComputation = computation_lines.map(line => {
              val Parsed.Success(res, _) = parse(line, parser(_))
              res(0)
            }).toSeq
            val (all_tensors_preprocess, tensorComputations_preprocess, dimInfo_preprocess, uniqueSets_preprocess, redundancyMaps_preprocess): (Seq[Access], Seq[Rule], Seq[DimInfo], Map[Access, Rule], Map[Access, Rule]) = convertRules(parsedPreprocess, config.enforceDimensions)
            val (all_tensors_computation, tensorComputations_computation, dimInfo_computation, uniqueSets_computation, redundancyMaps_computation): (Seq[Access], Seq[Rule], Seq[DimInfo], Map[Access, Rule], Map[Access, Rule]) = convertRules(parsedComputation, config.enforceDimensions)
            val (init_str, end_str): (String, String) = if (!config.initTensors) ("", "") else Bodygen(config.codeLang, (parsedPreprocess ++ parsedComputation).distinct, (all_tensors_preprocess ++ all_tensors_computation).distinct, (dimInfo_preprocess ++ dimInfo_computation).distinct.toAccessMap, uniqueSets_preprocess ++ uniqueSets_computation, config.sturOpt)
            // println("**************************")
            // println("Preprocess Tensor Computations:")
            // tensorComputations_preprocess.map(r => println(r.prettyFormat))
            // println("Computation Tensor Computations:")
            // tensorComputations_computation.map(r => println(r.prettyFormat))
            // println("**************************")

            // println("US")
            // uniqueSets_computation.map{case (k, v) => println(s"${k.prettyFormat} -> ${v.prettyFormat}")}
            // println("RM")
            // redundancyMaps_computation.map{case (k, v) => println(s"${k.prettyFormat} -> ${v.prettyFormat}")}

            val (newUS, newRM, newCC, newComputationCode) = tensorComputations_computation.foldLeft((uniqueSets_computation, redundancyMaps_computation, Map[Access, Rule](), ""))((acc, tc) => {
              val inps: Seq[(Rule, Rule, Rule, Rule)] = getInps(tc, acc._1, acc._2, acc._3)
              val (usRule, rmRule, ccRule) = compile(tc, inps)
              // println(s"usRule: ${usRule.prettyFormat}")
              // println(s"rmRule: ${rmRule.prettyFormat}")
              // println(s"ccRule: ${ccRule.prettyFormat}")
              (acc._1 + (usRule.head -> usRule), acc._2 + (rmRule.head -> rmRule), acc._3 + (ccRule.head -> ccRule), s"${acc._4}\n${Codegen(ccRule, symbols)}")
            })

            val (newUS_preprocess, newRM_preprocess, newCC_preprocess, newPreprocessCode) = tensorComputations_preprocess.foldLeft((uniqueSets_preprocess, redundancyMaps_preprocess, Map[Access, Rule](), ""))((acc, tc) => {
              val inps: Seq[(Rule, Rule, Rule, Rule)] = getInps(tc, acc._1, acc._2, acc._3)
              val (usRule, rmRule, ccRule) = compile(tc, inps)
              (acc._1 + (usRule.head -> usRule), acc._2 + (rmRule.head -> rmRule), acc._3 + (ccRule.head -> ccRule), s"${acc._4}\n${Codegen(ccRule, symbols)}")
            })

            val timer_start_index = init_str.indexOf(init_timer(config.codeLang))
            write2File(config.outFilePath, init_str.slice(0, timer_start_index) + "\n" + newPreprocessCode + "\n" + init_str.slice(timer_start_index, init_str.length) + "\n" + newComputationCode + "\n" + end_str)
          } else {
            println("Please specify the stur code or the file path")
          }
        }
      }
    }
    case _ => println("Error parsing arguments")
  }
}