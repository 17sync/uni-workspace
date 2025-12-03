#include <iostream>
using namespace std;

float totalrent (int days, float miles);

int main ()
{

    //Declaration of variables storing days rented and miles driven
    int days;
    float miles;

    //Asking of days rented and miles driven
    cout<<"Enter the number of days the car was rented for: ";
    cin>>days;
    cout<<"Enter the number of miles driven in the stated time period: ";
    cin>>miles;

    //Calling function to calculate the total rent and displaying the final rent
    cout<<"\nYour total rent is: $"<<totalrent(days, miles);

}

float totalrent (int days, float miles)
{
    float total = (25.00*days)+(0.15*miles);
    
    if (days>30){
        total*=0.7;
    }
    else if (days<15){
        total = (26.99*days)+(0.15*miles);
    }

    return total;
}