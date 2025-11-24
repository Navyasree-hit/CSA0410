#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int mutex = 1;        
int writeBlock = 1;  
int readCount = 0;    


void wait(int *s) {
    while (*s <= 0); 
    (*s)--;
}


void signal(int *s) {
    (*s)++;
}


void reader(int id) {
    wait(&mutex);
    readCount++;

    if (readCount == 1)
        wait(&writeBlock); 

    signal(&mutex);

    printf("\nReader %d is READING...", id);
    Sleep(500);

    wait(&mutex);
    readCount--;

    if (readCount == 0)
        signal(&writeBlock); 

    signal(&mutex);

    printf("\nReader %d has FINISHED reading.", id);
}


void writer(int id) {
    wait(&writeBlock);  

    printf("\nWriter %d is WRITING...", id);
    Sleep(500);

    signal(&writeBlock);

    printf("\nWriter %d has FINISHED writing.", id);
}


int main() {
    int choice, r = 1, w = 1;

    while (1) {
        printf("\n\n--- Reader-Writer Problem Simulation ---");
        printf("\n1. Reader");
        printf("\n2. Writer");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            reader(r++);
            break;

        case 2:
            writer(w++);
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}

