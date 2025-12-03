#include<iostream>
using namespace std;

class Customer{
    string name;
    string address;
    string phone;

    public:
    Customer(string n, string a, string p){
        name=n;
        address=a;
        phone=p;
    }

    void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone number: "<<phone<<endl;
    }

    string getName(){
        return name;
    }

    string getAddress(){
        return address;
    }

    string getPhone(){
        return phone;
    }
};

class Account{
    string accountNumber;
    Customer *customer;
    float balance;

    public:
    Account(string accNum, Customer c){
        accountNumber=accNum;
        customer=&c;
        balance=0;
    }

    void deposit(float amount){
        balance+=amount;
    }

    void withdraw(float amount){
        if(balance==0 || amount>balance){
            cout<<"Insufficient balance."<<endl;
            return;
        }
        balance-=amount;
    }

    void displayInfo(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder details: "<<endl;
        customer->displayInfo();
        cout<<"Balance: "<<balance<<endl;
    }

    string getaccNum(){
        return accountNumber;
    }

    Customer getCustomer(){
        return *customer;
    }

    float getbalance(){
        return balance;
    }
};

class Bank{
    string name;
    Account *accounts[3];

    public:
    Bank(string n){
        name=n;
        accounts[3]={nullptr};
    }

    void addAccount(Account &a){
        for(int i=0;i<3;i++){
            if(accounts[i]==nullptr){
                accounts[i]=&a;
                cout<<"Successfully added account to bank."<<endl;
                return;
            }
        }

        cout<<"Bank full, cannot accomodate any more accounts."<<endl;
    }

    void removeAccount(string accNum){
        for(int i=0;i<3;i++){
            if(accounts[i]->getaccNum()==accNum){
                accounts[i]=nullptr;
                cout<<"Successfully removed account from bank."<<endl;
                return;
            }
        }

        cout<<"Account does not exist."<<endl;
    }

    Account findAccount(string accNum){
        for(int i=0;i<3;i++){
            if(accounts[i]->getaccNum()==accNum){
                cout<<"Account found."<<endl;
                return *accounts[i];
            }
        }

        cout<<"Account does not exist."<<endl;
    }

    void displayAllAccounts(){
        for(int i=0;i<3;i++){
            if(accounts[i]!=nullptr) accounts[i]->displayInfo();
            cout<<endl;
        }
    }
};

int main(){
    Bank b("Bilal Banking Ltd");
    
    Customer c1("Aun Anis", "RMT Zone 4, Peshawar", "0316-9544433");
    Customer c2("Bilal Malik", "Jouhar Town, Lahore", "0323-5386795");
    Customer c3("Ahmad Ali Shah", "City Housing Society, Jhelum", "0335-1599753");

    Account a1("1433-5433-0896", c1);
    Account a2("1342-8613-3231", c2);
    Account a3("2314-8765-9087", c3);

    b.addAccount(a1);
    b.addAccount(a2);
    b.addAccount(a3);

    a1.deposit(200);
    a2.deposit(250);
    a3.deposit(300);

    a1.withdraw(100);
    a2.withdraw(125);
    a3.withdraw(150);

    b.displayAllAccounts();
    b.removeAccount(a1.getaccNum());
    b.displayAllAccounts();
}