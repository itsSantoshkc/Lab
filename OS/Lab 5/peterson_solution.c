// Write a program in C to simulate Peterson’s Solution
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdbool.h>
#include<time.h>


#define NUM_THREADS 2
volatile bool flag[NUM_THREADS] = {false,false};
volatile int turn = 0;


void *criticalSection(void *threadID){
    int id = *(int *)threadID;
    int other = 1 - id;

    for(int i = 0;i<5;i++){
        flag[id] = true;
        turn - other;
         while(flag[other] && turn == other){

         }

         time_t now;
         time(&now);
         printf("Thread %d entering the crtical section at %s." , id ,ctime(&now));
         usleep(1000000);
         time(&now);
         printf("Thread %d entering the crtical section at %s." , id ,ctime(&now));

         flag[id] = false;
         usleep(5000000);

    }
    pthread_exit(NULL);
}


int main(){
    pthread_t threads[NUM_THREADS];

    int threadIDs[NUM_THREADS] = {0,1};

    for(int i = 0;i < NUM_THREADS ;++i){
        pthread_create(&threads[i],NULL,criticalSection,(void*)&threadIDs[i]);
    }

    for(int i = 0;i< NUM_THREADS;++i){
        pthread_join(threads[i],NULL);
    }

    return 0;
}