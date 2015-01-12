#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int greatest_divisor(int a, int b){
    if(a < b)
        swap(&a, &b);

    if(a%b == 0){
        return b;
    }else{
        return greatest_divisor(b, a%b);
    }
}

int greatest_divisor_loop(int a, int b){
    if(a < b)
        swap(&a, &b);

    while(a%b!=0){
        int temp_a = a;
        a = b;
        b = temp_a%b;
    }
    return b;
}

int main(void){
    int divisor = greatest_divisor_loop(16, 12);
    printf("greatest_divisor is %d\n", divisor);

    return 0;
}
