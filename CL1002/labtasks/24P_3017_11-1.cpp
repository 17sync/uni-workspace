#include <iostream>
using namespace std;

const int ROWS = 10;
const int SEATS = 10;

int main() 
{
    
    //Declaration of 2d array for seating and variables to store inputs and compute seat reservation count
    int seating[ROWS][SEATS] = {0};
    int reservedCount = 0;
    int row, seat;

    //Asking for seat reservation
    cout <<"Enter row and seat number to reserve (0 0 to stop): ";
    while (cin >> row >> seat) {
        if (row == 0 && seat == 0) {
            break;
        }
        if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
            cout <<"Invalid row or seat number. Please try again.\n";
        } else if (seating[row - 1][seat - 1] == 1) {
            cout <<"Seat already reserved. Please try again.\n";
        } else {
            seating[row - 1][seat - 1] = 1;
            reservedCount++;
            cout <<"Seat reserved successfully.\n";
        }

        cout <<"Enter row and seat number to reserve (0 0 to stop): ";
    }

    //Displaying total reserved seats
    cout <<"\nTotal reserved seats: "<<reservedCount<<endl;

    //Display final seating chart
    cout <<"Final seating chart:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SEATS; j++) {
            cout<<seating[i][j]<<" ";
        }
        cout<<endl;
    }

}

