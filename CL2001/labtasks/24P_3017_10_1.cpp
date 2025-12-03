#include<iostream>
using namespace std;

struct Node{int v;Node*l;Node*r;Node(int x):v(x),l(0),r(0){}};

int h(Node*x){return x?1+max(h(x->l),h(x->r)):0;}
int bf(Node*x){return h(x->l)-h(x->r);}

Node*rr(Node*y){Node*x=y->l;y->l=x->r;x->r=y;return x;}      
Node*lr(Node*x){Node*y=x->r;x->r=y->l;y->l=x;return y;}      

Node*balance(Node*r){
    int b=bf(r);
    if(b>1){
        if(bf(r->l)<0)r->l=lr(r->l); // Left-Right case
        return rr(r);
    }
    if(b<-1){
        if(bf(r->r)>0)r->r=rr(r->r); // Right-Left case
        return lr(r);
    }
    return r;
}

Node*convert(Node*r){
    if(!r)return 0;
    r->l=convert(r->l);
    r->r=convert(r->r);
    return balance(r);
}

int main(){
    cout<<"24P-3017\n"<<endl;
}
