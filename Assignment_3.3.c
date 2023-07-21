#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/dir.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct direct *entry = NULL;
    char olddir[50];
    char newdir[50];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open the directoty \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(olddir,"%s/%s", argv[1], entry->d_name);
        sprintf(newdir,"%s/%s", argv[2], entry->d_name);
        rename(olddir,newdir);
    }

    closedir(dp);
    return 0;
}