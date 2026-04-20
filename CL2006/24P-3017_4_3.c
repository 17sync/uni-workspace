#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int pipefd[2];
    pid_t pid;
    char *words[]={"level\n", "kayak\n", "racecar\n", "hello\n", "world\n"};
    char buffer[100];

    pipe(pipefd);
    pid=fork();
  
    if(pid>0){
        close(pipefd[0]);

        for(int i=0;i<5;i++){
            write(pipefd[1], words[i], strlen(words[i]));
        }

        close(pipefd[1]);
        wait(NULL);
    } 
    else{
        close(pipefd[1]);

        ssize_t bytes;
        while((bytes = read(pipefd[0], buffer, sizeof(buffer))) > 0){
            write(STDOUT_FILENO, buffer, bytes);
        }

        close(pipefd[0]);
    }

    return 0;
}

