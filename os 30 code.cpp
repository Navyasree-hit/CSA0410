#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Thread function
void* myThread(void* arg) {
    printf("Inside thread. Thread ID = %lu\n", pthread_self());

    // (iv) pthread_exit
    pthread_exit("Thread exiting...");
}

int main() {
    pthread_t t1, t2;
    void* exitStatus;

    // (i) pthread_create - create two threads
    if (pthread_create(&t1, NULL, myThread, NULL) != 0) {
        printf("Error creating thread t1\n");
        return 1;
    }

    if (pthread_create(&t2, NULL, myThread, NULL) != 0) {
        printf("Error creating thread t2\n");
        return 1;
    }

    // (iii) pthread_equal - check if t1 and t2 are same thread
    if (pthread_equal(t1, t2))
        printf("t1 and t2 are equal (same thread)\n");
    else
        printf("t1 and t2 are NOT equal (different threads)\n");

    // (ii) pthread_join - wait for both threads
    pthread_join(t1, &exitStatus);
    printf("Thread t1 exit message: %s\n", (char*)exitStatus);

    pthread_join(t2, &exitStatus);
    printf("Thread t2 exit message: %s\n", (char*)exitStatus);

    printf("Main thread finished.\n");

    return 0;
}

