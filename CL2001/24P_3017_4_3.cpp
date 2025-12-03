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

        cout<<"Token cancellation successful"<<endl;
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

    List queue;

    int choice;
    do{
        cout<<"\nWelcome to Aun Canteen Queue System"<<endl;
        cout<<"======================================="<<endl;
        cout<<"\n1. Join Queue\n2. Join Queue at front\n3. Join at a specific position\n4. Update Token at a specific position\n5. Cancel Token\n6. Search for Token\n7. Display Current Queue\n8. Reverse Queue\n9. Exit Program\n"<<endl;
        cout<<"Choose option: "; cin>>choice;

        if(choice==1){
            int num;
            cout<<"\nEnter token number: "; cin>>num;
            queue.append(num);
            cout<<"Added to queue";
        }
        else if(choice==2){
            int num;
            cout<<"\nEnter token number: "; cin>>num;
            queue.prepend(num);
            cout<<"Added to queue";
        }
        else if(choice==3){
            int num; int position;
            cout<<"\nEnter token number: "; cin>>num;
            cout<<"Enter position: "; cin>>position;
            queue.insert(num, position);
        }
        else if(choice==4){
            int num; int position;
            cout<<"\nEnter new token number: "; cin>>num;
            cout<<"Enter existing position: "; cin>>position;
            queue.update(num, position);
        }
        else if(choice==5){
            int subChoice;
            cout<<"\n1. Cancel token at front\n2. Cancel token at back\n3. Cancel token at specific position"<<endl;
            cout<<"Choose option: "; cin>>subChoice;

            if(subChoice==1){
                queue.popFront();
                cout<<"Token cancellation successful."<<endl;
            }
            else if(subChoice==2){
                queue.popBack();
                cout<<"Token cancellation successful."<<endl;
            }
            else if(subChoice==3){
                int position;
                cout<<"Enter position: "; cin>>position;
                queue.popAt(position);
            }
            else{
                cout<<"Invalid choice."<<endl;
            }
        }
        else if(choice==6){
            int num;
            cout<<"\nEnter ticket number: "; cin>>num;
            if(queue.search(num)==true){
                cout<<"Token exists"<<endl;
            }
            else{
                cout<<"Token does not exist"<<endl;
            }
        }
        else if(choice==7){
            queue.printList();
        }
        else if(choice==8){
            queue.reverse();
            cout<<"Queue reversed successfully!";
        }
        else if(choice==9){
            cout<<"\nProgram ended."<<endl;
        }
        else{
            cout<<"\nInvalid choice, try again."<<endl;
        }
    }while(choice!=9);
}