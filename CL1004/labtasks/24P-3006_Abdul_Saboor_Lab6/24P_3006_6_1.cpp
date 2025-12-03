#include <iostream>
using namespace std;

class Book {
    string title, author, ISBN;
    bool available;
    static int totalBooks, availableBooks, borrowedBooks;
public:
    Book(string t, string a, string i, bool avail = true) : title(t), author(a), ISBN(i), available(avail) {
        totalBooks++;
        if (available) availableBooks++;
    }
    void borrowBook() {
        if (available) {
            available = false;
            availableBooks--;
            borrowedBooks++;
        }
    }
    void returnBook() {
        if (!available) {
            available = true;
            borrowedBooks--;
            availableBooks++;
        }
    }
    void displayBookInfo() {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN
             << ", Available: " << (available ? "Yes" : "No") << endl;
    }
    static void displayLibraryStats() {
        cout << "Total Books: " << totalBooks << ", Available: " << availableBooks
             << ", Borrowed: " << borrowedBooks << endl;
    }
    static double getAvailabilityRate() {
        if (totalBooks == 0) return 0;
        return (double)availableBooks / totalBooks * 100;
    }
};

int Book::totalBooks = 0;
int Book::availableBooks = 0;
int Book::borrowedBooks = 0;

int main() {
    Book b1("Book A", "Author A", "111");
    Book b2("Book B", "Author B", "222");
    Book b3("Book C", "Author C", "333");
    Book b4("Book D", "Author D", "444");
    Book b5("Book E", "Author E", "555");
    b1.borrowBook();
    b3.borrowBook();
    b2.borrowBook();
    b3.returnBook();
    b1.displayBookInfo();
    b3.displayBookInfo();
    Book::displayLibraryStats();
    cout << "Availability Rate: " << Book::getAvailabilityRate() << "%" << endl;
    return 0;
}
