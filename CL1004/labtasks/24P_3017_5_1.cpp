#include <iostream>
using namespace std;
struct rectangle;
int area(const rectangle &r);

struct rectangle{
    int length;
    int width;
}r;

int main(){
    cout<<"Enter the length of the rectangle: ";
    cin>>r.length;
    cout<<"Enter the width of the rectangle: ";
    cin>>r.width;
    cout<<"The area of the rectangle is: "<<area(r);
}

int area(const rectangle &r){
    int area;
    area=r.length*r.width;

    return area;
}