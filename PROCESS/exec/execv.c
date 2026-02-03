/*
int execv(const char *path, char *const argv[]);
Arguments are passed using an array of strings
On success → does not return
On failure → returns -1
*/
#include<unistd.h>
#include<stdio.h>
int main(){
    char *args[]={"ls","-l",NULL};
    execv("/bin/ls",args);
    perror("execv");//executes if execv() fails
    return 0;
}