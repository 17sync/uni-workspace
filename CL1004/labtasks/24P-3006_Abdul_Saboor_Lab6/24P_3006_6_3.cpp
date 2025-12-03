#include <iostream>
using namespace std;

class Faculty {
    string name, designation, department;
    int employeeID;
public:
    Faculty() {}
    Faculty(string n, int id, string d, string dept) : name(n), employeeID(id), designation(d), department(dept) {}
    void displayInfo() {
        cout << "Faculty: " << name << ", ID: " << employeeID << ", " << designation
             << ", Department: " << department << endl;
    }
    string getName() { return name; }
};

class Course {
    string courseName, courseCode;
    int creditHours;
    Faculty instructor;
public:
    Course() {}
    Course(string n, string code, int c) : courseName(n), courseCode(code), creditHours(c) {}
    void assignInstructor(Faculty f) { instructor = f; }
    void displayCourseInfo() {
        cout << "Course: " << courseName << " (" << courseCode << "), Credits: " << creditHours << endl;
        instructor.displayInfo();
    }
    int getCredits() { return creditHours; }
};

class Department {
    string departmentName;
    Faculty facultyMembers[10];
    Course courses[10];
    int facultyCount, courseCount;
public:
    Department(string name = "") : departmentName(name), facultyCount(0), courseCount(0) {}
    void addFaculty(Faculty f) { facultyMembers[facultyCount++] = f; }
    void addCourse(Course c) { courses[courseCount++] = c; }
    void displayDepartmentInfo() {
        cout << "Department: " << departmentName << endl;
        cout << "Faculty Members:" << endl;
        for (int i = 0; i < facultyCount; i++) facultyMembers[i].displayInfo();
        cout << "Courses:" << endl;
        for (int i = 0; i < courseCount; i++) courses[i].displayCourseInfo();
    }
    int getTotalCredits() {
        int sum = 0;
        for (int i = 0; i < courseCount; i++) sum += courses[i].getCredits();
        return sum;
    }
    int getFacultyCount() { return facultyCount; }
    int getCourseCount() { return courseCount; }
};

class University {
    string universityName;
    Department departments[10];
    int deptCount;
public:
    University(string name) : universityName(name), deptCount(0) {}
    void addDepartment(Department d) { departments[deptCount++] = d; }
    void displayUniversityInfo() {
        cout << "University: " << universityName << endl;
        for (int i = 0; i < deptCount; i++) departments[i].displayDepartmentInfo();
    }
    int getTotalFaculty() {
        int total = 0;
        for (int i = 0; i < deptCount; i++) total += departments[i].getFacultyCount();
        return total;
    }
    int getTotalCourses() {
        int total = 0;
        for (int i = 0; i < deptCount; i++) total += departments[i].getCourseCount();
        return total;
    }
};

int main() {
    Faculty f1("Alice", 101, "Professor", "CS");
    Faculty f2("Bob", 102, "Lecturer", "CS");
    Faculty f3("Carol", 103, "Associate Professor", "EE");

    Course c1("OOP", "CS101", 3);
    Course c2("DSA", "CS102", 4);
    Course c3("Circuits", "EE101", 3);
    Course c4("Signals", "EE102", 4);

    c1.assignInstructor(f1);
    c2.assignInstructor(f2);
    c3.assignInstructor(f3);
    c4.assignInstructor(f3);

    Department cs("Computer Science");
    cs.addFaculty(f1);
    cs.addFaculty(f2);
    cs.addCourse(c1);
    cs.addCourse(c2);

    Department ee("Electrical Engineering");
    ee.addFaculty(f3);
    ee.addCourse(c3);
    ee.addCourse(c4);

    University uni("Tech University");
    uni.addDepartment(cs);
    uni.addDepartment(ee);

    uni.displayUniversityInfo();
    cout << "Total Faculty: " << uni.getTotalFaculty() << endl;
    cout << "Total Courses: " << uni.getTotalCourses() << endl;
    return 0;
}

