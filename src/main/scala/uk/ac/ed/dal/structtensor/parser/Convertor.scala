package uk.ac.ed.dal
package structtensor
package parser

import compiler._
import apps._

import scala.collection.mutable.LinkedHashMap

object Convertor {
  import Compiler._
  import STURHelper._
  import Bodygen._

  def groupRules(rules: Seq[Rule]): (LinkedHashMap[Access, Rule], Map[Access, Rule], Map[Access, Rule], Map[Access, Rule]) = {
    rules.foldLeft((LinkedHashMap.empty[Access, Rule], Map.empty[Access, Rule], Map.empty[Access, Rule], Map.empty[Access, Rule]))((acc, r) => {
      val headToTensorMap = acc._1
      val headToUniqueSetMap = acc._2
      val headToRedundancyMapMap = acc._3
      val headToDimensionMap = acc._4
      val head = Access(r.head.name, r.head.vars, Tensor)
      r.head.kind match {
        case Tensor => (headToTensorMap ++ Map(head -> r), headToUniqueSetMap, headToRedundancyMapMap, headToDimensionMap)
        case UniqueSet => (headToTensorMap, headToUniqueSetMap ++ Map(head -> r), headToRedundancyMapMap, headToDimensionMap)
        case RedundancyMap => (headToTensorMap, headToUniqueSetMap, headToRedundancyMapMap ++ Map(head -> r), headToDimensionMap)
        case DimensionType => (headToTensorMap, headToUniqueSetMap, headToRedundancyMapMap, headToDimensionMap ++ Map(head -> r))
        case _ => throw new Exception("Unknown kind of tensor")
      }
    })
  }

  def getHeadsThatRequireDim(headToTensorMap: LinkedHashMap[Access, Rule]): Seq[Access] = {
    val lhs: Seq[Access] = headToTensorMap.keySet.toSeq
    val rhs: Seq[Access] = headToTensorMap.values.foldLeft(Seq.empty[Access])((acc, r) => {
      acc ++ r.body.prods.foldLeft(Seq.empty[Access])((acc2, p) => {
        acc2 ++ p.exps.foldLeft(Seq.empty[Access])((acc3, e) => {
          e match {
            case Access(n, v, _) => acc3 :+ Access(n, v, Tensor)
            case _ => acc3
          }
        })
      })
    })
    rhs.distinct.diff(lhs.distinct).toSeq
  }

  def checkDimsAvailable(headToTensorMap: LinkedHashMap[Access, Rule], headToDimensionMap: Map[Access, Rule]): Boolean = {
    getHeadsThatRequireDim(headToTensorMap).foldLeft(true)((acc, head) => {
      headToDimensionMap.get(head) match {
        case None => false
        case Some(d) => acc
      }
    })
  }

  def findUpperBound(v: Variable, sop: SoP): Dim = {
    val upperBounds: Seq[Dim] = sop.prods.foldLeft(Seq.empty[Dim])((acc, p) => {
      acc ++ p.exps.foldLeft(Seq.empty[Dim])((acc2, e) => {
        e match {
          case Comparison(op, index, variable) => {
            if (variable == v) {
              op match {
                case ">=" => acc2 :+ Arithmetic("-", index, ConstantInt(1))
                case ">" => acc2 :+ index.asInstanceOf[Dim]
                case _ => acc2
              }
            }
            else if (index.isInstanceOf[Variable] && index.asInstanceOf[Variable] == v) {
              op match {
                case "<=" => acc2 :+ Arithmetic("+", variable, ConstantInt(1))
                case "<" => acc2 :+ variable
                case _ => acc2
              }
            }
            else acc2
          }
          case _ => acc2
        }
      })
    })
    upperBounds(0)
  }

  def extractDims(headToDimensionMap: Map[Access, Rule]): (Seq[DimInfo], Map[Access, DimInfo]) = { // and a map to diminfo to mix it with unique set and redundancy map if necessary.
    headToDimensionMap.foldLeft((Seq.empty[DimInfo], Map.empty[Access, DimInfo]))((acc, headRule) => {
      val old_head = headRule._1
      val rule = headRule._2
      val head = Access(rule.head.name, rule.head.vars, Tensor)
      val body = rule.body
      val dimSeq = head.vars.foldLeft(Seq.empty[Dim])((acc2, v) => acc2 :+ findUpperBound(v, body))
      (acc._1 :+ DimInfo(head, dimSeq), acc._2 ++ Map(old_head -> DimInfo(rule.head, dimSeq)))
    })
  }

  def extractSet(headToSetMap: Map[Access, Rule], dimInfoMap: Map[Access, DimInfo], kind: AccessType): Map[Exp, Rule] = {
    dimInfoMap.foldLeft(Map.empty[Exp, Rule])((acc, headDimInfo) => {
      val old_head = headDimInfo._1
      val dimInfo = headDimInfo._2
      val head = Access(dimInfo.access.name, dimInfo.access.vars, Tensor)
      val body = dimInfo.toSoP
      val newBody = if (kind == UniqueSet) headToSetMap.get(old_head) match {
        case Some(r) => SoPTimesSoP(body, r.body)
        case None => body
      } else {
        headToSetMap.get(Access(old_head.name, old_head.vars.redundancyVarsInplace, Tensor)) match {
          case Some(r) => SoPTimesSoP(body, r.body)
          case None => emptySoP()
        }
      }
      acc ++ Map(head -> Rule(head, newBody))
    }) 
  }

  def getAllTensors(rules: Seq[Rule]): Seq[Access] = {
    rules.foldLeft(Seq.empty[Access])((acc, r) => {
      (acc :+ r.head) ++ r.body.prods.foldLeft(Seq.empty[Access])((acc2, p) => {
        acc2 ++ p.exps.foldLeft(Seq.empty[Access])((acc3, e) => {
          e match {
            case Access(_, _, _) => acc3 :+ e.asInstanceOf[Access]
            case _ => acc3
          }
        })
      })
    })
  }

  def convertRules(rules: Seq[Rule], initTensors: Boolean, enforceDimensions: Boolean, codeLang: String, sturOpt: Boolean): (String, Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule], String) = {
    val (headToTensorMap, headToUniqueSetMap, headToRedundancyMapMap, headToDimensionMap) = groupRules(rules)
    // headToTensorMap.foreach{case (k, v) => println(s"**************************\nTensor:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // headToUniqueSetMap.foreach{case (k, v) => println(s"**************************\nUnique Set:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // headToRedundancyMapMap.foreach{case (k, v) => println(s"**************************\nRedundancy Map:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    // headToDimensionMap.foreach{case (k, v) => println(s"**************************\nDimension:\n${k.prettyFormat} -> ${v.prettyFormat}\n")}
    val dimsAvailable = checkDimsAvailable(headToTensorMap, headToDimensionMap)
    if (!dimsAvailable) throw new Exception("Dimensions not available for all tensors")
    val (dimInfo, dimInfoMap): (Seq[DimInfo], Map[Access, DimInfo]) = extractDims(headToDimensionMap)
    val uniqueSets: Map[Exp, Rule] = if (!enforceDimensions) headToUniqueSetMap.values.map(r => (Access(r.head.name, r.head.vars, Tensor) -> Rule(Access(r.head.name, r.head.vars, UniqueSet), r.body))).toMap else extractSet(headToUniqueSetMap, dimInfoMap, UniqueSet)
    val redundancyMaps: Map[Exp, Rule] = if (!enforceDimensions) headToRedundancyMapMap.values.map(r => (Access(r.head.name, r.head.vars.slice(0, r.head.vars.length / 2), Tensor) -> Rule(Access(r.head.name, r.head.vars, RedundancyMap), r.body))).toMap else extractSet(headToRedundancyMapMap, dimInfoMap, RedundancyMap)
    val tensorComputations: Seq[Rule] = headToTensorMap.values.toSeq
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
    ///// val all_tensors: Seq[Access] = getAllTensors(tensorComputations).distinct
    val (init, end) = ("", "") ////// if (!initTensors) ("", "") else Bodygen(codeLang, rules, all_tensors, all_dimensions.toAccessMap, uniqueSets, sturOpt)
    return (init, tensorComputations, Seq[DimInfo](), uniqueSets, redundancyMaps, end)
  }
}