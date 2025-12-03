#include <iostream>
using namespace std;

int main ()
{

	//Declaration of age
	int age;

	//Asking for age
	cout<<"What is your age? ";
	cin>>age;
	
	//Evalutating if user is eligible for voting
	if(age>0)
	{
		switch (age>=18)
		{
			case 1:
				cout<<"you are eligible to vote";
				break;
			default:
				cout<<"you are not eligible to vote";
		}

	}
	else
	{
		cout<<"Invalid number";
	}

}