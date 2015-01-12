#include <stdio.h>

int main(void){
    int ch;
    while((ch=getchar())!=EOF){
        putchar(ch);
        fflush(stdout);
    }
    return 0;
}
