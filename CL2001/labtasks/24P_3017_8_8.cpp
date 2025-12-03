#include <iostream>
using namespace std;

struct Node{
    int data;      
    Node *left;      
    Node *right;     

    Node(int value) {  
        data=value;
        left=right=NULL;
    }
};

void postorder(Node* root) {
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node *A=new Node(30);
    Node *B=new Node(20);
    Node *C=new Node(90);
    Node *D=new Node(9);
    Node *E=new Node(29);
    Node *F=new Node(50);
    Node *G=new Node(120);
    Node *H=new Node(100);

    A->left=B;
    A->right=C;
    B->left=D;
    B->right=E;
    C->left=F;
    C->right=G;
    G->left=H;

    cout<<"Postorder traversal: ";                 // Postorder Traversal Output: Left → Right → Root
    postorder(A);
}