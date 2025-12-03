#include <iostream>
using namespace std;

struct Node{int v;Node*l,*r;Node(int x){v=x;l=r=NULL;}};

Node*ins(Node*n,int x){
    if(!n)return new Node(x);
    if(x<n->v)n->l=ins(n->l,x);
    else if(x>n->v)n->r=ins(n->r,x);
    return n;
}

int cnt(Node*n,int a,int b){
    if(!n)return 0;
    if(n->v<a)return cnt(n->r,a,b);
    if(n->v>b)return cnt(n->l,a,b);
    return 1+cnt(n->l,a,b)+cnt(n->r,a,b);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node*r=NULL;
    r=ins(r,20);r=ins(r,10);r=ins(r,40);r=ins(r,5);r=ins(r,15);
    int a=5,b=45;
    cout<<cnt(r,a,b);
}
