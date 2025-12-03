#include <iostream>
using namespace std;


int main(){
    cout<<"24P-3017"<<endl;

    int r, c;
    cout<<"\nEnter number of rows: "; cin>>r;
    cout<<"Enter number of columns: "; cin>>c;
    cout<<endl;
    
    int **arr=new int*[r];
    for(int i=0;i<r;i++){
        *(arr+i)=new int[c];
    }

    int *row=new int(0);
    int *col=new int(0);
    int counter=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter Entry #"<<counter<<": "; counter++;
            cin>>*(*(arr+i)+j);
            if(i==j==0 || i==r-1 && j==0){
                *row+=*(*(arr+i)+j);
            }
            if(i==0 && j==c-1){
                *col+=*(*(arr+i)+j);
            }
    }
    }
    *row+=r;
    *col+=c;

    int **resultArray = new int*[*row];
    for(int i=0;i<*row;i++){
        *(resultArray+i) = new int[*col]{0};
    }

    int index=0;
    for(int i=*(*(arr+0)+0);i<r+*(*(arr+0)+0);i++){
        for(int j=0;j<c;j++){
                *(*(resultArray+i)+j) = *(*(arr+index)+j);
        }
        index++;
    }
    
    cout<<"\nNew Array:\n";
    for(int i=0;i<*row;i++){
    cout<<"\t";
       for(int j=0;j<*col;j++){
              cout<<" "<<*(*(resultArray+i)+j);
        }
        cout<<endl;
    }

    delete row;
    delete col;
    
    for(int i=0;i<r;i++){
        delete[] *(arr+i);
    }
    delete arr;
    
    for(int i=0;i<*row;i++){
        delete[] (resultArray+i);
    }
    delete resultArray;
}