#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>   

void* threadFunction(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d is running...\n", id);

    Sleep(500); 

    printf("Thread %d finished work.\n", id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int threadIDs[3] = {1, 2, 3};

    printf("Creating threads...\n");

    
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, threadFunction, &threadIDs[i]) != 0) {
            printf("Error creating thread %d\n", i+1);
            return 1;
        }
    }

   
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");

    return 0;
}

