#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/// declarar de manera global los semaforos a utilizar

sem_t A, B, C;

int a = 5;

int x;
/*
void *saludar1()
{
    // A = 1
    sem_wait(&A);
    // A = 0
    printf("Hola soy el Hilo: 1!\n");
    // B = 0

    a--;
    printf("A vale: %d\n", a);

    sem_post(&B);
    // B = 1
}

void *saludar2()
{
    sem_wait(&B);
    // B = 0
    printf("Hola soy el Hilo: 2!\n");
    // C = 0

    a++;
    printf("A vale: %d\n", a);

    sem_post(&C);
    // C = 1
}

void *saludar3()
{
    sem_wait(&C);
    // C = 0
    printf("Hola soy el hilo: 3!\n");
    // A = 0

    a = a*a;
    printf("A vale: %d", a);

    sem_post(&A);
    // A = 1
}

void *saludarTodos()
{
    printf("Hola soy el Hilo: %d\n", pthread_self());
}
*/

void funcionA()
{
    sem_wait(&A);
    x = 199;
    x++;
    printf("%d\n", x);
    sem_post(&B);
}

void funcionB()
{
    sem_wait(&B);
    x = 500;
    x = x/10;
    printf("%d\n", x);
    sem_post(&A);
}

int main()
{
    pthread_t hilo1, hilo2, hilo3;

    sem_init(&A, 0, 1);
    sem_init(&B, 0, 0);


    pthread_create(&hilo1, NULL, funcionA, NULL);
    pthread_create(&hilo2, NULL, funcionB, NULL);
    //pthread_create(&hilo3, NULL, saludar3, NULL);

    pthread_join(&hilo1, NULL);
    pthread_join(&hilo2, NULL);
    pthread_join(&hilo3, NULL);

    sem_destroy(&A);
    sem_destroy(&B);
    sem_destroy(&C);



    return 0;
}
