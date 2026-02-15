#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int id = fork();
    
    if (id < 0){
        printf("fork failed\n");
    }
    else if (id == 0){
        printf("child sleeping 5s\n");
        sleep(5);
        printf("child awake, exiting\n");
        exit(0);
    }
    else{
        wait(NULL);
        printf("parent waited, exiting\n");
    }
    return 0;
}
