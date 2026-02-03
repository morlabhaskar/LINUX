/*
Searches executable in PATH environment variable
int execlp(const char *file, const char *arg0, ..., NULL);
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    execlp("ls", "ls", "-l", NULL);
    return 0;
}