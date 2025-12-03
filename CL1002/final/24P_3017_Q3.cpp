#include <iostream>
using namespace std;

int factorial (int X);
int powerfunction (int X, int N);

int main ()
{

    //Declaration of variables storing X and number of terms N
    int X;
    int N;

    //Asking for X and N from user
    cout<<"Enter the value of X: ";
    cin>>X;
    cout<<"Enter the number of terms N: ";
    cin>>N;

    //Equating the answer by calling functions
    int i=0;
    int temp1=0;
    while(i<=N){
        temp1+=factorial(i);
        i=i+2;
    }

    int j=1;
    int temp2=0;
    while(j<=N){
        temp2+=powerfunction(X, N);
    }
    
    //Displaying answer according to equation
    cout<<"\n\nThe answer according to the equation is: ";
    cout<<temp1/temp2;
}

int factorial (int X)
{
    if (X==0){
        return 1;
    }
    else{
        return X*factorial(X-1);
    }
}

int powerfunction (int X, int N)
{
    for (int i=1; i<=N; i=i+2){
        X*=X;
    }
    return X;
}