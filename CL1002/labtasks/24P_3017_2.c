#include <stdio.h>

int main ()
{
	//Declaration of total marks, total percentage, student's percentage and section
	int tm = 100;
	float tp, sp;
	tp = 100;
	char sec;
	
	//Printing total marks and percentage
	printf("Total Marks are %d and total percentage is %.1f\n", tm, tp);
	
	//Scanning and printing student's percentage
	printf("Enter the student's percentage: ");
	scanf("%f", &sp);
	printf("The student obtained %f percent marks\n", sp);
	
	//Scanning and Printing student's section
	printf("What section is the student from? ");
	scanf(" %c", &sec); 
	printf("And they are from section: %c\n", sec);
	
	return 0;
}
