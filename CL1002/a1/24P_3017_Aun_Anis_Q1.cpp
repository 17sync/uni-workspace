#include <iostream>
using namespace std;

int main ()
{
    
    start:
    //Declaration of all operands
    int p, r, q, w, x, y;
    
    //Displaying the subject of the program
    cout<<"\tz=pr%q+w/x-y\n\t------------";
    
    //Asking for input from user
    cout<<"\nEnter the value of p: "; cin>>p;
    cout<<"Enter the value of r: "; cin>>r;
    cout<<"Enter the value of q: "; cin>>q;
    cout<<"Enter the value of w: "; cin>>w;
    cout<<"Enter the value of x: "; cin>>x;
    cout<<"Enter the value of y: "; cin>>y;

    //Defining and displaying the value of z
    int z = p*r%q+w/x-y;
    cout<<"\nThe value of z is: "<<z;

    reset:
    //Restarting
    int reset;
    cout<<"\n\n(press 0 to calculate another value of z or press 1 to end)\n";
    cin>>reset;
    
    if (reset == 0)
    {
        goto start;
    }
    else if (reset == 1)
    {
        cout<<"\n\tProgram Ended.";
    }
    else if (reset != 0 && reset!= 1)
    {
        cout<<"\nInvalid input";
        goto reset;
    } 
}