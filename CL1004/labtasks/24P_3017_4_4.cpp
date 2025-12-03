#include <iostream>
using namespace std;
void transpose(int**, int, int); 

int main(){
    int row, col;
    cout<<"Enter number of rows: ";
    cin>>row;
    cout<<"Enter number of columns: ";
    cin>>col;

    int **matrix=new int*[row];
    for(int i=0;i<row;i++){
        matrix[i]=new int[col];
    }

    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }

    transpose(matrix, row, col);

    for(int i=0;i<row;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix=NULL;
}

void transpose(int **matrix, int row, int col){
    int **transpose=new int*[row];
    for(int i=0;i<row;i++){
        transpose[i]=new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            transpose[j][i]=matrix[i][j];
        }
    }

    cout<<"\nThe transpose of the matrix is:\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<transpose[i][j]<<"\t";
        }
        cout<<endl;
    }

    for(int i=0;i<row;i++){
        delete[] transpose[i];
    }
    delete[] transpose;
    transpose=NULL;
}