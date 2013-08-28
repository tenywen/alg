package alg

/******************************
only rotate char
X="abc",X^T="cba"
1.strings->XY
2.(X^T Y^T)^T = YX(three rotate)
3.return YX
******************************/

import (
	"common"
)

func _rotate(str []byte,start,end int32) bool{
	i := start
	j := end
	for ; j > i; {
		str[i],str[j] = str[j],str[i]
		i ++
		j --
	}
	return true
}

func StringRotate(str string, m int32) string{
	length := int32(len(str))
	n := m % length
	if n == 0 {
		return str	
	}
	str_bytes := []byte(str)
	_rotate(str_bytes,0,n - 1) //X^T one rotate
	_rotate(str_bytes,n,length - 1)//Y^T  two rotate
	_rotate(str_bytes,0,length - 1)//^T   three rotate

	_rotate_seq(str_bytes,m)	//another rotate 
	return string(str_bytes)
}

/*****************************
only rotate char
字符串移动，其实是一系列序号
之间的交换。
******************************/
func _rotate_seq(str []byte,m int32) {
	length := int32(len(str))
	np := common.Gcd(length,m)
	for i := int32(0); i < np; i ++ {
		for j := int32(0); j < length; j ++ {
			str[(i + j * m) % length],str[(i + (j + 1) * m) % length]	= str[(i + (j + 1)* m) % length],str[(i + j * m) % length]		} 
	}
}
