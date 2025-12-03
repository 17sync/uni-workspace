#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of year and checking variable
    int year;

    //Asking for year
    cout<<"Enter a year...\n";
    cin>>year;

    //Checking if year is a leap year
    if (year%4==0 || year%400==0)
    {
        cout<<"\n"<<year<<" is a leap year.";
    }
    else
    {
        cout<<"\n"<<year<<"is not a leap year.";
    }

}