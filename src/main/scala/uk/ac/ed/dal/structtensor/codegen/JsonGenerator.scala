package uk.ac.ed.dal
package structtensor
package codegen

import compiler._

object JsonGenerator {
  def codegen(e: Exp): String = e match {
    case Access(name, vars, tp) => s"""{ 
  op: 'access', 
  vars: [${vars.map(codegen).mkString(",\n")}],
  tp: '${codegen(tp)}'
}"""
    case _ => "NOT_HANDLED"
  }
  def codegen(v: Variable): String = s"{ op: 'var', name: '${v.name}'}"
  def codegen(tp: AccessType): String = tp.toString
}