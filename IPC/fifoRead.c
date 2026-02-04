#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
    int fd;
    char buff[100];
    fd=open(argv[1],O_RDONLY);
    read(fd,buff,sizeof(buff));
    printf("Recieved : %s\n",buff);
    close(fd);
}
