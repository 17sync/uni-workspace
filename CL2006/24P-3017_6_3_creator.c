#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

int main(){
    key_t key=1234;
    int shmid;
    char *data;
    int num;

    shmid=shmget(key, 1024, 0666 | IPC_CREAT);
    data=(char*)shmat(shmid, NULL, 0);

    printf("Enter number: ");
    scanf("%d", &num);

    sprintf(data, "%d", num);

    sleep(1);
    strcpy(data, "ready");

    while(1){
        if(data[0]!='*' && strcmp(data, "ready")!=0){
            printf("Value: %s\n", data);
            strcpy(data, "*");
        }
        sleep(1);
    }

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}