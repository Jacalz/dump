#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double A, B, C, T1, T2, X1, X2, X3, X4, root;
  cout << "Solver for biquadratic equations!" << endl;
  cout << "Equation in format: AX^4 + BX^4 + C = 0" << endl;
  cout << "Enter value of A: "; cin >> A;
    if(A == 0) {
    cout << "Not a biquadratic equation!";
    return 0; }
  cout << "Enter value of B: "; cin >> B;
  cout << "Enter value of C: "; cin >> C;
  if(A != 1) {B = B / A, C = C / A;}
  root = pow (B / 2, 2) - C;
  T1 = -(B / 2) + (sqrt (root));
  T2 = -(B / 2) - (sqrt (root));
  if(root <= 0) {cerr << "No real solution avaliable!"; return 0;}

  X1 = sqrt(T1);
  X2 = -sqrt(T1);
  X3 = sqrt(T2);
  X4 = -sqrt(T2);

  if(X1 == X3 || T2 < 0) {
    cout << "Only two solutions:" << endl;
    cout << "Value of X1: " << X1 << endl;
    cout << "Value of X2: " << X2 << endl;
  } else {
    cout << "Results of equation:" << endl;
    cout << "Value of X1: " << X1 << endl;
    cout << "value of X2: " << X2 << endl;
    cout << "Value of X3: " << X3 << endl;
    cout << "value of X4: " << X4 << endl;
  }

  return 0;
}
