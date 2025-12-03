#include<iostream>
using namespace std;

struct doublyNode{
    doublyNode *prev;
    int data;
    doublyNode *next;

    doublyNode(int val): data(val), next(nullptr), prev(nullptr){}
};

class DoublyRing{
    public:
    doublyNode *head;
    doublyNode *tail;

    DoublyRing():head(nullptr), tail(nullptr){}

    ~DoublyRing(){
        if(head==nullptr) return;

        tail->next=nullptr;

        doublyNode *curr=head;
        while(curr!=nullptr){
            doublyNode* temp=curr->next;
            delete curr;
            curr=temp;
        }
    }

    void pushFront(int val){
        doublyNode *newNode=new doublyNode(val);

        if(head==nullptr) {
            head=tail=newNode;
            head->next=head->prev=head;
            return;
        }

        newNode->next=head;
        newNode->prev=tail;
        head->prev=newNode;
        tail->next=newNode;
        head=newNode;
    }

    void pushBack(int val){
        doublyNode *newNode=new doublyNode(val);

        if(head==nullptr) {
            head=tail=newNode;
            head->next=head->prev=head;
            return;
        }

        newNode->next=head;
        newNode->prev=tail;
        tail->next=newNode;
        head->prev=newNode;
        tail=newNode;
    }

    void popFront(){
        if (head==nullptr) return;
        if (head==tail) {
            delete head;
            head=tail=nullptr;
            return;
        }

        doublyNode *temp=head;
        
        head=head->next;
        head->prev=tail;
        tail->next=head;

        delete temp;
    }

    void popBack(){
        if (head==nullptr) return;
        if (head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }

        doublyNode *temp=tail;

        tail=tail->prev;
        tail->next=head;
        head->prev=tail;

        delete temp;
    }

    void concatenateDoublyRing(doublyNode *&head_M, doublyNode *&tail_M){
    if(head==nullptr){
        head=head_M;
        tail=tail_M;
        return;
    }
    if(head_M==nullptr) return;
    
    head->prev=nullptr;
    tail->next=nullptr;
    head_M->prev=nullptr;
    tail_M->next=nullptr;

    tail_M->next=head;
    tail->prev=tail_M;

    tail->next=head_M;
    head_M->prev=tail;

    doublyNode *tail=tail_M;
}

    void printList(){
        doublyNode *print=head;
        
        cout << "\n";
        do{
            if(print->next==head) cout<<print->data;
            else cout<<print->data<<" <-> ";
            print=print->next;
        }while(print!=head);

        cout<<" <-> (back to "<<head->data<<")"<<endl;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    DoublyRing L;
    DoublyRing M;

    int ex1[5]={1, 2, 3, 4, 5};
    int ex2[5]={6, 7, 8, 9 ,10};

    for(int i=0;i<5;i++){
        L.pushBack(ex1[i]);
        M.pushBack(ex2[i]);
    }

    cout<<"L:"; L.printList();
    cout<<"\nM:"; M.printList();

    L.concatenateDoublyRing(M.head, M.tail);

    cout<<"\nConcatenated List: "; L.printList();
}