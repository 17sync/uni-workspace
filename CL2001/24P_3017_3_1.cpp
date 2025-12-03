#include<iostream>
using namespace std;

class waitingArea{
    int *List;
    int capacity;
    int length;

    public:
    waitingArea();
    ~waitingArea();
    bool isEmpty();
    bool isFull();
    void addPatient(int);
    void callPatient();
    bool checkForPatient(int);
    void displayQueue();
};

int main(){
    cout<<"24P-3017\n"<<endl;
    waitingArea H1;

    H1.addPatient(7445);
    H1.addPatient(8766);
    H1.addPatient(9830);
    H1.addPatient(2131);
    H1.addPatient(6542);
    H1.addPatient(3776);

    H1.checkForPatient(7445);
    H1.displayQueue();
    H1.callPatient();
    H1.displayQueue();
}

waitingArea::waitingArea(){
    capacity=6;
    List=new int[capacity];
    length=0;
}

waitingArea::~waitingArea(){
    delete[] List;
}

bool waitingArea::isEmpty(){
    if(length==0) return true;
    else return false;
}

bool waitingArea::isFull(){
    if(length==capacity) return true;
    else return false;
}   

void waitingArea::addPatient(int patientNum){
    if(isFull()==true){
        cout<<"Waiting area is full, unable to add anymore patients."<<endl;
        return;
    }
    
    List[length]=patientNum;
    cout<<"Added patient #"<<patientNum<<" to the queue."<<endl;
    length++;
}

void waitingArea:: callPatient(){
    if(isEmpty()==true){
        cout<<"No patients in waiting area."<<endl;
        return;
    }

    cout<<"Patient #"<<List[0]<<" has been called."<<endl;
    for(int i=0;i<length-1;i++){
        List[i]=List[i+1];
    }
    length--;
}

bool waitingArea::checkForPatient(int patientNum){
    if(isEmpty()==true){
        cout<<"No patients in waiting area."<<endl;
        return false;
    }
    else if(List[0]==patientNum){
        cout<<"Patient #"<<patientNum<<"is next in queue."<<endl;
        return true;
    }

    for(int i=1;i<length;i++){
        if(List[i]==patientNum){
            cout<<"Patient is at spot #"<<i<<" in queue."<<endl;
            return true;
        }
    }

    cout<<"Patient not in waiting area."<<endl;
    return false;
}

void waitingArea::displayQueue(){
    cout<<"\nWaiting Area: "<<endl;
    for(int i=0;i<length;i++){
        cout<<List[i]<<" ";
    }
    cout<<"\n"<<endl;
}
