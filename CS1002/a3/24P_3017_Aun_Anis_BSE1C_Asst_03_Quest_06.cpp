#include <iostream>
using namespace std;

int main ()
{
    //Declaration of variable storing units and bill
    int unit, bill;

    //Asking for units from user
    cout<<"Enter units used: ";
    cin>>unit;

    //Calculating bill
    if (unit<=100)
    {
        bill = unit*5;
        cout<<"\nYour bill is: Rs."<<bill;
    }
    else if (unit>100 && unit<=200)
    {
        bill = (100*5)+((unit-100)*7);
        cout<<"\nYour bill is: Rs."<<bill;
    }
    else if (unit>200)
    {
        bill = (100*5)+(100*7)+((unit-200)*10);
        cout<<"\nYour bill is: Rs."<<bill;
    }
    
}