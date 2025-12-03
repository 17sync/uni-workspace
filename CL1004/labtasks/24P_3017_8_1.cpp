#include<iostream>
using namespace std;

class person{
    public:
    string name;
    string address;
    
    person(){
        cout<<"\n\nEnter employee name: ";
        cin>>name;
        cout<<"Enter employee address: ";
        cin>>address;
    }
};

class employee: public person{
    public:
    int emp_num;
    int hours_worked;

    employee(){
        cout<<"Enter employee id number: ";
        cin>>emp_num;
        cout<<"Enter hours worked: ";
        cin>>hours_worked;
    }
};

class production_worker: public employee{
    public:
    static int count;
    int shift;
    double hpr;
    double salary;

    production_worker(int shift=0, double salary=0, double hpr=0){
        this->shift=shift;
        this->hpr=hpr;
        this->salary=salary;
    }

    void set_shift();
    int get_shift();
    void set_hpr();
    double get_hpr();
    void calculate_salary();
    double get_salary();
    void print_details();
};

int production_worker:: count=0;

int main(){
    production_worker w1;
    w1.calculate_salary();
    production_worker w2;
    w2.calculate_salary();
    w1.print_details();
    w2.print_details();
}

void production_worker:: set_shift(){
    cout<<"Select shift (1 for day, 2 for night): ";
    cin>>shift;
}

int production_worker:: get_shift(){
    return shift;
}

void production_worker:: set_hpr(){
    cout<<"Enter hourly pay rate: ";
    cin>>hpr;
}

double production_worker:: get_hpr(){
    return hpr;
}

double production_worker:: get_salary(){
    return salary;
}

void production_worker:: calculate_salary(){
    set_shift();
    set_hpr();
    salary=hpr*hours_worked;

    if(shift==2 && hours_worked>5){
        salary+=1000;
    }
}

void production_worker:: print_details(){
    count++;
    cout<<"\n\nDetails of employee #"<<count<<":\n";
    cout<<"Name: "<<name<<"\nAddress: "<<address<<"\nID: "<<emp_num<<"\nHours worked: "<<hours_worked;
    if(shift==1){
        cout<<"\nShift: Day";
    }
    else if(shift==2){
        cout<<"\nShift: Night";
    }
    cout<<"\nHourly pay rate: "<<hpr;
    cout<<"\nSalary: $"<<get_salary();
}