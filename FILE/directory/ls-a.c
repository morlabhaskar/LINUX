//ls -a
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
struct fileinfo{
    char name[256];
    int size;
    int time;
};
void sort(struct fileinfo file[],int cnt){
    for(int i=0;i<cnt-1;i++){
        for(int j=0;j<cnt-i-1;j++){
            if(strcmp(file[j].name,file[j+1].name)>0){
                struct fileinfo temp=file[j];
                file[j]=file[j+1];
                file[j+1]=temp;
            }
        }
    }
}
int main(int argc,char *argv[]){
    DIR *fd;
    struct dirent *entry;
    struct stat st;
    struct fileinfo files[1024];
    int cnt=0;
    fd=opendir(".");
    if(fd==NULL){
        perror("opendir");
        return 0;
    }
    if(argc==1){
        while((entry=readdir(fd))!=NULL){
            if(!((strcmp(entry->d_name,".")==0)||(strcmp(entry->d_name,"..")==0))){
                strcpy(files[cnt].name,entry->d_name);
                files[cnt].size=entry->d_type;
                cnt++;
            }
        }
        sort(files,cnt);
        for(int i=0;i<cnt;i++){
            printf("%s  ",files[i].name);
        }
        printf("\n");
    }
    else if((argc==2)&&(strcmp(argv[1],"-a")==0)){
        while(entry=readdir(fd)){
            printf("%s  ",entry->d_name);
        }
        printf("\n");
    }
    closedir(fd);
}
