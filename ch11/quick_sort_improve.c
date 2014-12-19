#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_all(int *array, int len){
    for(int i=0; i<len; i++){
        printf("%d, ", *(array+i));
    }
    printf("\n");
}

int balance(int *array, int begin, int end){
    int key = array[begin];

    while(begin < end){
        //from high to low
        while(begin<end && key<array[end])
            end--;

        array[begin] = array[end];

        //form low to high
        while(begin<end && key>array[begin])
            begin++;

        array[end] = array[begin];
     }
    array[begin] = key;

    return begin;
}

void quick_sort(int *array, int begin, int end){
    if(begin < end){
        int pivot = balance(array, begin, end);
        quick_sort(array, begin, pivot);
        quick_sort(array, pivot+1, end);
    }
}

int main(void){
    int a[] = {4, 9, 2, 6, 0, 5, 1, 7, 3};
    print_all(a, ARRAY_LEN(a));
    quick_sort(a, 0, ARRAY_LEN(a)-1);
    print_all(a, ARRAY_LEN(a));

    return 0;
}
