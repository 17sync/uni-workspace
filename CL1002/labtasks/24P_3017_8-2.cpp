#include <iostream>
using namespace std;

int main ()
{
     
     //Declaration of repitition variable
     char rerun;

     //Multiplication table loop
     do
     {
        //Declaration of number, factor and rerun
        int num, factor;
        factor = 1;

        //Asking for number
        cout<<"Enter a number to print its multiplication table: ";
        cin>>num;

        //Displaying multiplication table
        for (; factor >=1 && factor <=10; factor++ )
        {
            cout<<num<<" x "<<factor<<" = "<<num*factor<<endl;
        }

        rr:
        cout<<"Do you want to print another table? (Y/N): ";
        cin>>rerun;
        if (rerun == 'n' || rerun == 'N')
        {
            cout<<"Program ended.";
        }
        else if ((rerun != 'y' && rerun != 'Y') && (rerun != 'n' && rerun != 'N'))
        {
            cout<<"Invalid response."<<endl;
            goto rr;
        }  
     } 
     while (rerun == 'Y' || rerun == 'y');

}