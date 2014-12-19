#include <stdio.h>

double power(double x, int n){
    if(n == 1) return x;

    if(n == 2){
        return x*x;
    }else{
        int flag = n%2;

        double low = power(x, n/2);
        double res = low*low;

        if(flag){
            res = res * x;
        }

        return res;
    }
}

double power_loop(double x, int n){
    int flag = (x>1) && (n%2);
    int step = 1;

    double ac = x;
    while(step*2 < n){
        ac = ac * ac;
        step = step*2;
    }

    if(flag){
        ac = ac * x;
    }
    return ac;
}

int main(void){
    double res = power_loop(2, 9);
    printf("res=%.0f\n", res);

    return 0;
}
