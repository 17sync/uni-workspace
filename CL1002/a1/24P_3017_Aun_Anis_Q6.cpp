#include <iostream>
using namespace std;

int main ()
{
    
    //Displaying subject of program
    cout<<"\tEarthquake Magnitude Categorizer\n\t--------------------------------";

    //Declaration of magnitude
    float mag;

    start:
    //Asking for magnitude from user
    cout<<"\nEnter magnitude of the earthquake: "; cin>>mag;

    //Categorizing magntiude
    if (mag>=0 && mag<2)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Micro earthquake.";
    }
    else if (mag>=2 && mag<3)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Very Minor earthquake.";
    }
    else if (mag>=3 && mag<4)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Minor earthquake.";
    }
    else if (mag>=4 && mag<5)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Light earthquake.";
    }
    else if (mag>=5 && mag<6)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Moderate earthquake.";
    }
    else if (mag>=6 && mag<7)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Strong earthquake.";
    }
    else if (mag>=7 && mag<8)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Major earthquake.";
    }
    else if (mag>=8 && mag<10)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Great earthquake.";
    }
    else if (mag>=10)
    {
        cout<<"By convention an earthquake of magnitude "<<mag<<" is considered to be a Meteoric earthquake.";
    }
    else
    {
        cout<<"Invalid magnitude";
    }

    //Asking for reset
    int reset;
    cout<<"\n\nDo you want to know the category of another magnitude? (press 1 for yes or 0 for no) "; cin>>reset;
    if (reset == 1)
    {
        goto start;
    }
}