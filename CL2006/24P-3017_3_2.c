#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int y = 20;

int main(){

    int x = 0;

    printf("before fork\n");

    int id = fork();

    printf("after fork\n");

    if (id < 0) {

        printf("fork failed\n");

    } 
    else if(id==0){
        x = 3;
        y = y + 2;

        printf("child pid: %d\n", getpid());
        printf("parent pid: %d\n", getppid());
        printf("child x: %d, y: %d\n", x, y);
    } 
    else{
        x = 5;

        printf("parent pid: %d\n", getpid());
        printf("child pid: %d\n", id);
        printf("parent x: %d, y: %d\n", x, y);
    }

    return 0;
}
