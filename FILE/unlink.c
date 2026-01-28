/*
unlink() removes a file name from the directory.
int unlink(const char *pathname);
pathname → name or path of the file to be deleted
Return Value :
0  → success
-1 → failure
*/
#include <stdio.h>
#include <unistd.h>
int main(){
    if(unlink("data.txt") == 0)
        printf("File deleted successfully\n");
    else
        perror("unlink");
    return 0;
}
