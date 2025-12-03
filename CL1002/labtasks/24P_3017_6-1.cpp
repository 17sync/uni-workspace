#include <iostream>
using namespace std;

int main ()
{
	//Declaration of number
	int num;

	//Asking for number 
	cout<<"Enter a number...\n";
	cin>>num;

	//Checking for even or odd
	if (num%2 == 0)
	{
		cout<<"The number is even";
	}

	else 
	{
		cout<<"The number is odd";
	}
}