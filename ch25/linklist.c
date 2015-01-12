#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"

linklist* create_linklist(unsigned typesize){
    linklist *list = malloc(sizeof(linklist));
    if (list == NULL){
        perror("mem overflow");
        return list;
    }

    list->header = NULL;
    list->typesize = typesize;

    return list;
}


void destory_linklist(linklist *l, destory_pelem dp){
    node_st *p = l->header;
    while (p!=NULL){
        node_st *tp = p;
        p = p->next;
        dp(tp->pelem);
        free(tp);
    }

    free(l);
}

BOOL empty_linklist(linklist *l){
    return l->header == NULL;
}

//insert elem at tail
void insert_linklist(linklist *l, void *elem){

    node_st **pnode = &l->header;

    while(*pnode != NULL){
        pnode = &(*pnode)->next;
    }

    node_st *new_node = malloc(sizeof(node_st));

    new_node->pelem = malloc(l->typesize);
    memcpy(new_node->pelem, elem, l->typesize);

    new_node->next = NULL;

    *pnode = new_node;
}

void print_linklist(linklist *l, visit_func visit){
    node_st *p = l->header;

    while (p!=NULL){
        visit(p);
        p = p->next;
    }
}


