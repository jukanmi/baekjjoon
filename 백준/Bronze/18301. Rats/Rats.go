package main

import (
	"fmt"
)

func main() {
	var a int
	var b int
	var c int
	fmt.Scanf("%d%d%d", &a, &b, &c)
	fmt.Println((a+1)*(b+1)/(c+1) - 1)
}
