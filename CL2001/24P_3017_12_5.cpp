#include<iostream>
using namespace std;

struct Student{
    int roll;
    string name;
    bool occupied;
    Student(){ roll=-1; name=""; occupied=false; }
};

class StudentHashTable{
    Student table[15];
    int size = 15;

    int hashFunc(int roll){
        return roll % size;
    }

public:
    void InsertRecord(int roll,string name){
        int idx=hashFunc(roll);

        for(int attempt=0;attempt<size;attempt++){
            int newIdx = (idx + attempt*attempt) % size;

            if(!table[newIdx].occupied){
                table[newIdx].roll = roll;
                table[newIdx].name = name;
                table[newIdx].occupied = true;
                cout<<"Inserted at index "<<newIdx<<"\n";
                return;
            }
        }
        cout<<"Hash table is full, cannot insert.\n";
    }

    void SearchRecord(int roll){
        int idx=hashFunc(roll);

        for(int attempt=0;attempt<size;attempt++){
            int newIdx = (idx + attempt*attempt) % size;

            if(!table[newIdx].occupied){
                break;
            }

            if(table[newIdx].roll == roll){
                cout<<"Student found: "<<table[newIdx].name<<"\n";
                return;
            }
        }
        cout<<"Record not found\n";
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    StudentHashTable ht;

    ht.InsertRecord(101, "Aun");
    ht.InsertRecord(116, "Saboor");
    ht.InsertRecord(131, "Ali");

    ht.SearchRecord(116);
    ht.SearchRecord(500);
}
