#include <iostream>
using namespace std;

int main ()
{

    //Declaration of variables storing information given in the question
    int cX = 10; 
    int cY = 20;
    int fsX = 6; 
    int fsY = 8;
    int vX = 8; 
    int vY = 12;
    int budget = 140;
    int fs = 72;

    //Declaration of variables storing the best combination of X and Y
    int bestV=0;
    int bestX=0;
    int bestY=0;

    //Calculating the best combination of X and Y
    for (int i = 0; i<=14; ++i){
        for (int j=0; j<=7; ++j){
            int cost = i * cX + j * cY;
            int reqfs = i * fsX + j * fsY;

            if (reqfs <= fs && cost <= budget){
                int Volume = i * vX + j * vY;
                if (Volume > bestV) {
                    bestV = Volume;
                    bestX = i;
                    bestY = j;
                }
            }
        }
    }

    //Displaying the best combination
    cout<<"X: "<<bestX<< " Y: "<<bestY<<endl;
    cout<<"Storage space available: "<<bestV<<" ft^2";

}