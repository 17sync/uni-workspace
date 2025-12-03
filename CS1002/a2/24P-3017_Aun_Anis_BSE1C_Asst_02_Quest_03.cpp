#include <iostream>
using namespace std;

int main ()
{

    //Declaration of daily expense and number of weeks
    float de;                                           //taken as float as in some currencies decimal values exist
    int weeks;

    //Asking for the daily expense and numbers of weeks
    cout<<"Enter your daily expenses: ";
    cin>>de;
    cout<<"Enter the number of weeks: ";
    cin>>weeks;

    //Declaration and definition of total expenses
    float te = de*7*weeks;

    //Displaying total expenses
    cout<<"\nYour total expenses for the specified time period are: "<<te;

}