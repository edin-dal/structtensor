package uk.ac.ed.dal
package structtensor
package parser

import fastparse._, SingleLineWhitespace._
import compiler._

object Parser {
  import Interpreter._

  def variable[$: P]: P[Variable] = P( CharIn("A-Za-z") ~ CharIn("A-Za-z0-9_").rep ).!.map(Variable(_))

  def variableSeq[$: P]: P[Seq[Variable]] = P( variable.rep(sep=",") )

  def name[$: P]: P[String] = P( CharIn("A-Za-z") ~ CharIn("A-Za-z0-9._").rep ~ (":" ~ CharIn("DUR")).? ).!

  def access[$: P]: P[Access] = P("(" ~ access ~ ")") | P( name.! ~ "(" ~ variableSeq ~ ")" ).map({case (n, v) => interpretAccess(n, v)})

  def integer[$: P]: P[ConstantInt] = P( CharIn("0-9").rep(1).!.map(_.toInt) ).map(ConstantInt(_))

  def decimal[$: P]: P[ConstantDouble] = P( CharIn("0-9").rep(1).! ~ "." ~ CharIn("0-9").rep(1).! ).map({case (a, b) => (a + "." + b).toDouble}).map(ConstantDouble(_))

  def arith_op[$: P]: P[String] = P( "+" | "-" | "*" | "/" | "%" ).!

  def mult_div_op[$: P]: P[String] = P( "*" | "/" ).!

  def add_sub_op[$: P]: P[String] = P( "+" | "-" ).!

  def remainder_op[$: P]: P[String] = P( "%" ).!

  def remainder[$: P]: P[Index] = P(index ~ (remainder_op ~ index).rep).map({case (i, sOpI) => interpretArith(i, sOpI)})

  def mult_div[$: P]: P[Index] = P(remainder ~ (mult_div_op ~ remainder).rep).map({case (i, sOpI) => interpretArith(i, sOpI)})

  def arithmetic[$: P]: P[Index] = P(mult_div ~ (add_sub_op ~ mult_div).rep).map({case (i, sOpI) => interpretArith(i, sOpI)})
    
  def index[$: P]: P[Index] = P( variable ) | P( integer ) | P( decimal ) | P( "(" ~ arithmetic ~ ")" )

  def comp_op[$: P]: P[String] = P( "<=" | ">=" | "==" | "=" | "<" | ">" | "!=" ).!

  def comparison[$: P]: P[Seq[Comparison]] = P("(" ~ comparison ~ ")" ) | P (arithmetic ~ comp_op ~ arithmetic).map({case (i1, op, i2) => interpretComparison(op, i1, i2)})
    
  def exp[$: P]: P[Seq[Exp]] = P( "(" ~ exp ~ ")" ) | P(access.rep(exactly=1)) | P(comparison)

  def factor[$: P]: P[Prod] = P( "(" ~ factor ~ ")") | P( exp ~ ("*" ~ exp).rep ).map{case(e, se) => interpretProd(e, se)}

  def sop[$: P]: P[SoP] = P( "(" ~ sop ~ ")" ) | P( factor ~ ("+" ~ factor).rep ).map{case(f, sf) => SoP(f +: sf)}

  def rule[$: P]: P[Rule] = P("(" ~ rule ~ ")" ) | P( access ~ ":=" ~ sop ).map({case (a, b) => Rule(a, b)})

  def program[$: P]: P[Seq[Rule]] = P( rule.rep(sep="\n") )

  def parser[$: P] = P( program ~ End )  
}