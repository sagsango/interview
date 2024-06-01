#include <pthread.h>
#include <stdio.h>

#define THREADS 10


void * thread_function (void *arg) {
	printf("Hello Chicago: %p\n", pthread_self());
	pthread_exit(0);
}

int main () 
{
	pthread_t thread_id[THREADS];
	for (int i=0; i<THREADS; ++i) {
		pthread_create(&thread_id[i], NULL, &thread_function, NULL);
	}
	for (int i=0; i<THREADS; ++i) {
		pthread_join(thread_id[i], NULL);
	}
}
