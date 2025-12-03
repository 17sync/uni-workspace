#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of a and b
    int a,b;
    a = 10;
    b = 5;

    //Showing output with assignment operations
    a *= b;
    cout<<"a: 10 | b: 5 | "<<"a*=b : "<<a<<" | a is now: "<<a<<"\n";
    a /= b;
    cout<<"a: 10 | b: 5 | "<<"a/=b : "<<a<<" | a is now: "<<a<<"\n";
    a %= b;
    cout<<"a: 10 | b: 5 | "<<"a%=b : "<<a<<" | a is now: "<<a<<"\n";
    a = 10;
    a *= b+10;
    cout<<"a: 10 | b: 5 | "<<"a*=b+10 : "<<a<<" | a is now: "<<a<<"\n";

}