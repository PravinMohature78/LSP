#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


#define MAX_FILENAME_LEN 20
#define MAX_CONTENT_LEN 10


int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[50];
    struct stat sobj;
    int fd = 0;
    int fd1  = 0;
    char content[MAX_CONTENT_LEN + 1];

    printf("Name of Directory : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if (dp == NULL)     
    {
        printf("Unable ro open directory \n");
        return -1;
    }

    fd = open("Demo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);;

    if(fd == -1){
        printf("Unable to open the file \n");
        closedir(dp);
        return -1;
    }
    while((entry = readdir(dp)) != NULL)
    {
        
        if(entry->d_type == DT_REG){
            sprintf(name, "%s/%s",DirName, entry->d_name);
            fd1 = open(name, O_RDONLY);
            if (fd1 == -1)
            {
                printf("Unable to open file: %s\n", name);
                continue;
            }
            ssize_t bytes_read = read(fd1, content, MAX_CONTENT_LEN);
            close(fd1);
            if (bytes_read <= 0)
            {
                printf("Unable to read from file: %s\n", name);
                continue;
            }
            content[bytes_read] = '\0';
            write(fd,content,strlen(content));
        }
    }
    
    closedir(dp);
    return 0;
}