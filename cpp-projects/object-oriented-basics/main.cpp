#include <iostream>

using namespace std;

class Rectangle {
    public:
        float Length;
        float Height;

        double Area();
        double Circumference();
};

double Rectangle::Area() {
    return Length * Height;
}

double Rectangle::Circumference() {
    return 2 * (Length + Height);
}

int main() {
    Rectangle First;

    First.Length = 5;
    First.Height = 7;

    cout << First.Area() << endl;
    cout << First.Circumference() << endl;
}