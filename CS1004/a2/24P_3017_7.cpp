#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;
public:
    void setEmployee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }
    void showEmployee() {
        cout << "Employee Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee {
    string department;
public:
    void setManager(string n, int i, double s, string d) {
        setEmployee(n, i, s);
        department = d;
    }

    void showManager() {
        showEmployee();
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager m;
    m.setManager("Alice", 101, 75000, "HR");
    m.showManager();
    return 0;
}
