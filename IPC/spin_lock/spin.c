#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_t t1,t2;
pthread_spinlock_t lock;
int var=0;
void *f1(void *arg){
    printf("thread=1\n");
    pthread_spin_lock(&lock);
    var++;
    pthread_spin_unlock(&lock);
    printf("thread1 exit\n");
}
void *f2(void *arg){
    printf("thread=2\n");
    pthread_spin_lock(&lock);
    var++;
    pthread_spin_unlock(&lock);
    printf("thread2 exit\n");
}
int main(){
    pthread_spin_init(&lock,PTHREAD_PROCESS_PRIVATE);
    printf("spinLock initialized\n");
    pthread_create(&t1,NULL,f1,NULL);
    pthread_create(&t2,NULL,f2,NULL);
    printf("2 threads created\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Value = %d\n",var);
    printf("Main Exit\n");
    pthread_spin_destroy(&lock);
    return 0;
}