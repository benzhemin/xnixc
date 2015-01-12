#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))

void print_all(int *array, int len){
    for(int i=0; i<len; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    int *a = *b;
    *b = temp;
}

//insertion
int find_k_min(int *array, int len, int k){
    if(len < 2)
        return -1;

    int key0 = array[0];
    for(int i=1; i<len; i++){
        for(int j=1; j>=0; j--){
            if(array[i] > array[j]){
                break;
            }
        }
    }

}

int find_min(int *array, int len){
    int min = array[0];
    for(int i=1; i<len; i++){
        if(min > array[i]){
            min = array[i];
        }
    }
    return min;
}

int main(void){
    int a[] = {5, 9, 6, 2, 8, 3, 1};
    print_all(a, ARRAY_LEN(a));
    int min = find_min(a, ARRAY_LEN(a));
    printf("%d\n", min);

    return 0;
}
