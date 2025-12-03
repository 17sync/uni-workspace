#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of three digit number
    int tdn;

    //Declaration of seperate variables for each digit
    int units, tens, hundreds;

    //Asking for three digit number
    cout<<"Enter three digit number for reversal...\n";
    cin>>tdn;

    //Reversing the three digit number
    units = tdn%10;
    tdn /= 10;
    tens = tdn%10;
    tdn /= 10;
    hundreds = tdn%10;
    tdn /= 10;
    tdn = (units*100)+(tens*10)+(hundreds*1);

    //Displaying the reveresed three digit number
    cout<<tdn;
    
}