#include<iostream>
using namespace std;

int main(){
    int rollNo=3017;

    int *teacher=&rollNo;
    int **incharge=&teacher;
    int ***principal=&incharge;

    cout<<"24P-3017"<<endl;
    cout<<"\nDirect roll number: "<<rollNo;
    cout<<"\nRoll number through teacher: "<<*teacher;
    cout<<"\nRoll number through class incharge: "<<**incharge;
    cout<<"\nRoll number through principal: "<<***principal;
}