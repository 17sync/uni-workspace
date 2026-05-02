#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("\nSIGQUIT caught! (Ctrl+\\ pressed)\n");
}

int main() {
    printf("Custom SIGQUIT active for 5 seconds\n");
    signal(SIGQUIT, handler);

    sleep(5);

    printf("Restoring default SIGQUIT behavior\n");
    signal(SIGQUIT, SIG_DFL);

    printf("Press Ctrl+\\ now to terminate\n");
    sleep(5);

    printf("Exiting normally\n");
    return 0;
}