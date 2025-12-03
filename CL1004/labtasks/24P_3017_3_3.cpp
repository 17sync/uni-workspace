#include <iostream>
using namespace std;
void swap(int*, int*);

int main ()
{

    int *ptr_a;     //Pointers pointing to the dynamic integers
    int *ptr_b;
    
    ptr_a = new int;
    ptr_b = new int;

    *ptr_a = 777;
    *ptr_b = 666;

    cout<<"Before swapping:\ninteger a: " <<*ptr_a<<"\ninteger b: "<<*ptr_b;       //Displaying integers before swapping   
    
    swap(ptr_a, ptr_b);     //Calling relevant function to perform swapping

    delete ptr_a;
    ptr_a = NULL;
    delete ptr_b;
    ptr_b = NULL;

}

void swap(int *ptr_a, int *ptr_b)
{

    int temp;       //Variable for swapping

    temp=*ptr_a;        //Swapping integers
    *ptr_a=*ptr_b;
    *ptr_b=temp;

    cout<<"\nAfter swapping:\ninteger a: " <<*ptr_a<<"\ninteger b: "<<*ptr_b;      //Displaying integers after swapping

}