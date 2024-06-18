package parser
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import uk.ac.ed.dal.structtensor.parser.Parser
import uk.ac.ed.dal.structtensor.compiler._
import fastparse._
import fastparse.SingleLineWhitespace._

class ParserTest extends AnyFlatSpec with Matchers {
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
        result.get.value shouldBe Access("foo", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor)
    }

    it should "parse an integer" in {
        val input = "123"
        val result = fastparse.parse(input, Parser.integer(_))
        result.isSuccess shouldBe true
        result.get.value shouldBe ConstantInt(123)
    }

    it should "parse a decimal" in {
        val input = "3.14"
        val result = fastparse.parse(input, Parser.decimal(_))
        result.isSuccess shouldBe true
        result.get.value shouldBe ConstantDouble(3.14)
    }

    it should "parse an arithmetic operation" in {
        val input = "x + y * z"
        val result = fastparse.parse(input, Parser.arithmetic(_))
        result.isSuccess shouldBe true
        result.get.value shouldBe Arithmetic("+", Variable("x"), Arithmetic("*", Variable("y"), Variable("z")))
    }

    it should "parse a comparison" in {
        val input = "x > y"
        val result = fastparse.parse(input, Parser.comparison(_))
        result.isSuccess shouldBe true
        result.get.value shouldBe Seq(Comparison(">", Variable("x"), Variable("y")))
    }

    it should "parse an expression" in {
        val input = "foo(x, y, z)"
        val result = fastparse.parse(input, Parser.exp(_))
        result.isSuccess shouldBe true
        result.get.value shouldBe Seq(Access("foo", Seq(Variable("x"), Variable("y"), Variable("z")), Tensor))
    }
}