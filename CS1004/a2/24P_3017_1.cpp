#include <iostream>
using namespace std;

class Employee {
    static int count;
public:
    Employee() { count++; }
    static void showCount() {
        cout << "Total Employees: " << count << endl;
    }
};
int Employee::count = 0;

int main() {
    Employee e1, e2, e3;
    Employee::showCount();
    return 0;
}
