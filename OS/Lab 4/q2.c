#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d is running\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    // create two threads
    pthread_create(&t1, NULL, task, &id1);
    pthread_create(&t2, NULL, task, &id2);

    // wait for both threads
    pthread_join(t2, NULL);
    pthread_join(t1, NULL);
    printf("Both threads have finished.\n");

    return 0;
}
