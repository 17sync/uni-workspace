#include <iostream>
using namespace std;

int main()
{

    //Declaration of year and checking variable
    int year, check;

    //Asking for year
    cout<<"Enter a year...\n";
    cin>>year;

    //Determining if the year is a leap year
    check = ((year%4==0 && year%100!=0)||year%400==0?1:0);
    cout<<"\nThe year is a leap year: "<<check;
    cout<<"\n(1 = yes, 0 = no)";

}