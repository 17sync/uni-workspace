#include<iostream>
using namespace std;

struct treeNode{
    int val, count;                             // count tracks duplicates
    treeNode *left, *right;

    treeNode(int num): val(num), count(1), left(nullptr), right(nullptr){}
};

class BST{      
    treeNode *root;

    treeNode *del(treeNode* node,int val){     // main deletion logic
        if(!node) return node;

        if(val<node->val) node->left=del(node->left, val);
        else if(val>node->val) node->right=del(node->right, val);
        else{
            if(node->count>1){                  // in case of duplicate
                node->count--;
                return node;
            }
            if(!node->left){
                treeNode* temp=node->right;
                delete node;
                return temp;
            }
            if(!node->right){
                treeNode* temp=node->left;
                delete node;
                return temp;
            }

            treeNode* successor=node->right;                    // inorder successor
            while(successor->left) successor=successor->left;
            
            node->val=successor->val;
            node->count=successor->count;
            successor->count=1;
            node->right=del(node->right, successor->val);
        }
        
        return node;
    }

    treeNode *searchNode(treeNode *node, int val){
        if(!node) return node;
        if(node->val==val) return node;
        
        if(node->val>val) return searchNode(node->left, val);
        else return searchNode(node->right, val);
    }
    
    void inorder(treeNode *node){
        if(!node) return;

        inorder(node->left);
        cout<<node->val<<"("<<node->count<<") ";
        inorder(node->right);
    }

    public:
    BST(): root(nullptr){}

    void insert(int val){
        treeNode *newNode=new treeNode(val);

        if(!root){
            root=newNode;
            return;
        }

        treeNode *parent, *current;
        current=root;

        while(current){
            parent=current;

            if(current->val==val){              // duplicate case
                current->count++;                   
                return;
            }
            if(current->val>val) current=current->left;
            else if(current->val<val) current=current->right;
        }

        if(parent->val>val) parent->left=newNode;
        else parent->right=newNode;
    }

    void remove(int val){
        root=del(root, val);                // deletion public wrapper
    }

    void showValueCount(int val){
        treeNode *temp=searchNode(root, val);

        cout<<"\n\nNumber of times "<<temp->val<<" has been inserted: "<<temp->count<<endl;
    }

    void inorderPrint(){
        cout<<"Inorder format: value(count)"<<endl;
        inorder(root);
    }
};

int main(){
    cout<<"Data Structures Assignment 3 - 24P-3017\n"<<endl;

    BST tree;

    tree.insert(40);
    tree.insert(14);
    tree.insert(50);
    tree.insert(45);
    tree.insert(80);
    tree.insert(10);
    tree.insert(19);
    tree.insert(12);
    tree.insert(17);
    tree.insert(60);
    tree.insert(46);
    tree.insert(42);
    tree.insert(17);
    tree.insert(80);
    tree.insert(14);
    tree.insert(14);
    tree.insert(11);
    
    cout<<"Base Tree:\n"<<endl;
    tree.inorderPrint();

    tree.remove(50);
    tree.remove(17);

    cout<<"\n\nTree after removing 50 and 17:\n"<<endl;
    tree.inorderPrint();

    tree.showValueCount(14);
}