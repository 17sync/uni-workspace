#include <iostream>
using namespace std;
struct Point;
void inputPoints(Point* points, int size);
void translatePoints(Point* points, int size, int dx, int dy);
void printPoints(Point* points, int size);

struct Point{
    int x, y;
};

int main(){
    int numPoints;
    
    cout<<"Enter the number of points: ";
    cin>>numPoints;

    Point* points=new Point[numPoints];

    inputPoints(points, numPoints);

    cout<<"\nOriginal Points:\n";
    printPoints(points, numPoints);

    int dx, dy;
    cout<<"\nEnter translation values (dx dy): ";
    cin>>dx>>dy;

    translatePoints(points, numPoints, dx, dy);

    cout<<"\nTranslated Points:\n";
    printPoints(points, numPoints);

    delete[] points;
    points=NULL;
}

void inputPoints(Point* points, int size){
    for (int i=0; i<size; i++) {
        cout<<"Enter coordinates for point #"<<i + 1<<" (x y): ";
        cin>>points[i].x>>points[i].y;
    }
}

void translatePoints(Point* points, int size, int dx, int dy){
    for(int i=0;i<size;i++){
        points[i].x+=dx;
        points[i].y+=dy;
    }
}

void printPoints(Point* points, int size){
    for(int i=0;i<size;i++){
        cout<<"("<<points[i].x<<", "<<points[i].y<<")\n";
    }
}

