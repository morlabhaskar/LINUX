//WAP to communication between parent and child using pipe parent send a string to 
//child and child find vowels that string and reply back to parent.

#include<stdio.h>
#include<string.h>
#include<unistd.h>
int is_vowel(char ch){
    switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':return 1;
    }
    return 0;
}
void remove_non_vowels(char *ptr){
    while(*ptr!='\0'){
        if(is_vowel(*ptr)==0){
            memmove(ptr,ptr+1,strlen(ptr+1)+1);
        }
        else{
            ptr++;
        }
    }
}
int main(){
    pid_t pid;
    int p2c[2],c2p[2];
    char pbuff[100];
    if(pipe(p2c)==-1){
        perror("pipe");
        return 0;
    }
    if(pipe(c2p)==-1){
        perror("pipe");
        return 0;
    }
    pid=fork();
    if(pid==-1){
        perror("fork");
        return 0;
    }
    if(pid>0){
        char rbuff[100];
        printf("Parent Process\n");
        close(p2c[0]);
        close(c2p[1]);
        printf("Enter the string to send child :\n");
        fgets(pbuff,sizeof(pbuff),stdin);
        pbuff[strlen(pbuff)-1]='\0';
        write(p2c[1],pbuff,sizeof(pbuff));
        printf("Parent Send String : %s\n",pbuff);
        read(c2p[0],rbuff,sizeof(rbuff));
        printf("Parent Recieved String : %s\n",rbuff);
        close(p2c[1]);
        close(c2p[0]);
    }
    else{
        char rbuff[100];
        printf("Child process\n");
        close(p2c[1]);
        close(c2p[0]);
        read(p2c[0],rbuff,sizeof(rbuff));
        printf("Child Recieved String : %s\n",rbuff);
        remove_non_vowels(rbuff);
        write(c2p[1],rbuff,sizeof(rbuff));
        printf("Child Send String : %s\n",rbuff);
        close(p2c[0]);
        close(c2p[1]);
    }
}
