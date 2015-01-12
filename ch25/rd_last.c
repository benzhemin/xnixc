#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_last_line(){

    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL){
        perror("open fp error");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    long tail_off = ftell(fp);
    long cur_off = tail_off;


    int ch;
    int last_line = 0;
    while(cur_off > 0){
        cur_off--;

        fseek(fp, cur_off, SEEK_SET);

        ch = fgetc(fp);
        if (ch=='\n' && last_line){
            cur_off++;
            break;
        }else{
            if(ch == '\n'){
                last_line = 1;
            }
        }
    }

    fseek(fp, cur_off, SEEK_SET);

    char buf[256];
    fgets(buf, sizeof(buf), fp);

    fputs(buf, stdout);

    fclose(fp);
}

int main(void){

    read_last_line();

    return 0;
}
