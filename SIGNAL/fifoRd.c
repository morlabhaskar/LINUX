#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main(){
    int fd;
    char rbuff[100];
    fd=open("fifo",O_RDONLY);
    if(fd==-1){
        perror("open");
        return 0;
    }
    read(fd,rbuff,sizeof(rbuff));
    printf("Recieved Buffer = %s\n",rbuff);
    close(fd);
}