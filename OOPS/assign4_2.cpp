//operator overlaoding
#include <iostream>
using namespace std;

// Class representing a Point
class Point {
public:
    int x, y;

    // Constructor
    Point(int x_val = 0, int y_val = 0) {
        x = x_val;
        y = y_val;
    }

    // -------- OPERATOR OVERLOADING --------

    // Overloading + operator to add two Point objects
    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }

    // Overloading - operator
    Point operator-(Point p) {
        return Point(x - p.x, y - p.y);
    }

    // Overloading * operator
    Point operator*(Point p) {
        return Point(x * p.x, y * p.y);
    }

    // Display function
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x1, y1, x2, y2;

    // Taking input
    cout << "Enter coordinates of Point 1 (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of Point 2 (x2 y2): ";
    cin >> x2 >> y2;

    // Creating objects
    Point p1(x1, y1), p2(x2, y2);

    Point result;

    cout << "\nResults using Operator Overloading:\n";

    // Using overloaded operators
    result = p1 + p2;   // Calls operator+
    cout << "Addition: ";
    result.display();

    result = p1 - p2;   // Calls operator-
    cout << "Subtraction: ";
    result.display();

    result = p1 * p2;   // Calls operator*
    cout << "Multiplication: ";
    result.display();

    return 0;
}