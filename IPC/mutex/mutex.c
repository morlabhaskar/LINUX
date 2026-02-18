#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_t tid1,tid2;
int var=1;
pthread_mutex_t m1;
void *f1(void *p){
	printf("In thread1...\n");
	////////////////critical section starts here
	pthread_mutex_lock(&m1);
	printf("in thread1...var=%d\n",var);
	++var;
	// sleep(14);
	++var;
	printf("in thread1...var=%d\n",var);
	pthread_mutex_unlock(&m1);
	//////////////critical section ends here
	printf("thread1..exiting\n");
	pthread_exit(NULL);

}
void *f2(void *p){
	printf("In thread2...\n");
    /////////////////////critical regions starts
	pthread_mutex_lock(&m1);
	printf("in thread2...var=%d\n",var);
	var+=100;
	// sleep(12);
	var+=100;
	printf("in thread2...var=%d\n",var);
	pthread_mutex_unlock(&m1);
    ////////////////////critical regions ends
	printf("thread2..exiting\n");
	pthread_exit(NULL);
	
}
int main(){
	printf("pid=%d\n",getpid());
	pthread_mutex_init(&m1,NULL);
	pthread_create(&tid1,NULL,f1,NULL); //2nd arg is Attribute, //4th arg is optional data.
	pthread_create(&tid2,NULL,f2,NULL);
	//here two new threads(jobs) created. but execution by scheduler.
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_exit(NULL);
	return 0;
}
