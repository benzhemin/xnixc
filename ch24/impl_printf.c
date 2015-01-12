#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char *itostr(int value){
    char *buf = malloc(20);
    memset(buf, 0, 20);

    if(value < 0){
        *buf = '-';
        value = value * (-1);
        buf++;
    }

    char *start = buf;
    while(value){
        int last = value % 10;
        *buf++ = '0'+last;
        value = value / 10;
    }
    char *end = buf-1;

    while(start < end){
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return buf;
}

void impl_printf(char *fmt, ...){
    va_list pa;

    va_start(pa, fmt);

    while(fmt && *fmt!='\0'){
        char c = *fmt;

        switch(c){
            case '%':{
                char next = *(fmt+1);

                switch(next){
                    case 's':{
                        char *str = va_arg(pa, char *);
                        fputs(str, stdout);
                        fmt++;
                        break;
                    }
                    case 'd':{
                        int integer = va_arg(pa, int);
                        fputs(itostr(integer), stdout);
                        fmt++;
                        break;
                    }
                }

            }
        }

        fmt++;
    }

    va_end(pa);
}

int main(void){
    impl_printf("%s, %s %d\n", "Hello", "World", 23);

    return 0;
}
