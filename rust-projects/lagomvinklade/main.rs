use std::cmp::min;


fn main() {
    let n = 3000;
    let mut c = 0;

    for a in 1..n+1 {
      for b in a..min(a*a+1, n+1) {
        if f64::floor(f64::sqrt((a*a+b*b-a*b) as f64)) == f64::ceil(f64::sqrt((a*a+b*b-a*b) as f64)) {
          c += 1;
        }
      }
    }

    println!("{}", c);
}
