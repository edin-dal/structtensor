package uk.ac.ed.dal
package structtensor

import parser._
import fastparse._
import compiler._
import utils._
import codegen._

import java.io.File
import scopt.OParser

object Main {
  def main(args: Array[String]) = {
  import Optimizer._
  import Utils._

  def getInputs(
      tc: Rule,
      usMap: Map[Access, Rule],
      rmMap: Map[Access, Rule],
      ccMap: Map[Access, Rule]
  ): Seq[(Rule, Rule, Rule, Rule)] = {
    tc.body.prods.flatMap(prod =>
      prod.exps.collect(e => {
        e match {
          case access @ Access(n, v, _) if usMap.containsByName(n) => {
            val usRule =
              usMap.getByAccessNameAndReplaceVars(access)
            val us = Rule(
              usRule.get.head.uniqueHead(),
              usRule.get.body
            )
            val rmRule =
              rmMap.getByAccessNameAndReplaceVars(access)
            val rm =
              Rule(
                rmRule.get.head.redundancyHead(),
                rmRule.get.body
              )
            val ccRule = ccMap.getByAccessNameAndReplaceVarsOrElse(
              access,
              Rule(
                usMap.getByAccessNameAndReplaceVars(access).get.head,
                SoPTimesSoP(
                  SoP(Seq(Prod(Seq(e)))),
                  us.body
                )
              )
            )
            val cc = Rule(
              ccRule.head.compressedHead(),
              ccRule.body
            )
            val t = Rule(access, SoP(Seq(Prod(Seq(e)))))
            (us, rm, cc, t)
          }
        }
      })
    )
  }

  case class Config(
      codeLang: String = "CPP",
      inFilePath: String = "",
      initTensors: Boolean = false,
      onlyComputation: Boolean = false,
      outFilePath: String = ""
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
        .text("select the target language for the generated code")
        .valueName("<lang>"),
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
      opt[Unit]("only-computation")
        .action((_, c) => c.copy(onlyComputation = true))
        .text("generate only the computation code (no reconstruction code)")
    )
  }

  // OParser.parse returns Option[Config]
  OParser.parse(parser1, args, Config()) match {
    case Some(config) => {
      if (config.inFilePath != "") {
        import Parser._
        import Convertor._
        import Utils._
        import Compiler._
        import Optimizer._
        import Codegen._
        val lines = scala.io.Source.fromFile(config.inFilePath).mkString
        val lineSeqInit = lines
          .split("\n")
          .toSeq
          .filter(_.nonEmpty)
          .filterNot(_.startsWith("#"))
        val (symbols_lines, symbols_index) =
          lineSeqInit.zipWithIndex.filter(_._1.startsWith("symbols:")).unzip
        val (outputs_lines, outputs_index) =
          lineSeqInit.zipWithIndex.filter(_._1.startsWith("outputs:")).unzip
        val (iters_lines, iters_index) =
          lineSeqInit.zipWithIndex.filter(_._1.startsWith("iters:")).unzip
        val symbols = symbols_lines
          .map(e => e.slice(8, e.length))
          .flatMap(_.split(",").map(_.trim).toSeq)
          .map(Variable(_))
        val outputs_names = outputs_lines
          .map(e => e.slice(8, e.length))
          .flatMap(_.split(",").map(_.trim).toSeq)
        val iters_map = iters_lines
          .map(e => e.slice(6, e.length))
          .flatMap(_.split(";").map(_.trim).toSeq)
          .map(iter_str =>
            fastparse.parse(iter_str, Parser.iterators(_)).get.value
          )
          .toMap
        val lineSeq = lineSeqInit.zipWithIndex
          .filterNot(x =>
            symbols_index.contains(x._2) ||
              outputs_index.contains(x._2) ||
              iters_index.contains(x._2)
          )
          .map(_._1)
        val preprocess_start_index = lineSeq.indexOf("@preprocess_start")
        val preprocess_end_index = lineSeq.indexOf("@preprocess_end")
        val preprocess_lines =
          lineSeq.slice(preprocess_start_index + 1, preprocess_end_index)
        val computation_lines = lineSeq.slice(
          0,
          preprocess_start_index
        ) ++ lineSeq.slice(preprocess_end_index + 1, lineSeq.length)

        val parsedPreprocess = preprocess_lines
          .map(line => {
            val Parsed.Success(res, _) = parse(line, parser(_))
            res.head
          })
          .toSeq
        val parsedComputation = computation_lines
          .map(line => {
            val Parsed.Success(res, _) = parse(line, parser(_))
            res.head
          })
          .toSeq
        val (
          all_tensors_preprocess,
          tensorComputations_preprocess,
          dimInfo_preprocess,
          uniqueSets_preprocess,
          redundancyMaps_preprocess
        ) = convertRules(parsedPreprocess)
        val (
          all_tensors_computation,
          tensorComputations_computation,
          dimInfo_computation,
          uniqueSets_computation,
          redundancyMaps_computation
        ) = convertRules(parsedComputation)
        val (init_str, end_str) = Bodygen(
          config.codeLang,
          (parsedPreprocess ++ parsedComputation).distinct,
          (all_tensors_preprocess ++ all_tensors_computation).distinct,
          (dimInfo_preprocess ++ dimInfo_computation).distinct.toAccessMap,
          uniqueSets_preprocess ++ uniqueSets_computation,
          config.initTensors,
          symbols,
          outputs_names
        )

        val (newUS, newRM, newCC, ccRuleSeq, rcRuleSeq) =
          tensorComputations_computation.foldLeft(
            (
              uniqueSets_computation,
              redundancyMaps_computation,
              Map[Access, Rule](),
              Seq[Rule](),
              Seq[Rule]()
            )
          )((acc, tc) => {
            val inps = getInputs(tc, acc._1, acc._2, acc._3)
            val iters = iters_map.getOrElse(tc.head.name, Seq())
            val (usRule, rmRule, ccRule) =
              compile(tc, inps, symbols, outputs_names, iters)
            val rcRule = Rule(
              ccRule.head,
              SoPTimesSoP(
                SoP(Seq(Prod(Seq(ccRule.head.vars2RedundancyVars())))),
                rmRule.body
              )
            )
            (
              acc._1 + (usRule.head -> usRule) + (usRule.head
                .inverseHead() -> usRule),
              acc._2 + (Access(
                rmRule.head.name,
                usRule.head.vars,
                rmRule.head.kind
              ) -> rmRule) + (Access(
                rmRule.head.name.inverseName,
                usRule.head.vars,
                rmRule.head.kind
              ) -> rmRule),
              acc._3 + (ccRule.head -> ccRule) + (ccRule.head
                .inverseHead() -> ccRule.inverse()),
              acc._4 :+ ccRule,
              acc._5 :+ rcRule
            )
          })

        val (
          newUS_preprocess,
          newRM_preprocess,
          newCC_preprocess,
          ccRuleSeq_preprocess
        ) = tensorComputations_preprocess.foldLeft(
          (
            uniqueSets_preprocess,
            redundancyMaps_preprocess,
            Map[Access, Rule](),
            Seq[Rule]()
          )
        )((acc, tc) => {
          val inps = getInputs(tc, acc._1, acc._2, acc._3)
          val iters = iters_map.getOrElse(tc.head.name, Seq())
          val (usRule, rmRule, ccRule) =
            compile(tc, inps, symbols, iters = iters)
          (
            acc._1 + (usRule.head -> usRule),
            acc._2 + (rmRule.head -> rmRule),
            acc._3 + (ccRule.head -> ccRule),
            acc._4 :+ ccRule
          )
        })

        val preprocessComputation = ccRuleSeq_preprocess
          .map(r => Codegen(r, symbols, config.codeLang, Tensor, iters_map))
          .mkString("\n")
        val ccComputation = outputs_names.isEmpty match {
          case true =>
            ccRuleSeq
              .map(r =>
                Codegen(
                  r,
                  symbols,
                  config.codeLang,
                  CompressedTensor,
                  iters_map
                )
              )
              .mkString("\n")
          case false =>
            ccRuleSeq
              .filter(r => outputs_names.contains(r.head.name))
              .map(r =>
                Codegen(
                  r,
                  symbols,
                  config.codeLang,
                  CompressedTensor,
                  iters_map
                )
              )
              .mkString("\n")
        }

        config.onlyComputation match {
          case true =>
            write2File(
              config.outFilePath,
              init_str + "\n" + preprocessComputation + "\n" + init_timer(
                config.codeLang,
                postfix = "_computation"
              ) + "\n" + ccComputation + "\n" + end_timer(
                config.codeLang,
                postfix = "_computation"
              ) + "\n" + end_str
            )
          case false => {
            val rcComputation = outputs_names.isEmpty match {
              case true =>
                rcRuleSeq
                  .map(r => Codegen(r, symbols, config.codeLang, RedundancyMap))
                  .mkString("\n")
              case false =>
                rcRuleSeq
                  .filter(r => outputs_names.contains(r.head.name))
                  .map(r => Codegen(r, symbols, config.codeLang, RedundancyMap))
                  .mkString("\n")
            }
            write2File(
              config.outFilePath,
              init_str + "\n" + preprocessComputation + "\n" + init_timer(
                config.codeLang,
                postfix = "_computation"
              ) + "\n" + ccComputation + "\n" + end_timer(
                config.codeLang,
                postfix = "_computation"
              ) + "\n" + init_timer(
                config.codeLang,
                postfix = "_reconstruction"
              ) + "\n" + rcComputation + "\n" + end_timer(
                config.codeLang,
                postfix = "_reconstruction"
              ) + "\n" + end_str
            )
          }
        }
      } else {
        println("Please specify the stur code or the file path")
      }
    }
    case _ => {
      println("Use --help to see the options")
    }
  }
}
}
