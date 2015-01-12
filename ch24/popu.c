#include <string.h>

#include "popu.h"
#include "stack.h"
void set_unit(unit_t *p){
    if(p == NULL){
        return ;
    }

    p->number = 3;
    strcpy(p->msg, "Hello World!");
}
