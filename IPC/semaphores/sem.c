/*
 sem_init(&sem, 0, 1);
Parameters:
&sem  → semaphore variable
0     → semaphore is shared between threads, not processes
1     → initial value (binary semaphore)
Value 1 means only one thread allowed at a time.
*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem;
pthread_t t1,t2;
void *inc1(void *arg){
    printf("Thread=1\n");
    sem_wait(&sem);
    printf("Thread one\n");
    sem_post(&sem);
    printf("thread 1 exit\n");
}
void *inc2(void *arg){
    printf("Thread=2\n");
    sem_wait(&sem);
    printf("Thread two\n");
    sem_post(&sem);
    printf("thread 2 exit\n");
}
int main(){
    sem_init(&sem,0,1);
    printf("Semaphore initialized\n");
    pthread_create(&t1,NULL,inc1,NULL);
    pthread_create(&t2,NULL,inc2,NULL);
    printf("2 threads created\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&sem);
    printf("Main completed\n");
}
