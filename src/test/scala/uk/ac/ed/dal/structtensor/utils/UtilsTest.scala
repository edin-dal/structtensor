package uk.ac.ed.dal
package structtensor
package utils

import compiler._

import java.io._

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

class UtilsTest extends AnyFlatSpec with Matchers with ParallelTestExecution {
  "Utils" should "write to file correct value" in {
    Utils.write2File("test.txt", "test", append = false)
    val file = new File("test.txt")
    file.exists() should be(true)
    val source = scala.io.Source.fromFile("test.txt")
    val lines =
      try source.mkString
      finally source.close()
    lines should be("test")
    file.delete()
  }
}
