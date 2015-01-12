#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *p;
    unsigned allocated = 0;
    do{
        p = malloc(10*1024*1024*1024u);
        allocated += 10;
        printf("allocated %uG\n", allocated);
    }while(p!=NULL);

    return 0;
}
