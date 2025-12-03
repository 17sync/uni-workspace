#include <iostream>
using namespace std;
void admit();
void discharge();
void display_all();
void show_hospital_details();

const int n=101;      //variable storing number of patients

struct hospital;
struct doctor;
struct patient;

int main(){
    int option;

    do{
        do{
            cout<<"\t|| Hospital Management System ||";
            cout<<"\n\n1. Admit patient\n2. Display all patients\n3. Discharge patient\n4. Show hospital details";
            cout<<"\nselect operation (00 to end program): ";
            cin>>option;
    
            if(option==1){
                admit();
            }
            else if(option==2){
                display_all();
            }
            else if(option==3){
                discharge();
            }
            else if(option==4){
                show_hospital_details();
            }
            else{
                cout<<"\n\nERROR--> Invalid selection, try again.";
            }
        }while(option<1 && option>3);
    }while(option!=00);
}

struct doctor{
    string name;
    bool resident;
};

struct patient{
    string name;
    int age;
    string disease;
    doctor d[n];
};

struct hospital{
    string name="Lady Reading Hospital";
    string address="Soekarno Rd, Pipal Mandi, Peshawar";
    int zip=25000;
    patient *p=new patient[n];

    ~hospital(){
        delete[] p;
    }
}h;

void admit(){
    int slot;
    do{
        cout<<"\n\nselect slot (0-100): ";
        cin>>slot;
    
        if(h.p[slot].name!=""){
            cout<<"\nERROR--> slot already taken, choose another slot.";
        }
    }while(h.p[slot].name!="");

    cout<<"Enter patient name: ";
    cin>>h.p[slot].name;
    cout<<"Enter patient age: ";
    cin>>h.p[slot].age;
    cout<<"Enter disease: ";
    cin>>h.p[slot].disease;
    cout<<"Enter name of doctor incharge: ";
    cin>>h.p[slot].d[slot].name;
    cout<<"Is the doctor a resident or not (0 or 1)? ";
    cin>>h.p[slot].d[slot].resident;

    cout<<"\npatient admitted successfully!\n\n";
}

void discharge(){
    int slot;
    do{
        cout<<"\n\nselect slot (0-100): ";
        cin>>slot;
    
        if(h.p[slot].name==""){
            cout<<"\nERROR--> slot empty, choose another slot.";
        }
    }while(h.p[slot].name=="");

    int temp;
    h.p[slot].name="";
    temp=h.p[slot].age;
    h.p[slot].disease="";
    h.p[slot].d[slot].name="";
    h.p[slot].d[slot].resident=0;

    cout<<"\n\npatient discharged successfully!\n\n";
}

void display_all(){
    cout<<endl;
    for(int i=0;i<n;i++){
        if(h.p[i].name!=""){
            cout<<h.p[i].name<<"\n"<<h.p[i].age;
            cout<<"\nDoctor incharge: "<<h.p[i].d[i].name;
            if(h.p[i].d[i].resident==1){
                cout<<" (resident)";
            }
            cout<<"\n\n";
        }
        else{
            continue;
        }
    }       //end of loop
}

void show_hospital_details(){
    cout<<"\n\n";
    cout<<h.name<<endl;
    cout<<h.address<<endl;
    cout<<"zip code: "<<h.zip;
}

