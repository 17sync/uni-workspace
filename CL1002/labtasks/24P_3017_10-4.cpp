#include <iostream>
using namespace std;

int main ()
{

    //Declaration of array already given and order inducing variable
    int ascendingArray[] = {10, 2, 5, 3, 7, 9, 8, 2, 1};
    int order;

    //Arranging in Ascending order
    for (int i=0; i<9; i++){
        for (int j=i+1; j<9; j++){
            if (ascendingArray[i]>ascendingArray[j]){
                order=ascendingArray[i];
                ascendingArray[i]=ascendingArray[j];
                ascendingArray[j]=order;
            }
        }
    }

    //Displaying elements of the array after arrangement
    cout<<"Array arranged in ascending order:\n";
    for (int i=0; i<9; i++){
        cout<<ascendingArray[i]<<" ";
    }
    
}