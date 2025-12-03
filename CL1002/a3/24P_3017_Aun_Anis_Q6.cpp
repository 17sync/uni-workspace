#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of size of the array
    int size;

    //Asking for size
    cout<<"Enter the size fo the array: ";
    cin>>size;
    
    //Declaration of array
    int a[size];

    //Asking for elements of the array
     cout<<"Enter elements of the array: ";
    for (int i=0; i<size; i++){
        cin>>a[i];
    }

    //Declaration of pointers for the array
    int *ptr_a1 = a;                        //pointer pointing at start of array
    int *ptr_a2 = &a[size-1];               //pointer pointing at end of array
 
    //Displaying the array before reversal
    cout<<"\nArray before reversal:\n a = [ ";
    for (int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<"]\n\n";

    //Reversing the array
    int temp;

    for (int i=0; i<size-1; i++){
        temp=*ptr_a1;
        *ptr_a1=*ptr_a2;
        *ptr_a2=temp;
        *ptr_a1++; 
        *ptr_a2--;
    }

    //Displaying the array after reversal
    cout<<"\nArray after reversal:\n a = [ ";
    for (int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<"]\n\n";

    
}