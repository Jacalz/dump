import std;
import std.math : sqrt, ceil;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void main() {
    const int n = 3000;
    int c = 0;
    int a, b;

    for (a = 1; a < n + 1; a++) {
        for (b = a; b < min(a * a + 1, n + 1); b++) {
            if (floor(sqrt(float(a * a + b * b - a * b))) == ceil(sqrt(float(a * a + b * b - a * b)))) {
                c++;
            }
        }
    }
    
    writeln(c);
}
