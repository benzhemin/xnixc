#include <stdio.h>
#include <string.h>

void *mem_mov(void *dest, void *src, size_t n){
	char temp[n];
	int i;
	char *d = dest;
	char char *s = src;

	for(i=0; i<n; i++){
		temp[i] = s[i];
	}

	for(i=0; i<n; i++){
		d[i] =  temp[i];
	}

	return dest;
}

int main(void){
	char buf[20] = "hello world\n";
	memmove(buf+1, buf, strlen(buf));
	printf(buf);

	return 0;
}