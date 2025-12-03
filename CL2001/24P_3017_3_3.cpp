#include<iostream>
using namespace std;

class studentList{
    int *list;
    int capacity;
    int length;
    string courseName;

    public:
    studentList();
    studentList(int);
    ~studentList();
    void createList();
    bool isFull();
    bool isEmpty();
    void copyList(studentList);
    void clearList();
    void insertStudent(int);
    void insertStudentAt(int, int);
    void removeStudent(int);
    int getStudent(int);
    void update(int, int);
    bool find(int);
    int getLength();
    void printList();
    void reverseList();
    void sort();
};

int main(){
    cout<<"24P-3017\n"<<endl;

    int choice;
    studentList c, backup;
    do{
        cout<<"\n|| -- Student List Management System -- ||"<<endl;
        cout<<"1. Create New List\n2. Copy Existing List\n3. Clear List";
        cout<<"\n4. Add Student to List\n5. Add Student to an Index\n6. Remove Student";
        cout<<"\n7. Check for Student at Index\n8. Update an Index\n9. Find Student in List";
        cout<<"\n10. Check Total Students in List\n11. Display List\n12. Sort List by ID";
        cout<<"\n13. Exit program"<<endl;
        cout<<"\nSelect operation: "; cin>>choice;
        
        switch(choice){
            case 1:{
                int capacity; cout<<"\nEnter student limit for course: "; cin>>capacity;
                c=studentList(capacity);
                c.createList();
                break;
            }
            case 2:{
                backup=studentList(c.getLength());
                backup.createList();
                c.copyList(backup);
                break;
            }
            case 3:{
                c.clearList();
                break;
            }
            case 4:{
                int studentID;
                cout<<"\nEnter student ID: "; cin>>studentID;
                c.insertStudent(studentID);
                break;
            }
            case 5:{
                int studentID, index;
                cout<<"\nEnter student ID: "; cin>>studentID;
                cout<<"Enter index: "; cin>>index;
                c.insertStudentAt(studentID, index);
                break;
            }
            case 6:{
                int studentID;
                cout<<"\nEnter student ID: "; cin>>studentID;
                c.removeStudent(studentID);
                break;
            }
            case 7:{
                int index;
                cout<<"\nEnter index: "; cin>>index;
                if(c.getStudent(index)==-1) cout<<"Invalid Index, try again."<<endl;
                else cout<<"Student at index #"<<index<<" "<<c.getStudent(index);
                break;
            }
            case 8:{
                int studentID, index;
                cout<<"\nEnter student ID: "; cin>>studentID;
                cout<<"Enter index: "; cin>>index;
                c.update(studentID, index);
                break;
            }
            case 9:{
                int studentID;
                cout<<"\nEnter student ID: "; cin>>studentID;
                c.find(studentID);
                break;
            }
            case 10:{
                cout<<"\nTotal students enrolled in course "<<c.getLength()<<endl;
                break;
            }
            case 11:{
                c.printList();
                break;
            }
            case 12:{
                c.sort();
                break;
            }
            case 13:{
                cout<<"\nExiting Program..."<<endl;
                break;
            }
        }
    }while(choice!=13);
    
}

studentList::studentList(){}

studentList::studentList(int cap){
    capacity=cap;
    list=new int[capacity];
    string name;
    cout<<"Enter course title: "; cin>>name;
    courseName=name;
}

studentList::~studentList(){
    delete[] list;
}

void studentList::createList(){
    length=0;
    cout<<"New List for course "<<courseName<<" has been created."<<endl;
}

bool studentList::isEmpty(){
    if(length==0) return true;
    else return false;
}

bool studentList::isFull(){
    if(length==capacity) return true;
    else return false;
}

void studentList::clearList(){
    length=0;
    cout<<"List for course "<<courseName<<" has been cleared."<<endl;
}

void studentList::copyList(studentList otherList){
    otherList.clearList();
    otherList.length=length;

    for(int i=0;i<length;i++){
        *(otherList.list+i)=*(list+i);
    }
    cout<<"List from "<<courseName<<" has successfully been copied to "<<otherList.courseName<<endl;
}

void studentList::insertStudent(int studentID){
    if(isFull()==true){
        cout<<"Course is full, cannot enroll anymore students."<<endl;
        return;
    }
    if(studentID<0){
        cout<<"Invalid student ID."<<endl;
        return;
    }
    
    *(list+length)=studentID;
    length++;
    cout<<"Student #"<<studentID<<" has been successfully added to course "<<courseName<<endl;
}

void studentList::insertStudentAt(int studentID, int index){
    if(isFull()==true){
        cout<<"Course is full, cannot add any more students."<<endl;
        return;
    }
    else if(isEmpty()==true && index!=0){
        cout<<"Course list is currently empty."<<endl;
    }
    else if(index<0 || index>length){
        cout<<"Invalid index, try again."<<endl;
    }

    for(int i=length;i>index;i--){
        *(list+i)=*(list+i-1);
    }
    length++;
    cout<<"Student #"<<studentID<<" successfully added at index #"<<index<<"to course "<<courseName<<endl;
}

void studentList::removeStudent(int studentID){
    if(isEmpty()==true){
        cout<<"Course list is currently empty."<<endl;
        return;
    }
    else if(studentID<0){
        cout<<"Invalid student ID"<<endl;
        return;
    }

    for(int i=0;i<length;i++){
        if(*(list+i)==studentID){
            for(int j=i;j<length-1;j++){
                *(list+j)=*(list+j+1);
            }
            cout<<"Successfully removed student #"<<studentID<<" from course "<<courseName<<endl;
            return;
        }
        else continue;
    }

    cout<<"No such student enrolled in "<<courseName<<endl;
}

int studentList::getStudent(int index){
    if(index>length-1 || index<0) return -1;
    return *(list+index);
}

int studentList::getLength(){
    return length;
}

void studentList::update(int studentID, int index){
    if(index>length-1 || index<0){
        cout<<"Invalid index, try again."<<endl;
        return;
    }

    *(list+index)=studentID;
    cout<<"Successfully updated index #"<<index<<" in course "<<courseName;
} 

bool studentList::find(int studentID){
    if(studentID<0){
        cout<<"Invalid index."<<endl;
        return false;
    }

    int index;
    for(int i=0;i<length;i++){
        if(*(list+i)==studentID){
            index=i;
            cout<<"Student #"<<studentID<<" found at index #"<<index<<" in course "<<courseName<<endl;
            return true;
        }
        else continue;
    }
    cout<<"No such student in course "<<courseName<<endl;
    return false;
}

void studentList::printList(){
    cout<<"\n"<<courseName<<" student list:\n";
    for(int i=0;i<length;i++){
        cout<<*(list+i)<<" ";
    }
    cout<<endl;
}

void studentList::reverseList(){
    for(int i=0;i<length;i++){
        bool swapped=false;
        for(int j=0;j<length;j++){
            if(*(list+j)<*(list+j+1)){
                swap(*(list+j), *(list+j+1));
                swapped=true;
            }
            else continue;
        }
        if(!swapped) break;
    }

    cout<<"Course list for "<<courseName<<" has been sorted in descending order successfully!"<<endl;    
}

void studentList::sort(){
    for(int i=0;i<length;i++){
        bool swapped=false;
        for(int j=0;j<length;j++){
            if(*(list+j)>*(list+j+1)){
                swap(*(list+j), *(list+j+1));
                swapped=true;
            }
            else continue;
        }
        if(!swapped) break;
    }

    cout<<"Course list for "<<courseName<<" has been sorted in ascending order successfully!"<<endl;
}