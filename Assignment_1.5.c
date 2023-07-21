#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    char *Buffer = NULL;
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

    Buffer = (char *)malloc(sizeof(atoi(argv[2])));

    if (Buffer == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    ret = read(fd,Buffer,atoi(argv[2]));

    if(ret==0)
    {
        printf("Unable to read data from file \n");
        return -1;
    }

    printf("Data from file is : %s\n", Buffer);
    return 0;
}