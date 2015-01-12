#include <stdio.h>

int main(void){
    int count = 0;
    for(int i=0; i<=100; i++){
        int tp = i;
        while(tp!=0 &&tp%10==9){
            count++;
            tp = tp/10;
        }
    }

    printf("appears %d time\n", count);

    return 0;
}
