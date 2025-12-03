#include <iostream>
using namespace std;

int main ()
{

    //Declaration of variable storing month number
    int month;

    //Asking for month number from user
    cout<<"Enter month number [eg: 1 (January), 2 (February)]: ";
    cin>>month;

    //Checking season based on month number
    switch (month)
    {
        case 1:
            cout<<"\nWinter";
            break;
        case 2:
            cout<<"\nWinter";
            break;
        case 12:
            cout<<"\nWinter";
            break;
        case 3:
            cout<<"\nSpring";
            break;
        case 4:
            cout<<"\nSpring";
            break;
        case 5:
            cout<<"\nSpring";
            break;
        case 6:
            cout<<"\nSummer";
            break;
        case 7:
            cout<<"\nSummer";
            break;
        case 8:
            cout<<"\nSummer";
            break;
        case 9:
            cout<<"\nAutumn";
            break;
        case 10:
            cout<<"\nAutumn";
            break;
        case 11:
            cout<<"\nAutumn";
            break;
        default:
            cout<<"\nInvalid month number";
    }
}