#include<iostream>
using namespace std;
void removeDuplicates(int*, int&);
void countFrequency(int*, int, int[][100]);
void descendingFrequency(int*, int, int[][100]);
void printArray(int*, int, int[][100]);

int main(){
    cout<<"24P-3017"<<endl;

    int array[]={4, 5, 6, 5, 4, 3, 4, 6, 7, 3, 5};
    int size=sizeof(array)/sizeof(array[0]);
    int frequency[2][100]={0};                                               // top row unique elements, bottom row frequency

    countFrequency(array, size, frequency);
    removeDuplicates(array, size);
    descendingFrequency(array, size, frequency);
    cout<<"Rearranged Array: ";
    printArray(array, size, frequency);

}

void removeDuplicates(int *array, int &size){                               // shortens size, need to pass by reference
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(j==i) continue;
            if(array[i]==array[j]){
                while(j<size){
                    array[j]=array[j+1];
                    j++;
                }
                size--;
            }
            else continue;
        }
    }
}

void countFrequency(int *array, int size, int frequency[][100]){
    int n=0;                                                                // iterates 2d array
    
    for(int i=0;i<size;i++){
        bool exists=false;                                                  // flag for if element's frequency has already been counted
        for(int k=0;k<size;k++){
            if(frequency[0][k]==array[i]){
                exists=true; break;
            }
            else continue;
        }
        if(exists==true) continue;

        frequency[0][n]=array[i];
            
        int counter=0;
        for(int j=0;j<size;j++){
            if(array[j]==array[i]) counter++;
            else continue;
        }
        frequency[1][n]=counter;
        n++;
    }
}

void descendingFrequency(int *array, int size, int frequency[][100]){
    for(int i=0;i<size;i++){
        if(frequency[0][i]==0 && frequency[1][i]==0) break;
        for(int j=i+1;j<size;j++){
            if(frequency[1][j]>frequency[1][i]){
                swap(frequency[0][j], frequency[0][i]);
                swap(frequency[1][j], frequency[1][i]);
            }
            else if(frequency[1][j]==frequency[1][i]){
                if(frequency[0][j]<frequency[0][i]) swap(frequency[0][j], frequency[0][i]);
                else continue;
            }
        }
    }

    for(int i=0;i<size;i++){
        if(frequency[0][i]==0 && frequency[1][i]==0) break;
        array[i]=frequency[0][i];
    }
}

void printArray(int *array, int size, int frequency[][100]){
    cout<<"[";
    for(int i=0;i<size;i++){
        if(i==size-1) cout<<array[i];
        else cout<<array[i]<<", ";
    }
    cout<<"]\n\n";

    cout<<"Frequencies:\n\n";
    for(int i=0;i<size;i++){
        if(frequency[0][i]==0 && frequency[1][i]==0) break;
        cout<<frequency[0][i]<<" -> "<<frequency[1][i]<<endl;
    }
}