#include<iostream>
using namespace std;
int *findIntersection(int *, int *, int, int, int*);

int main(){
    cout<<"24P-3017"<<endl;

    int size1=5;
    int size2=7;
    int array1[size1]={1, 3, 6, 8, 56};
    int array2[size2]={1, 1, 6, 7, 8, 8, 45};

    int resultSize;
    int *resultArray=findIntersection(array1, array2, size1, size2, &resultSize);

    cout<<"\nA = ";
    for(int i=0;i<size1;i++){
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    cout<<"B = ";
    for(int i=0;i<size1;i++){
        cout<<array2[i]<<" ";
    }
    cout<<endl;

    cout<<"\nCommon Unique Elements: ";
    for(int i=0;i<resultSize;i++){
        cout<<resultArray[i]<<" ";
    }

    delete[] resultArray;
    resultArray=NULL;
}

int *findIntersection(int *array1, int *array2, int size1, int size2, int *resultSize){
    int length;
    if(size1>size2) length=size1;
    else length=size2;
    int uCom=0;
    int common[length];

    bool alreadyFound=false;
    int cfilled=0;
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(array1[i]==array2[j]){
                for(int k=0;k<length;k++){
                    if(common[k]==array1[i]){
                        alreadyFound=true;
                        break;
                    }
                    else continue; 
                }

                if(alreadyFound==true){
                    alreadyFound=false;
                    continue;
                }
                else{
                    common[cfilled]=array1[i];
                    cfilled++;
                }
            }
            else continue;
        }
    }

    *resultSize=cfilled;
    int *resultArray=new int[*resultSize];

    for(int i=0;i<*resultSize;i++){
        resultArray[i]=common[i];
    }

    return resultArray;
}