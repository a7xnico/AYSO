#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define numThreads 10
#define n 10000
void *funcion1(void *p)
{
    pthread_t idThread = pthread_self();
    pid_t pid = getpid();

    for(int i = 1; i <= n; i++)
    {
        printf("Hola Threads!. Soy el thread %d del proceso %d ejecutando por %d vez\n",idThread ,pid ,i);
    }
    pthread_exit(NULL);
}



int main()
{
    pthread_t hilos[numThreads];
    for(int i = 0; i < numThreads; i++)
        pthread_create(&hilos[i], NULL, funcion1, NULL);

    for(int i = 0; i < numThreads; i++)
        pthread_join(hilos[i], NULL);
    return 0;
}
