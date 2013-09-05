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
	"common"
)


func PrimeDivided(src ,find string) bool {
	prime_table := make(map[byte]int32,0)
	find_bytes := []byte(find)
	src_bytes := []byte(src)

	base := byte('a')	//假设所有字符都是小写
	fmt.Println(find_bytes,src_bytes,base)
	limit := 26			//26 character
	for i := 2; limit > 0; i ++ {
		if common.JudgePrime(uint64(i)) {
			prime_table[byte(26 - limit + 1)] = int32(i)
			limit --
		}
	}

	find_prime_count := uint64(1)
	for i := 0; i < len(find_bytes); i ++ {
		find_prime_count *= uint64(prime_table[find_bytes[i] - base + 1])
	}
	for i := 0; i < len(src_bytes) && find_prime_count != 1; i ++ {
		if find_prime_count % uint64(prime_table[src_bytes[i] - base + 1]) == 0 {
			find_prime_count /= uint64(prime_table[src_bytes[i] - base + 1])
		}
	}
	if find_prime_count != 1 {
		return false
	}
	return true
}
