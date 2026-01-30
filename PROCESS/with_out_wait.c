#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
    }
    else {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
    }
    return 0;
}
/*
Parent Process
Parent PID = 24385
Child Process
Child PID = 24386
*/