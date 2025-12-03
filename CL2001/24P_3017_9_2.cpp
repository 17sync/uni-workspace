#include <iostream>
using namespace std;

struct Node{int v;Node*l,*r;Node(int x){v=x;l=r=NULL;}};

Node*ins(Node*n,int x){
    if(!n)return new Node(x);
    if(x<n->v)n->l=ins(n->l,x);
    else if(x>n->v)n->r=ins(n->r,x);
    return n;
}

Node*src(Node*n,int x){
    if(!n||n->v==x)return n;
    if(x<n->v)return src(n->l,x);
    return src(n->r,x);
}

void in(Node*n){if(!n)return;in(n->l);cout<<n->v<<" ";in(n->r);}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node*r=NULL;
    r=ins(r,10);r=ins(r,5);r=ins(r,20);
    int x;cin>>x;
    if(!src(r,x))r=ins(r,x);
    in(r);
}
