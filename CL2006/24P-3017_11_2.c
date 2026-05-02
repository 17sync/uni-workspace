#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>

#define N 5

int arr[N] = {1,2,3,4,5};
int sum = 0;
sem_t sem;

volatile sig_atomic_t done = 0;

void handler(int sig) {
    done = 1;
}

void* worker(void* arg) {
    int i = *(int*)arg;

    sem_wait(&sem);

    printf("Thread %d in critical section\n", i);

    signal(SIGALRM, handler);
    done = 0;
    alarm(5);

    while (!done);
    sum += arr[i];

    printf("Thread %d leaving CS\n", i);

    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t t[N];
    int idx[N];

    sem_init(&sem, 0, 1);

    for (int i = 0; i < N; i++) {
        idx[i] = i;
        pthread_create(&t[i], NULL, worker, &idx[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("Final Sum = %d\n", sum);

    sem_destroy(&sem);
    return 0;
}