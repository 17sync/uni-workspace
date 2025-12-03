#include <iostream>
using namespace std;

double mySqrt(double x) {
    if (x < 0) return -1;
    double guess = x;
    for (int i = 0; i < 20; i++) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

const double PI = 3.14159265;
const double TAN_P20 = 0.726542528;

class Shape {
protected:
    string color;
    string name;

public:
    Shape(string c, string n) : color(c), name(n) {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const { cout << "Shape\n"; }
    virtual void getDetails() const { cout << color << " " << name << "\n"; }
    bool operator<(const Shape& other) const { return area() < other.area(); }
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(string c, string n, double radius) : Shape(c, n), r(radius) {
        if (r <= 0) throw invalid_argument("Invalid radius");
    }
    double area() const { return PI * r * r; }
    double perimeter() const { return 2 * PI * r; }
    void draw() const {
        cout << "Drawing " << color << " circle " << name << "\n";
        cout << "  ⭕\n";
        cout << " ⭕⭕⭕\n";
        cout << "⭕⭕⭕⭕⭕\n";
    }
    void getDetails() const {
        cout << color << " Circle - Radius: " << r << " Area: " << area() << "\n";
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(string c, string n, double W, double H) : Shape(c, n), w(W), h(H) {
        if (w <= 0 || h <= 0) throw invalid_argument("Invalid size");
    }
    double area() const { return w * h; }
    double perimeter() const { return 2 * (w + h); }
    void draw() const {
        cout << "Drawing " << color << " rectangle " << name << "\n";
        for (int i = 0; i < (int)h; i++) {
            for (int j = 0; j < (int)w; j++) cout << "▢";
            cout << "\n";
        }
    }
    void getDetails() const {
        cout << color << " Rectangle " << w << "x" << h << " Area: " << area() << "\n";
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(string col, string n, double A, double B, double C)
        : Shape(col, n), a(A), b(B), c(C) {
        if (a <= 0 || b <= 0 || c <= 0 ||
            a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle");
    }
    double perimeter() const { return a + b + c; }
    double area() const {
        double s = perimeter() / 2;
        return mySqrt(s * (s - a) * (s - b) * (s - c));
    }
    void draw() const {
        cout << "Drawing " << color << " triangle " << name << "\n";
        cout << "  ▲\n";
        cout << " ▲▲▲\n";
        cout << "▲▲▲▲▲\n";
    }
    void getDetails() const {
        cout << color << " Triangle Sides: " << a << " " << b << " " << c
             << " Area: " << area() << "\n";
    }
};

class Pentagon : public Shape {
    double s;
public:
    Pentagon(string col, string n, double side) : Shape(col, n), s(side) {
        if (s <= 0) throw invalid_argument("Invalid side");
    }
    double area() const { return (5 * s * s) / (4 * TAN_P20); }
    double perimeter() const { return 5 * s; }
    void draw() const {
        cout << "Drawing " << color << " pentagon " << name << "\n";
        cout << " ⬟\n";
        cout << "⬟⬟⬟\n";
    }
    void getDetails() const {
        cout << color << " Pentagon Side: " << s << " Area: " << area() << "\n";
    }
};

class ShapeManager {
    Shape* arr[50];
    int count;
public:
    ShapeManager() : count(0) {}

    void addShape(Shape* s) { if (count < 50) arr[count++] = s; }

    void sortByArea() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (*arr[j] < *arr[j + 1]) {
                    Shape* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    Shape* largestArea() {
        if (count == 0) return 0;
        Shape* big = arr[0];
        for (int i = 1; i < count; i++) {
            if (*big < *arr[i]) big = arr[i];
        }
        return big;
    }

    void showAll() {
        for (int i = 0; i < count; i++) {
            arr[i]->draw();
            cout << "Area: " << arr[i]->area() << " Perimeter: " << arr[i]->perimeter() << "\n";
            arr[i]->getDetails();
            cout << "\n";
        }
    }
};

int main() {
    ShapeManager m;

    try {
        m.addShape(new Circle("Red", "C1", 5));
        m.addShape(new Rectangle("Blue", "R1", 6, 3));
        m.addShape(new Triangle("Green", "T1", 3, 4, 5));
        m.addShape(new Pentagon("Purple", "P1", 4));
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    m.sortByArea();
    m.showAll();

    cout << "Largest:\n";
    Shape* L = m.largestArea();
    if (L) L->getDetails();
}
