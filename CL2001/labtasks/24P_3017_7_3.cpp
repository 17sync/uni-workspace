#include<iostream>
using namespace std;

class Node{
public:
    int arrival,service;
    Node* next;
    Node(int a,int s){arrival=a;service=s;next=nullptr;}
};

class PatientQueue{
private:
    Node* front;
    Node* rear;
public:
    PatientQueue(){front=rear=nullptr;}
    bool isEmpty(){return front==nullptr;}
    void enqueue(int a,int s){
        Node* n=new Node(a,s);
        if(isEmpty())front=rear=n;
        else{rear->next=n;rear=n;}
    }
    Node* dequeue(){
        if(isEmpty()) return nullptr;
        Node* temp=front;
        front=front->next;
        if(front==nullptr) rear=nullptr;
        return temp;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    PatientQueue q;
    q.enqueue(0,5);
    q.enqueue(3,3);
    q.enqueue(9,4);
    q.enqueue(10,2);
    q.enqueue(14,5);

    int clock=0,total_wait=0,count=0,peak=0,longest_idle=0;
    int in_system=0,last_service_end=0;
    Node* temp=q.dequeue();

    while(temp){
        count++;
        int arrival=temp->arrival;
        int service=temp->service;
        if(arrival>clock){
            int idle=arrival-clock;
            if(idle>longest_idle)longest_idle=idle;
            clock=arrival;
        }
        
        int wait=0;
        if(clock>arrival) wait=clock-arrival;
        total_wait+=wait;
        cout<<"Patient "<<count<<": Arrival="<<arrival<<", Service="<<service<<", Wait="<<wait<<endl;
        clock+=service;
        
        last_service_end=clock;
        in_system++;
        if(in_system>peak) peak=in_system;
        in_system--;
        
        delete temp;
        temp=q.dequeue();
    }

    double avg_wait=0;
    if(count>0) avg_wait=(double)total_wait/count;
    cout<<"\nAverage waiting time: "<<avg_wait;
    cout<<"\nPeak system size: "<<peak;
    cout<<"\nLongest idle stretch: "<<longest_idle<<endl;
}
