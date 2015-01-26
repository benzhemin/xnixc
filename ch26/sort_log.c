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
    FILE *fp = fopen(file_name, "r");
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


int cmp_record(db_node_st *pa, db_node_st *pb){

    char *pa_time, *pb_time;

    crcp_str(&pa_time, ((record_st *)(pa->pelem))->time);
    crcp_str(&pb_time, ((record_st *)(pb->pelem))->time);

    char *pa_space_split_ptr = NULL;
    char *pb_space_split_ptr = NULL;

    int cmp_res = 0;
    for( ; ; pa_time=NULL, pb_time=NULL){

        char *pa_time_piece = strtok_r(pa_time, ":", &pa_space_split_ptr);
        char *pb_time_piece = strtok_r(pb_time, ":", &pb_space_split_ptr);

        if (pa_time_piece==NULL || pb_time_piece==NULL)
            break;

        cmp_res = strcmp(pa_time_piece, pb_time_piece);

        if (cmp_res != 0)
            break;

    }

    return cmp_res;
}

//insertion sort
//double link easy to maintain
void sort_records(db_linklist *L){

    db_node_st *pn = L->header;

    while (pn != NULL){

        db_node_st *p = L->header;
        while(p!=pn){
            if (cmp_record(pn, p) < 0){

                //del pn first
                pn->prev->next = pn->next;
                if (pn->next != NULL){
                    pn->next->prev = pn->prev;
                }else{
                    L->tail = pn->prev;
                }


                if (p == L->header){

                    pn->next = L->header;
                    pn->prev = NULL;

                    L->header->prev = pn;
                    L->header = pn;
                }else{

                    p->prev->next = pn;
                    pn->prev = p->prev;

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

    return 0;
}
