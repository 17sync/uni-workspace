#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of variables storing numerators and denominators
    int a, b;
    int c, d;
    char slash;   

    //Displaying subject of the program
    cout<<"\n\n\tSum of 2 Fractions\n\t------------------";

    //Asking for values of numerators and denominators
    cout<<"\nEnter first fraction: "; cin>>a>>slash>>b;
    cout<<"Enter second fraction: "; cin>>c>>slash>>d;

    //Displaying summation
    int numerator, denominator;
    numerator = (a*d)+(b*c);
    denominator = b*d;
    if (numerator == denominator)
    {
        cout<<"\nSum = 1";
    }
    else
    {
        cout<<"\nSum = "<<numerator<<"/"<<denominator;
    }
    
}