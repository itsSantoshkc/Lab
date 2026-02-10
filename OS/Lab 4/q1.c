#include<pthread.h>
#include<stdio.h>

void *newThreadFunc(void *arg) {
    printf("Thread Created\n");
    return NULL;
}

int main(){
    pthread_t thread1;


    pthread_create(&thread1,NULL,newThreadFunc,NULL);

    pthread_join(thread1,NULL);
    return 0;


}