#include <iostream>
#include <cmath>

using namespace std;

// Column represents the values for the column to calculate buckling of it.
class Column {
    public:
        // The set of variables that are always needed:
        double YieldStength;    // N/mm2
        double ElasticModulus;  // N/mm2
        double Length;          // mm
        double ColumnForce;     // N
        double BucklingSafety;  // Procent in decimal form.
        uint8_t Fastening;      // Which fastening case that is used. Valid values are 1, 2, 3 or 4.

        // Can optionally be provided to calculate some of the needed variables:
        double BucklingLength;  // mm
        double Area;            // mm2
        double Imin;            // mm4
        double BucklingForce;   // N
        double Lambda;          // N/mm2
        double LambdaZero;      // N/mm2

        // Data for the column type:
            bool Circle;            // Specifies that we have a circle.
            bool CircularPipe;      // Specifies that we have a cirular pipe.
            bool Rectangle;         // Specifies that we have a rectangle.
            bool RectangularPipe;   // Specifies that we have a rectangular pipe.

        // Data for the cross section:
            // The circular data variables:
            double CircleDiameter;      // mm
            double OuterCircleDiameter; // mm
            double InnerCircleDiameter; // mm

            // The rectangular variables:
            double RectSideLong;        // mm
	        double RectSideShort;       // mm
	        double RectWallThickness;   // mm

        // Members for the class:
        bool CheckValidBuckling();
        bool Buckling();

        double BucklingSafetyFactor; // Private variable calculated from other variables, can not be entered by hand.
};

// CheckValidBuckling checks if the can use the buckling theory.
bool Column::CheckValidBuckling() {
    // Calculate Lambda value if Lambda isn't provided.
    if (Lambda == 0) {
        Lambda = BucklingLength / sqrt(Imin / Area);
    }

    // Calculate LambdaZero as the lowest possible number of Lambda.
    if (LambdaZero == 0) {
        LambdaZero = sqrt((M_PI * M_PI * ElasticModulus) / (0.99 * YieldStength)); 
    }

    // Return true if Lambda is bigger than LambdaZero, that means we can use Eulers buckling theories.
    if (Lambda > LambdaZero) {
        return true;
    }

    return false;
}

bool Column::Buckling() {
    // Check what case should use for the free buckling length. Use case two when no case is provided.
    if (BucklingLength == 0) {
        switch (Fastening) {
            case 1:
                BucklingLength = 2 * Length;
                break;
            case 2:
                BucklingLength = 0.7 * Length;
                break;
            case 3:
                BucklingLength = 0.5 * Length;
                break;
            case 4:
                BucklingLength = Length;
                break;
            default:
                BucklingLength = 0.7 * Length;
        }
    }

    // Calculate the minimum value of I, called Imin.
    if (Imin == 0) {
        if (Circle) {
            Imin = (M_PI * pow(CircleDiameter, 4)) / 64; 
        } else if (CircularPipe) {
            Imin = (M_PI / 64) * (pow(OuterCircleDiameter, 4) - pow(InnerCircleDiameter, 4));
        } else if (Rectangle) {
            Imin = (pow(RectSideShort, 3) * RectSideLong) / 12;
        } else if (RectangularPipe) {
            Imin = ((pow(RectSideShort, 3) * RectSideLong) - (pow(RectSideShort - 2*RectWallThickness, 3) * (RectSideLong - 2*RectWallThickness))) / 12;
        }
    }

    // Calculate the Area of our column depending on which type of column we have.
    if (Area == 0) {
        if (Circle) {
            Area = M_PI * pow(0.5* CircleDiameter, 2);
        } else if (CircularPipe) {
            Area = M_PI * (pow(0.5* OuterCircleDiameter, 2) - pow(0.5* InnerCircleDiameter, 2));
        } else if (Rectangle) {
            Area = RectSideShort * RectSideLong;
        } else if (RectangularPipe) {
            Area = RectSideShort * RectSideLong - (RectSideShort-2*RectWallThickness) * (RectSideLong-2*RectWallThickness);
        }
    }

    if (!CheckValidBuckling()) {
        cout << "We can't use Eulers theory of buckling in this example!" << endl;
        return false;
    }

    if (BucklingForce == 0) {
        BucklingForce = M_PI * M_PI * ((ElasticModulus * Imin) / pow(BucklingLength, 2));
    }

    BucklingSafetyFactor = BucklingForce / ColumnForce;

    if (BucklingSafetyFactor > 1) {
        return false;
    }

    return true;
}

int main() {
    // Define our object.
    Column Horizontal;

    // Add data to the object.
    Horizontal.YieldStength = 275;
    Horizontal.ElasticModulus = 105000;
    Horizontal.Length = 2400;
    Horizontal.Fastening = 2;
    Horizontal.RectangularPipe = true;
    Horizontal.RectSideShort = 30;
    Horizontal.RectSideLong = 50;
    Horizontal.RectWallThickness = 2.6;
    Horizontal.ColumnForce = 10000;

    cout << "The column will buckle and break: " << Horizontal.Buckling() << endl;
    cout << "The column has a safety factor on: " << Horizontal.BucklingSafetyFactor << endl;
}