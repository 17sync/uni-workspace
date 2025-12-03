#include<iostream>
#include<climits>
using namespace std;
int avgStock(int *, int);
int critProducts(int *, int, int);
void topSelling(int *, int);
int findSecondBestSeller(int*, int);
void sortByPopularity(int *, int);

int main(){
    cout<<"24P-3017"<<endl;

    int invenSize;
    cout<<"\nEnter inventory size: "; cin>>invenSize;

    int *inventory=new int[invenSize];
    for(int i=0;i<invenSize;i++){
        *(inventory+i)=rand()%100;
    }

    cout<<"\nInventory: ";
    for(int i=0;i<invenSize;i++){
        cout<<*(inventory+i)<<" ";
    }

    int avgQuantity=avgStock(inventory, invenSize);
    cout<<"\nAverage Stock: "<<avgQuantity<<endl;
    cout<<"Number of Critical Products: "<<critProducts(inventory, invenSize, avgQuantity)<<endl;
    topSelling(inventory, invenSize);
    cout<<"Product #"<<findSecondBestSeller(inventory, invenSize)<<" is the second best selling product."<<endl;
    cout<<"\nInventory sorted by popularity: "; sortByPopularity(inventory, invenSize);

    for(int i=0;i<invenSize;i++){
        cout<<*(inventory+i)<<" ";
    }
    cout<<endl;

    delete[] inventory;
}

int avgStock(int *array, int size){
    int totalQuantity=0;
    int items=0;

    for(int i=0;i<size;i++){
        totalQuantity+=*(array+i);
        items++;
    }
    int avgQuantity=totalQuantity/items;

    return avgQuantity;
}

int critProducts(int *array, int size, int avgQuantity){
    int critProducts=0;
    
    for(int i=0;i<size;i++){
        if(*(array+i)<avgQuantity) critProducts++;
        else continue;
    }

    return critProducts;
}

void topSelling(int *array, int size){
    int topSellingIndex=0;
    int topSellingQuantity=INT_MAX;

    for(int i=0;i<size;i++){
        if(*(array+i)==0){
            topSellingIndex=i;
            break;
        }
        else if(*(array+i)<topSellingQuantity){
            topSellingQuantity=*(array+i);
            topSellingIndex=i;
        }
        else continue;
    }

    cout<<"Product #"<<topSellingIndex+1<<" is the top selling product."<<endl;
}

int findSecondBestSeller(int *array, int size){
    int best=INT_MAX;
    int secBest=INT_MAX;
    int bestIndex=0; 
    int secBestIndex=0;

    for (int i=0;i<size;i++){
        if(*(array+i)<best){
            secBest=best;
            secBestIndex=bestIndex;

            best=*(array+i);
            bestIndex=i;
        }
        else if(*(array+i)>best && *(array+i)<secBest){
            secBest=*(array+i);
            secBestIndex=i;
        }
    }

    return secBestIndex+1;
}

void sortByPopularity(int *array, int size){
    for(int i=0;i<size-1;i++){
        int *maxEl=(array + i);
        for(int j=i+1;j<size;j++){
            if (*(array+j)>*maxEl){
                maxEl=(array+j);  
            }
        }
        if(maxEl!=(array+i)) {
            int temp=*(array+i);
            *(array+i)=*maxEl;
            *maxEl=temp;
        }
    }
}