#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_data = 0;          
pthread_mutex_t lock;         

void* thread_function(void* arg)
{
    pthread_mutex_lock(&lock);   

    printf("Thread %d entered critical section.\n", *(int*)arg);

    int temp = shared_data;
    temp++;
    sleep(1);                   
    shared_data = temp;

    printf("Thread %d leaving critical section. Updated Value = %d\n",
           *(int*)arg, shared_data);

    pthread_mutex_unlock(&lock);  

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, thread_function, &id1);
    pthread_create(&t2, NULL, thread_function, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("\nFinal Shared Data Value = %d\n", shared_data);

    return 0;
}

