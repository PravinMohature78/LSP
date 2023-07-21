#include<stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalide Number of Argument \n");
        return -1;
    }

    fd = open(argv[1], O_RDWR);

    if(fd == -1){
        printf("Entered file name can not be opened \n");
        return -1;
    }

    printf("File is succssfully opened with fd : %d", fd);
    return 0;

}