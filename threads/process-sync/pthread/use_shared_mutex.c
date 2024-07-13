#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define SHM_NAME "./my_shm"
#define SHM_SIZE sizeof(pthread_mutex_t)

int main() {
    int shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object
    void *shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_t *mutex = (pthread_mutex_t *)shm_ptr;

    // Lock the mutex
    if (pthread_mutex_lock(mutex) != 0) {
        perror("pthread_mutex_lock");
        exit(EXIT_FAILURE);
    }

    // Critical section
    printf("In the critical section of the second process.\n");

    // Unlock the mutex
    if (pthread_mutex_unlock(mutex) != 0) {
        perror("pthread_mutex_unlock");
        exit(EXIT_FAILURE);
    }

    printf("Mutex unlocked by the second process.\n");

    return 0;
}

