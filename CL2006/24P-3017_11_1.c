#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Ignoring SIGTSTP (Ctrl+Z) and SIGALRM\n");

    signal(SIGTSTP, SIG_IGN);
    signal(SIGALRM, SIG_IGN);
    alarm(5);

    while (1) {
        printf("Running... Press Ctrl+C to exit\n");
        sleep(1);
    }

    return 0;
}