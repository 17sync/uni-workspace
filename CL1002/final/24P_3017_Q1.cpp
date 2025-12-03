#include <iostream>
using namespace std;

void finallistmaker (int score[25]);

int main ()
{

    //Declaration of array containing scores for 25 students
    int score[25];

    //Asking user to input scores of the array
    cout<<"Enter scores for the 25 participants:\n";
    for (int i=0; i<25; i++){
        do{
            cin>>score[i];
            if (score[i]<=50)   //Condition to equate the index value to 0 if it is less than 50
            {
                score[i]=0;
            }
            else if (score[i]<0 || score[i]>100){
                    cout<<"ERROR--> Invalid score\n";
            }
        }while(score[i]<0 || score[i]>100);
    }

    //Calling function to remove duplicates and display final list
    finallistmaker(score);
}

void finallistmaker (int score[25])
{

    //Checking for duplicates and storing scores in another array
    int uniquescores = 0;
    for (int i=0; i<25; i++) {
        if (i==0 || score[i]!=score[i-1]) {
            score[uniquescores++] = score[i];
        }
    }

    //Sorting the array in descending order
    for (int i=0; i<25-1; i++) {
        for (int j=0; j<25-i-1; j++) {
            if (score[j]<score[j+1]) {
                int temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
            }
        }
    }

    //Displaying array in descending order
    cout<<"The final scores list is (excluding duplicates):\n";
    for (int i=0; i<25; i++){
        cout<<score[i]<<endl;
    }
    
}
