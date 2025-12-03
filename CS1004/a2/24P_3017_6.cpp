#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char* name;
public:
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Shallow Copy Constructor
    Person(const Person& p) {
        name = p.name;
    }

    // Deep Copy Constructor
    Person deepCopy(const Person& p) {
        Person copy("temp");
        delete[] copy.name;
        copy.name = new char[strlen(p.name) + 1];
        strcpy(copy.name, p.name);
        return copy;
    }

    void showName() {
        cout << "Name: " << name << endl;
    }

    ~Person() {
        delete[] name;
    }
};

int main() {
    Person p1("John");

    // Shallow copy
    Person p2 = p1;

    // Deep copy
    Person p3 = p1.deepCopy(p1);

    cout << "Original: ";
    p1.showName();
    cout << "Shallow Copy: ";
    p2.showName();
    cout << "Deep Copy: ";
    p3.showName();

    return 0;
}
