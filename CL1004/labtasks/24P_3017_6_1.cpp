#include <iostream>
using namespace std;

class student{
    private:
    string name;
    string roll;
    int marks[3];

    public:
    student(){

    }

    student(string name, string roll, int m1, int m2, int m3){
        this->name=name;
        this->roll=roll;
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
    }

    bool slot_check(){
        if(name==""){
            return true;
        }
        else{
            return false;
        }
    }

    void add_record(){
        cout<<"Enter student name: ";
        cin>>name;
        cout<<"Enter roll#: ";
        cin>>roll;
        cout<<"Enter marks of 3 subjects: ";
        for(int i=0;i<3;i++){
            cin>>marks[i];
        }
    }

    void display_records(student *s){
        int counter=1;
        for(int i=0;i<10;i++){
            if(s[i].name!=""){
                cout<<"\n\nStudent #"<<counter<<endl;
                cout<<"Name: "<<s[i].name<<endl;
                cout<<"Roll #: "<<s[i].roll<<endl;
                cout<<"Marks (3 subjects): "<<s[i].marks[0]<<" "<<s[i].marks[1]<<" "<<s[i].marks[2];
                counter++;
            }
            else{
                continue;
            }    
        }
    }

    float average_calculator(){
        int sum=marks[0]+marks[1]+marks[2];
        float average=sum/3;

        return average;
    }

    string highest_average(student *s){
        string highest;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(s[i].average_calculator()>s[j].average_calculator()){
                    highest=s[i].name;
                }
                else{
                    highest=s[j].name;
                }
            }
        }   //end of nested loop
        
        return highest;
    }
}s[10];

int main(){
    int slot;
    int operation;

    do{
        cout<<"\n\n(0 to quit program)\n\n1. Add new record\n2. Display all records\n3. Calculate average\n4. Find highest averaging student";
        cout<<"\n\nSelect operation: "; cin>>operation;

        if(operation==1){
            do{
                cout<<"\nselect slot: ";
                cin>>slot;
                if(slot>10){
                    cout<<"ERROR-->Invalid slot selection, Try again.\n";
                }
            }while(slot>10);
            
            if(s[slot].slot_check()==true){
                cout<<endl;

                s[slot].add_record();

                cout<<"Student record added successfully!";    
            }
            else{
                cout<<"\nSlot full, try another slot.";
            }
        }
        else if(operation==2){
            cout<<endl;
            s->display_records(s);
        }
        else if(operation==3){
            do{
                cout<<"\nselect slot: ";
                cin>>slot;
                if(slot>10){
                    cout<<"ERROR-->Invalid slot selection, Try again.\n";
                }
            }while(slot>10);

            if(s[slot].slot_check()==false){
                cout<<endl;

                cout<<"\nAverage of Student#"<<slot<<": "<<s[slot].average_calculator();    
            }
            else{
                cout<<"\nSlot empty, try another slot.";
            }
        }
        else if(operation==4){
            cout<<"\nThe student with the highest average is: "<<s->highest_average(s);
        }
    }while(operation!=0);
}