#include<iostream>
using namespace std;

class Node{
public:
    int id,a,b,c;
    bool deferred;
    string status;
    Node* next;
    Node(int i,int x,int y,int z){
        id=i;a=x;b=y;c=z;
        deferred=false;status="Pending";next=nullptr;
    }
};

class OrderQueue{
private:
    Node* front;
    Node* rear;
public:
    OrderQueue(){front=rear=nullptr;}
    bool isEmpty(){return front==nullptr;}
    void enqueue(Node* n){
        if(isEmpty())front=rear=n;
        else{rear->next=n;rear=n;}
    }
    Node* dequeue(){
        if(isEmpty())return nullptr;
        Node* temp=front;
        front=front->next;
        if(front==nullptr)rear=nullptr;
        return temp;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;
    int stockA,stockB,stockC;
    cout<<"Enter initial stock for A B C: ";
    cin>>stockA>>stockB>>stockC;

    OrderQueue q;
    int n;
    cout<<"Enter number of orders: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cout<<"Order "<<i<<" (A B C): ";
        cin>>a>>b>>c;
        Node* node=new Node(i,a,b,c);
        q.enqueue(node);
    }

    int fulfilled=0,deferred=0,canceled=0;
    OrderQueue processed;

    while(!q.isEmpty()){
        Node* cur=q.dequeue();
        if(cur->a<=stockA && cur->b<=stockB && cur->c<=stockC){
            stockA-=cur->a;stockB-=cur->b;stockC-=cur->c;
            cur->status="Fulfilled";
            fulfilled++;
        }else{
            if(!cur->deferred){
                cur->deferred=true;
                cur->status="Deferred once";
                q.enqueue(cur);
                deferred++;
                continue;
            }else{
                cur->status="Canceled";
                canceled++;
            }
        }
        processed.enqueue(cur);
    }

    cout<<"\nOrder Summary:\n";
    Node* p=processed.dequeue();
    while(p){
        cout<<"Order "<<p->id<<": "<<p->status<<endl;
        delete p;
        p=processed.dequeue();
    }

    cout<<"\nTotal Fulfilled: "<<fulfilled;
    cout<<"\nTotal Deferred: "<<deferred;
    cout<<"\nTotal Canceled: "<<canceled;
    cout<<"\nRemaining Stock -> A:"<<stockA<<" B:"<<stockB<<" C:"<<stockC<<endl;
}
