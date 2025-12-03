#include <iostream>
using namespace std;
struct employee;

struct employee{
    string name;
    int id;
    int salary;
};

int main(){
    employee emp1, *p_emp;
    p_emp=&emp1;
    
    cout<<"Enter employee name: ";
    cin>>p_emp->name;
    cout<<"Enter employee ID: ";
    cin>>p_emp->id;
    cout<<"Enter employee salary: ";
    cin>>p_emp->salary;
    
    cout<<"\nEmployee details:\n";
    cout<<"Name: "<<p_emp->name;
    cout<<"\nID: "<<p_emp->id;
    cout<<"\nSalary: "<<p_emp->salary;
}