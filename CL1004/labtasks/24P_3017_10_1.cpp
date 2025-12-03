#include<iostream>
using namespace std;

class engine{
    public:
    void start(){
        cout<<"Engine started."<<endl;
    }
};

class car{
    engine e;
    public:
    void car_start(){
        e.start();
        cout<<"Car started.";
    }
}c;

int main(){
    c.car_start();
}