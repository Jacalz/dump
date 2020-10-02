import std;

// Define the equation to integrate.
double f(double x) {
  return x * x;
}

// Integral gives us the area under a graph between the start and end values. The accuracy is defined by telling the amount of trapzoids to divide it up into.
double integral(double start, double end, int ammount) {

  // h gives us the length of each divided part.
  double h = (end - start) / ammount;

  // s is our intital sum of half the start values.
  double s = 0.5 * (f(start) + f(end));

  // Loop through the sums of the functions at each trapzoid.
  for (int i = 1; i < ammount-1; i++) {
    s += f(start + i * h);
  }

  // The area is our h multiplied by the sum.
  double I = h * s;

  return I;
}

void main() {
    writefln("%f", integral(2, 4, 1000000));
}
