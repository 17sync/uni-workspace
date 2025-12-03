#include <iostream>
using namespace std;

int main() 
{
    //Declaration of variables for size of rows and columns
    int rA, cA, rB, cB;

    //Asking for dimensions of matrix A and B
    cout <<"Enter the number of rows and columns of Matrix A: ";
    cin >>rA>>cA;
    cout<<"Enter the number of rows and columns of Matrix B: ";
    cin>>rB>>cB;

    // Check if matrix multiplication is possible
    if (cA != rB) {
        cout<<"Matrices cannot be multiplied. Number of columns of Matrix A must equal number of rows of Matrix B.\n";
        return 0;
    }

    // Declare matrices A, B, and the result matrix C
    int matrixA[rA][cA];
    int matrixB[rB][cB];
    int result[rA][cB];

    //Initialize result matrix with 0
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
        }
    }

    //Asking for elements of matrix A and B
    cout <<"Enter the elements of Matrix A:"<< endl;
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            cin>>matrixA[i][j];
        }
    }
    cout<<"Enter the elements of Matrix B:"<< endl;
    for (int i = 0; i < rB; i++) {
        for (int j = 0; j < cB; j++) {
            cin >> matrixB[i][j];
        }
    }

    //Computing matrix multiplication
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            for (int k = 0; k < cA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    //Displaying the resultant matrix
    cout << "Resultant Matrix after multiplication:" << endl;
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            cout<<result[i][j]<< " ";
        }
        cout<<endl;
    }
    
    return 0;

}
