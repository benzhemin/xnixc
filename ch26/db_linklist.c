//
//  db_linklist.c
//  xnixc
//
//  Created by peer on 1/13/15.
//  Copyright (c) 2015 peer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db_linklist.h"

db_linklist* db_linklist_create(unsigned typesize){
    db_linklist *L= malloc(sizeof(db_linklist));

    L->header = L->tail = NULL;
    L->typesize = typesize;
    L->list_len = 0;

    return L;
}

void db_linklist_destory(db_linklist *L, destory_func destory){

    db_node_st *p = L->header;

    while (p != NULL) {
        db_node_st *tp = p;
        p = p->next;

        destory(tp->pelem);
        free(tp);
    }

    free(L);
}

void db_linklist_insert(db_linklist *L, void *pelem){

    db_node_st *new_st = malloc(sizeof(db_node_st));

    new_st->pelem = malloc(sizeof(L->typesize));
    memcpy(new_st->pelem, pelem, L->typesize);

    new_st->next = NULL;
    new_st->prev = NULL;

    if (db_linklist_empty(L)){

        L->header = L->tail = new_st;

    }else{

        L->tail->next = new_st;
        new_st->prev = L->tail;

        L->tail = new_st;
    }
    L->list_len++;
}

BOOL db_linklist_empty(db_linklist *L){
    if (L->header==L->tail && L->header==NULL) {
        return TRUE;
    }
    return FALSE;
}

void db_linklist_print(db_linklist *L, visit_func visit){

    db_node_st *p = L->header;

    while (p != NULL) {
        visit(p);

        p = p->next;
    }
}

size_t db_linklist_length(db_linklist *L){

    return L->list_len;

    /*
    size_t len = 0;

    db_node_st *p = L->header;

    while (p != NULL) {
        ++len;
        p = p->next;
    }

    return len;
    */
}

