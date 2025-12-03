#include <iostream>
using namespace std;
int main (){

//Declaration of rows and columns
int i;
int j;
int row;

//Asking for number of rows and symbols
cout<<"number of rows ";cin >>row;
cout<<"symbol: ";char symbol;
cin>>symbol;

//Displaying pattern
  for(i=1;i<=row;i++){
    for(j=1;j<=i;j++){
        cout<<symbol;
    }
    cout<<endl;
    }
     
    for(i=row;i>=1;i--){
        for(j=1;j<=i;j++){
             cout<<symbol;
    }
    cout<<endl;
    } 
}
