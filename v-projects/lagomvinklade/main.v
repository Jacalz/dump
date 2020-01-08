import math

fn main() {
	n := 3000
	mut c := 0

	for a := 1; a < n+1; a++ {
		for b := a; b < math.min(a*a+1, n+1); b++ {
			c++
		} 
	}

	println(c)
}
