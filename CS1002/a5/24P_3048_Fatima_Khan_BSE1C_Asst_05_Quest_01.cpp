#include <iostream>
#include <string>
using namespace std;
void mainmenu();
void registration();
void schedule();
void seatb();
void tickets();

string guests[50];      // global declaration for max size of guest array
int num_guests = 0;           // global declaration for number of guests          // commonly used values for most functions
int seats[5][5] = {0};  // global declaration for seats initialized to 0

int main() 
{

    cout<<"||  Event Managing System ||"<<endl;
    mainmenu(); // calling main menu function to main
    
}

void registration() 
{

    // printing welcome message and asking for number of guests
    cout<<"|| Guest Registration ||"<<endl;
    int num;
    cout<<"How many guests would you like to register: ";
    cin>>num;

    // safety for exceeding max guests
    if (num_guests + num > 50) {
        cout << "Sorry we can only register up to 50 guests. Please try again with fewer guests" << endl;
        return;
    }

   // loop for registration of guests
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

    // printing schedule
    cout<<"\n\t=== Schedule ===\n";
    cout<<"2:00 PM -- Welcoming Ceremony\n";
    cout<<"3:30 PM -- Main Convocation Event\n";
    cout<<"5:30 PM -- Dinner\n";
    cout<<"8:30 PM -- Closing Ceremony\n";

}


void tickets() 
{
    
    // scanning for number of tickets
    int t;
    const int tcost = 50;
    cout<<"How many tickets would you like to book? ";
    cin>>t;

    // defining and printing total cost of tickets
    int total_cost = t*tcost;
    cout<<"Your total bill is $"<<total_cost<<".";
}


void seatb() 
{

    int choice;

    // loop to trigger going back to main menu if requested
    do {
    // printing seat managment menu
        cout << "\nSeat Management:\n";
        cout << "1. View Seating Arrangement\n";
        cout << "2. Book a Seat\n";
        cout << "3. Go Back to Main Menu\n";
        cout << "Select option: ";
        cin >> choice;

    // switch case for performing function according to choice
        switch (choice) {
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
                    int row_choice, column_choice;
                    cout<<"Enter row number (0-4): ";
                    cin>>row_choice;
                    cout<<"Enter column number (0-4): ";
                    cin>>column_choice;

                    
                    if (row_choice<0 || row_choice>4 || column_choice<0 || column_choice>4) {
                        cout<<"ERROR----> Invalid choice\n";
                    } else if (seats[row_choice][column_choice] == 1) {
                        cout<<"Seat already booked.\n";
                    } else {
                        seats[row_choice][column_choice] = 1;
                        cout<<"Seat booked!\n";
                    }
                }
                break;

            case 3:
                cout<<"Returning to the main menu...\n";
                break;

            default:
                cout<<"INVALID CHOICE.\n";
        }
    } while (choice != 3);

}


void mainmenu() 
{

    int option;

    // loop to avoid wrong option selection
    do {
        cout<<"\n\t|| Event Managment System ||\n";
        cout<<"1. Register Guests\n";
        cout<<"2. Show Event Schedule\n";
        cout<<"3. Book Tickets\n";
        cout<<"4. Manage Seats\n";
        cout<<"5. Exit\n\n";
        cout<<"Select Option: ";
        cin>>option;

    // switch case to call relevant function
        switch (option) {
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
                cout<<"Closing..."<<endl;
                break;

            default:
                cout << "INVALID CHOICE." << endl;
        }

    } while (option != 5);

}
