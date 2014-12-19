#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

void print_all(int *array, int len){
    for(int i=0; i<len; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int len){
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(array[j]<array[i]){
                swap(array+j, array+i);
            }
        }
    }
}

int main(void){
    int a[] = {10, 2, 8, 5, 3, 0, 4, 7};

    print_all(a, ARRAY_LEN(a));
    bubble_sort(a, ARRAY_LEN(a));
    print_all(a, ARRAY_LEN(a));

    return 0;
}
