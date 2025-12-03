#include<iostream>
using namespace std;

struct Vehicle{
    string make;
    string model;
    int year;
    int mileage;
    int price;
    bool isNew;
};

bool searchForVehicle(Vehicle *v){
    string make;
    string model;
    cout<<"\nEnter manufacturer: "; cin>>make;
    cout<<"Enter model: "; cin>>model;

    for(int i=0;i<10;i++){
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

    cout<<"Vehicle not found."<<endl;
    return false;
}

void sortPrice(Vehicle *v){
    Vehicle temp;
    for(int i=0;i<10-1;i++){
        for(int j=0;j<10-i-1;j++) {
            if(v[j].price>v[j+1].price){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

void calcGarageValue(Vehicle *v){
    float total=0;
    for(int i=0;i<10;i++){
        total+=v[i].price;
    }
    cout<<"\nTotal Inventory Value: "<<total<<endl;
}

void printRange(Vehicle *v){
    float lowerPrice;
    float higherPrice;
    cout<<"\nEnter min Price: "; cin>>lowerPrice;
    cout<<"Enter max Price: "; cin>>higherPrice;

    cout<<"\nVehicles available in price range:\n";
    for(int i=0;i<10;i++){
        if(v[i].price>=lowerPrice && v[i].price<=higherPrice){
            cout<<"\nManufacturer: "<<v[i].make<<endl;
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

int main(){
    Vehicle v[10];
    v[0] = {"Ford", "Mustang", 2019, 5000, 18000, true};
    v[1] = {"Kia", "Sportage", 2022, 2000, 7200, false}; 
    v[2] = {"Chevrolet", "Camaro", 2015, 6200, 9500, true};
    v[3] = {"BMW", "M3", 2020, 3000, 16000, false};
    v[4] = {"Audi", "A4", 2023, 1800, 11000, true};
    v[5] = {"Tesla", "Model S", 2024, 0, 25000, true};
    v[6] = {"Volkswagen", "Golf", 2018, 1600, 6400, false};
    v[7] = {"Jeep", "Wrangler", 2017, 3600, 8700, true};
    v[8] = {"Lamborghini", "Huracan", 2021, 5200, 30000, false};
    v[9] = {"Mitsubishi", "Lancer", 2016, 2000, 5400, true};

    searchForVehicle(v);
    sortPrice(v);
    calcGarageValue(v);
    printRange(v);
}