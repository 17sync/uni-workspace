#include <iostream>
using namespace std;

int main ()
{

    //Declaration of variables for all three numbers 
    int n1, n2, n3;

    //Asking user to input three numbers
    cout<<"Enter three numbers: "; 
    cin>>n1>>n2>>n3; 

    //Checking and displaying largest number
    if (n1>n2 && n1>n3)
    {
        cout<<"\n"<<n1<<" is the largest.";
    }
    else if (n2>n1 && n2>n3)
    {
        cout<<"\n"<<n2<<" is the largest.";
    }
    else if (n3>n2 && n3>n1)
    {
        cout<<"\n"<<n3<<" is the largest.";
    }

}