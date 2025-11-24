#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;


int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;

HANDLE producerThread, consumerThread;


void wait(int *s) {
    while (*s <= 0);  
    (*s)--;
}


void signal(int *s) {
    (*s)++;
}

DWORD WINAPI producer(LPVOID param) {
    int item = 1;
    while (1) {
        wait(&empty);   
        wait(&mutex);   

        buffer[in] = item;
        printf("Producer produced: %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item++;

        signal(&mutex); 
        signal(&full);  

        Sleep(500);
    }
}

DWORD WINAPI consumer(LPVOID param) {

    while (1) {
        wait(&full);    
        wait(&mutex);   

        int item = buffer[out];
        printf("Consumer consumed: %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        signal(&mutex); 
        signal(&empty); 

        Sleep(700);
    }
}

int main() {

    printf("Producer-Consumer Problem Simulation Using Semaphores (Dev-C++)\n\n");

    producerThread = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    consumerThread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    WaitForSingleObject(producerThread, INFINITE);
    WaitForSingleObject(consumerThread, INFINITE);

    return 0;
}

