/*
WAP Parent sends data, Child receives data
Write End  ────► Pipe ────►  Read End
fd[1] → write end,fd[0] → read end
Parent writes → Child reads
Child writes → Parent reads (need another pipe)
ls | wc -l
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    int fd[2];
    pid_t pid;
    char arr[]="Bhaskar";
    char buf[20];
    //create a pipe
    // pipe(fd);
    if(pipe(fd)==-1){
        perror("pipe");
        return 0;
    }
    //create child process
    pid = fork();
    if(pid==-1){
        perror("fork");
        return 0;
    }
    if(pid>0){
        //parent process
        printf("Parent Process\n");
        close(fd[0]);//close read end
        write(fd[1],arr,strlen(arr)+1);
        close(fd[1]);
    }else{
        //child process
        printf("Child Process\n");
        close(fd[1]);//close write end
        read(fd[0],buf,sizeof(buf));
        printf("Read data = %s\n",buf);
        close(fd[0]);
    }
}