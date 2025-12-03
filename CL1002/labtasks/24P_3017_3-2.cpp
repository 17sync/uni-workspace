#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of operands and operation
    int a,b;
    float formula;
    
    //Scanning for operands
    cout<<"What is the value of a? ";
    cin>>a;
    cout<<"\nWhat is the value of b? ";
    cin>>b;

    //Defining formula
    formula = a^3-b^3-3*a*b*(a-b);

    //Showing output on terminal
    cout<<"\n"<<"("<<a<<"-"<<b<<")^3"<<" = "<<a<<"^3-"<<b<<"^3-3*"<<a<<"*"<<b<<"*"<<"("<<a<<"-"<<b<<")"<<" = "<<formula<<endl; 

}