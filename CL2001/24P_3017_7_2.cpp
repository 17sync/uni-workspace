#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};

class LinkedLinearQueue{
private:
    Node* front;
    Node* rear;
public:
    LinkedLinearQueue(){
        front=rear=nullptr;
    }
    bool isEmpty(){
        return front==nullptr;
    }
    void Enqueue(int value){
        Node* newNode=new Node(value);
        if(rear==nullptr){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
        cout<<value<<" enqueued to Linear Queue"<<endl;
    }
    void Dequeue(){
        if(isEmpty()){
            cout<<"Linear Queue is empty"<<endl;
            return;
        }
        Node* temp=front;
        cout<<front->data<<" dequeued from Linear Queue"<<endl;
        front=front->next;
        if(front==nullptr)rear=nullptr;
        delete temp;
    }
    void display(){
        if(isEmpty()){
            cout<<"Linear Queue is empty"<<endl;
            return;
        }
        Node* temp=front;
        cout<<"Linear Queue: ";
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

class LinkedCircularQueue{
private:
    Node* front;
    Node* rear;
public:
    LinkedCircularQueue(){
        front=rear=nullptr;
    }
    bool isEmpty(){
        return front==nullptr;
    }
    void Enqueue(int value){
        Node* newNode=new Node(value);
        if(front==nullptr){
            front=rear=newNode;
            rear->next=front;
        }else{
            rear->next=newNode;
            rear=newNode;
            rear->next=front;
        }
        cout<<value<<" enqueued to Circular Queue"<<endl;
    }
    void Dequeue(){
        if(isEmpty()){
            cout<<"Circular Queue is empty"<<endl;
            return;
        }
        if(front==rear){
            cout<<front->data<<" dequeued from Circular Queue"<<endl;
            delete front;
            front=rear=nullptr;
        }else{
            Node* temp=front;
            cout<<front->data<<" dequeued from Circular Queue"<<endl;
            front=front->next;
            rear->next=front;
            delete temp;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Circular Queue is empty"<<endl;
            return;
        }
        Node* temp=front;
        cout<<"Circular Queue: ";
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=front);
        cout<<"(back to front)"<<endl;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;
}
