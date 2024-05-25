OBJS=pthread_create pthread_join pthread_detach pthread_mutex pthread_spinlock pthread_cond pthread_barrier

all:$(OBJS)

pthread_create: pthread_create.c
	gcc -o pthread_create pthread_create.c -lpthread

pthread_join: pthread_join.c
	gcc -o pthread_join pthread_join.c -lpthread

pthread_detach: pthread_detach.c
	gcc -o pthread_detach pthread_detach.c -lpthread

pthread_mutex: pthread_mutex.c
	gcc -o pthread_mutex pthread_mutex.c -lpthread

pthread_spinlock: pthread_spinlock.c
	gcc -o pthread_spinlock pthread_spinlock.c -lpthread

pthread_cond: pthread_cond.c
	gcc -o pthread_cond pthread_cond.c -lpthread

pthread_barrier: pthread_cond.c
	gcc -o pthread_barrier pthread_cond.c -lpthread

clean:
	rm -rf $(OBJS)
