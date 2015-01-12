#ifndef _QUEUE_H
#define _QUEUE_H

#define BOOL    int
#define TRUE    1
#define FALSE   0

#define QUEUE_MAX_SIZE 20

typedef struct{
    void *base;
    unsigned type_size;
    unsigned front;
    unsigned rear;
}SqQueue;

void init_sequeue(SqQueue *Q, unsigned type_size);
void destory_sequeue(SqQueue *Q);

BOOL queue_empty(SqQueue *Q);

BOOL enqueue(SqQueue *Q, void *elem);

BOOL dequeue(SqQueue *Q, void *pelem);



#endif
