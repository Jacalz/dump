fn fibon(n: u64) -> u64 {
  if  n == 0 {
    return 0;
  } else if n == 1 {
    return 1;
  }
  return fibon(n-1) + fibon(n-2); 
}

fn main() {
  println!("{}", fibon(45));
}
