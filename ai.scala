while(true) {
  println(scala.io.StdIn.readLine("> ").
    replaceAll("你", "我").
    split('吗').
    dropRight(1).
    mkString("吗") + "!")
}
