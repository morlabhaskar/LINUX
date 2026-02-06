/*
$ls | wc -l

After fork():
Child process → executes ls
Parent process → executes wc -l
Both processes inherit the pipe.
 ls
 │ (stdout redirected by dup2)
 ▼
PIPE
 ▼
 │ (stdin redirected by dup2)
wc -l
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int fd[2];
    pid_t pid;
    // Create pipe
    if(pipe(fd) == -1){
        perror("pipe");
        exit(1);
    }
    // Create child process
    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        // Child process → executes "ls"
        close(fd[0]);             // close read end
        dup2(fd[1], STDOUT_FILENO); // redirect stdout to pipe, Any output written to stdout now goes into the pipe
        close(fd[1]);
        execlp("ls", "ls", NULL);  // execute ls and write to ls output in pipe
        perror("execlp");//if execlp() failed
    }else{
        // Parent process → executes "wc -l"
        close(fd[1]);              // close write end
        dup2(fd[0], STDIN_FILENO);  // redirect stdin from pipe
        close(fd[0]);
        execlp("wc", "wc", "-l", NULL); // execute wc -l
        perror("execlp");//if execlp() failed
    }
    return 0;
}