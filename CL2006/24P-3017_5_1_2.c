#include <stdio.h>      // reader
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    int fd,n;
    char buffer[1024];

    if(mkfifo("myfifo.txt", 0666)<0){
        perror("failed to create fifo");
        exit(1);
    }

    fd=open("myfifo.txt", O_RDONLY);
    if(fd<0){
        perror("open");
        exit(1);
    }

    while((n=read(fd, buffer, sizeof(buffer)))>0){
        if(write(1, buffer, n)<0){
            perror("failed to write to stdout");
            close(fd);
            exit(1);
        }
    }
    close(fd);
    
    return 0;
}