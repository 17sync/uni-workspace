#include<iostream>
using namespace std;

struct doublyNode{              
    doublyNode *prev;
    int data;
    doublyNode *next;

    doublyNode(int val): data(val), next(nullptr), prev(nullptr){}
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

    void pushFront(int val){
        doublyNode *newNode=new doublyNode(val);

        if(head==nullptr){
            head=tail=newNode;
            return;
        }

        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }

    void pushBack(int val){
        doublyNode *newNode=new doublyNode(val);

        if(head==nullptr){
            head=tail=newNode;
            return;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void popFront(){
        if(head==nullptr) return;
        if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }

        doublyNode *temp=head;
        head=head->next;
        head->prev=nullptr;

        delete temp;
    }

    void popBack(){
        if(head==nullptr) return;
        if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }

        doublyNode *temp=tail;
        tail=tail->prev;
        tail->next=nullptr;

        delete temp;
    }

    void evenFirstThenOdd(){
    if (head==nullptr || head->next==nullptr) return;

    doublyNode *evenHead=nullptr;
    doublyNode *evenTail=nullptr;
    doublyNode *oddHead=nullptr;
    doublyNode *oddTail=nullptr;

    doublyNode* curr=head;

    while(curr!=nullptr){
        doublyNode *next=curr->next;
        curr->next=curr->prev= nullptr;

        if(curr->data%2==0){
            if(evenHead==nullptr){
                evenHead=evenTail=curr;
            }
            else{
                evenTail->next=curr;
                curr->prev=evenTail;
                evenTail=curr;
            }
        } 
        else{
            if(oddHead==nullptr){
                oddHead=oddTail=curr;
            } 
            else{
                oddTail->next=curr;
                curr->prev=oddTail;
                oddTail=curr;
            }
        }

        curr=next;
    }

    if(evenHead==nullptr || oddHead==nullptr){
        return;
    }

    evenTail->next=oddHead;
    oddHead->prev=evenTail;

    head=evenHead;
    tail=oddTail;
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

    int example[10]={17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    Doubly exampleList;

    for(int i=0;i<10;i++){
        exampleList.pushBack(example[i]);
    }

    cout<<"Given DLL: ";
    exampleList.printList();

    exampleList.evenFirstThenOdd();

    cout<<"\nOutput DLL: ";
    exampleList.printList();
}