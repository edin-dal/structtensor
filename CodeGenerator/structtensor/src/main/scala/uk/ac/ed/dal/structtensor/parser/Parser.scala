package uk.ac.ed.dal
package structtensor
package parser

import fastparse._, SingleLineWhitespace._
import compiler._

object Parser {
  import Interpreter._

  def variable[$: P]: P[Variable] = P( CharIn("A-Za-z") ~ CharIn("A-Za-z0-9").rep ).!.map(Variable(_))

  def variableSeq[$: P]: P[Seq[Variable]] = P( variable.rep(sep=",") )

  def name[$: P]: P[String] = P( CharIn("A-Za-z") ~ CharIn("A-Za-z0-9._").rep ).!

  def access[$: P]: P[Access] = P( name.! ~ "(".rep ~ variableSeq ~ ")".rep ).map({case (n, v) => interpretAccess(n, v)})

  def integer[$: P]: P[ConstantInt] = P( CharIn("0-9").rep(1).!.map(_.toInt) ).map(ConstantInt(_))

  def decimal[$: P]: P[ConstantDouble] = P( CharIn("0-9").rep(1).! ~ "." ~ CharIn("0-9").rep(1).!.map(_.toInt) ).map({case (a, b) => (a + "." + b).toDouble}).map(ConstantDouble(_))

  def arith_op[$: P]: P[String] = P( "+" | "-" | "*" | "/" | "%" ).!

  def arithmetic[$: P]: P[Arithmetic] = P( "(".rep ~ index ~ arith_op ~ index ~ ")".rep ).map({case (i1, op, i2) => Arithmetic( op, i1, i2)}) // How to solve precedence issue?
    
  def index[$: P]: P[Index] = P( variable | integer | decimal | arithmetic)

  def comp_op[$: P]: P[String] = P( "<=" | ">=" | "==" | "=" | "<" | ">" | "!=" ).!

  def exp[$: P]: P[Exp] = P( "(".rep ~ variable ~ comp_op ~ index ~ ")".rep ).map({case (v, op, i) => Comparison(op, i, v)}) | 
                          P( "(".rep ~ index ~ comp_op ~ variable ~ ")".rep ).map({case (i, op, v) => Comparison(op, i, v)}) |
                          access

  def factor[$: P]: P[Prod] = P( "(".rep ~ exp.rep(sep="*") ~ ")".rep ).map(Prod(_))

  def body[$: P]: P[SoP] = P( "(".rep ~ factor.rep(sep="+") ~ ")".rep ).map(SoP(_))

  def rule[$: P]: P[Rule] = P( "(".rep ~ access ~ ":=" ~ body ).map({case (a, b) => Rule(a, b)})

  def program[$: P]: P[Seq[Rule]] = P( rule.rep(sep=";") ~ ")".rep )

  def parser[$: P] = P( program ~ End )  
}