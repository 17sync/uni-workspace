#include <iostream>
using namespace std;
struct book;
void display_books(book *b);

struct book{
    string title;
    string author;
    int price;
}b[5];

int main(){
    //hardcoded indexes
    b[0]={"Diary of a Wimpy Kid", "Jeff Kinney", 501};
    b[1]={"A Tale of Two Cities", "Charles Dickens", 650};
    b[2]={"Harry Potter", "JK Rowling", 750};
    b[3]={"Hamlet", "William Shakespeare", 800};
    b[4]={"James and The Giant Peach", "Roald Dahl", 20};

    display_books(b);       //displays books with price higher than $500
}

void display_books(book *b){
    cout<<"Books >$500:\n";

    for(int i=0;i<5;i++){
        if(b[i].price>500){
            cout<<"\n"<<b[i].title<<endl;
            cout<<"by "<<b[i].author;
            cout<<"\nPrice: $"<<b[i].price;
            cout<<endl;
        }
        else{
            continue;
        }
    }
}