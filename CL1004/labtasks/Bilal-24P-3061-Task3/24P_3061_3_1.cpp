#include<iostream>
using namespace std;

class Book{
    string title;
    string author;
    string ISBN;
    float price;

    public:
    Book(string t, string a, string i, float p){
        title=t;
        author=a;
        ISBN=i;
        price=p;
    }

    void displayInfo();
    void applyDiscount(float);
    string getTitle();
    string getAuthor();
    string getISBN();
    float getPrice();
};

int main(){
    Book b1("Diary of a Wimpy Kid", "Jeff Kinney", "1245-9087-7654", 10.25);
    Book b2("Tale of two Cities", "Charles Dickens", "3452-1432-8765", 12.5);

    b1.displayInfo();
    b2.displayInfo();
    
    b1.applyDiscount(25);
    b2.applyDiscount(30);

    b1.displayInfo();
    b2.displayInfo();
}

void Book::displayInfo(){
    cout<<"\n"<<title<<"\nby: "<<author<<endl;
    cout<<"ISBN: "<<ISBN<<endl;
    cout<<"Price: "<<price<<endl;
}

void Book::applyDiscount(float percentage){
    if(percentage>100 || percentage<=0){
        cout<<"\nInvalid discount"<<endl;
        return;
    }
    
    price=price*((100-percentage)/100);
}

string Book::getTitle(){
    return title;
}

string Book::getAuthor(){
    return author;
}

string Book::getISBN(){
    return ISBN;
}

float Book::getPrice(){
    return price;
}