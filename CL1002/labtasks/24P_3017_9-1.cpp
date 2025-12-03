#include <iostream>
using namespace std;

int main ()
{

    //Declaration of two variables for row and column
    int i = 1;
    int j;

    //Displaying pattern
    do
    {   

        j = 5;
        
        while (j>=i)
        {
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;

    }while (i<=5);
    
}
