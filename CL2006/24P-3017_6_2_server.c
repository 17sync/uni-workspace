#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(){
    int fd1, fd2;
    char buffer[100];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    fd1=open("fifo1", O_WRONLY);
    write(fd1, "Hello", 6);
    close(fd1);

    fd2=open("fifo2", O_RDONLY);
    read(fd2, buffer, sizeof(buffer));
    printf("Server received: %s\n", buffer);
    close(fd2);

    return 0;
}