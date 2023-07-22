#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

// Function to read and print the content of a file
void readAndPrintFileContent(const char *filename) {

}

int main(int argc, char *argv[]) {

    char buffer[BLOCKSIZE];
    struct dirent *entry;
    struct stat statbuf;
    char dirname[20];
    struct stat sobj;
    int ret = 0;
    int fd1 = 0;

    if (argc != 2) {
        printf("Insufficient arguments \n");
        return -1;
    }

    strcpy(dirname, argv[1]);

    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        printf("Unable to open directory: %s\n", dirname);
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filepath[256];
        sprintf(filepath, "%s/%s", dirname, entry->d_name);

        if (stat(filepath, &statbuf) == 0 && S_ISREG(statbuf.st_mode)) {
            stat(argv[1],&sobj);
            printf("File Name : %s\n",argv[1]);
            printf("File size is : %lld\n",sobj.st_size);
            printf("Number of Links : %d\n",sobj.st_nlink);
            printf("INODE number :%llu\n",sobj.st_ino);
            printf("FIle system numer :%d\n",sobj.st_dev);
            printf("Number of blocks : %lld\n",sobj.st_blocks);
            printf("Mode of file is : %d \n",sobj.st_mode);
            
            printf("Contents of the file %s:\n", entry->d_name);
            int fd1 = open(argv[1], O_RDONLY);
            while ((ret = read(fd1, buffer, sizeof(buffer))) != 0)
            {
                if (ret == -1)
                {
                    printf("Error while reading the file: %s\n", entry->d_name);
                    close(fd1);
                    break;
                }
                write(1, buffer, ret); 
            }
            close(fd1);
        }
    }

    closedir(dir);

    return 0;
}
