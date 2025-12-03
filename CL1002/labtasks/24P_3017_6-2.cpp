#include <iostream>
using namespace std;

int main ()
{
	//Declaration of hourly rate, hours worked and salary
	float hr, hw, salary;

	//Asking for the employee's hourly rate and hours worked
	cout<<"What is the hourly rate? ";
	cin>>hr;
	cout<<"\nHow many hours has the employee worked? ";
	cin>>hw;

	//Calculating salary
	if (hw>40)
	{
		salary = 0.8*((hr*40)+(1.5*hr*(hw-40)));
		cout<<"\nThe employee's salary after taxes and including overtime bonus is: "<<salary;
	}

	else if (hw<=40)
	{
		salary = 0.8*(hr*hw);
		cout<<"\nThe employee's salary after taxes is: "<<salary;
	}
}