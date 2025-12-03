#include <iostream>
using namespace std;

int main ()
{

    //Declaration of a,b and c
    int a, b, c;
    a = 20;
    b = 22;
    c = 30;

    //Declaration of PI
    float PI;
    PI = 3.142;

    //Showing initial values of a,b and c
    cout<<"Initial values of the variables:"<<"\n\n";
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<"\n\n\n";

    //Declaration of operations x and y
    int x = a*4+b/2-c*b-(++a);
    int y = (--a*(3+b)/2-c++*b/PI);

    //Showing output of operations with a, b and c 
    cout<<"Value of a*4+b/2-c*b-(++a): "<<x<<"\n\n";
    cout<<"Value of --a*(3+b)/2-c++*b/PI: "<<y<<"\n\n";
    cout<<"Value of PI*c-(x+(++y))/a*b*a*b(-(++c)): "<<int (PI*c-(x+(++y))/a*b*a*b*(-(++c)))<<"\n\n";

    //Showing final values of variables
    cout<<"Values of the variables are now:"<<"\n\n"<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;      

}