#include <stdio.h>
#include <stdlib.h>

#define N 20

int a[N] = {0};

void gen_random(int upper_bound){
    for(int i=0; i<N; i++){
        int rand_num = rand() % upper_bound;
        a[rand_num]++;
    }
}

void print_all(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(i==0){
                printf("%d ", j);
            }else{
                if(a[j] > 0){
                    printf("%c ", '*');
                    a[j]--;
                }
            }
        }
        printf("\n");
    }
}

int main(void){
    gen_random(10);
    print_all();

    return 0;
}

