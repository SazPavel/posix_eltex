#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 1000
#define STEPS 1000

//pthread_mutex_t mutex_sum = PTHREAD_MUTEX_INITIALIZER;

int a = 0;

void *func()
{
    int i, tmp;
    for(i = 0; i < STEPS; i++)
    {
        //pthread_mutex_lock(&mutex_sum);
        tmp = a;
        tmp++;
        a = tmp;
        //pthread_mutex_unlock(&mutex_sum);
    }
}


int main()
{
    int i;
    pthread_t tid[THREADS];
    for(i = 0; i < THREADS; i++)
    {
        pthread_create(&tid[i], NULL, func, NULL);
    }
    for(i = 0; i < THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }
    printf("%d\n", a);
    exit(0);
}
