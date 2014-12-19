#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))

void print_all(int *array, int len);

void insertion_sort(int *array, int length){
    for(int i=0; i<length; i++){
        int value = *(array+i);
        int j = i-1;
        while(j>=0 && value<array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = value;

        print_all(array, length);
    }
}

void print_all(int *array, int len){
    for(int i=0; i<len; i++){
        printf("%d, ", *(array+i));
    }
    printf("\n");
}

int main(void){
    int a[] = {2, 8, 5, 1, 9, 4};
    print_all(a, ARRAY_LEN(a));
    printf("\n");
    insertion_sort(a, ARRAY_LEN(a));
    printf("\n");
    print_all(a, ARRAY_LEN(a));

    return 0;
}
