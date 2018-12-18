while(true) {
  println(scala.io.StdIn.readLine("> ").
    split('吗').
    dropRight(1).
    mkString("吗") + "！")
}
