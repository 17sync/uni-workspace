#include <iostream>
using namespace std;

struct Node{
    char data;      
    Node *left;      
    Node *right;     

    Node(char value) {  
        data=value;
        left=right=NULL;
    }
};

void preorder(Node* root) {
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node *A=new Node('A');
    Node *B=new Node('B');
    Node *C=new Node('C');
    Node *D=new Node('D');
    Node *E=new Node('E');
    Node *F=new Node('F');
    Node *G=new Node('G');
    Node *H=new Node('H');

    A->left=B;
    A->right=C;
    B->left=D;
    B->right=E;
    C->right=F;
    E->left=G;
    E->right=H;

    cout<<"Preorder traversal: ";                 // Preorder Traversal Output: Root → Left → Right
    preorder(A);
}
