package alg

/******************************
2 merge sort
******************************/

import (
	"math"
	"fmt"
)

func _merge_sort(array []int32,start,end int32) []int32{
	if start == end {
		return []int32{array[start]}
	}
	mid := int32(math.Floor(float64((start+end)/2)))
	array_a := _merge_sort(array,start,mid)
	fmt.Println("a:",array_a)
	array_b := _merge_sort(array,mid + 1,end)
	fmt.Println("a:",array_b)
	return _merge(array_a,array_b)
}

func _merge(array_a,array_b []int32) []int32 {
	result := make([]int32,0)
	len_1 := len(array_a)
	len_2 := len(array_b)
	i := 0
	j := 0
	for ;i < len_1 && j < len_2; {
		if array_a[i] > array_b[j] {
			result = append(result,array_b[j])
			j ++
		} else {
			result = append(result,array_a[i])
			i ++
		}
	}

	if i < len_1 {
		for ;i < len_1; i ++ {
			result = append(result,array_a[i])
		}
	}
	if j < len_2 {
		for ; j < len_2; j ++ {
			result = append(result,array_b[j])
		}
	}
	return result
}


func MergeSort(array []int32) []int32 {
	return _merge_sort(array,int32(0),int32(len(array) - 1))	
}

