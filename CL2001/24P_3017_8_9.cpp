#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void inorder(Node *root) {
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    cout<<"24P-3017\n"<<endl;

    Node *root=new Node(40);
    root->left=new Node(30);
    root->right=new Node(50);
    root->left->left=new Node(25);
    root->left->right=new Node(35);
    root->right->left=new Node(45);
    root->right->right=new Node(60);
    root->left->left->left=new Node(15);
    root->left->left->right=new Node(28);
    root->right->right->left=new Node(55);
    root->right->right->right=new Node(70);

    cout<<"Inorder traversal: ";          // Inorder traversal: Left → Root → Right
    inorder(root);
}
