#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int count=0;
pthread_t tid1,tid2;
pthread_mutex_t m;
void *inc(void *arg){
    pthread_mutex_lock(&m);
    count++;
    pthread_mutex_unlock(&m);
    return NULL;
}
int main(){
    pthread_mutex_init(&m,NULL);
    printf("Mutex Init complete\n");
    pthread_create(&tid1,NULL,inc,NULL);
    pthread_create(&tid2,NULL,inc,NULL);
    printf("Two Threads Created\n");
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("Count = %d\n",count);
    pthread_mutex_destroy(&m);
}