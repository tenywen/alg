package common


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
