#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val):data(val), next(NULL){}
};

bool search(Node *head, int key){
    if(head==NULL) return false;              
    bool found=search(head->next,key);       
    if(found) return true;                    
    if(head->data==key) return true;          
    return false;
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);

    int key;
    cout<<"Enter value to search: ";
    cin>>key;

    if(search(head,key)) cout<<"Value found in list!"<<endl;
    else cout<<"Value not found."<<endl;
}
