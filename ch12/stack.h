#ifndef _STACK_H_
#define _STACK_H_

#ifndef BOOL
#define BOOL    int
#define TRUE    1
#define FALSE   0
#endif

#define STACK_SIZE 100
#define STACK_INCREMENT 10

typedef struct {
    void *base;
    void *top;
    unsigned type_size;
    unsigned stack_size;
} SqStack;

void init_stack(SqStack *ps, unsigned type_size);

BOOL stack_empty(SqStack *ps);

void push(SqStack *ps, void *elem);

BOOL pop(SqStack *ps, void *pelem);

BOOL get_top(SqStack *ps, void *pelem);

#endif
