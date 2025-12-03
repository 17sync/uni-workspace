#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *insertAtEnd(Node *head,int value){
    if(head==NULL) return new Node{value,NULL};
    head->next=insertAtEnd(head->next,value);
    return head;
}

void displayReverse(Node *head){
    if(head==NULL)return;
    displayReverse(head->next);
    cout<<head->data<<" ";
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node *head=NULL;
    head=insertAtEnd(head,10);
    head=insertAtEnd(head,20);
    head=insertAtEnd(head,30);
    displayReverse(head);
}
