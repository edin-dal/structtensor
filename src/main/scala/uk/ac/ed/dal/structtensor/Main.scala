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

  def getInputs(tc: Rule, usMap: Map[Access, Rule], rmMap: Map[Access, Rule], ccMap: Map[Access, Rule]): Seq[(Rule, Rule, Rule, Rule)] = {
    tc.body.prods.flatMap(prod => prod.exps.map(e => {
      e match {
        case access: Access => {
          val us = Rule(usMap(access).head.uniqueHead, usMap(access).body)
          val rm = Rule(rmMap(access).head.redundancyHead, rmMap(access).body)
          val cc = if (ccMap.contains(access)) {
            Rule(ccMap(access).head.compressedHead, ccMap(access).body)
          } else Rule(usMap(access).head.compressedHead, SoPTimesSoP(SoP(Seq(Prod(Seq(e)))), usMap(access).body))
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
    codeLang: String = "CPP",
    inFilePath: String = "",
    sturOpt: Boolean = false,
    initTensors: Boolean = false,
    enforceDimensions: Boolean = false,
    outFilePath: String = "",
    compress: Boolean = false,
    sturOptArgs: Seq[String] = Seq(),
  )

  val builder = OParser.builder[Config]
  val parser1 = {
    import builder._
    OParser.sequence(
      programName("sturct-tensor"),
      head("struct-tensor", "0.1"),

      help("help").text("prints this usage text"),

      opt[String]('l', "lang")
        .action((x, c) => c.copy(codeLang = x))
        .text("select the target language for the generated code").
        valueName("<lang>"),
      opt[String]('i', "inf")
        .action((x, c) => c.copy(inFilePath = x))
        .text("path to the stur input file")
        .valueName("<path>"),
      opt[String]('o', "outf")
        .action((x, c) => c.copy(outFilePath = x))
        .text("where to stored the generated code")
        .valueName("<path>"),
      opt[Unit]("init-tensors")
        .action((_, c) => c.copy(initTensors = true))
        .text("initialize the tensors randomly in the generated code"),
      opt[Unit]("enforce-dims")
        .action((_, c) => c.copy(enforceDimensions = true))
        .text("enforce the dimensions of the tensors in the generated code by multiplying dimensions by unique set (if false, we assume unique set is in the dimension boundaries)"),
      opt[Unit]("stur-opt-code-gen")
        .action((_, c) => c.copy(sturOpt = true))
        .text("send the code through stur-opt path for code generation"),
      opt[Unit]("compress")
        .action((_, c) => c.copy(compress = true))
        .text("generate the compressed code"),
      opt[Seq[String]]("stur-opt-args")
        .action((x, c) => c.copy(sturOptArgs = x))
        .text("arguments to be passed to stur-opt")
        .valueName("<args>")
    )
  }

  // OParser.parse returns Option[Config]
  OParser.parse(parser1, args, Config()) match {
    case Some(config) => {
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
          res.head
        }).toSeq
        val parsedComputation = computation_lines.map(line => {
          val Parsed.Success(res, _) = parse(line, parser(_))
          res.head
        }).toSeq
        val (all_tensors_preprocess, tensorComputations_preprocess, dimInfo_preprocess, uniqueSets_preprocess, redundancyMaps_preprocess): (Seq[Access], Seq[Rule], Seq[DimInfo], Map[Access, Rule], Map[Access, Rule]) = convertRules(parsedPreprocess, config.enforceDimensions)
        val (all_tensors_computation, tensorComputations_computation, dimInfo_computation, uniqueSets_computation, redundancyMaps_computation): (Seq[Access], Seq[Rule], Seq[DimInfo], Map[Access, Rule], Map[Access, Rule]) = convertRules(parsedComputation, config.enforceDimensions)
        val (init_str, end_str): (String, String) = if (!config.initTensors) ("", "") else Bodygen(config.codeLang, (parsedPreprocess ++ parsedComputation).distinct, (all_tensors_preprocess ++ all_tensors_computation).distinct, (dimInfo_preprocess ++ dimInfo_computation).distinct.toAccessMap, uniqueSets_preprocess ++ uniqueSets_computation, config.sturOpt)

        val (newUS, newRM, newCC, newComputationCode, newReconstructionCode) = tensorComputations_computation.foldLeft((uniqueSets_computation, redundancyMaps_computation, Map[Access, Rule](), "", ""))((acc, tc) => {
          val inps: Seq[(Rule, Rule, Rule, Rule)] = getInputs(tc, acc._1, acc._2, acc._3)
          val (usRule, rmRule, ccRule) = compile(tc, inps)
          val rcRule = Rule(ccRule.head, SoPTimesSoP(SoP(Seq(Prod(Seq(ccRule.head.vars2RedundancyVars)))), rmRule.body))
          (acc._1 + (usRule.head -> usRule), acc._2 + (rmRule.head -> rmRule), acc._3 + (ccRule.head -> ccRule), s"${acc._4}\n${Codegen(ccRule, symbols)}", s"${acc._5}\n${Codegen(rcRule, symbols)}")
        })

        val (newUS_preprocess, newRM_preprocess, newCC_preprocess, newPreprocessCode) = tensorComputations_preprocess.foldLeft((uniqueSets_preprocess, redundancyMaps_preprocess, Map[Access, Rule](), ""))((acc, tc) => {
          val inps: Seq[(Rule, Rule, Rule, Rule)] = getInputs(tc, acc._1, acc._2, acc._3)
          val (usRule, rmRule, ccRule) = compile(tc, inps)
          (acc._1 + (usRule.head -> usRule), acc._2 + (rmRule.head -> rmRule), acc._3 + (ccRule.head -> ccRule), s"${acc._4}\n${Codegen(ccRule, symbols)}")
        })

        write2File(config.outFilePath, init_str + "\n" + newPreprocessCode + "\n" + init_timer(config.codeLang, postfix="_computation") + "\n" + newComputationCode + "\n" + end_timer(config.codeLang, postfix="_computation") + "\n" + init_timer(config.codeLang, postfix="_reconstruction") + "\n" + newReconstructionCode + "\n" + end_timer(config.codeLang, postfix="_reconstruction") + "\n" + "\n" + end_str)
      } else {
        println("Please specify the stur code or the file path")
      }
    }
  }
}