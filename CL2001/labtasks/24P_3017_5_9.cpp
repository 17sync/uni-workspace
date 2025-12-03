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

    void extractAltReverse(){
        if(head==nullptr || head==tail || head->next==tail) return;

        doublyNode* curr=head->next;
        doublyNode* extractedHead=nullptr;
        doublyNode* extractedTail=nullptr;

        while(curr!=head){
            doublyNode* nextNode=curr->next;

            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;

            curr->next=nullptr;
            curr->prev=nullptr;

            if(extractedHead==nullptr){
                extractedHead=extractedTail=curr;
            }
            else{
                extractedTail->next=curr;
                curr->prev=extractedTail;
                extractedTail=curr;
            }

            if(nextNode==head) break;
            curr=nextNode->next;
        }

        if(extractedHead==nullptr) return;

        doublyNode* revHead=extractedHead;
        doublyNode* node=extractedHead;
        while(node){
            std::swap(node->next,node->prev);
            if(node->prev==nullptr){
                revHead=node;
                break;
            }
            node=node->prev;
        }

        doublyNode* revTail=revHead;
        while(revTail->next) revTail=revTail->next;

        tail->next=revHead;
        revHead->prev=tail;
        revTail->next=head;
        head->prev=revTail;
        tail=revTail;
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

    int example[10]={17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    DoublyRing exampleList;

    for(int i=0;i<10;i++){
        exampleList.pushBack(example[i]);
    }

    cout<<"Example List:"; exampleList.printList();
    exampleList.extractAltReverse();
    cout<<"\nOutput List:"; exampleList.printList();
}