#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
//./a.out
int main(){    
    int fd;
    char str[100];
    int count;
    if(mkfifo("fifo1",0666)==-1){
        if(errno!=EEXIST){
            perror("fifo1");
            return 0;
        }
    }
    if(mkfifo("fifo2",0666)==-1){
        if(errno!=EEXIST){
            perror("fifo2");
            exit(0);
        }
    }
    printf("Enter the String :\n");
    fgets(str,sizeof(str),stdin);
    str[strlen(str)-1]='\0';
    fd=open("fifo1",O_WRONLY|O_CREAT);
    if(fd==-1){
        printf("fifo1 is not opened\n");
        return 0;
    }
    write(fd,str,sizeof(str));
    close(fd);
    printf("Writting Successfully\n");
    fd=open("fifo2",O_RDONLY);
    if(fd==-1){
        printf("fifo2 is not opened\n");
        return 0;
    }
    read(fd,&count,sizeof(count));
    printf("Substrings count is : %d\n",count);
    close(fd);
    return 0;
}