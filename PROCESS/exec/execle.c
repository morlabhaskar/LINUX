/*
int execle(const char *path, const char *arg0, ..., NULL, char *const envp[]);
Allows passing a custom environment
Arguments passed as list
Runs env with a custom environment
*/
#include <unistd.h>
#include <stdio.h>

int main(){
    char *env[] = {"MYVAR=Hello", NULL};
    execle("/usr/bin/env", "env", NULL, env);
    return 0;
}