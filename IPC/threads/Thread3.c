#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_t tid1,tid2;
int var=10;
void *f1(void *p){
	static int v1=5;
	printf("in f1...var=%d\n",var);
	++var;
	sleep(20);
	printf("thread1..exiting\n");
	pthread_exit(&v1);
}
void *f2(void *p){
	static int v2=8;
	printf("in f2...%d\n",var);
	sleep(15);
	printf("thread2 exiting\n");
	pthread_exit(&v2);	
}
int main(){
	printf("in main with pid=%d\n",getpid());
	pthread_create(&tid1,NULL,f1,NULL);
	pthread_create(&tid2,NULL,f2,NULL);
	//here two new threads(jobs) created. but execution by scheduler.
	printf("two new jobs created...\n");
	pthread_join(tid1,NULL);
	printf("main..collected exit status of thread1\n");
	pthread_join(tid2,NULL);
	printf("main..collected exit status of thread2\n");
	printf("main  exitng\n");
	pthread_exit(NULL);
	return 0;
}
