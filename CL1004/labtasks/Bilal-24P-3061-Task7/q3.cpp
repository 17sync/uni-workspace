#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    string department;
    string hireDate;
    double baseSalary;

public:
    Employee(string n = "", int i = 0, string d = "", string h = "", double s = 0.0)
        : name(n), id(i), department(d), hireDate(h), baseSalary(s) {}

    virtual double calculateSalary() = 0;
    virtual void giveRaise(double percent) { baseSalary += baseSalary * (percent / 100.0); }
    virtual double performanceRating() = 0;

    virtual void displayInfo() {
        cout << "Employee: " << name << " (ID: " << id << ", "
             << department << ", Hired: " << hireDate << ")" << endl;
    }

    string getName() { return name; }
    string getDept() { return department; }
};

class FullTimeEmployee : public Employee {
    double bonus;
    double benefits;

public:
    FullTimeEmployee(string n, int i, string d, string h, double s,
                     double b, double bf)
        : Employee(n, i, d, h, s), bonus(b), benefits(bf) {}

    double calculateSalary() {
        return baseSalary + bonus + benefits;
    }

    void giveRaise(double percent) {
        baseSalary += baseSalary * (percent / 100.0);
        bonus += bonus * 0.05;
    }

    double performanceRating() {
        return 4.8;
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Type: Full-time" << endl;
        cout << "Base Salary: $" << baseSalary << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Benefits: $" << benefits << endl;
        cout << "Total Monthly Salary: $" << calculateSalary() << endl;
        cout << "Performance: Excellent (" << performanceRating() << "/5)" << endl;
    }
};

class PartTimeEmployee : public Employee {
    int hours;
    double rate;

public:
    PartTimeEmployee(string n, int i, string d, string h,
                     int hrs, double r)
        : Employee(n, i, d, h), hours(hrs), rate(r) {}

    double calculateSalary() {
        return hours * rate;
    }

    void giveRaise(double percent) {
        rate += rate * (percent / 100.0);
    }

    double performanceRating() {
        return 4.0;
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Type: Part-time" << endl;
        cout << "Hours: " << hours << " Rate: $" << rate << endl;
        cout << "Total Monthly Salary: $" << calculateSalary() << endl;
        cout << "Performance: Good (" << performanceRating() << "/5)" << endl;
    }
};

class ContractEmployee : public Employee {
    double projectPay;

public:
    ContractEmployee(string n, int i, string d, string h, double p)
        : Employee(n, i, d, h), projectPay(p) {}

    double calculateSalary() {
        return projectPay;
    }

    double performanceRating() {
        return 4.3;
    }

    void giveRaise(double percent) {
        projectPay += projectPay * (percent / 100.0);
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Type: Contract" << endl;
        cout << "Project Pay: $" << projectPay << endl;
        cout << "Performance: Very Good (" << performanceRating() << "/5)" << endl;
    }
};

class Intern : public Employee {
    double stipend;

public:
    Intern(string n, int i, string d, string h, double st)
        : Employee(n, i, d, h), stipend(st) {}

    double calculateSalary() {
        return stipend;
    }

    void giveRaise(double percent) {
        stipend += stipend * (percent / 100.0);
    }

    double performanceRating() {
        return 3.7;
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Type: Intern" << endl;
        cout << "Stipend: $" << stipend << endl;
        cout << "Performance: Good (" << performanceRating() << "/5)" << endl;
    }
};

class HRSystem {
    Employee* employees[100];
    int count;

public:
    HRSystem() : count(0) {}

    void addEmployee(Employee* e) {
        if (count < 100) employees[count++] = e;
    }

    void showAll() {
        for (int i = 0; i < count; i++) {
            cout << "---------------------------------" << endl;
            employees[i]->displayInfo();
        }
    }

    double totalPayroll() {
        double sum = 0;
        for (int i = 0; i < count; i++)
            sum += employees[i]->calculateSalary();
        return sum;
    }

    void searchByDept(string d) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getDept() == d)
                employees[i]->displayInfo();
        }
    }

    void searchByName(string n) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getName() == n)
                employees[i]->displayInfo();
        }
    }
};

int main() {
    HRSystem hr;

    hr.addEmployee(new FullTimeEmployee("John Doe", 1001, "Engineering", "2020-01-15", 8000, 2000, 1500));
    hr.addEmployee(new PartTimeEmployee("Alice", 1002, "Support", "2022-02-10", 80, 20));
    hr.addEmployee(new ContractEmployee("Michael", 1003, "Design", "2023-03-18", 5000));
    hr.addEmployee(new Intern("Bob", 1004, "Engineering", "2024-05-01", 1200));

    cout << "=== All Employees ===" << endl;
    hr.showAll();

    cout << "\nTotal Payroll: $" << hr.totalPayroll() << endl;

    return 0;
}
