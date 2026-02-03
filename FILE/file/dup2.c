/*
dup2() is a Linux system call used to redirect input or output by copying one 
file descriptor to another specific file descriptor number.
int dup2(int oldfd, int newfd);
Because standard input/output/error have fixed FD numbers:
FD	Meaning
0	stdin
1	stdout
2	stderr

Before dup2:
printf → terminal
After dup2:
printf → output.txt
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd;
    fd=open("output.txt",O_WRONLY|O_CREAT);
    dup2(fd,STDOUT_FILENO);//Redirect stdout (FD=1) to file
    close(fd);//Close original fd
    printf("Hello dup2\n");//printf now writes to file
    printf("Hello World");//printf now writes to file
}