#include <stdio.h>
#include <math.h>

double mysqrt(double y){
    double start=0, end=y, mid;
    while(start < end){
        mid = (start+end)/2;
        double diff = mid*mid - y;
        if(fabs(diff) < 0.001){
            return mid;
        }else if(diff > 0){
            end = mid;
        }else{
            start = mid;
        }
    }
    return -1;
}

int main(void){
    double res = mysqrt(5);
    printf("res=%f\n", res);

    return 0;
}
