#include <iostream>
#include<string>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Address{
    string city;
    string street;
    int houseNo;
};

struct Patient{
    string name;
    int id;
    Address address;
    Date admissionDate;
    Date dischargeDate;
    string diagnosis;
    double bill;
};

int daysStayed(Date &a, Date &d){
    int date1=a.year*360+a.month*30+a.day;
    int date2=d.year*360+d.month*30+d.day;
    return date2-date1;
}

double calcBill(string &diagnosis, int days){
    double price=0;
    if (diagnosis=="Nausea"){
        price=150;
    }
    else if (diagnosis=="Fever"){
        price= 300;
    }
    else if (diagnosis=="Flu"){
        price = 200;
    }
    else{
        price=100;
    }
    return price*days;
}

void addPatient(Patient* patients, int &count){
    Patient &p = patients[count];

    cout<<"Enter ID: ";
    cin>>p.id;
    cin.ignore();

    cout<<"Enter name: ";
    getline(cin, p.name);
    cout<<"Enter address (city street houseNo): ";
    cin>>p.address.city>>p.address.street>>p.address.houseNo;
    cout<<"Enter admission date:";
    cin>>p.admissionDate.day>>p.admissionDate.month>>p.admissionDate.year;

    cout<<"Enter discharge date: ";
    cin>>p.dischargeDate.day>>p.dischargeDate.month>>p.dischargeDate.year;
    cout<<"Enter diagnosis: ";
    cin>>p.diagnosis;

    int stay=daysStayed(p.admissionDate, p.dischargeDate);
    p.bill=calcBill(p.diagnosis, stay);

    count++;
    cout<<"Patient added successfully!\n";
}

void searchPatient(Patient* patients, int count, int id){
    for(int i=0;i<count;i++){
        if (patients[i].id==id){
            cout<<"Found: "<<patients[i].name<<", Diagnosis: "<<patients[i].diagnosis<<", Bill: "<<patients[i].bill<<endl;
            return;
        }
    }
    cout<<"Patient not found!\n";
}

void printMonthlyPatients(Patient* patients, int count, int month){
    cout<<"Patients admitted in month "<<month<<":\n";
    for (int i=0;i<count;i++){
        if (patients[i].admissionDate.month==month) {
            cout<<patients[i].name<<" (ID:"<<patients[i].id <<")\n";
        }
    }
}

int main(){
    int max;
    cout<<"Enter maximum number of patients: ";
    cin>>max;

    Patient* p=new Patient[max];
    int count=0;

    int choice;
    while(choice!=4){
        cout<<"\nPatient Management System\n";
        cout<<"1. Add Patient\n2. Search Patient by ID\n3. Display Patients by Month\n4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            if(count<max)
                addPatient(p, count);
            else
                cout<<"Maximum patients enrolled!\n";
        } 
        else if(choice==2){
            int id;
            cout<<"Enter patient ID: "; cin>>id;
            searchPatient(p, count, id);
        } 
        else if(choice==3) {
            int month;
            cout<<"Enter month: "; cin>>month;
            printMonthlyPatients(p, count, month);
        }
    }

    delete[] p;
}


