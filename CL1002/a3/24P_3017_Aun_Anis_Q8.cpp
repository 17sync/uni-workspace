#include <iostream>
using namespace std;
bool compare(const char* str1, const char* str2);
bool check(char ssid_storage[][50], char passwords[][50], int count, const char* ssid, const char* password);

int main() 
{

    //Declaration of constant for maximum entries
    const int max= 10;
    
    //Declaration of array for SSID and passwords
    char ssids[max][50];
    char passwords[max][50];
    
    //Variable counting number of stored passwords
    int stored=0;

    //Main Menu
    int choice;
    do {
        cout<<"1. Add SSID and Password\n";
        cout<<"2. Check SSID and Password\n";
        cout<<"3. Exit\n";
        cout<<"Select Operation: ";
        cin>>choice;

        if (choice==1){
            char ssid[50], password[50];
            cout<<"Enter SSID (No spaces): ";
            cin>>ssid;
            cout<<"Enter Password (No spaces): ";
            cin>>password;

            if (stored<max){
                int i=0;
                while (ssid[i]!='\0'){
                    ssids[stored][i]=ssid[i];
                    ++i;
                }
                ssids[stored][i]='\0';

                i=0;
                while (password[i]!='\0'){
                    passwords[stored][i]=password[i];
                    ++i;
                }
                passwords[stored][i]='\0';
                stored++;
                cout<<"SSID and Password added.\n";
            } 
            else{
                cout << "ERROR---> Maximum number of entries reached.\n";
            }
        } 
        else if (choice==2){
            char ssid[50], password[50];
            cout << "Enter SSID: ";
            cin>>ssid;
            cout << "Enter Password: ";
            cin>>password;

            if (check(ssids, passwords, stored, ssid, password)) {
                cout << "SSID and Password match found.\n";
            } else {
                cout << "No matching SSID and Password found.\n";
            }
        } else if (choice == 3) {
            cout << "Exiting the program. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;
    }while (choice!=3);

}

bool compare(const char* str1, const char* str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        ++i;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

bool check(char ssid_storage[][50], char passwords[][50], int count, const char* ssid, const char* password) 
{
    for (int i = 0; i < count; ++i) {
        if (compare(ssid_storage[i], ssid) && compare(passwords[i], password)) {
            return true;
        }
    }
    return false;
}

