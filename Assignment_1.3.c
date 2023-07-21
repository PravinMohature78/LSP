#include<stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Fname[20];
    char Mode[10];

    printf("Enter the file name you want to open : \n");
    scanf("%s",Fname);
    printf("Enter the mode in which you want to open the file (ex. O_RDONLY, O_WRONLY, O_RDWR) : \n");
    scanf("%s",Mode);

    int flags = 0;

    if (strcmp(Mode, "O_RDONLY") == 0) {
        flags = O_RDONLY;
    } else if (strcmp(Mode, "O_WRONLY") == 0) {
        flags = O_WRONLY;
    } else if (strcmp(Mode, "O_RDWR") == 0) {
        flags = O_RDWR;
    } else {
        printf("Invalid mode specified.\n");
        return -1;
    }

    if (access(Fname, flags) == 0) {
        printf("File is accessible with Mode : %s.\n",Mode);
    } else {
        printf("File cannot be accessed with Mode : %s.\n",Mode);
        return -1 ;
    }

    fd = open(Fname,flags);

    if(fd == -1){
        printf("Entered file name can not be opened \n");
        return -1;
    }

    printf("File is succssfully opened with fd : %d and mode is %s", fd, Mode);
    return 0;

}