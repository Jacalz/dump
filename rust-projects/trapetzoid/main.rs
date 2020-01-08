// Define the equation to integrate.
fn f(x: f64) -> f64 {
    return x * x;
}

// Integral gives us the area under a graph between the start and end values. The accuracy is defined by telling the amount of trapzoids to divide it up into.
fn integral(start: f64, end: f64, ammount: i64) -> f64 {

    // h gives us the length of each divided part.
    let h = (end - start) / ammount as f64;

    // s is our initial sum of half the start values.
    let mut s = 0.5 * (f(start) + f(end));

    // Loop through the sums of the functions at each trapzoid.
    for i in 1..ammount - 1 {
        s += f(start + i as f64 * h)
    }

    // Multiply the height and sum to get the area.
    return h * s;
}

fn main() {
    println!("{}", integral(2.0, 4.0, 1000000))
}
