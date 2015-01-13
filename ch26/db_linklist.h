//
//  db_linklist.h
//  xnixc
//
//  Created by peer on 1/13/15.
//  Copyright (c) 2015 peer. All rights reserved.
//

#ifndef xnixc_db_linklist_h
#define xnixc_db_linklist_h

#ifndef BOOL

#define BOOL    int
#define TRUE    1
#define FALSE   0

#endif

typedef struct _db_node_st{
    struct _db_node_st *next;
    struct _db_node_st *prev;
    
    void *pelem;
} db_node_st;


typedef struct _db_linklist{
    db_node_st *header;
    db_node_st *tail;
    unsigned typesize;
} db_linklist;

typedef void (visit_func)(void *pelem);
typedef void (destory_func)(void *pelem);

db_linklist* db_linklist_create(unsigned typesize);

void db_linklist_destory(db_linklist *L, destory_func destory);

void db_linklist_insert(db_linklist *L, void *pelem);

BOOL db_linklist_empty(db_linklist *L);

void db_linklist_print(db_linklist *L, visit_func visit);

size_t db_linklist_length(db_linklist *L);


#endif
