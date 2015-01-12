#include <stdio.h>

#define TRUE 1
#define FALSE 0

int fibonacci(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

int fibonacci_loop(int n){
    int a=1, b=1;
    if(n <= 1){
        return 1;
    }

    int flag = TRUE;
    int sum;
    for(int i=2; i<=n; i++){
        sum = a+b;
        if(flag){
            flag = FALSE;
            a = sum;
        }else{
            flag = TRUE;
            b = sum;
        }
    }
    return sum;
}

int main(void){
    int res = fibonacci(3);
    printf("%d\n", res);

    return 0;
}
