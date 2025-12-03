#include <iostream>
using namespace std;

int main ()
{   
     //Declaration of numbers and check variable
    int num1, num2, num3, check;

    //Asking for 3 Integers
    cout<<"Input the first number: ";
    cin>>num1;
    cout<<"\nInput the second number: ";
    cin>>num2;
    cout<<"\nInput the third number: ";
    cin>>num3;

    //Checking which one is largest
    check = (num1>num2 && num1>num3?num1 : num2>num1 && num2>num3?num2 : num3);
    cout<<"\nThe largest number is: "<<check; 

}