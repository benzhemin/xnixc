#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))

void print_all(int *a, unsigned len){
	for(unsigned i=0; i<len; i++){
		printf("%d, ", *(a+i));
	}
	printf("\n");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int balance(int *a, int begin, int end){
	int pivot = a[begin];

	while(begin < end){
		while(end>begin && a[end] >= pivot){
			end--;
		}

		swap(a+end, a+begin);

		while(begin<end && a[begin] <= pivot){
			begin++;
		}
		swap(a+end, a+begin);
	}

	return begin;
}

int find_kmin(int *a, int begin, int end, int kmin){
	int mid = balance(a, begin, end);
	if(mid == kmin){
		return a[kmin];
	}else if(mid > kmin){
		return find_kmin(a, begin, mid-1, kmin);
	}else{
		return find_kmin(a, mid+1, end, kmin);
	}
}

int main(void){
    int a[] = {5, 9, 6, 2, 8, 3, 1};
    print_all(a, ARRAY_LEN(a));
    for(int i=0; i<ARRAY_LEN(a); i++){
    	int min = find_kmin(a, 0, ARRAY_LEN(a)-1, i);
    	printf("%d, ", min);
    }
    printf("\n");

    return 0;
}
