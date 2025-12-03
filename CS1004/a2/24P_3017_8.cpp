#include <iostream>
#include <cmath>
using namespace std;

class Shape {
private:
    double area;
protected:
    void calculateArea(double radius) {
        area = 3.1416 * radius * radius;
    }
    double getArea() {
        return area;
    }
public:
    void displayArea() {
        cout << "Area: " << area << endl;
    }
};

class Circle : public Shape {
public:
    void calculateArea(double radius) {
        Shape::calculateArea(radius);
    }
};

int main() {
    Circle c;
    c.calculateArea(5);
    c.displayArea();
    return 0;
}
