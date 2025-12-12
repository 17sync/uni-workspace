#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    string value;
    Node *next;
    Node(string val):value(val), next(nullptr){}
};

class HashTable{
private:
    Node **table;
    int size;

    int hashFunction(string str){
        int sum=0;
        for(int i=0;i<str.length();i++){
            sum+=str[i];
        }
        return sum%size;
    }

public:
    HashTable(int size){
        this->size=size;
        table=new Node *[size];
        for (int i=0;i<size;i++){
            table[i] = nullptr;
        }
    }

    void Add_Record(string key){
        int index=hashFunction(key);
        Node* newNode=new Node(key);
        if(table[index]==nullptr){
            table[index]=newNode;
        } 
		else{
            Node *temp=table[index];
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cout<<"key "<<key<<" added successfully !"<<endl;
    }

    void Word_Search(string key){
        int index = hashFunction(key);
        Node *temp=table[index];
        bool found=false;

        while(temp!=nullptr){
            if(temp->value==key){
                found=true;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            cout << "search key " << key << " found at index " << index << endl;
        } else {
            cout << "search key " << key << " not found!" << endl;
        }
    }

    void Delete_Record(string key){
        int index=hashFunction(key);
        Node* temp=table[index];
        Node* prev=nullptr;
        bool found=false;

        while(temp!=nullptr){
            if (temp->value==key) {
                found=true;
                if(prev==nullptr){
                    table[index]=temp->next;
                } 
				else{
                    prev->next=temp->next;
                }
                delete temp;
                cout<<"key "<<key<<" deleted!"<<endl;
                break;
            }
            prev=temp;
            temp=temp->next;
        }

        if(!found){
            cout<<"key "<<key<<" not found."<<endl;
        }
    }

    void Print_Dictionary(){
        for(int i=0;i<size;i++){
            Node *temp=table[i];
            if(temp!=nullptr){
                cout<<"index "<<i<<": ";
                while (temp != nullptr){
                    cout<<"("<<temp->value<<") ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    HashTable myhash(100);
    myhash.Add_Record("FASTNU");
    myhash.Add_Record("AB");
    myhash.Add_Record("EF");
    myhash.Add_Record("CD");
    myhash.Add_Record("CS");
    myhash.Print_Dictionary();
    myhash.Word_Search("FAST-NUCES");
    myhash.Delete_Record("EF");
    myhash.Print_Dictionary();
    myhash.Word_Search("EF");
}

