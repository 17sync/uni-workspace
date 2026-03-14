#include <stdio.h>      // writer
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    int fd;
    char buffer[1024];

    if(mkfifo("myfifo.txt", 0666)<0){
        perror("failed to create fifo");
        exit(1);
    }

    fd=open("myfifo.txt", O_WRONLY);
    if(fd<0){
        perror("open");
        exit(1);
    }

    while(1){
        if(fgets(buffer, sizeof(buffer), stdin)==NULL) break;

        if(buffer[0]=='e' && buffer[1]=='x'&&buffer[2]=='i'&&buffer[3]=='t') break;

        if(write(fd, buffer, sizeof(buffer))<0){
            perror("failed to write to fifo");
            close(fd);
            exit(1);
        }
    }
    close(fd);

    return 0;
}