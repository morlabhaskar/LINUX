#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
int main(){
    int shmid;
    char *ptr=NULL;
    shmid=shmget(1234,1024,0666);
    ptr=shmat(shmid,NULL,0);
    printf("Read : %s\n",ptr);
    shmdt(ptr);
    shmctl(shmid,IPC_RMID,NULL);
    printf("Shared Memory is Deleted\n");
}