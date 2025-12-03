#include <iostream>
using namespace std;

int main ()
{
    //Declaration of variables storing operands and type of arithmetic operation
    int a, b;
    char operation;

    //Asking for operands from user
    cout<<"Enter two operands: ";
    cin>>a>>b;

    //Asking for type of operation from user
    cout<<"select operation (+ - * /): ";
    cin>>operation;

    //Performing operation
    switch (operation)
    {
        case ('+'):
            cout<<"\n"<<a<<" + "<<b<<" = "<<a+b;
            break;
        case ('-'):
            cout<<"\n"<<a<<" - "<<b<<" = "<<a-b;
            break;
        case ('*'):
            cout<<"\n"<<a<<" x "<<b<<" = "<<a*b;
            break;
        case ('/'):
            cout<<"\n"<<a<<" / "<<b<<" = "<<a/b;
    }
}