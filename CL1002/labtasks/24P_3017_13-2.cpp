#include <iostream>
using namespace std;

void sum_upto_limit(int limit, int num, int &sum);

int main ()
{

    //Declaration of variables storing limit and sum
    int limit;
    int sum = 0;

    //Asking user for limit
    cout<<"Enter an integer: ";
    cin>>limit; cout<<endl;

    //Displaying sum uptil limit
    sum_upto_limit(limit, 2, sum);
    cout<<" = "<<sum;

}

void sum_upto_limit(int limit, int num, int &sum)
{
    if (num>limit){
        return;
    }
    else{
        cout<<" "<<num<<" + ";
        sum+=num;
        sum_upto_limit(limit, num+2, sum);
    }
}