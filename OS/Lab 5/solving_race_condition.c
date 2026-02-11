// Write a program in C to solve the problem of race conditions using a semaphore.
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>

int value = 1;
sem_t mutex;

void *sleepA(void *u)
{
    printf("From A\n");
    sem_wait(&mutex);
    value += 5;

    printf("A: I am goin to sleep for %d seconds \n", value);

    sleep(value);

    printf("A: slept for %d serconds \n", value);

    sem_post(&mutex);

    return NULL;
}

void *sleepB(void *u)
{
    printf("From B\n");
    sem_wait(&mutex);
    value += 2;

    printf("B: I am goin to sleep for %d seconds \n", value);

    sleep(value);

    printf("B: slept for %d serconds \n", value);

    sem_post(&mutex);

    return NULL;
}


int main(){
    pthread_t tid1,tid2;

    time_t t;
    time(&t);

    sem_init(&mutex,0,1);


    printf("Date: \n %s",ctime(&t));


    pthread_create(&tid1,NULL,&sleepA,NULL);
    pthread_create(&tid2,NULL,&sleepB,NULL);

    printf("Main Thread\n");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);


    printf("Final Global Variable value : %d \n",value);


    sem_destroy(&mutex);

    return 0;
}