/*
ssize_t msgrcv(int msgid, void *msgp, size_t msgsz,long msgtyp, int msgflg); → Receive Message from Queue
Parameter	Meaning
msgid	    Message queue ID
msgp	    Buffer to store received message
msgsz	    Max size of message
msgtyp	    Message type to receive
msgflg	    Control flags
msgtyp Behavior
Value	Meaning
>0	    Receive specific message type
0	    Receive first message
<0	    Receive lowest type ≤ value
Success → number of bytes received
Failure → -1

int msgctl(int msgid, int cmd, struct msqid_ds *buf); → Control / Delete Message Queue
Parameter	Meaning
msgid	    Message queue ID
cmd	        Control command
buf	        Queue info structure
Command	    Purpose
IPC_RMID	Remove message queue
IPC_STAT	Get queue status
IPC_SET	    Set queue parameters
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