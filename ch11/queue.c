#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void init_sequeue(SqQueue *Q, unsigned type_size){
    Q->type_size = type_size;
    Q->base = malloc(type_size * QUEUE_MAX_SIZE);
    Q->front = Q->rear = 0;
}

void destory_sequeue(SqQueue *Q){
    free(Q->base);
}

BOOL queue_empty(SqQueue *Q){
    return Q->front == Q->rear;
}

BOOL enqueue(SqQueue *Q, void *elem){
    unsigned step = Q->type_size;
    unsigned rear = Q->rear;
    char *base = Q->base;

    if((Q->rear+1)%QUEUE_MAX_SIZE == Q->front){
        perror("queue full");
        return FALSE;
    }

    memcpy(base+rear*step, elem, step);
    Q->rear = (Q->rear+1)%QUEUE_MAX_SIZE;

    return TRUE;
}

BOOL dequeue(SqQueue *Q, void *pelem){
    char *base = Q->base;
    unsigned front = Q->front;
    unsigned step = Q->type_size;

    if(queue_empty(Q)){
        return FALSE;
    }
    memcpy(pelem, base+front*step, step);
    Q->front = (Q->front+1)%QUEUE_MAX_SIZE;

    return TRUE;    
}


