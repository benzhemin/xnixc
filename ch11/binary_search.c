#include <stdio.h>

#define LEN 8
int a[LEN] = {1, 2, 2, 2, 5, 6, 8, 9};

int binarysearch(int number){
    int mid, start=0, end=LEN-1;
    int find = -1;

    while(start < end){
        mid = (start+end)/2;
        if(a[mid] > number){
            end = mid-1;
        }else if(a[mid] < number){
            start = mid+1;
        }else{
            find = mid;
            end = mid-1;
        }
    }
    return find;
}

int main(void){
    int find = binarysearch(2);
    printf("find = %d\n", find);
    if (find != -1) {
        printf("res=%d\n", a[find]);
    }

    return 0;
}
