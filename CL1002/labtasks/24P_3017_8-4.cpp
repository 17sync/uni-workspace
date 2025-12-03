#include <iostream>
using namespace std;

int main ()
{

    //Declaration of prime, odd and even number
    int prime, odd, even;
    odd = 0;
    even = 0;
    prime = 0;

    //Counter for even and odd numbers between 1 and 20
    for (int i=1; i>=1 && i<=20; i++)
    {
        if (i%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    //Counter for prime numbers between 1 and 20
    for (int i=2; i>=1 && i<=20; i++)               //starting count from 2 since a prime number must be larger than 1
    {
        if (i%2!=0 && i%3!=0)
        {
            prime++;
        }
        else if (i == 2)
        {
            prime++;
        }
        else if (i == 3)
        {
            prime++;
        }
    }

    //Displaying number of even, odd and prime numbers between 1 and 20
    cout<<"Even numbers: "<<even<<"\nOdd numbers: "<<odd<<"\nPrime numbers: "<<prime;

}