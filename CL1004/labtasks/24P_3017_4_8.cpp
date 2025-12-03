#include <iostream>
using namespace std;

struct Book{
    string title;
    string author;
    int pages;
    float price;
}b;

int main(){
    cout<<"Enter the title of the book: ";
    getline(cin, b.title);
    cout<<"Enter the name of the author: ";
    getline(cin, b.author);
    cout<<"Enter the number of pages: ";
    cin>>b.pages;
    cout<<"Enter the price of the book: ";
    cin>>b.price;

    cout<<"\n"<<b.title;
    cout<<"\nby "<<b.author;
    cout<<"\nNumber of pages: "<<b.pages;
    cout<<"\nPrice: Rs "<<b.price;
}   