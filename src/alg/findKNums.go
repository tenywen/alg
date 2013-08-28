package alg

/***********************
find k nums which are min
找到最小的k个数
************************/

import (
	"fmt"
	"common"
)

func _random_partion(array []int32,start,end int32) int32 {
	p := common.Random(start,end)
	return common.Partion(array,start,end,p)
}

func RandomizedSelect(array []int32,start,end,k int32) []int32 {
	length := int32(len(array))
	pos := _random_partion(array,start,end)
	x := pos - start + 1
	fmt.Printf("pos :%v,x :%v,k :%v, start:%v, len :%v\n",pos,x,k,start,length)
	if k > x {
		RandomizedSelect(array,pos + 1,end,k - x)
	}
	if k < x {
		RandomizedSelect(array,start,pos - 1,k)
	}
	return array[start:start + k]
}
