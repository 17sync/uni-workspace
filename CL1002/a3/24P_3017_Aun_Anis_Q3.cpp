#include <iostream>
using namespace std;
void combinations(int candidates[], int n, int target, int current[], int currentSize, int start, int result[][150], int& resultCount);

int main() 
{

    //Declaration of integer target and size of array
    int target; 
    int size;

    //Asking for size of array from user
    cout<<"Enter the number of candidates (1D array): ";
    cin>>size;

    //Declaration of array for candidates
    int candidates[size];

    //Asking for candidates from user
    cout<<"Enter candidates: ";
    for (int i=0; i<size; ++i){
        cin>>candidates[i];
    }

    //Asking for target integer
    cout<<"Enter target integer: ";
    cin>>target;

    //Declaration of necessary tools for combination function
    int presentcombos[150];                 //Stores present combinations
    int allcombos[150][150];                //Stores all combinations
    int combocount=0;                       //Counts valid combinations

    //Calling function to calculate valid combinations
    combinations(candidates, size, target, presentcombos, 0, 0, allcombos, combocount);

    //Displaying all valid combinations
    cout<<"Valid Combinations:\n";
    for (int i = 0; i < combocount; ++i){
        cout << "[";
        for (int j = 0; allcombos[i][j] != -1; ++j){
            cout << allcombos[i][j];
            if (allcombos[i][j + 1] != -1) cout << ",";
        }
        cout << "]\n";
    }

}

void combinations(int candidates[], int n, int target, int current[], int currentsize, int start, int result[][150], int& resultcount) 
{

    if (target==0){
        for (int i=0; i<currentsize; ++i){
            result[resultcount][i]=current[i];
        }
        result[resultcount][currentsize]=-1;
        resultcount++;
        return;
    }
    for (int i=start; i<n; ++i){
        if (candidates[i]<=target){
            current[currentsize]=candidates[i];
            combinations(candidates, n, target-candidates[i], current, currentsize + 1, i, result, resultcount);
        }
    }
    
}
