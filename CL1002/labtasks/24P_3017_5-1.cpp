#include <iostream>
using namespace std;

int main()
{
    
    //Declaration of checking variable and integer
    int num1, check, check2, check3;
    
    //Running checks on the integer
    cout<<"Enter an integer... "<<"\n";
    cin>>num1;
    check = (num1>=10 && num1<=20);
    cout<<"\n"<<"number is greater or equal to 10 and less than and equal to 20: "<<check<<"\n\n";
    check2 = (num1>20 || num1<10);
    cout<<"number is greater than 20 or less than 10: "<<check2<<"\n\n";
    check3 = (num1!=15);
    cout<<"The number is not equal to 15: "<<check3<<endl;

}