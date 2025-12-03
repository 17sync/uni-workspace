#include <iostream>
using namespace std;

int main ()
{
    /*Example from Question*/
    
    //Declaration of example array (given in question)
    char ex[5][5] = {"Read", "Bear", "Hat", "beat", " "};

    //Displaying example array before swapping
    cout<<"Example array before swapping: ";
    for (int i=0; i<5; i++){
        cout<<ex[i]<<" ";
    }

    //Swapping R and B
    char temp1;
    temp1 = ex[0][0];
    ex[0][0] = ex[1][0];
    ex[1][0] = temp1;  

    //Swapping b and H
    char temp2;
    temp2 = ex[2][0];
    ex[2][0] = ex[3][0];
    ex[3][0] = temp2;

    //Displaying example array after swapping
    cout<<"\nExample array after swapping: ";
    for (int i=0; i<5; i++){
        cout<<ex[i]<<" ";
    }

    /*Taking Input from User*/

    //Declaration of array and variable storing total characters
    char array[5][5];
    int tc = 0;

    //Asking for a string array from the user
    cout<<"\n\nEnter a string array (max 4 letters and words): ";
    for(int i=0; i<5; i++){
        cin>>array[i];
    }

    //Swapping [0][0] and [1][0]
    temp1 = array[0][0];
    array[0][0] = array[1][0];
    array[1][0] = temp1; 

    //Swapping [2][0] and [3][0]
    temp2 = array[2][0];
    array[2][0] = array[3][0];
    array[3][0] = temp2;

    //Displaying array after swapping
    cout<<"Array after swapping: ";
    for (int i=0; i<5; i++){
        cout<<array[i]<<" ";
    }
    
    //Calculating total # of characters in the array
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (array[i][j]=='\0'){
                break;
            }
            tc++;
        }
    }

    //Displaying total # of characters in the array
    cout<<"\nTotal number of characters in the array: "<<tc;

}