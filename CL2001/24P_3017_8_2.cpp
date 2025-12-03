#include<iostream>
using namespace std;

void playGame(int secret, int player, int totalPlayers){
    int guess;
    cout<<"Player "<<player<<", enter your guess (1-100): ";
    cin>>guess;

    if(guess==secret){
        cout<<"🎉 Player "<<player<<" wins! The number was "<<secret<<"!\n";
        return; 
    }
    else if(guess<secret) cout<<"Too low!\n";
    else cout<<"Too high!\n";

    int nextPlayer=(player%totalPlayers)+1;
    playGame(secret, nextPlayer, totalPlayers);
}

int main(){
    cout<<"24P-3017\n"<<endl;

    srand(time(0));
    int secret=rand()%100+1; 
    int players;

    cout<<"Enter number of players: ";
    cin>>players;

    cout<<"Guess the number between 1 and 100!\n";
    playGame(secret, 1, players);
}
