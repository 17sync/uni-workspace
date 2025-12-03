#include <iostream>
using namespace std;

int main ()
{

	//Declaration of student's score
	int score;

	//Asking for score
	cout<<"Enter the Student's score...\n";
	cin>>score;

	//Assigning grades to the Student
	if (0<=score && score<=100)
	{
		if (score>=90)
		{		
			cout<<"The Student's grade is: A+";
		}
	
		else if (80<=score && score<=89)
		{
			cout<<"The Student's grade is: A";
		}

		else if (70<=score && score<=79)
		{
			cout<<"The Student's grade is: B";
		}

		else if (60<=score && score<=69)
		{
			cout<<"The Student's grade is: C";
		}

		else if (50<=score && score<=59)
		{
			cout<<"The Student's grade is: D";
		}

		else if (score<50)
		{
			cout<<"The Student's grade is: F";
		}	
	}

	else
	{
		cout<<"Invalid score";
	}

}