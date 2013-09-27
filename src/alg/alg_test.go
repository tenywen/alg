package alg

import (
	"testing"
	"fmt"
)

func TestStringsRotate(t *testing.T) {
	str := "abcdefg"	
	fmt.Println(str)
	fmt.Println(StringRotate(str,1))
	fmt.Println(StringRotate(str,2))
	fmt.Println(StringRotate(str,3))
	fmt.Println(StringRotate(str,4))
	fmt.Println(StringRotate(str,5))
	fmt.Println(StringRotate(str,6))
	fmt.Println(StringRotate(str,7))
	fmt.Println(StringRotate(str,8))
	fmt.Println(StringRotate(str,9))
	fmt.Println(StringRotate(str,10))
	fmt.Println(StringRotate(str,11))
}


func TestRandomizedSelect(t *testing.T) {
	array := []int32{1,343,3434,34454,5,4554,231,55455,14,545,121,7545,}
	fmt.Println(RandomizedSelect(array,0,int32(len(array) - 1),1))
	fmt.Println(RandomizedSelect(array,0,int32(len(array) - 1),2))
	fmt.Println(RandomizedSelect(array,0,int32(len(array) - 1),3))
	fmt.Println(RandomizedSelect(array,0,int32(len(array) - 1),4))
	fmt.Println(RandomizedSelect(array,0,int32(len(array) - 1),5))
}

func TestPrimeDivided(t *testing.T) {
	src := string("abcdefgh")
	find := string("haj")
	fmt.Println(PrimeDivided(src,find))
}

func TestMergeSort(t *testing.T) {
	array := []int32{12,10,222,3,3,4,5,6,9,10,22,33,123,2545,545,12,754}
	fmt.Println(array)
	fmt.Println(MergeSort(array))
}

func TestLCS(t *testing.T) {
	array_a := []byte("cedef")
	array_b := []byte("hijkelkjmlc")
	fmt.Println(array_a,array_b)
	_lcs_length(array_a,array_b)	
}
