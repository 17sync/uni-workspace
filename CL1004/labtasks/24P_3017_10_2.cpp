#include<iostream>
using namespace std;

class book{
    string name;
    public:
    book(string n): name(n){}
    void display_name(){
        cout<<name<<endl;
    }
};

class library{
    book b1, b2, b3;
    public:
    library(): b1("Hamlet"), b2("Harry Potter"), b3("Diary of a Wimpy Kid"){}
    void display_books(){
        cout<<"Books in Library:\n";
        b1.display_name();
        b2.display_name();
        b3.display_name();
    }
}l;

int main(){
    l.display_books();
}