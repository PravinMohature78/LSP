#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[BLOCKSIZE];
    int ret = 0;
    
    if(argc != 2){
        printf("Insufficient Arguments \n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to opned file \n");
        return -1;
    }

    while ((ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        write(1, Buffer, ret);
    }
    
    close(fd);
    return 0;
}