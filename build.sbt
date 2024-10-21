scalaVersion := "3.3.3"

name := "struct-tensor"
organization := "uk.ac.ed.dal"
version := "0.1"

libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "2.0.0"
libraryDependencies += "com.lihaoyi" %% "fastparse" % "3.0.2"
libraryDependencies += "com.github.scopt" %% "scopt" % "4.1.0"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.11" % Test

addCommandAlias(
  "test-no-codegen",
  """;
    set ThisBuild/Test/testOptions += Tests.Filter(t => !t.endsWith("CodegenTest"));
    test;
    set ThisBuild/Test/testOptions -= Tests.Filter(t => !t.endsWith("CodegenTest"))
  """.stripMargin
)
