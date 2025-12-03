#include<iostream>
using namespace std;

struct doublyNode{              
    doublyNode *prev;
    string data;
    doublyNode *next;

    doublyNode(string name): data(name), next(nullptr), prev(nullptr){}
};

class Doubly{
    doublyNode *head;
    doublyNode *tail;

    public:
    Doubly(): head(nullptr), tail(nullptr){}

    ~Doubly(){
        if(head==nullptr) return;

        doublyNode *curr=head;
        while(curr!=nullptr){
            doublyNode* temp=curr->next;
            delete curr;
            curr=temp;
        }
    }

    void pushFront(string name){
        doublyNode *newNode=new doublyNode(name);

        if(head==nullptr){
            head=tail=newNode;
            return;
        }

        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }

    void pushBack(string name){
        doublyNode *newNode=new doublyNode(name);

        if(head==nullptr){
            head=tail=newNode;
            return;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void deleteNode(string name){
        if(head==nullptr){
            cout<<"\nList is empty, add passengers first."<<endl;
            return;
        }

        doublyNode *curr=head;

        if(head->data==name){
            if(head->next==nullptr){
                delete head;
                head=nullptr;
                return;
            }

            head=head->next;
            head->prev=nullptr;
            delete curr;
            return;
        }

        while(curr!=nullptr){
            if(curr->data==name){
                if(curr->next!=nullptr){
                    curr->prev->next=curr->next;
                    curr->next->prev=curr->prev;
                }
                else{
                    curr->prev->next=nullptr;
                }
                delete curr;
                return;
            }
            curr=curr->next;
        }

        cout<<"\nPassenger not found."<<endl;
    }

    bool search(string name){
        if(head==nullptr){
            cout<<"list is empty"<<endl; 
            return false;
        }

        doublyNode *curr=head;
        while(curr!=nullptr){
            if(curr->data==name) return true;
            curr=curr->next;
        }

        return false;
    }

    void printList(){
        doublyNode *print=head;

        cout<<"\n";
        while(print!=nullptr){
            if(print->next==nullptr) cout<<print->data;
            else cout<<print->data<<" <-> ";
            print=print->next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    Doubly passengerList;

    int choice;
    do{
        cout<<"\nAirline Ticket Reservation System\n";
        cout<<"1. Reserve a ticket\n2. Cancel a ticket\n3. Check for a reserved ticket\n4. Display Passengers\n5. Exit program\n";
        cout<<"Enter operation: "; cin>>choice;

        switch(choice){
            case 1:{
                string name;
                cout<<"\nEnter passenger name: "; cin>>name;
                passengerList.pushBack(name);
                cout<<endl;
            }
            case 2:{
                string name;
                cout<<"\nEnter passenger name: "; cin>>name;
                passengerList.deleteNode(name);
                cout<<endl;
            }
            case 3:{
                string name;
                cout<<"\nEnter passenger name: "; cin>>name;
                if(passengerList.search(name)==true){
                    cout<<"Passenger found."<<endl;
                }
                else{
                    cout<<"Passenger not found."<<endl;
                }
                cout<<endl;
            }
            case 4:{
                cout<<"\nAll reserved passengers on current flight:\n";
                passengerList.printList();
            }
            case 5:{
                cout<<"\nExiting Program..."<<endl;
            }
        }
    }while(choice!=5);
}