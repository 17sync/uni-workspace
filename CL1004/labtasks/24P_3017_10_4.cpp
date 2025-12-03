#include<iostream>
using namespace std;

class employee{
    string name;
    int id;
    public:
    employee(string n, int aidee): name(n), id(aidee){}
};

class department{
    employee *emp1, *emp2, *emp3;
    public:
    department(){
        emp1=NULL;emp2=NULL;emp3=NULL;
    }
    void assign_emp(employee *emp){
        if(emp1==NULL){emp1=emp;cout<<"\nEmployee successfully assigned.";}
        else if(emp2==NULL){emp2=emp;cout<<"\nEmployee successfully assigned.";}
        else if(emp3==NULL){emp3=emp;cout<<"\nEmployee successfully assigned.";}
        else
        cout<<"No vacany available."<<endl;
    }
    void remove_emp(employee *emp){
        if(emp1==emp){emp1=NULL;cout<<"\nEmployee successfully removed.";}
        else if(emp2==emp){emp2=NULL;cout<<"\nEmployee successfully removed.";}
        else if(emp3==emp){emp3=NULL;cout<<"\nEmployee successfully removed.";}
        else
        cout<<"No such employee exists."<<endl;
    }
};

int main(){
    employee e1("Aun", 0001), e2("Saad", 0002), e3("Ali", 0003);
    department d;
    cout<<"\nAssigning employee 1 a department:";
    d.assign_emp(&e1);
    cout<<"\nAssigning employee 2 a department:";
    d.assign_emp(&e2);
    cout<<"\nAssigning employee 3 a department:";
    d.assign_emp(&e3);
    cout<<"\nRemoving employee 1 from the department:";
    d.remove_emp(&e1);
}