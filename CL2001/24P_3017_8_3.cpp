#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val):data(val), next(NULL){}
};

int getLength(Node *head, int count=0){
    if(head==NULL) return count;   
    return getLength(head->next, count+1); 
}

int main(){
    cout<<"24P-3017\n"<<endl;
}