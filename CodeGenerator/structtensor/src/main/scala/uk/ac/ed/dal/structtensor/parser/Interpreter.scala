package uk.ac.ed.dal
package structtensor
package parser

import compiler._

object Interpreter {
  def interpretAccess(n: String, v: Seq[Variable]): Access = {
    if (n.endsWith("_U")) Access(n.substring(0, n.length-2), v, UniqueSet)
    else if (n.endsWith("_Dim")) Access(n.substring(0, n.length-4), v, UniqueSet)
    else if (n.endsWith("_R")) Access(n.substring(0, n.length-2), v, RedundancyMap)
    else if (n.endsWith("_C")) Access(n.substring(0, n.length-2), v, CompressedTensor)
    else Access(n, v, Tensor)
  }
  
}