package uk.ac.ed.dal
package structtensor
package parser

import utils._
import compiler._

object Interpreter {
  import Shared._

  def interpretAccess(n: String, v: Seq[Variable]): Access = {
    if (n.length < 3 && !n.contains(":")) Access(n, v, Tensor)
    else n.substring(n.length-2, n.length) match {
      case ":U" => Access(n.substring(0, n.length-2), v, UniqueSet)
      case ":D" => Access(n.substring(0, n.length-2), v, DimensionType)
      case ":R" => Access(n.substring(0, n.length-2), v, RedundancyMap)
      case _ => if (!n.contains(":")) Access(n, v, Tensor) else throw new Exception("Invalid access name")
    }
  }

  def reverseOp(op: String): String = op match {
    case "<=" => ">="
    case ">=" => "<="
    case "==" => "=="
    case "=" => "="
    case "<" => ">"
    case ">" => "<"
    case "!=" => "!="
  }

  def interpretComparison(op: String, i1: Index, i2: Index): Seq[Comparison] = (i1, i2) match {
    case (v1: Variable, v2: Variable) => Seq(Comparison(op, v1, v2))
    case (v1: Variable, ii2: Index) => Seq(Comparison(reverseOp(op), i2, v1))
    case (ii1: Index, v2: Variable) => Seq(Comparison(op, i1, v2))
    case _ => {
      val v = getVar("v")
      val c1 = Comparison("=", i2, Variable(v))
      val c2 = Comparison(op, i1, Variable(v))
      Seq(c1, c2)
    }
  }
    
  def interpretArith(i: Index, sOpI: Seq[(String, Index)]): Index = sOpI match {
    case Nil => i
    case (op, i2) :: t => interpretArith(Arithmetic(op, i, i2), t)
  }

  def interpretSeqExp(e: Seq[Exp], se: Seq[Seq[Exp]]): Seq[Exp] = se match {
    case Nil => e
    case h :: t => interpretSeqExp(e ++ h, t)
  }

  def interpretProd(e: Seq[Exp], se: Seq[Seq[Exp]]): Prod = Prod(interpretSeqExp(e, se))
  
}