#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *saludar1()
{
    printf("Hola, soy el hilo 1\n");
}

void *saludar2()
{
    // pthread_exit(0) NO SE REALIZA TODO LO QUE ESTE DEBAJO DE EXIT

    printf("Hola, soy el hilo 2\n");
}

void *saludar3()
{
    printf("Hola, soy el hilo 3\n");

    pthread_exit(0);
}

void *saludar()
{
    printf("Hola, soy el hilo %d\n", pthread_self()); // pthread_self da el identificador del hilo
}

int main()
{
    // los valores para el pthread_self se va dando mientras se inicializan
    //          1      2      3     4   ......   N
    pthread_t hilo1, hilo2, hilo3; // iniciamos las variables

    pthread_create(&hilo1, NULL, saludar, NULL); // crear e inicializar la funcion
    pthread_create(&hilo2, NULL, saludar, NULL);
    pthread_create(&hilo3, NULL, saludar, NULL);

    pthread_join(hilo1, NULL); // el main espera a que los hilos terminen
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);


    return 0;
}
