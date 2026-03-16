#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

int main(){
    key_t key=1234;
    int shmid;
    char *data;
    int num, i=1, val;

    shmid=shmget(key, 1024, 0666);
    data=(char*)shmat(shmid,NULL,0);

    while(strcmp(data, "ready")!=0) sleep(1);

    printf("Enter the number again: ");
    scanf("%d", &num);

    while(i<=10){
        if(strcmp(data, "*")==0){
            val=num*i;
            sprintf(data, "%d", val);
            i++;
        }
        sleep(1);
    }
    shmdt(data);
    
    return 0;
}