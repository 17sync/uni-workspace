#include <iostream>
using namespace std;
int total_cost (int days, int miles);

int main ()
{

    int days, miles;    //Variables storing miles driven and days used

    cout<<"Days: ";     
    cin>>days;          
    cout<<"Miles driven: ";      //Asking for days and miles from user
    cin>>miles;
    cout<<"Total cost: $"<<total_cost (days, miles);    //Calling function to calculate total cost

}

int total_cost (int days, int miles)
{

    int total = (25*days)+(0.15*miles);      //Variable storing total cost 

    if (days>30){
        total*=0.8;
    }
    else if (days<15){
        total = (26.99*days)+(0.15*miles);
    }

    return total;

}