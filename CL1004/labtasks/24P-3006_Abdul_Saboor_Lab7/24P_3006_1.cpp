#include<iostream>
using namespace std;

class Vehicle{
protected:
    string brand,model;
    int year;
    double price;
public:
    Vehicle(string b,string m,int y,double p):brand(b),model(m),year(y),price(p){}
    virtual void displayInfo(){
        cout<<"Brand:"<<brand<<" Model:"<<model<<" Year:"<<year<<" Price:"<<price<<"\n";
    }
    virtual void startEngine(){cout<<brand<<" "<<model<<" engine started\n";}
    virtual double calculateDepreciation(){return price*0.1;}
    virtual ~Vehicle(){}
};

class Car:public Vehicle{
    int doors;
    string fuelType;
public:
    Car(string b,string m,int y,double p,int d,string f):Vehicle(b,m,y,p),doors(d),fuelType(f){}
    void displayInfo()override{
        Vehicle::displayInfo();
        cout<<"Doors:"<<doors<<" Fuel:"<<fuelType<<"\n";
    }
    void openTrunk(){cout<<"Trunk opened\n";}
    void playMusic(){cout<<"Playing music\n";}
};

class Motorcycle:public Vehicle{
    string type;
    bool hasHelmet;
public:
    Motorcycle(string b,string m,int y,double p,string t,bool h):Vehicle(b,m,y,p),type(t),hasHelmet(h){}
    void displayInfo()override{
        Vehicle::displayInfo();
        cout<<"Type:"<<type<<" Helmet:"<<hasHelmet<<"\n";
    }
    void doWheelie(){cout<<"Doing wheelie!\n";}
    double calculateDepreciation()override{return price*0.2;}
};

class Truck:public Vehicle{
    double capacity;
    int axles;
public:
    Truck(string b,string m,int y,double p,double c,int a):Vehicle(b,m,y,p),capacity(c),axles(a){}
    void displayInfo()override{
        Vehicle::displayInfo();
        cout<<"Capacity:"<<capacity<<" Axles:"<<axles<<"\n";
    }
    void loadCargo(){cout<<"Cargo loaded\n";}
    void unloadCargo(){cout<<"Cargo unloaded\n";}
};

class VehicleShowroom{
    Vehicle* arr[50];
    int count;
public:
    VehicleShowroom():count(0){}
    void addVehicle(Vehicle* x){
        if(count<50)arr[count++]=x;
    }
    void showAll(){
        for(int i=0;i<count;i++){
            arr[i]->displayInfo();
            cout<<"Depreciation:"<<arr[i]->calculateDepreciation()<<"\n";
            arr[i]->startEngine();
            cout<<"------\n";
        }
    }
    ~VehicleShowroom(){
        for(int i=0;i<count;i++) delete arr[i];
    }
};

int main(){
    VehicleShowroom s;
    s.addVehicle(new Car("Toyota","Corolla",2020,25000,4,"Petrol"));
    s.addVehicle(new Motorcycle("Honda","CBR",2019,15000,"Sport",true));
    s.addVehicle(new Truck("Volvo","FH",2018,90000,18.5,4));
    s.showAll();
}
