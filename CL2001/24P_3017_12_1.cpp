#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    string value;
    Node* next;
    Node(string val):value(val), next(nullptr){}
};

class HashTable{
private:
    Node **table;
    int size;

    int hashFunction(string str){
        int sum=0;
        for (int i=0;i<str.length();i++){
            sum+=str[i];
        }
        return sum%size;
    }

public:
    HashTable(int size){
        this->size=size;
        table=new Node *[size];
        for (int i=0;i<size;i++){
            table[i]=nullptr;
        }
    }

    void insert(string key){
        int index=hashFunction(key);
        Node* newNode=new Node(key);
        if (table[index]==nullptr) {
            table[index]=newNode;
        } else {
            Node *temp=table[index];
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void display(){
        for (int i=0;i<size;i++){
            cout<<i<<": ";
            Node *temp=table[i];
            while(temp!=nullptr){
                cout<<temp->value<<" -> ";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
    }
};

int main() {
	cout<<"24P-3017\n"<<endl;
	
	
    HashTable myhash(5);
    myhash.insert("aaaaa");
    myhash.insert("bbbbb");
    myhash.insert("ccccc");
    myhash.insert("Zzzzz");
    myhash.insert("aaaaa");
    myhash.display();
}

