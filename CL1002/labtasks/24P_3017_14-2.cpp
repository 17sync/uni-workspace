# include <iostream>
using namespace std ;
int main ()
{
    
    //Declaration of variables storing integers
    int num1, num2;
    
    //Declaration of pointers for both integers and swapping
    int *swap, *ptr1, *ptr2;
     
    //Asking for both integers from user
    cout<<"Enter integer 1: ";
    cin>>num1;
    cout<<"Enter integer 2: ";
    cin>>num2 ;

    //Defining both pointers
    ptr1 = &num1 ;
    ptr2 = &num2 ;
     
    //Swapping integers
     swap = ptr1 ;
     ptr1 = ptr2 ;
     ptr2 = swap ;
     
     //Displaying both integers after swapping
     cout<<"\nInteger 1: "<<*ptr1;
     cout<<"\nInteger 2: "<<*ptr2;
     
}