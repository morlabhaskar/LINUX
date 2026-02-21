#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
void handler(int arg){
    printf("SIGUSR1 signal is recieved\n");
    int fd;
    char buff[100];
    printf("Enter the msg to send another process :\n");
    fgets(buff,sizeof(buff),stdin);
    buff[strlen(buff)-1]='\0';
    fd=open("fifo",O_WRONLY);
    if(fd==-1){
        perror("open");
        exit(0);
    }
    write(fd,buff,sizeof(buff));
    close(fd);
    printf("%s send to another process\n");
}
int main(){
    int fd;
    printf("PID=%d\n",getpid());
    fd=mkfifo("fifo",0660);
    if(fd==-1){
        if(errno!=EEXIST){
            perror("mkfifo");
            exit(0);
        }
    }
    signal(SIGUSR1,handler);
    printf("Waiting for SIGUSR1 signal...\n");
    pause();//wait for signal if 3rd terminal type $kill -SIGUSR1 PID
}