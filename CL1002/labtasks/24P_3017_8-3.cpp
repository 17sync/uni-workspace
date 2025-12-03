#include <iostream>
using namespace std;

int main ()
{   
    
    //Declaration of repition variable
    char rerun;

    //Power calcualtion loop
    do
    {   
        //Declaration of base, exponent and power
        int base, exponent, power;
        power = 1;

        //Asking for base and exponent
        cout<<"Enter the base number: ";
        cin>>base;
        cout<<"Enter the exponent number: ";
        cin>>exponent;

        for (int i = 0; i != exponent; i++)
        {
            power *= base;
        }

        cout<<"The power is: "<<power;
        rr:
        cout<<"\nDo you want to calculate another power? (Y/N): ";
        cin>>rerun;
        if (rerun == 'n' || rerun == 'N')
        {
            cout<<"Program ended.";
        }
        else if ((rerun != 'y' && rerun != 'Y') && (rerun != 'n' && rerun != 'N'))
        {
            cout<<"Invalid response."<<endl;
            goto rr;
        }  
    }
    while (rerun == 'y' || rerun == 'Y');

}