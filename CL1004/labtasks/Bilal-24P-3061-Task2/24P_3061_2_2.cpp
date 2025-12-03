#include<iostream>
using namespace std;

struct Student{
    string name;
    int ID;
    float scores[3];
    float average;
    char grade;
}s[5];

void calculateAverage(Student*);
void displayStatistics(Student*);

int main(){
    s[0]={"Bilal Malik", 3061, {85, 93, 88}};
    s[1]={"Abdul Saboor", 3006, {99, 5, 78}};
    s[2]={"Ahmad Ali Shah", 3075, {80, 91, 73}};
    s[3]={"Aun Anis", 3017, {64, 69, 12}};
    s[4]={"Mashaal Khan", 3112, {89, 91, 86}};   

    calculateAverage(s);
    displayStatistics(s);
}

void calculateAverage(Student *s){
    for(int i=0;i<5;i++){
        s[i].average=(s[i].scores[0]+s[i].scores[1]+s[i].scores[2])/3;
        if(s[i].average<50) s[i].grade='F';
        else if(s[i].average>=50 && s[i].average<=60) s[i].grade='D';
        else if(s[i].average>60 && s[i].average<=70) s[i].grade='C';
        else if(s[i].average>70 && s[i].average<=80) s[i].grade='B';
        else if(s[i].average>80 && s[i].average<=100) s[i].grade='A';
    }
}

void displayStatistics(Student *s){
    float lowestAverage=s[0].average;
    int indexL=0;
    float highestAverage=s[0].average;
    int indexH=0;
    
    for(int i=0;i<5;i++){
        if(s[i].average>highestAverage){
            highestAverage=s[i].average;
            indexH=i;
        }
    }

    for(int i=0;i<5;i++){
        if(s[i].average<lowestAverage){
            lowestAverage=s[i].average;
            indexL=i;
        }
    }

    float sumAverage=0;
    for(int i=0;i<5;i++){
        sumAverage+=s[i].average;
    }

    float classAverage=sumAverage/5;
    
    cout<<"\nHighest Average: "<<s[indexH].name<<" "<<highestAverage<<endl;
    cout<<"Lowest Average: "<<s[indexL].name<<" "<<lowestAverage<<endl;
    cout<<"Class Average: "<<classAverage<<endl;
}