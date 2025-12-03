#include <iostream>
using namespace std;

int main ()
{
    //Declaration of currencies
    float dollar, pound, franc, deutsch, yen;

    //Displaying subject of the program
    cout<<"\tCurrency Converter\n\t------------------";

    //Asking for value in dollars from user
    cout<<"\nEnter amount in dollars: $"; cin>>dollar;

    //Defining other currencies in regard to dollar
    pound = dollar/1.487;
    franc = dollar/0.172;
    deutsch = dollar/0.584;
    yen = dollar/0.00955;

    //Displaying entered value in other currencies
    cout<<"\nEnglish Pound: "<<pound;
    cout<<"\nFrench Franc: "<<franc;
    cout<<"\nGerman Deutschemark: "<<deutsch;
    cout<<"\nJapanese yen: "<<yen;
}