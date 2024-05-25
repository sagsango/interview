#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#define ITERATIONS 2000000
#define THREADS 10

pthread_mutex_t mutex;
int gvar = 0;

void * thread_func (void * arg)
{
	for (int i=0; i<ITERATIONS; ++i) {
		pthread_mutex_lock (&mutex);
		gvar += 1;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit (0);
}


int main() 
{
	pthread_t thread[THREADS];

	pthread_mutex_init (&mutex, NULL);

	for (int i=0; i<THREADS; ++i) {
		pthread_create (&thread[i], NULL, &thread_func, NULL);
	}
	
	for (int i=0; i<THREADS; ++i) {
		pthread_join (thread[i], NULL);
	}

	pthread_mutex_destroy (&mutex);

	assert (gvar == THREADS * ITERATIONS);	
}
