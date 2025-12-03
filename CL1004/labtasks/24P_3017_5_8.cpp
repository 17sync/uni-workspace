#include <iostream>
using namespace std;
struct hospital;
struct doctor;
void get_data(hospital*, int);
void display_data(hospital*, int);

struct doctor{
    string name;
    string spec;
};

struct hospital{
    string name;
    doctor d[3];
};

int main(){
    int n;
    cout<<"Enter number of hospitals: ";
    cin>>n;

    hospital *h=new hospital[n];

    get_data(h, n);
    cout<<endl;
    display_data(h, n);

    delete[] h;
    h=NULL;
}

void get_data(hospital *h, int n){
    int counter1=1, counter2=1;
    for(int i=0;i<n;i++){
        cout<<"\nEnter hospital #"<<counter1<<" name: ";
        cin>>h[i].name;
        counter1++;
        for(int j=0;j<3;j++){
            cout<<"Doctor #"<<counter2;
            cout<<"\nEnter name: ";
            cin>>h[i].d[j].name;
            cout<<"Enter specialization: ";
            cin>>h[i].d[j].spec;
            counter2++;
        }
        counter2=1;
    }
}

void display_data(hospital *h, int n){
    int counter1=1, counter2=1;
    for(int i=0;i<n;i++){
        cout<<"\n\nHospital #"<<counter1<<": "<<h[i].name;
        counter1++;
        for(int j=0;j<3;j++){
            cout<<"\n\nDoctor #"<<counter2;
            cout<<"\nName: "<<h[i].d[j].name;
            cout<<"\nSpecialization: "<<h[i].d[j].spec;
            counter2++;
        }
        counter2=1;
    }
}