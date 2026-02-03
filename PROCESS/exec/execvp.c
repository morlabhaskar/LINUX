/*
int execvp(const char *file, char *const argv[]);
Searches program in PATH
Arguments passed as array
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);
    return 0;
}