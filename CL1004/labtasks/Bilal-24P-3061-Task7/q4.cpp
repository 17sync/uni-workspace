#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    double getMagnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    double getPhase() const {
        return atan2(imaginary, real);
    }

    Complex getConjugate() const {
        return Complex(real, -imaginary);
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    Complex operator*(const Complex& c) const {
        double r = real * c.real - imaginary * c.imaginary;
        double i = real * c.imaginary + imaginary * c.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& c) const {
        double d = c.real * c.real + c.imaginary * c.imaginary;
        double r = (real * c.real + imaginary * c.imaginary) / d;
        double i = (imaginary * c.real - real * c.imaginary) / d;
        return Complex(r, i);
    }

    bool operator==(const Complex& c) const {
        return real == c.real && imaginary == c.imaginary;
    }

    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }

    bool operator<(const Complex& c) const {
        return getMagnitude() < c.getMagnitude();
    }

    bool operator>(const Complex& c) const {
        return getMagnitude() > c.getMagnitude();
    }

    Complex operator+() const {
        return *this;
    }

    Complex operator-() const {
        return Complex(-real, -imaginary);
    }

    Complex operator!() const {
        return getConjugate();
    }

    Complex& operator+=(const Complex& c) {
        real += c.real;
        imaginary += c.imaginary;
        return *this;
    }

    Complex& operator-=(const Complex& c) {
        real -= c.real;
        imaginary -= c.imaginary;
        return *this;
    }

    Complex& operator*=(const Complex& c) {
        double r = real * c.real - imaginary * c.imaginary;
        double i = real * c.imaginary + imaginary * c.real;
        real = r;
        imaginary = i;
        return *this;
    }

    Complex& operator/=(const Complex& c) {
        double d = c.real * c.real + c.imaginary * c.imaginary;
        double r = (real * c.real + imaginary * c.imaginary) / d;
        double i = (imaginary * c.real - real * c.imaginary) / d;
        real = r;
        imaginary = i;
        return *this;
    }

    static Complex fromPolar(double magnitude, double angle) {
        double r = magnitude * cos(angle);
        double i = magnitude * sin(angle);
        return Complex(r, i);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        if (c.imaginary >= 0)
            out << c.real << " + " << c.imaginary << "i";
        else
            out << c.real << " - " << -c.imaginary << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imaginary;
        return in;
    }

    friend Complex pow(const Complex& c, int n) {
        if (n == 0) return Complex(1, 0);
        Complex result = c;
        for (int i = 1; i < n; i++)
            result *= c;
        return result;
    }
};

class ComplexCalculator {
public:
    static void showOperations(const Complex& a, const Complex& b) {
        cout << "Complex Number 1: " << a << endl;
        cout << "Complex Number 2: " << b << endl;
        cout << "Addition: " << a << " + " << b << " = " << (a + b) << endl;
        cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << endl;
        cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << endl;
        cout << "Division: " << a << " / " << b << " = " << (a / b) << endl;
        cout << "Magnitude of A: " << a.getMagnitude() << endl;
        cout << "Phase of A (radians): " << a.getPhase() << endl;
        cout << "Conjugate of A: " << !a << endl;
        cout << "A^2: " << pow(a, 2) << endl;
    }
};

int main() {
    Complex a(3, 4);
    Complex b(1, 2);

    ComplexCalculator::showOperations(a, b);

    return 0;
}
