#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main()
{
    int pthread_create(&hilo1, NULL, saludarHilo, NULL); // CREACION DE HILO Y EJECUTA LA FUNCION DADA EN LOS PARAMETROS
    int pthread_join(h1, NULL); // MAIN ESPERA A QUE EL HILO TERMINE
    int pthread_exit(0) // ingresar en la funcion el tiempo que debe esperar hasta cerrar el hilo (normalmente 0)
    pthread_t // dato para almacenar el hilo
    pthread_self // devuelve el identificador del thread que ejecuta la llamada

    return 0;
}
