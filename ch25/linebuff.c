#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("Hello World");
    fflush(stdout);

    while(1);

    //_exit(0);
}
