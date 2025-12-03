#include <iostream>
using namespace std;

void heapifyUp(int heap[], int index){
    while(index>0){
        int parent=(index - 1)/2;

        if(heap[parent]>heap[index]){
            swap(heap[parent], heap[index]);
            index = parent;
        } else break;
    }
}

int main(){
    cout<<"24P-3017\n"<<endl;

    int heap[10]={1, 3, 5, 4};  
    int size=4;

    int newPackage=2;
    heap[size]=newPackage;
    size++;

    heapifyUp(heap, size-1);
    
    for (int i=0;i<size;i++)
        cout << heap[i] << " ";
}
