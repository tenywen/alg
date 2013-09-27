package alg

/******************************
		LCS
最长子序列
比如abcdefg 和accddfg的
最长子序列是acdfg
******************************/

import(
	"math"
	"fmt"
)

const (
	X	=	256
	Y 	=	256
)


// 计算lcs长度，并且保存lcs子序列信息
func _lcs_length(array_a,array_b []byte) {

	//lcs长度信息
//	length_1 := len(array_a)
//	length_2 := len(array_b)
	c := [X][Y]byte{}
	b := []byte{} 
	for i := 1; i <= len(array_a); i ++ {
		c[i][0]	= byte(0)	
	}
	for j := 1; j <= len(array_b); j ++ {
		c[0][j]	= byte(0)	
	}
	
	for i := 1; i <= len(array_a); i ++ {
		for j := 1; j <= len(array_b); j ++ {
			if array_a[i - 1] == array_b[j - 1] {
				c[i][j]	= c[i - 1][j - 1] + 1
				b = append(b,array_a[i - 1])	
			} else {
				c[i][j] = byte(math.Max(float64(c[i - 1][j]),float64(c[i][j - 1])))
			}
			fmt.Printf("c[%v][%v] = %v\n",i,j,c[i][j])
		}
	}
	fmt.Println(string(b))
}
