#include<iostream>
using namespace std;

struct Node{
    public:
    int Data;
    Node *Next;

    Node(int val){
        Data=val;
        Next=NULL;
    }
};

class List{
    Node *Head;
    Node *Tail;

    public:
    List(){
        Head=Tail=NULL;
    }

    void prepend(int val){
        Node *newNode=new Node(val);
        
        if(Head==NULL){
            Head=Tail=newNode;
            return;
        }

        newNode->Next=Head;
        Head=newNode;
    }

    void append(int val){
        Node *newNode=new Node(val);

        if(Head==NULL){
            Head=Tail=newNode;
            return;
        }
        
        Tail->Next=newNode;
        Tail=newNode;
    }

    void popFront(){
        if(Head==NULL){
            cout<<"List is has no entries"<<endl;
            return;
        }

        Node *temp=Head;
        Head=Head->Next;
        temp->Next=NULL;

        delete temp;
    }

    void popBack(){
        if(Head==NULL){
            cout<<"List has no entries"<<endl;
            return;
        }

        Node *temp=Head;
        while(temp->Next!=Tail){
            temp=temp->Next;
        }

        temp->Next=NULL;
        delete Tail;
        Tail=temp;
    }

    void insert(int val, int index){
        if(index<0){
            cout<<"Invalid index, try again."<<endl;
        }
        else if(index==0){
            prepend(val);
        }

        Node *temp=Head;
        for(int i=0;i<index-1;i++){
            if(temp==NULL){
                cout<<"Invalid index, try again."<<endl;
                return;
            }
            temp=temp->Next;
        }

        Node *newNode=new Node(val);
        newNode->Next=temp->Next;
        temp->Next=newNode;

        cout<<"Added to queue at index "<<index<<"."<<endl;
    }

    void popAt(int index){
        Node *temp=Head;
        for(int i=0;i<index-1;i++){
            if(temp==NULL){
                cout<<"Invalid index, try again."<<endl;
                return;
            }
            temp=temp->Next;
        }

        Node* temp2=Head;
        while(temp2->Next!=temp){
            temp2=temp2->Next;
        }

        temp2->Next=temp->Next;
        delete temp;

        cout<<"Ticket cancellation successful."<<endl;
    }

    bool search(int val){
        Node *search=Head;

        while(search!=NULL){
            if(search->Data==val){
                return true;
            }
            else search=search->Next;
        }

        return false;
    }

    void printList(){
        Node *print=Head;

        cout<<"\n";
        while(print!=NULL){
            if(print->Next==NULL) cout<<print->Data;
            else cout<<print->Data<<" -> ";
            print=print->Next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    List ticket;
    for(int i=0;i<5;i++){           // adding filler nodes
        ticket.append(rand()%100);
    }

    int choice;
    do{
        cout<<"\nWelcome to Aun Ticket Management System"<<endl;
        cout<<"======================================="<<endl;
        cout<<"\n1. Join Queue\n2. Join Queue as VIP\n3. Join at a specific position\n4. Cancel Ticket\n5. Search for Ticket Number\n6. Display Current Queue\n7. Exit Program\n"<<endl;
        cout<<"Choose option: "; cin>>choice;

        if(choice==1){
            int ticketNum;
            cout<<"\nEnter ticket number: "; cin>>ticketNum;
            ticket.append(ticketNum);
            cout<<"Added to queue";
        }
        else if(choice==2){
            int ticketNum;
            cout<<"\nEnter ticket number: "; cin>>ticketNum;
            ticket.prepend(ticketNum);
            cout<<"Added to front of queue";
        }
        else if(choice==3){
            int ticketNum; int position;
            cout<<"\nEnter ticket number: "; cin>>ticketNum;
            cout<<"Enter position: "; cin>>position;
            ticket.insert(ticketNum, position);
        }
        else if(choice==4){
            int subChoice;
            cout<<"\n1. Cancel ticket at front\n2. Cancel ticket at back\n3. Cancel ticket at specific position"<<endl;
            cout<<"Choose option: "; cin>>subChoice;

            if(subChoice==1){
                ticket.popFront();
                cout<<"Ticket cancellation successful."<<endl;
            }
            else if(subChoice==2){
                ticket.popBack();
                cout<<"Ticket cancellation successful."<<endl;
            }
            else if(subChoice==3){
                int position;
                cout<<"Enter position: "; cin>>position;
                ticket.popAt(position);
            }
            else{
                cout<<"Invalid choice."<<endl;
            }
        }
        else if(choice==5){
            int ticketNum;
            cout<<"\nEnter ticket number: "; cin>>ticketNum;
            if(ticket.search(ticketNum)==true){
                cout<<"Ticket exists"<<endl;
            }
            else{
                cout<<"Ticket does not exist"<<endl;
            }
        }
        else if(choice==6){
            ticket.printList();
        }
        else if(choice==7){
            cout<<"\nProgram ended."<<endl;
        }
        else{
            cout<<"\nInvalid choice, try again."<<endl;
        }
    }while(choice!=7);
}