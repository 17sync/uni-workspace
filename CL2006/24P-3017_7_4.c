#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define PARTICIPANTS 10

pthread_mutex_t reg = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t ann = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t spn = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t qry = PTHREAD_MUTEX_INITIALIZER;

void* participant(void* arg) {
    int id = *(int*)arg;

    pthread_mutex_lock(&reg);
    printf("Participant %d: Registration done\n", id);
    pthread_mutex_unlock(&reg);

    pthread_mutex_lock(&ann);
    printf("Participant %d: Announcement received\n", id);
    pthread_mutex_unlock(&ann);

    pthread_mutex_lock(&spn);
    printf("Participant %d: Sponsor interaction\n", id);
    pthread_mutex_unlock(&spn);

    pthread_mutex_lock(&qry);
    printf("Participant %d: Query resolved\n", id);
    pthread_mutex_unlock(&qry);

    return NULL;
}

int main() {
    pthread_t t[PARTICIPANTS];
    int ids[PARTICIPANTS];

    for (int i = 0; i < PARTICIPANTS; i++) {
        ids[i] = i + 1;
        pthread_create(&t[i], NULL, participant, &ids[i]);
    }

    for (int i = 0; i < PARTICIPANTS; i++)
        pthread_join(t[i], NULL);

    return 0;
}