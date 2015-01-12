#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y){
	unsigned int sum = 0;
	unsigned shift = 0;
	unsigned mask = 1;

	while(y){
		if((y & mask) && shift){
			sum = sum + (x << shift);
		}

		y = y >> 1;
		shift++;
	}

	return sum;
}

int main(void){
	unsigned int res = multiply(033, 022);
	printf("res:%u\n", res);

	return 0;
}