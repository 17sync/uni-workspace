#include <iostream>
using namespace std;

void maxHeapify(int a[], int n, int i){
    int l = 2*i + 1, r = 2*i + 2, largest = i;
    if(l<n && a[l] > a[largest]) largest = l;
    if(r<n && a[r] > a[largest]) largest = r;
    if(largest != i){
        int t = a[i]; a[i] = a[largest]; a[largest] = t;
        maxHeapify(a, n, largest);
    }
}

void minHeapify(int a[], int n, int i){
    int l = 2*i + 1, r = 2*i + 2, smallest = i;
    if(l<n && a[l] < a[smallest]) smallest = l;
    if(r<n && a[r] < a[smallest]) smallest = r;
    if(smallest != i){
        int t = a[i]; a[i] = a[smallest]; a[smallest] = t;
        minHeapify(a, n, smallest);
    }
}

int main(){
    cout<<"24P-3017\n"<<endl;

    int arr[10] = {25,30,35,11,15,19,18,55,78,36};

    int maxH[10], minH[10];
    for(int i=0;i<10;i++){
        maxH[i] = arr[i];
        minH[i] = arr[i];
    }

    int n = 10;
    for(int i=n/2-1;i>=0;i--) maxHeapify(maxH, n, i);

    int del = 55;
    for(int i=0;i<n;i++)
        if(maxH[i] == del){
            maxH[i] = maxH[n-1];
            n--;
            maxHeapify(maxH, n, i);
            break;
        }

    cout<<"Max Heap after deleting 55: ";
    for(int i=0;i<n;i++) cout<<maxH[i]<<" ";
    cout<<"\n";

    int m = 10;
    for(int i=m/2-1;i>=0;i--) minHeapify(minH, m, i);

    del = 18;
    for(int i=0;i<m;i++)
        if(minH[i] == del){
            minH[i] = minH[m-1];
            m--;
            minHeapify(minH, m, i);
            break;
        }

    cout<<"Min Heap after deleting 18: ";
    for(int i=0;i<m;i++) cout<<minH[i]<<" ";
    cout<<"\n";

    int size = n;
    for(int i=size-1;i>0;i--){
        int t = maxH[0]; maxH[0] = maxH[i]; maxH[i] = t;
        maxHeapify(maxH, i, 0);
    }

    cout<<"Sorted max heap: ";
    for(int i=0;i<size;i++) cout<<maxH[i]<<" ";
}
