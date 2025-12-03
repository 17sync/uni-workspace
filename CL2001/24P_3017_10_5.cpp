#include<iostream>
using namespace std;

struct N{int v,h;N*l,*r;N(int x):v(x),h(1),l(0),r(0){}};
int H(N*x){return x?x->h:0;}

void kthSmall(N*r,int&k,int&ans){
    if(!r)return;
    kthSmall(r->l,k,ans);
    if(--k==0){ans=r->v;return;}
    kthSmall(r->r,k,ans);
}

void kthLarge(N*r,int&k,int&ans){
    if(!r) return;
    kthLarge(r->r,k,ans);
    if(--k==0){ans=r->v; return;}
    kthLarge(r->l,k,ans);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    N*r=new N(30);
    r->l=new N(20);r->r=new N(40);
    r->l->l=new N(10);r->l->r=new N(25);

    int k1=2,ks,kl;
    kthSmall(r,k1,ks);
    int k2=2;
    kthLarge(r,k2,kl);

    cout<<"kthSmall="<<ks<<" kthLarge="<<kl<<"\n";
    cout<<"LeftH="<<H(r->l)<<" RightH="<<H(r->r);
}
