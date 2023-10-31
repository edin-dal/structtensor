package uk.ac.ed.dal
package structtensor
package parser

import compiler._
import apps._

object Convertor {
  import Compiler._
  import STURHelper._
  import Bodygen._

  def groupRules(rules: Seq[Rule]): (Map[String, Rule], Map[String, Rule], Map[String, Rule], Map[String, Rule]) = {
    rules.foldLeft((Map.empty[String, Rule], Map.empty[String, Rule], Map.empty[String, Rule], Map.empty[String, Rule]))((acc, r) => {
      val nameToTensorMap = acc._1
      val nameToUniqueSetMap = acc._2
      val nameToRedundancyMapMap = acc._3
      val nameToDimensionMap = acc._4
      val name = r.head.name
      r.head.kind match {
        case Tensor => (nameToTensorMap ++ Map(name -> r), nameToUniqueSetMap, nameToRedundancyMapMap, nameToDimensionMap)
        case UniqueSet => (nameToTensorMap, nameToUniqueSetMap ++ Map(name -> r), nameToRedundancyMapMap, nameToDimensionMap)
        case RedundancyMap => (nameToTensorMap, nameToUniqueSetMap, nameToRedundancyMapMap ++ Map(name -> r), nameToDimensionMap)
        case DimensionType => (nameToTensorMap, nameToUniqueSetMap, nameToRedundancyMapMap, nameToDimensionMap ++ Map(name -> r))
        case _ => throw new Exception("Unknown kind of tensor")
      }
    })
  }

  def getNamesThatRequireDim(nameToTensorMap: Map[String, Rule]): Seq[String] = {
    val lhs: Seq[String] = nameToTensorMap.keySet.toSeq
    val rhs: Seq[String] = nameToTensorMap.values.foldLeft(Seq.empty[String])((acc, r) => {
      acc ++ r.body.prods.foldLeft(Seq.empty[String])((acc2, p) => {
        acc2 ++ p.exps.foldLeft(Seq.empty[String])((acc3, e) => {
          e match {
            case Access(n, _, _) => acc3 :+ n
            case _ => acc3
          }
        })
      })
    })
    rhs.diff(lhs).distinct.toSeq
  }

  def checkDimsAvailable(nameToTensorMap: Map[String, Rule], nameToDimensionMap: Map[String, Rule]): Boolean = {
    getNamesThatRequireDim(nameToTensorMap).foldLeft(true)((acc, name) => {
      nameToDimensionMap.get(name) match {
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

  def extractDims(nameToDimensionMap: Map[String, Rule]): (Seq[DimInfo], Map[String, DimInfo]) = { // and a map to diminfo to mix it with unique set and redundancy map if necessary.
    nameToDimensionMap.foldLeft((Seq.empty[DimInfo], Map.empty[String, DimInfo]))((acc, nameRule) => {
      val name = nameRule._1
      val rule = nameRule._2
      val head = Access(rule.head.name, rule.head.vars, Tensor)
      val body = rule.body
      val dimSeq = head.vars.foldLeft(Seq.empty[Dim])((acc2, v) => acc2 :+ findUpperBound(v, body))
      (acc._1 :+ DimInfo(head, dimSeq), acc._2 ++ Map(name -> DimInfo(rule.head, dimSeq)))
    })
  }

  def extractSet(nameToSetMap: Map[String, Rule], dimInfoMap: Map[String, DimInfo], kind: AccessType): Map[Exp, Rule] = {
    dimInfoMap.foldLeft(Map.empty[Exp, Rule])((acc, nameDimInfo) => {
      val name = nameDimInfo._1
      val dimInfo = nameDimInfo._2
      val head = Access(dimInfo.access.name, dimInfo.access.vars, Tensor)
      val body = dimInfo.toSoP
      val newBody = if (kind == UniqueSet) nameToSetMap.get(name) match {
        case Some(r) => SoPTimesSoP(body, r.body)
        case None => body
      } else {
        nameToSetMap.get(name) match {
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
    val (nameToTensorMap, nameToUniqueSetMap, nameToRedundancyMapMap, nameToDimensionMap) = groupRules(rules)
    val dimsAvailable = checkDimsAvailable(nameToTensorMap, nameToDimensionMap)
    if (!dimsAvailable) throw new Exception("Dimensions not available for all tensors")
    val (dimInfo, dimInfoMap): (Seq[DimInfo], Map[String, DimInfo]) = extractDims(nameToDimensionMap)
    val uniqueSets: Map[Exp, Rule] = if (!enforceDimensions) nameToUniqueSetMap.values.map(r => (r.head -> Rule(Access(r.head.name, r.head.vars, Tensor), r.body))).toMap else extractSet(nameToUniqueSetMap, dimInfoMap, UniqueSet)
    val redundancyMaps: Map[Exp, Rule] = if (!enforceDimensions) nameToRedundancyMapMap.values.map(r => (r.head -> Rule(Access(r.head.name, r.head.vars, Tensor), r.body))).toMap else extractSet(nameToRedundancyMapMap, dimInfoMap, RedundancyMap)
    val tensorComputations: Seq[Rule] = nameToTensorMap.values.toSeq
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
    val all_dimensions: Seq[DimInfo] = dimInfo ++ tensorComputations.map(r => infer(r, dimInfo, uniqueSets, redundancyMaps)._4)
    val all_tensors: Seq[Access] = getAllTensors(tensorComputations).distinct
    val (init, end) = if (!initTensors) ("", "") else Bodygen(codeLang, rules, all_tensors, all_dimensions.toAccessMap, uniqueSets, sturOpt)
    return (init, tensorComputations, dimInfo, uniqueSets, redundancyMaps, end)
  }
}