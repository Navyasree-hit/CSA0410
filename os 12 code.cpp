#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 5   

pthread_mutex_t chopstick[NUM];


void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        
        pthread_mutex_lock(&chopstick[id]);
        printf("Philosopher %d picked LEFT chopstick.\n", id);

       
        pthread_mutex_lock(&chopstick[(id + 1) % NUM]);
        printf("Philosopher %d picked RIGHT chopstick.\n", id);

        // Eating
        printf("Philosopher %d is EATING...\n", id);
        sleep(2);

        
        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id + 1) % NUM]);

        printf("Philosopher %d finished eating and put down chopsticks.\n", id);

        sleep(1);
    }
}

int main() {
    pthread_t thread[NUM];
    int ids[NUM];

    
    for (int i = 0; i < NUM; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    
    for (int i = 0; i < NUM; i++) {
        ids[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &ids[i]);
    }

  
    for (int i = 0; i < NUM; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}

