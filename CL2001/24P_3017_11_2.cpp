#include<iostream>
using namespace std;

void heapifyDown(int h[], int n, int i){
    int l=2*i+1, r=2*i+2, largest=i;
    if(l<n && h[l]>h[largest]) largest=l;
    if(r<n && h[r]>h[largest]) largest=r;
    if(largest!=i){ 
        swap(h[i], h[largest]); heapifyDown(h, n, largest);
    }
}

int main() {
    cout<<"24P-3017\n"<<endl;

    int heap[10]={50, 30, 40, 10, 20};
    int size=5;

    heap[0]=heap[size-1];
    size--;
    heapifyDown(heap, size, 0);

    for (int i=0;i<size;i++) cout<<heap[i]<< " ";
}
