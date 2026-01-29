#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<time.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
//./myls -l
int main(int argc,char *argv[]){
    DIR *fd;
    struct dirent *entry;
    struct stat st;
    fd=opendir(".");
    if(fd==NULL){
        perror("opendir");
        return 0;
    }
    if(argc==1){
        while((entry=readdir(fd))!=NULL){
            stat(entry->d_name,&st);
            if(S_ISDIR(st.st_mode))
                printf("\033[1;34m%s\033[0m  ",entry->d_name);//blue dir
            else if(st.st_mode &&S_IXUSR)
                printf("\033[1;32m%s\033[0m  ",entry->d_name);//green exe
            else
                printf("%s  ",entry->d_name);//default regular
        }
        printf("\n");
    }else if((argc==2)&&(strcmp("-i",argv[1])==0)){
        while((entry=readdir(fd))!=NULL){
            printf("%lu %s   ",entry->d_ino,entry->d_name);
        }
        printf("\n");
    }else if((argc==2)&&(strcmp("-a",argv[1])==0)){
        while((entry=readdir(fd))!=NULL){
            if(entry->d_name[0]=='.'){
                printf("%s  ",entry->d_name);
            }
        }
        printf("\n");
    }else if((argc==2)&&(strcmp("-l",argv[1])==0)){
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