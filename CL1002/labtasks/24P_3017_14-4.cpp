#include<iostream>
using namespace std;

void addM(int*, int*, int*, int);
void displayM(int*, int);

int main() 
{

    //Declaration of matrix size and arrays representing each matrix 
    int size = 6;
    int m1[] = {2, 4, 6, 8, 10, 12};
    int m2[] = {1, 3, 5, 7, 9, 11};

    //Calling Functions to perform addition and printing
    int sum[6] = {0};
    addM(m1, m2, sum, size);
    cout << "Matrix 1: ";
    displayM(m1, size);
    cout << "Matrix 2: ";
    displayM(m2, size);
    cout << "\nMatrix 1 + Matrix 2: ";
    displayM(sum, size);
    return 0;
}

void addM(int* matrix1, int* matrix2, int* sum, int size) 
{
    for (int i = 0; i < size; i++) {
        *(sum + i) = *(matrix1 + i) + *(matrix2 + i);
    }
}

void displayM(int* matrix, int size) 
{
    for (int i = 0; i < size; i++) {
        cout << *(matrix + i) << " ";
    }
    cout << endl;

}
