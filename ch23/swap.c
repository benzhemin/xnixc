#include <stdio.h>

void swap(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main(void){
    int i=10, j=20;
    swap(&i, &j);
    printf("now i=%d j=%d\n", i, j);

    return 0;
}
