#include<iostream>
using namespace std;

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
    int rate;
    int worked;
    int gross;
    int net;
};

void calcSalary(Employee *e){
    for(int i=0;i<5;i++){
        e[i].gross=e[i].rate*e[i].worked;
        e[i].net=e[i].gross*0.8;
    }
}

void printPayRoll(Employee *e){
    for(int i=0;i<5;i++){
        cout<<e[i].name<<"\tGross pay: $"<<e[i].gross<<"\tNet pay: $"<<e[i].net<<endl;
    }
}

void highestPay(Employee *e){
    float highest=e[0].net;
    int index=0;
    for(int i=0;i<5;i++){
        if(e[i].net>highest){
            highest=e[i].net;
            index=i;
        }
    }

    cout<<"\nHighest paid: "<<e[index].name<<"\t$"<<highest;
}

int main(){
    Employee e[5];
    e[0]={"Employee #1", 1001, {"Street #1", "City #1", "State #1", 2500}, 21, 56};
    e[1]={"Employee #2", 1002, {"Street #2", "City #2", "State #2", 3500}, 45, 47};
    e[2]={"Employee #3", 1003, {"Street #3", "City #3", "State #3", 4500}, 34, 40};
    e[4]={"Employee #4", 1004, {"Street #4", "City #4", "State #4", 5500}, 52, 29};
    e[5]={"Employee #5", 1005, {"Street #5", "City #5", "State #5", 6500}, 17, 60};

    calcSalary(e);
    printPayRoll(e);
    highestPay(e);
}

