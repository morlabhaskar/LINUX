/*
The parent executes first due to scheduling, writes data to the pipe, the child reads and prints it, then the child replies and the parent prints the response
Parent ── "Rambabu" ──▶ Child
Parent ◀─ "Bhaskar" ── Child
 */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
        pid_t pid;
        int p2c[2];//parent to child
        int c2p[2];//child to parent
        char parent_buff[]="Rambabu";
        char child_buff[]="Bhaskar";
        char buff[20];
        //create pipes
        if(pipe(p2c)==-1){
            perror("pipe");
            return 0;
        }
        if(pipe(c2p)==-1){
            perror("pipe");
            return 0;
        }
        //create child process
        pid=fork();
        if(pid==-1){
            perror("fork");
            return 0;
        }
        if(pid>0){
            //parent process
            printf("Parent Process\n");
            close(p2c[0]);//no need read end
            close(c2p[1]);//no need write end
            //parent -> child
            write(p2c[1],parent_buff,strlen(parent_buff)+1);
            //read data from the child
            read(c2p[0],buff,sizeof(buff));
            printf("Parent Recieved = %s\n",buff);
            close(p2c[1]);
            close(c2p[0]);
        }else{
            //child process
            printf("Child Process\n");
            close(p2c[1]);//no need write end
            close(c2p[0]);//no need read end
            //read data from parent
            read(p2c[0],buff,sizeof(buff));
            printf("Child Recieved = %s\n",buff);
            //child -> parent
            write(c2p[1],child_buff,strlen(child_buff)+1);
            close(c2p[1]);
            close(p2c[0]);
        }
        return 0;

}