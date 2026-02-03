/*
int execve(const char *path, char *const argv[], char *const envp[]);
Lowest-level system call
All other exec() functions internally call execve()
Requires path, argv, and envp
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {NULL};

    execve("/bin/ls", args, env);
    return 0;
}