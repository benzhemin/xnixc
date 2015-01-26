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

void destory_rd(void *pelem){
    record_st *p = pelem;

    free(p->date);
    free(p->time);
    free(p);
}

void parse_log(db_linklist *L, char *file_name){
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL){
        perror("open file error");
        exit(0);
    }

    char buf[512];
    while(fgets(buf, sizeof(buf), fp)!=NULL){

        char *p_newline = strchr(buf, '\n');
        if (p_newline != NULL){
            *p_newline = '\0';
        }

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

int cmp_record(db_node_st *pa, db_node_st *pb){
    record_st *pa_rd = pa->pelem;
    record_st *pb_rd = pb->pelem;

    int res = strcmp(pa_rd->time, pb_rd->time);

    if (res == 0){
        res = strcmp(pa_rd->date, pb_rd->date);
    }

    return res;
}

//insertion sort
//double link easy to maintain
void sort_records(db_linklist *L){

    db_node_st *pn = L->header;

    while (pn != NULL){

        db_node_st *p = L->header;
        while(p!=pn){
            if(cmp_record(pn, p) < 0){

                //del pn
                pn->prev->next = pn->next;
                if (pn->next){
                    pn->next->prev = pn->prev;
                }else{
                    L->tail = pn->prev;
                }

                if (p == L->header){
                    pn->next = p;
                    p->prev = pn;
                    L->header = pn;
                }else{
                    p->prev->next = pn;
                    pn->next = p;
                    p->prev = pn;
                }
                break;
            }
            p = p->next;
        }

        pn = pn->next;

    }
}

void visit(db_node_st *p){
    record_st *pe = p->pelem;
    printf("%s, %s\n", pe->date, pe->time);

    record_st *p_rd = p->pelem;

    printf("%s %s\n", p_rd->date, p_rd->time);
}

void write_back(db_linklist *L, char *log_file){
    FILE *fp = fopen(log_file, "w");
    if (fp == NULL){
        perror("open log_file error");
    }

    db_node_st *p = L->header;

    char buf[256] = {0};
    int seq = 1;
    while(p != NULL){
        record_st *p_rd = p->pelem;

        sprintf(buf, "%d %s %s\n", seq, p_rd->date, p_rd->time);
        fputs(buf, fp);

        p = p->next;
        seq++;
    }

    fclose(fp);
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

    db_linklist_print(L, visit);

    write_back(L, log_file);

    db_linklist_destory(L, destory_rd);

    return 0;
}
