#include <stdio.h>
#include <stdlib.h>

int count_one(unsigned int x){
	int count = 0;

	unsigned int mask = 1;

	while(x){
		if((x & mask))
			count++;
		x = x>>1;
	}
	return count;
}

int main(void){
	int num = 0;

	while(1){
		scanf("%d", &num);
		printf("count_one:%d\n", count_one(num));
	}
	
	return 0;
}