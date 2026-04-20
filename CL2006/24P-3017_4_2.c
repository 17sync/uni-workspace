#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    char filename[50];
    char buffer[100];
    struct stat fileStat;

    for (int i=1;i<=5;i++){
        sprintf(filename, "temp%d.txt", i);

        int fd=open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd<0){
            perror("File creation failed");
            exit(0);
        }

        sprintf(buffer, "This is a temporary file %d\n", i);
        write(fd, buffer, strlen(buffer));
        close(fd);

        fd=open(filename, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("Content of %s: %s", filename, buffer);
        close(fd);

        stat(filename, &fileStat);
        printf("Size: %ld bytes, Permissions: %o\n", fileStat.st_size, fileStat.st_mode & 0777);

        unlink(filename);
        printf("%s deleted.\n\n", filename);
    }

    printf("All temporary files removed successfully.\n");
    
    return 0;
}

