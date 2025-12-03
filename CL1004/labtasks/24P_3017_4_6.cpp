#include <iostream>
using namespace std;
void seating_arrangement(int**);

int main(){
    int row, sn;

    int **seat=new int*[10];
    for(int i=0;i<10;i++){
        seat[i]=new int[10];
    }

    int seating[10][10]={
        {0, 0, 0, 0 ,0, 0, 0, 0, 0 ,0},
        {0, 1, 0, 0 ,0, 0, 0, 0, 0 ,0},
        {0, 0, 0, 1 ,1, 0, 0, 0, 0 ,0},
        {0, 0, 1, 0 ,0, 1, 0, 0, 1 ,0},
        {0, 0, 0, 0 ,0, 1, 0, 0, 0 ,0},
        {0, 0, 0, 0 ,0, 0, 1, 1, 1 ,0},
        {0, 0, 0, 0 ,0, 0, 0, 0, 1 ,0},
        {0, 0, 0, 0 ,0, 0, 0, 1, 1 ,0},
        {0, 0, 0, 0 ,0, 0, 0, 1, 0 ,0},
        {0, 0, 0, 0 ,0, 1, 1, 1, 0 ,0}
    };

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            seat[i][j]=seating[i][j];
        }
    }

    cout<<"(Enter 0 0 to exit the program)\n";

    do{
        cout<<"\nEnter row and seat number to reserve: ";
        cin>>row>>sn;

        if(row>10 || sn>10){
            cout<<"Invalid row or seat number, please try again.";
            continue;
        }
        else if(seat[row][sn]==0){
            cout<<"Seat reserved successfully.";
            seat[row][sn]=1;
        }
        else if(seat[row][sn]==1){
            cout<<"Sorry, seat already reserved.";
        }
    }while(row!=0 || sn!=0);

    seating_arrangement(seat);

    for(int i=0;i<10;i++){
        delete[] seat[i];
    }
    delete[] seat;
    seat=NULL;
}

void seating_arrangement(int **seat){
    cout<<"\nSeating arrangement:\n";
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<seat[i][j]<<"\t";
        }
        cout<<endl;
    }
}