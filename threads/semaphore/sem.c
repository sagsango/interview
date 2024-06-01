#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2

sem_t semaphore;

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;

    sem_wait(&semaphore); // Try to acquire the semaphore

    printf("Thread %d is in the critical section\n", thread_id);

    // Simulating some work in the critical section
    for(int i = 0; i < 5; i++){
        printf("Thread %d is working\n", thread_id);
    }

    printf("Thread %d is leaving the critical section\n", thread_id);

    sem_post(&semaphore); // Release the semaphore

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {1, 2};

    sem_init(&semaphore, 0, 1); // Initializing binary semaphore

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); // Destroying the semaphore

    return 0;
}
