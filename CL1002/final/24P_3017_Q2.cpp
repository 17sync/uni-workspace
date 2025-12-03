#include <iostream>
using namespace std;
void subtraction (int a[5], int b[5]);

int main ()
{

    //Declaration of two arrays
    int a[5]={10,20,30,40,50};
    int b[5]={1,2,3,4,5};
    
    //Displaying arrays before operation
    cout<<"Before Operation:\n\narray_a = [ ";
    for (int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
    cout<<"]\n";
    cout<<"array_b = [ ";
    for (int i=0; i<5; i++){
        cout<<b[i]<<" ";
    }
    cout<<"]";
    
    //Declaration of two pointers pointing at the two arrays respectively
    int *ptra=&a[5];
    int *ptrb=&b[5];

    //Calling function to perform subtraction
    subtraction(a, b);

}

void subtraction (int a[5], int b[5])
{

    //Declaration of two pointers pointing at the two arrays respectively
    int *ptra=&a[5];
    int *ptrb=&b[5];
    
    //performing the subtraction
    int temp;
    for (int i=0; i<3; i++){
        temp=*ptra-*ptrb;
        a[i]=temp;
        ptra=ptra+2;
        ptrb=ptrb+2;
    }

    int *ptrc=&a[5];        //Redeclaring to reset address stored in pointer
    int *ptrd=&b[5];
    ptrc++; ptrd++; 

    for (int i=0; i<2; i++){
        temp=*ptrd-*ptrc;
        a[i]=temp;
        ptrc=ptrc+2;
        ptrd=ptrd+2;
    }

    //Displaying arrays after operation
    cout<<"\n\nAfter Operation:\n\narray_a = [ ";
    for (int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
    cout<<"]\n";
    cout<<"array_b = [ ";
    for (int i=0; i<5; i++){
        cout<<b[i]<<" ";
    }
    cout<<"]";
    
}


