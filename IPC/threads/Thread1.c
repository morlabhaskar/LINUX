#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_t tid;
void *fun(void *arg){
    printf("Hello Thread\n");
    pthread_exit(NULL);//return NULL
}
int main(){
    pthread_create(&tid,NULL,fun,NULL);//create a thread assign thread id into tid
    pthread_join(tid,NULL);//waiting for thread complete to avoid zombie thread
    printf("Main Code\n");
    return 0;
}
