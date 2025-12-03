#include<iostream>
using namespace std;

struct Book{
    string title;
    string author;
    string ISBN;
    int pages;
    double price;
    bool isAvailable;
};

int main(){
    Book b[3];

    int count=1;
    for(int i=0;i<3;i++){
        cout<<"\nBook #"<<count;
        cout<<"\nEnter book title: "; cin>>b[i].title;
        cout<<"Enter book author: ";cin>>b[i].author;
        cout<<"Enter book ISBN: "; cin>>b[i].ISBN;
        cout<<"Enter the number of pages: "; cin>>b[i].pages;
        cout<<"Enter price: $"; cin>>b[i].price;
        
        string avl;
        do{
          cout<<"Is the book available? (Y/N): "; cin>>avl;
          
          if(avl=="Y" || avl=="y") b[i].isAvailable=true;
          else if(avl=="N" || avl=="n") b[i].isAvailable=false;
          else cout<<"\nInvalid input."<<endl;
        }while((avl!="Y" && avl!="y") && (avl!="N" && avl!="n"));

        count++;
        cout<<endl;
    }

    count=1;
    cout<<"\nLibrary Management System\n";
    for(int i=0;i<3;i++){
        cout<<"Book "<<count<<":";
        cout<<" \""<<b[i].title<<"\" ";
        cout<<"by "<<b[i].author<<endl;
        cout<<"ISBN: "<<b[i].ISBN<<", Pages: "<<b[i].pages<<", Price: $"<<b[i].price<<endl;
        cout<<"Status: ";
        if(b[i].isAvailable==true) cout<<"In stock";
        else cout<<"Out of stock";
        count++;
        cout<<endl<<endl;
    }

    double mostExp=b[0].price;
    int Index=0;
    for(int i=0;i<3;i++){
        if(b[i].price>Index){
            mostExp=b[i].price;
            Index=i;
        }
    }
    cout<<"Most Expensive Book: \""<<b[Index].title<<"\" -  $"<<mostExp;
}