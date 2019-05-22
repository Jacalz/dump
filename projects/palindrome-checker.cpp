#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string input;
  cout << "Enter word to check: ";
  cin >> input;
  
  transform(input.begin(), input.end(), input.begin(), ::tolower);
  string reversed(input);
  reverse(reversed.begin(), reversed.end());

  if (input == reversed) {
    cout << "The entered string is a palindrome!";
  } else {
    cout << "The entered string is not a palindrome!";
  }
}
