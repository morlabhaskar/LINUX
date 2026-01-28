/*
Moves the file offset (file pointer) to a specified position.
off_t lseek(int fd, off_t offset, int whence);
fd     - File descriptor returned by open()
offset - Number of bytes to move
whence - Starting reference point
whence Values :
Value	     Meaning
SEEK_SET	From beginning
SEEK_CUR	From current position
SEEK_END	From end of file
Return Value :
Success → New file offset
Failure → -1
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[]){
    int fd,n;
    char buf[20];
    fd=open(argv[1],O_RDONLY);
    if(fd==-1){
        perror("Failed");
        return 1;
    }
    lseek(fd,3,SEEK_SET);
    n=read(fd,buf,sizeof(buf)+2);
    buf[n]='\0';
    printf("Data is :\n%s",buf);
    close(fd);
    return 0;
}
