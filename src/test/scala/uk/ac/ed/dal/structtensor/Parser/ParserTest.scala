package parser

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatest.ParallelTestExecution

import uk.ac.ed.dal.structtensor.parser.Parser
import uk.ac.ed.dal.structtensor.compiler._

import fastparse._
import fastparse.SingleLineWhitespace._

class ParserTest extends AnyFlatSpec with Matchers with ParallelTestExecution {
  "Parser" should "parse a variable" in {
    val input = "xA_0Tz"
    val result = fastparse.parse(input, Parser.variable(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Variable("xA_0Tz")
  }

  it should "parse a sequence of variables" in {
    val input = "x, y, z"
    val result = fastparse.parse(input, Parser.variableSeq(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Seq(Variable("x"), Variable("y"), Variable("z"))
  }

  it should "parse a name" in {
    val input = "foo:R"
    val result = fastparse.parse(input, Parser.name(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe "foo:R"
  }

  it should "parse an access" in {
    val input = "foo(x, y, z)"
    val result = fastparse.parse(input, Parser.access(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Access(
      "foo",
      Seq(Variable("x"), Variable("y"), Variable("z")),
      Tensor
    )
  }

  it should "parse an access in multiple parantheses" in {
    val input = "(((foo(x, y, z))))"
    val result = fastparse.parse(input, Parser.access(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Access(
      "foo",
      Seq(Variable("x"), Variable("y"), Variable("z")),
      Tensor
    )
  }

  it should "parse an integer" in {
    val input = "123"
    val result = fastparse.parse(input, Parser.integer(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe ConstantInt(123)
  }

  it should "parse a decimal" in {
    val input = "273.1124"
    val result = fastparse.parse(input, Parser.decimal(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe ConstantDouble(273.1124)
  }

  it should "parse an arithmetic operation" in {
    val input = "x + y * z"
    val result = fastparse.parse(input, Parser.arithmetic(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Arithmetic(
      "+",
      Variable("x"),
      Arithmetic("*", Variable("y"), Variable("z"))
    )
  }

  it should "parse a complex arithmetic operation" in {
    val input = "x + y * (z - 2)"
    val result = fastparse.parse(input, Parser.arithmetic(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Arithmetic(
      "+",
      Variable("x"),
      Arithmetic(
        "*",
        Variable("y"),
        Arithmetic("-", Variable("z"), ConstantInt(2))
      )
    )
  }

  it should "parse a comparison" in {
    val input = "x > y"
    val result = fastparse.parse(input, Parser.comparison(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Seq(Comparison(">", Variable("x"), Variable("y")))
  }

  it should "parse a chained comparison" in {
    val input = "x > y = z"
    val result = fastparse.parse(input, Parser.comparison(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Seq(
      Comparison(">", Variable("x"), Variable("y")),
      Comparison("=", Variable("y"), Variable("z"))
    )
  }

  it should "parse an expression" in {
    val input = "foo(x, y, z)"
    val result = fastparse.parse(input, Parser.exp(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Seq(
      Access("foo", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor)
    )
  }

  it should "parse a factor" in {
    val input = "foo(x, y, z) * bar:U(x, y, z) * x > y = z"
    val result = fastparse.parse(input, Parser.factor(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Prod(
      Seq(
        Access("foo", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor),
        Access(
          "bar",
          Seq(Variable("x"), Variable("y"), Variable("z")),
          UniqueSet
        ),
        Comparison(">", Variable("x"), Variable("y")),
        Comparison("=", Variable("y"), Variable("z"))
      )
    )
  }

  it should "parse sum of factors" in {
    val input = "foo(x, y, z) * bar(x, y, z) + baz(x, y) * qux(x, z) * x > y"
    val result = fastparse.parse(input, Parser.sop(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe SoP(
      Seq(
        Prod(
          Seq(
            Access(
              "foo",
              Seq(Variable("x"), Variable("y"), Variable("z")),
              Tensor
            ),
            Access(
              "bar",
              Seq(Variable("x"), Variable("y"), Variable("z")),
              Tensor
            )
          )
        ),
        Prod(
          Seq(
            Access("baz", Seq(Variable("x"), Variable("y")), Tensor),
            Access("qux", Seq(Variable("x"), Variable("z")), Tensor),
            Comparison(">", Variable("x"), Variable("y"))
          )
        )
      )
    )
  }

  it should "parse a rule" in {
    val input = "foo(x, y, z):= bar(x, y, z) * baz(x, y, z) + qux(x, y, z)"
    val result = fastparse.parse(input, Parser.rule(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Rule(
      Access("foo", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor),
      SoP(
        Seq(
          Prod(
            Seq(
              Access(
                "bar",
                Seq(Variable("x"), Variable("y"), Variable("z")),
                Tensor
              ),
              Access(
                "baz",
                Seq(Variable("x"), Variable("y"), Variable("z")),
                Tensor
              )
            )
          ),
          Prod(
            Seq(
              Access(
                "qux",
                Seq(Variable("x"), Variable("y"), Variable("z")),
                Tensor
              )
            )
          )
        )
      )
    )
  }

  it should "parse a program" in {
    val input =
      """|foo(x, y, z):= bar(x, y, z) * baz(x, y, z) + qux(x, y, z)
        |bax(x, y, z):= foo(x, y, z) * bar(x, y, z) + qux(x, y, z)
        |""".stripMargin
    val result = fastparse.parse(input, Parser.program(_))
    result.isSuccess shouldBe true
    result.get.value shouldBe Seq(
      Rule(
        Access("foo", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access(
                  "bar",
                  Seq(Variable("x"), Variable("y"), Variable("z")),
                  Tensor
                ),
                Access(
                  "baz",
                  Seq(Variable("x"), Variable("y"), Variable("z")),
                  Tensor
                )
              )
            ),
            Prod(
              Seq(
                Access(
                  "qux",
                  Seq(Variable("x"), Variable("y"), Variable("z")),
                  Tensor
                )
              )
            )
          )
        )
      ),
      Rule(
        Access("bax", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor),
        SoP(
          Seq(
            Prod(
              Seq(
                Access(
                  "foo",
                  Seq(Variable("x"), Variable("y"), Variable("z")),
                  Tensor
                ),
                Access(
                  "bar",
                  Seq(Variable("x"), Variable("y"), Variable("z")),
                  Tensor
                )
              )
            ),
            Prod(
              Seq(
                Access(
                  "qux",
                  Seq(Variable("x"), Variable("y"), Variable("z")),
                  Tensor
                )
              )
            )
          )
        )
      )
    )
  }
}
