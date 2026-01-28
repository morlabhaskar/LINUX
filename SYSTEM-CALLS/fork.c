#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	printf("Hello\n");
	fork();
	printf("Process is about to terminate\n");
}
