#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of variables storing account pin, operations and rerun
    int pin, operation, deposit, withdraw, balance;
    char rerun;

    //Displaying ATM heading
    cout<<"\t|BANK ATM SIMULATION|";

    //Asking for pin
    cout<<"\n\nEnter 4-digit pin: "; cin>>pin;
    for (int i=2; i>=2 && i<=3; i++)
    {
        if (pin!=2005)
        {
            cout<<"Incorrect pin";
            cout<<"\nEnter 4-digit pin: "; cin>>pin;
            if (i==3)
            {
                cout<<"\t\n|| Too many incorrect attempts, card confiscated ||";
                goto end;
            }
        }
        else
        {
            break;
        }
    }

    do
    {
    //Asking for which operation to execute
        cout<<"\n\tWELCOME TO NU BANKING\n\nSelect operation:\n1.Deposit money\n2.Withdraw money\n3.Check balance"<<endl;
        cout<<"\noperation: ";
        cin>>operation;
    
    //Operations execution
        switch (operation)
        {
            case 1:
            {
                cout<<"\n\nEnter amount for deposit: ";
                cin>>deposit;
                cout<<"\n$"<<deposit<<" depositted";
                cout<<"\nDo you want to perform another action? (Y/N): ";
                cin>>rerun;
                break;
            }
            case 2:
            {
                cout<<"\n\nEnter amount for withdrawl: ";
                cin>>withdraw;
                if (withdraw<=6500)
                {
                    cout<<"\n$"<<withdraw<<" withdrawn";
                    cout<<"\nDo you want to perform another action? (Y/N): ";
                    cin>>rerun;
                    break;
                }
                else
                {
                    cout<<"Entered amount exceeds current balance";
                    cout<<"\nDo you want to perform another action? (Y/N): ";
                    cin>>rerun;
                    break;
                }
            }
            case 3: 
            {
                cout<<"\n\nBalance: $6500";
                cout<<"\nDo you want to perform another action? (Y/N): ";
                cin>>rerun;
                break;
            }
            default:
            {
                cout<<"\n\ninvalid input";
                cout<<"\nDo you want to perform another action? (Y/N): ";
                cin>>rerun;
            }
        }
    } while (rerun == 'Y' || rerun == 'y');
    
    end:

    return 0;

}