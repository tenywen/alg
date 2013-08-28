package common

import (
	"math"
	"math/rand"
	"time"
	"fmt"
)

//greatest common divisor
//Euclidean algorithm
func Gcd(m,n int32) int32 {
	if n < m {
		m,n = n,m	
	}	 
	r := m % n
	for ; r != 0; {
		m = n
		n = r
		r = m % n
	}
	return n
}


//judge prime numbers
//just fun....
func JudgePrime(num uint64) bool {
	if num == 2 || num == 3 || num == 5 {
		return true
	}
	if num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num == 1 {
		return false
	}
	c := uint64(7)
	m := uint64(math.Sqrt(float64(num)))
	for ; c <= m ; {
		if num % c == 0 {
			return false
		}
		c += 4
		if num % c == 0 {
			return false
		}
		c += 2
		if num % c == 0 {
			return false
		}
		c += 4
		if num % c == 0 {
			return false
		}
		c += 2
		if num % c == 0 {
			return false
		}
		c += 4
		if num % c == 0 {
			return false
		}
		c += 6
		if num % c == 0 {
			return false
		}
		c += 2
		if num % c == 0 {
			return false
		}
		c += 6
	}
	return true
}

//partions
//0,i - 1 < array[i]
//i + 1,len(array) - 1 > array[i]
func Partion(array []int32,start,end,pos int32) int32{
	temp := array[pos]
	i := start 
	j := end 
	for ; i < j ; {
		for ;array[i] <= temp && i < j ;{
			i ++
		}

		array[pos] = array[i]
		pos = i
		for ;array[j] >= temp && i < j ;{
			j --
		}

		array[pos] = array[j]
		pos = j
	}
	array[i] = temp
	return i
}

func Random(start,end int32) int32 {
	if end < start {
		return 0
	}
	if start == end {
		return start
	}
	r := rand.New(rand.NewSource(time.Now().Unix()))
	return r.Int31() % (end - start) + 1 + start
}

//modify heap
func _modify_heap(array []int32,i int32) {
	r := i << 1 + 2	  //i (0,len(array) - 1)
	l := i << 1 + 1
	largest := i
	length := int32(len(array))
	if length > l && array[l] > array[largest] {
		largest = l
	}
	if length > r && array[r] > array[largest] {
		largest = r
	}
	fmt.Printf("l :%v, r :%v, i :%v, larget :%v\n",l,r,i,largest)
	if largest != i {
		array[i],array[largest]	= array[largest],array[i]
		_modify_heap(array,largest)
	}
}

//build max heap
func BuildHeap(array []int32) {
	length := int32(len(array))
	for i := int32((length - 2)/2); i >= 0; i -- {
		_modify_heap(array,i)
	}
}
