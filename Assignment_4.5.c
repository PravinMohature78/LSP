#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_CONTENT_LEN 20

int main(int argc, char *argv[])
{
    char DirName[20];
    char name[50];
    int fd = 0;
    int position  = 0;
    char content[MAX_CONTENT_LEN + 1];

    printf("Name of Directory : \n");
    scanf("%s", DirName);
    printf("Enter the position to read from: \n");
    scanf("%d", &position);
    fd = open("Demo.txt",O_RDONLY);;

    if(fd == -1){
        printf("Unable to open the file \n"); 
        return -1;
    }
        
    off_t offset = lseek(fd, position, SEEK_SET);

    if(offset == -1)
    {
        printf("Error Seeking the file \n");
        close(fd);
        return -1;
    }
    ssize_t bytes_read = read(fd, content, MAX_CONTENT_LEN);
    if (bytes_read == -1)
    {
        printf("Error reading from the file\n");
    }
    content[bytes_read] = '\0';
    printf("Data read from the file at position %d: %s\n", position, content);
    return 0;
}