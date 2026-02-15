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
        printf("child exiting with code 5\n");
        exit(5);
    }
    else{
        int status;
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("child exited with code %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
