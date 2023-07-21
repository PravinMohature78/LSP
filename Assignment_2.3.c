#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    
    if(argc != 2){
        printf("Insufficient Arguments \n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Unable to open directory.\n");
        return -1;
    }
    
    printf("--------------------------------------------------------\n");
    printf("Given Directory Name : %s \n ",argv[1]);
    printf("--------------------------------------------------------\n");
    while ((entry = readdir(dp))!= NULL)
    {
        printf("%s \n",entry->d_name);
    }
    closedir(dp);
    return 0;
}