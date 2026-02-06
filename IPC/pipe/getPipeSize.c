/*WAP to find pipe size*/
#define _GNU_SOURCE //enables GNU extensions to the standard c library
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
        int fd[2];
        //create pipe
        if(pipe(fd)==-1){
                perror("pipe");
                return 0;
        }
        int size = fcntl(fd[0],F_GETPIPE_SZ);
        // int size = fcntl(fd[1],F_GETPIPE_SZ);//fd[0],fd[1] both same
        if(size==-1){
                perror("fcntl");
                return 0;
        }
        printf("Pipe size = %d\n",size);
        close(fd[0]);
        close(fd[1]);
}