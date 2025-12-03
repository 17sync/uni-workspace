#include<iostream>
using namespace std;

const int totalVehciles=10;

struct Vehicle{
    string make;
    string model;
    int year;
    float mileage;
    float price;
    bool isNew;
}v[totalVehciles];

bool search(Vehicle*);
void sortByPrice(Vehicle*);
void calculateTotalValue(Vehicle*);
void displayWithinRange(Vehicle*);

int main(){
    v[0]={"Toyota", "Corolla", 2024, 1254.5, 4000, true};
    v[1]={"Mercedes", "E class", 2016, 1455.5, 3500, false};
    v[2]={"Mazda", "Rx7", 2007, 4500, 2400, false};
    v[3]={"Hyundai", "Elantra", 2025, 200, 8000, true};
    v[4]={"Toyota", "Prius", 2017, 3000, 2200, false};
    v[5]={"Suzuki", "Mehran", 2020, 2500, 800, true};
    v[6]={"Nissan", "GTR", 2018, 3500, 10000, false};
    v[7]={"Honda", "Civic", 2021, 2000, 4800, true};
    v[8]={"Honda", "City", 2025, 800, 5500, true};
    v[9]={"Bugatti", "Chiron", 2023, 750, 25000, true};

    search(v);
    sortByPrice(v);
    calculateTotalValue(v);
    displayWithinRange(v);
}

bool search(Vehicle *v){
    string make;
    string model;
    cout<<"\nEnter Vehicle Make: "; cin>>make;
    cout<<"Enter Vehicle model: "; cin>>model;

    for(int i=0;i<totalVehciles;i++){
        if(v[i].make==make){
            if(v[i].model==model){
                cout<<"Vehicle available:\n";
                cout<<"Year: "<<v[i].year<<endl;
                cout<<"Mileage: "<<v[i].mileage<<endl;
                cout<<"Price: "<<v[i].price<<endl;
                cout<<"Condition: ";
                if(v[i].isNew==true) cout<<"New"<<endl;
                else cout<<"Used"<<endl;
                return true;
            }
            else continue;
        }
    }

    cout<<"Vehicle not available."<<endl;
    return false;
}

void sortByPrice(Vehicle *v){
    Vehicle temp;
    for(int i=0;i<totalVehciles-1;i++){
        for(int j=0;j<totalVehciles-i-1;j++) {
            if(v[j].price>v[j+1].price){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

void calculateTotalValue(Vehicle *v){
    float totalValue=0;
    for(int i=0;i<totalVehciles;i++){
        totalValue+=v[i].price;
    }
    cout<<"\nTotal Inventory Value: "<<totalValue<<endl;
}

void displayWithinRange(Vehicle *v){
    float lowerBound;
    float higherBound;
    cout<<"\nEnter Minimum Price: "; cin>>lowerBound;
    cout<<"Enter Maximum Price: "; cin>>higherBound;

    cout<<"\nVehicles available in price range:\n";
    for(int i=0;i<totalVehciles;i++){
        if(v[i].price>=lowerBound && v[i].price<=higherBound){
            cout<<"\nMake: "<<v[i].make<<endl;
            cout<<"Model: "<<v[i].model<<endl;
            cout<<"Year: "<<v[i].year<<endl;
            cout<<"Mileage: "<<v[i].mileage<<endl;
            cout<<"Price: "<<v[i].price<<endl;
            cout<<"Condition: ";
            if(v[i].isNew==true) cout<<"New"<<endl;
            else cout<<"Used"<<endl;
        }
    }
}