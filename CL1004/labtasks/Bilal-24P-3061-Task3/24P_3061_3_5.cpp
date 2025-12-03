#include<iostream>
using namespace std;

class Student{
    string studentId;
    string name;
    string major;
    string registeredCourses[3];
    int courseCount;

    public:
    Student(string id, string n, string m){
        studentId=id;
        name=n;
        major=m;
        courseCount=0;
    }

    void registerCourse(string courseId){
        if(courseCount<5){
            registeredCourses[courseCount]=courseId;
            courseCount++;
            cout<<name<<" registered for course "<<courseId<<" successfully."<<endl;
        }else cout<<"Cannot register more than 5 courses"<<endl;
    }

    void dropCourse(string courseId){
        for(int i=0;i<courseCount;i++){
            if(registeredCourses[i]==courseId){
                for(int j=i;j<courseCount-1;j++){
                    registeredCourses[j]=registeredCourses[j+1];
                }
                courseCount--;
                cout<<name<<" dropped course "<<courseId<<" successfully."<<endl;
                return;
            }
        }
        cout<<"Course not found."<<endl;
    }

    void displayInfo(){
        cout<<"Student ID: "<<studentId<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Major: "<<major<<endl;
        cout<<"Registered Courses: ";
        if(courseCount==0) cout<<"None";
        else{
            for(int i=0;i<courseCount;i++) cout<<registeredCourses[i]<<" ";
        }
        cout<<endl;
    }

    string getStudentId(){
        return studentId;
    }

    string getName(){
        return name;
    }

    string getMajor(){
        return major;
    }
};

class Course{
    string courseId;
    string title;
    int credits;
    int capacity;
    int enrolledStudents;

    public:
    Course(string id, string t, int c, int cap){
        courseId=id;
        title=t;
        credits=c;
        capacity=cap;
        enrolledStudents=0;
    }

    bool enrollStudent(){
        if(enrolledStudents<capacity){
            enrolledStudents++;
            return true;
        }
        return false;
    }

    bool dropStudent(){
        if(enrolledStudents>0){
            enrolledStudents--;
            return true;
        }
        return false;
    }

    void displayInfo(){
        cout<<"Course ID: "<<courseId<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Credits: "<<credits<<endl;
        cout<<"Capacity: "<<capacity<<endl;
        cout<<"Enrolled Students: "<<enrolledStudents<<endl;
    }

    string getCourseId(){
        return courseId;
    }
};

class Department{
    string name;
    Course *courses[3];
    Student *students[5];
    int courseCount;
    int studentCount;

    public:
    Department(string n){
        name=n;
        courseCount=0;
        studentCount=0;
        for(int i=0;i<10;i++) courses[i]=nullptr;
        for(int i=0;i<20;i++) students[i]=nullptr;
    }

    void addCourse(Course course){
        if(courseCount<10){
            courses[courseCount]=&course;
            courseCount++;
            cout<<"Course "<<course.getCourseId()<<" added to department"<<endl;
        }else cout<<"Department full, cannot add any more courses."<<endl;
    }

    void addStudent(Student student){
        if(studentCount<20){
            students[studentCount]=&student;
            studentCount++;
            cout<<"Student "<<student.getStudentId()<<" added to department"<<endl;
        }else cout<<"Department full, cannot add any more students"<<endl;
    }

    void registerStudentForCourse(string studentId, string courseId){
        Student *s=nullptr;
        Course *c=nullptr;
        
        for(int i=0;i<studentCount;i++) if(students[i]->getStudentId()==studentId) s=students[i];
        for(int i=0;i<courseCount;i++) if(courses[i]->getCourseId()==courseId) c=courses[i];

        if(s!=nullptr && c!=nullptr){
            if(c->enrollStudent()) s->registerCourse(courseId);
            else cout<<"Course capacity reached"<<endl;
        }else cout<<"Student or course not found"<<endl;
    }

    void dropStudentFromCourse(string studentId, string courseId){
        Student *s=nullptr;
        Course *c=nullptr;

        for(int i=0;i<studentCount;i++) if(students[i]->getStudentId()==studentId) s=students[i];
        for(int i=0;i<courseCount;i++) if(courses[i]->getCourseId()==courseId) c=courses[i];

        if(s!=nullptr && c!=nullptr){
            if(c->dropStudent()) s->dropCourse(courseId);
            else cout<<"No student enrolled in this course"<<endl;
        }else cout<<"Student or course not found"<<endl;
    }

    void displayCourseInfo(string courseId){
        for(int i=0;i<courseCount;i++){
            if(courses[i]->getCourseId()==courseId){
                courses[i]->displayInfo();
                return;
            }
        }
        cout<<"Course not found"<<endl;
    }

    void displayStudentInfo(string studentId){
        for(int i=0;i<studentCount;i++){
            if(students[i]->getStudentId()==studentId){
                students[i]->displayInfo();
                return;
            }
        }
        cout<<"Student not found"<<endl;
    }

    void displayAllCourses(){
        cout<<"All Courses in Department:"<<endl;
        for(int i=0;i<courseCount;i++){
            courses[i]->displayInfo();
            cout<<endl;
        }
    }

    void displayAllStudents(){
        cout<<"All Students in Department:"<<endl;
        for(int i=0;i<studentCount;i++){
            students[i]->displayInfo();
            cout<<endl;
        }
    }
};

int main(){
    Department d("Software Engineering");

    Course c1("CS1002", "Programming Fundamentals", 3, 2);
    Course c2("CS1004", "Object Oriented Programming", 4, 3);
    Course c3("CS2001", "Data Structures", 4, 2);

    d.addCourse(c1);
    d.addCourse(c2);
    d.addCourse(c3);

    Student s1("3061", "Bilal Malik", "SE");
    Student s2("3075", "Ahmad Ali Shah", "SE");
    Student s3("3006", "Abdul Saboor", "MBBS");
    Student s4("3017", "Aun Anis", "SE");
    Student s5("3112", "Mashaal Khan", "SE");

    d.addStudent(s1);
    d.addStudent(s2);
    d.addStudent(s3);
    d.addStudent(s4);
    d.addStudent(s5);

    d.registerStudentForCourse("3017", "CS1004");
    d.registerStudentForCourse("3061", "CS2001");
    d.registerStudentForCourse("3075", "CS2001");

    d.dropStudentFromCourse("S001","CS101");

    d.displayCourseInfo("CS2001");
    d.displayStudentInfo("3061");

    d.displayAllCourses();
    d.displayAllStudents();
}
