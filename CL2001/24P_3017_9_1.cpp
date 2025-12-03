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

Node*mn(Node*n){while(n->l)n=n->l;return n;}

Node*del(Node*n,int x){
    if(!n)return n;
    if(x<n->v)n->l=del(n->l,x);
    else if(x>n->v)n->r=del(n->r,x);
    else{
        if(!n->l)return n->r;
        if(!n->r)return n->l;
        Node*t=mn(n->r);
        n->v=t->v;
        n->r=del(n->r,t->v);
    }
    return n;
}

void in(Node*n){if(!n)return;in(n->l);cout<<n->v<<" ";in(n->r);}
void pre(Node*n){if(!n)return;cout<<n->v<<" ";pre(n->l);pre(n->r);}
void post(Node*n){if(!n)return;post(n->l);post(n->r);cout<<n->v<<" ";}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node*r=NULL;
    r=ins(r,20);
    r=ins(r,10);
    r=ins(r,30);
    r=ins(r,5);
    in(r);cout<<"\n";
    pre(r);cout<<"\n";
    post(r);cout<<"\n";
    r=del(r,10);
    in(r);
}
