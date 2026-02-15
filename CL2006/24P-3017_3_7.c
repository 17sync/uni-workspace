#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    printf("press e to quit\n");
    
    while (1){
        printf("cmd: ");
        scanf("%s", command);

        if (strcmp(command, "e") == 0){
            exit(0);
        }

        int id = fork();
        if (id < 0){
            printf("fork failed\n");
        }
        else if (id == 0){
            execlp(command, command, NULL);
            printf("exec failed\n");
            exit(1);
        }
        else{
            wait(NULL);
        }
    }
    
    return 0;
}
