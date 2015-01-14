#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db_linklist.h"

typedef struct{
    char *date;
    char *time;
} record_st;

void crcp_str(char **dst, char *src){
    if (src == NULL){
        return;
    }

    char *new_str = malloc(strlen(src)+1);
    strcpy(new_str, src);

    *dst = new_str;
}

void parse_log(db_linklist *L, char *file_name){
    FILE *fp = fopen(file_name, "w+");
    if (fp == NULL){
        perror("open file error");
        exit(0);
    }

    char buf[512];
    while(fgets(buf, sizeof(buf), fp)!=NULL){

        char *space_split_svptr;

        strtok_r(buf, " ", &space_split_svptr);

        char *date = strtok_r(NULL, " ", &space_split_svptr);
        char *time = strtok_r(NULL, " ", &space_split_svptr);

        record_st *rd = malloc(sizeof(record_st));
        crcp_str(&rd->date, date);
        crcp_str(&rd->time, time);

        db_linklist_insert(L, rd);
    }

    fclose(fp);
}

void sort_records(db_linklist *L){

}

int main(int argc, char *argv[]){
    if (argc < 2){
        perror("log file must specified!");
        exit(0);
    }
    char *log_file = argv[1];

    db_linklist *L = db_linklist_create(sizeof(record_st));

    parse_log(L, log_file);

    sort_records(L);

    return 0;
}
