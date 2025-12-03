#include <iostream>
using namespace std;
void swap (int array1[], int array2[]);

int main ()
{

    int array_a[5]={2, 1, 4, 5, 6};     //Arrays given in task
    int array_b[5]={5, 6, 9, 55, 76};

    cout<<"Arrays before swapping:\nArray A: "; //Displaying arrays before swapping
    for (int i=0; i<5; i++){
        cout<<array_a[i]<<" ";
    }
    cout<<"\nArray B: ";
    for (int i=0; i<5; i++){
        cout<<array_b[i]<<" ";
    }

    swap (array_a, array_b);    //Calling function to swap elements of arrays

}

void swap (int array1[], int array2[])
{

    int temp;   //Variable used for swapping
    for (int i=0; i<5; i++){
        temp=array1[i];
        array1[i]=array2[i];
        array2[i]=temp;
    }

    cout<<"\nArrays after swapping:\nArray A: ";  //Displaying arrays after swapping
    for (int i=0; i<5; i++){
        cout<<array1[i]<<" ";
    }
    cout<<"\nArray B: ";
    for (int i=0; i<5; i++){
        cout<<array2[i]<<" ";
    }

}