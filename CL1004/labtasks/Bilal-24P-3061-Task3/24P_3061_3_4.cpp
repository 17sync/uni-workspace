#include<iostream>
using namespace std;

class Book{
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    public:
    Book(string t,string a,string i, bool isA){
        title=t;
        author=a;
        ISBN=i;
        isAvailable=isA;
    }

    void checkOut(){
        if(isAvailable) isAvailable=false;
        else cout<<"Book already checked out"<<endl;
    }

    void checkIn(){
        isAvailable=true;
    }

    void displayInfo(){
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Available: ";
        if(isAvailable==true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    string getTitle(){ 
        return title;
    }

    string getAuthor(){
        return author;
    }

    string getIsbn(){
        return ISBN; 
    }

    bool getIsAvailable(){
        return isAvailable;
    }
};

class Member{
    string name;
    string memberId;
    Book *borrowedBooks[5];

    public:
    Member(string n,string id){
        name=n;
        memberId=id;
        for(int i=0;i<5;i++) borrowedBooks[i]=nullptr;
    }

    void borrowBook(Book book){
        if(book.getIsAvailable()){
            for(int i=0;i<5;i++){
                if(borrowedBooks[i]==nullptr){
                    book.checkOut();
                    borrowedBooks[i]=&book;
                    cout<<"Book borrowed successfully."<<endl;
                    return;
                }
            }
            cout<<"Borrow limit reached"<<endl;
        } else cout<<"Book not available at the moment."<<endl;
    }

    void returnBook(Book book){
        for(int i=0;i<5;i++){
            if(borrowedBooks[i]!=nullptr && borrowedBooks[i]->getIsbn()==book.getIsbn()){
                borrowedBooks[i]=nullptr;
                book.checkIn();
                cout<<"Book returned successfully"<<endl;
                return;
            }
        }
        cout<<"Book not found in borrowed list"<<endl;
    }

    void displayInfo(){
        cout<<"Member Name: "<<name<<endl;
        cout<<"Member ID: "<<memberId<<endl;
        cout<<"Borrowed Books:"<<endl;
        for(int i=0;i<5;i++){
            if(borrowedBooks[i]!=nullptr){
                borrowedBooks[i]->displayInfo();
                cout<<endl;
            }
        }
    }

    string getName(){
        return name;
    }

    string getMemberId(){ 
        return memberId; 
    }
};

class Library{
    string name;
    Book *books[5];
    Member *members[3];

    public:
    Library(string n){
        name=n;
        books[10]={nullptr};
        members[5]={nullptr};
    }

    void addBook(Book book){
        for(int i=0;i<5;i++){
            if(books[i]==nullptr){
                books[i]=&book;
                cout<<"Book successfully added to library."<<endl;
                return;
            }
        }
        cout<<"Library full, cannot add any more books at the moment."<<endl;
    }

    void addMember(Member member){
        for(int i=0;i<3;i++){
            if(members[i]==nullptr){
                members[i]=&member;
                cout<<"Member successfully added to library."<<endl;
                return;
            }
        }
        cout<<"Library full, cannot add any more members at the moments."<<endl;
    }

    void lendBook(string memberId, string isbn){
        for(int i=0;i<3;i++){
            if(members[i]!=nullptr && members[i]->getMemberId()==memberId){
                for(int j=0;j<10;j++){
                    if(books[j]!=nullptr && books[j]->getIsbn()==isbn){
                        members[i]->borrowBook(*books[j]);
                        return;
                    }
                }
            }
        }
        cout<<"Book does not exist."<<endl;
    }

    void returnBook(string memberId, string isbn){
        for(int i=0;i<3;i++){
            if(members[i]!=nullptr && members[i]->getMemberId()==memberId){
                for(int j=0;j<10;j++){
                    if(books[j]!=nullptr && books[j]->getIsbn()==isbn){
                        members[i]->returnBook(*books[j]);
                        return;
                    }
                }
            }
        }
        cout<<"Book does not exist."<<endl;
    }

    void displayAvailableBooks(){
        cout<<"Available Books:"<<endl;
        for(int i=0;i<10;i++){
            if(books[i]!=nullptr && books[i]->getIsAvailable()){
                books[i]->displayInfo();
                cout<<endl;
            }
        }
    }

    void displayMemberInfo(string memberId){
        for(int i=0;i<5;i++){
            if(members[i]!=nullptr && members[i]->getMemberId()==memberId){
                members[i]->displayInfo();
                return;
            }
        }
        cout<<"Member does not exist."<<endl;
    }
};

int main(){
    Library l("Bilal Library");

    Book b1("Diary of a Wimpy Kid: Cabin Fever", "Jeff Kinney", "3411-7654-9088", true);
    Book b2("Diary of a Wimpy Kid: Third Wheel", "Jeff Kinney", "1323-8643-9841", false);
    Book b3("Diary of a Wimpy Kid: The Long Haul", "Jeff Kinney", "9081-6537-1242", true);
    Book b4("Diary of a Wimpy Kid: Old School", "Jeff Kinney", "7643-7653-8906", true);
    Book b5("Diary of a Wimpy Kid: Rodrick Rules", "Jeff Kinney", "8765-9087-6501", true);

    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);
    l.addBook(b4);
    l.addBook(b5);

    Member m1("Abdul Saboor", "3006");
    Member m2("Bilal Malik", "3061");
    Member m3("Ahmad Ali Shah", "3075");

    l.addMember(m1);
    l.addMember(m2);
    l.addMember(m3);

    l.lendBook("3006", b1.getIsbn());
    l.returnBook("3006", b1.getIsbn());

    l.displayAvailableBooks();
    l.displayMemberInfo("3075");
}
