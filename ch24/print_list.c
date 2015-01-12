#include <stdio.h>
#include <stdarg.h>

void print_list(int begin, ...){
    va_list ap;
    char *p;

    va_start(ap, begin);

    p = va_arg(ap, char *);
    while(p!=NULL){
        fputs(p, stdout);
        putchar('\n');
        p = va_arg(ap, char *);
    }

    va_end(ap);
}

int main(void){
    print_list(0, "hello", "world", "little", "peer!", NULL);

    return 0;
}
