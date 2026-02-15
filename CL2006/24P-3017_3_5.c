#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int id = fork();
    
    if (id < 0){
        printf("fork failed\n");
    }
    else if (id == 0){
        printf("child exiting\n");
        exit(0);
    }
    else{
        printf("parent running\n");
        printf("parent pid: %d\n", getpid());
        printf("child pid: %d\n", id);
        while (1)
        {
            sleep(1);
        }
    }

    return 0;
}
