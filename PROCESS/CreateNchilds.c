#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void ParentCode(void){
    printf("In Parent PID=%d PPID=%d\n", getpid(), getppid());
}
void Child1Code(void){
    sleep(15);
    printf("In child11PID=%d PPID=%d\n", getpid(), getppid());
}
void Child2Code(void){
    sleep(25);
    printf("In child12PID=%d PPID=%d\n", getpid(), getppid());
}
int main(){
    int ret;
    ret = fork();
    if(ret == -1){
        perror("fork");
        return 0;
    }
    if(ret){
        int ret1 = fork();
        if(ret1 == -1){
            perror("fork1");
            exit(0);
        }
        if(ret1)
            ParentCode();
        else
            Child2Code();
    }
    else
        Child1Code();
}
