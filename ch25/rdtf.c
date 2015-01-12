#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp = fopen("tf", "r");
	if(fp == NULL){
		perror("open file failure");
		return 1;
	}

	int ch;
	while((ch=fgetc(fp))!=EOF){
		fputc(ch, stdout);
	}

	return 0;
}