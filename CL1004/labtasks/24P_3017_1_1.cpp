#include <iostream>
using namespace std;
void display (int array[]);
void initiate (int array[]);
void sort (int array[]);

int main ()
{

    int array[25];  //Array storing 25 readings
    
    cout<<"Enter 25 positive integers (10-100): \n";
    
    initiate (array);   //Calling functions to initiate and display the array respectively
    display (array);
    sort (array);

}

void initiate (int array[])
{

    for (int i=0; i<25; i++){
        do{
            cin>>array[i];
            if (array[i]<10 || array[i]>100){     //Condition to keep readings between 10-100 and avoid duplicates
                cout<<"ERROR---> Invalid Input, try again.\n";
            }
        }while(array[i]<10 || array[i]>100);
    }

}

void sort (int array[])
{

    int length=25;     //Variable storing length of variable

    for (int i=0; i<length; i++){       //Removing duplicates
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

void display (int array[])
{
    cout<<"\nUnqiue array readings:\n";
    for (int i=0; i<25; i++){   //Displaying array
        cout<<array[i]<<endl;
    }

}