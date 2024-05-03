package uk.ac.ed.dal
package structtensor
package parser

import compiler._
import apps._

import scala.collection.mutable.LinkedHashMap

object Convertor {
  import Compiler._
  import Sompiler._
  import Optimizer.denormalizeDim, Optimizer.setIdempotentOpt, Optimizer.removeEmptyProductsOpt
  import STURHelper._
  import Bodygen._

  def groupRules(rules: Seq[Rule]): (LinkedHashMap[Access, Rule], Map[Access, Rule], Map[Access, Rule], Map[Access, Rule]) = {
    rules.foldLeft((LinkedHashMap.empty[Access, Rule], Map.empty[Access, Rule], Map.empty[Access, Rule], Map.empty[Access, Rule]))((acc, r) => {
      val head = Access(r.head.name, r.head.vars, Tensor)
      r.head.kind match {
        case Tensor => (acc._1 ++ Map(head -> r), acc._2, acc._3, acc._4)
        case UniqueSet => (acc._1, acc._2 ++ Map(head -> r), acc._3, acc._4)
        case RedundancyMap => (acc._1, acc._2, acc._3 ++ Map(head -> r), acc._4)
        case DimensionType => (acc._1, acc._2, acc._3, acc._4 ++ Map(head -> r))
        case _ => throw new Exception("Unknown kind of tensor")
      }
    })
  }

  def getHeadsThatRequireDim(headToTensorMap: LinkedHashMap[Access, Rule]): Seq[Access] = {
    val lhs = headToTensorMap.keySet.toSeq
    val rhs = headToTensorMap.values.flatMap(_.body.prods.flatMap(_.exps)).flatMap {
      case Access(n, v, _) => Seq(Access(n, v, Tensor))
      case _ => Seq[Access]()
    }.toSeq
    rhs.distinct.diff(lhs.distinct).toSeq
  }

  def checkDimsAvailable(headToTensorMap: LinkedHashMap[Access, Rule], headToDimensionMap: Map[Access, Rule]): Boolean = getHeadsThatRequireDim(headToTensorMap).forall(head => headToDimensionMap.contains(head))

  def findUpperBound(v: Variable, sop: SoP): Dim = {
    val upperBounds: Seq[Dim] = sop.prods.flatMap(_.exps.flatMap {
      case Comparison(op, index, variable) => {
        index match {
          case ind: Dim if (variable == v) => {
            op match {
              case ">=" => Seq(Arithmetic("-", ind, ConstantInt(1)))
              case ">" => Seq(ind)
              case _ => Seq[Dim]()
            }
          }
          case ind: Variable if (ind == v) => {
            op match {
              case "<=" => Seq(Arithmetic("+", variable, ConstantInt(1)))
              case "<" => Seq(variable)
              case _ => Seq[Dim]()
            }
          }
          case arith @ Arithmetic("-", arithVaria1: Variable, arithVaria2: Variable) if (op == "=" && arithVaria1 == v) => {
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
    if (upperBounds.length > 0) upperBounds(0) else ConstantInt(0)
  }

  def extractDims(dimSeqAsRuleSeq: Seq[Rule]): (Seq[DimInfo], Map[Access, DimInfo]) = {
    dimSeqAsRuleSeq.foldLeft((Seq[DimInfo](), Map[Access, DimInfo]()))((acc, r) => {
      val old_head = r.head
      val name = if (r.head.name.contains("_D")) r.head.name.substring(0, r.head.name.length - 2) else r.head.name
      val head = Access(name, r.head.vars, Tensor)
      val body = r.body

      val dimSeq = head.vars.map(v => findUpperBound(v, body))
      (acc._1 :+ DimInfo(head, dimSeq), acc._2 ++ Map(old_head -> DimInfo(r.head, dimSeq)))
    })
  }

  def extractSet(headToSetMap: Map[Access, Rule], dimInfoMap: Map[Access, DimInfo], kind: AccessType): Map[Exp, Rule] = {
    dimInfoMap.map { case (old_head, dimInfo) =>
      val head = Access(dimInfo.access.name, dimInfo.access.vars, Tensor)
      val body = dimInfo.toSoP
      val newBody = if (kind == UniqueSet) headToSetMap.get(Access(old_head.name, old_head.vars, Tensor)) match {
        case Some(r) => SoPTimesSoP(body, r.body)
        case None => body
      } else {
        headToSetMap.get(Access(old_head.name, old_head.vars.redundancyVarsInplace, Tensor)) match {
          case Some(r) => SoPTimesSoP(body, r.body)
          case None => emptySoP()
        }
      }
      head -> Rule(head, newBody)
    }.toMap
  }

  def getAllTensors(rules: Seq[Rule]): Seq[Access] = rules.flatMap(r => r.head +: r.body.prods.flatMap(_.exps.collect { case access: Access => access }))


  // def getAllOptDims(tensorComputations: Seq[Rule], headToDimensionMap: Map[Access, Rule]): Seq[Rule] = {
  //   val norms = tensorComputations.map(normalize)
  //   val dimsSeq = norms.map(norm => norm.map(dimensionInfer))
  //   val denormDimsSeq = dimsSeq.foldLeft(Seq[Rule]())((acc, dimSeq) => {
  //     acc :+ denormalizeDim(dimSeq.last.head, headToDimensionMap.values.toSeq.map(r => Rule(r.head.dimensionHead, r.body)) ++ acc ++ dimSeq)
  //   })
  //   val idempotentDimsSeq = denormDimsSeq.map(setIdempotentOpt)
  //   val removeEmptyProductsDimsSeq = idempotentDimsSeq.map(removeEmptyProductsOpt)
  //   removeEmptyProductsDimsSeq
  // }

  def convertRules(rules: Seq[Rule], enforceDimensions: Boolean): (Seq[Access], Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule]) = {
    val (headToTensorMap, headToUniqueSetMap, headToRedundancyMapMap, headToDimensionMap) = groupRules(rules)
    // headToTensorMap.foreach{case (k, v) => println(s"**************************\nTensor:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // headToUniqueSetMap.foreach{case (k, v) => println(s"**************************\nUnique Set:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // headToRedundancyMapMap.foreach{case (k, v) => println(s"**************************\nRedundancy Map:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // headToDimensionMap.foreach{case (k, v) => println(s"**************************\nDimension:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    val tensorComputations = headToTensorMap.values.toSeq
    // TODO: Extract the dimensions needed from the rules (pay attention to shift, min and maxes and stuff)

    val dimsAvailable = checkDimsAvailable(headToTensorMap, headToDimensionMap)
    if (!dimsAvailable) throw new Exception("Dimensions not available for all tensors")
    
    // val optDimsSeq = getAllOptDims(tensorComputations, headToDimensionMap)

    // val (dimInfo, dimInfoMap): (Seq[DimInfo], Map[Access, DimInfo]) = extractDims(headToDimensionMap.values.toSeq ++ optDimsSeq)
    val (dimInfo, dimInfoMap): (Seq[DimInfo], Map[Access, DimInfo]) = extractDims(headToDimensionMap.values.toSeq)
    val uniqueSets: Map[Exp, Rule] = if (!enforceDimensions) headToUniqueSetMap.values.map(r => (Access(r.head.name, r.head.vars, Tensor) -> Rule(Access(r.head.name, r.head.vars, UniqueSet), r.body))).toMap else extractSet(headToUniqueSetMap, dimInfoMap, UniqueSet)
    val redundancyMaps: Map[Exp, Rule] = if (!enforceDimensions) headToRedundancyMapMap.values.map(r => (Access(r.head.name, r.head.vars.slice(0, r.head.vars.length / 2), Tensor) -> Rule(Access(r.head.name, r.head.vars, RedundancyMap), r.body))).toMap else extractSet(headToRedundancyMapMap, dimInfoMap, RedundancyMap)
    // println("Enforce Dimensions:")
    // println(enforceDimensions)
    // println("Tensor Computations:")
    // tensorComputations.map(r => println(r.prettyFormat))
    // println("Unique Sets:")
    // uniqueSets.values.toSeq.map(r => println(r.prettyFormat))
    // println("Redundancy Maps:")
    // redundancyMaps.values.toSeq.map(r => println(r.prettyFormat))
    // println("Dimensions:")
    // println(dimInfo)
    ///// val all_dimensions: Seq[DimInfo] = tensorComputations.foldLeft(dimInfo)((acc, r) => acc :+ DimInfo(r.head, infer(r, acc, uniqueSets, redundancyMaps)._4.dims))
    // println("All Dimensions:")
    // println(all_dimensions)
    val all_tensors: Seq[Access] = getAllTensors(tensorComputations).distinct
    return (all_tensors, tensorComputations, dimInfo, uniqueSets, redundancyMaps)
  }
}