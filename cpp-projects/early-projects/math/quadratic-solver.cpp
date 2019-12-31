#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double A, B, C, X1, X2, root;
  cout <<"Equation in format: AX^2 + BX + C = 0" << endl;
  cout << "Enter value of A: "; cin >> A;
  if(A == 0) {
    cout << "Not a quadratic equation!";
    return 0; }
  cout << "Enter value of B: "; cin >> B;
  cout << "Enter value of C: "; cin >> C;

  if(A != 1) {B = B / A, C = C / A;}
  root = pow (B / 2, 2) - C;
  if(root < 0) {
    cerr << "No real solution avaliable!";
    return 0; }
  X1 = -(B / 2) + (sqrt (root));
  X2 = -(B / 2) - (sqrt (root));
  if(X1 == X2) {
    cout << "Only one solution: X = " << X1;
  } else {
    cout << "Value of X1: " << X1 << endl;
    cout << "value of X2: " << X2 << endl;
  }

  return 0;
}
