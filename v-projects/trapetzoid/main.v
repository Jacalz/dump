// Define the equation to integrate.
fn f(x f64) f64 {
    return x * x
}

// Integral gives us the area under a graph between the start and end values. The accuracy is defined by telling the amount of trapzoids to divide it up into.
fn integral(start, end f64, ammount int) f64 {
    
    // h gives us the length of each divided part.
    h := (end - start) / ammount

    // s is our intital sum of half the start values.
    mut s := 0.5 * (f(start) + f(end))

    // Loop through the sums of the functions at each trapzoid.
    for i := 1; i < ammount-1; i++ {
        s += f(start + f64(i) * h)
    }

    // Multiply the height and sum to get the area.
    return h * s
}

fn main() {
    println(integral(2, 4, 1000000))
}
