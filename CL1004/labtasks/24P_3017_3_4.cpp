#include <iostream>
using namespace std;
void reverse (int*, int*, int);

int main ()
{

    int *ptr1;
    int *ptr2;

    int size;
    cout<<"Enter the size of the dynamic array: ";
    cin>>size;

    ptr1 = new int[size];
    ptr2 = &ptr1[size-1];

    cout<<"Enter the elements of the dynamic array: ";
    for (int i=0; i<size; i++){
        cin>>ptr1[i];
    }

    reverse (ptr1, ptr2, size);

    delete[] ptr1;
    ptr1 = NULL;

}

void reverse (int *ptr1, int *ptr2, int size)
{

    int temp;
    for (int i=0; i<size; i++){
        temp=ptr1[size+i];
        ptr1[size+i]=*(ptr2-i);
        *(ptr2-i)=temp;
    }

    cout<<"\nAfter reversal: ";
    for (int i=0; i<size; i++){
        cout<<ptr1[i]<<" ";
    }

}