#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main ()
{

    //Declaration of 2 C-style arrays
    char s1[50];
    char s2[50];

    //Asking for 2 strings from user
    cout<<"Enter string #1: "; fgets(s1, sizeof(s1), stdin);
    cout<<"Enter string #2: "; fgets(s2, sizeof(s2), stdin);

    //Checking if the 2 strings are reverse of each other
    bool reverse = true;
    int sl1 = strlen(s1);
    int sl2 = strlen(s2);
    if (sl1!=sl2){
        cout<<"\nThe strings are not reverses of each other.";
    }
    else{
        for (int i=0; i<sl1; i++){
            if (s1[i]!=s2[sl1-i-1]){
                reverse = false;
            }
        }
        if (reverse = true){
            cout<<"\nThe strings are reverses of each other.";
        }
        else if (reverse = false){
            cout<<"\nThe strings are not reverses of each other";
        }
    }
    
}