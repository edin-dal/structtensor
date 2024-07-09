package uk.ac.ed.dal
package structtensor
package parser

import fastparse._, SingleLineWhitespace._
import compiler._
import utils._
import Utils._

object Parser {
  def parseAccess(n: String, v: Seq[Variable]): Access = {
    if (n.length < 3 && !n.contains(":")) Access(n, v, Tensor)
    else
      n.substring(n.length - 2, n.length) match {
        case ":U" => Access(n.substring(0, n.length - 2), v, UniqueSet)
        case ":D" => Access(n.substring(0, n.length - 2), v, DimensionType)
        case ":R" => Access(n.substring(0, n.length - 2), v, RedundancyMap)
        case _ =>
          if (!n.contains(":")) Access(n, v, Tensor)
          else throw new Exception("Invalid access name")
      }
  }

  def reverseOp(op: String): String = op match {
    case "<=" => ">="
    case ">=" => "<="
    case "==" => "=="
    case "="  => "="
    case "<"  => ">"
    case ">"  => "<"
    case "!=" => "!="
  }

  def parseComparison(op: String, i1: Index, i2: Index): Seq[Comparison] =
    (i1, i2) match {
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

  def parseArith(i: Index, sOpI: Seq[(String, Index)]): Index = sOpI match {
    case Nil           => i
    case (op, i2) :: t => parseArith(Arithmetic(op, i, i2), t)
  }

  def parseSeqExp(e: Seq[Exp], se: Seq[Seq[Exp]]): Seq[Exp] = se match {
    case Nil    => e
    case h :: t => parseSeqExp(e ++ h, t)
  }

  def parseProd(e: Seq[Exp], se: Seq[Seq[Exp]]): Prod = Prod(parseSeqExp(e, se))

  def variable[$: P]: P[Variable] =
    P(CharIn("A-Za-z") ~ CharIn("A-Za-z0-9_").rep).!.map(Variable(_))

  def variableSeq[$: P]: P[Seq[Variable]] = P(variable.rep(sep = ","))

  def name[$: P]: P[String] = P(
    CharIn("A-Za-z") ~ CharIn("A-Za-z0-9._").rep ~ (":" ~ CharIn("DUR")).?
  ).!

  def access[$: P]: P[Access] = P(name.! ~ "(" ~ variableSeq ~ ")").map {
    case (n, v) => parseAccess(n, v)
  } | P(name.!).map { case n => parseAccess(n, Seq()) } | P("(" ~ access ~ ")")

  def integer[$: P]: P[ConstantInt] =
    P(CharIn("0-9").rep(1).!.map(_.toInt)).map(ConstantInt(_))

  def decimal[$: P]: P[ConstantDouble] = P(
    CharIn("0-9").rep(1).! ~ "." ~ CharIn("0-9").rep(1).!
  ).map({ case (a, b) => (a + "." + b).toDouble }).map(ConstantDouble(_))

  def arith_op[$: P]: P[String] = P("+" | "-" | "*" | "/" | "%").!

  def mult_div_op[$: P]: P[String] = P("*" | "/").!

  def add_sub_op[$: P]: P[String] = P("+" | "-").!

  def remainder_op[$: P]: P[String] = P("%").!

  def remainder[$: P]: P[Index] = P(index ~ (remainder_op ~ index).rep).map({
    case (i, sOpI) => parseArith(i, sOpI)
  })

  def mult_div[$: P]: P[Index] =
    P(remainder ~ (mult_div_op ~ remainder).rep).map({ case (i, sOpI) =>
      parseArith(i, sOpI)
    })

  def arithmetic[$: P]: P[Index] =
    P(mult_div ~ (add_sub_op ~ mult_div).rep).map({ case (i, sOpI) =>
      parseArith(i, sOpI)
    })

  def index[$: P]: P[Index] =
    P(variable) | P(integer) | P(decimal) | P("(" ~ arithmetic ~ ")")

  def comp_op[$: P]: P[String] = P(
    "<=" | ">=" | "==" | "=" | "<" | ">" | "!="
  ).!

  def comparison[$: P]: P[Seq[Comparison]] =
    P(arithmetic ~ (comp_op ~ arithmetic).rep(1)).map({ case (i1, op_i2_Seq) =>
      parseComparison(op_i2_Seq(0)._1, i1, op_i2_Seq(0)._2) ++
        op_i2_Seq.zipWithIndex.tail.flatMap({ case ((op, i2), index) =>
          parseComparison(op, op_i2_Seq(index - 1)._2, i2)
        })
    })

  def exp[$: P]: P[Seq[Exp]] =
    P(access.rep(exactly = 1)) | P(comparison) | P("(" ~ exp ~ ")")

  def factor[$: P]: P[Prod] = P(exp ~ ("*" ~ exp).rep).map { case (e, se) =>
    parseProd(e, se)
  } | P("(" ~ factor ~ ")")

  def sop[$: P]: P[SoP] = P(factor ~ ("+" ~ factor).rep).map { case (f, sf) =>
    SoP(f +: sf)
  } | P("(" ~ sop ~ ")")

  def rule[$: P]: P[Rule] = P(access ~ ":=" ~ sop).map({ case (a, b) =>
    Rule(a, b)
  }) | P("(" ~ rule ~ ")")

  def program[$: P]: P[Seq[Rule]] = P(rule.rep(sep = "\n"))

  def parser[$: P] = P(program ~ End)
}
