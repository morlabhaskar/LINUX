#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
    int ret;
    ret = fork();
    if (ret == -1){
        perror("fork");
        return 0;
    }
    if (ret){
        printf("In Parent:PID=%d PPID=%d\n", getpid(), getppid());
        int ret1 = fork();
        if (ret1 == -1){
            perror("fork1");
            exit(0);
        }
        if (ret1 == 0){
            sleep(25);
            printf("In child12PID=%d PPID=%d\n", getpid(), getppid());
            exit(0);
        }
    }
    else{
        sleep(15);
        printf("In child1PID=%d PPID=%d\n", getpid(), getppid());
    }
    printf("Byeee\n");
}
