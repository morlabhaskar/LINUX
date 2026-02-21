#include<unistd.h>
#include<stdio.h>
#include<signal.h>
void handler(int sig){
    printf("Signal %d is Recieved\n",sig);
}
int main(){
    signal(SIGINT,handler);
    while(1){
        printf("Running...\n");
        sleep(2);
    }
}
//kill -SIGUSR1 4321