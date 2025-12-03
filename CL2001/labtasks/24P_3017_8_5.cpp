#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim){
    int sum=0;

    if(dim==1){
        for(int i=0;i<sizes[0];i++) sum+=arr[i][0]; 
        return sum;
    }

    for(int i=0;i<sizes[0];i++) sum+=recursiveArraySum((int**)arr[i], sizes + 1, dim - 1); 
    return sum;
}

int main(){
    cout<<"24P-3017\n"<<endl;
    
    int a1[]={1, 2, 3};
    int a2[]={4, 5};
    int a3[]={6, 7, 8, 9};
    int *arr2D[]={a1, a2, a3};
    int sizes[]={3, 4};

    int total=0;
    for(int i=0;i<3; i++){
        int len=(i==0?3:(i==1?2:4)); 
        for(int j=0;j<len;j++)
            total+=arr2D[i][j];
    }

    cout<<"Sum of all elements: "<<total<<endl;
}
