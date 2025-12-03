#include <iostream>
using namespace std;

struct Node{int id,q;Node*l,*r;Node(int i,int x){id=i;q=x;l=r=NULL;}};

Node*ins(Node*n,int id,int q){
    if(!n)return new Node(id,q);
    if(id<n->id)n->l=ins(n->l,id,q);
    else if(id>n->id)n->r=ins(n->r,id,q);
    else n->q=q;
    return n;
}

Node*src(Node*n,int id){
    if(!n||n->id==id)return n;
    if(id<n->id)return src(n->l,id);
    return src(n->r,id);
}

void mx(Node*n,Node*&best){
    if(!n)return;
    if(!best||n->q>best->q)best=n;
    mx(n->l,best);mx(n->r,best);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node*r=NULL;
    r=ins(r,50,10);
    r=ins(r,20,5);
    r=ins(r,70,30);
    r=ins(r,30,8);
    r=ins(r,80,25);

    Node*best=NULL;
    mx(r,best);
    cout<<best->id<<" "<<best->q;
}
