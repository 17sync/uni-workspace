#include <iostream>
using namespace std;

int main ()
{

    //Declaration of array for storing sales and variable for sum 
    int sales[7];
    int sum = 0;
    int num = 1;

    //Asking for sales on each day
    for (int i =0; i<7; i++){
        cout<<"Enter the sales for day "<<num<<": $";
        cin>>sales[i];
        num++;
        sum+=sales[i];
    }

    //Displaying total sales for the week
    cout<<"\nTotal sales for the week: $"<<sum;
    
}