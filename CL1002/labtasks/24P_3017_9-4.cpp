#include <iostream>
using namespace std;

int main() {
	
//Declaration of number and summation		
int i=1;
int num;
int sum;

//Asking for number    	
cout<<"Enter a number: ";    	
cin>>num;

//Displaying pattern
for(i=1;i<=num;i++){
    if(num%i==0){
      cout<<i<<endl;
        sum+=i;
     }
        
    }
    sum-=num;
    
    if(sum==num)
    cout<<"\n The number "<<sum<<" is a perfect number";
    else
    cout<<"\n The number "<<sum<<" is not a perfect number";
}
