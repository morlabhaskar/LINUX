/*
int execl(const char *path, const char *arg0, ..., NULL);
execl() replaces the current process image with a new process image.
Here, it replaces your program with the ls -l command.
On success → does not return
On failure → returns -1
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    execl("/bin/ls", "ls", "-l", NULL);
    return 0;
}