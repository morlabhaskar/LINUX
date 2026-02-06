#define _GNU_SOURCE //enables GNU extensions to the standard C library. 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
main(){
	int a[2],cnt=0,ch='A';
	//if(pipe(a)==-1)
	if(pipe2(a,O_NONBLOCK)==-1){
		perror("pipe");
		exit(0);
	}
	while(1){
		if(write(a[1],&ch,1)==1)
			cnt++;
		else
			break;
	}
	printf("cnt=%d\n",cnt);
}