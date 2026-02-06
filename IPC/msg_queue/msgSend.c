/*
int msgget(key_t key, int msgflg); → Create / Access Message Queue
key	   → Unique key to identify message queue
msgflg → Permission + control flags
Success → message queue ID (msgid)
Failure → -1

int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); → Send Message to Queue
Parameter	Meaning
msgid	    Message queue ID
msgp	    Pointer to message structure
msgsz	    Size of message data (excluding mtype)
msgflg  	Control flags
Success → 0
Failure → -1
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct msgbuff{
    long mtype;
    char mtext[100];
};
int main(){
    int msgid,st;
    msgid=msgget(123,0666 | IPC_CREAT);
    if(msgid==-1){
        perror("msgget");
        return 0;
    }
    struct msgbuff msg;
    msg.mtype=1;
    printf("Enter the Message : \n");
    fgets(msg.mtext,sizeof(msg.mtext),stdin);
    msg.mtext[strlen(msg.mtext)-1]='\0';

    st=msgsnd(msgid,&msg,sizeof(msg.mtext),0);
    if(st==-1){
        perror("msgsend");
        return 0;
    }
    printf("Message Send Successfully\n");
    return 0;
}
