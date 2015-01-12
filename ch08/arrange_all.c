#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))
int a[] = {1, 2, 3, 4};
int len = ARRAY_LEN(a);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_all(){
    for(int i=0; i<len; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void arrange_all(int start){
    if(start < len){
        for(int i=start; i<len; i++){
            swap(a+start, a+i);
/*
            int *buff = (int *)malloc(sizeof(int)*len);
            memcpy(buff, a, sizeof(int)*len);
*/
            arrange_all(start+1);

            swap(a+start, a+i);
            /*
            memcpy(a, buff, sizeof(int)*len);
            free(buff);
            */
        }
    }else{
        print_all();
    }
}

int main(void){
    arrange_all(0);

    return 0;
}
