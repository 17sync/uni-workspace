#include <iostream>
#include <string>
using namespace std;
void mainmenu();
void registration();
void schedule();
void seatb();
void tickets();

//Global declarations of significant variables used in every function
string guests[50];
int num_guests = 0;
int seats[5][5] = {0};  

int main() 
{   

    //Displaying welcome message and calling menu function to main
    cout<<"Welcome to FAST-NUCES Event Organiser!"<<endl;
    mainmenu();
    
}

void registration() 
{

    //Displaying welcome message and asking for number of guests
    cout<<"Welcome to Guest Registration!"<<endl;
    int num;
    cout<<"How many guests would you like to register? ";
    cin>>num;

    //Registration system
    if (num_guests + num > 50) {
        cout << "Sorry we can only register up to 50 guests. Please try again with fewer guests" << endl;
        return;
    }

   
    for (int i = 0; i < num; ++i) {
        string name;
        cout << "Please enter the name of guest " << num_guests + 1 << ": ";
        cin >> name;  
        guests[num_guests] = name;
        num_guests++;
    }
    cout << "Guests have been registered!" << endl;

}


void schedule() 
{

    //Displaying schedule
    cout<<"\n\t|| Schedule ||\n";
    cout<<"4:00 PM - Welcome Ceremony\n";
    cout<<"5:30 PM - Brunch\n";
    cout<<"7:30 PM - Concert\n";
    cout<<"11:30 PM - Closing Ceremony\n";

}


void tickets() 
{
    
    //Asking for number of tickets from user
    int tcount;
    const int price = 50;
    cout<<"How many tickets would you like to book? ";
    cin>>tcount;

    //Displaying total cost of tickets
    int totalCost = tcount*price;
    cout<<"Your total is $"<<totalCost<<".";
}


void seatb() 
{

    //Declaration of variable storing user defined option number
    int option;

    //Displaying seat managment menu
    do {
        cout << "\nSeat Management:" << endl;
        cout << "1. View Seating Arrangement" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Go Back to Main Menu" << endl;
        cout << "Choose an action: ";
        cin >> option;

    //Seat management system
        switch (option) {
            case 1:
                cout << "\nCurrent Seating Arrangement (0 = Available, 1 = Booked):" << endl;
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        cout << seats[i][j] << " ";
                    }
                    cout<<endl;
                }
                break;

            case 2:
                {
                    int r, c;
                    cout<<"Enter row number (0-4): ";
                    cin>>r;
                    cout<<"Enter column number (0-4): ";
                    cin>>c;

                    
                    if (r<0 || r>4 || c<0 || c>4) {
                        cout<<"ERROR----> Invalid choice\n";
                    } else if (seats[r][c] == 1) {
                        cout<<"Seat already booked.\n";
                    } else {
                        seats[r][c] = 1;
                        cout<<"Seat booked!\n";
                    }
                }
                break;

            case 3:
                cout<<"Returning to the main menu...\n";
                break;

            default:
                cout<<"ERROR----> Invalid choice\n";
        }
    } while (option != 3);

}


void mainmenu() 
{

    //Declaration of variable storing user defined operation number
    int operation;

    //Displaying menu and calling relevant function
    do {
        cout<<"\n\t|| FAST-NUCES Event Organiser ||\n";
        cout<<"1. Register Guests\n";
        cout<<"2. Show Event Schedule\n";
        cout<<"3. Book Tickets\n";
        cout<<"4. Manage Seats\n";
        cout<<"5. Exit\n\n";
        cout<<"Select Operation: ";
        cin>>operation;

        switch (operation) {
            case 1:
                registration();
                break;

            case 2:
                schedule();
                break;

            case 3:
                tickets();
                break;

            case 4:
                seatb();
                break;

            case 5:
                cout << "Thank you for choosing FAST-NUCES Even Organiser!" << endl;
                break;

            default:
                cout << "ERROR----> Invalid option" << endl;
        }

    } while (operation != 5);

}
