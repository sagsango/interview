CC = gcc
CFLAGS = -lpthread
TARGETS = shared_mutex use_shared_mutex

.PHONY: all clean run

all: $(TARGETS)

shared_mutex: shared_mutex.c
	$(CC) -o shared_mutex shared_mutex.c $(CFLAGS)

use_shared_mutex: use_shared_mutex.c
	$(CC) -o use_shared_mutex use_shared_mutex.c $(CFLAGS)

clean:
	rm -f $(TARGETS) *.o

run: all
	./shared_mutex &
	sleep 1
	./use_shared_mutex

