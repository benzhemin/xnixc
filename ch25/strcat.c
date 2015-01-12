#include <stdio.h>
#include <string.h>

int main(void){
	char d[10] = "foo";
	char s[10] = "bar";

	strcat(d, s);
	printf("%s %s\n", d, s);
}