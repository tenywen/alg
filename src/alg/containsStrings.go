package alg

/******************************
O(n + m)
每个字符用素数表示
A = 3
B = 5
C = 7
find的素数相乘，得到m
src中的字母所代表的素数除m, m最后有剩余则不包含 
******************************/

import (
	"fmt"
)


//to doing
func PrimeDivided(src ,find string) bool {
	find_bytes := []byte(find)
	src_bytes := []byte(src)

	base := byte('a')	//假设所有字符都是小写
	fmt.Println(find_bytes,src_bytes,base)	
	return true
}
