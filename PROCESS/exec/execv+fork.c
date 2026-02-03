#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        perror("execv failed");
    } else {
        // Parent process
        printf("Parent process running\n");
    }
    return 0;
}