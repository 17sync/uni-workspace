#include <iostream>
using namespace std;

int main ()
{

    //Declaration of fuel, max distance, mileage in km and mileage in mile 
    int fuel, maxdis;
    float mileagekm, mileagemile;
    fuel = 40;
    maxdis = 700;

    //Defining mileage in km and mileage in mile
    mileagekm = maxdis/float (fuel);
    mileagemile = mileagekm*0.621;

    //Showing output on the terminal
    cout<<"The mileage of the car is "<<mileagekm<<"km/l or"<<mileagemile<<"mile/l"<<endl;

}