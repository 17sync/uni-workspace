#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
};

int main() {
    Book* b = new Book;
    b->title = "The Alchemist";
    b->author = "Paulo Coelho";

    cout << "Title: " << b->title << ", Author: " << b->author << endl;

    delete b; // Deallocate memory
    return 0;
}
