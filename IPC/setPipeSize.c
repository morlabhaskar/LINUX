#define _GNU_SOURCE
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
        int o_size = fcntl(fd[0],F_GETPIPE_SZ);
        printf("Old Pipe Size = %d\n",o_size);
        int desired_size = 131072; // 128KB only two powers
        int n_size = fcntl(fd[0],F_SETPIPE_SZ,desired_size);
        if(n_size==-1){
                perror("fcntl setsize");
                return 0;
        }
        printf("Requested Pipe Size = %d\n",desired_size);
        printf("New Pipe Size = %d\n",n_size);
        close(fd[0]);
        close(fd[1]);
}