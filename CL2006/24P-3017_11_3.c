#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("\nSIGTSTP received after unblock (Ctrl+Z handled)\n");
}

int main() {
    signal(SIGTSTP, handler);

    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGTSTP);

    printf("Blocking Ctrl+Z for 5 seconds...\n");
    sigprocmask(SIG_BLOCK, &set, NULL);

    sleep(5);

    printf("Unblocking Ctrl+Z now\n");
    sigprocmask(SIG_UNBLOCK, &set, NULL);

    while (1) pause();

    return 0;
}