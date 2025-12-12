#include<iostream>
#include<list>
using namespace std;

class Hash{
    int buckets;
    list<int>*table;

public:
    Hash(int b){
        buckets=b;
        table=new list<int>[b];
    }

    int hashFunc(int key){
        return key%buckets;
    }

    void insertItem(int key){
        int idx=hashFunc(key);
        table[idx].push_back(key);
    }

    void deleteItem(int key){
        int idx=hashFunc(key);
        table[idx].remove(key);
    }

    bool searchItem(int key){
        int idx=hashFunc(key);
        for(int x:table[idx]) if(x==key) return true;
        return false;
    }

    void display(){
        for(int i=0;i<buckets;i++){
            cout<<i<<": ";
            for(int x:table[i]) cout<<x<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    Hash h(7);
    h.insertItem(10);
    h.insertItem(20);
    h.insertItem(15);
    h.insertItem(7);
    h.insertItem(22);

    h.display();

    cout<<"Search 15: "<<(h.searchItem(15)?"Found":"Not Found")<<endl;
    h.deleteItem(15);
    cout<<"After delete:\n";
    h.display();
}
