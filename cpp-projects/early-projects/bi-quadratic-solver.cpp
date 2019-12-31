#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double A, B, C, Q1, Q2, BQ1, BQ2, BQ3, BQ4, root;
  string equation_type;
  cout << "Choose quadratic or biquadratic equation: ";
  getline(cin, equation_type);
  if (equation_type == "quadratic") {
    cout << "Equation in format: AX^2 + BX + C = 0" << endl;
  } else if(equation_type == "biquadratic") {
    cout << "Equation in format: AX^4 + BX^4 + C = 0" << endl;
  } else {
    cout << "Not a valid equation type!";
    return 0;
  }
  cout << "Enter value of A: "; cin >> A;
  if(A == 0) {cout << "Not a quadratic equation!"; return 0;}
  cout << "Enter value of B: "; cin >> B;
  cout << "Enter value of C: "; cin >> C;
  if(A != 1) {B = B / A, C = C / A;}

  root = pow(B / 2, 2) - C;
  if(root < 0) {cerr << "No real solution avaliable!"; return 0;}

  Q1 = -(B / 2) + (sqrt (root));
  Q2 = -(B / 2) - (sqrt (root));

  if (equation_type == "quadratic") {
    if(Q1 == Q2) {
      cout << "Only one solution: X = " << Q1;
    } else {
      cout << "Value of X1: " << Q1 << endl;
      cout << "value of X2: " << Q2 << endl;
    }
  } else {
      BQ1 = sqrt(Q1);
      BQ2 = -sqrt(Q1);
      BQ3 = sqrt(Q2);
      BQ4 = -sqrt(Q2);

      if(BQ1 == BQ3 || Q2 < 0) {
        cout << "Only two solutions:" << endl;
        cout << "Value of X1: " << BQ1 << endl;
        cout << "Value of X2: " << BQ2 << endl;
      } else {
        cout << "Results of equation:" << endl;
        cout << "Value of X1: " << BQ1 << endl;
        cout << "value of X2: " << BQ2 << endl;
        cout << "Value of X3: " << BQ3 << endl;
        cout << "value of X4: " << BQ4 << endl;
    }
  }

  return 0;
}

