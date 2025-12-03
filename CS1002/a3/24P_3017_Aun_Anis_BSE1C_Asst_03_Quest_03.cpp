#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of variable storing letter
    char letter;

    //Asking for letter from user
    cout<<"Enter a letter: ";
    cin>>letter;

    //Checking if entered letter is a vowel or not
    switch (letter)
    {
        case ('a'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('A'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('e'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('E'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('i'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('I'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('o'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('O'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('u'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        case ('U'):
            cout<<"\n"<<letter<<" is a vowel.";
            break;
        default:
            cout<<"\n"<<letter<<" is a consonant.";
    }

}