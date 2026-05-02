#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig1(int sig) {
    printf("Child: Received SIGUSR1 (Message 1)\n");
}

void sig2(int sig) {
    printf("Child: Received SIGUSR2 (Message 2)\n");
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGUSR1, sig1);
        signal(SIGUSR2, sig2);

        printf("Child waiting for signals...\n");

        while (1) pause();
    } else {
        sleep(2);

        printf("Parent sending SIGUSR1\n");
        kill(pid, SIGUSR1);

        sleep(2);

        printf("Parent sending SIGUSR2\n");
        kill(pid, SIGUSR2);
    }

    return 0;
}