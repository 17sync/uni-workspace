#include<iostream>
using namespace std;

class address{
    string area, city, province;
    int street_no, house_no;
    public:
    address(string a, string c, string p, int s, int h): area(a), city(c), province(p), street_no(s), house_no(h){}
    void display_address(){ 
        cout<<area<<", Street "<<street_no<<", House "<<house_no<<endl;
        cout<<city<<", "<<province<<", Pakistan";
    }
};
class student{
    address *a;
    string name, grade;
    int age;
    public:
    student(string n, string g, int age, address *a): name(n), grade(g){
        this->a=a;
        this->age=age;
    }
    void studentcredentials(){
        cout<<"Name: "<<name<<"\nAge: "<<age<<"\nGrade: "<<grade;
        cout<<"\n\nAddress:\n";
        a->display_address();
    }
};

int main(){
    address a1("RMT Zone 4", "Peshawar", "Khyper Pakhtunkhwa", 16, 286);
    student s1("Aun", "Bachelors of Software Engineering", 19, &a1);
    s1.studentcredentials();
}