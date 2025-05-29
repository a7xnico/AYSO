#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int x;
sem_t A, B;

void *pA()
{
    sem_wait(&A);
    x = 199;
    x++;
    printf("%d\n", x);
    sem_post(&B);
}

void *pB()
{
    sem_wait(&B);
    x = 500;
    x = x/10;
    printf("%d\n", x);
    sem_post(&A);
}


int main()
{
    pthread_t h1, h2;
    sem_init(&A, 0, 0);
    sem_init(&B, 0, 1);

    pthread_create(&h1, NULL, pA, NULL);
    pthread_create(&h2, NULL, pB, NULL);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);

    sem_destroy(&A);
    sem_destroy(&B);
    return 0;
}
