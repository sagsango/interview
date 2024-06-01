#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

pthread_cond_t not_empty;
pthread_cond_t not_full;

pthread_mutex_t lock;
pthread_barrier_t barrier;


int gvar;


#define FULL(size) (size == 10)
#define EMPTY(size) (size == 0)

#define ITERATIONS 1000000
#define PRODUCERS 20
#define CONSUMERS 20

void * producer_func (void * arg) {
	int broadcast_consumers;
	struct timespec ts;

	pthread_barrier_wait (&barrier);

	for (int i=0; i<ITERATIONS; ++i)  {
		pthread_mutex_lock (&lock);
		while (FULL(gvar)) {
			clock_gettime(CLOCK_REALTIME, &ts);
               		ts.tv_sec += 5;
			pthread_cond_timedwait (&not_full, &lock, &ts);
		}
		broadcast_consumers = EMPTY(gvar);
		gvar += 1;
		if (broadcast_consumers) {
			pthread_cond_broadcast (&not_empty);
		}
		pthread_mutex_unlock (&lock);
	}
}

void * consumer_func (void *arg) {
	int broadcast_producers;
	struct timespec ts;

	pthread_barrier_wait (&barrier);

	for (int i=0; i<ITERATIONS; ++i) {
		pthread_mutex_lock (&lock);
		while (EMPTY(gvar)) {
			clock_gettime(CLOCK_REALTIME, &ts);
               		ts.tv_sec += 5;
			pthread_cond_timedwait (&not_empty, &lock, &ts);
		}
		broadcast_producers = FULL(gvar);
		gvar -= 1;
		if (broadcast_producers) {
			pthread_cond_broadcast (&not_full);
		}
		pthread_mutex_unlock (&lock);
	}
}


int main () {
	pthread_t producer[PRODUCERS];
	pthread_t consumer[CONSUMERS];

	pthread_cond_init (&not_full, NULL);
	pthread_cond_init (&not_empty, NULL);
	pthread_mutex_init (&lock, NULL);
	pthread_barrier_init (&barrier, NULL, (PRODUCERS + CONSUMERS));

	for (int i=0; i<PRODUCERS; ++i) {
		pthread_create (&producer[i], NULL, &producer_func, NULL);
	}

	for (int i=0; i<CONSUMERS; ++i) {
		pthread_create (&consumer[i], NULL, &consumer_func, NULL);
	}

	for (int i=0; i<PRODUCERS; ++i) {
		pthread_join (producer[i], NULL);
	}

	for (int i=0; i<CONSUMERS; ++i) {
		pthread_join (consumer[i], NULL);
	}

	pthread_cond_destroy (&not_full);
	pthread_cond_destroy (&not_empty);
	pthread_mutex_destroy (&lock);
	pthread_barrier_destroy (&barrier);

	assert (gvar == 0);
}
