#include <stdio.h>
#include "popu.h"

int main(void){
    unit_t u;
    set_unit(&u);

    printf("number: %d\n", u.number);
    printf("nmsg:%s\n", u.msg);

    return 0;
}
