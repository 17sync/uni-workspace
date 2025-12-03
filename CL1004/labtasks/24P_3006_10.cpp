#include<iostream>
using namespace std;

void function(int i, int n){
    if(n==0){
        return;
    }
    else{
        cout<<" "<<i;
        function(i+2,n-1);
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Even numbers: ";
    function(2, n);
}