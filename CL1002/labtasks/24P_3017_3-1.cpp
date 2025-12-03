#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of operands and operations
    int a, b, add, sub, multi;
    float mod, div;

    //Scanning for operands
    cout<<"What is the value of a? ";
    cin>>a;
    cout<<"\nWhat is the value of b? ";
    cin>>b;

    //Defining operations
    add = a+b;
    sub = a-b;
    multi = a*b;
    div = float (a/b);
    mod = float (a%b);

    //Showing operations on the terminal
    cout<<"Addition: "<<add<<"\n";
    cout<<"Subtraction: "<<sub<<"\n";
    cout<<"Multiplication: "<<multi<<"\n";
    cout<<"Division: "<<div<<"\n";
    cout<<"Modulous: "<<mod<<"\n";

}