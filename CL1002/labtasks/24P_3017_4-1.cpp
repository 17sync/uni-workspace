#include <iostream>
using namespace std;

int main ()
{

    //Declaration of x, y, z, answer 1 and 2
    int x, y, z, ans1, ans2;
    x = 10;
    y = 5;
    z = 22;
    ans1 = z*x+y;
    ans2 = z*(x+y);
    
    //Showing initial output with operations on terminal
    cout<<"z * x+y is: "<<ans1<<"\n";
    cout<<"z * (x+y) is: "<<ans2<<"\n";

    //Showing final output after increment and decrement on terminal
    cout<<"Answer 1 after decrement: "<<--ans1<<"\n";
    cout<<"incrementing z: "<<z++<<"\n";
    cout<<"Answer 2 after incrementing z: "<<z*(x+y)<<endl;

}