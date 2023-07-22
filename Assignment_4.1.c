#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char Arr[20];

    fd = open(argv[1], O_RDONLY);

    if(fd == -1){
        printf("Unable to open file \n");
        return -1;
    }



    close(fd);

    return 0;
    
}