package alg

import (
	"testing"
	"fmt"
)

func TestStringsRotate(t *testing.T) {
	str := "abcdefg"	
	fmt.Println(str)
	fmt.Println(String_rotate(str,1))
	fmt.Println(String_rotate(str,2))
	fmt.Println(String_rotate(str,3))
	fmt.Println(String_rotate(str,4))
	fmt.Println(String_rotate(str,5))
	fmt.Println(String_rotate(str,6))
	fmt.Println(String_rotate(str,7))
	fmt.Println(String_rotate(str,8))
	fmt.Println(String_rotate(str,9))
	fmt.Println(String_rotate(str,10))
	fmt.Println(String_rotate(str,11))
}
