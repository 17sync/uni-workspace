#include <iostream>
using namespace std;

class Student {
    string name;
    int studentID;
    double GPA;
    string* courses;
    int numCourses;
public:
    Student(string n, int id, double g, int count) : name(n), studentID(id), GPA(g), numCourses(count) {
        courses = new string[numCourses];
        for (int i = 0; i < numCourses; i++) {
            cout << "Enter course " << i + 1 << " for " << name << ": ";
            cin >> courses[i];
        }
    }
    ~Student() { delete[] courses; }
    void displayInfo() {
        cout << "Name: " << name << ", ID: " << studentID << ", GPA: " << GPA << ", Courses: ";
        for (int i = 0; i < numCourses; i++) cout << courses[i] << " ";
        cout << endl;
    }
    double getGPA() { return GPA; }
};

class Database {
    Student** students;
    int count;
public:
    Database(int c) { count = c; students = new Student*[count]; }
    void createStudent(int index) {
        string name;
        int id, num;
        double gpa;
        cout << "Enter name: "; cin >> name;
        cout << "Enter ID: "; cin >> id;
        cout << "Enter GPA: "; cin >> gpa;
        cout << "Enter number of courses: "; cin >> num;
        students[index] = new Student(name, id, gpa, num);
    }
    void displayAllStudents() {
        for (int i = 0; i < count; i++) students[i]->displayInfo();
    }
    double getAverageGPA() {
        double sum = 0;
        for (int i = 0; i < count; i++) sum += students[i]->getGPA();
        return sum / count;
    }
    ~Database() {
        for (int i = 0; i < count; i++) delete students[i];
        delete[] students;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Database* db = new Database(n);
    for (int i = 0; i < n; i++) db->createStudent(i);
    db->displayAllStudents();
    cout << "Average GPA: " << db->getAverageGPA() << endl;
    delete db;
    return 0;
}
