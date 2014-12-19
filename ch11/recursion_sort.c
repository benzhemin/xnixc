#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))

void print_all(int *array, int len){
    for(int i=0; i<len; i++){
        printf("%d, ", *(array+i));
    }
    printf("\n");
}

void merge(int *array, int low, int mid, int high){
    int low_count = mid - low + 1;
    int high_count = high - mid;

    int *plow = (int *)malloc(sizeof(int)*low_count);
    int *phigh = (int *)malloc(sizeof(int)*high_count);

    memcpy(plow, (array+low), low_count*sizeof(int));
    memcpy(phigh, (array+mid+1), high_count*sizeof(int));

    int pl=0, ph=0;
    while(pl<low_count && ph<high_count){
        if(*(plow+pl) < *(phigh+ph)){
            *(array+low) = *(plow+pl);
            pl++;
        }else{
            *(array+low) = *(phigh+ph);
            ph++;
        }
        low++;
    }

    while(pl < low_count){
        *(array+low) = *(plow+pl);
        pl++; low++;
    }

    while(ph < high_count){
        *(array+low) = *(phigh+ph);
        ph++; low++;
    }

    free(plow);
    free(phigh);
}

void recursion_sort(int *array, int low, int high){
    int mid = (low+high)/2;
    if(low < high){
        recursion_sort(array, low, mid);
        recursion_sort(array, (mid+1), high);
        merge(array, low, mid, high);
    }
}

int main(void){
    int a[] = {8, 3, 9, 2, 6, 1, 1};
    print_all(a, ARRAY_LEN(a));
    recursion_sort(a, 0, ARRAY_LEN(a)-1);
    print_all(a, ARRAY_LEN(a));

    return 0;
}
