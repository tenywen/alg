package common

import (
	"testing"
	"fmt"
)

func TestGcd(t *testing.T) {
	fmt.Println(Gcd(5,12))	
	fmt.Println(Gcd(5,10))	
	fmt.Println(Gcd(20,10))	
	fmt.Println(Gcd(14,21))	
	fmt.Println(Gcd(100000,1))	
}
