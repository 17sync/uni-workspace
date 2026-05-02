#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* threadFunc(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d started\n", id);

    int *ret = malloc(sizeof(int));
    *ret = id * 10;   // return value

    pthread_exit(ret);
}

int main() {
    pthread_t t[3];
    int ids[3] = {1,2,3};

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&t[i], NULL, threadFunc, &ids[i]) != 0) {
            printf("Error\n");
        }
    }

    for (int i = 0; i < 3; i++) {
        int *ret;
        pthread_join(t[i], (void**)&ret);
        printf("Thread %d returned %d\n", i+1, *ret);
        free(ret);
    }

    return 0;
}