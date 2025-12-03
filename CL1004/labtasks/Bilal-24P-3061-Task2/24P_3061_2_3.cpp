#include<iostream>
using namespace std;

const int totalEmployees=3;

struct Address{
    string street;
    string city;
    string state;
    int zipCode;
};

struct Employee{
    string name;
    int id;
    Address address;
    float hourlyRate;
    float hoursWorked;
    float grossPay;
    float netPay;
}e[totalEmployees];

void calculatePay(Employee*);
void displayPayRoll(Employee*);
void findHighestPay(Employee*);

int main(){
    e[0]={"Bilal Malik", 3061, {"Johar Town", "Lahore", "Punjab", 42000}, 35.5, 56};
    e[1]={"Abdul Saboor", 3006, {"Gulbahar", "Peshawar", "KPK", 25000}, 32.5, 47};
    e[2]={"Ahmad Ali Shah", 3075, {"City Housing", "Jhelum", "Punjab", 51000}, 38.75, 42};

    calculatePay(e);
    displayPayRoll(e);
    findHighestPay(e);
}

void calculatePay(Employee *e){
    for(int i=0;i<totalEmployees;i++){
        e[i].grossPay=e[i].hourlyRate*e[i].hoursWorked;
        e[i].netPay=e[i].grossPay*0.8;
    }
}

void displayPayRoll(Employee *e){
    cout<<"\nEmployee Payroll:\n";
    for(int i=0;i<totalEmployees;i++){
        cout<<e[i].name<<"\tGross pay: $"<<e[i].grossPay<<"\tNet pay: $"<<e[i].netPay<<endl;
    }
}

void findHighestPay(Employee *e){
    float highestPay=e[0].netPay;
    int indexHP=0;
    for(int i=0;i<totalEmployees;i++){
        if(e[i].netPay>highestPay){
            highestPay=e[i].netPay;
            indexHP=i;
        }
    }

    cout<<"\nHighest paid employee: "<<e[indexHP].name<<"\t$"<<highestPay;
}