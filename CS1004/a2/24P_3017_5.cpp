#include <iostream>
using namespace std;

class Rectangle {
    int length, breadth;
public:
    Rectangle(int l, int b) : length(l), breadth(b) {}

    // Copy Constructor
    Rectangle(const Rectangle& r) {
        length = r.length;
        breadth = r.breadth;
    }

    void display() {
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
    }
};

int main() {
    Rectangle r1(10, 5);
    Rectangle r2 = r1; // Calls copy constructor
    r2.display();
    return 0;
}
