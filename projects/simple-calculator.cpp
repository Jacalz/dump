#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cout << "Type your mathematical expression: ";
  double num1, num2; char op;
  cin >> num1 >> op >> num2;

switch(op) {
  case '+': cout << "Your result is: " << num1 + num2; break;
  case '-': cout << "Your result is: " << num1 - num2; break;
  case '*': cout << "Your result is: " << num1 * num2; break;
  case '/': cout << "Your result is: " << num1 / num2; break;
  case '^': cout << "Your result is: " << pow(num1, num2); break;
  case 'v': cout << "Your result is: " << pow(num2, (1 / num1)); break;
  default: cout << "Error: not a valid expression"; break;
  }

  return 0;
}
