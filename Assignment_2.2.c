#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{

    int fd = 0;
    if(argc != 3)
    {
        printf("Insufficient Arguments \n");
        return -1;
    }

    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the  files \n");
        return -1;
    }

    if (write(fd, argv[2], strlen(argv[2])) == -1)
    {
        printf("Error writing to the file\n");
        close(fd);
        return -1;
    }

    close(fd);
    printf("Data has been written to the successfully.\n");

    return 0;
}
