#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void create(string file_name);
void write(string file_name, string name, string rollno, string hobbies);
void append(string file_name, int array[]);

int main ()
{
    
    string file_name;       //Variable storing name of the file

    cout<<"Enter the name of the file to be created: ";     //Asking for file name from user
    cin>>file_name;

    create(file_name);      //Calling relevant function to create file

    string name, rollno, hobbies;       //Variables storing name, roll# and hobbies

    cout<<"Enter your name: ";          //Asking for relevant information from user
    cin>>name;
    cout<<"Enter your roll #: ";
    cin>>rollno;
    cout<<"Mention some hobbies: ";
    cin>>hobbies;

    write(file_name, name, rollno, hobbies);       //Calling relevant function to write to the file

    int age[1];
    cout<<"Enter your age: ";
    cin>>age[0];

    append(file_name, age);

}

void create(string file_name)
{

    ofstream outfile(file_name);        //Opening the file

    if(outfile.is_open()){      //Checking if file is open
        cout<<"File created successfully!"<<endl;
    }
    else{
        cerr<<"Failed to create file."<<endl;
    }

    outfile.close();        //Closing the file

}

void write(string file_name, string name, string rollno, string hobbies)
{

    ofstream outfile(file_name);

    outfile<<"Name: "<<name<<"\nRoll_no: "<<rollno<<"\nHobbies: "<<hobbies;         //Writing to the file
    
    outfile.close();

}

void append(string file_name, int array[])
{

    ofstream outfile(file_name, ios::app);
    outfile<<"\nAge: "<<*array;

}