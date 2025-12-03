#include<iostream>
using namespace std;

class engine{
    public:
    void start(){
        cout<<"Engine started."<<endl;
    }
};

class car{
    engine e;                           //composition between car and engine
    public:
    void car_start(){
        e.start();
        cout<<"Car started.";
    }
};

class employee{
    protected:
    string name;
    int id;
    int days_worked;
    int salary;
    public:
    employee(string n, int aidee): name(n), id(aidee){}
    virtual void calculate_bonus(){}
    void show_salary(){
        cout<<"Rs "<<salary<<endl;
    }
};

class manager: public employee{
    public:
    manager(string n, int aidee): employee(n, aidee){
        salary=80000;
        days_worked=20;
        manager::calculate_bonus();
    }
    void calculate_bonus() override{
        if(days_worked>15)
        salary*=1.2;
    }
    void show_salary(){
        cout<<"\nManager's salary after bonus: ";
        employee::show_salary();
    }
};

class engineer: public employee{
    car *c;
    public:
    engineer(string n, int aidee, car *c): employee(n, aidee){
        this->c=c;
        days_worked=20;
        salary=150000;
        engineer::calculate_bonus();
    }
    void calculate_bonus() override{
        if(days_worked>15)
        salary*=1.35;
    }
    void show_salary(){
        cout<<"\nEngineer's salary after bonus: ";
        employee::show_salary();
    }
    void show_car(){
        cout<<"Engineer "<<name<<" has a car, starting car.\n";
        c->car_start();
    }
};


class department{
    employee *emp1, *emp2, *emp3;                   //aggregation between department and employees
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
        if(emp1==emp){emp1=NULL;cout<<"\nEmployee successfully removed.\n";}
        else if(emp2==emp){emp2=NULL;cout<<"\nEmployee successfully removed.\n";}
        else if(emp3==emp){emp3=NULL;cout<<"\nEmployee successfully removed.\n";}
        else
        cout<<"No such employee exists."<<endl;
    }
};

int main(){
    employee e1("Aun", 0001), e2("Saad", 0002), e3("Ali", 0003);
    department d;
    cout<<"Department created, Adding employees:\n";
    cout<<"\nAssigning employee 1 a department:";
    d.assign_emp(&e1);
    cout<<"\nAssigning employee 2 a department:";
    d.assign_emp(&e2);
    cout<<"\nAssigning employee 3 a department:";
    d.assign_emp(&e3);
    cout<<"\nRemoving employee 1 from the department:";
    d.remove_emp(&e1);

    car c1;
    manager m("Don", 0004);
    m.show_salary();
    engineer e("Saboor", 0005, &c1);
    e.show_salary();
    e.show_car();
}