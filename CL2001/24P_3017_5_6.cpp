#include<iostream>
using namespace std;

struct doublyNode{              
    doublyNode *prev;
    int data;
    doublyNode *next;

    doublyNode(int val): data(val), next(nullptr), prev(nullptr){}
};

class Doubly{
    public:
    doublyNode *head;
    doublyNode *tail;

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

bool palindrome(doublyNode *&head, doublyNode *&tail){
    if (head==nullptr || head==tail) return true;

    doublyNode *start=head;
    doublyNode *end=tail;

    while (start!=end && end->next!=start) {
        if(start->data!=end->data) return false;
        start=start->next;
        end=end->prev;
    }

    return true;
}

int main(){
    cout<<"24P-3017\n"<<endl;

    int example[5]={1, 0, 2, 0, 1};
    Doubly exampleList;

    for(int i=0;i<5;i++){
        exampleList.pushBack(example[i]);
    }

    cout<<"Given DLL: ";
    exampleList.printList();

    if(palindrome(exampleList.head, exampleList.tail)==true) cout<<"\nLinked List is a Palindrome"<<endl;
    else cout<<"\nLinked List is not a Palindrome"<<endl;
}