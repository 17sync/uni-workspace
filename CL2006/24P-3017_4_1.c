#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main(){
    int src, dest;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    src=open("source.txt", O_RDONLY);
    if(src<0){
        perror("Error opening source file");
        exit(1);
    }

    dest=open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(dest<0){
        perror("Error opening destination file");
        close(src);
        exit(1);
    }

    while((bytesRead=read(src, buffer, BUFFER_SIZE))>0){
        bytesWritten=write(dest, buffer, bytesRead);
        if (bytesWritten!=bytesRead) {
            perror("Write error");
            close(src);
            close(dest);
            exit(1);
        }
    }

    if(bytesRead<0){
        perror("Read error");
    }

    close(src);
    close(dest);

    printf("File copied successfully.\n");
    
    return 0;
}

