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

// Function to initialize shared memory and the process-shared mutex
void initialize_shared_mutex(pthread_mutex_t **mutex) {
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Resize the shared memory object
    if (ftruncate(shm_fd, SHM_SIZE) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object
    void *shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    *mutex = (pthread_mutex_t *)shm_ptr;

    // Initialize the mutex attribute
    pthread_mutexattr_t attr;
    if (pthread_mutexattr_init(&attr) != 0) {
        perror("pthread_mutexattr_init");
        exit(EXIT_FAILURE);
    }

    // Set the mutex attribute to process-shared
    if (pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED) != 0) {
        perror("pthread_mutexattr_setpshared");
        exit(EXIT_FAILURE);
    }

    // Initialize the mutex with the attribute
    if (pthread_mutex_init(*mutex, &attr) != 0) {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }

    // Destroy the attribute object as it is no longer needed
    pthread_mutexattr_destroy(&attr);

    // Close the shared memory file descriptor
    close(shm_fd);
}

int main() {
    pthread_mutex_t *mutex;

    initialize_shared_mutex(&mutex);

    printf("Mutex initialized and stored in shared memory.\n");

    // Lock the mutex
    if (pthread_mutex_lock(mutex) != 0) {
        perror("pthread_mutex_lock");
        exit(EXIT_FAILURE);
    }

    // Critical section
    printf("In the critical section.\n");

    // Unlock the mutex
    if (pthread_mutex_unlock(mutex) != 0) {
        perror("pthread_mutex_unlock");
        exit(EXIT_FAILURE);
    }

    printf("Mutex unlocked.\n");

    return 0;
}

