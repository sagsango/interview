#include <pthread.h>
#include <stdio.h>

#define THREADS 10

void * thread_func(void *arg) 
{
	printf("Hello Chicago:%p\n", pthread_self());
	pthread_exit(0);
}

int main() 
{
	pthread_t tid[THREADS];
	for (int i=0; i<THREADS; ++i) {
		pthread_create(&tid[i], NULL, &thread_func, NULL);
	}
	for (int i=0; i<THREADS; ++i) {
		pthread_join(tid[i], NULL);
	}
	
}
