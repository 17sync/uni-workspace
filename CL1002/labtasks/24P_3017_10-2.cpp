#include <iostream>
using namespace std;

int main ()
{

    //Declaration of arrays already given
    int array_A[5] = {54, 2, 37, 7, 45};
    int array_B[5] = {51, 2, 45, 1, 6};

    //Declaration of variable counting similar values
    int counter = 0;

    //Loop for check
    for (int i=0; i<5; i++){
        if (array_A[i]==array_B[i]){
            counter++;
        }
    }

    //Displaying counter
    cout<<"Number of integers placed at the same location with the same value: "<<counter;
    
}