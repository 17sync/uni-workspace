#include <iostream>
using namespace std;
void menu ();
void new_entry ();
void all_records ();

int main ()
{

    menu ();    //Calling menu function to display main menu
    
    int marks[10][3];
    int total[10];
    char names[10][50];
    

}

void menu ()
{

    int operation;      //Variable storing corresponding operation number as displayed

    cout<<"\t|| STUDENT DATABASE ||\n\n";       //Displaying menu
    cout<<"1. Add new student data\n2. Show all student records\n\n";
    cout<<"Select Operation: "; 
    cin>>operation;

    switch (operation){     //Calling relevant function as per selected operation      
        case 1:
            new_entry();
            break;
        case 2:
            all_records();
            break;
    }

}

void new_entry ()
{



}

void all_records (char names[10][50], int marks[10][3], int total[10])
{



}