#include <stdio.h>

int main(void){
    char a[4][3][2] = {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
                {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
               {{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
               {{'s', 't'}, {'u', 'v'}, {'w', 'x'}}};

    char (*pa)[2] = &a[1][0];
    char (*ppa)[3][2] = &a[1];

    printf("pa=%c\n", pa[5][1]);
    printf("ppa=%c\n", ppa[1][2][1]);

    return 0;
}
