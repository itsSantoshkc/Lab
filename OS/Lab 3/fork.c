#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // Required for pid_t in some systems

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Error handling if fork fails
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Code inside this block runs in the child process
        printf("Hello from the Child process!\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        // Code inside this block runs in the parent process
        printf("Hello from the Parent process!\n");
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }

    // Both processes execute the code below this point
    printf("This line is executed by both parent and child.\n");

    return 0;
}
