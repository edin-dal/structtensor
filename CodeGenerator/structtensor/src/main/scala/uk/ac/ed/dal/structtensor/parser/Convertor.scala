package uk.ac.ed.dal
package structtensor
package parser

import compiler._

object Convertor {

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

  def checkDimsAvailable(nameToTensorMap: Map[String, Rule], nameToDimensionMap: Map[String, Rule]): Boolean = {
    nameToTensorMap.keySet.foldLeft(true)((acc, name) => {
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
                case ">" => acc2 :+ Arithmetic("+", index, ConstantInt(0))
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

  def extractDims(nameToDimensionMap: Map[String, Rule]): Seq[DimInfo] = { // and a map to diminfo to mix it with unique set and redundancy map if necessary.
    nameToDimensionMap.foldLeft(Seq.empty[DimInfo])((acc, nameRule) => {
      val name = nameRule._1
      val rule = nameRule._2
      val head = rule.head
      val body = rule.body
      val dimSeq = head.vars.foldLeft(Seq.empty[Dim])((acc2, v) => acc2 :+ findUpperBound(v, body))
      acc :+ DimInfo(head, dimSeq)
    })
  }

  def convertRules(rules: Seq[Rule], initTensors: Boolean, enforceDimensions: Boolean): (Seq[Rule], Seq[DimInfo], Map[Exp, Rule], Map[Exp, Rule]) = {
    val (nameToTensorMap, nameToUniqueSetMap, nameToRedundancyMapMap, nameToDimensionMap) = groupRules(rules)
    val dimsAvailable = checkDimsAvailable(nameToTensorMap, nameToDimensionMap)
    if (!dimsAvailable) throw new Exception("Dimensions not available for all tensors")
    val dimInfo: Seq[DimInfo] = extractDims(nameToDimensionMap)

  }
}