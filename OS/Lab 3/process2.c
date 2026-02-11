#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    char *args[] = {"./process1",NULL};
    printf("Process 2 PID : %d\n",getpid());
    printf("Executing another process\n");
    fflush(stdout);
    execv("./process1",args);
    perror("Execution Failed");
    return 1;
}