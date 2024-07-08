scalaVersion := "2.13.14"

name := "struct-tensor"
organization := "uk.ac.ed.dal"
version := "0.1"

libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "1.1.2"
libraryDependencies += "com.lihaoyi" %% "fastparse" % "3.0.2"
libraryDependencies += "com.github.scopt" %% "scopt" % "4.1.0"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.11" % Test
