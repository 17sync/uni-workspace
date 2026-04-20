#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
    int shmid;
    key_t key=222;
    int *b;

    shmid=shmget(key, sizeof(int), 0666 | IPC_CREAT);
    b=(int*)shmat(shmid, NULL, 0);
    *b=1;

    printf("B initialized: %d\n", *b);

    while(1);
}