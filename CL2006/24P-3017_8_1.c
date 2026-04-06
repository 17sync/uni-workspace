#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int NUM_CUSTOMERS= 10;

sem_t sem_weigh;
sem_t sem_security;
sem_t sem_board;

void* customer(void* arg) {
    int id=(int)(long)arg;


    sem_wait(&sem_weigh);
    printf("Customer %d is weighting the luggage\n",id);
    sleep(4);

    printf("Customer %d done weighting\n",id);
    sem_post(&sem_weigh);
    sem_wait(&sem_security);

    printf("Customer %d is at security check\n",id);
    sleep(7);

    printf("Customer %d passed security\n",id);
    sem_post(&sem_security);
    sem_wait(&sem_board);


    printf("Customer %d is getting boarding pass\n",id);
    sleep(3);

    printf("Customer %d got boarding pass\n",id);
    sem_post(&sem_board);

    return NULL;
}

int main() {
    pthread_t customers[NUM_CUSTOMERS];

    sem_init(&sem_weigh, 0, 1);
    sem_init(&sem_security, 0, 1);
    sem_init(&sem_board, 0, 1);

    for (long i=0; i<NUM_CUSTOMERS; i++) {

        pthread_create(&customers[i], NULL, customer, (void*)i);
    }

    for (int i=0; i<NUM_CUSTOMERS; i++) {

        pthread_join(customers[i], NULL);

    }

    sem_destroy(&sem_weigh);    
    sem_destroy(&sem_security);
    sem_destroy(&sem_board);

    return 0;
}
