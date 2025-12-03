#include<iostream>
using namespace std;
int findSecondLargest(int*, int);
void countEvenOdd(int*, int, int*, int*);
void rotateArray(int*, int, int);
int sumOfPrimes(int*, int);
void printArray(int*, int);

int main(){
    cout<<"24P-3017\n\n";

    int size;
    cout<<"Enter size: "; cin>>size;
    int array[size];
    cout<<"Enter elements: ";
    
    for(int i=0;i<size;i++){
        cin>>array[i];
    }

    int *evenCount=new int;
    int *oddCount=new int;
    *evenCount=0;
    *oddCount=0;

    printArray(array, size);
    cout<<"Second Largest Element: "<<findSecondLargest(array, size)<<endl;
    countEvenOdd(array, size, evenCount, oddCount);
    cout<<"Even Numbers: "<<*evenCount; cout<<"\nOdd Numbers: "<<*oddCount;
    cout<<"\nSum of Prime Numbers: "<<sumOfPrimes(array, size);
    rotateArray(array, size, 2);
    cout<<"\nArray rotated by 2 positions to the left: ";
    printArray(array, size);

    delete evenCount;
    evenCount=NULL;
    delete oddCount;
    oddCount=NULL;
}

int findSecondLargest(int *array, int n){
    int secondLargest=-1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(*(array+j)>*(array+j+1)) swap(*(array+j), *(array+j+1));
            else continue;
        }
    }

    int largest=array[n-1];
    for(int i=n-2;i>0;i--){
        if(array[i]<largest){
            secondLargest=array[i];
            break;
        }
    }

    return secondLargest;
}

void countEvenOdd(int *array, int n, int *evenCount, int *oddCount){
    for(int i=0;i<n;i++){
        if(*(array+i)%2==0) *evenCount+=1;
        else *oddCount+=1;
    }
}

void rotateArray(int *array, int n, int k){
    int temp[k];

    for(int i=0;i<k;i++){
        *(temp+i)=*(array+i);
    }
    for(int i = 0; i < n - k; i++){
        *(array+i)=*(array+i+k);
    }
    for(int i=0;i<k;i++){
        *(array+n-k+i)=*(temp+i);
    }
}

int sumOfPrimes(int *array, int n){
    int sum=0;

    for(int i=0;i<n;i++){
        if(*(array+i)<=1) continue;

        else if(*(array+i)==2){
            sum+=*(array+i);
            continue;
        }

        else if(*(array+i)%2==0) continue;

        bool isPrime=true;
        for(int j=3;j*j<=*(array+i);j+=2) {
            if (*(array+i)%j==0){
                isPrime=false; 
                break;
            }
        }

        if(isPrime==true) sum+=*(array+i);
    }

    return sum;
}

void printArray(int *array, int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        if(i==n-1) cout<<*(array+i);
        else cout<<*(array+i)<<", ";
    }
    cout<<"]\n\n";
}