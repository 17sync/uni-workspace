#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("root 1 pid: %d ppid: %d\n", getpid(), getppid());
    
    int id = fork();

    if (id < 0) {
        printf("fork failed\n");
    } 
    else if (id == 0) {
        printf("node 3 pid: %d ppid: %d\n", getpid(), getppid());
    } 
    else {
        int id2 = fork();
        if (id2 == 0) {
            printf("node 2 pid: %d ppid: %d\n", getpid(), getppid());
            
            int id3 = fork();
            if (id3 == 0) {
                printf("node 6 pid: %d ppid: %d\n", getpid(), getppid());
            } 
            else {
                int id4 = fork();
                if (id4 == 0) {
                    printf("node 5 pid: %d ppid: %d\n", getpid(), getppid());
                }
            }
        } 
        else {
            int id5 = fork();
            if (id5 == 0) {
                printf("node 4 pid: %d ppid: %d\n", getpid(), getppid());
            }
        }
    }
    return 0;
}
