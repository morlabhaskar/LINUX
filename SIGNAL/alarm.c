#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handler(int arg){
    printf("Alarm time period is elapsed\n");
}
int main(){
    printf("I am in Main\n");
    signal(SIGALRM,handler);
    alarm(5);
    printf("set with alarm of 5 sec\n");
    pause();//wait for the alarm
}