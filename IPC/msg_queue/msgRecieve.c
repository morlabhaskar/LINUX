#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct msgbuff{
    long mtype;
    char mtext[100];
}
int main(){
    int msgid;
    msgid=msgget(123,0666|IPC_CREAT);
    if(msgid==-1){
        perror("msgget");
        return 0;
    }
    struct msgbuff msg;
    if(msgrcv(msgid,&msg,sizeof(msg.mtext),1,0)==-1){
        perror("msgrcv");
        return 0;
    }
    printf("Recieved message : %s\n",msg.mtext);

    msgctl(msgid,IPC_RMID,NULL);//delete queue
    return 0;
}