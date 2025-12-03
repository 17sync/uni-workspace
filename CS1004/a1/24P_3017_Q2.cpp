#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int main_diagonal_sum(int** matrix, int n);
int sec_diagonal_sum(int** matrix, int n);

int main(){
    int n;
    cout<<"Enter the size of the matrix (n x n): ";
    cin>>n;

    srand(time(0));

    int** matrix=new int*[n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[n];
        for (int j=0;j<n;j++){
            matrix[i][j]=rand()%100+1;
        }
    }   

    cout<<"\nMatrix ("<<n<<"x"<<n<<"):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    int main_sum=main_diagonal_sum(matrix, n);
    int sec_sum=sec_diagonal_sum(matrix, n);
    int absDifference=(main_sum>sec_sum)?(main_sum-sec_sum):(sec_sum-main_sum);

    cout<<"\nMain Diagonal Sum: "<<main_sum;
    cout<<"\nSecondary Diagonal Sum: "<<sec_sum;
    cout<<"\nAbsolute Difference: "<<absDifference<<endl;

    for (int i=0;i<n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main_diagonal_sum(int** matrix, int n){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=matrix[i][i];
    }
    return sum;
}

int sec_diagonal_sum(int** matrix, int n){
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=matrix[i][n-i-1];
    }
    return sum;
}
