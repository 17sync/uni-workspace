#include <iostream>
using namespace std;
int factorial(int n);
int sum_array(int arr[], int size);

int main() {
    int arr[5]={2, 4, 6, 8, 10};

    int sum=sum_array(arr, 5);
    int fact=factorial(5);

    cout<<"Sum of array elements: "<<sum<<endl;
    cout<<"Factorial of size: "<<fact<<endl;
}

int sum_array(int arr[], int size) {
    if (size==0) return 0;
    return arr[size-1]+sum_array(arr, size - 1); 
}

int factorial(int n) {
    if (n<=1) return 1; 
    return n*factorial(n-1); 
}
