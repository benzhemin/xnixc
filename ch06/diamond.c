#include <stdio.h>

void print_diamond(int lines, char symbol){
    if(lines%2 == 0)
        printf("lines can not be even");

    int count = 0;
    int step = 1;
    int mid = lines/2;
    for(int i=0; i<lines; i++){
        for(int j=0; j<lines; j++){
            if(j>=(mid-count) && j<=(mid+count))
                printf("%c", symbol);
            else
                printf(" ");
        }
        printf("\n");

        if(i == mid)
            step = step*-1;
        count = count+step;
    }
    printf("\n");
}

int main(void){
    print_diamond(1, '*');
    print_diamond(3, '*');
    print_diamond(5, '+');

    return 0;
}
