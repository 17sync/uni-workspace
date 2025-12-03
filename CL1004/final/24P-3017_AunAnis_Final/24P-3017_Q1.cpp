#include<iostream>
using namespace std;

class professor{            //common interface for both types of professors
    public:
    virtual void salary_report()=0;
    virtual void view_details()=0;
};

class permenantprofessor: public professor{
    float salary;
    public:
    string name;
    int age;
    permenantprofessor(){}
    permenantprofessor(string n, float s, int a): name(n), salary(s), age(a){}
    void salary_report() override{
        cout<<name<<"'s Annual Salary: $"<<salary<<" (permenant professor)"<<endl;
    }
    void view_details() override{
        cout<<"\nPermenant Professor Details:\nName: "<<name;
        cout<<"\nAge: "<<age<<endl;
    }
    friend class admin;
};

class visitingprofessor: public professor{
    float salary;
    public:
    string name;
    int age;
    visitingprofessor(){}
    visitingprofessor(string n, float s, int a): name(n), salary(s), age(a){}
    void salary_report() override{
        cout<<name<<"'s Contract Salary: $"<<salary<<" (visitng professor)"<<endl;
    }
    void view_details() override{
        cout<<"\nVisiting Professor Details:\nName: "<<name;
        cout<<"\nAge: "<<age<<endl;
    }
    friend class admin;
};

class student{
    int id;
    public:
    string name;
    student(string n, int aidee): name(n), id(aidee){}
    void view_professorsalary(){
        cout<<"unauthorized personnel, cannot issue command."<<endl;
    }
};

class department{
    student *s1;
    public:
    permenantprofessor pp;
    visitingprofessor vp;
    string name;
    department(string n): name(n){}
    void add_permenantprofessor(permenantprofessor pp){
        this->pp=pp;
        cout<<"\n"<<pp.name<<" successfully added to department.";
    }

    void add_visitingprofessor(visitingprofessor vp){
        this->vp=vp;
        cout<<"\n"<<vp.name<<" successfully added to department.";
    }

    void add_student(student *s1){
        this->s1=s1;
        cout<<"\n"<<s1->name<<" successfully enrolled in department."<<endl;
    }

    void view_professordetails(professor *p){
        p->view_details();
        cout<<"Department: "<<name<<endl;
    }
};

class admin{
    public:
    void view_professorsalary(professor *p){
        p->salary_report();
    }
};

int main(){
    department d("Computer Science");
    permenantprofessor pp("Smith", 8000, 55);
    visitingprofessor vp("Brown", 5000, 40);
    student a("Alice", 0001);
    admin adm;
    d.add_student(&a);
    d.add_permenantprofessor(pp);
    d.add_visitingprofessor(vp);
    d.view_professordetails(&pp);
    d.view_professordetails(&vp);
    a.view_professorsalary();
    adm.view_professorsalary(&pp);
    adm.view_professorsalary(&vp);
}