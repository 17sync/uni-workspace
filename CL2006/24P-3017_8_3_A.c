#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define PERSONS 3

sem_t sem;
int icecreamremaining=15;

void* eat(void* arg){
    int id=(int)(long)arg;

    while(1){
        sem_wait(&sem);
        if (icecreamremaining<=0){
            sem_post(&sem);
            break;
        }

        icecreamremaining--;
        printf("Person %d got a cone. Icecreams left: %d\n", id, icecreamremaining);

        sem_post(&sem);
        sleep(1);
    }

    printf("Person %d is done eating.\n", id);
    return NULL;
}

int main(){
    pthread_t persons[PERSONS];

    sem_init(&sem, 0, 1);
    for(long i=0; i<PERSONS; i++){
        pthread_create(&persons[i], NULL, eat, (void*)i);
    }
    for(int i=0; i<PERSONS; i++){
        pthread_join(persons[i], NULL);
    }

    sem_destroy(&sem);
    printf("Contest over. Icecreams remaining: %d\n", icecreamremaining);
    return 0;
}