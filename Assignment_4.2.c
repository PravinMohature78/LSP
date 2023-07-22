#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    if(argc != 2){
        printf("Insufficient Arguments \n");
        return -1;
    }

    fd = mkdir(argv[1], 0777);
    if(fd != 0){
        printf("Error creating Directory. \n");
        return -1;
    }
    else
    {
        printf("New directory created successfully.\n");
    }


    return 0;
    
}