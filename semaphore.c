#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t mutex,wrt;
pthread_t tid;
int sharedvar = 99;
pthread_t writers[5], readers[5];
int readercount = 0;

void *reader(void* param) {
	sem_wait(&mutex);
	readercount++;
	if(readercount == 1)
		sem_wait(&wrt);
	sem_post(&mutex);

	printf("\n%d reader is reading sharedvar = %d", readercount, sharedvar);

	usleep(500000);
	sem_wait(&mutex);
	readercount--;
	if(readercount == 0)
		sem_post(&wrt);
	sem_post(&mutex);

	printf("\n%d reader is done", readercount + 1);
}

void *writer(void* param) {
	printf("\nwriter is trying to enter");
	sem_wait(&wrt);
	printf("\nwriter has entered cs");
	sharedvar++;
	printf("\nwriter changed the value of shared var to %d", sharedvar);
	sem_post(&wrt);
	printf("\nwriter is out of cs\n");
}

int main() {
	int n2,i;
	printf("Enter the number of readers:");
	scanf("%d",&n2);
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	for(i = 0; i < n2; i++) {
		pthread_create(&writers[i], NULL, writer, NULL);
		pthread_create(&readers[i], NULL, reader, NULL);
	}
	for(i = 0; i < n2; i++) {
		pthread_join(writers[i], NULL);
		pthread_join(readers[i], NULL);
	}
}
