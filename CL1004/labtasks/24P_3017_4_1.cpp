#include <iostream>
using namespace std;
bool reverse_check(char*, char*);

int main(){
    char *str1=new char[15];
    char *str2=new char[15];

    cout<<"DISCLAIMER: Keep strings <= 15 characters.\n\n";
    cout<<"Enter string #1: ";
    cin>>str1;
    cout<<"Enter string #2: ";
    cin>>str2;

    if (reverse_check(str1, str2)==true){
        cout<<"\nReverses.";
    }
    else{
        cout<<"\nNot Reverses.";
    }

    delete[] str1;
    str1=NULL;

    delete[] str2;
    str2=NULL;
}

bool reverse_check(char *str1, char *str2){
    int l1=0, l2=0;

    for(int i=0;str1[i]!='\0';i++){
        l1++;
    }
    for(int i=0;str2[i]!='\0';i++){
        l2++;
    }

    if(l1!=l2){
        return false;
    }
    else{
        for(int i=0;i<l1;i++){
            if(str1[i]!=str2[(l1-1)-i]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
}