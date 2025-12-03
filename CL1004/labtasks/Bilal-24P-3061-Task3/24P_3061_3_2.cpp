#include<iostream>
using namespace std;

class Shape{
    protected:
    string color;

    public:
    Shape(string c){
        color=c;
    }

    void displayColor(){
        cout<<"Color: "<<color<<endl;
    }

    virtual float calculateArea(){
        return 0;
    }

    virtual void displayInfo(){
        displayColor();
    }
};

class Circle: public Shape{
    float radius;

    public:
    Circle(float r, string c): Shape(c){
        radius=r;
    }

    float calculateArea(){
        float area=3.142*(radius*radius);
        return area;
    }

    void displayInfo(){
        displayColor();
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
    }
};

class Rectangle: public Shape{
    float length;
    float width;

    public:
    Rectangle(float l, float w, string c): Shape(c){
        length=l;
        width=w;
    }

    float calculateArea(){
        float area=length*width;
        return area;
    }

    void displayInfo(){
        displayColor();
        cout<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
    }
};

int main(){
    Shape *s[2];
    Circle c(2, "Red");
    Rectangle r(2, 4, "Black");

    s[1]=&c;
    s[2]=&r;

    for(int i=0;i<2;i++){
        s[i]->displayInfo();
        cout<<endl;
    }

    for(int i=0;i<2;i++){
        cout<<"Area through Polymorphism: "<<s[i]->calculateArea()<<endl;
    }
}