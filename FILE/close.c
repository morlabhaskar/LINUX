/*
Closes an open file descriptor and releases system resources.
int close(int fd);
Return Value :
0  → success
-1 → failure
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    int fd = open("data.txt", O_RDONLY);
    close(fd);
    return 0;
}