#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#define ITERATIONS 100000
#define THREADS 10

pthread_spinlock_t lock;
int gvar;

void * thread_func (void * var) 
{
	for (int i=0; i<ITERATIONS; ++i) {
		pthread_spin_lock(&lock);
		gvar += 1;
		pthread_spin_unlock(&lock);
	}
	pthread_exit(0);
}

int main () 
{
	pthread_t thread[THREADS];
	
	pthread_spin_init (&lock, 0 & PTHREAD_PROCESS_PRIVATE); /* See the man page for spin_lock betwen process */
	
	for (int i=0; i<THREADS; ++i) {
		pthread_create (&thread[i], NULL, &thread_func, NULL);
	}

	for (int i=0; i<THREADS; ++i) {
		pthread_join (thread[i], NULL);
	}
	
	pthread_spin_destroy (&lock);

	assert (gvar == ITERATIONS * THREADS);
}
