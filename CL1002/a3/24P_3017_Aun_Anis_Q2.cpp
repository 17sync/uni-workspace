#include <iostream>
using namespace std;
void duplicateremover (int array[], int &length);

int MAXLENGTH=50;

int main ()
{

    //Declaration of array and variable storing length
    int array[MAXLENGTH];
    int length;

    //Asking for length of array from user
    cout<<"Enter length of the array: ";
    cin>>length;

    //Asking for elements of the array from user
    cout<<"\nEnter the elements of the array: ";
    for (int i=0; i<length; i++){
        cin>>array[i];
    }

    //Calling function to remove duplicates from the array
    duplicateremover(array, length);

    //Displaying array after removing duplicates
    cout<<"\n\nArray after removing duplicates: ";
    for (int i=0; i<length; i++){
        cout<<array[i]<<" ";
    }
    
}

void duplicateremover (int array[], int &length)
{
    for (int i=0; i<length; i++){
        for (int j=i+1; j<length; j++){
            if (array[i]==array[j]){
                while (j<length){
                    array[j]=array[j+1];
                    j++;
                }
                --length;
            }
        }
    }
}