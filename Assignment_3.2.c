#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct direct *entry = NULL;
    char path[50] = {'\0'};
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directoty \n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(argv[2], entry->d_name)) == 0)
        {
            printf("File is present in the directory \n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file \n");
        return -1;
    }
    closedir(dp);
    return 0;
}