#include <iostream>
using namespace std;

int main ()
{

    //Declaration of 2 arrays given in Qs
    int A[5] = {54, 2, 37, 7, 45};
    int B[5] = {51, 2, 45, 1, 6};

    //Displaying both arrays
    cout<<"array_A = [ ";
    for (int i=0; i<5; i++){
        cout<<A[i]<<" ";
    }
    cout<<"]\n";

    cout<<"array_B = [ ";
    for (int i=0; i<5; i++){
        cout<<B[i]<<" ";
    }
    cout<<"]\n\n";

    //Declaration of 2 pointers for each array
    int *pA = A;
    int *pB = B;
    
    //Part A: Checking for same location + same value
    int checkA = 0;
    for (int i=0; i<5; i++){
        if (*pA == *pB){
            checkA++;
        }
        pA++; pB++;
    }
    cout<<"Number of integers having common location and value: "<<checkA;

    //Part B: Checking for common elements regardless of address
    pA = A;                                                         //Resetting address stored in both pointers
    pB = B;                                                         
    
    int checkB = 0;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (A[i]==B[j]){
                checkB++;
            }
        }
    }
    cout<<"\nNumber of common elements regardless of address: "<<checkB;

}