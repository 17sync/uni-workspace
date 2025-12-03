#include <iostream>
using namespace std;

int main ()
{

    //Declaration of array for 5 numbers and variable for sum
    int num[5];
    int sum = 0;
    int count = 1;

    //Asking for 5 numbers
    for (int i =0; i<5; i++){
    cout<<"Enter integer #"<<count<<": ";
    cin>>num[i];
    count++;
    sum+=num[i];
    }
     //Displaying sum
     cout<<"\nThe sum of the integers is: "<<sum;

}