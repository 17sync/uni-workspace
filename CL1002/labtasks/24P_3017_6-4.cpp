#include <iostream>
using namespace std;

int main ()
{
	//Declaration of credit score and income per annum
	int cs, income;

	//Asking for credit score
	cout<<"Enter your credit score: ";
	cin>>cs;

	//Checking for loan eligibility
	if (cs>=700)
	{
		cout<<"\nWhat is your income per annum? ";
		cin>>income;

		if(income>=50000)
		{
			cout<<"\nYour loan is approved";
		}
		else
		{
			cout<<"\nYou are not eligible for loan";
		}
	}

	else 
	{
		cout<<"\nYou are not eligible for loan";
	}
}