#include <iostream>
using namespace std;

class Employee {
    int id;
    const int salary;
public:
    Employee(int idVal, int salaryVal) : id(idVal), salary(salaryVal) {
        cout << "Address of this object: " << this << endl;
        cout << "Employee ID: " << this->id << ", Salary: " << this->salary << endl;
    }
};

int main() {
    Employee e1(101, 50000);
    return 0;
}
