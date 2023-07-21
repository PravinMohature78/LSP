#include<stdio.h>
#include <fcntl.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    struct stat sobj;
    
    if(argc != 2){
        printf("Insufficient Arguments \n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File Name : %s\n",argv[1]);
    printf("File size is : %lld\n",sobj.st_size);
    printf("Number of Links : %d\n",sobj.st_nlink);
    printf("INODE number :%llu\n",sobj.st_ino);
    printf("FIle system numer :%d\n",sobj.st_dev);
    printf("Number of blocks : %lld\n",sobj.st_blocks);
    printf("Mode of file is : %d \n",sobj.st_mode);
    return 0;
}