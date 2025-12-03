#include <iostream>
using namespace std;
struct Student;
void sortbyaverage(Student *s, int num);
float average(const Student *s);

struct Student{
    char name[50];
    int num_subjects;
    int *scores;
}s[50];

int main(){
    int num;
    cout<<"Enter number of students: ";
    cin>>num;

    int counter=1;
    for(int i=0;i<num;i++){
        cout<<"\nStudent #"<<counter<<"\n";
        cout<<"Enter name: ";
        cin>>s[i].name;
        cout<<"Enter number of subjects: ";
        cin>>s[i].num_subjects;
        cout<<"Enter scores: ";
        s[i].scores=new int[s[i].num_subjects];
        for(int j=0;j<s[i].num_subjects;j++){
            cin>>s[i].scores[j];
        }    
        counter++;
    }

    counter=1;
    for(int i=0;i<num;i++){
        cout<<"\nAverage score of Student #"<<counter<<": ";
        cout<<average(&s[i]);
        counter++;
    }

    sortbyaverage(s, num);
    cout<<"\n\nStudents sorted by average score:\n";
    for (int i=0;i<num;i++) {
        cout<<s[i].name<< endl;
    }

    for(int i=0;i<num;i++) {
        delete[] s[i].scores;
        s[i].scores=NULL;
    }
}

float average(const Student *s){
    int sum=0;

    for(int i=0;i<s->num_subjects;i++){
        sum+=s->scores[i];
    }

    float average=sum/s->num_subjects;

    return average;
}

void sortbyaverage(Student *s, int num) {
    for (int i=0;i<num-1;i++){
        for (int j=0;j<num-i-1;j++){
            if (average(&s[j])<average(&s[j+1])){
                swap(s[j], s[j+1]);
            }
        }
    }
}

