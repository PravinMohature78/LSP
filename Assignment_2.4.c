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
    printf("Given Directory Name : %s \n ",argv[1]);
    printf("--------------------------------------------------------\n");
    printf("File Name             ***  File Type\n ");
    printf("--------------------------------------------------------\n");
    while ((entry = readdir(dp))!= NULL)
    {
        printf("%20s  ***  %hhu\n",entry->d_name , entry->d_type);
    }
    closedir(dp);
    return 0;
}