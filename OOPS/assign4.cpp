//function overloading
#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x_val = 0, int y_val = 0) {
        x = x_val;
        y = y_val;
    }

    int add(int a, int b) {
        return a + b;
    }

    int sub(int a, int b) {
        return a - b;
    }

    int mul(int a, int b) {
        return a * b;
    }

    Point add(Point p1, Point p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    Point sub(Point p1, Point p2) {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }

    Point mul(Point p1, Point p2) {
        return Point(p1.x * p2.x, p1.y * p2.y);
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point obj;

    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "\nInteger Operations:" << endl;
    cout << "Addition: " << obj.add(a, b) << endl;
    cout << "Subtraction: " << obj.sub(a, b) << endl;
    cout << "Multiplication: " << obj.mul(a, b) << endl;

    int x1, y1, x2, y2;

    // Taking input for Point objects
    cout << "\nEnter coordinates of Point 1 (x y): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of Point 2 (x y): ";
    cin >> x2 >> y2;

    // Creating two Point objects
    Point p1(x1, y1), p2(x2, y2);

    cout << "\nPoint Operations:" << endl;

    Point result;

    // Calling overloaded functions for objects
    result = obj.add(p1, p2);
    cout << "Addition: ";
    result.display();

    result = obj.sub(p1, p2);
    cout << "Subtraction: ";
    result.display();

    result = obj.mul(p1, p2);
    cout << "Multiplication: ";
    result.display();

    return 0;
}