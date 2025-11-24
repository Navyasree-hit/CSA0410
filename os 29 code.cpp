/*
 * C Program to demonstrate the use of pthread_create().
 * This program creates a new thread and the new thread prints a message.
 *
 * Compilation Note for Dev-C++ / MinGW:
 * You must compile with the -lpthread flag:
 * gcc pthread_create_demo.c -o create_demo -lpthread
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep()

// Function that will be executed by the new thread
void* thread_function(void* arg) {
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());
    printf("-> New thread created successfully and is now running.\n");
    // Simulate some work
    sleep(2);
    printf("-> New thread is finishing its execution.\n");
    return NULL;
}

int main() {
    pthread_t thread_id; // Variable to hold the ID of the new thread
    int result;

    printf("Main thread ID: %lu\n", (unsigned long)pthread_self());
    printf("Main: Attempting to create a new thread...\n");

    // (i) Demonstrate pthread_create
    // Arguments: 1. Pointer to pthread_t variable (output)
    //            2. Thread attributes (NULL for default)
    //            3. Function pointer for the thread to execute
    //            4. Argument to pass to the thread function (NULL here)
    result = pthread_create(&thread_id, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Error creating thread");
        return 1;
    }

    printf("Main: Thread created successfully. ID is %lu\n", (unsigned long)thread_id);

    // Let the main thread wait a bit before exiting to allow the new thread to finish
    // A better practice is to use pthread_join, demonstrated in the next example.
    sleep(3);

    printf("Main: Program finished.\n");
    return 0;
}
