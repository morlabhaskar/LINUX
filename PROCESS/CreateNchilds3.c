/*W.A.P. for creating n no. of children processes by common parent
  where n should be from command line args*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Insufficicent infn\n");
        return 0;
    }
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++){
        int ret = fork();
        if (ret == 0){
            sleep(4);
            printf("pid=%d ppid=%d\n", getpid(), getppid());
            exit(0);
        }
    }
    printf("Byeee\n");
}
