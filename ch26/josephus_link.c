//
//  Josephus.c
//  xnixc
//
//  Created by peer on 1/13/15.
//  Copyright (c) 2015 peer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "db_linklist.h"

//return delete res
BOOL db_linklist_delete(db_linklist *L, db_node_st *pdel){
    BOOL del_res = FALSE;

    if (pdel == NULL || db_linklist_empty(L)){
        return del_res;
    }

    db_node_st *pre = NULL;
    db_node_st *p = L->header;

    while (p != NULL){

        if (p == pdel){
            if (pre){
                pre->next = p->next;
                if (p->next){
                    p->next->prev = pre;
                }else{
                    L->tail = pre;
                }
                free(p);
            }
            //del header
            else{

                L->header = p->next;
                if (p->next){
                    p->next->prev = NULL;
                }else{
                    L->tail = L->header;
                }
            }

            L->list_len--;
            del_res = TRUE;
            break;
        }

        pre = p;
        p = p->next;
    }

    return del_res;
}

void Josephus(db_linklist *L, int n){

    unsigned counter = 0;

    db_node_st *p = L->header;
    while (db_linklist_length(L) >= n) {

        if (counter == n){
            db_node_st *tp = p;

            if (p->next == NULL){
                p = L->header;
            }else{
                p = p->next;
            }

            db_linklist_delete(L, tp);
            counter = 0;

            continue;
        }

        counter++;
        if (p->next == NULL){
            p = L->header;
        }else{
            p = p->next;
        }
    }
}

void visit(void *pn){
    db_node_st *p = pn;
    int *pelem = p->pelem;
    if (p->next == NULL){
        printf("%d\n", *pelem);
    }else{
        printf("%d, ", *pelem);
    }
}

int main(int argc, char *argv[]){

    if (argc != 3) {
        perror("m, n must be specified");
        exit(0);
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    db_linklist *L = db_linklist_create(sizeof(int));

    for (int i=1; i<=m; i++) {
        db_linklist_insert(L, &i);
    }

    Josephus(L, n);

    db_linklist_print(L, visit);

    return 0;
}




