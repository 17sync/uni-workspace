#include<iostream>
using namespace std;

struct N{int v,h;N*l,*r;N(int x):v(x),h(1),l(0),r(0){}};

int H(N*x){return x?x->h:0;}
int B(N*x){return H(x->l)-H(x->r);}
N*U(N*x){x->h=1+max(H(x->l),H(x->r));return x;}

N*LR(N*x){N*y=x->r;x->r=y->l;y->l=x;U(x);U(y);return y;}
N*RR(N*x){N*y=x->l;x->l=y->r;y->r=x;U(x);U(y);return y;}

N*ins(N*r,int k){
    if(!r)return new N(k);
    if(k<r->v)r->l=ins(r->l,k);else r->r=ins(r->r,k);
    U(r);
    int b=B(r);
    if(b>1&&k<r->l->v)return RR(r);
    if(b<-1&&k>r->r->v)return LR(r);
    if(b>1&&k>r->l->v){r->l=LR(r->l);return RR(r);}
    if(b<-1&&k<r->r->v){r->r=RR(r->r);return LR(r);}
    return r;
}

int main(){
    cout<<"24P-3017\n"<<endl;

    N*r=0;
    int a[]={10,20,30,40,50};
    for(int x:a)r=ins(r,x);
    r=ins(r,15);
    cout<<"Height="<<H(r);
}
