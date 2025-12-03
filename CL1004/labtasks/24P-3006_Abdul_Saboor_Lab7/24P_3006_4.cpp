#include<iostream>
#include<cmath>
using namespace std;

class Complex{
    double real,imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){}
    double getReal(){return real;}
    double getImag(){return imag;}
    double getMagnitude(){return sqrt(real*real+imag*imag);}
    double getPhase(){return atan2(imag,real);}
    Complex getConjugate(){return Complex(real,-imag);}
    // Unary
    Complex operator+(){return *this;}
    Complex operator-(){return Complex(-real,-imag);}
    Complex operator!(){return getConjugate();}
    // Arithmetic
    Complex operator+(const Complex& c){return Complex(real+c.real,imag+c.imag);}
    Complex operator-(const Complex& c){return Complex(real-c.real,imag-c.imag);}
    Complex operator*(const Complex& c){return Complex(real*c.real - imag*c.imag, real*c.imag + imag*c.real);}
    Complex operator/(const Complex& c){
        double denom=c.real*c.real+c.imag*c.imag;
        return Complex((real*c.real + imag*c.imag)/denom,(imag*c.real - real*c.imag)/denom);
    }
    // Compound
    Complex& operator+=(const Complex& c){real+=c.real;imag+=c.imag;return *this;}
    Complex& operator-=(const Complex& c){real-=c.real;imag-=c.imag;return *this;}
    Complex& operator*=(const Complex& c){double r=real*c.real - imag*c.imag; imag=real*c.imag + imag*c.real; real=r; return *this;}
    Complex& operator/=(const Complex& c){double denom=c.real*c.real+c.imag*c.imag; double r=(real*c.real + imag*c.imag)/denom; imag=(imag*c.real - real*c.imag)/denom; real=r; return *this;}
    // Comparison by magnitude
    bool operator==(const Complex& c){return real==c.real && imag==c.imag;}
    bool operator!=(const Complex& c){return !(*this==c);}
    // Stream
    friend ostream& operator<<(ostream& os,const Complex& c){os<<c.real<<(c.imag>=0?"+":"")<<c.imag<<"i";return os;}
    friend istream& operator>>(istream& is,Complex& c){is>>c.real>>c.imag;return is;}
    // Polar
    static Complex fromPolar(double r,double theta){return Complex(r*cos(theta),r*sin(theta));}
    double getRadius(){return getMagnitude();}
    double getAngle(){return getPhase();}
    // Exponentiation
    friend Complex pow(Complex c,int n){
        double r=pow(c.getMagnitude(),n);
        double theta=c.getPhase()*n;
        return Complex(r*cos(theta),r*sin(theta));
    }
};

class ComplexCalculator{
public:
    static Complex add(Complex a,Complex b){return a+b;}
    static Complex sub(Complex a,Complex b){return a-b;}
    static Complex mul(Complex a,Complex b){return a*b;}
    static Complex div(Complex a,Complex b){return a/b;}
    static Complex pow(Complex a,int n){return pow(a,n);}
    static void showPolar(Complex c){cout<<"r="<<c.getRadius()<<" θ="<<c.getAngle()<<"\n";}
};

int main(){
    Complex a(3,4),b(1,-2);
    cout<<"a="<<a<<"\n"; cout<<"b="<<b<<"\n";
    cout<<"a+b="<<ComplexCalculator::add(a,b)<<"\n";
    cout<<"a-b="<<ComplexCalculator::sub(a,b)<<"\n";
    cout<<"a*b="<<ComplexCalculator::mul(a,b)<<"\n";
    cout<<"a/b="<<ComplexCalculator::div(a,b)<<"\n";
    cout<<"a^3="<<ComplexCalculator::pow(a,3)<<"\n";
    cout<<"Polar of a: "; ComplexCalculator::showPolar(a);
    cout<<"Conjugate of b: "<<!b<<"\n";
}
