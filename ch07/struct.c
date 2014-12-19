#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    int b;
} typeA;

typedef struct{
    int m;
    int n;
    int test;
} typeB;

int main(void){
    typeA a = {3, 5};
    printf("%d, %d\n", a.a, a.b);

    typeB *pb = (typeB *)&a;
    printf("%d, %d\n", pb->m, pb->n);

    return 0;
}
