#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int Sellers =5;
const int Total_tickets =20;

sem_t sem;
int tickets = Total_tickets;

void* sell(void* arg) {
    int id=(int)(long)arg;

    while(1){
        sem_wait(&sem);

        if(tickets<=0){
            sem_post(&sem);
            break;
        }

        tickets--;
        printf("Seller %d sold a ticket. Remaining: %d\n", id, tickets);
        sleep(1);

        sem_post(&sem);
    }

    return NULL;
}

int main() {
    pthread_t sellers[Sellers];
    sem_init(&sem, 0, 1);

    for(long i=0; i<Sellers; i++){
        pthread_create(&sellers[i], NULL, sell, (void*)i);
    }
    for(int i=0; i<Sellers; i++){
        pthread_join(sellers[i], NULL);
    }

    sem_destroy(&sem);
    printf("All tickets sold. Final count: %d\n", tickets);

    return 0;
}