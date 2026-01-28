/*
Opens an existing file,Creates a new file if it does not exist
int open(const char *pathname, int flags, mode_t mode);
Flag	        Meaning
O_RDONLY	Open for read only
O_WRONLY	Open for write only
O_RDWR	    Open for read & write
O_CREAT	    Create file if not exists
O_APPEND	Write at end of file
O_TRUNC	    Clear file contents
Return Value :
Success → returns a file descriptor (≥ 0)
Failure → returns -1
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd;
    fd=open("data1.txt",O_CREAT|O_WRONLY,0644);
    if(fd==-1){
        perror("Failed");
        return 1;
    }
    printf("File created Successfully");
    close(fd);//auto closed by OS if not closed
    return 0;
}