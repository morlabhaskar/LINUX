#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_t tid1,tid2;
int var=10;
void *f1(void *p){
	static int v1=5;
	printf("in f1...var=%d\n",var);
	++var;
	sleep(4);
	printf("thread1..exiting\n");
	pthread_exit(&v1);

}
void *f2(void *p){
	static int v2=8;
	printf("in f2...%d\n",var);
	sleep(3);
	printf("thread2 exiting\n");
	pthread_exit(&v2);
	
}
int *ptr;
int main(){
	printf("in main...pid=%d\n",getpid());
	pthread_create(&tid1,NULL,f1,NULL);
	pthread_create(&tid2,NULL,f2,NULL);
	//here two new threads(jobs) created. but execution by scheduler.
	//
	printf("two new jobs created...\n");
	pthread_join(tid1,&ptr);
	printf("main..collected exit val: %u\n",*ptr);
	pthread_join(tid2,&ptr);
	printf("main..collected exit val: %u\n",*ptr);
	pthread_exit(NULL);
	return 0;
}
