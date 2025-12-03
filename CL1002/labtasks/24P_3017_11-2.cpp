#include <iostream>
using namespace std;

int main() 
{
    //Declaration of 2d arrays storing 4x4 matrices
    int matrix[4][4];
    int transpose[4][4];

    //Asking for the elements of the 4x4 matrix
    cout << "Enter the elements of the 4x4 matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin>>matrix[i][j];
        }
    }

    // Compute the transpose of the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transpose[j][i]=matrix[i][j];
        }
    }

    // Display the transpose of the matrix
    cout << "Transpose of the matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout <<transpose[i][j]<< " ";
        }
        cout << endl;
    }

}
