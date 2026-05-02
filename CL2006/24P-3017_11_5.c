#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Signals active (Ctrl+C / kill works)\n");
    sleep(5);

    printf("Entering protected mode (signals ignored)\n");
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    sleep(5);

    printf("Restoring normal signal behavior\n");
    signal(SIGINT, SIG_DFL);
    signal(SIGTERM, SIG_DFL);

    sleep(5);

    printf("Program ending normally\n");
    return 0;
}