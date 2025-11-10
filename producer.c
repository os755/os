#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define MAX_ITEM 5

int in = 0;
int out = 0;
int buffer[BUFFER_SIZE];

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void* args) {
    int item;
    int* thread_no = (int*) args;

    for (int i = 0; i < MAX_ITEM; i++) {
        item = rand() % 100; // limit item size for clarity

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer %d produced item %d\n", *thread_no, buffer[in]);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(1); // simulate delay
    }

    return NULL;
}

void* consumer(void* args) {
    int item;
    int* thread_no = (int*) args;

    for (int i = 0; i < MAX_ITEM; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer %d consumed item %d\n", *thread_no, item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1); // simulate delay
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t prod[5], cons[5];
    int arr[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&prod[i], NULL, producer, (void*)&arr[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&cons[i], NULL, consumer, (void*)&arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(prod[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(cons[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("\nAll producers and consumers finished.\n");
    return 0;
}