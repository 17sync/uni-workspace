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
    }

    void update(int index, int value){
        Node* update=Head;
        for(int i=0;i<index-1;i++){
            if(update==NULL){
                cout<<"Invalid index, try again."<<endl;
                return;
            }
            update=update->Next;
        }

        update->Data=value;
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

    void reverse(){
        Node *temp1=Tail;

        if(Head==Tail){
            return;
        }
        
        do{
            Node *temp2=Head;
            while(temp2->Next!=temp1){
                temp2=temp2->Next;
            }

            temp1->Next=temp2;
            temp1=temp1->Next;
        }while(temp1!=Head);

        Head->Next=NULL;
        Head=Tail;
        Tail=temp1;
    }

    void printList(){
        Node *temp=Head;

        while(temp!=NULL){
            cout<<temp->Data<<" ";
            temp=temp->Next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    List l1;
    l1.append(2);
    l1.append(4);
    l1.append(6);
    l1.append(8);
    l1.printList();
    l1.popAt(2);
    l1.printList();
    l1.update(1, 5);
    l1.printList();
    l1.prepend(0);
    l1.printList();
    l1.reverse();
    l1.printList();
}