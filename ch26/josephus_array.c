#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BOOL

#define BOOL    int
#define TRUE    1
#define FALSE   0

#endif


void print_array(int *pa, int count){
    for(int i=0; i<count; i++){
        printf("%d, ", pa[i]);
    }
    printf("\n");
}

void Josephus(int m, int n){

    int *pa = malloc(sizeof(int)*m);
    memset(pa, 0, sizeof(int)*m);

    int counter = 0;
    int find_kill = FALSE;
    for (int i=0; ; i++, i=i%m){
        if (i == 0){
            find_kill = FALSE;
        }

        if (pa[i] == 0){
            counter++;
        }

        if(counter == n){
            find_kill = TRUE;
            pa[i] = 1;
            counter = 0;

            print_array(pa, m);
        }

        //遍历到尾部计数器还没找到要杀死的人
        if (i==m-1 && find_kill==FALSE){
            break;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 3){
        perror("m, n must specified");
        exit(0);
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    Josephus(m, n);
    return 0;
}
