#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
int main(){
    int shmid;
    char *ptr=NULL;
    shmid=shmget(IPC_PRIVATE,1024,0666|IPC_CREAT);
    if(fork()==0){
        printf("Child Process\n");
        ptr=(char*)shmat(shmid,NULL,0);
        printf("shm attached in child\n");
        printf("read shm : %s\n",ptr);
        shmdt(ptr);
    }
    else{
        printf("Parent Process\n");
        ptr=(char*)shmat(shmid,NULL,0);
        strcpy(ptr,"Bhaskar");
        printf("Written in shm\n");
        shmdt(ptr);
        wait(NULL);
        shmctl(shmid,IPC_RMID,NULL);
        printf("Shared memory is deleted\n");
    }
}