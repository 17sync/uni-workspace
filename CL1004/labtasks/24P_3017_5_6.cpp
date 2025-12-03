#include <iostream>
using namespace std;
struct company;
struct address;
void get_data(company*);
void display_data(company*);

struct address{
    string city;
    int zip;
};

struct company{
    string name;
    float revenue;
    address a;
}c[3];

int main(){
    get_data(c);
    cout<<endl;
    display_data(c);
}

void get_data(company *c){
    int counter=1;
    cout<<"\nEnter data:\n";
    for(int i=0;i<3;i++){
        cout<<"\nCompany #"<<counter<<": ";
        cout<<"\nEnter name: ";
        cin>>c[i].name;
        cout<<"Enter revenue: ";
        cin>>c[i].revenue;
        cout<<"Enter city: ";
        cin>>c[i].a.city;
        cout<<"Enter zip code: ";
        cin>>c[i].a.zip;
        counter++;
    }
}

void display_data(company *c){
    cout<<"\nCompany details:\n";
    int counter=1;
    for(int i=0;i<3;i++){
        cout<<"\nCompany #"<<counter<<": ";
        cout<<c[i].name;
        cout<<"\nRevenue: "<<c[i].revenue;
        cout<<"\nCity location: "<<c[i].a.city;
        cout<<"\nZip code: "<<c[i].a.zip;
        counter++;
    }
}