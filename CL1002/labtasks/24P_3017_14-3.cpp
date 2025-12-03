#include <iostream>
using namespace std;

int main ()
{

    //Declaration of array
    int a[10] = {5, 3, 2, 1, 10, 12, 45, 68, 11, 89};

    //Declaration of pointers for the array
    int *ptr_a1 = a;                        //pointer pointing at start of array
    int *ptr_a2 = &a[9];                    //pointer pointing at end of array
 
    //Displaying the array before reversal
    cout<<"Array before reversal:\n a = [ ";
    for (int i=0; i<10; i++){
        cout<<a[i]<<" ";
    }
    cout<<"]\n\n";

    //Reversing the array
    int temp;

    for (int i=0; i<9; i++){
        temp=*ptr_a1;
        *ptr_a1=*ptr_a2;
        *ptr_a2=temp;
        *ptr_a1++; 
        *ptr_a2--;
    }

    //Displaying the array after reversal
    cout<<"\nArray after reversal:\n a = [ ";
    for (int i=0; i<10; i++){
        cout<<a[i]<<" ";
    }
    cout<<"]\n\n";

    
}