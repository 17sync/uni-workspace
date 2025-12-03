#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of variables storing number of players available, number of teams, coach's preference and leftover players
    int nopa, teams; 
    int coachp, leftovers;

    //Asking for input for number of players available and coach's preference
    cout<<"How many players do you want per team? ";
    cin>>coachp;
    
    while (coachp < 9 || coachp > 15)       //Defining upper and lower limit for number of players per team and implementing a check on it
    {
        if (coachp < 9)
        {
            cout<<"\nERROR --> You must have atleast 9 players per team";
            cout<<"\n\nHow many players do you want per team? ";
            cin>>coachp;
        }
        else if (coachp > 15)
        {
            cout<<"\nERROR --> You may have a maximum of 15 players per team";
            cout<<"\n\nHow many players do you want per team? ";
            cin>>coachp;
        }
    }
    
    cout<<"How many players are available? ";
    cin>>nopa;
    
    //Defining number of teams and leftover players
    teams = nopa/coachp;
    leftovers = nopa%coachp;

    //Displaying number of teams and leftover players
    cout<<"\nThere will be "<<teams<<" teams with "<<leftovers<<" players left over."; 

}