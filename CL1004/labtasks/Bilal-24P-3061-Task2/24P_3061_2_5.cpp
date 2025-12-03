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

int daysBetween(const Date&, const Date&);
double calculateBill(const string&, int);
void addPatient(Patient*, int&);
void searchPatientByID(Patient*, int, int);
void displayPatientsByMonth(Patient*, int, int);

int main(){
    int maxPatients;
    cout<<"Enter maximum number of patients: ";
    cin>>maxPatients;

    Patient* patients=new Patient[maxPatients];
    int count=0;

    int choice;
    do{
        cout<<"\n--- Patient Management Menu ---\n";
        cout<<"1. Add Patient\n2. Search Patient by ID\n3. Display Patients by Month\n4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            if(count<maxPatients)
                addPatient(patients, count);
            else
                cout<<"Patient limit reached!\n";
        } 
        else if(choice==2){
            int id;
            cout<<"Enter ID: "; cin>>id;
            searchPatientByID(patients, count, id);
        } 
        else if(choice==3) {
            int month;
            cout<<"Enter month: "; cin>>month;
            displayPatientsByMonth(patients, count, month);
        }
    }while(choice!=4);

    delete[] patients;
}

int daysBetween(const Date &a, const Date &d){
    int date1=a.year*360+a.month*30+a.day;
    int date2=d.year*360+d.month*30+d.day;
    return date2-date1;
}

double calculateBill(const string &diagnosis, int days){
    double rate=0;
    if (diagnosis=="Common Cold") rate=100;
    else if (diagnosis=="Cancer") rate= 500000;
    else if (diagnosis=="Chicken Pox") rate = 300;
    else rate=150;
    return rate*days;
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

    int stay=daysBetween(p.admissionDate, p.dischargeDate);
    p.bill=calculateBill(p.diagnosis, stay);

    count++;
    cout<<"Patient added successfully!\n";
}

void searchPatientByID(Patient* patients, int count, int id){
    for(int i=0;i<count;i++){
        if (patients[i].id==id){
            cout<<"Found: "<<patients[i].name<<", Diagnosis: "<<patients[i].diagnosis<<", Bill: "<<patients[i].bill<<endl;
            return;
        }
    }
    cout<<"Patient not found!\n";
}

void displayPatientsByMonth(Patient* patients, int count, int month){
    cout<<"Patients admitted in month "<<month<<":\n";
    for (int i=0;i<count;i++){
        if (patients[i].admissionDate.month==month) {
            cout<<patients[i].name<<" (ID:"<<patients[i].id <<")\n";
        }
    }
}
