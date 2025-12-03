#include<iostream>
using namespace std;
void rowSum(int **, int, int);
void colSum(int **, int, int);

int main(){
    cout<<"24P-3017"<<endl;

    int r, c;
    cout<<"\nEnter the number of rows: "; cin>>r;
    cout<<"Enter the number of columns: "; cin>>c; cout<<endl;

    int **array=new int*[r];
    for(int i=0;i<r;i++){
        *(array+i)=new int[c];
    }

    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            *(*(array+i)+j)=rand()%100;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<*(*(array+i)+j)<<" ";
        }
        cout<<endl;
    }

    cout<<"\nRow Sum:\n"; rowSum(array, r, c);
    cout<<"\nColumn Sum:\n"; colSum(array, r, c);

    for(int i=0;i<r;i++){
        delete[] *(array+i);
    }
    delete[] array;
}

void rowSum(int **array, int rowSize, int columnSize){
    int rowSum=0;
    for(int i=0;i<rowSize;i++){
        cout<<"row #"<<i+1<<": ";
        for(int j=0;j<columnSize;j++){
            rowSum+=*(*(array+i)+j);
        }
        cout<<rowSum<<endl;
        rowSum=0;
    }
}

void colSum(int **array, int rowSize, int columnSize){
    int colSum=0;
    for(int i=0;i<rowSize;i++){
        cout<<"column #"<<i+1<<": ";
        for(int j=0;j<columnSize;j++){
            colSum+=*(*(array+j)+i);
        }
        cout<<colSum<<endl;
        colSum=0;
    }
}

