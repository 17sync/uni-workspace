#include <iostream>
using namespace std;
class Number {
private:
int value;  

public:
Number(int val=0) {
    value=val; }
    
Number operator+(const Number& obj) {
    return Number(value + obj.value); 
}
void input() {
    cout<<"Enter value: ";
    cin>>value; }
    void display() const {
        cout<<"Value = "<<value<<endl;  }
};

int main() {
Number num1, num2, sum;  
num1.input();
num2.input();
sum=num1+num2;
cout<<"Sum of objects: ";
sum.display();

    return 0;
}
