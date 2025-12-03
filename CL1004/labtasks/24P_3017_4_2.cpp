#include <iostream>
using namespace std;
int total_characters(char**);

int main(){
    char **string=new char*[5];
    for(int i=0;i<5;i++){
        string[i]=new char[5];
    }
    
    char hardcode[5][5]={
        {"Read"},
        {"Bear"},
        {"Hat"},
        {"Beat"},
        {" "}
    };

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string[i][j]=hardcode[i][j];
        }
    }

    int temp;
    temp=string[0][0];
    string[0][0]=string[1][0];
    string[1][0]=temp;

    temp=string[2][0];
    string[2][0]=string[3][0];
    string[3][0]=temp;

    cout<<"Total number of characters: "<<total_characters(string);

    for(int i=0;i<5;i++){
        delete[] string[i];
    }
    delete[] string;
    string=NULL;
}

int total_characters(char **string){
    int total=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(string[i][j]=='\0'){
                break;
            }
            else{
                total++;
            }
        }
    }
    
    return total;
}