#include<iostream>
using namespace std;

struct Book{
    string title;
    string author;
    string ISBN;
    int pages;
    double price;
    bool isAvailable;
}b[3];

int main(){
    int counter=1;
    for(int i=0;i<3;i++){
        cout<<"\nBook #"<<counter;
        cout<<"\nEnter book title: "; cin>>b[i].title;
        cout<<"Enter book author: ";cin>>b[i].author;
        cout<<"Enter book ISBN: "; cin>>b[i].ISBN;
        cout<<"Enter the number of pages: "; cin>>b[i].pages;
        cout<<"Enter price: $"; cin>>b[i].price;
        
        string available;
        do{
          cout<<"Set Availability (Y/N): "; cin>>available;
          
          if(available=="Y" || available=="y") b[i].isAvailable=true;
          else if(available=="N" || available=="n") b[i].isAvailable=false;
          else cout<<"\nInvalid input, try again."<<endl;
        }while((available!="Y" && available!="y") && (available!="N" && available!="n"));

        counter++;
        cout<<endl;
    }

    counter=1;
    cout<<"\nLibrary Management System\n";
    cout<<"=========================\n";
    for(int i=0;i<3;i++){
        cout<<"Book "<<counter<<":";
        cout<<" \""<<b[i].title<<"\" ";
        cout<<"by "<<b[i].author<<endl;
        cout<<"ISBN: "<<b[i].ISBN<<", Pages: "<<b[i].pages<<", Price: $"<<b[i].price<<endl;
        cout<<"Status: ";
        if(b[i].isAvailable==true) cout<<"Available";
        else cout<<"Not Available";
        counter++;
        cout<<endl<<endl;
    }

    double mostExpensivePrice=b[0].price;
    int mostExpensiveBook=0;
    for(int i=0;i<3;i++){
        if(b[i].price>mostExpensiveBook){
            mostExpensivePrice=b[i].price;
            mostExpensiveBook=i;
        }
    }
    cout<<"Most Expensive Book: \""<<b[mostExpensiveBook].title<<"\" -  $"<<mostExpensivePrice;
}