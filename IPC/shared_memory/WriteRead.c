#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main(){
    int shmid;
    char *shmptr=NULL;
    //create shm 
    shmid=shmget(IPC_PRIVATE,1024,0666|IPC_CREAT);
    if(fork()==0){
        //child process
        shmptr=shmat(shmid,NULL,0);
        printf("memory attached in child\n");
        printf("Child Read : %s\n",shmptr);
        shmdt(shmptr);
        printf("memory is detached in child\n");
    }else{
        //parent process
        printf("Parent Process\n");
        shmptr=shmat(shmid,NULL,0);
        printf("memory attached in parent\n");
        strcpy(shmptr,"Hello from Parent (Shared Memory)");
        printf("memory is copied from parent\n");
        shmdt(shmptr);
        printf("memory is detached in parent\n");

        wait(NULL);

        //remove shared memory
        shmctl(shmid,IPC_RMID,NULL);
        printf("shared memory is deleted\n");
    }
    return 0;
}

