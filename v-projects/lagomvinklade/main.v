import math

fn main() {
	// Amount of triangles to calculate. Larger number equals to longer time to completion.
	n := 3000

	// Create the c variable that will be our counter. Set to zero initially.
	mut c := 0

	// Loop through and calculate all the triangles.
	for a := 1; a < n+1; a++ {
		for b := a; b < int(math.min(a*a+1, n+1)); b++ {
			if math.floor(math.sqrt(a*a+b*b-a*b)) == math.ceil((math.sqrt(a*a + b*b - a*b))) {
				c++
			}
		}
	}

	// Lastly, we print the calculated amount of possible triangles within the n number of triangles.
	println(c)
}
