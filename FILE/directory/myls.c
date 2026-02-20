/*
struct dirent {
    ino_t          d_ino;       /* Inode number 
    off_t          d_off;       /* Not an offset; see below 
    unsigned short d_reclen;    /* Length of this record 
    unsigned char  d_type;      /* Type of file; not supported by all filesystem types 
    char           d_name[256]; /* Null-terminated filename 
};

*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<time.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
struct fileinfo{
    char name[256];
    int size;
};
void sort(struct fileinfo file[],int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(strcmp(file[j].name,file.[j+1].name)>0){
                struct fileinfo temp=file[j];
                file[j]=file[j+1];
                file[j+1]=temp;
            }
        }
    }
}
//./myls -l
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
    //ls
    if(argc==1){
        while((entry=readdir(fd))!=NULL){
            if(!((strcmp(entry->d_name,".")==0)||(strcmp(entry->d_name,"..")==0))){
                if(stat(entry->d_name,&st)==0){
                    strcpy(files[cnt].name,entry->d_name);
                    files[cnt].size=entry->d_type;
                    cnt++;
                }
            }
        }
        sort(files,cnt);
        for(int i=0;i<cnt;i++){
            stat(files[i].name,&st);
            if(S_ISDIR(st.st_mode))
                printf("\033[1;34m%s\033[0m  ",files[i].name);//blue dir
            else if(st.st_mode & S_IXUSR)
                printf("\033[1;32m%s\033[0m  ",files[i].name);//green exe
            else
                printf("%s  ",files[i].name);//default regular
        }
        printf("\n");
    }
    //ls -i
    else if((argc==2)&&(strcmp("-i",argv[1])==0)){
        while((entry=readdir(fd))!=NULL){
            printf("%lu %s   ",entry->d_ino,entry->d_name);
        }
        printf("\n");
    }
    //ls -a
    else if((argc==2)&&(strcmp("-a",argv[1])==0)){
        while((entry=readdir(fd))!=NULL){
            if(entry->d_name[0]=='.'){
                printf("%s  ",entry->d_name);
            }
        }
        printf("\n");
    }
    //ls -S
    else if((argc==2)&&(strcmp("-S",argv[1])==0)){
        while((entry=readdir(fd))!=NULL){
            if(entry->d_name[0]=='.'){
                continue;//skip hidden files
            }
            if(stat(entry->d_name,&st)==0){
                strcpy(files[cnt].name,entry->d_name);
                files[cnt].size=st.st_size;
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            printf("%s  ",files[i].name);
        }
        printf("\n");
    }
    //ls -t
    else if((argc==2)&&(strcmp("-t",argv[1])==0)){
        //sort by time
    }
    //ls -l
    else if((argc==2)&&(strcmp("-l",argv[1])==0)){
        long total=0;
        while((entry=readdir(fd))!=NULL){
            int flag=0;
            if((stat(entry->d_name,&st)==0)&&(entry->d_name[0]!='.')){//'.' → hidden files
                flag=1;
                //total += st.st_blocks;
                //printf("total=%ld\n",total/2);
                if(S_ISDIR(st.st_mode)){
                    printf("d");
                }else if(S_ISLNK(st.st_mode)){
                    printf("l");
                }else{
                    printf("-");
                }
                //owner
                printf((st.st_mode & S_IRUSR)?"r":"-");
                printf((st.st_mode & S_IWUSR)?"w":"-");
                printf((st.st_mode & S_IXUSR)?"x":"-");
                //group
                printf((st.st_mode & S_IRGRP)?"r":"-");
                printf((st.st_mode & S_IWGRP)?"w":"-");
                printf((st.st_mode & S_IXGRP)?"x":"-");
                //others
                printf((st.st_mode & S_IROTH)?"r":"-");
                printf((st.st_mode & S_IWOTH)?"w":"-");
                printf((st.st_mode & S_IXOTH)?"x":"-");

                printf("  %lu",st.st_nlink);
                //user & group
                struct passwd *pw = getpwuid(st.st_uid);
                struct group *gr = getgrgid(st.st_gid);

                printf("  %s",pw->pw_name);
                printf("  %s",gr->gr_name);
                printf("  %lu",st.st_size);

                char timebuf[80];
                struct tm *tm_info;
                tm_info = localtime(&st.st_mtime);
                strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", tm_info);
                printf("  %s", timebuf);

                if(S_ISDIR(st.st_mode))
                    printf("  \033[1;34m%s\033[0m  ",entry->d_name);//blue dir
                else if(st.st_mode &S_IXUSR)
                    printf("  \033[1;32m%s\033[0m  ",entry->d_name);//green exe
                else
                    printf("  %s",entry->d_name);//default regular
            }
            if(flag) printf("\n");
        }
    }
    closedir(fd);
    return 0;
}

