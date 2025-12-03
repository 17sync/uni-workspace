#include <iostream>
using namespace std;

void attendance (int attended, int total);

int main()
{

    //Declaration of variables storing attended classes and total classes
    int attended, total;

    //Asking for classes attended and scheduled
    cout<<"Enter the number of classes scheduled by the relevant instructor: ";
    cin>>total;
    cout<<"Enter the number of classes you attended: ";
    cin>>attended;

    //Calling function to calulcate attendance and check if student may proceed
    attendance(attended, total);

}

void attendance (int attended, int total)
{
    float percentage = ((float)attended/(float)total)*100;
    cout<<"\nYour attendance is: "<<percentage<<"%";
    
    if(percentage>=80){
        cout<<"\nYou may attempt the final exams.";
    }
    else{
        cout<<"\nYou are not allowed to sit in the finals!";
    }
}