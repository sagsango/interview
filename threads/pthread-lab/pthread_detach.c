#include <unistd.h>
#include <stdio.h>

#include <stdlib.h>
#include <pthread.h>

#define THREADS 10

void * thread_func (void *arg) 
{
	int sum = 0;
	for (int i=0; i<1000; ++i) {
		sum += i & *((long *)(arg));
	}
	printf("id<%p> sum<%d>\n", pthread_self(), sum);
	pthread_exit(0);
}

int main() 
{
	int status;
	pthread_t tid[THREADS];
	for (int i=0; i<THREADS; ++i) {
		status = pthread_create (&tid[i], NULL, &thread_func, &i);
		if (status != 0) {
			exit(1);
		}
		status = pthread_detach(tid[i]);
		if (status != 0) {
			exit(1);
		}
	}
	printf("main thread<%p> exiting\n", getpid());
}
