#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_t tid1,tid2;
int var=2;
void *f1(void *p){
    printf("TID1=%d\n",gettid());
    printf("in f1...var=%d\n",var);
    ++var;
    sleep(15);
    printf("thread1 exiting..\n");
    pthread_exit(NULL);
}
void *f2(void *p){
    printf("TID2=%d\n",gettid());
    printf("in f2...var=%d\n",var);
    sleep(30);
    printf("thread2 exiting...\n");
    pthread_exit(NULL);
}
int main(){
    printf("in main...pid=%d\n",getpid());
    pthead_create(&tid1,NULL,f1,NULL);
    pthead_create(&tid2,NULL,f2,NULL);
    //here two new threads(jobs) created. but execution by scheduler.
    printf("two new jobs created...\n");
    printf("main exiting...\n");
    pthread_exit(NULL);
    return 0;
}