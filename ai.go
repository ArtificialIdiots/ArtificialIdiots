package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	fmt.Scanf("%s", &str)
	str = strings.Replace(str, "?", "!", -1)
	str = strings.Replace(str, "吗", "", -1)
	str = strings.Replace(str, "嘛", "", -1)
	str = strings.Replace(str, "你是", "我是", -1)
	str = strings.Replace(str, "你会", "我会", -1)
	str = strings.Replace(str, "你能", "我能", -1)
	fmt.Println(str)
}
