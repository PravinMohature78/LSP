#include<stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{
    int fd = 0;
    char Fname[20];
    char Mode[10];
    int flag = 0;

    printf("Enter the file name you want to open : \n");
    scanf("%s",Fname);
    printf("Enter the mode in which you want to open the file (ex. O_RDONLY, O_WRONLY, O_RDWR) : \n");
    scanf("%9s",Mode);

    flag = atoi(Mode);

    fd = open(Fname,flag);

    if(fd == -1){
        printf("Entered file name can not be opened \n");
        return -1;
    }

    printf("File is succssfully opened with fd : %d and mode is %s", fd, Mode);
    return 0;

}