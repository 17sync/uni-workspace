#include<iostream>
using namespace std;

struct singlyNode{              
    int data;
    singlyNode *next;

    singlyNode(int val): data(val), next(nullptr){}
};

class Ring{
    singlyNode *head;
    singlyNode *tail;

    public:
    Ring(): head(nullptr), tail(nullptr){}

    ~Ring(){
        singlyNode *curr=head;

        tail->next=nullptr;

        while(curr!=nullptr){
            singlyNode *temp=curr->next;
            delete curr;
            curr=temp;
        }
    }

    void pushFront(int val){
        singlyNode *newNode=new singlyNode(val);
        
        if(head==nullptr){
            head=tail=newNode;
            tail->next=head;

            return;
        }

        newNode->next=head;
        head=newNode;
        tail->next=head;
    }

    void pushBack(int val){
        singlyNode *newNode=new singlyNode(val);

        if(head==nullptr){
            head=tail=newNode;
            tail->next=head;

            return;
        }

        tail->next=newNode;
        tail=newNode;
        tail->next=head;
    }

    void popFront(){
        if(head==nullptr) return;
        if(head==tail){
            delete head;
            head=tail=nullptr;
            
            return;
        }

        singlyNode *temp=head;
        head=head->next;
        tail->next=head;

        delete temp;
    }

    void popBack(){
        if(head==nullptr) return;
        if(head==tail){
            delete head;
            head=tail=nullptr;

            return;
        }

        singlyNode *temp=head;
        while(temp->next!=tail) temp=temp->next;
        
        delete tail;

        tail=temp;
        tail->next=head;
    }

    void rotate(int x){
        if (head==nullptr || head==tail || x==0) return;

        singlyNode *curr=head;
        int size=1;
        while(curr->next!=head){
            curr=curr->next;
            size++;
        }

        x=x%size;
        if (x==0) return;           // if x>=size it wraps around

        curr=head;
        for(int i=1;i<x;i++){
            curr=curr->next;
        }

        singlyNode *newHead=curr->next;
        curr->next=head;

        tail=curr;
        head=newHead;
    }

    void printList(){
        singlyNode *print=head;
        tail->next=nullptr;

        cout<<"\n";
        while(print!=nullptr){
            if(print->next==nullptr) cout<<print->data;
            else cout<<print->data<<" -> ";
            print=print->next;
        }
        cout<<" (back to "<<head->data<<")"<<endl;

        tail->next=head;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    int example[7]={5, 3, 1, 8, 6, 4, 2};
    Ring exampleList;

    for(int i=0;i<7;i++){
        exampleList.pushBack(example[i]);
    }

    cout<<"Given CLL: ";
    exampleList.printList();

    int num;
    cout<<"\nEnter number of elements to rotate: ";
    cin>>num;

    exampleList.rotate(num);

    cout<<"\nOutput CLL: ";
    exampleList.printList();
}