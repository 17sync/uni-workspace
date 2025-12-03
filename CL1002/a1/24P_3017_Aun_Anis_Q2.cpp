#include <iostream>
using namespace std;

int main ()
{

    //Displaying subject of the program
    cout<<"\tLinear Equation Calculator\n\t--------------------------";
    
    //Declaration of variables for both points, slope and y-intercept
    int y1, y2, x1, x2;
    int mx, my, c;

    //Asking for coordinates from user
    cout<<"\nEnter coordinates of the first point: "; cin>>x1; cin>>y1;
    cout<<"Enter coordinates of the second point: "; cin>>x2; cin>>y2;
    cout<<"Enter the y-intercept: "; cin>>c;
    //Defining and calculating slope
    my = (y2-y1);
    mx = (x2-x1);

    //Displaying final equation
    if (my == mx)
    {
        cout<<"The equation of the straight line is: y = x + "<<c;
    }
    else 
    {
    cout<<"The equation of the straight line is: y = "<<my<<"/"<<mx<<"x + "<<c;
    }

}