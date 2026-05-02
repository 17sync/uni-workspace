#include <stdio.h>
#include <pthread.h>

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int sum = 0;
pthread_mutex_t lock;

void* add(void* arg) {
    int i = *(int*)arg;

    pthread_mutex_lock(&lock);
    sum += arr[i];
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[10];
    int idx[10];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 10; i++) {
        idx[i] = i;
        pthread_create(&t[i], NULL, add, &idx[i]);
    }

    for (int i = 0; i < 10; i++)
        pthread_join(t[i], NULL);

    printf("Final Sum = %d\n", sum);

    pthread_mutex_destroy(&lock);
    return 0;
}