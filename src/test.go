package main

import (
	"fmt"
	"alg"
	"common"
)

func main() {
	m := 3 
	n := 4 
	for i := 0; i < n; i ++ {
		k := i * m % n
		fmt.Println(k)
	} 
}
