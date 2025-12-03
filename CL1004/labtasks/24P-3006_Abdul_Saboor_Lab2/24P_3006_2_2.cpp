#include<iostream>
using namespace std;

struct Student{
    string name;
    int ID;
    int scores[3];
    int average;
    char grade;
};

void calcAvg(Student *s){
    for(int i=0;i<5;i++){
        s[i].average=(s[i].scores[0]+s[i].scores[1]+s[i].scores[2])/3;
        if(s[i].average<50) s[i].grade='F';
        else if(s[i].average>=50 && s[i].average<=60) s[i].grade='D';
        else if(s[i].average>60 && s[i].average<=70) s[i].grade='C';
        else if(s[i].average>70 && s[i].average<=80) s[i].grade='B';
        else if(s[i].average>80 && s[i].average<=100) s[i].grade='A';
    }
}

void printStats(Student *s){
    int lowest=s[0].average; int lowestIndex=0;
    int highest=s[0].average; int highestIndex=0;
    
    for(int i=0;i<5;i++){
        if(s[i].average>highest){
            highest=s[i].average;
            highestIndex=i;
        }
    }

    for(int i=0;i<5;i++){
        if(s[i].average<lowest){
            lowest=s[i].average;
            lowestIndex=i;
        }
    }

    int sumAverage=0;
    for(int i=0;i<5;i++){
        sumAverage+=s[i].average;
    }

    int classAvg=sumAverage/5;
    
    cout<<"\nHighest: "<<s[highestIndex].name<<" "<<highest<<endl;
    cout<<"Lowest: "<<s[lowestIndex].name<<" "<<lowest<<endl;
    cout<<"Average: "<<classAvg<<endl;
}

int main(){
    Student s[5];

    s[0]={"Student #1", 1000, {43, 87, 54}};
    s[1]={"Student #2", 1001, {91, 31, 78}};
    s[2]={"Student #3", 1002, {84, 71, 83}};
    s[3]={"Student #4", 1003, {23, 98, 45}};
    s[4]={"Student #5", 1004, {88, 34, 67}};   

    calcAvg(s);
    printStats(s);
}