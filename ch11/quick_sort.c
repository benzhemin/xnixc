#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int pivot = begin;

    int pb = begin+1;
    int pe = end;

    while(pb <= pe){
        if(array[pivot] > array[pb]){
            swap(array+pivot, array+pb);
            pivot = pb; pb++;
            continue;
        }

        if(array[pivot] < array[pe]){
            pe--;
            continue;
        }

        swap(array+pb, array+pe);
    }

    return pivot;
}
void quick_sort(int *array, int begin, int end){
    if(begin < end){
        int mid = balance(array, begin, end);
        quick_sort(array, begin, mid-1);
        quick_sort(array, mid+1, end);
    }
}

int main(void){
    int a[] = {5, 1, 2, 6, 4, 3, 9, 8};
    print_all(a, ARRAY_LEN(a));
    quick_sort(a, 0, ARRAY_LEN(a)-1);
    print_all(a, ARRAY_LEN(a));

    return 0;
}





