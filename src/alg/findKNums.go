package alg

/***********************
find k nums which are min
找到最小的第k个数
O(n)
************************/
import (
	"common"
	"fmt"
)

func _random_partion(array []int32,start,end int32) int32 {
	p := common.Random(start,end)
	fmt.Println(start,end,p)
	return common.Partion(array,start,end,p)
}

//---------- one method
func RandomizedSelect(array []int32,start,end,k int32) int32 {
	if start == end {
		return array[start]
	}
	pos := _random_partion(array,start,end)
	x := pos - start + 1
	if k > x {
		return RandomizedSelect(array,pos + 1,end,k - x)
	}
	if k < x {
		return RandomizedSelect(array,start,pos - 1,k)
	}
	return array[pos]
}

//---------- two method
func HeapSelect(array []int32,k int32) {
//	heap := make([]int32,k)	
}
