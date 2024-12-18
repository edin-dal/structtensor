package uk.ac.ed.dal
package structtensor
package parser

import compiler._
import utils._

import scala.collection.mutable.LinkedHashMap

object Convertor {
  import Compiler._
  import Optimizer.setIdempotentOpt, Optimizer.removeEmptyProductsOpt
  import Utils._

  def groupRules(rules: Seq[Rule]): (
      LinkedHashMap[Access, Rule],
      Map[Access, Rule],
      Map[Access, Rule],
      Map[Access, Rule]
  ) = {
    rules.foldLeft(
      (
        LinkedHashMap.empty[Access, Rule],
        Map.empty[Access, Rule],
        Map.empty[Access, Rule],
        Map.empty[Access, Rule]
      )
    )((acc, r) => {
      val head = Access(r.head.name.deinversifiedName, r.head.vars, Tensor)
      val head_inverse = head.inverseHead()
      r.head.kind match {
        case Tensor => (acc._1 ++ Map(head -> r), acc._2, acc._3, acc._4)
        case UniqueSet =>
          (
            acc._1,
            acc._2 ++ Map(
              head -> r,
              head_inverse -> Rule(r.head, r.body.inverse())
            ),
            acc._3,
            acc._4
          )
        case RedundancyMap =>
          (
            acc._1,
            acc._2,
            acc._3 ++ Map(
              head -> r,
              head_inverse -> Rule(r.head, r.body.inverse())
            ),
            acc._4
          )
        case DimensionType =>
          (
            acc._1,
            acc._2,
            acc._3,
            acc._4 ++ Map(
              head -> r,
              head_inverse -> Rule(r.head, r.body.inverse())
            )
          )
        case _ => throw new Exception("Unknown kind of tensor")
      }
    })
  }

  def getHeadsThatRequireDim(
      headToTensorMap: LinkedHashMap[Access, Rule]
  ): Seq[Access] = {
    val lhs = headToTensorMap.keySet.toSeq.filterNot(_.vars.isEmpty)
    val rhs = headToTensorMap.values
      .flatMap(_.body.prods.flatMap(_.exps))
      .flatMap {
        case Access(n, v, _) if v.nonEmpty => Seq(Access(n, v, Tensor))
        case _                             => Seq[Access]()
      }
      .toSeq
    (rhs.distinct ++ lhs.distinct).toSeq
  }

  def findUpperBound(v: Variable, sop: SoP): Dim = {
    val upperBounds: Seq[Dim] = sop.prods.flatMap(_.exps.flatMap {
      case Comparison(op, index, variable) => {
        index match {
          case ind: Dim if (variable == v) => {
            op match {
              case ">=" => Seq(Arithmetic("+", ind, ConstantInt(1)))
              case ">"  => Seq(ind)
              case _    => Seq[Dim]()
            }
          }
          case ind: Variable if (ind == v) => {
            op match {
              case "<=" => Seq(Arithmetic("+", variable, ConstantInt(1)))
              case "<"  => Seq(variable)
              case _    => Seq[Dim]()
            }
          }
          case arith @ Arithmetic(
                "-",
                arithVaria1: Variable,
                arithVaria2: Variable
              ) if (op == "=" && arithVaria1 == v) => {
            val d = findUpperBound(variable, sop)
            Seq(Arithmetic("+", d, arithVaria2))
          }
          case _ => Seq[Dim]()
        }
      }
      case _ => Seq[Dim]()
    })

    // might be better if we have a min function and pass that in case of multiple upper bounds
    // println(s"Upper Bounds for $v: $upperBounds")
    if (upperBounds.length > 0) upperBounds.head else ConstantInt(0)
  }

  def extractDims(
      headToTensorMap: LinkedHashMap[Access, Rule],
      headToDimensionMap: Map[Access, Rule]
  ): (Seq[DimInfo], Map[Access, DimInfo]) = {
    val headsRequiringDim = getHeadsThatRequireDim(headToTensorMap)
    val dimsAvailable = headsRequiringDim.forall(head =>
      headToDimensionMap.containsByName(head.name)
    )
    if (!dimsAvailable)
      throw new Exception("Dimensions not available for all tensors")

    val headAndHeadInverseRequiringDim =
      headsRequiringDim ++ headsRequiringDim.map(_.inverseHead())

    val (dimInfos, headToDimInfoMap) = headAndHeadInverseRequiringDim.collect {
      a =>
        headToDimensionMap.containsByName(a.name) match {
          case true => {
            val r = headToDimensionMap.getByAccessNameAndReplaceVars(a).get
            val oldHead = r.head
            val name =
              if (r.head.name.contains("_D"))
                r.head.name.substring(0, r.head.name.length - 2)
              else r.head.name
            val head = Access(name, r.head.vars, Tensor)
            val body = r.body

            val dimSeq = head.vars.map(v => findUpperBound(v, body))
            (DimInfo(head, dimSeq), oldHead -> DimInfo(r.head, dimSeq))
          }
        }
    }.unzip
    (dimInfos, headToDimInfoMap.toMap)
  }

  def extractSet(
      headToSetMap: Map[Access, Rule],
      dimInfoMap: Map[Access, DimInfo],
      lhs: Seq[Access],
      kind: AccessType
  ): Map[Access, Rule] = {
    dimInfoMap.collect {
      case (old_head, dimInfo)
          if (!lhs.containsByName(old_head.name) && !lhs.containsByName(
            old_head.name.inverseName
          )) =>
        val head = Access(dimInfo.access.name, dimInfo.access.vars, Tensor)
        val body = dimInfo.toSoP
        val newBody =
          if (kind == UniqueSet)
            headToSetMap.getByAccessNameAndReplaceVars(
              Access(old_head.name, old_head.vars, Tensor)
            ) match {
              case Some(r) => SoPTimesSoP(body, r.body)
              case None    => body
            }
          else {
            headToSetMap.getByAccessNameAndReplaceVars(
              Access(old_head.name, old_head.vars.redundancyVarsInplace, Tensor)
            ) match {
              case Some(r) => SoPTimesSoP(body, r.body)
              case None    => emptySoP()
            }
          }
        head -> Rule(head, newBody)
    }.toMap
  }

  def getAllTensors(rules: Seq[Rule]): Seq[Access] = rules.flatMap(r =>
    r.head +: r.body.prods.flatMap(_.exps.collect { case access: Access =>
      access
    })
  )

  def convertRules(rules: Seq[Rule]): (
      Seq[Access],
      Seq[Rule],
      Seq[DimInfo],
      Map[Access, Rule],
      Map[Access, Rule]
  ) = {
    val (
      headToTensorMap,
      headToUniqueSetMap,
      headToRedundancyMapMap,
      headToDimensionMap
    ) = groupRules(rules)
    val tensorComputations = headToTensorMap.values.toSeq

    val (dimInfo, dimInfoMap) = extractDims(headToTensorMap, headToDimensionMap)

    val lhs = headToTensorMap.keySet.toSeq.filterNot(_.vars.isEmpty)
    val uniqueSets = extractSet(headToUniqueSetMap, dimInfoMap, lhs, UniqueSet)
    val redundancyMaps =
      extractSet(headToRedundancyMapMap, dimInfoMap, lhs, RedundancyMap)

    val all_tensors: Seq[Access] = getAllTensors(tensorComputations).distinct
    (all_tensors, tensorComputations, dimInfo, uniqueSets, redundancyMaps)
  }
}
