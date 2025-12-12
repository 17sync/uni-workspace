#include<iostream>
#include<list>              // for easy separate chaining
using namespace std;

struct Pair{
    int a,b;
    Pair(int x,int y){a=x;b=y;}
};

class Hash{
    int buckets;
    list<Pair>*table;

public:
    Hash(int b){
        buckets=b;
        table=new list<Pair>[b];
    }

    int hashFunc(int key){
        return key%buckets;
    }

    void insertSum(int sum,int a,int b){
        int idx=hashFunc(sum);
        table[idx].push_back(Pair(a,b));
    }

    list<Pair>&getList(int sum){
        return table[hashFunc(sum)];
    }
};

void findPairs(int arr[],int n){
    Hash h(100);   

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a=arr[i],b=arr[j];
            int sum=a+b;

            list<Pair>&lst=h.getList(sum);

            for(auto &p:lst){
                int c=p.a,d=p.b;

                if(a!=c && a!=d && b!=c && b!=d){
                    cout<<"("<<a<<", "<<b<<") and ("<<c<<", "<<d<<")\n";
                    return;
                }
            }

            h.insertSum(sum,a,b);
        }
    }
    cout<<"No pairs found\n";
}

int main(){
    cout<<"24P-3017\n"<<endl;

    int a1[]={3,4,7,1,2,9,8};
    findPairs(a1,7);
    int a2[]={3,4,7,1,12,9};
    findPairs(a2,6);
    int a3[]={65,30,7,90,1,9,8};
    findPairs(a3,7);
}
