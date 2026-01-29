/*
opendir() opens a directory stream for reading directory entries.
DIR *opendir(const char *name);
name → Path of the directory( "." for current directory )
Return Value :
Success → Pointer to DIR structure
Failure → NULL
*/
#include<stdio.h>
#include<dirent.h>
int main(){
    DIR *dp;
    dp = opendir(".");
    if (dp == NULL){
        perror("opendir");
        return 1;
    }
    printf("Directory opened successfully\n");
    closedir(dp);
    return 0;
}
