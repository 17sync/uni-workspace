#include <iostream>
using namespace std;

int main ()
{
	//Declaration of selection
	int selection, quantity;

	//Showing menu to user
	cout<<"\tMENU:";
	cout<<"\n\n1. Espresso - $2.50\n\n2. Latte - 3.00$\n\n3. Cappuccino - $3.50\n\n4. Mocha - $4.00\n\n5. Americano - $2.25";
	cout<<"\n\nWhat would you like? ";
	cin>>selection;
	cout<<"How many? ";
	cin>>quantity;

	//Summing bill of the user
	switch (selection)
	{
		case 1:
			cout<<"\nYou have chosen "<<quantity<<" Espresso, your total bill is: $"<<2.50*quantity;
			cout<<"\nEnjoy your coffee!";
			break;
		case 2:
			cout<<"\nYou have chosen "<<quantity<<" Latte, your total bill is: $"<<3.00*quantity;
			cout<<"\nEnjoy your coffee!";
			break;
		case 3:
			cout<<"\nYou have chosen "<<quantity<<" Cappuccino, your total bill is: $"<<3.50*quantity;
			cout<<"\nEnjoy your coffee!";
			break;
		case 4:
			cout<<"\nYou have chosen "<<quantity<<" Mocha, your total bill is: $"<<4.00*quantity;
			cout<<"\nEnjoy your coffee!";
			break;
		case 5:
			cout<<"You have chosen "<<quantity<<" Americano, your total bill is: $"<<2.25*quantity;
			cout<<"\nEnjoy your coffee!";
			break;
		default:
			cout<<"\nInvalid number";
			break;
	}

}