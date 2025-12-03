#include <iostream>
using namespace std;

int main ()
{
    //Declaration of variables for burger, pizza, sandwich and quantity
    int burger= 200;
    int pizza = 500;
    int sandwich = 100;
    int selection, quantity;
    int total = 0;
    char rerun, ph;

    //Displaying menu
    cout<<"\t||MENU||\n\n1. Pizza: Rs.500\n2. Burger: Rs.200\n3. Sandwich: Rs.100\n\n\t||PRICING||\n--> 15% surcharge in peak hours \n--> flat Rs.100 off on ordering more than 5 of the same item!\n--> 10% off on orders adding upto more than Rs.1000!)";
    
    //Calculating total bill
    do {
        start:
        //Asking for input from user
        cout<<"\n\nEnter corresponding number to select item: "; cin>>selection;
        cout<<"How many? "; cin>>quantity;
        
        //Calculating total bill
        if (selection>=1 && selection<=3)
        {    
            if (selection==1)
            {
                total+=500*quantity;
                if (quantity>5)
                {
                    total-=100;
                }
            }
            else if (selection==2)
            {
                total+=200*quantity;
                if (quantity>5)
                {
                    total-=100;
                }
            }
            else if (selection==3)
            {
                total+=100*quantity;
                if (quantity>5)
                {
                    total-=100;
                }
            }
        }
        else
        {
            cout<<"invalid input";
            goto start;
        }
        cout<<"\nDo you want to order another item? (Y/N): ";
        cin>>rerun;
    } while (rerun=='y'||rerun=='Y');

    //Asking for peak time
    ph:
    cout<<"\nIs it peak hours? (Y/N): ";
    cin>>ph;
    if (ph=='Y'||ph=='y'||ph=='N'||ph=='n')
    {
        if (ph=='Y'||ph=='y')
        {
            total*=1.15;
        }
    }
    else
    {
        cout<<"Invalid input";
        goto ph;
    }

    //Displaying total bill after applying discount
    if (total>1000)
    {
        total*=0.9;
    }
    cout<<"Your total is: Rs."<<total;

}