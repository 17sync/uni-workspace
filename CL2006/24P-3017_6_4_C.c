#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
    int shmidA, shmidB;
    key_t keyA=111,keyB=222;
    int *a, *b, sum, n, i;

    printf("Enter n: ");
    scanf("%d",&n);

    shmidA=shmget(keyA, sizeof(int), 0666);
    shmidB=shmget(keyB, sizeof(int), 0666);

    a=(int*)shmat(shmidA, NULL, 0);
    b=(int*)shmat(shmidB, NULL, 0);

    printf("%d %d ", *a, *b);

    for(i=0;i<n;i++){
        sum=*a+*b;
        printf("%d ", sum);

        *a=*b;
        *b=sum;
    }
    printf("\n");
    
    return 0;
}