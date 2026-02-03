/*
readdir() reads the next directory entry from a directory stream.
struct dirent *readdir(DIR *dirp);
dirp → Directory pointer returned by opendir()
Return Value :
Success → Pointer to struct dirent
End of directory / Error → NULL
*/
#include <stdio.h>
#include <dirent.h>
//gcc readdir.c -o myls
int main(){
    DIR *dp;
    struct dirent *entry;
    dp = opendir(".");
    if (dp == NULL){
        perror("opendir");
        return 1;
    }
    while((entry = readdir(dp)) != NULL){
        printf("%s  ", entry->d_name);
    }
    closedir(dp);
    return 0;
}