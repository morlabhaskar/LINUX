// struct stat {
//     dev_t     st_dev;     /* ID of device containing file */
//     ino_t     st_ino;     /* inode number */
//     mode_t    st_mode;    /* protection */
//     nlink_t   st_nlink;   /* number of hard links */
//     uid_t     st_uid;     /* user ID of owner */
//     gid_t     st_gid;     /* group ID of owner */
//     dev_t     st_rdev;    /* device ID (if special file) */
//     off_t     st_size;    /* total size, in bytes */
//     blksize_t st_blksize; /* blocksize for filesystem I/O */
//     blkcnt_t  st_blocks;  /* number of blocks allocated */
//     time_t    st_atime;   /* time of last access */
//     time_t    st_mtime;   /* time of last modification */
//     time_t    st_ctime;   /* time of last status change */
// };
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc,char *argv[]){
        struct stat v;
        if(argc<2){
                printf("Usage : %s <filename>\n",argv[0]);
                exit(1);
        }
        if(stat(argv[1],&v)==-1){//stat return -1 if fail otherwise 0 for success
                perror("Stat");
                exit(1);
        }
        printf("File: %s\n",argv[1]);
        //file type
        if(S_ISREG(v.st_mode)) printf("Regular file\n");
        else if(S_ISDIR(v.st_mode)) printf("Directory\n");
        else if(S_ISCHR(v.st_mode)) printf("Character device\n");
        else if(S_ISBLK(v.st_mode)) printf("Block device\n");
        else if(S_ISFIFO(v.st_mode)) printf("FIFO/pipe\n");
        else if(S_ISLNK(v.st_mode)) printf("Symbolic link\n");
        else if(S_ISSOCK(v.st_mode)) printf("Socket\n");

        printf("Inode number           : %lu\n",v.st_ino);
        printf("Number of links        : %lu\n",v.st_nlink);
        printf("Owner UID              : %u\n",v.st_uid);
        printf("Owner GID              : %u\n",v.st_gid);
        printf("File Size              : %lu\n",v.st_size);
        printf("Block Size             : %lu\n",v.st_blksize);
        printf("Blocks allocated       : %lu\n",v.st_blocks);

        //permissions
        printf("Permissions :\n");
        printf((v.st_mode & S_IRUSR) ? "r" : "-");
        printf((v.st_mode & S_IWUSR) ? "w" : "-");
        printf((v.st_mode & S_IXUSR) ? "x" : "-");
        printf((v.st_mode & S_IRGRP) ? "r" : "-");
        printf((v.st_mode & S_IWGRP) ? "w" : "-");
        printf((v.st_mode & S_IXGRP) ? "x" : "-");
        printf((v.st_mode & S_IROTH) ? "r" : "-");
        printf((v.st_mode & S_IWOTH) ? "w" : "-");
        printf((v.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");

        //Time information
        printf("Last access time   : %s",ctime(&v.st_atime));
        printf("Last modify time   : %s",ctime(&v.st_mtime));
        printf("Last status change : %s",ctime(&v.st_ctime));

        return 0;
}
