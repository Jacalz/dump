#include <iostream>
using namespace std;

int main() {
    unsigned int iterations;  
    cout << "Enter ammount of numbers to print: ";
    cin >> iterations;

    // Set intial values for n-1 and n-2 while also initializing the next var.
    unsigned int n1 = 0, n2 = 1, next;

    for (int i = 0; i < iterations; i++) { 
        // Print next and calculate a new value for it.
        cout << next << endl;
        next = n1 + n2; 
        
        // Set n-2 to be our old n-1 and set n-1 to the next number in the series.
        n2 = n1;
        n1 = next;
    }
}
