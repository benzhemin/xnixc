#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void){
    FILE *fp = fopen(".", "w");
    if(fp == NULL){
        perror("Open /etc/shadow");
        printf("errno: %d\n", errno);
        exit(1);
    }

    return 0;
}
