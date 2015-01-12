#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

void compress_blank(){
    int ch;
    BOOL flag = FALSE;
    while((ch=getchar())!=EOF){
        if(ch=='\t'||ch=='\n'||ch=='\r'||ch==' '){
            if(flag == FALSE){
                flag = TRUE;
                putchar(' ');
            }
        }else{
            flag = FALSE;
            putchar(ch);
        }
        fflush(stdout);
    }
}

int main(void){
    compress_blank();

    return 0;
}
