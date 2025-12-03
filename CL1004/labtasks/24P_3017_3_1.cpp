#include <iostream>
using namespace std;
int slsv(int *a, int *b);

int main ()
{

    int *arr_a, *arr_b;

    arr_a=new int [5];
    arr_b=new int [5];

    cout<<"Enter elements for array a: ";
    for(int i=0; i<5; i++){
        cin>>arr_a[i];
    }
    cout<<"Enter elements for array b: ";
    for(int i=0; i<5; i++){
        cin>>arr_b[i];
    }

    cout<<"\nNumber of integers placed at same location with same value are: "<<slsv(arr_a, arr_b);
    
    delete[] arr_a;
    arr_a=NULL;
    delete[] arr_b;
    arr_b=NULL;

}

int slsv(int *a, int *b)
{

    int counter=0;

    for(int i=0; i<5; i++){
        if(*(a+i)==*(b+i)){
            counter++;
        }
    }

    return counter;

}