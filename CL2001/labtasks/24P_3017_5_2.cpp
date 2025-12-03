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

    void deleteVal(int val){
        if(head==nullptr) return;

        singlyNode *curr=head;
        singlyNode *prev=nullptr;

        if(head->data==val){
            if(head->next==head){
                delete head;
                head=nullptr;
                return;
            }

            singlyNode *last=head;
            while(last->next!=head){
                last=last->next;
            }

            last->next=head->next;
            singlyNode *temp=head;
            head=head->next;
            delete temp;
            return;
        }

        while(curr!=head){
            prev=curr;
            curr=curr->next;

            if(curr->data==val){
                prev->next=curr->next;
                delete curr;
                return;
            }
        }
    }

    void insert(int val, int index){
        if(index==0){
            pushFront(val);
            return;
        }

        singlyNode *curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
            if(curr==tail){                             
                cout<<"invalid index."<<endl; return;
            }
        }

        if(curr->next==tail){                           
            pushBack(val);
            return;
        }

        singlyNode *newNode=new singlyNode(val);

        newNode->next=curr->next;
        curr->next=newNode;
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

    int array[5]={3, 1, 2, 5, 8};
    cout<<"Array:\n";
    for(int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
    
    Ring List;
    for(int i=0;i<5;i++){
        List.pushBack(array[i]);
    }

    List.pushBack(9);
    List.insert(11, 2);
    List.pushFront(4);
    List.deleteVal(1);
    List.deleteVal(2);
    List.deleteVal(5);
    cout<<"\n\nFinal Cirular Linked List:";
    List.printList();
}