#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#ifndef BOOL
#define BOOL    int

#define TRUE    1
#define FALSE   0

#endif

typedef struct _node{
    struct _node *next;
    void *pelem;
} node_st;

typedef struct {
    node_st *header;
    unsigned typesize;
}linklist;

typedef void (*visit_func)(node_st *node);

linklist* create_linklist(unsigned typesize);

void destory_linklist(linklist *l);

BOOL empty_linklist(linklist *l);

//insert elem at tail
void insert_linklist(linklist *l, void *elem);

void print_linklist(linklist *l, visit_func visit);


#endif
