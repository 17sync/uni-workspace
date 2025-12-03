#include <iostream>
using namespace std;
bool reverse_checker(char* str1, char* str2);

int main() 
{

    char str1 [50];
    char str2 [50];

    cout<<"Enter string #1: ";
    cin>>str1;
    cout<<"Enter string #2: ";
    cin>>str2;

    if (reverse_checker(str1, str2)){
        cout<<"Reverses."<<endl;
    } 
    else{
        cout<<"Not reverses."<<endl;
    }

}

bool reverse_checker(char* str1, char* str2) 
{

    int len1=0;
    int len2=0;
    
    while (str1[len1]!='\0'){
        len1++;    
    } 
    
    while (str2[len2]!='\0'){
        len2++;
    } 

    if (len1!=len2){
        return false;
    }

    for (int i=0; i<len1; i++){
        if (str1[i]!=str2[len1-1-i]){
            return false;
        }
    }

    return true;
    
}
