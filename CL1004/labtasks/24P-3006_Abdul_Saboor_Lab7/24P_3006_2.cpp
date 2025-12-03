#include<iostream>
#include<cmath>
using namespace std;

class Shape{
protected:
    string color,name;
public:
    Shape(string c,string n):color(c),name(n){}
    virtual double area()=0;
    virtual double perimeter()=0;
    virtual void draw(){cout<<"Drawing "<<name<<"\n";}
    virtual void getDetails(){
        cout<<"Shape:"<<name<<" Color:"<<color<<" Area:"<<area()<<" Perimeter:"<<perimeter()<<"\n";
    }
    bool operator<(Shape& s){return area()<s.area();}
    bool operator>(Shape& s){return area()>s.area();}
    virtual ~Shape(){}
};

class Circle:public Shape{
    double r;
public:
    Circle(string c,double R):Shape(c,"Circle"),r(R<=0?throw invalid_argument("Invalid radius"):R){}
    double area(){return 3.14159*r*r;}
    double perimeter(){return 2*3.14159*r;}
    void draw(){
        cout<<"  ***  \n";
        cout<<" *   * \n";
        cout<<" *   * \n";
        cout<<"  ***  \n";
    }
};

class Rectangle:public Shape{
    double w,h;
public:
    Rectangle(string c,double W,double H):Shape(c,"Rectangle"),w(W<=0||H<=0?throw invalid_argument("Invalid rectangle"):W),h(H){}
    double area(){return w*h;}
    double perimeter(){return 2*(w+h);}
    void draw(){
        cout<<"******\n";
        cout<<"*    *\n";
        cout<<"******\n";
    }
};

class Triangle:public Shape{
    double a,b,c;
public:
    Triangle(string col,double A,double B,double C):Shape(col,"Triangle"),a(A),b(B),c(C){
        if(a<=0||b<=0||c<=0||a+b<=c||a+c<=b||b+c<=a)throw invalid_argument("Invalid triangle");
    }
    double area(){
        double s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double perimeter(){return a+b+c;}
    void draw(){
        cout<<"  /\\\n";
        cout<<" /  \\\n";
        cout<<"/____\\\n";
    }
};

class Pentagon:public Shape{
    double side;
public:
    Pentagon(string c,double s):Shape(c,"Pentagon"),side(s<=0?throw invalid_argument("Invalid pentagon"):s){}
    double area(){return 1.72048*side*side;}
    double perimeter(){return 5*side;}
    void draw(){
        cout<<"  ***  \n";
        cout<<" *   * \n";
        cout<<"*     *\n";
        cout<<" ***** \n";
    }
};

class ShapeManager{
    Shape* arr[50];
    int cnt;
public:
    ShapeManager():cnt(0){}
    void add(Shape* s){if(cnt<50)arr[cnt++]=s;}
    void showAll(){
        for(int i=0;i<cnt;i++){
            arr[i]->getDetails();
            arr[i]->draw();
            cout<<"------\n";
        }
    }
    void sortByArea(){
        for(int i=0;i<cnt-1;i++)
            for(int j=i+1;j<cnt;j++)
                if(*arr[j]<*arr[i]){Shape* t=arr[i];arr[i]=arr[j];arr[j]=t;}
    }
    Shape* largest(){
        if(cnt==0)return nullptr;
        Shape* mx=arr[0];
        for(int i=1;i<cnt;i++)if(*arr[i]>*mx)mx=arr[i];
        return mx;
    }
    ~ShapeManager(){for(int i=0;i<cnt;i++)delete arr[i];}
};

int main(){
    ShapeManager m;
    m.add(new Circle("Red",5));
    m.add(new Rectangle("Blue",4,6));
    m.add(new Triangle("Green",3,4,5));
    m.add(new Pentagon("Yellow",4));

    m.showAll();
    m.sortByArea();
    cout<<"Sorted by area:\n";
    m.showAll();

    Shape* big=m.largest();
    if(big){
        cout<<"Largest shape:\n";
        big->getDetails();
        big->draw();
    }
}
