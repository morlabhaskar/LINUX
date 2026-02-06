#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
int countSubString(char *str,char *sub){
    char *ptr=str;
    int count;
    while((ptr=strstr(ptr,sub))!=NULL){
        count++;
        ptr=ptr+strlen(sub);
    }
    return count;
}
//./a.out
int main(){
    int fd,count;
    char buff[100],sub[30];
    fd=open("fifo1",O_RDONLY);
    if(fd==-1){
        printf("fifo1 is not opened\n");
        return 0;
    }
    read(fd,buff,sizeof(buff));
    close(fd);
    printf("Enter the Substring :\n");
    fgets(sub,sizeof(sub),stdin);
    sub[strlen(sub)-1]='\0';
    printf("Recieved : %s\n",buff);
    count=countSubString(buff,sub);
    fd=open("fifo2",O_WRONLY);
    if(fd==-1){
        printf("fifo2 is not opened\n");
        return 0;
    }
    write(fd,&count,sizeof(count));
    close(fd);
    return 0;
}
