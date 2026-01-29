/*
write() writes data from a memory buffer to a file descriptor.
ssize_t write(int fd, const void *buf, size_t count);
fd – File descriptor (returned by open())
buf – Buffer containing data to write
count – Number of bytes to write
Return Value :
> 0 → Number of bytes actually written
-1 → Error
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
    int fd,n;
    char msg[]="This write() system call";
    fd=open(argv[1],O_CREAT|O_WRONLY);
    if(fd==-1){
        perror("failed");
        return 1;
    }
    write(fd,msg,strlen(msg));//only override content
    close(fd);
    return 0;
}
