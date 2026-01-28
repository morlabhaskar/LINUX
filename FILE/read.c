/*
ssize_t read(int fd, void *buf, size_t count);
fd – File descriptor (returned by open())
buf – Buffer to store the read data
count – Number of bytes to read
Return Value :
>0 → Number of bytes actually read
0  → End of file (EOF)
-1 → Error
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[]){
    int fd,n;
    char buf[100];
    fd=open(argv[1],O_RDONLY);
    if(fd==-1){
        perror("Error");
        return 1;
    }
    n=read(fd,buf,sizeof(buf)-1);
    if(n>0){
        buf[n]='\0';
        printf("Data is :\n%s",buf);
    }
    close(fd);
    return 0;
}