#include <iostream>
using namespace std;
struct book;
void get_books(book*, int);
void display_books(book*, int);
void most_expensive(book*, int);

struct book{
    string title;
    string author;
    float price;
};

int main(){
    int n;
    cout<<"Enter the number of books: ";
    cin>>n;

    book *b=new book[n];
    
    get_books(b, n);
    cout<<endl;
    display_books(b, n);
    cout<<endl;
    most_expensive(b, n);
    
    delete[] b;
    b=NULL;
}

void get_books(book *b, int n){
    int counter=1;
    cout<<"\nEnter book details:";
    for(int i=0;i<n;i++){
        cout<<"\n\nBook #"<<counter<<":";
        cout<<"\nEnter book title: ";
        cin>>b[i].title;
        cout<<"Enter author's name: ";
        cin>>b[i].author;
        cout<<"Enter price: ";
        cin>>b[i].price;
        counter++;
    }
}

void display_books(book *b, int n){
    cout<<"\n\nBook details:";
    for(int i=0;i<n;i++){
            cout<<"\n"<<b[i].title<<endl;
            cout<<"by "<<b[i].author;
            cout<<"\nPrice: $"<<b[i].price;
            cout<<endl;
    }
}

void most_expensive(book *b, int n){
    int m_exp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i].price>b[j].price){
                m_exp=i;
            }
            else{
                m_exp=j;
            }
        }
    }   //end of nested loop
    
    cout<<"\n\nMost expensive book details: ";
    cout<<"\n"<<b[m_exp].title<<endl;
    cout<<"by "<<b[m_exp].author;
    cout<<"\nPrice: $"<<b[m_exp].price;
    cout<<endl;
}