#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{

    //Declaration of subjects
    int maths, physics, chemistry, english, urdu;
    float percentage;
    string name;

    //Asking for student credentials and marks obtained in each subject
    cout<<"What is the name of the student? ";
    cin>>name;
    cout<<"Enter marks obtained in Maths (out of 100): ";
    cin>>maths;
    cout<<"Enter marks obtained in Physics (out of 100): ";
    cin>>physics;
    cout<<"Enter marks obtained in Chemistry (out of 100): ";
    cin>>chemistry;
    cout<<"Enter marks obtained in English (out of 100): ";
    cin>>english;
    cout<<"Enter marks obtained in Urdu (out of 100): ";
    cin>>urdu;
    cout<<"\n\n";

    //Defining percentage
    int total = maths+physics+chemistry+english+urdu;
    percentage = (total/500.0)*100;
    
    //Generating marksheet
    cout<<"Name: "<<name;
    cout<<"\n"<<setw(20)<<"MARKSHEET"<<endl;
    cout<<setfill('-')<<setw(32)<<"-";
    cout<<"\nMaths"<<setfill(' ')<<setw(11)<<"|"<<setw(16)<<maths;
    cout<<"\nPhysics"<<setfill(' ')<<setw(9)<<"|"<<setw(16)<<physics;
    cout<<"\nChemistry"<<setfill(' ')<<setw(7)<<"|"<<setw(16)<<chemistry;
    cout<<"\nEnglish"<<setfill(' ')<<setw(9)<<"|"<<setw(16)<<english;
    cout<<"\nUrdu"<<setfill(' ')<<setw(12)<<"|"<<setw(16)<<urdu;

    //Displaying percentage
    if (percentage<40)
    {
        cout<<"\npercentage = "<<percentage<<"% (FAILED)";
    }
    else if (percentage>=75)
    {
        cout<<"\npercentage = "<<percentage<<"% (DISTINCTION)";
    }
    else if (percentage>=60 && percentage<75)
    {
        cout<<"\npercentage = "<<percentage<<"% (FIRST DIVISION)";   
    }
    else if (percentage>=50 && percentage<60)
    {
        cout<<"\npercentage = "<<percentage<<"% (SECOND DIVISION)";
    }
    else if (percentage>=40 && percentage<50)
    {
        cout<<"\npercentage = "<<percentage<<"% (THIRD DIVISION)";
    }
    else
    {
        cout<<"\npercentage = "<<percentage<<"% (INVALID MARKS ENTERED)";
    }

    //Repeating year condition
    if ((maths<50||physics<50||chemistry<50||english<50||urdu<50) && (maths<50||physics<50||chemistry<50||english<50||urdu<50))
    {
        cout<<"\n\nRepeat the year.";
    }
    
}