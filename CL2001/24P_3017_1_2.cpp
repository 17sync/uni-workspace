#include<iostream>
using namespace std;
void reverseSentence(char*, int);
void reverseWord(char*, int);
void convertCase(char*, int);
void removeSpaces(char*, int);
void printArray(char*, int);

int main(){
    cout<<"24P-3017"<<endl;

    char string[]={'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    int length=sizeof(string)/sizeof(string[0]);
    
    reverseSentence(string, length);
    removeSpaces(string, length);
    convertCase(string, length);
    printArray(string, length);
}

void reverseSentence(char *string, int length){
    for(int i=0;i<length/2;i++){
        swap(string[i], string[length-2-i]);
    }
}

void reverseWord(char *string, int length){
    int firstLetter=0;
    int lastLetter;

    for(int i=0;i<length;i++){
        int n=0;
        if((string[i]==' ') || (string[i+1]=='\0')){
            lastLetter=i-1;
            for(int j=firstLetter;j<lastLetter/2;j++){
                swap(string[firstLetter+n], string[lastLetter-n]);
                n++;
            }
            firstLetter=i+1;
        }
    }
    
}

void convertCase(char *string, int length){
    for(int i=0;i<length;i++){
        if(string[i]==' ' || string[i]=='\0') continue;
        if(string[i]<96) string[i]+=32;
    }

    for(int i=0;i<length;i++){
        if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u' ) string[i]-=32;
    }
}

void removeSpaces(char *string, int length){
    bool space=true;
    
    do{
        for(int i=0;i<length;i++){
            if(string[i]==' '){
                while(i<length){
                    string[i]=string[i+1];
                    i++;
                }
                space=false;
            }
            else continue;
        }

        for(int i=0;i<length;i++){
            if(string[i]==' '){
                if((string[i+1]=='\0') || (string[i+1]==' ')) break;
                else space=true;
            }
            else continue;
        }
    }while(space==true);
}

void printArray(char *string, int length){
    for(int i=0;i<length;i++){
        if(string[i]=='\0') break;
        else cout<<string[i];
    }
}
