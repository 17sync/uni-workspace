#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of variables for selection of class, age and price
    int selection, age, price;

    //Displaying classes
    start:
    cout<<"Select a class:\n1. Economy\n2. Business\n3. First Class\n\nselection: ";
    cin>>selection;

    //Displaying prices for each class and confirming selection
    char confirm;
    switch (selection)
    {
        case 1:
        {
            cout<<"\n Economy: Rs.5000\nDo you want to confirm ticket purchase? (Y/N): ";
            cin>>confirm;
            if (confirm=='n'||confirm=='N')
            {
                goto start;
            }
            price=5000;
            break;
        }
        case 2:
        {
            cout<<"\n Business: Rs.12000\nDo you want to confirm ticket purchase? (Y/N): ";
            cin>>confirm;
            if (confirm=='n'||confirm=='N')
            {
                goto start;
            }   
            price=12000;
            break;
        }
        case 3:
        {
            cout<<"\n First Class: Rs.25000\nDo you want to confirm ticket purchase? (Y/N): ";
            cin>>confirm;
            if (confirm=='n'||confirm=='N')
            {
                goto start;
            }
            price=25000;
            break;
        }
        
        default:
        {
            cout<<"\nInvalid input";
            goto start;
            break;
        }
    }

    //Asking for age and applying discount
    cout<<"\nWhat is the passenger's age? ";
    cin>>age;
    if (age<12)
    {
        price*=0.5;
    }
    else if (age>60)
    {
        price*=0.8;
    }
    cout<<"\nYour total is: Rs."<<price;

}