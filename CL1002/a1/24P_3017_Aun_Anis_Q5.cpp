#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    //Declaration of pounds, shillings, pence and decimal pounds
    int old_p, shillings, pence;
    float new_p;

    //Displaying subject of program
    cout<<"\tOld to New British Currency Converter\n\t-------------------------------------";

    //Asking for old values
    cout<<"\nEnter pounds: "; cin>>old_p;
    cout<<"Enter shillings: "; cin>>shillings;
    cout<<"Enter pence: "; cin>>pence;

    //Calculating decimal pound
    new_p = old_p + (shillings/20.0) + (pence/240.0);
    
    //Displaying decimal pound
    cout<<fixed<<setprecision(2);
    cout<<"\nDecimal pounds = "<<new_p;
}