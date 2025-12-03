#include <iostream>
using namespace std;
int sv(int *a, int *b);

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

    cout<<"\nNumber of elements common: "<<sv(arr_a, arr_b);
    
    delete[] arr_a;
    arr_a=NULL;
    delete[] arr_b;
    arr_b=NULL;

}

int sv(int *a, int *b)
{

    int counter=0;

    for(int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if(*(a+i)==*(b+j)){
                counter++;
            }
        }
    }

    return counter;

}