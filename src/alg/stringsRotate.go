package alg

import (
)


//only rotate char
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

func String_rotate(str string, m int32) string{
	length := int32(len(str))
	n := m % length
	if n == 0 {
		return str	
	}
	str_bytes := []byte(str)
	_rotate(str_bytes,0,n - 1)
	_rotate(str_bytes,n,length - 1)
	_rotate(str_bytes,0,length - 1)
	return string(str_bytes)
}


