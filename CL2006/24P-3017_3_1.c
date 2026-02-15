#include <stdio.h>    
#include <sys/types.h> 
#include <unistd.h>   
#include <stdlib.h>

int main(){
    printf("before fork\n");

    int id = fork();
    printf("attempting to fork\n");

    if(id < 0){
        printf("failed\n");
    }
    else if(id ==0){
        printf("this is a child process and it's id is %d \n", getpid());
    }
    else{
        printf("this is a parent process and it's id is %d \n ", getpid());
    }

    return 0;
}