#include <iostream>
using namespace std;
void reverse(int*, int*, int);
int second_largest(int*, int*, int);
void rotate(int *array, int *ptr, int size, int k);

int main(){
    int size=10;
    int array[size]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr=array;     //pointing to array[0]
    
    cout<<"Original: { ";     //displaying original array
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<"}\n\n";
    
    reverse(array, ptr, size);      //calling relevant function to reverse array
    
    cout<<"Second largest element: "<<second_largest(array, ptr, size);     //calling relevant function to find second largest element
    
    int k;
    cout<<"\n\nEnter k: ";
    cin>>k;
    
    rotate(array, ptr, size, k);        //calling relevant function to rotate array
}

void reverse(int *array, int *ptr, int size){
    int temp;       //variable for swapping values at indexes
    
    for(int i=0;i<size/2;i++){
        temp=*(ptr+i);
        *(ptr+i)=*(ptr+size-1-i);       //(ptr+i) moves forward, (ptr+size-1-i) moves backward
        *(ptr+size-1-i)=temp;           //(ptr+size-1-i) originally points at array[9]
    }

    cout<<"Reversed: { "; 
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<"}\n\n";
}

int second_largest(int *array, int *ptr, int size){
    int largest=0, second_largest=0;

    for(int i=0;i<size;i++){
        if(*(ptr+i)>largest){
            second_largest=largest;
            largest=*(ptr+i);
        }
        else if(*(ptr+i)>second_largest && *(ptr+i)!=largest){      
            second_largest=*(ptr+i);    
        }
                
    }

    return second_largest;
}

void rotate(int *array, int *ptr, int size, int k){
    k%=size;
    for (int i=0;i<k;i++){
        int last=*(ptr + size - 1);
        for (int j=size-1;j>0;j--){
            *(ptr+j)=*(ptr+j-1);
        }
        *ptr=last;
    }

    cout<<"\nRotated: { "; 
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<"}\n\n";
}