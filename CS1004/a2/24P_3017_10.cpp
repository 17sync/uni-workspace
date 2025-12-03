#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }
    void showPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
private:
    char grade;
public:
    void setStudent(string n, int a, char g) {
        setPerson(n, a);
        grade = g;
    }

    void showStudent() {
        showPerson();
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s;
    s.setStudent("John", 20, 'A');
    s.showStudent();
    return 0;
}
