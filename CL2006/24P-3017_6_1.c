#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    key_t key=1234;
    int shmid;
    char *data;

    shmid=shmget(key, 1024, 0666 | IPC_CREAT);
    if(shmid<0){
        perror("shmget");
        exit(1);
    }

    data=(char*)shmat(shmid, NULL, 0);
    if(data==(char*)-1){
        perror("shmat");
        exit(1);
    }

    strcpy(data, "Hello from Parent");

    pid_t pid=fork();

    if(pid==0){
        char *child_data=(char*)shmat(shmid, NULL, 0);
        printf("Child read: %s\n", child_data);
        shmdt(child_data);
    }
    else{
        wait(NULL);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}