#include <iostream>
#include <vector>
using namespace std;

struct Node{int v;Node*l,*r;Node(int x){v=x;l=r=NULL;}};

Node*ins(Node*n,int x){
    if(!n)return new Node(x);
    if(x<n->v)n->l=ins(n->l,x);
    else if(x>n->v)n->r=ins(n->r,x);
    return n;
}

void inA(Node*n,vector<int>&a){
    if(!n)return;
    inA(n->l,a);a.push_back(n->v);inA(n->r,a);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    Node*r=NULL;
    r=ins(r,20);r=ins(r,10);r=ins(r,30);r=ins(r,5);r=ins(r,15);

    vector<int>a;inA(r,a);
    int n=a.size();
    if(n%2)cout<<a[n/2];
    else cout<<(a[n/2-1]+a[n/2])/2.0;
}
