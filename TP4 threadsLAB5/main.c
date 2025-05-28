#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *funcion(void *p)
{
 printf("Thread: %d\n", pthread_self());
 pthread_exit(0);
}
int main()
{
 pthread_t th1, th2;
 pthread_create(&th1, NULL, funcion, NULL);
 pthread_create(&th2, NULL, funcion, NULL);
 printf("El thread principal continua ejecutando: %d\n", pthread_self());
 ///pthread_join(th1,NULL);
 ///pthread_join(th2,NULL);
 return 0;
}
