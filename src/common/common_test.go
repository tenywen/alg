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

func TestJudgePrime(t *testing.T) {
	c := uint64(0)
	i := uint64(0)
	for ; i < 100000; i ++ {
		if	JudgePrime(i) ==  true {
			c ++
		}
		
	}
	fmt.Println(c)
}

func TestPartion(t *testing.T) {
	m := []int32{10,12,18,1,2,4,9,99,10,17,23,33,79,68}
	Partion(m,0,int32(len(m)) - 1,8)
	fmt.Println(m)
}

func TestRandom(t *testing.T) {
	fmt.Println(Random(10,100))	
}

func TestBuildHeap(t *testing.T) {
	m := []int32{10,12,18,1,2,4,9,99,10,17,23,33,79,68}
	fmt.Println(m)
	BuildHeap(m,"max")
	fmt.Println(m)
}

func TestGetHeapRoot(t *testing.T) {
	m := []int32{10,12,18,1,2,4,9,99,10,17,23,33,79,68}
	BuildHeap(m,"max")
	length := int32(len(m))
	heapSize := length
	for i := int32(0); i < length; i ++ {
		fmt.Println(GetHeapRoot(m,"max",heapSize))
		heapSize -= 1
	}
	fmt.Println("===================")
	BuildHeap(m,"min")
	heapSize = length
	for i := int32(0); i < length; i ++ {
		fmt.Println(GetHeapRoot(m,"min",heapSize))
		heapSize -= 1
	}
}
