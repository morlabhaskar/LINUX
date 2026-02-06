/*
mkfifo() creates a named pipe file in the filesystem for IPC between unrelated processes.
int mkfifo(const char *pathname, mode_t mode);
0 → FIFO created successfully
-1 → Error occurred (check errno)
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[]){
    int fd;
    char msg[]="Hello Bhaskar";
    //create fifo with name
    if(mkfifo(argv[1],0660)==-1){
        if(errno!=EEXIST){
            perror("mkfifo");
            return 0;
        }
        printf("FIFO already Exist No need creation\n");
    }
    fd=open(argv[1],O_WRONLY);
    if(fd==-1){
        perror("open");
        return 0;
    }
    printf("FIFO opened successfully\n");
    write(fd,msg,sizeof(msg));
    close(fd);
}