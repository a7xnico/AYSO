#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t espacioLibre, manipulacionDelBuffer, elementoDisponible;

void *productor()
{
    while(true){
        producirUnElemento;
        sem_wait(espacioLibre);
        sem_wait(manipulacionDelBuffer);
        depositarElementoEnBuffer;
        sem_post(manipulacionDelBuffer);
        sem_post(elementoDisponible)
    }
}

void *consumidor()
{
    while(true){
        sem_wait(manipulacionDelBuffer):
        sem_wait(elementoDisponible);
        sacarElementoDelBuffer;
        sem_post(manipulacionDelBuffer);
        sem_post(espacioLibre);
        consumirElemento;
    }
}

int main()
{

    pthread_t h1, h2;
    sem_init(&espacioLibre, 0, 1);
    sem_init(&manipulacionDelBuffer, 0, 1);
    sem_init(&elementoDisponible, 0 ,0);
    return 0;
}
