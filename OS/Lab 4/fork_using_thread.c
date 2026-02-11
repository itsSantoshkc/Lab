// Explore the behavior of fork while using threads.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* worker(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d: running\n", id);

    if (id == 1) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Child: after fork, I am running only thread %d\n", id);
        } else {
            printf("Parent: forked a child with PID %d\n", pid);
        }
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main: both threads completed in parent.\n");
    return 0;
}
