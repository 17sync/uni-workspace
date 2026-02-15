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
        printf("child running\n");
        printf("child pid: %d, ppid: %d\n", getpid(), getppid());
    }
    else{
        printf("parent sleeping 2s\n");
        sleep(2);
        printf("parent awake\n");
        printf("parent pid: %d, child pid: %d\n", getpid(), id);
    }
    
    return 0;
}
