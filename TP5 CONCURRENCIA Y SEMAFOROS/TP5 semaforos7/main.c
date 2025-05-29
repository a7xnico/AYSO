#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t A,B,C;

void *printA()
{
    sem_wait(&A);
    printf("A, ");
    sem_post(&B);
}

void *printB()
{
    sem_wait(&B);
    printf("B, ");
    sem_post(&C);
}

void *printC()
{
    sem_wait(&C);
    printf("C, ");
    sem_post(&A);
}

int main()
{
    pthread_t h1,h2,h3;

    sem_init(&A,0,1);
    sem_init(&B,0,0);
    sem_init(&C,0,0);

    pthread_create(&h1, NULL, printA, NULL);
    pthread_create(&h2, NULL, printB, NULL);
    pthread_create(&h3, NULL, printC, NULL);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    pthread_join(h3, NULL);

    sem_destroy(&A);
    sem_destroy(&B);
    sem_destroy(&C);

    return 0;
}
