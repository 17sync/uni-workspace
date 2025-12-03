#include <iostream>
using namespace std;
#define N 5

void displaySol(int solution[N][N]){
 for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        cout<<solution[i][j]<<" ";
    }
    cout<<endl;
 }
}

bool checkSafety(int maze[N][N], int x, int y){
 return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}

bool mazeUtil(int maze[N][N], int x, int y, int solution[N][N]){
 if(x==N-1 && y==N-1){
    solution[x][y] = 1;
    return true;
 }
 if(checkSafety(maze, x, y)){
    solution[x][y] = 1;
 
    if(mazeUtil(maze, x, y+1, solution)) return true;
    if(mazeUtil(maze, x+1, y, solution)) return true;
 
    solution[x][y] = 0;
    return false;
 }

 return false;
}

void solMaze(int maze[N][N]){
 int solution[N][N] = {0};
 if(mazeUtil(maze, 0, 0, solution)){
    cout<<"Path to reach the meat:\n";
    displaySol(solution);
 }
 else{
    cout<<"No path found!";
 }
}
int main(){
 cout<<"24P-3017\n"<<endl;

 int maze[N][N]={
 {1, 0, 1, 1, 1},
 {1, 0, 1, 0, 1},
 {1, 1, 1, 0, 1},
 {0, 0, 0, 0, 1},
 {1, 1, 1, 1, 1}
 };
 
 displaySol(maze);
 solMaze(maze);
}