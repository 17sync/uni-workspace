#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
    int shmid;
    key_t key=111;
    int *a;

    shmid=shmget(key, sizeof(int), 0666 | IPC_CREAT);
    a=(int*)shmat(shmid, NULL, 0);
    *a=0;

    printf("A initialized: %d\n", *a);

    while(1);
}