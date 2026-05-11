#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

volatile sig_atomic_t flag = 0;     // volatile=could change unexpectedly, sig_atomic_t=integer type that can be accessed atomically

void handler(int sig) {
    flag = 1;
}

int main() {
    signal(SIGUSR1, handler);

    pid_t pid = fork();

    if(pid == 0) {
        sleep(2);

        printf("Child sending signal...\n");
        kill(getppid(), SIGUSR1);

        exit(0);
    }

    else {
        while(flag == 0);       // wait for custom handler to set flag

        printf("Signal received.\n");
        if(mkfifo("myfifo.txt", 0666) == -1) {
            perror("mkfifo");
        }
        else {
            printf("Named pipe created successfully.\n");
        }

        wait(NULL);

        if(unlink("myfifo.txt") == -1) {
            perror("unlink");
        }
    }

    return 0;
}