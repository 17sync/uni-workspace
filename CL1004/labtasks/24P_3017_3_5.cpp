#include <iostream>
using namespace std;
void addition(int*, int*);

int main ()
{

    int *arr1;      //Pointers pointing to each dynamic array
    int *arr2;

    int size = 3;       //max size of arrays (1D matrix)   

    arr1 = new int[size];       //Declaration of dynamic arrays       
    arr2 = new int[size];

    cout<<"Enter the elements (3) of array #1: ";       //Asking user to input the elements of the dynamic arrays
    for (int i=0; i<3; i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elements (3) of array #2: ";
    for (int i=0; i<3; i++){
        cin>>arr2[i];
    }

    addition(arr1, arr2);       //Calling relevant function to perform addition

    delete[] arr1;      //Deleting dynamic arrays
    arr1 = NULL;
    delete[] arr2;
    arr2 = NULL;

}

void addition(int *arr1, int *arr2)
{

    int add[3];     //Declaration of array storing the addition of the 2 dynamic arrays

    for (int i=0; i<3; i++){        //Adding the 2 dynamic arrays
        add[i] = *(arr1+i)+*(arr2+i);
    }

    cout<<"\nAfter matrix addition: ";      //Displaying the array storing the added elements
    for (int i=0; i<3; i++){
        cout<<add[i]<<" ";
    }

}