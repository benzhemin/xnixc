#include <stdio.h>

unsigned int rotate_right(unsigned int x, unsigned int bits){
	
	unsigned int high_mask = 0x80000000;
	unsigned int low_mask = 1;
	int flag;

	while(bits > 0){
		bits--;
		
		flag = x & low_mask;
		x = x >> 1;
		if (flag)
			x = x | high_mask;
	}
	return x;
}

int main(void){
	unsigned int res = rotate_right(0xdeadbeef, 16);
	printf("res=%x\n", res);

	return 0;
}