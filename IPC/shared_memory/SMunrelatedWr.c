#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
int main(){
    int shmid;
    char *ptr=NULL;
    shmid=shmget(1234,1024,0666|IPC_CREAT);
    printf("Writting Process\n");
    ptr=shmat(shmid,NULL,0);
    strcpy(ptr,"Bhaskar");
    printf("Written Success\n");
    shmdt(ptr);
}