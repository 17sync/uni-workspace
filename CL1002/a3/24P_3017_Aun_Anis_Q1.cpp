#include <iostream>
using namespace std;
bool palindromechecker (int num);

int main ()
{

    //Declaration of integer
    int num;

    //Asking user for integer
    cout<<"Enter an integer: ";
    cin>>num;

    //Calling function to check if integer is a palindrome
    if (palindromechecker(num)==true){
        cout<<"\nThe Integer is a palindrome";
    }
    else{
        cout<<"\nThe Integer is not a palindrome";
    }
     
}

bool palindromechecker (int num)
{   

    //Declaration of variable storing original number and reverse of number
    int original=num;
    int reverse=0;

    //Building reverse of number
    while (num>0){
        int digit=num%10;
        reverse=reverse*10+digit;
        num/=10;
    }

    //Comparing reverse and original to come to a conclusion
    if (reverse==original){
        return true;
    }
    else{
        return false;
    }

}