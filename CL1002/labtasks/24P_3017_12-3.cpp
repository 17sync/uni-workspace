#include <iostream>
using namespace std;

const float pi = 3.141592653589;
const float half = 0.5;

float area (float radius);
float area (float length, float width);
float area (const float half, float base, float height);

int main ()
{

    //Declaration of variables storing length, width, base, height and radius
    float length, width, base, height, radius;

    //Selection of shape
    char select;
    cout<<"\t|| Shape Area Calculator ||\n\nCircle (C)\nRectangle (R)\nTriangle (T)\n\nSelection: ";
    cin>>select;

    //Calling functions to perform area calculation
    switch (select){
        case ('c'):
        case ('C'):
        cout<<"\nEnter the radius of the circle: ";
        cin>>radius;
        cout<<"The area of the circle is: "<<area(radius);
        break;
        case ('r'):
        case ('R'):
        cout<<"\nEnter the length and width of the rectangle: ";
        cin>>length>>width;
        cout<<"The area of the rectangle is: "<<area(length, width);
        break;
        case ('t'):
        case ('T'):
        cout<<"\nEnter the base and height of the triangle: ";
        cin>>base>>height;
        cout<<"The area of the triangle is: "<<area(half, base, height);
        break;
        default:
        cout<<"Invalid selection.";
        break;
    }

}

float area (float radius)
{
    float area = pi*radius*radius;

    return area;
}
float area (float length, float width)
{
    float area = length*width;

    return area;
}
float area (const float half, float base, float height)
{
    float area = half*base*height;

    return area;
}
