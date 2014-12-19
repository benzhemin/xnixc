#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init_stack(SqStack *ps, unsigned type_size){
    ps->type_size = type_size;
    ps->top = ps->base = malloc(STACK_SIZE*type_size);
    if(ps->base == NULL){
        perror("malloc stack encounter error!");
    }
    ps->stack_size = STACK_SIZE;
}

BOOL stack_empty(SqStack *ps){
    if(ps->top == ps->base){
        return TRUE;
    }
    return FALSE;
}

void push(SqStack *ps, void *elem){
    unsigned type_size = ps->type_size;
    unsigned stack_size = ps->stack_size;
    char *top = ps->top;
    char *base = ps->base;

    if((top-base)/type_size >= stack_size){
        base = ps->base = realloc(base, (stack_size+STACK_INCREMENT)*type_size);
        ps->stack_size += STACK_INCREMENT;
        top = ps->top = (char *)ps->base+ps->stack_size*type_size;
    }

    memcpy(top, elem, type_size);
    ps->top = top + type_size;
}

BOOL pop(SqStack *ps, void *pelem){
    if(stack_empty(ps)){
        return FALSE;
    }

    char *top_elem = (char *)ps->top - ps->type_size;
    if(pelem != NULL){
        memcpy(pelem, top_elem, ps->type_size);
    }
    ps->top = (char *)ps->top - ps->type_size;

    return TRUE;
}

BOOL get_top(SqStack *ps, void *pelem){
    if(stack_empty(ps)){
        return FALSE;
    }

    char *top_elem = (char *)ps->top - ps->type_size;
    memcpy(pelem, top_elem, ps->type_size);

    return TRUE;
}


