#include<iostream>
using namespace std;

struct singlyNode{              // for SLL
    int data;
    singlyNode *next;

    singlyNode(int val): data(val), next(nullptr){}
};

struct doublyNode{              // for DLL
    doublyNode *prev;
    int data;
    doublyNode *next;

    doublyNode(int val): data(val), next(nullptr), prev(nullptr){}
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

    void insert(int val, int index){
        if(index==0){
            pushFront(val);
            return;
        }

        singlyNode *curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
            if(curr==tail){                             // condition i<index-1 or would've been curr==head
                cout<<"invalid index."<<endl; return;
            }
        }

        if(curr->next==tail){                           // same reason, i<index-1
            pushBack(val);
            return;
        }

        singlyNode *newNode=new singlyNode(val);

        newNode->next=curr->next;
        curr->next=newNode;
    }

    bool search(int val){
        if(head==nullptr) return false;
        if(head==tail){
            if(head->data==val) return true;
            else return false;
        }

        singlyNode *curr=head;
        while(curr->next!=head){
            if(curr->data==val) return true;
            curr=curr->next;
        }

        if(tail->data==val) return true;                // check on tail cuz loop doesnt check tail

        return false;
    }

    void reverse(){
        if(head==nullptr || head==tail) return;

        tail->next=nullptr;                             // convert to SLL

        singlyNode *curr=head;
        singlyNode *next=nullptr;
        singlyNode *prev=nullptr;
        
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        head->next=tail;                                // convert back to ring
        
        curr=head;                                      // exchange end points
        head=tail;
        tail=curr;
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
        cout<<"(back to "<<head->data<<")"<<endl;

        tail->next=head;
    }
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

    void insert(int val, int index){
        if(index==0){
            pushFront(val);
            return;
        }

        doublyNode *curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
            if(curr==nullptr){
                cout<<"Invalid index."<<endl; 
                return;
            }
        }

        if(curr==tail){
            pushBack(val);
            return;
        }

        doublyNode *newNode=new doublyNode(val);
        
        newNode->next=curr->next;
        newNode->prev=curr;
        curr->next->prev=newNode;
        curr->next=newNode;
    }

    bool search(int val){
        if(head==nullptr){
            cout<<"list is empty"<<endl; 
            return false;
        }

        doublyNode *curr=head;
        while(curr!=nullptr){
            if(curr->data==val) return true;
            curr=curr->next;
        }

        return false;
    }

    void reverse(){
        if(head==nullptr || head->next==nullptr) return;
        
        doublyNode* curr=head;
        doublyNode* temp=nullptr;

        while(curr!=nullptr){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }

        temp=head;
        head=tail;
        tail=temp;        
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

class DoublyRing{
    doublyNode *head;
    doublyNode *tail;

    public:
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

    void insert(int val, int index){
        if(index==0){
            pushFront(val);
            return;
        }

        doublyNode *curr=head;
        for(int i=0;i<index-1;i++){
            curr = curr->next;
            if (curr == tail) {
                cout << "invalid index." << endl;
                return;
            }
        }

        if(curr->next==head){
            pushBack(val);
            return;
        }

        doublyNode *newNode=new doublyNode(val);

        newNode->next=curr->next;
        newNode->prev=curr;
        curr->next->prev=newNode;
        curr->next=newNode;
    }

    bool search(int val){
        if(head==nullptr) return false;

        doublyNode *curr = head;
        do{
            if(curr->data==val) return true;
            curr=curr->next;
        }while(curr!=head);

        return false;
    }

    void reverse(){
        if(head==nullptr || head==tail) return;

        doublyNode *curr=head;
        do{
            swap(curr->next, curr->prev);
            curr=curr->prev; 
        }while(curr!=head);

        swap(head, tail);
    }

    void printList(){
        doublyNode *print=head;
        
        cout << "\n";
        do{
            if(print->next==head) cout<<print->data;
            else cout<<print->data<<" <-> ";
            print=print->next;
        }while(print!=head);

        cout<<" (back to "<<head->data<<")"<<endl;
    }
};

int main(){
    cout<<"24P-3017"<<endl;
}