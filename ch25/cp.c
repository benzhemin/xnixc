#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("input file and out file must be specified\n");
        exit(0);
    }

    FILE *rd = fopen(argv[1], "r");
    if(rd == NULL){
        perror("Open file\n");
        exit(1);
    }

    FILE *wt = fopen(argv[2], "w");
    if(wt == NULL){
        perror("Open file\n");
        exit(1);
    }

    int ch;
    while((ch=fgetc(rd))!=EOF){
        fputc(ch, wt);
    }

    fclose(rd);
    fclose(wt);
    return 0;
}
