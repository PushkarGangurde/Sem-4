#include <iostream>
using namespace std;

class Circle {
    const double pi = 3.14;
private:
    double radius;
public:
    Circle() {//default
        radius = 1.0;
        cout << "Default. Radius: " << radius << endl;
    }

    Circle(double r){//parametrized
        radius = r;
        cout << "Parameterized. Radius: " << r << endl;
    }

    Circle(const Circle& c) { //copy
        radius = c.radius;
        cout << "Copy. Radius: " << c.radius << endl;
    }

    ~Circle() {
        cout << "destructor. radius: " << radius << endl;
    }

    double area() {
        return pi * radius * radius;
    }

    double perimeter() {
        return 2 * pi * radius;
    }
};

class Rectangle {
private:
    double height;
    double width;
public:
    Rectangle(){ //default
        height = width = 1.0;
        cout << "Default. Height: " << height << ", Width: " << width << endl;
    }

    Rectangle(double h, double w){//parametrized
        height = h;
        width = w;
        cout << "Parameterized. Height: " << h << ", Width: " << w << endl;
    }

    Rectangle(const Rectangle& r){ //copy
        height = r.height;
        width = r.width;
        cout << "Copy. Height: " << r.height << ", Width: " << r.width << endl;
    }

    ~Rectangle() { //dest
        cout << "Destructor. Height: " << height << ", Width: " << width << endl;
    }

    double area() {
        return height * width;
    }

    double perimeter() {
        return 2 * (height + width);
    }
};

int main() {
    cout << "Creating Circle objects:" << endl;
    Circle c1; // Default 
    Circle c2(5.0); // implicit Parameterized 
    Circle c3 = Circle(5.0); // explicit Parameterized 
    Circle c4 = c2; // Copy 

    cout << "\nCircle c1 - Area: " << c1.area() << ", Perimeter: " << c1.perimeter() << endl;
    cout << "Circle c2 - Area: " << c2.area() << ", Perimeter: " << c2.perimeter() << endl;
    cout << "Circle c3 - Area: " << c3.area() << ", Perimeter: " << c3.perimeter() << endl;
    cout << "Circle c4 - Area: " << c4.area() << ", Perimeter: " << c4.perimeter() << endl;

    cout << "\nCreating Rectangle objects:" << endl;
    Rectangle r1; // Default
    Rectangle r2(3.0, 4.0); // implicit Parameterized
    Rectangle r3 = Rectangle(3.0, 4.0); // explicit Parameterized
    Rectangle r4 = r2; // Copy

    cout << "\nRectangle r1 - Area: " << r1.area() << ", Perimeter: " << r1.perimeter() << endl;
    cout << "Rectangle r2 - Area: " << r2.area() << ", Perimeter: " << r2.perimeter() << endl;
    cout << "Rectangle r3 - Area: " << r3.area() << ", Perimeter: " << r3.perimeter() << endl;
    cout << "Rectangle r4 - Area: " << r4.area() << ", Perimeter: " << r4.perimeter() << endl;

    cout << "\nEnd of main." << endl;
    return 0;
}