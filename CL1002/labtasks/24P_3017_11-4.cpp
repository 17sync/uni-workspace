#include <iostream>

using namespace std;

int main() 
{

    //Declaration of array storing string
    char strng[20];

    //Asking for input from the user
    cout << "Enter a character array (max 19 characters): ";
    cin >> strng;

    //Checking if the input is a string or just characters
    bool string = false;
    for (int i = 0; i < 20; i++) {
        if (strng[i] == '\0') { 
            string = true;
            break;
        }
    }

    //Display the result
    if (string) {
        cout <<"The input is a string."<< endl;
    } else {
        cout <<"The input is a character array."<< endl;
    }

    return 0;
    
}
