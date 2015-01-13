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

void Josephus(db_linklist *L, int n){
    
    unsigned counter = 1;
    
    db_node_st *p = L->header;
    while (db_linklist_length(L) >= n) {
        
        
        
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
    
    return 0;
}