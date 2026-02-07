#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
struct student{
    int id;
    char name[100];
};
int main(){
    int shmid;
    shmid=shmget(IPC_PRIVATE,sizeof(struct student),0666|IPC_CREAT);
    struct student *stu;
    stu=(struct student *)shmat(shmid,NULL,0);
    if(fork()==0){
        //child
        printf("Child Process\n");
        printf("Student ID   : %d\n",stu->id);
        printf("Student Name : %s\n",stu->name);
        shmdt(stu);
    }else{
        //parent
        printf("Parent Process\n");
        stu->id=100;
        strcpy(stu->name,"Bhaskar");
        shmdt(stu);
        wait(NULL);
        shmctl(shmid,IPC_RMID,NULL);
    }
    return 0;
}