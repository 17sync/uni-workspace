#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* worker(void* arg) {
    printf("Hello from thread ID: %lu\n", pthread_self());
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    pthread_t t[N];

    for (int i = 0; i < N; i++) {
        pthread_create(&t[i], NULL, worker, NULL);

        if ((i+1) % 5 == 0) {
            sleep(1);  
        }
    }

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    return 0;
}