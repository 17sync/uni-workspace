#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of a and b
    int a, b;
    a = 6;
    b = 9;

    //Showing initial values of a and b
    cout<<"Values of a and b before swapping:"<<"\n\n"<<"a = "<<a<<"\tb = "<<b;

    //Swapping
    a += b;
    b = a-b;
    a -= b;

    //Showing final values of a and b
    cout<<"\n\n"<<"Values of a and b after swapping:"<<"\n\n"<<"a = "<<a<<"\tb = "<<b;

}