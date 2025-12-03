#include<iostream>
#include<string>
using namespace std;

class Employee{
protected:
    string name,department,hireDate;
    int id;
public:
    Employee(string n,int i,string d,string h):name(n),id(i),department(d),hireDate(h){}
    virtual double calculateSalary()=0;
    virtual void giveRaise(double pct)=0;
    virtual void performanceEval()=0;
    virtual void displayInfo(){
        cout<<"ID:"<<id<<" Name:"<<name<<" Dept:"<<department<<" Hire:"<<hireDate<<" Salary:"<<calculateSalary()<<"\n";
    }
    string getName(){return name;}
    string getDept(){return department;}
    virtual ~Employee(){}
};

class FullTimeEmployee:public Employee{
    double baseSalary,bonus;
public:
    FullTimeEmployee(string n,int i,string d,string h,double b,double bo):Employee(n,i,d,h),baseSalary(b),bonus(bo){}
    double calculateSalary(){return baseSalary+bonus;}
    void giveRaise(double pct){baseSalary+=baseSalary*pct/100;}
    void performanceEval(){cout<<name<<" FT performance: Excellent\n";}
};

class PartTimeEmployee:public Employee{
    double hourlyRate,hoursWorked;
public:
    PartTimeEmployee(string n,int i,string d,string h,double rate,double hours):Employee(n,i,d,h),hourlyRate(rate),hoursWorked(hours){}
    double calculateSalary(){return hourlyRate*hoursWorked;}
    void giveRaise(double pct){hourlyRate+=hourlyRate*pct/100;}
    void performanceEval(){cout<<name<<" PT performance: Good\n";}
};

class ContractEmployee:public Employee{
    double contractAmount;
public:
    ContractEmployee(string n,int i,string d,string h,double amt):Employee(n,i,d,h),contractAmount(amt){}
    double calculateSalary(){return contractAmount;}
    void giveRaise(double pct){contractAmount+=contractAmount*pct/100;}
    void performanceEval(){cout<<name<<" Contract performance: Satisfactory\n";}
};

class Intern:public Employee{
    double stipend;
public:
    Intern(string n,int i,string d,string h,double s):Employee(n,i,d,h),stipend(s){}
    double calculateSalary(){return stipend;}
    void giveRaise(double pct){stipend+=stipend*pct/100;}
    void performanceEval(){cout<<name<<" Intern performance: Learning phase\n";}
};

class HRSystem{
    Employee* arr[50];
    int count;
public:
    HRSystem():count(0){}
    void addEmployee(Employee* e){if(count<50)arr[count++]=e;}
    void showAll(){for(int i=0;i<count;i++){arr[i]->displayInfo();arr[i]->performanceEval();cout<<"------\n";}}
    double totalPayroll(){double sum=0;for(int i=0;i<count;i++)sum+=arr[i]->calculateSalary();return sum;}
    void giveRaiseAll(double pct){for(int i=0;i<count;i++)arr[i]->giveRaise(pct);}
    void searchByDept(string d){for(int i=0;i<count;i++)if(arr[i]->getDept()==d)arr[i]->displayInfo();}
    void searchByName(string n){for(int i=0;i<count;i++)if(arr[i]->getName()==n)arr[i]->displayInfo();}
    void reportStats(){
        int ft=0,pt=0,ct=0,intr=0;
        for(int i=0;i<count;i++){
            if(dynamic_cast<FullTimeEmployee*>(arr[i]))ft++;
            else if(dynamic_cast<PartTimeEmployee*>(arr[i]))pt++;
            else if(dynamic_cast<ContractEmployee*>(arr[i]))ct++;
            else if(dynamic_cast<Intern*>(arr[i]))intr++;
        }
        cout<<"Employee Stats: FT:"<<ft<<" PT:"<<pt<<" Contract:"<<ct<<" Intern:"<<intr<<"\n";
    }
    ~HRSystem(){for(int i=0;i<count;i++)delete arr[i];}
};

int main(){
    HRSystem hr;
    hr.addEmployee(new FullTimeEmployee("Alice",101,"IT","2021-01-10",5000,500));
    hr.addEmployee(new PartTimeEmployee("Bob",102,"HR","2022-03-15",20,120));
    hr.addEmployee(new ContractEmployee("Charlie",103,"IT","2023-05-01",3000));
    hr.addEmployee(new Intern("Diana",104,"Finance","2023-06-01",1000));

    cout<<"All Employees:\n";
    hr.showAll();

    cout<<"Total Payroll:"<<hr.totalPayroll()<<"\n";
    hr.giveRaiseAll(10);
    cout<<"After 10% Raise:\n";
    hr.showAll();

    cout<<"Search Dept IT:\n"; hr.searchByDept("IT");
    cout<<"Search Name Bob:\n"; hr.searchByName("Bob");

    hr.reportStats();
}
