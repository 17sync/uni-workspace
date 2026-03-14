#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

#define BUFFER_SIZE 100

void to_uppercase(char *str){
    for(int i=0;str[i];i++)
        str[i]=toupper(str[i]);
}

int main(){
    int pipe1[2], pipe2[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    pipe(pipe1);
    pipe(pipe2);

    pid=fork();

    if(pid>0){
        close(pipe1[0]);
        close(pipe2[1]);

        while(1){
            printf("Enter order on counter: ");
            fgets(buffer, BUFFER_SIZE, stdin);

            write(pipe1[1], buffer, strlen(buffer));

            if(strncmp(buffer, "exit", 4)==0) break;

            read(pipe2[0], buffer, BUFFER_SIZE);
            printf("Kitchen says: %s", buffer);
        }

        close(pipe1[1]);
        close(pipe2[0]);
        waitpid(pid, NULL, 0);
        printf("Session ended.\n");

    } 
    else{
        close(pipe1[1]);
        close(pipe2[0]);

        while(1){
            ssize_t byte=read(pipe1[0], buffer, BUFFER_SIZE);
            if(byte<=0) break;

            if(strncmp(buffer, "exit", 4)==0) break;

            sleep(1);
            to_uppercase(buffer);

            write(pipe2[1], buffer, strlen(buffer));
        }

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}

