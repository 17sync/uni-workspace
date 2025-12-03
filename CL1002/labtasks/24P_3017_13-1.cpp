#include <iostream>
using namespace std;

void mt(int x, int y);

int main ()
{
    
    //Declaration of variables storing subject integer and factor
    int num;
    int factor = 1;

    //Displaying multiplication table via recursion
    cout<<"\t|| Multiplication Table ||";
    cout<<"\n\nEnter an integer: "; cin>>num;
    cout<<endl;
    mt(num, factor);

}

void mt(int x, int y)
{
    if(y==11){
        return;
    }
    else{
        cout<<x<<" x "<<y<<" = "<<x*y<<endl;
        mt(x, y+1);
    } 
}
