// Shorthand to be able to only use the min function.
use std::cmp::min;

fn main() {
    // Amount of triangles to calculate. Larger number equals to longer time to completion.
    let n = 3000;

    // Create the c variable that will be our counter. Set to zero initially.
    let mut c = 0;

    // Loop through and calculate all the triangles.
    for a in 1..n + 1 {
        for b in a..min(a * a + 1, n + 1) {
            if f64::floor(f64::sqrt((a * a + b * b - a * b) as f64))
                == f64::ceil(f64::sqrt((a * a + b * b - a * b) as f64))
            {
                c += 1;
            }
        }
    }

    // Lastly, we print the calculated amount of possible triangles within the n number of triangles.
    println!("{}", c);
}
