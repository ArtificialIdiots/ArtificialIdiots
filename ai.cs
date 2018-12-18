using System;
using System.Text.RegularExpressions;

public class AI {
  static string Analytics(string input) {
    Random rnd = new Random();
    if (input.Contains("吗"))
      input = input.Replace("吗", rnd.Next(2) == 0 ? "" : "呀");
    if (input.Contains("你"))
      input = input.Replace("你", rnd.Next(2) == 0 ? "" : "我");
    input = Regex.Replace(input, @"[？|?]", "！");
    return input;
  }

  static void Main(string[] args) {
    string line;
    Console.WriteLine("你好我的朋友！");
    while ((line = Console.ReadLine()) != null) {
      if (line == "")
        continue;
      if (line == "再见") {
        Console.WriteLine("再见我的朋友！");
        break;
      }
      if (line == "你好") {
        Console.WriteLine("你好！");
        continue;
      }
      Console.WriteLine(Analytics(line));
    }
  }
}
