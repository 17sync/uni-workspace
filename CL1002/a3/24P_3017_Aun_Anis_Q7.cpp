#include <iostream>
using namespace std;

int main() 
{
    //Declaration of size of arrays
    int size;

    //Asking for size of arrays
    cout<<"Enter size of arrays: ";
    cin>>size;

    //Declaration of 3 arrays
    int a1[size]; 
    int a2[size]; 
    int sum[size];

    //Asking for a1
    cout<<"Enter elements of the array #1: ";
    for (int i=0; i<size; i++){
        cin>>a1[i];
    }

    //Asking for a2
    cout<<"Enter elements of array #2: ";
    for (int i=0; i<size; i++){
        cin>>a2[i];
    }

    //Declaration of 3 pointers pointing towards the 3 arrays
    int *ptr1 = a1;
    int *ptr2 = a2;
    int *ptrSum = sum;

    //Calculating element wise sum via pointers
    for (int i=0; i<size; i++) {
        *(ptrSum+i)=*(ptr1+i)+*(ptr2+i);
    }

    //Displaying element wise sum
    cout<<"Element-wise sum of the arrays: ";
    for (int i=0; i<size; i++){
        cout<<*(ptrSum+i)<<" ";
    }
    cout<<endl;

}
