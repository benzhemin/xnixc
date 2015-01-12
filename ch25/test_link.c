#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"

void visit(node_st *node){
    int *pe = node->pelem;

    if (node->next == NULL){
        printf("%d\n", *pe);
    }else{
        printf("%d,", *pe);
    }
}

int compare(void *a, void *b){
    int *pa = a;
    int *pb = b;

    if (*pa < *pb){
        return -1;
    }else if (*pa == *pb){
        return 0;
    }else{
        return 1;
    }
}

void list_insert_seq(linklist *L, void *pelem){

    node_st **pnode = &L->header;

    while(*pnode != NULL){
        if (compare((*pnode)->pelem, pelem) > 0)
            break;

        pnode = &(*pnode)->next;
    }

    node_st *new_node = malloc(sizeof(node_st));
    new_node->pelem = malloc(L->typesize);
    memcpy(new_node->pelem, pelem, L->typesize);
    new_node->next = NULL;

    new_node->next = *pnode;
    *pnode = new_node;
}

void list_reverse(linklist *L){
    node_st **pnode = &L->header;

    node_st *p = L->header;
    node_st *tp = NULL;

    while(p != NULL){
        node_st *cur = p;
        p = p->next;

        cur->next = tp;
        tp = cur;

        *pnode = cur;
    }
}

int main(void){

    int a[] = {2, 5, 3, 0, 8, 1};

    linklist *L = create_linklist(sizeof(int));

    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        list_insert_seq(L, a+i);
    }
    print_linklist(L, visit);

    list_reverse(L);

    print_linklist(L, visit);

    return 0;
}
