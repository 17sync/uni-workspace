#include <iostream>
using namespace std;

struct Node{int v;Node*l,*r;Node(int x){v=x;l=r=NULL;}};

bool isBST(Node*n,long mn,long mx){
    if(!n)return true;
    if(n->v<=mn||n->v>=mx)return false;
    return isBST(n->l,mn,n->v)&&isBST(n->r,n->v,mx);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node*r=new Node(10);
    r->l=new Node(5);
    r->r=new Node(20);
    r->r->l=new Node(15);
    cout<<isBST(r,-1e9,1e9);
}
