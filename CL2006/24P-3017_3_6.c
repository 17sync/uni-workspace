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
        printf("child ppid: %d\n", getppid());
        sleep(2);
        printf("child now orphan\n");
        printf("child new ppid: %d\n", getppid());
    }
    else{
        printf("parent exiting\n");
        exit(0);
    }

    return 0;
}
