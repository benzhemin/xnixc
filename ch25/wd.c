#include <stdio.h>
#include <unistd.h>

int main(void){
	char buf[256];
	getcwd(buf, sizeof(buf));

	printf("%s\n", buf);

	return 0;
}