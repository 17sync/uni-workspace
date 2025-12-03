#include <iostream>
using namespace std;
struct student;
void get_students(student*, int);
void display_students(student*, int);

struct student{
    string name;
    int roll;
    int marks;
};

int main(){
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    student *s=new student[n];
    
    get_students(s, n);
    cout<<endl;
    display_students(s, n);

    delete[]s;
    s=NULL;
}

void get_students(student *s, int n){
    cout<<"\nEnter details: ";
    int counter=1;
    for(int i=0;i<n;i++){
        cout<<"\n\nStudent #"<<counter;
        cout<<"\nEnter name: ";
        cin>>s[i].name;
        cout<<"Enter roll#: ";
        cin>>s[i].roll;
        cout<<"Enter marks: ";
        cin>>s[i].marks;
        counter++;
    }
}

void display_students(student *s, int n){
    cout<<"\nStudent details: ";
    int counter=1;
    for(int i=0;i<n;i++){
        cout<<"\n\nStudent #"<<counter;
        cout<<"\nName: "<<s[i].name;
        cout<<"\nRoll#: "<<s[i].roll;
        cout<<"\nMarks: "<<s[i].marks;
        counter++;
    }
}