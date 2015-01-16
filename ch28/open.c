#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

int main(void){
    char buf[] = "hello\n";

    int fd = open("aka.txt", O_WRONLY|O_EXCL|O_CREAT, 0644);
    if (fd < 0){
        perror("open error");
        exit(0);
    }
    write(fd, buf, sizeof(buf)/sizeof(buf[0]));

    close(fd);

    return 0;
}
