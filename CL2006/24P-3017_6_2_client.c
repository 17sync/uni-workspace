#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
    int fd1, fd2;
    char buffer[100];

    fd1=open("fifo1", O_RDONLY);
    read(fd1, buffer, sizeof(buffer));
    printf("Client received: %s\n", buffer);
    close(fd1);

    fd2=open("fifo2", O_WRONLY);
    write(fd2, "World" ,6);
    close(fd2);

    return 0;
}