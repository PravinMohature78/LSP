#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fd = 0;
    int fdDest = 0;
    char Buffer[BLOCKSIZE];
    int ret = 0;
    
    if(argc != 3){
        printf("Insufficient Arguments \n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to opned file \n");
        return -1;
    }

    fdDest = creat(argv[2], 0777);
    if(fdDest == -1)
    {
        printf("Unable to crete the file on Destination\n");
        close(fdDest);
        return -1;
    }

    while ((ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        write(fdDest, Buffer, ret);
        memset(Buffer, 0, sizeof(Buffer));
    }
    
    close(fd);
    close(fdDest);
    return 0;
}